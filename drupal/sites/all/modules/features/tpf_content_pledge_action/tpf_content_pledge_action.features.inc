<?php
/**
 * @file
 * tpf_content_pledge_action.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tpf_content_pledge_action_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function tpf_content_pledge_action_node_info() {
  $items = array(
    'pledge_action' => array(
      'name' => t('Pledge Action'),
      'base' => 'node_content',
      'description' => t('Used to add pledges to the site.'),
      'has_title' => '1',
      'title_label' => t('Page Title'),
      'help' => '',
    ),
  );
  return $items;
}
