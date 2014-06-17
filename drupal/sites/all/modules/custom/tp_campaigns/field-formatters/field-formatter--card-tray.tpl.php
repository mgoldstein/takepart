<?php
  foreach ($items as $key => $item) {
    $node = node_load($item['target_id']);
    //If a tray has a background we make the card transparent and set the background on the slider level.
    $slider_styles = array();
    $slider_class = array('tray', 'swipe', 'on-first-slide');
    if($style_settings = field_get_items('node', $node, 'field_campaign_style_setting')){
      $slider_class[] = $style_settings[0]['value'];
    }

    if($bg_width_img = field_get_items('node', $node, 'field_campaign_bgw_image')){
      $bg_width_img = drupal_render(field_view_value('node', $node, 'field_campaign_bgw_image', $bg_width_img[0]));
      $slider_class[] = ($bg_width_img == 0 ? 'tray-img-width-full' : 'tray-img-width-1000');
    }
    if($bg_color = field_get_items('node', $node, 'field_campaign_bg_color')){
      $bg_color = $bg_color[0]['rgb'];
      $slider_styles[] = 'background-color: '. $bg_color. ';';
    }

    if($background_image = field_get_items('node', $node, 'field_campaign_background')){
      $background_image = $background_image[0]['uri'];
      $background_image = file_create_url($background_image);
      $slider_styles[] = 'background-image: url(\''. $background_image. '\');';
      $slider_class[] = 'has-tray-background';
    }
    else{
      $slider_class[] = '';
    }
	  if($background_image || $bg_color){
			$slider_class[] = 'has-tray-background';
	  }
    $references = field_get_items('node', $node, 'field_campaign_card_reference');

    if(!empty($references) && count($references) > 1){
      $slider_class[] = 'has-multiple-cards';
      $slider_class[] = 'slider';
    }
    print '<div' . drupal_attributes(array(
      'id' => 'slider_' . $key,
      'class' => $slider_class,
      'style' => $slider_styles,
      'data-title' => $node->title,
    )) . '>';
    print drupal_render(node_view($node, 'full', NULL));
    print '</div>';
  }?>
