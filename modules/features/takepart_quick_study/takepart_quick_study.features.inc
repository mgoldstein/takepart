<?php
/**
 * @file
 * takepart_quick_study.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function takepart_quick_study_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
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
