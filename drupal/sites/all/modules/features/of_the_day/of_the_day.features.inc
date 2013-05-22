<?php
/**
 * @file
 * of_the_day.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function of_the_day_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function of_the_day_views_api() {
  return array("version" => "3.0");
}
