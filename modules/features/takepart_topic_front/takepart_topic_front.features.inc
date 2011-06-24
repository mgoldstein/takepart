<?php
/**
 * @file
 * takepart_topic_front.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function takepart_topic_front_ctools_plugin_api() {
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
 * Implementation of hook_views_api().
 */
function takepart_topic_front_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implementation of hook_node_info().
 */
function takepart_topic_front_node_info() {
  $items = array(
    'topic_front' => array(
      'name' => t('Topic Front'),
      'base' => 'node_content',
      'description' => t('Custom Page for a Topic'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
