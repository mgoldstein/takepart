<?php
/**
 * @file
 * tpf_content_photo.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tpf_content_photo_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function tpf_content_photo_node_info() {
  $items = array(
    'openpublish_photo' => array(
      'name' => t('Photo'),
      'base' => 'node_content',
      'description' => t('Create content consisting of a single image.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
