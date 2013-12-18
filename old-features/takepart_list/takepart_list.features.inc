<?php
/**
 * @file
 * takepart_list.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function takepart_list_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function takepart_list_node_info() {
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
