<?php

$plugin = array(
  'schema' => 'pm_jwplayer_presets',
  'access' => 'configure pm_jwplayer',
  'title singular' => t('preset'),
  'title plural' => t('presets'),
  'title singular proper' => t('JW Player preset'),
  'title plural proper' => t('JW Player presets'),
  'menu' => array(
    'menu item' => 'pm_jwplayer',
    'menu title' => 'JW Player presets',
    'menu prefix' => 'admin/config/media',
    'menu description' => 'Administer JW Player presets.',
  ),
  'form' => array(
    'settings' => 'pm_jwplayer_ctools_export_ui_form',
  ),
);

function pm_jwplayer_ctools_export_ui_form(&$form, &$form_state) {

  // Get the preset.
  $preset = $form_state['item'];

  // Build the form for the preset itself.
  $controller = new JWPlayerUIPresetFormController($preset);
  $form = $controller->form($form, $form_state);

  // Add the form the preset settings.
  $settings = $preset->settings;

  $controller = new JWPlayerUIPresetSettingsFormController($settings);
  $form['settings'] = $controller->form(array(
    '#type' => 'container',
    '#tree' => TRUE,
    '#weight' => 5,
  ), $form_state);
}
