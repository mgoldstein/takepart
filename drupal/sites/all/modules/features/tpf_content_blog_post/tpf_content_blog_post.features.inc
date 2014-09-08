<?php
/**
 * @file
 * tpf_content_blog_post.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tpf_content_blog_post_ctools_plugin_api($module = NULL, $api = NULL) {
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
function tpf_content_blog_post_node_info() {
  $items = array(
    'openpublish_blog_post' => array(
      'name' => t('Blog Post'),
      'base' => 'node_content',
      'description' => t('Used to create a single post to a column or blog.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
