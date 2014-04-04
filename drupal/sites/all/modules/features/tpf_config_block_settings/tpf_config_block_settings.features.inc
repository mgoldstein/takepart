<?php
/**
 * @file
 * tpf_config_block_settings.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tpf_config_block_settings_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
}
