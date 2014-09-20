<?php
/**
 * @file
 * TakePart custom video player global defaults admin.
 */

function tp_video_player_defaults_page($name) {
  $configuration = tp_video_player_load_default_configuration($name);
  if (is_null($configuration)) {
    $configuration = tp_video_player_create_default_configuration($name);
  }
  return drupal_get_form('tp_video_player_global_defaults_form', $configuration);
}

function tp_video_player_global_defaults_form($form, &$form_state, $configuration) {
  $controller = new TakePartVideoPlayerConfigurationFormController($configuration);
  return $controller->form($form, $form_state);
}

function tp_video_player_global_defaults_form_submit($form, $form_state) {
  $configuration = TakePartVideoPlayerConfigurationFormController::instance($form_state)->submit($form_state);
  tp_video_player_save_configuration($configuration);
  drupal_set_message('Defaults saved.');
}
