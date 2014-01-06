<?php
/**
 * @file
 * tp_feature_feature_article.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tp_feature_feature_article_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function tp_feature_feature_article_node_info() {
  $items = array(
    'feature_article' => array(
      'name' => t('Feature Article'),
      'base' => 'node_content',
      'description' => t('Original longform articles.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
