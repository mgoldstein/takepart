<?php
/**
 * @file
 * tpf_content_blog_front.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tpf_content_blog_front_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function tpf_content_blog_front_node_info() {
  $items = array(
    'blog_front' => array(
      'name' => t('Blog Front'),
      'base' => 'node_content',
      'description' => t('Landing Page for a Blog'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
