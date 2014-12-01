<?php
/**
 * @file
 * tp_custom_nav.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tp_custom_nav_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}
