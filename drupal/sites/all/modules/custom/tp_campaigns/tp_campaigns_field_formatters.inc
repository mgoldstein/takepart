<?php
/*
 *Functions for Field Formatters
 */

/*
 * Implements hook_field_formatter_info()
 */
function tp_campaigns_field_formatter_info(){
	return array(
		'tp_card_tray' => array(
			'label' => t('Card Tray'),
			'field types' => array('entityreference'),
		),
		'tp_card_reference' => array(
			'label' => t('Card Reference'),
			'field types' => array('entityreference'),
		)
	);
}


/*
 * Implements hook_field_formatter_view()
 */
function tp_campaigns_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display){
  $element = array();
  $settings = $display['settings'];
  switch($display['type']){
    case 'tp_card_tray':

		drupal_add_js(array('autoloadCampaigns' => $entity->nid), 'setting');
		drupal_add_js(drupal_get_path('module', 'tp_campaigns').'/js/tp_auto_campaign.js', array('type' => 'file', 'scope' => 'footer'));
		drupal_add_library('system', 'drupal.ajax');
	  drupal_add_library('system', 'drupal.form');
		//Only load items 1 and 2
		$items = array_slice($items, 0, 2);
		array_slice($items, 0, 2);
      $element = array(
        '#theme' => 'tp_card_tray',
        '#items' => $items,
        '#entity' => $entity,
      );
      break;
    case 'tp_card_reference':
      $element = array(
        '#theme' => 'tp_card_reference',
        '#items' => $items,
        '#entity' => $entity,
        '#tray_vars' => tp_campaigns_tray_vars($entity),
      );
      break;
  }
  return $element;
}

/*
 * Tray vars for the TP reference field
 */
function tp_campaigns_tray_vars($entity){

	$tray_vars = array();
	$tray_vars['tray_classes'] = array();
	//Grab the tray title if it exists
	if($items = field_get_items('node', $entity, 'field_campaign_tray_title')){
		$tray_vars['tray_title'] = drupal_render(field_view_value('node', $entity, 'field_campaign_tray_title', $items[0]));
		$tray_vars['tray_classes'][] = 'has-tray-title';
		$title_exists = '';
		$title_exists = true;
	}
	//Set the tray classes
	if($items = field_get_items('node', $entity, 'field_campaign_background')){
		$tray_vars['tray_classes'][] = 'has-tray-background';
	}

	//Return Cards
	$tray_vars['cards'] = array();
	if($items = field_get_items('node', $entity, 'field_campaign_card_reference')){
		foreach($items as $key => $item){
			$node = node_load($item['target_id']);
			//Test for playlist to add special playlist class
			if(isset($node->field_media_video_playlist) && !empty($node->field_media_video_playlist)) {
				$playlist = true;
			}
			if($card_title = field_get_items('node', $node, 'field_campaign_card_title')){
				//If any card within a tray has a title we need to show a line above it
				$title_exists = true;
			}
			$output = '';
			$output .= '<div class="card-wrapper '. drupal_html_class($node->title). ' card-'. ($playlist === true?'video-playlist':'') .'">';
      $node_view = node_view($node, 'full', NULL);
			$output .= drupal_render($node_view);
			$output .= '</div>';
			$tray_vars['cards'][] = $output;
		}
	}
	if($title_exists == true){
		$tray_vars['tray_classes'][] = 'has-title';
	}

	//Anchor Tag
	if($items = field_get_items('node', $entity, 'field_campaign_anchor_tag')){
		$title = drupal_render(field_view_value('node', $entity, 'field_campaign_anchor_tag', $items[0]));
		$title = drupal_html_id($title);
		$tray_vars['anchor_tag'] = $title;
		$tray_vars['anchor_tag'] = l('', '', array(
			'fragment' => $title,
			'external' => TRUE,
			'attributes' => array(
				'name' => $title,
				'id' => $title,
				'class' => array('card-anchor')
			)
		));
	}


	return $tray_vars;
}
