<?php
/**
 * @file
 * tpf_content_not_an_article.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tpf_content_not_an_article_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function tpf_content_not_an_article_node_info() {
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
