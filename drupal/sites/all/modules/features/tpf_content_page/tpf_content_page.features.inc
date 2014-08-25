<?php
/**
 * @file
 * tpf_content_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tpf_content_page_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function tpf_content_page_node_info() {
  $items = array(
    'takepart_page' => array(
      'name' => t('Page'),
      'base' => 'node_content',
      'description' => t('General Page'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
