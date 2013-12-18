<?php
/**
 * @file
 * takepart_audio.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function takepart_audio_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function takepart_audio_node_info() {
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
