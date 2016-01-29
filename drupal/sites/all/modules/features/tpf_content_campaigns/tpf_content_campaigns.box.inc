<?php
/**
 * @file
 * tpf_content_campaigns.box.inc
 */

/**
 * Implements hook_default_box().
 */
function tpf_content_campaigns_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'ga_campaign_header';
  $box->plugin_key = 'ga_ad';
  $box->title = '';
  $box->description = 'Leaderboard Ad for Campaigns';
  $box->options = array(
    'ga_ad_slot' => 'TP_Campaign_728x90_a',
    'ga_ad_gpt_id' => 'div-gpt-ad-1394222082576-0',
  );
  $export['ga_campaign_header'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'ga_campaign_header_mobile';
  $box->plugin_key = 'ga_ad';
  $box->title = '';
  $box->description = 'Leaderboard Ad for Campaigns Mobile';
  $box->options = array(
    'ga_ad_slot' => 'TP_Campaign_320x50_a',
    'ga_ad_gpt_id' => 'div-gpt-ad-1452124185125-0',
    'ga_ad_width' => '320',
    'ga_ad_height' => '50',
  );
  $export['ga_campaign_header_mobile'] = $box;

  return $export;
}
