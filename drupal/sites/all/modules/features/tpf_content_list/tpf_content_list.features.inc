<?php
/**
 * @file
 * tpf_content_list.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tpf_content_list_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function tpf_content_list_node_info() {
  $items = array(
    'takepart_list' => array(
      'name' => t('List'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
