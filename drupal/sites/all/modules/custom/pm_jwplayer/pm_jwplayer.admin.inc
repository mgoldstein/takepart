<?php

/**
 * Settings form callback.
 */
function pm_jwplayer_settings_form($form, &$form_state) {

  $form['pm_jwplayer_account_token'] = array(
    '#type' => 'textfield',
    '#title' => t('Account Token'),
    '#description' => t('Account token used in the cloud hosting URL.'),
    '#default_value' => variable_get('pm_jwplayer_account_token', ''),
    '#required' => TRUE,
  );

  $form['pm_jwplayer_player_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Player Key'),
    '#description' => t('License key for the JW Player.'),
    '#default_value' => variable_get('pm_jwplayer_player_key', ''),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}
