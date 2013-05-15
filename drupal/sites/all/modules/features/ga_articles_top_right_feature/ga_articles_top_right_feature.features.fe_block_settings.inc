<?php
/**
 * @file
 * ga_articles_top_right_feature.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function ga_articles_top_right_feature_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['boxes-ga_articles_top_right'] = array(
    'cache' => -2,
    'custom' => '0',
    'delta' => 'ga_articles_top_right',
    'module' => 'boxes',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'chunkpart' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'chunkpart',
        'weight' => '-87',
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
        'weight' => '-87',
      ),
      'takepart_embeddable' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'takepart_embeddable',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  return $export;
}
