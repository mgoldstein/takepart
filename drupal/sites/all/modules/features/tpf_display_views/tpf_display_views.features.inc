<?php
/**
 * @file
 * tpf_display_views.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tpf_display_views_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function tpf_display_views_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function tpf_display_views_node_info() {
  $items = array(
    'venue' => array(
      'name' => t('Venue'),
      'base' => 'node_content',
      'description' => t('Content that applies to a physical location, such as a business or event place.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
