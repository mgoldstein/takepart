<?php
/**
 * @file
 * of_the_day.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function of_the_day_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bean_admin_ui" && $api == "bean") {
    return array("version" => "5");
  }
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function of_the_day_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
