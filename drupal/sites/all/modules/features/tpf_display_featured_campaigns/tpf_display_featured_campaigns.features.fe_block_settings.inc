<?php
/**
 * @file
 * tpf_display_featured_campaigns.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function tpf_display_featured_campaigns_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['bean-featured-campaigns-module'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'featured-campaigns-module',
    'module' => 'bean',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
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
