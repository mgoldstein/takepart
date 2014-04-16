<?php
//some php stuff. duh.
// move this to .module file
  $campaign_variables = $variables['campaign_node'];

  $logo_position      = $campaign_variables->field_campaign_logo_position['und'][0]['value']; // 0 => Center, 1 => Left, 2 => Right
  $uri                = $campaign_variables->field_campaign_background['und'][0]['uri'];
  $image_url          = file_create_url($uri);
  $min_height         = $campaign_variables->field_campaign_min_height['und'][0]['value'] - 20;
  $bg_color           = $campaign_variables->field_campaign_bg_color['und'][0]['rgb'];
  $bg_width           = $campaign_variables->field_campaign_bgw['und'][0]['value'];
  $bg_width_image     = $campaign_variables->field_campaign_bgw_image['und'][0]['value'];
  $styles             = array();
  $classes            = array();

  //Header link
  if(isset($campaign_variables->field_campaign_hp['und'][0]['url']) == true){
    $homepage_link = $campaign_variables->field_campaign_hp['und'][0]['url'];
  }

  //background
  if(isset($campaign_variables->field_campaign_background['und'][0]['uri']) == true){
    $uri = $campaign_variables->field_campaign_background['und'][0]['uri'];
    $image_url  = file_create_url($uri);
    $styles[]   = 'background-image: url(\''. $image_url. '\');';
    if($bg_width_image == 0){
      $classes[] = 'header-bg-image-full';
    }
    else{
      $classes[] = 'header-bg-image-980';
    }
  }
  if($bg_width = 0){
    $classes[] = 'header-full';
  }
  else{
    $classes[] = 'header-980';
  }
  if(isset($campaign_variables->field_campaign_min_height['und'][0]['value']) == true){
    $styles[] = 'min-height: '. $min_height. 'px;';
  }
  if(isset($campaign_variables->field_campaign_bg_color['und'][0]['rgb']) == true){
    $styles[] = 'background-color: '. $bg_color. ';';
  }

  if(isset($campaign_variables->field_campaign_logo['und'][0]['uri']) == true){
    $logo = $campaign_variables->field_campaign_logo['und'][0]['uri'];
    $logo = file_create_url($campaign_variables->field_campaign_logo['und'][0]['uri']);

    if($logo_position == 0){ // Center
      $logo_class = 'logo-center';
    }
    elseif($logo_position == 1){ // Left
      $logo_class = 'logo-left';
    }
    else{ //Right
      $logo_class = 'logo-right';
    }
    $logo = '<div class="campaign-logo-div"><img src="'. $logo. '" class="campaign-logo '. $logo_class. '"></div>';
  }

  //Menu Styling
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

<div class="branding-header <?php print implode(' ', $classes); ?>" style="<?php print implode(' ', $styles); ?>">


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
      // it's ok, "changing the menu color in the CMS is easy, right?"

      print '<div class=menu-wrapper>';
      print '<div class="menu sf-navbar" style="'. implode(' ', $menu_styles). '">';
      print '<ul class="sf-menu" style="background-color: transparent;">';
      foreach($improved as $key => $link){
        $anchor = $link['#localized_options']['attributes']['rel'];

        $parent_menu_title        = $link['#title'];

        $parent_menu_classes      = array('parent-item');
        $parent_link_classes      = array();
        if (!is_null($anchor)) {
          // $parent_menu_classes[]  = 'anchored';
          $parent_link_classes[]  = 'anchored';
        }

        $parent_menu_attrs = drupal_attributes(array(
          'class' => $parent_menu_classes,
          'style' => array(
            'background-color ' . $menu_color_parent . ';',
          ),
        ));

        $parent_menu_link = l($parent_menu_title, $link['#href'], array(
          'fragment' => $anchor,
          'attributes' => array(
            'data-path' => $parent_menu_title,
            'class' => $parent_link_classes,
          ),
        ));

        print '<li' . $parent_menu_attrs . '>' . $parent_menu_link;

        if (isset($link['#below']) == true && $link['#below'] != NULL) {

          print '<ul>';
          $child_elements = element_children($link['#below']);
          foreach ($child_elements as $key_child => $link_child){

            $child_menu_anchor = $link_child['#localized_options']['attributes']['rel'];

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

            $child_menu_link = l($child_menu_title,
              $link['#below'][$link_child]['#href'], array(
                'fragment' => $child_menu_anchor,
                'attributes' => array(
                  'class' => $child_link_classes,
                  'data-path' => $parent_menu_title . ': ' . $child_menu_title,
                ),
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

  <div class="header-inner" style="min-height: <?php print $min_height; ?>px">
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

    <?php print (isset($homepage_link) == true ? l(' ', $homepage_link, array('attributes' => array('class' => array('big-link')))) : ''); ?>
    <?php print (isset($logo) == true ? $logo : ''); ?>

    <a href="#" class="campaign-menu-toggle icon i-touch-menu"></a>

  </div>

</div>




