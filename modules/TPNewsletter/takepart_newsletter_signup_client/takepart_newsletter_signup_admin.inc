<?php
/**
 * Returns the admin settings for the module
 */
function takepart_newsletter_signup_client_admin_settings() {
  $form = array();

  $form['takepart_newsletter_signup_client_service_url'] = array(
    '#prefix' => '<br/><br/>',
    '#type' => 'textfield',
    '#size' => 100,
    '#title' => t('Webservice URL'),
    '#description' => t('Full url to the TakePart.com service; i.e., http://www.takepart.com/services/rest/takepart_newsletter_signup.subscribe'),
    '#default_value' => variable_get('takepart_newsletter_signup_client_service_url', 'http://www.takepart.com/services/rest/takepart_newsletter_signup.subscribe'),
  );
  
  $form['takepart_newsletter_signup_client_domain'] = array(
    '#type' => 'textfield',
    '#size' => 30,
    '#title' => t('Domain'),
    '#description' => t('Domain name supplied to TakePart for the API Key'),
    '#default_value' => variable_get('takepart_newsletter_signup_client_domain', ''),
  );
  
  $form['takepart_newsletter_signup_client_api_key'] = array(
    '#type' => 'textfield',
    '#size' => 60,
    '#title' => t('API Key'),
    '#description' => t('API Key to the web service obtained from TakePart'),
    '#default_value' => variable_get('takepart_newsletter_signup_client_api_key', ''),
  );
    
  if (module_exists('takepart_newsletter_signup')) {
    $form['takepart_newsletter_signup_client_direct_save'] = array(
      '#type' => 'checkbox',
      '#title' => t('Direct Save'),
      '#description' => t('Bypass the service and save directly to the database. Only used if TakePart Newsletter Service module is installed'),
      '#default_value' => variable_get('takepart_newsletter_signup_client_direct_save', 0),
    );
  }
  
  return system_settings_form($form);  
  
}
