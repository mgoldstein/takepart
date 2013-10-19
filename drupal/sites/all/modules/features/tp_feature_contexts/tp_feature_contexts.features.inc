<?php
/**
 * @file
 * tp_feature_contexts.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tp_feature_contexts_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
