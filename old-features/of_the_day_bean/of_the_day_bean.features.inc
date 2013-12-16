<?php
/**
 * @file
 * of_the_day_bean.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function of_the_day_bean_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "bean_admin_ui" && $api == "bean") {
    return array("version" => "5");
  }
}
