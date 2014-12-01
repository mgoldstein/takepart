<?php
/**
 * @file
 * tpf_content_photo_gallery.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tpf_content_photo_gallery_ctools_plugin_api($module = NULL, $api = NULL) {
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
function tpf_content_photo_gallery_node_info() {
  $items = array(
    'openpublish_photo_gallery' => array(
      'name' => t('Photo Gallery'),
      'base' => 'node_content',
      'description' => t('Create galleries from image media assets available on the site.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
