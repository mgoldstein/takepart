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
		),
		'tp_card_tab_widget_reference' => array(
			'label' => t('TAB Widget Reference'),
			'field types' => array('entityreference'),
		),
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
		case 'tp_card_tab_widget_reference':
			$element = array(
				'#theme' => 'tp_tap_widget',
				'#tap_id' => tp_campaigns_tap_widget_id($items),
				'#widget_exposed' => tp_campaigns_tap_widget_exposed($entity),
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
			if($card_title = field_get_items('node', $node, 'field_campaign_card_title')){
				//If any card within a tray has a title we need to show a line above it
				$title_exists = true;
			}
			$output = '';
			$output .= '<div class="card-wrapper '. drupal_html_class($node->title). '">';
			$output .= drupal_render(node_view($node, 'full', NULL));
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

/*
 * Widget ID for the TAP widget reference
 */
function tp_campaigns_tap_widget_id($items){
//Grab Action ID
	$tap_id = db_select('signature_node', 's')
		->fields('s', array('tap_id'))
		->condition('nid', $items[0]['target_id'],'=')
		->execute()
		->fetchAssoc();
	$tap_id = $tap_id['tap_id'];
	return $tap_id;
}

/*
 * Widget expose value for the TAP widget reference
 */
function tp_campaigns_tap_widget_exposed($entity){

	if($widget_exposed = field_get_items('node', $entity, 'field_campaign_tab_widget_expose')){
		$widget_exposed = 'expanded';
	}else{
		$widget_exposed = '';
	}
	return $widget_exposed;
}