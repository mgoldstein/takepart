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

	/* Render TAP Widget */
	if($tap_widget = field_get_items('node', $variables['node'], 'field_campaign_tab_widget_ref')){
		$tap_widget = field_view_field('node', $variables['node'], 'field_campaign_tab_widget_ref', array('type' => 'tp_card_tab_widget_reference'));
		$tap_widget = drupal_render($tap_widget);
	}

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
	return drupal_render(field_view_value($entity_type, $entity, $field_name, $item[0]));
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
	if($background_crop = field_get_items('node', $variables['node'], 'field_campaign_bg_crop')){
		if($background_crop[0]['value'] == 1){
			$variables['classes_array'][] = 'background-crop';
		}
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