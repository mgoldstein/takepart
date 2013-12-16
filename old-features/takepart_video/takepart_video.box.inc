<?php
/**
 * @file
 * takepart_video.box.inc
 */

/**
 * Implements hook_default_box().
 */
function takepart_video_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-208c3905';
  $box->plugin_key = 'view';
  $box->title = 'Most Popular';
  $box->description = 'Popular Videos';
  $box->options = array(
    'view' => 'video--block_2',
    'settings' => array(
      'nid' => '180+31+183',
    ),
    'view_object' => NULL,
    'view_more_text' => '',
    'view_more_link' => '',
    'additional_classes' => '',
  );
  $export['box-208c3905'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-7afa6acd';
  $box->plugin_key = 'field';
  $box->title = '';
  $box->description = 'Topic Block';
  $box->options = array(
    'entity_type' => 'node',
    'entity_id' => '',
    'bundle' => 'action',
    'field' => array(
      'field_topic' => 'field_topic',
      'body' => 0,
      'field_action_main_image' => 0,
      'field_action_related' => 0,
      'field_action_sponsor' => 0,
      'field_action_type' => 0,
      'field_action_url' => 0,
      'field_free_tag' => 0,
      'field_thumbnail' => 0,
      'field_promo_headline' => 0,
      'field_promo_text' => 0,
      'field_related_content' => 0,
      'field_suggest_campaigns' => 0,
      'field_suggest_content' => 0,
      'field_related_campaigns' => 0,
      'field_suggest_actions' => 0,
      'field_multi_page_campaign' => 0,
    ),
    'use_page' => 1,
    'exclude_from_content' => 0,
    'view_mode' => 'default',
  );
  $export['box-7afa6acd'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-e9e8814f';
  $box->plugin_key = 'view';
  $box->title = 'Popular Video';
  $box->description = 'Popular Video';
  $box->options = array(
    'view' => 'video--block_1',
    'settings' => array(
      'nid' => '25987',
    ),
    'view_object' => NULL,
    'view_more_text' => '',
    'view_more_link' => '',
    'additional_classes' => '',
    'selected_style' => '0',
  );
  $export['box-e9e8814f'] = $box;

  return $export;
}
