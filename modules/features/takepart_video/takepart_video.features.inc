<?php
/**
 * @file
 * takepart_video.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function takepart_video_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => 1);
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function takepart_video_node_info() {
  $items = array(
    'video_series' => array(
      'name' => t('Video Series'),
      'base' => 'node_content',
      'description' => t('A series of related videos.'),
      'has_title' => '1',
      'title_label' => t('Headline'),
      'help' => '',
    ),
  );
  return $items;
}
