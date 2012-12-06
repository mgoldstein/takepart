<?php
/**
 * @file
 * feature_content_types.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_content_types_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function feature_content_types_node_info() {
  $items = array(
    'section_front' => array(
      'name' => t('Section Front'),
      'base' => 'node_content',
      'description' => t('Default section front content type.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
