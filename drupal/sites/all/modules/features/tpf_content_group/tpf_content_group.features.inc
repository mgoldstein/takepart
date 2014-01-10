<?php
/**
 * @file
 * tpf_content_group.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tpf_content_group_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function tpf_content_group_node_info() {
  $items = array(
    'takepart_group' => array(
      'name' => t('Group'),
      'base' => 'node_content',
      'description' => t('Group Content Type'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}