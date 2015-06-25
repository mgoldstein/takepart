<?php
/**
 * @file
 * tp_intercept.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tp_intercept_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
