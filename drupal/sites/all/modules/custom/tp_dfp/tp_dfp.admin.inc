<?php

/**
 * DFP Admin Settings Form
 */
function tp_dfp_admin_config($form, &$form_state, $form_id){

  //CLIENT_ID
  $form['dfp_client_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Client ID'),
    '#default_value' => 'TODO: add default value',
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => TRUE,
  );

  //CLIENT_SECRET
  $form['dfp_client_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Client Secret'),
    '#default_value' => 'TODO: add default value',
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => TRUE,
  );

  //REFRESH_TOKEN?
  $form['dfp_refresh_token'] = array(
    '#type' => 'textfield',
    '#title' => t('Refresh Token'),
    '#default_value' => 'TODO: add default value',
    '#size' => 60,
    '#maxlength' => 128,
  );

  //NETWORK_CODE?
  $form['dfp_network_code'] = array(
    '#type' => 'textfield',
    '#title' => t('Network Code'),
    '#default_value' => 'TODO: add default value',
    '#size' => 60,
    '#maxlength' => 128,
  );

  //APPLICATION_NAME?
  $form['dfp_application_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Application Name'),
    '#default_value' => 'TODO: add default value',
    '#size' => 60,
    '#maxlength' => 128,
  );

  return system_settings_form($form);

}

