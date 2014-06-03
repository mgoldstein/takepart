<?php
/**
 * @file
 * tpf_display_boxes.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function tpf_display_boxes_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['boxes-ga_mobile_320x50'] = array(
    'cache' => -2,
    'custom' => 0,
    'delta' => 'ga_mobile_320x50',
    'module' => 'boxes',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'stark' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'stark',
        'weight' => 0,
      ),
      'takepart3' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'takepart3',
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
