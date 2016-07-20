<?php
/**
 * @file
 * tp_feature_fresh_gallery.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tp_feature_fresh_gallery_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function tp_feature_fresh_gallery_node_info() {
  $items = array(
    'fresh_gallery' => array(
      'name' => t('Fresh Gallery'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
