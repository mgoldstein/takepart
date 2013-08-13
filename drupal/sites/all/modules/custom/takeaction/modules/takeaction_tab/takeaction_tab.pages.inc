<?php
/**
 * Implements TakeAction TAB module pages.
 */

/**
 * Implement module settings form.
 */
function takeaction_tab_settings_form($form, &$form_state) {
  $form['takeaction_tab_security_token'] = array(
    '#type' => 'textfield',
    '#title' => t('TAB Security Token'),
    '#default_value' => variable_get('takeaction_tab_security_token', ''),
    '#required' => TRUE,
  );
  $form['takeaction_tab_api_url'] = array(
    '#type' => 'textfield',
    '#title' => t('TAB API URL'),
    '#default_value' => variable_get('takeaction_tab_api_url', ''),
    '#description' => t('The URL where to send the API requests.'),
    '#required' => TRUE,
  );
  return system_settings_form($form);
}
