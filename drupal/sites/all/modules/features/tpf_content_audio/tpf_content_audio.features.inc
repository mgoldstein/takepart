<?php
/**
 * @file
 * tpf_content_audio.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tpf_content_audio_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function tpf_content_audio_node_info() {
  $items = array(
    'audio' => array(
      'name' => t('Audio'),
      'base' => 'node_content',
      'description' => t('Audio node type'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
