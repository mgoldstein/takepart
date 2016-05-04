<?php
/*
 *Functions for Theme Processes for Campaign Cards
 */

/********************************
 * Common Elements for Cards
 ********************************/
/*
 * Instructional copy for campaign cards
 */
function tp_campaigns_card_instructional($variables){
	$instructional = tp4_render_field_value('node', $variables['node'], 'field_campaign_instructional');
	if(!empty($instructional)){
		return $instructional;
	}
}
function tp_campaigns_card_title($variables){
	$card_title = tp4_render_field_value('node', $variables['node'], 'field_campaign_instructional');
	if(!empty($instructional)){
		return $instructional;
	}
}

/********************************
 * Campaign Card Content
 ********************************/
/*
 * Campaign Card: TAP Widget
 */
function tp_campaigns_card_content_tap_widget($variables){

  //Get TAP Widget Type
  $tap_type = field_get_items('node', $variables['node'], 'field_campaign_tap_widget_type');

  //Get Action Override ID
  if($tap_action = field_get_items('node', $variables['node'], 'field_campaign_tab_widget_ref')){

    $mapping = SignatureActionMapping::loadByNodeId($tap_action[0]['target_id']);
    if ($mapping !== FALSE) {
      $tap_action_id = $mapping->tapID();
    }
  }

  //Set TAP version specific settings
  $overrides = array();
  if(!empty($tap_type) && $tap_type[0]['value'] == 2){
    //Set Type
    $type = 'tap_embed';

    //Set Action ID
    $overrides['data-action-id'] = isset($tap_action_id) ? $tap_action_id : '';

    //Set Expanded value
    if($tap_expanded = field_get_items('node', $variables['node'], 'field_campaign_tab_widget_expose')){
      $overrides['data-expanded'] = $tap_expanded[0]['value'] ? 'TRUE' : '';
    }


  }else { //Use original TAP
    //Set type
    $type = 'tap_widget';

    //Set Action ID
    $overrides['data-action-id'] = isset($tap_action_id) ? $tap_action_id : '';

    //Set Expanded value
    if($tap_expanded = field_get_items('node', $variables['node'], 'field_campaign_tab_widget_expose')){
      $overrides['data-form-style'] = $tap_expanded[0]['value'] ? 'expanded' : '';
    }

  }

  //Set Alignment
  $alignment = 'left';
  if($alignment = field_get_items('node', $variables['node'], 'field_campaign_content_side')){
    $alignment = ($alignment[0]['value'] == 0 ? 'left' : 'right');
  }

  $tap_widget = theme('takeaction_widget', array(
    'type' => $type,
    'overrides' => $overrides,
    'alignment' => $alignment
  ));

	/* Render Image Field */
	if($image = field_get_items('node', $variables['node'], 'field_campaign_media_photo')){
		$image = field_view_field('node', $variables['node'], 'field_campaign_media_photo', array('type' => 'full', 'label' => 'hidden'));
		$image = drupal_render($image);

		/* Wrap Image Field in link */
		if($link = field_get_items('node', $variables['node'], 'field_campaign_media_photo_url')){
			$image = l($image, $link[0]['url'], array_merge( $link[0], array('html' => true)) );
		}
	}

	/* Render Body Field */
	if($body = field_get_items('node', $variables['node'], 'body')){
		$body = field_view_field('node', $variables['node'], 'body', array('type' => 'full', 'label' => 'hidden'));
		$body = drupal_render($body);
	}

	/* Set column classes */
	$column_count = tp4_render_field_value('node', $variables['node'], 'field_campaign_media_col');
	$left_classes = array();
	$right_classes = array();
	switch($column_count){
		case 'Single Column':
			$left_classes[] = 'left-full';
			break;
		case 'Two Column (even width)':
			$left_classes[] = 'column-even';
			$right_classes[] = 'column-even';
			break;
		case 'Two Column (left side wide)':
			$left_classes[] = 'column-wide';
			$right_classes[] = 'column-narrow';
			break;
		case 'Two Column (right side wide)':
			$left_classes[] = 'column-narrow';
			$right_classes[] = 'column-wide';
			break;
	}

	/* Set Content Side */
	$widget_side = tp4_render_field_value('node', $variables['node'], 'field_campaign_content_side');
	if($column_count != 'Single Column' && $widget_side == 'Left Side'){
		//Put Widget on the left side
		$left = $tap_widget;
		$right = (!empty($image) ? $image : FALSE);
		$right .= (!empty($body) ? $body : FALSE);
	}elseif($column_count != 'Single Column' && $widget_side == 'Right Side'){
		//Put Widget on the Right Side
		$left = (!empty($image) ? $image : FALSE);
		$left .= (!empty($body) ? $body : FALSE);
		$right = $tap_widget;
	}else{
		//Put Widget on the left with no right.
		$left = $tap_widget;
	}

	/* variables for hook_theme are defined in the .module file */
	$content = theme('tp_card_tap_widget', array(
		'left' => $left,
		'right' => $right,
		'left_classes' => $left_classes,
		'right_classes' => $right_classes,
	));
	return $content;
}


