<?php

/**
 * @file
 *   Provides admin settings form(s)
 */

/**
 * General settings form
 */
function jw_player_settings_form($form) {

  drupal_set_title(t('JW Player general settings'));

  $form['jw_player_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Licence key'),
    '#description' => t('If you have a premium account enter your key here'),
    '#default_value' => variable_get('jw_player_key', NULL),
  );
  return system_settings_form($form);
}
