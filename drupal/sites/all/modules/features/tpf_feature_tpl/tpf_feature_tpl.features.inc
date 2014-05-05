<?php
/**
 * @file
 * tpf_feature_tpl.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tpf_feature_tpl_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bean_admin_ui" && $api == "bean") {
    return array("version" => "5");
  }
}
