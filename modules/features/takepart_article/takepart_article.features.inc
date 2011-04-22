<?php
/**
 * @file
 * takepart_article.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function takepart_article_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}
