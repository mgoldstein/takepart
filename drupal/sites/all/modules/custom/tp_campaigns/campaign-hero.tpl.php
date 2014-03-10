<?php
//some php stuff. duh.
// move this to .module file
  $campaign_variables = $variables['campaign_node'];

  $uri = $campaign_variables->field_campaign_background['und'][0]['uri'];
  $image_url = file_create_url($uri);
  $min_height = $campaign_variables->field_campaign_min_height['und'][0]['value'];
  $bg_color = $campaign_variables->field_campaign_bg_color['und'][0]['rgb'];
  $bg_width = $variables['campaign_node']->field_campaign_bgw['und'][0]['value'];
  $bg_width_image = $variables['campaign_node']->field_campaign_bgw_image['und'][0]['value'];
  $styles = array();
  $classes = array();
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
    $logo = '<img src="'. $logo. '" class="logo">';
  }

?>


<div class="branding-header <?php print implode(' ', $classes); ?>" style="<?php print implode(' ', $styles); ?>">
  <div class="header-inner" style="min-height: <?php print $min_height; ?>px">
  <?php
    $menu = 'menu-'. $campaign_variables->field_campaign_menu['und'][0]['value'];
    $nice_menus = theme('nice_menus', array(
      'id' => 100,
      'menu_name' => $menu,
      'mlid' => 0,
      'direction' => 'down',
      'depth' => '-1',
      'respect_expanded' => FALSE
    ));
    print (isset($logo) == true ? $logo : '');
    print '<div class="menu">';
    print $nice_menus['content'];
    print '</div>';
  ?>
  </div>
</div>

