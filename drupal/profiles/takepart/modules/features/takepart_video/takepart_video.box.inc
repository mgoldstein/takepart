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

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-1104adce';
  $box->plugin_key = 'ga_ad';
  $box->title = '';
  $box->description = 'GA: Bottom Right';
  $box->options = array(
    'ga_ad_slot' => 'TP3_ROS_RR_BTF_300x600',
  );
  $export['box-1104adce'] = $box;

  $box = new stdClass;
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

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-66c05d6f';
  $box->plugin_key = 'ga_ad';
  $box->title = '';
  $box->description = 'GA: Top Right';
  $box->options = array(
    'ga_ad_slot' => 'TP3_ROS_RR_ATF_300x250',
  );
  $export['box-66c05d6f'] = $box;

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-bb0b625d';
  $box->plugin_key = 'field';
  $box->title = '';
  $box->description = 'Article Display Tag';
  $box->options = array(
    'entity_type' => 'node',
    'entity_id' => '',
    'bundle' => 'openpublish_article',
    'field' => array(
      'field_display_tag' => 'field_display_tag',
      'body' => 0,
      'field_author' => 0,
      'field_article_main_image' => 0,
      'field_free_tag' => 0,
      'field_thumbnail' => 0,
      'field_topic' => 0,
      'field_article_action' => 0,
      'field_article_subhead' => 0,
      'field_promo_headline' => 0,
      'field_promo_text' => 0,
      'field_series' => 0,
      'field_related_content' => 0,
      'field_related_actions' => 0,
      'field_suggest_campaigns' => 0,
      'field_suggest_content' => 0,
      'field_related_campaigns' => 0,
      'field_suggest_actions' => 0,
      'field_multi_page_campaign' => 0,
      'field_tp_campaign_show_title' => 0,
    ),
    'use_page' => 1,
    'exclude_from_content' => 0,
    'view_mode' => 'default',
  );
  $export['box-bb0b625d'] = $box;

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-e9e8814f';
  $box->plugin_key = 'view';
  $box->title = 'Popular Video';
  $box->description = 'Popular Video';
  $box->options = array(
    'view' => 'video--block_1',
    'settings' => array(
      'nid' => '20973+21179+20948',
    ),
    'view_object' => NULL,
    'view_more_text' => '',
    'view_more_link' => '',
    'additional_classes' => '',
  );
  $export['box-e9e8814f'] = $box;

  return $export;
}
