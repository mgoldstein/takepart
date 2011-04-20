<?php
/**
 * @file
 * takepart_blog_post.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function takepart_blog_post_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}
