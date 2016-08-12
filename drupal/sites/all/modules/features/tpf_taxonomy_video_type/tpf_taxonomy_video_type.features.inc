<?php
/**
 * @file
 * tpf_taxonomy_video_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tpf_taxonomy_video_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
