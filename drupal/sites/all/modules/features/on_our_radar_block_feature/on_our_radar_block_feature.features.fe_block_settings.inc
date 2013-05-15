<?php
/**
 * @file
 * on_our_radar_block_feature.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function on_our_radar_block_feature_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['bean-on-our-radar-block'] = array(
    'cache' => 1,
    'custom' => '0',
    'delta' => 'on-our-radar-block',
    'module' => 'bean',
    'node_types' => array(
      0 => 'article',
      1 => 'openpublish_article',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'chunkpart' => array(
        'region' => 'sidebar_second',
        'status' => '1',
        'theme' => 'chunkpart',
        'weight' => '3',
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
    ),
    'title' => 'On Our Radar',
    'visibility' => '0',
  );

  return $export;
}
