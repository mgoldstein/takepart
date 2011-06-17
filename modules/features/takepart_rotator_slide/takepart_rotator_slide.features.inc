<?php
/**
 * @file
 * takepart_rotator_slide.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function takepart_rotator_slide_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_views_api().
 */
function takepart_rotator_slide_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => 3.0);
  }
}

/**
 * Implementation of hook_node_info().
 */
function takepart_rotator_slide_node_info() {
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
