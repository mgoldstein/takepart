<?php

/**
 * Settings form callback.
 */
function pm_jwplatform_settings_form($form, &$form_state) {

  $library = libraries_detect('jwplatform');
  if ($library && !empty($library['installed'])) {

    $form['pm_jwplatform_api_key'] = array(
      '#title' => t('API Key'),
      '#description' => t('Acount key for accessing the JW Platform API.'),
      '#type' => 'textfield',
      '#default_value' => variable_get('pm_jwplatform_api_key', ''),
    );

    $form['pm_jwplatform_api_secret'] = array(
      '#title' => t('API Secret'),
      '#description' => t('Shared secret for accessing the JW Platform API.'),
      '#type' => 'textfield',
      '#default_value' => variable_get('pm_jwplatform_api_secret', ''),
    );
  }

  $dns_mask_link = 'http://www.longtailvideo.com/support/bits-on-the-run/21627/dns-mask-our-content-servers';
  $form['pm_jwplatform_content_dns_mask'] = array(
    '#title' => t('Content DNS Mask'),
    '#description' => t('The !dns_mask_link of the content server.', array(
      '!dns_mask_link' => l(t('DNS mask'), $dns_mask_link),
    )),
    '#type' => 'textfield',
    '#default_value' => variable_get('pm_jwplatform_content_dns_mask', ''),
  );

  return system_settings_form($form);
}
