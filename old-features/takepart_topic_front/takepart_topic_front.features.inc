<?php
/**
 * @file
 * takepart_topic_front.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function takepart_topic_front_ctools_plugin_api() {
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
 * Implements hook_views_api().
 */
function takepart_topic_front_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
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
