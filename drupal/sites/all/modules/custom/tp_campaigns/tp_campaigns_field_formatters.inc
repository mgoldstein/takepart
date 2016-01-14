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
			//Turn off autoload on 2 or less cards.
			if(count($items) > 2) {
				//Get background images to preload
				$bgimgs = tp_campaigns_preload_images(array_slice($items, 2));
				//Only load items 1 and 2
				$itemstmp = array_slice($items, 0, 2);
				$itemcnt = count(array_slice($items, 2));
			} else {
				$bgimgs = array();
				$itemstmp = $items;
				$itemcnt = 0;
			}

			//Add additional JS to the page
			drupal_add_js(array('autoloadCampaigns' => $entity->nid,
				'campaignPreload' => $bgimgs,
				'campaignItemCount' => $itemcnt), 'setting');
			drupal_add_js(drupal_get_path('module', 'tp_campaigns').'/js/tp_auto_campaign.js', array('type' => 'file', 'scope' => 'footer'));
			drupal_add_library('system', 'drupal.ajax');
			drupal_add_library('system', 'drupal.form');
			drupal_add_library('system', 'jquery.form');

			$element = array(
			  '#theme' => 'tp_card_tray',
			  '#items' => $itemstmp,
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

function tp_campaigns_preload_images($items) {
	foreach($items AS $it) {
		$inarr[] = $it['target_id'];
	}
	$query = new EntityFieldQuery();
	$query->entityCondition('entity_type', 'node')
		->entityCondition('bundle', 'campaign_tray')
		->propertyCondition('status', 1)
		->entityCondition('entity_id', $inarr, 'IN')
		->fieldCondition('field_campaign_card_reference', 'target_id', 'NULL', '!=');
	$result = $query->execute();
	$ret = array();
	if (isset($result['node'])) {
		// // At first we need to get field's id. If you already know field id, you can ommit this step
		// // Get all fields attached to a given node type
		// $fields = field_info_instances('node', 'campaign_tray');
		//
		// // Get id of field
		// $field_id = $fields['field_campaign_card_reference']['field_id'];

		// Attach a field of selected id only to get value for it
		field_attach_load('node', $result['node'], FIELD_LOAD_CURRENT, array('field_id' => 541));

		foreach($result['node'] AS $k => $tray) {
			// Get values of our node field
			$output = field_get_items('node', $tray, 'field_campaign_card_reference');
			$cards[] = $output[0]['target_id'];
		}
		$ret = tp_campaigns_get_preload_url($cards);
	}
	return $ret;
}

function tp_campaigns_get_preload_url($cards) {
	$query = new EntityFieldQuery();
	$query->entityCondition('entity_type', 'node')
		->entityCondition('bundle', array('campaign_card_ad',
			'campaign_card_branding',
			'campaign_card_empty',
			'campaign_card_iframe',
			'campaign_card_media',
			'campaign_card_multi_column',
			'campaign_card_news',
			'campaign_card_social',
			'campaign_card_tap_widget',
			'campaign_card_text',
			'campaign_card_twitter'), 'IN')
		->propertyCondition('status', 1)
		->entityCondition('entity_id', $cards, 'IN')
		->fieldCondition('field_campaign_background', 'fid', 'NULL', '!=');
	$result = $query->execute();
	$ret = array();
	if (isset($result['node'])) {
		$bgs = $result['node'];

		// Attach a field of selected id only to get value for it
		field_attach_load('node', $bgs, FIELD_LOAD_CURRENT, array('field_id' => 514));

		foreach($bgs AS $bgimg) {
			// Get values of our node field
			$output = field_get_items('node', $bgimg, 'field_campaign_background');
			if(isset($output[0]['uri']) && !empty($output[0]['uri'])) {
				$background_image = $output[0]['uri'];
				$ret[] = file_create_url($background_image);
			}
		}
	}
	return $ret;
}
