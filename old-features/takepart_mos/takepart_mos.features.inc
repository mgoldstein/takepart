<?php
/**
 * @file
 * takepart_mos.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function takepart_mos_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function takepart_mos_node_info() {
  $items = array(
    'mos_action' => array(
      'name' => t('Message of Support Action'),
      'base' => 'node_content',
      'description' => t('Used to add messages of support to the site.'),
      'has_title' => '1',
      'title_label' => t('Page Title'),
      'help' => '',
    ),
  );
  return $items;
}
