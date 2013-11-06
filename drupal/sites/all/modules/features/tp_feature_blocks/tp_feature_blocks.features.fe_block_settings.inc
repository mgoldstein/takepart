<?php
/**
 * @file
 * tp_feature_blocks.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function tp_feature_blocks_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['menu_block-2'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => '2',
    'module' => 'menu_block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'chunkpart' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'chunkpart',
        'weight' => '0',
      ),
      'rubik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'rubik',
        'weight' => '0',
      ),
      'takepart3' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'takepart3',
        'weight' => '0',
      ),
      'takepart_embeddable' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'takepart_embeddable',
        'weight' => '0',
      ),
      'tp4' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'tp4',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  return $export;
}
