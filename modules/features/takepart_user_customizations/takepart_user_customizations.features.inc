<?php
/**
 * @file
 * takepart_user_customizations.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function takepart_user_customizations_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}
