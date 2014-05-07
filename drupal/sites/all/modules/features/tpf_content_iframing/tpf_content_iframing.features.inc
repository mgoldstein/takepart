<?php
/**
 * @file
 * tpf_content_iframing.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tpf_content_iframing_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
