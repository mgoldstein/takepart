<?php
/**
 * @file
 * takepart_gallery.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function takepart_gallery_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
