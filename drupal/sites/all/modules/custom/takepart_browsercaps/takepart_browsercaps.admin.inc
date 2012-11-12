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

  return system_settings_form($form);
}

