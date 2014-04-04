<?php
/**
 * @file
 * tpf_config_block_settings.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function tpf_config_block_settings_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['boxes-box-1104adce'] = array(
    'cache' => -2,
    'custom' => 0,
    'delta' => 'box-1104adce',
    'module' => 'boxes',
    'node_types' => array(
      0 => 'openpublish_article',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'takepart3' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'takepart3',
        'weight' => -83,
      ),
      'tp4' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'tp4',
        'weight' => -83,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['boxes-box-66c05d6f'] = array(
    'cache' => -2,
    'custom' => 0,
    'delta' => 'box-66c05d6f',
    'module' => 'boxes',
    'node_types' => array(
      0 => 'openpublish_article',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'takepart3' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'takepart3',
        'weight' => -82,
      ),
      'tp4' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'tp4',
        'weight' => -82,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['boxes-ga_articles_top'] = array(
    'cache' => -2,
    'custom' => 0,
    'delta' => 'ga_articles_top',
    'module' => 'boxes',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
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

  $export['boxes-ga_articles_top_right'] = array(
    'cache' => -2,
    'custom' => 0,
    'delta' => 'ga_articles_top_right',
    'module' => 'boxes',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'takepart3' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'takepart3',
        'weight' => -87,
      ),
      'tp4' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'tp4',
        'weight' => -87,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
