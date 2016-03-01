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
    '#default_value' => variable_get('content_services_endpoint','')
  );
  $form['content_services_access_token'] = array(
    '#type' => 'textfield',
    '#title' => t('Access Token'),
    '#default_value' => variable_get('content_services_access_token','')
  );

  //returns the system form
  return system_settings_form($form);
}
