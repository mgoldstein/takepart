<?php
/**
 * @file
 * tpf_taxonomy_series.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tpf_taxonomy_series_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}
