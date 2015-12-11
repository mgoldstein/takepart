<?php
/**
 * @file
 * tpf_content_iframing.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function tpf_content_iframing_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_iframe_bundle_bean';
  $strongarm->value = array(
    'of_the_day' => 'of_the_day',
    'on_our_radar' => 'on_our_radar',
  );
  $export['entity_iframe_bundle_bean'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_iframe_bundle_comment';
  $strongarm->value = array(
    'comment_node_action' => 'comment_node_action',
    'comment_node_openpublish_article' => 'comment_node_openpublish_article',
    'comment_node_campaign' => 'comment_node_campaign',
    'comment_node_campaign_card_branding' => 'comment_node_campaign_card_branding',
    'comment_node_campaign_card_empty' => 'comment_node_campaign_card_empty',
    'comment_node_campaign_card_iframe' => 'comment_node_campaign_card_iframe',
    'comment_node_campaign_card_media' => 'comment_node_campaign_card_media',
    'comment_node_campaign_card_news' => 'comment_node_campaign_card_news',
    'comment_node_campaign_card_social' => 'comment_node_campaign_card_social',
    'comment_node_campaign_card_text' => 'comment_node_campaign_card_text',
    'comment_node_campaign_page' => 'comment_node_campaign_page',
    'comment_node_campaign_tray' => 'comment_node_campaign_tray',
    'comment_node_feature_article' => 'comment_node_feature_article',
    'comment_node_takepart_page' => 'comment_node_takepart_page',
    'comment_node_openpublish_photo_gallery' => 'comment_node_openpublish_photo_gallery',
    'comment_node_profile' => 'comment_node_profile',
    'comment_node_section_front' => 'comment_node_section_front',
    'comment_node_video' => 'comment_node_video',
  );
  $export['entity_iframe_bundle_comment'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_iframe_bundle_field_collection_item';
  $strongarm->value = array(
    'field_listing_collection' => 'field_listing_collection',
    'field_promo_content_collection' => 'field_promo_content_collection',
    'field_color_scheme' => 'field_color_scheme',
    'field_campaign_social_follow' => 'field_campaign_social_follow',
  );
  $export['entity_iframe_bundle_field_collection_item'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_iframe_bundle_file';
  $strongarm->value = array(
    'image' => 'image',
    'video' => 'video',
    'audio' => 'audio',
    'document' => 'document',
  );
  $export['entity_iframe_bundle_file'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_iframe_bundle_inline_content';
  $strongarm->value = array(
    'nodes' => 'nodes',
    'horizontal_rule' => 'horizontal_rule',
    'markup' => 'markup',
    'media' => 'media',
    'newsletter' => 'newsletter',
    'take_action_widget' => 'take_action_widget',
    'image' => 'image',
    'ad_block' => 'ad_block',
    'pull_quote' => 'pull_quote',
  );
  $export['entity_iframe_bundle_inline_content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_iframe_bundle_node';
  $strongarm->value = array(
    'video' => 'video',
    'video_playlist' => 'video_playlist',
    'action' => 0,
    'openpublish_article' => 0,
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
    'takepart_page' => 0,
    'openpublish_photo_gallery' => 0,
    'profile' => 0,
    'section_front' => 0,
  );
  $export['entity_iframe_bundle_node'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_iframe_bundle_taxonomy_term';
  $strongarm->value = array(
    'action_type' => 'action_type',
    'series' => 'series',
    'free_tags' => 'free_tags',
    'topic' => 'topic',
    'group_type' => 'group_type',
    'agency' => 'agency',
    'photo_credit' => 'photo_credit',
    'video_series' => 'video_series',
    'significance' => 'significance',
    'topic_box' => 'topic_box',
    'admin_tag' => 'admin_tag',
    'campaign_categories' => 'campaign_categories',
    'social_follow' => 'social_follow',
  );
  $export['entity_iframe_bundle_taxonomy_term'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_iframe_bundle_user';
  $strongarm->value = array(
    'user' => 'user',
  );
  $export['entity_iframe_bundle_user'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_iframe_embed';
  $strongarm->value = 1;
  $export['entity_iframe_embed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_iframe_height';
  $strongarm->value = '332';
  $export['entity_iframe_height'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_iframe_link';
  $strongarm->value = 1;
  $export['entity_iframe_link'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_iframe_theme';
  $strongarm->value = 'tp4';
  $export['entity_iframe_theme'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_iframe_types';
  $strongarm->value = array(
    'node' => 'node',
    'bean' => 0,
    'comment' => 0,
    'field_collection_item' => 0,
    'inline_content' => 0,
    'file' => 0,
    'taxonomy_term' => 0,
    'user' => 0,
  );
  $export['entity_iframe_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_iframe_width';
  $strongarm->value = '100%';
  $export['entity_iframe_width'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_view_modes';
  $strongarm->value = array(
    'node' => array(
      'inline_content' => array(
        'label' => 'Inline Content',
        'custom settings' => 1,
      ),
    ),
    'file' => array(
      'landscape' => array(
        'label' => 'Landscape',
        'custom settings' => 1,
      ),
      'portrait' => array(
        'label' => 'Portrait',
        'custom settings' => 1,
      ),
    ),
  );
  $export['entity_view_modes'] = $strongarm;

  return $export;
}
