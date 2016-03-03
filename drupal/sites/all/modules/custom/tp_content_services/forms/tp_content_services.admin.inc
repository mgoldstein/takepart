<?php

/**
 *  @function:
 *    This function is used to provide an admin form for module.
 */
function tp_content_services_admin_form() {
  $form = array();

  $form['content_services_endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Endpoint'),
    '#description' => "This is just the pathname. The domain should be set in the settings file for the api.",
    '#default_value' => variable_get('content_services_endpoint','/api/v3/content_publish'),
  );
  $form['content_services_access_token'] = array(
    '#type' => 'textfield',
    '#title' => t('Access Token'),
    '#default_value' => variable_get('content_services_access_token','84628ca2-ca9e-11e3-9e4c-3374aaf7d853'),
  );

  //returns the system form
  return system_settings_form($form);
}
