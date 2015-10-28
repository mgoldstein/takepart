<?php

/**
 * Sailthru Admin form
 */
function pm_sailthru_settings_form($form, &$form_state, $form_id){

  //Quantity
  $form['pm_sailthru_range'] = array(
    '#type' => 'textfield',
    '#title' => t('Range'),
    '#description' => t('The number of items to render'),
    '#default_value' => variable_get('pm_sailthru_range', '100'),
    '#required' => TRUE,
  );

  //Node Types
  $types = array();
  $content_types = node_type_get_types();
  foreach($content_types as $key => $content_type){
    $types[$key] = $content_type->name;
  }

  $form['pm_sailthru_types'] = array(
    '#type' => 'select',
    '#title' => t('Content Types'),
    '#description' => t('The content types to be included in the feed.  Select all that apply'),
    '#multiple' => TRUE,
    '#options' => $types,
    '#default_value' => variable_get('pm_sailthru_types', array()),
    '#required' => TRUE,
  );

  //Order
  $form['pm_sailthru_order'] = array(
    '#type' => 'select',
    '#title' => t('Order'),
    '#description' => t('The order of items'),
    '#options' => array(
      'DESC' => 'DESC',
      'ASC' => 'ASC'
    ),
    '#default_value' => variable_get('pm_sailthru_types', '$order'),
    '#required' => TRUE,
  );


  return system_settings_form($form);

}