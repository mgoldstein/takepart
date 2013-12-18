<?php
/**
 * @file
 * ga_articles_top_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ga_articles_top_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
}
