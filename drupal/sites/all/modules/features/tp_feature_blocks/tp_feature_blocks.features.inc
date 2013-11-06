<?php
/**
 * @file
 * tp_feature_blocks.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tp_feature_blocks_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
