<?php
/**
 * @file
 * openpublish_section_fronts.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function openpublish_section_fronts_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
