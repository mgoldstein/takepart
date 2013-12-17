<?php
/**
 * @file
 * tpf_display_boxes.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tpf_display_boxes_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
}
