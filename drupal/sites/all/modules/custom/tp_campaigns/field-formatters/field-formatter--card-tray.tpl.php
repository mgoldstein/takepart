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
	  if($background_crop = field_get_items('node', $node, 'field_campaign_bg_crop')){
		  if($background_crop[0]['value'] == 1){
			  $slider_class[] = 'background-crop';
		  }
	  }

	  //Set the position of the background
	  if($background_position = field_get_items('node', $node, 'field_campaign_bg_image_position')){
		  if($background_position[0]['value'] == 2){
			  $background_position = 'bottom';
		  }else{
			  $background_position = 'top';
		  }
		  $slider_styles[] = 'background-position: '. $background_position. ';';
	  }

    //Add the animate class to the array if enabled
    if ($animate_tray = field_get_items('node' , $node , 'field_tray_animation')) {
      if ($animate_tray[0]['value']) {
        $slider_class[] = 'animate';
      }
    }

    //Add the fade in class if enabled
    if ($fade_elements = field_get_items('node' , $node , 'field_campaign_fade_in')) {
      if ($fade_elements[0]['value']) {
        $slider_class[] = 'fade-in';
      }
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
      'id' => 'slider_' . ($key+$itemnumb),
      'class' => $slider_class,
      'style' => $slider_styles,
      'data-title' => $node->title,
    )) . '>';
    $node_view = node_view($node, 'full', NULL);
    print drupal_render($node_view);
    print '</div>';
  }?>
