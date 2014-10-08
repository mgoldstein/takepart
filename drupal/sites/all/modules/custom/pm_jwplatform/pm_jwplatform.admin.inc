<?php

/**
 * Settings form callback.
 */
function pm_jwplatform_settings_form($form, &$form_state) {

  $form['pm_jwplatform_auto_create_tag'] = array(
    '#title' => t('Auto Create Tag'),
    '#description' => t('Tag marking videos that should be auto imported.'),
    '#type' => 'textfield',
    '#default_value' => variable_get('pm_jwplatform_auto_create_tag', 'Admin: TP Auto'),
  );

  return system_settings_form($form);
}
