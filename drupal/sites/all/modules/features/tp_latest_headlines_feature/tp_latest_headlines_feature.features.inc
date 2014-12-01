<?php
/**
 * @file
 * tp_latest_headlines_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tp_latest_headlines_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function tp_latest_headlines_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
