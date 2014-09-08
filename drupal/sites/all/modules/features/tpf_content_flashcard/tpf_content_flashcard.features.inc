<?php
/**
 * @file
 * tpf_content_flashcard.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tpf_content_flashcard_ctools_plugin_api($module = NULL, $api = NULL) {
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
function tpf_content_flashcard_node_info() {
  $items = array(
    'flashcard' => array(
      'name' => t('Flashcard'),
      'base' => 'node_content',
      'description' => t('A term to highlight with a definition in other Takepart content.'),
      'has_title' => '1',
      'title_label' => t('Term Name (Administrative Title)'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
