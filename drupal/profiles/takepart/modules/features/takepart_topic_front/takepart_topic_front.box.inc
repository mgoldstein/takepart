<?php
/**
 * @file
 * takepart_topic_front.box.inc
 */

/**
 * Implements hook_default_box().
 */
function takepart_topic_front_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-f8bddbae';
  $box->plugin_key = 'field';
  $box->title = 'Quick Study';
  $box->description = 'Topic Quick Study';
  $box->options = array(
    'entity_type' => 'taxonomy_term',
    'entity_id' => '',
    'bundle' => 'topic',
    'field' => array(
      'field_topic_featured_quick_study' => 'field_topic_featured_quick_study',
      'field_topic_context' => 0,
      'field_topic_override' => 0,
    ),
    'use_page' => 1,
    'exclude_from_content' => 0,
    'view_mode' => 'default',
  );
  $export['box-f8bddbae'] = $box;

  return $export;
}
