<?php
/**
 * @file
 * takepart_group.box.inc
 */

/**
 * Implements hook_default_box().
 */
function takepart_group_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-c5c30007';
  $box->plugin_key = 'field';
  $box->title = '';
  $box->description = 'Group Header';
  $box->options = array(
    'entity_type' => 'node',
    'entity_id' => '',
    'bundle' => 'takepart_group',
    'field' => array(
      'field_group_subhead' => 'field_group_subhead',
      'field_group_type' => 'field_group_type',
      'field_group_main_image' => 'field_group_main_image',
      'body' => 0,
      'field_group_location' => 0,
      'field_group_logo' => 0,
      'field_group_topic' => 0,
      'field_group_url' => 0,
      'field_group_context' => 0,
    ),
    'use_page' => 1,
    'exclude_from_content' => 0,
    'view_mode' => 'default',
  );
  $export['box-c5c30007'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-f070c115';
  $box->plugin_key = 'field';
  $box->title = '';
  $box->description = 'Group Left Rail';
  $box->options = array(
    'entity_type' => 'node',
    'entity_id' => '',
    'bundle' => 'takepart_group',
    'field' => array(
      'field_group_logo' => 'field_group_logo',
      'field_group_url' => 'field_group_url',
      'body' => 0,
      'field_group_location' => 0,
      'field_group_main_image' => 0,
      'field_group_subhead' => 0,
      'field_group_topic' => 0,
      'field_group_type' => 0,
      'field_group_context' => 0,
    ),
    'use_page' => 1,
    'exclude_from_content' => 0,
    'view_mode' => 'default',
  );
  $export['box-f070c115'] = $box;

  return $export;
}
