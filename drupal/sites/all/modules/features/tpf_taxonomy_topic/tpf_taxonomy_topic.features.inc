<?php
/**
 * @file
 * tpf_taxonomy_topic.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tpf_taxonomy_topic_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
