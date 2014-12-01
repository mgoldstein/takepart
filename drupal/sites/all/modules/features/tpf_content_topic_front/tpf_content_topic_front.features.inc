<?php
/**
 * @file
 * tpf_content_topic_front.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tpf_content_topic_front_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function tpf_content_topic_front_node_info() {
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
  drupal_alter('node_info', $items);
  return $items;
}
