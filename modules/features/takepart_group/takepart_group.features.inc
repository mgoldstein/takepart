<?php
/**
 * @file
 * takepart_group.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function takepart_group_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implementation of hook_node_info().
 */
function takepart_group_node_info() {
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
