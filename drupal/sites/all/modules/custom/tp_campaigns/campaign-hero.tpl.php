<?php
//some php stuff. duh.
// move this to .module file
  $campaign_variables = $variables['campaign_node'];

  $menu_color_parent = $variables['campaign_node']->field_menu_color_parent['und'][0]['rgb'];
  $menu_color_child = $variables['campaign_node']->field_campaign_menu_color_child['und'][0]['rgb'];

  $logo_position = $variables['campaign_node']->field_campaign_logo_position['und'][0]['value']; // 0 => Center, 1 => Left, 2 => Right
  $uri = $campaign_variables->field_campaign_background['und'][0]['uri'];
  $image_url = file_create_url($uri);
  $min_height = $campaign_variables->field_campaign_min_height['und'][0]['value'];
  $bg_color = $campaign_variables->field_campaign_bg_color['und'][0]['rgb'];
  $bg_width = $variables['campaign_node']->field_campaign_bgw['und'][0]['value'];
  $bg_width_image = $variables['campaign_node']->field_campaign_bgw_image['und'][0]['value'];
  $styles = array();
  $classes = array();

  //Header link
  if(isset($variables['campaign_node']->field_campaign_homepage['und'][0]['target_id']) == true){
    $homepage_id = $variables['campaign_node']->field_campaign_homepage['und'][0]['target_id'];
    global $base_url;
    $homepage_link = $base_url. '/'. drupal_get_path_alias('node/'. $homepage_id);

  }

  //If menu exists, add additional padding to the hero unit
  if(isset($campaign_variables->field_campaign_menu['und'][0]['value']) == true && $campaign_variables->field_campaign_menu['und'][0]['value'] != NULL){
    $classes[] = 'has-menu';
  }


  //background
  if(isset($campaign_variables->field_campaign_background['und'][0]['uri']) == true){
    $uri = $campaign_variables->field_campaign_background['und'][0]['uri'];
    $image_url = file_create_url($uri);
    $styles[] = 'background-image: url(\''. $image_url. '\');';
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

  if(isset($variables['campaign_node']->field_campaign_logo['und'][0]['uri']) == true){
    $logo = $variables['campaign_node']->field_campaign_logo['und'][0]['uri'];
    $logo = file_create_url($variables['campaign_node']->field_campaign_logo['und'][0]['uri']);

    if($logo_position == 0){ // Center
      $logo_class = 'logo-center';
    }
    elseif($logo_position == 1){ // Left
      $logo_class = 'logo-left';
    }
    else{ //Right
      $logo_class = 'logo-right';
    }
    $logo = '<img src="'. $logo. '" class="campaign-logo '. $logo_class. '">';
  }

?>


<div class="branding-header <?php print implode(' ', $classes); ?>" style="<?php print implode(' ', $styles); ?>">


  <?php
    $menu = 'menu-'. $campaign_variables->field_campaign_menu['und'][0]['value'];
    $menu_tree = menu_tree_all_data($menu);
    $menu_tree = menu_tree_output($menu_tree);
    
    $menu_elements = element_children($menu_tree);
    $improved = array();
    foreach($menu_elements as $key => $item){
      $improved[] = $menu_tree[$item];
    }
    dpm(get_defined_vars(), 'get defined vars');
    // it's ok, "changing the menu color in the CMS is easy, right?"

    print '<div class="menu sf-navbar" style="background-color: '. $menu_color_parent. ';"">';
    print '<ul class="sf-menu" style="background-color: '. $menu_color_parent. ';">';
    foreach($improved as $key => $link){
      $anchor = $link['#localized_options']['attributes']['rel'];
      if(isset($link['#below']) == true && $link['#below'] != NULL){
        print '<li class="parent-item '. ($anchor != NULL ? 'anchored' : ''). '" style="background-color: '. $menu_color_parent. ';">'. l($link['#title'], $link['#href'], array('fragment' => $anchor));
        print '<ul>';
        $child_elements = element_children($link['#below']);
        foreach($child_elements as $key_child => $link_child){
          $anchor = $link_child['#localized_options']['attributes']['rel'];
          print '<li style="background-color: '. $menu_color_child. '">'. l($link['#below'][$link_child]['#title'], $link['#below'][$link_child]['#href'], array('fragment' => $anchor, '#attributes' => array('class' => array('sf-with-ul')))). '</li>';

        }
        print '</ul></li>';
      }
      else{
        print '<li class="parent-item '. ($anchor != NULL ? 'anchored' : ''). '" style="background-color: '. $menu_color_parent. ';">'. l($link['#title'], $link['#href'], array('fragment' => $anchor)). '</li>';
      }
    }
    print '</ul>';
    print '</div>';
    ?>

  <div class="header-inner" style="min-height: <?php print $min_height; ?>px">
    <?php print (isset($homepage_link) == true ? l(' ', $homepage_link, array('attributes' => array('class' => array('big-link')))) : ''); ?>
    <?php print (isset($logo) == true ? $logo : ''); ?>
  </div>

</div>

