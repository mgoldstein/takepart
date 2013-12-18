<?php
/**
 * @file
 * feature_boxes.box.inc
 */

/**
 * Implements hook_default_box().
 */
function feature_boxes_default_box() {
  $export = array();

  $box = new stdClass();
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
      'field_html_title' => 0,
      'field_tab_action_override' => 0,
    ),
    'use_page' => 1,
    'exclude_from_content' => 0,
    'view_mode' => 'default',
    'additional_classes' => '',
  );
  $export['box-bb0b625d'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'ga_articles_top';
  $box->plugin_key = 'ga_ad';
  $box->title = '';
  $box->description = 'GA: Articles Top';
  $box->options = array(
    'ga_ad_slot' => 'TP_Test_ATF_header_728x90',
    'ga_ad_gpt_id' => 'div-gpt-ad-1367984606334-0',
    'additional_classes' => '',
  );
  $export['ga_articles_top'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'takepart';
  $box->plugin_key = 'ga_ad';
  $box->title = '';
  $box->description = 'GA: Leaderboard ROS';
  $box->options = array(
    'ga_ad_slot' => 'TP3_ROS_Leaderboard_728x90',
    'ga_ad_gpt_id' => '1346089138325-0',
  );
  $export['takepart'] = $box;

  return $export;
}
