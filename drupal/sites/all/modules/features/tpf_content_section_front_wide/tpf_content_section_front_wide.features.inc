<?php
/**
 * @file
 * tpf_content_section_front_wide.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tpf_content_section_front_wide_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function tpf_content_section_front_wide_node_info() {
  $items = array(
    'section_front_wide' => array(
      'name' => t('Section Front Wide'),
      'base' => 'node_content',
      'description' => t('Default section front content type, but without right column.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
