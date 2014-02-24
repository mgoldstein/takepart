<?php
/**
 * @file
 * tpf_content_video.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tpf_content_video_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "pm_jwplayer" && $api == "pm_jwplayer_presets") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function tpf_content_video_node_info() {
  $items = array(
    'openpublish_video' => array(
      'name' => t('Legacy Video'),
      'base' => 'node_content',
      'description' => t('Create content items with embedded video media assets.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'video' => array(
      'name' => t('Video'),
      'base' => 'node_content',
      'description' => t('Use to create individual video stories.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
