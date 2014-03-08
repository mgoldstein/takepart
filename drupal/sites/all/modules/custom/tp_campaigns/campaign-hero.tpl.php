<?php
//some php stuff. duh.
// move this to .module file
  $campaign_variables = $variables['campaign_node'];
  // dpm($campaign_variables, 'campaign_variables');
  $uri = $campaign_variables->field_campaign_background['und'][0]['uri'];
  $image_url = file_create_url($uri);
  $min_height = $campaign_variables->field_campaign_min_height['und'][0]['value'];
  $bg_color = $campaign_variables->field_campaign_bg_color['und'][0]['rgb'];
  $styles = array();
  if(isset($campaign_variables->field_campaign_background['und'][0]['uri']) == true){
    $uri = $campaign_variables->field_campaign_background['und'][0]['uri'];
    $image_url = file_create_url($uri);
    $styles[] = 'background-image: url(\''. $image_url. '\');';
    $styles[] = 'background-size: 980px;';
  }
  if(isset($campaign_variables->field_campaign_min_height['und'][0]['value']) == true){
    $styles[] = 'min-height: '. $min_height. 'px;';
  }
  if(isset($campaign_variables->field_campaign_bg_color['und'][0]['rgb']) == true){
    $styles[] = 'background-color: '. $bg_color. ';';
  }

  

?>


<div class="branding-header" style="<?php print implode(' ', $styles); ?>">
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
  print '<div class="menu">';
  print $nice_menus['content'];
  print '</div>';
?>
</div>

