<?php
/**
 * @file
 * tpf_content_article.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tpf_content_article_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function tpf_content_article_node_info() {
  $items = array(
    'openpublish_article' => array(
      'name' => t('Article'),
      'base' => 'node_content',
      'description' => t('Used to create individual stories as would appear in News, Sport, or Business content areas.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
