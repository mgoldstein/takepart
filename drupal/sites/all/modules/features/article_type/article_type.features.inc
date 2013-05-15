<?php
/**
 * @file
 * article_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function article_type_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function article_type_node_info() {
  $items = array(
    'article' => array(
      'name' => t('Not an article after all'),
      'base' => 'node_content',
      'description' => t('This is the new article content type that was added as part of the article redesign. It is not longer going to be used.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
