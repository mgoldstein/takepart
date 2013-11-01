<?php
/**
 * @file
 * tp_feature_contexts.box.inc
 */

/**
 * Implements hook_default_box().
 */
function tp_feature_contexts_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'ga_homepage_top_right';
  $box->plugin_key = 'ga_ad';
  $box->title = '';
  $box->description = 'GA: Homepage Top Right';
  $box->options = array(
    'ga_ad_slot' => 'TP3_Homepage_RR_ATF_300x250',
    'ga_ad_gpt_id' => 'div-gpt-ad-1376947911678-0',
    'additional_classes' => 'block-boxes-ga_ad',
  );
  $export['ga_homepage_top_right'] = $box;

  return $export;
}
