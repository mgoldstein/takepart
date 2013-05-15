<?php
/**
 * @file
 * ga_ros_bottom_right_feature.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function ga_ros_bottom_right_feature_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['boxes-box-1104adce'] = array(
    'cache' => -2,
    'custom' => '0',
    'delta' => 'box-1104adce',
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
        'weight' => '4',
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
        'weight' => '-83',
      ),
      'takepart_embeddable' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'takepart_embeddable',
        'weight' => '-35',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  return $export;
}
