<?php
/**
 * @file
 * tpf_display_context.box.inc
 */

/**
 * Implements hook_default_box().
 */
function tpf_display_context_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'ga_interstitial';
  $box->plugin_key = 'ga_ad';
  $box->title = '';
  $box->description = 'GA: ROS Interstitial Ad';
  $box->options = array(
    'ga_ad_slot' => 'TP_Mobile_Interstitial_1x1',
    'ga_ad_gpt_id' => 'div-gpt-ad-1413399742891-0',
    'additional_classes' => '',
  );
  $export['ga_interstitial'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'ga_mobile_320x50_relative';
  $box->plugin_key = 'ga_ad';
  $box->title = '';
  $box->description = 'GA: Mobile 320x50';
  $box->options = array(
    'ga_ad_slot' => 'TP_Mobile_320x50',
    'ga_ad_gpt_id' => 'div-gpt-ad-1382144784236-0a',
  );
  $export['ga_mobile_320x50_relative'] = $box;

  return $export;
}
