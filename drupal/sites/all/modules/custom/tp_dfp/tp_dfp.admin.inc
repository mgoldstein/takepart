<?php

/**
 * DFP Admin Settings Form
 */
function tp_dfp_admin_config($form, &$form_state, $form_id){

  //Template Id
  $form['dfp_template_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Network Code'),
    '#default_value' => variable_get('dfp_template_id', '10051775'),
    '#size' => 60,
    '#maxlength' => 128,
  );

  //Destination URL
  $form['dfp_destination_url'] = array(
    '#type' => 'select',
    '#title' => t('Destination URL'),
    '#default_value' => variable_get('dfp_destination_url', 'www.takepart.com'),
    '#options' => array(
      'dev.takepart.com' => 'dev.takepart.com',
      'qa.takepart.com' => 'qa.takepart.com',
      'stage.takepart.com' => 'stage.takepart.com',
      'www.takepart.com' => 'www.takepart.com'
    ),
  );

  return system_settings_form($form);

}

