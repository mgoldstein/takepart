<?php
/**
 * @file
 * tpf_display_context.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tpf_display_context_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
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
function tpf_display_context_node_info() {
  $items = array(
    'feed' => array(
      'name' => t('Feed'),
      'base' => 'node_content',
      'description' => t('Subscribe to RSS or Atom feeds. Creates nodes of the content type "Feed item" from feed content.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'feed_item' => array(
      'name' => t('Feed item'),
      'base' => 'node_content',
      'description' => t('This content type is being used for automatically aggregated content from feeds.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'openpublish_video' => array(
      'name' => t('Legacy Video'),
      'base' => 'node_content',
      'description' => t('Create content items with embedded video media assets.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'takepart_campaign' => array(
      'name' => t('Legacy Campaigns'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'venue' => array(
      'name' => t('Venue'),
      'base' => 'node_content',
      'description' => t('Content that applies to a physical location, such as a business or event place.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
