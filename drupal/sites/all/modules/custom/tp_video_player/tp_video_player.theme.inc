<?php

/**
 * Helper function for adding client side player configurations.
 */
function tp_video_player_add_player($id, $settings) {
  static $setup_function_added = FALSE;

  if (!$setup_function_added) {
    $js_path = drupal_get_path('module', 'tp_video_player') . '/js/player.js';
    drupal_add_js($js_path, array(
      'type' => 'file',
      'scope' => 'header',
      'weight' => 6,
    ));
    drupal_add_js(array('tp_video_player' => array(
      'key' => variable_get('tp_video_player_key', ''),
    )), 'setting');
    $setup_function_added = TRUE;
  }

  drupal_add_js(array('tp_video_player' => array(
    'settings' => array($id => $settings),
  )), 'setting');
}

/**
 * Theme hook for tp_video_player.
 */
function theme_tp_video_player($variables) {
  $player = $variables['player'];

  tp_video_player_add_player($player['#id'], $player['#settings']);

  $attributes = array(
    'id' => $player['#id'],
    'class' => array('tp-video-player'),
  );

  if (count($player['#allowed_regions']) > 0) {
    $attributes['class'][] = 'loading';
    $attributes['data-allowed-regions'] = implode(',', $player['#allowed_regions']);
  }

  return '<div' . drupal_attributes($attributes) . '></div>';
}
