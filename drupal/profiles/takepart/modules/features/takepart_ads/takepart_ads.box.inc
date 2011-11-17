<?php
/**
 * @file
 * takepart_ads.box.inc
 */

/**
 * Implements hook_default_box().
 */
function takepart_ads_default_box() {
  $export = array();

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-1104adce';
  $box->plugin_key = 'ga_ad';
  $box->title = '';
  $box->description = 'GA: Bottom Right';
  $box->options = array(
    'ga_ad_slot' => 'TP3_Home_RR_BTF_300x600',
  );
  $export['box-1104adce'] = $box;

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-66c05d6f';
  $box->plugin_key = 'ga_ad';
  $box->title = '';
  $box->description = 'GA: Top Right';
  $box->options = array(
    'ga_ad_slot' => 'TP3_Home_RR_ATF_300x250',
  );
  $export['box-66c05d6f'] = $box;

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-95b55e7';
  $box->plugin_key = 'field';
  $box->title = 'Sponsored By';
  $box->description = 'Campaign: Sponsored By Block';
  $box->options = array(
    'entity_type' => 'node',
    'entity_id' => '',
    'bundle' => 'takepart_campaign',
    'field' => array(
      'field_tp_campaign_sponsors' => 'field_tp_campaign_sponsors',
      'body' => 0,
      'field_topic' => 0,
      'field_tp_campaign_4_things_link' => 0,
      'field_tp_campaign_5_things_head' => 0,
      'field_tp_campaign_cover_image' => 0,
      'field_tp_campaign_intro_html' => 0,
      'field_tp_campaign_intro_media' => 0,
      'field_tp_campaign_seg_1_html' => 0,
      'field_tp_campaign_seg_1_label' => 0,
      'field_tp_campaign_seg_1_rel' => 0,
      'field_tp_campaign_seg_2_html' => 0,
      'field_tp_campaign_seg_2_label' => 0,
      'field_tp_campaign_seg_2_rel' => 0,
      'field_tp_campaign_seg_3_html' => 0,
      'field_tp_campaign_seg_3_label' => 0,
      'field_tp_campaign_seg_3_rel' => 0,
      'field_tp_campaign_seg_4_html' => 0,
      'field_tp_campaign_seg_4_label' => 0,
      'field_tp_campaign_seg_4_rel' => 0,
      'field_tp_campaign_sl_html' => 0,
      'field_tp_campaign_sl_image' => 0,
      'field_tp_campaign_subheadline' => 0,
      'field_related_actions' => 0,
      'field_suggest_actions' => 0,
      'field_multi_page_campaign' => 0,
      'field_tp_campaign_cover_intro' => 0,
      'field_tp_campaign_sl_nodes' => 0,
      'field_tp_campaign_context' => 0,
      'field_tp_campaign_header' => 0,
      'field_tp_campaign_cover_link' => 0,
      'field_tp_campaign_alliances' => 0,
      'field_tp_campaign_show_title' => 0,
    ),
    'use_page' => 1,
    'exclude_from_content' => 0,
    'view_mode' => 'default',
  );
  $export['box-95b55e7'] = $box;

  return $export;
}
