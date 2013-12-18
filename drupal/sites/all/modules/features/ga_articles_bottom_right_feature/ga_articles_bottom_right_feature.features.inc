<?php
/**
 * @file
 * ga_articles_bottom_right_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ga_articles_bottom_right_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
}
