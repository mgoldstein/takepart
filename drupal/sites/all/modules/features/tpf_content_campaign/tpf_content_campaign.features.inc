<?php
/**
 * @file
 * tpf_content_campaign.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tpf_content_campaign_ctools_plugin_api($module = NULL, $api = NULL) {
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
function tpf_content_campaign_node_info() {
  $items = array(
    'takepart_campaign' => array(
      'name' => t('Legacy Campaigns'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
