<?php
/**
 * @file
 * takepart_quick_study.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function takepart_quick_study_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
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
 * Implements hook_node_info().
 */
function takepart_quick_study_node_info() {
  $items = array(
    'takepart_quick_study' => array(
      'name' => t('Quick Study'),
      'base' => 'node_content',
      'description' => t('A Quick info page to be attached to topics'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
