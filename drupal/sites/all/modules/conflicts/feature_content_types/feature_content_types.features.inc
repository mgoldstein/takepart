<?php
/**
 * @file
 * feature_content_types.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_content_types_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
