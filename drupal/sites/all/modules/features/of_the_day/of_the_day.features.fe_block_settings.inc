<?php
/**
 * @file
 * of_the_day.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function of_the_day_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['bean--of-the-day'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => '-of-the-day',
    'module' => 'bean',
    'node_types' => array(
      0 => 'openpublish_article',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'chunkpart' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'chunkpart',
        'weight' => -80,
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
