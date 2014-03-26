<?php
/**
 * @file
 * tpf_content_poll.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tpf_content_poll_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