/********************************
 * Helper functions for Campaigns
 ********************************/
/*
 * Helper function 1
 * This function can be used in 90% of use cases in rendering a field's value
 */
function tp4_render_field_value($entity_type, $entity, $field_name){
	$item = field_get_items($entity_type, $entity, $field_name);
  $item = field_view_value($entity_type, $entity, $field_name, $item[0]);
	return drupal_render($item);
}
/*
 * Helper function 2
 * Standard set of background rules that get repeated across every card type
 */
function tp_campaigns_card_background(&$variables){

	$variables['styles'] = array();
	if($card_style = field_get_items('node', $variables['node'], 'field_campaign_style_setting')){
		$variables['classes_array'][] = $card_style[0]['value'];
	}
	if($background_color = field_get_items('node', $variables['node'], 'field_campaign_bg_color')){
		$variables['styles'][] = 'background-color: '. $background_color[0]['rgb']. ';';
	}
	if($min_height = tp4_render_field_value('node', $variables['node'], 'field_campaign_min_height')){
		$variables['styles'][] = 'min-height: '. $min_height. 'px;';
	}
	$background_width = tp4_render_field_value('node', $variables['node'], 'field_campaign_bgw');
	if($background_width == 'Full Width'){
		$variables['classes_array'][] = 'card-width-full';
	}
	else{
		$variables['classes_array'][] = 'card-width-980';
	}
	$background_crop_value = 0;
	if($background_crop = field_get_items('node', $variables['node'], 'field_campaign_bg_crop')){
		if($background_crop[0]['value'] == 1){
			$variables['classes_array'][] = 'background-crop';
			$background_crop_value = $background_crop[0]['value'];
		}
	}
  if(field_get_items('node', $variables['node'], 'field_campaign_full_width')){
    $variables['classes_array'][] = 'content-full-width';
  }

  $background = '';
  if($background = field_get_items('node', $variables['node'], 'field_campaign_background')) {
    $bg = file_create_url($background[0]['uri']);
		if($background_crop_value) {
      //image style for tablet and mobile
      $variables['background_image_desktop'][] = "background-image: url('$bg');";
      $variables['background_image_tablet'][] = "background-image: url('$bg');";
      $variables['background_image_mobile'][] = "background-image: url('$bg');";
    } else {
			//image style for tablet and mobile
			$variables['background_image_desktop'][] = "background-image: url('$bg');";
			if($bgtablet = image_style_path('large_responsive_tablet', $background[0]['uri'])) {
				$bgtablet = file_create_url($bgtablet);
				$variables['background_image_tablet'][] = "background-image: url('$bgtablet');";
			} else {
				$variables['background_image_tablet'][] = "background-image: url('$bg');";
			}
			if($bgmobile = image_style_path('large_responsive_mobile', $background[0]['uri'])) {
				$bgmobile = file_create_url($bgmobile);
				$variables['background_image_mobile'][] = "background-image: url('$bgmobile');";
			} else {
				$variables['background_image_mobile'][] = "background-image: url('$bg');";
			}
		}
		$variables['background_class'] = $variables['type'].$variables['nid'];
		$variables['classes_array'][] = $variables['type'].$variables['nid'];

  }

	//Set the size of the background image
	$bg_image_width = tp4_render_field_value('node', $variables['node'], 'field_campaign_bgw_image');
	if($bg_image_width == 'Full Width'){
		$variables['styles'][] = 'background-size: 100%;';
	}
	else{
		$variables['styles'][] = 'background-size: 1000px;';
	}

	//Set the position of the background
	if($background_position = field_get_items('node', $variables['node'], 'field_campaign_bg_image_position')){
		if($background_position[0]['value'] == 2){
			$background_position = 'bottom';
		}else{
			$background_position = 'top';
		}
		$variables['styles'][] = 'background-position: '. $background_position. ';';
	}

	$background = field_get_items('node', $variables['node'], 'field_campaign_background');
	$variables['card_background'] = (!empty($background) ? file_create_url($background[0]['uri']) : '');

}
