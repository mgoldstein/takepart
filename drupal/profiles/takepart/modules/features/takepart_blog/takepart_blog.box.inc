<?php
/**
 * @file
 * takepart_blog.box.inc
 */

/**
 * Implements hook_default_box().
 */
function takepart_blog_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-1dae03d3';
  $box->plugin_key = 'field';
  $box->title = '';
  $box->description = 'Blog Post Header';
  $box->options = array(
    'entity_type' => 'node',
    'entity_id' => '',
    'bundle' => 'openpublish_blog_post',
    'field' => array(
      'field_blogpost_subhead' => 'field_blogpost_subhead',
      'field_author' => 'field_author',
      'field_blogpost_main_image' => 'field_blogpost_main_image',
      'body' => 0,
      'field_blogpost_blog' => 0,
      'field_free_tag' => 0,
      'field_thumbnail' => 0,
      'field_topic' => 0,
      'field_display_tag' => 0,
      'field_promo_headline' => 0,
      'field_promo_text' => 0,
      'field_series' => 0,
      'field_blogpost_featured_action' => 0,
      'field_related_content' => 0,
      'field_related_actions' => 0,
      'field_suggest_campaigns' => 0,
      'field_suggest_content' => 0,
      'field_suggest_actions' => 0,
      'field_multi_page_campaign' => 0,
      'field_related_campaign' => 0,
    ),
    'use_page' => 1,
    'exclude_from_content' => 0,
    'view_mode' => 'default',
  );
  $export['box-1dae03d3'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-4eb62add';
  $box->plugin_key = 'field';
  $box->title = '';
  $box->description = 'Current Node Topic';
  $box->options = array(
    'entity_type' => 'node',
    'entity_id' => '',
    'bundle' => 'openpublish_article',
    'field' => array(
      'field_topic' => 'field_topic',
      'field_free_tag' => 0,
      'body' => 0,
      'field_author' => 0,
      'field_article_main_image' => 0,
      'field_thumbnail' => 0,
      'field_article_action' => 0,
      'field_article_subhead' => 0,
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
      'field_tp_campaign_show_title' => 0,
      'field_html_title' => 0,
      'field_tab_action_override' => 0,
    ),
    'use_page' => 1,
    'exclude_from_content' => 0,
    'view_mode' => 'default',
    'additional_classes' => '',
  );
  $export['box-4eb62add'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'our_blogs_summary_1';
  $box->plugin_key = 'view';
  $box->title = 'Our Blogs';
  $box->description = 'Our Blogs';
  $box->options = array(
    'view' => 'blogs--block_1',
    'settings' => array(
      'tid' => '25+26',
    ),
    'view_object' => NULL,
    'view_more_text' => '',
    'view_more_link' => '',
    'additional_classes' => '',
  );
  $export['our_blogs_summary_1'] = $box;

  return $export;
}
