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
  $box->delta = 'ga_mobile_320x50';
  $box->plugin_key = 'ga_ad';
  $box->title = '';
  $box->description = 'GA: Mobile 320x50';
  $box->options = array(
    'ga_ad_slot' => 'TP_Mobile_320x50',
    'ga_ad_gpt_id' => 'div-gpt-ad-1382144784236-0',
  );
  $export['ga_mobile_320x50'] = $box;

  return $export;
}
