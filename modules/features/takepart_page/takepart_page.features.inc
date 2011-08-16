<?php
/**
 * @file
 * takepart_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function takepart_page_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function takepart_page_node_info() {
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
  return $items;
}
