<?php
/**
 * @file
 * takepart_article.box.inc
 */

/**
 * Implements hook_default_box().
 */
function takepart_article_default_box() {
  $export = array();

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-9753089b';
  $box->plugin_key = 'field';
  $box->title = '';
  $box->description = 'Article Header';
  $box->options = array(
    'entity_type' => 'node',
    'entity_id' => '',
    'bundle' => 'openpublish_article',
    'field' => array(
      'field_article_subhead' => 'field_article_subhead',
      'field_author' => 'field_author',
      'field_article_main_image' => 'field_article_main_image',
      'body' => 0,
      'field_free_tag' => 0,
      'field_thumbnail' => 0,
      'field_topic' => 0,
      'field_article_action' => 0,
      'field_display_tag' => 0,
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
    ),
    'use_page' => 1,
    'exclude_from_content' => 0,
    'view_mode' => 'default',
  );
  $export['box-9753089b'] = $box;

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-b7c16541';
  $box->plugin_key = 'view';
  $box->title = 'Similar Campaigns';
  $box->description = 'Related Campaigns';
  $box->options = array(
    'view' => 'related_campaigns--block_1',
    'settings' => array(
      'null' => '132+28',
      'tid' => '',
    ),
    'view_object' => NULL,
    'view_more_text' => '',
    'view_more_link' => '',
    'additional_classes' => '',
  );
  $export['box-b7c16541'] = $box;

  return $export;
}
