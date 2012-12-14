<?php

/**
 * @file
 * Admin page callbacks for the TakePart Right Rail Video Popups Support module.
 *
 * @ingroup pathauto
 */

/**
 * Form builder; Configure the video popup settings.
 *
 * @ingroup forms
 * @see system_settings_form()
 */
function takepart_browsercaps_settings_form($form) {
  $form['takepart_vbrowsercaps_testing'] = array(
    '#type'          => 'fieldset',
    '#title'         => t('Testing'),
    '#collapsible'   => TRUE,
    '#collapsed'     => FALSE,
  );

  // testing options
  $options = array(
  TAKEPART_BROWSERCAPS_MODE_NORMAL        => t('Normal operation'),
  TAKEPART_BROWSERCAPS_MODE_FORCE_MOBILE  => t('Force mobile'),
  TAKEPART_BROWSERCAPS_MODE_FORCE_DESKTOP => t('Force desktop'),
  );

  $form['takepart_browsercaps_testing']['takepart_browsercaps_force'] = array(
    '#type' => 'radios',
    '#title' => t('Force device detection'),
    '#default_value' => variable_get('takepart_browsercaps_force', TAKEPART_BROWSERCAPS_MODE_NORMAL),
    '#options' => $options,
    '#description' => t('Force a device mode for testing.'),
  );
  $form['takepart_browsercaps_testing']['takepart_log_requests'] = array(
    '#type' => 'checkbox',
    '#title' => t('Log requests'),
    '#default_value' => variable_get('takepart_log_requests', false),
    '#description' => t('This will create a watchdog entry for each browser detect request. Needless to say, this could result in a very large log file, so do not forget to turn it off!'),
  );

  return system_settings_form($form);
}

