<?php
/**
 * @file
 * tpf_content_rotator_slide.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tpf_content_rotator_slide_ctools_plugin_api($module = NULL, $api = NULL) {
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
function tpf_content_rotator_slide_node_info() {
  $items = array(
    'takepart_slide' => array(
      'name' => t('Rotator Slide'),
      'base' => 'node_content',
      'description' => t('Used for slides that will be contained in the TakePart Rotator'),
      'has_title' => '1',
      'title_label' => t('Slide Name'),
      'help' => t('Enter a unique name to identify this slide when searching through content.'),
    ),
  );
  return $items;
}
