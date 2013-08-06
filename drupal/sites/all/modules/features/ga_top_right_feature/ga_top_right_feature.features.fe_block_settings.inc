<?php
/**
 * @file
 * ga_top_right_feature.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function ga_top_right_feature_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['boxes-box-66c05d6f'] = array(
    'cache' => -2,
    'custom' => '0',
    'delta' => 'box-66c05d6f',
    'module' => 'boxes',
    'node_types' => array(
      0 => 'openpublish_article',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'chunkpart' => array(
        'region' => 'sidebar_second',
        'status' => '1',
        'theme' => 'chunkpart',
        'weight' => '-100',
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
        'weight' => '-82',
      ),
      'takepart_embeddable' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'takepart_embeddable',
        'weight' => '-32',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  return $export;
}
