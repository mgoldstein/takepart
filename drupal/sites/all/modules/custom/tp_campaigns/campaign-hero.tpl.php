<?php

  $campaign_variables = $variables['campaign_node'];
  $styles             = array();
  $classes            = array();

  //Menu Styling
  //TODO: Move this to it's own template and call it in the .module file
  $menu_bar_color     = $campaign_variables->field_campaign_menu_bg_color['und'][0]['rgb'];
  $menu_color_parent  = $campaign_variables->field_menu_color_parent['und'][0]['rgb'];
  $menu_color_child   = $campaign_variables->field_campaign_menu_color_child['und'][0]['rgb'];
  $menu_width         = $campaign_variables->field_campaign_menu_width['und'][0]['value'];
  $menu_styles        = array();
  if(isset($campaign_variables->field_campaign_menu_bg_image['und'][0]['uri']) == true){
    $menu_image       = $campaign_variables->field_campaign_menu_bg_image['und'][0]['uri'];
    $menu_image       = file_create_url($menu_image);
    $menu_styles[]    = 'background-image: url(\''. $menu_image. '\');';

    $menu_image_width = $campaign_variables->field_campaign_menu_bg_image_w['und'][0]['value'];
    if($menu_image_width == 0){ //full width
      $menu_styles[]  = 'background-size: 100%;';
    }
    else{ //1000px
      $menu_styles[]  = 'background-size: 1000px;';
    }
  }
  if($menu_width == 0){ //full width
    $menu_styles[]    = 'width: 100%;';
  }
  else{ //1000px
    $menu_styles[]    = 'max-width: 1000px;';
  }
  if(isset($menu_bar_color) == TRUE && $menu_bar_color != NULL){
    $menu_styles[]    = 'background-color: '. $menu_bar_color. ';';
  }

  //If menu exists, add additional padding to the hero unit
  if(isset($campaign_variables->field_campaign_menu['und'][0]['value']) == true && $campaign_variables->field_campaign_menu['und'][0]['value'] != NULL){
    $classes[] = 'has-menu';
  }

?>

<div class="branding-header <?php print implode(' ', $bg_settings['classes']); ?>" style="<?php print implode(' ', $bg_settings['styles']); ?>">

  <?php
    if(isset($campaign_variables->field_campaign_menu['und'][0]['value']) == true){
      $menu           = 'menu-'. $campaign_variables->field_campaign_menu['und'][0]['value'];
      $menu_tree      = menu_tree_all_data($menu);
      $menu_tree      = menu_tree_output($menu_tree);

      $menu_elements  = element_children($menu_tree);
      $improved       = array();
      foreach($menu_elements as $key => $item){
        $improved[]   = $menu_tree[$item];
      }

      print '<div class="menu-wrapper">';
      print '<div class="menu sf-navbar" style="'. implode(' ', $menu_styles). '">';
      print '<ul class="sf-menu" style="background-color: transparent;">';
      foreach($improved as $key => $link){
        $anchor = $link['#localized_options']['attributes']['rel'];
        $target = $link['#localized_options']['attributes']['target'];

        $parent_menu_title        = $link['#title'];
        $parent_menu_classes      = array('parent-item');
        $parent_link_classes      = array();
        if (!is_null($anchor)) {
          $parent_menu_classes[]  = 'anchored';
          $parent_link_classes[]  = 'anchored-child';
        }

        $parent_menu_attrs = drupal_attributes(array(
          'class' => $parent_menu_classes,
          'style' => array(
            'background-color ' . $menu_color_parent . ';',
          ),
        ));

        $plattr = array(
            'data-path' => $parent_menu_title,
            'class' => $parent_link_classes,
          );
        if (!empty($target)) {
            $plattr['target'] = $target;
        }
        $parent_menu_link = l($parent_menu_title, $link['#href'], array(
          'fragment' => $anchor,
          'attributes' => $plattr,
        ));

        print '<li' . $parent_menu_attrs . '>' . $parent_menu_link;

        if (isset($link['#below']) == true && $link['#below'] != NULL) {

          print '<ul>';
          $child_elements = element_children($link['#below']);
          foreach ($child_elements as $key_child => $link_child){

            $child_menu_anchor = $link['#below'][$link_child]['#localized_options']['attributes']['rel'];

            $child_menu_title = $link['#below'][$link_child]['#title'];

            $child_menu_attrs = drupal_attributes(array(
              'style' => array(
                'background-color: ' . $menu_color_child . ';'
              ),
            ));

            $child_link_classes = array('sf-with-ul');
            if (!is_null($child_menu_anchor)) {
              $child_link_classes[] = 'anchored';
            }
            $clattr = array(
            'data-path' => $parent_menu_title,
            'class' => $parent_link_classes,
            );
            if (!empty($target)) {
              $clattr['target'] = $target;
            }

            $child_menu_link = l($child_menu_title,
              $link['#below'][$link_child]['#href'], array(
                'fragment' => $child_menu_anchor,
                'attributes' => $clattr,
                'html' => TRUE
              ));

            print '<li' . $child_menu_attrs . '>' . $child_menu_link . '</li>';
          }
          print '</ul>';
        }

        print '</li>';
      }
      print '</ul>';
      print '<div class="clearfix"></div></div></div>';
    }
    ?>

  <div class="header-inner" style="min-height: <?php print $bg_settings['min_height']; ?>px" data-mheight="<?php print $bg_settings['mobile_min_height']; ?>px">
    <?php // social links ?>
    <aside id="campaign-page-social" class="social" data-title="<?php print $share_headline; ?>" data-description="<?php print $share_description; ?>" data-imagesrc="<?php print $share_imagesrc; ?>">
      <div class="inner">
        <h3 class="tp-social-headline share-headline">Share</h3>
        <div class="tp-social" id="campaign-page-share"></div>
        <div id="campaign-page-social-more">
          <h4 class="trigger"><a href="#campaign-page-more-shares">More</a></h4>
          <div id="campaign-page-more-shares">
          <p></p>
          </div>
        </div>
      </div>
    </aside><!-- / #campaign-page-social -->
    <?php print $logo; ?>
    <a href="#" class="campaign-menu-toggle icon i-touch-menu"></a>
  </div>
</div>
