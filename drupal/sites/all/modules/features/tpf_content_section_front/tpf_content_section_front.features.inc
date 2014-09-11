<?php
/**
 * @file
 * tpf_content_section_front.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tpf_content_section_front_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function tpf_content_section_front_node_info() {
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
  drupal_alter('node_info', $items);
  return $items;
}
