<?php
/**
 * @file
 * tpf_content_inline_content.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function tpf_content_inline_content_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_ic_tap_widget_sponsor_name'
  $field_bases['field_ic_tap_widget_sponsor_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_ic_tap_widget_sponsor_name',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_ic_tap_widget_sponsor_url'
  $field_bases['field_ic_tap_widget_sponsor_url'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_ic_tap_widget_sponsor_url',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  // Exported field_base: 'field_ic_video'
  $field_bases['field_ic_video'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_ic_video',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'action' => 0,
        'audio' => 0,
        'blog_front' => 0,
        'campaign' => 0,
        'campaign_card_ad' => 0,
        'campaign_card_branding' => 0,
        'campaign_card_empty' => 0,
        'campaign_card_iframe' => 0,
        'campaign_card_media' => 0,
        'campaign_card_multi_column' => 0,
        'campaign_card_news' => 0,
        'campaign_card_social' => 0,
        'campaign_card_tap_widget' => 0,
        'campaign_card_text' => 0,
        'campaign_card_twitter' => 0,
        'campaign_page' => 0,
        'campaign_tray' => 0,
        'feature_article' => 0,
        'feed' => 0,
        'feed_item' => 0,
        'flashcard' => 0,
        'mos_action' => 0,
        'openpublish_article' => 0,
        'openpublish_blog_post' => 0,
        'openpublish_photo' => 0,
        'openpublish_photo_gallery' => 0,
        'openpublish_video' => 0,
        'profile' => 0,
        'section_front' => 0,
        'section_front_wide' => 0,
        'takepart_campaign' => 0,
        'takepart_group' => 0,
        'takepart_list' => 0,
        'takepart_page' => 0,
        'takepart_quick_study' => 0,
        'takepart_slide' => 0,
        'topic_front' => 0,
        'venue' => 0,
        'video' => 'video',
        'video_playlist' => 0,
        'webform' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => '',
        'view_name' => '',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
  );

  return $field_bases;
}
