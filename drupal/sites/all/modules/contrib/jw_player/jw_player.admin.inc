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
  $form['jw_player_all_pages'] = array(
    '#type' => 'checkbox',
    '#title' => t('Include on all pages'),
    '#description' => t('Include the JW Player script file on all pages.'),
    '#default_value' => variable_get('jw_player_all_pages', FALSE),
  );
  return system_settings_form($form);
}
