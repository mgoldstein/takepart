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

  $form['jw_player_hosting'] = array(
    '#type' => 'select',
    '#title' => t('Hosting'),
    '#description' => t('How the JW Player JavaScript is hosted'),
    '#default_value' => variable_get('jw_player_hosting', 'cloud'),
    '#options' => array(
      'self' => t('Self-Hosted'),
      'cloud' => t('Cloud-Hosted'),
    ),
  );

  $form['jw_player_account_token'] = array(
    '#type' => 'textfield',
    '#title' => t('Account Token'),
    '#description' => t('If you are using cloud hosting enter your account token here'),
    '#default_value' => variable_get('jw_player_account_token', ''),
  );

  $form['jw_player_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Licence key'),
    '#description' => t('If you have a premium or ads account enter your key here'),
    '#default_value' => variable_get('jw_player_key', ''),
  );

  $form['jw_player_all_pages'] = array(
    '#type' => 'checkbox',
    '#title' => t('Include on all pages'),
    '#description' => t('Include the JW Player script file on all pages.'),
    '#default_value' => variable_get('jw_player_all_pages', FALSE),
  );

  $form['jw_player_js_scope'] = array(
    '#type' => 'select',
    '#title' => t('JavaScript Location'),
    '#description' => t('The location of the included JavaScript.'),
    '#options' => array(
      'header' => t('Header'),
      'footer' => t('Footer'),
    ),
    '#default_value' => variable_get('jw_player_js_scope', 'header'),
  );

  return system_settings_form($form);
}
