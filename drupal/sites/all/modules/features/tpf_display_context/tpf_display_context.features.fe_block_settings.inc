<?php
/**
 * @file
 * tpf_display_context.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function tpf_display_context_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['boxes-mod_tracking'] = array(
    'cache' => -2,
    'custom' => 0,
    'delta' => 'mod_tracking',
    'module' => 'boxes',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'fresh' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'fresh',
        'weight' => 0,
      ),
      'tp4' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'tp4',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
