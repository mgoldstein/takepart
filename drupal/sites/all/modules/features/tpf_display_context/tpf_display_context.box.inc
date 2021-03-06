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
    'ga_ad_slot' => 'TP_HP_728x90_Responsive',
    'ga_ad_gpt_id' => 'div-gpt-ad-1459362243577-0',
    'ga_ad_width' => '320',
    'ga_ad_height' => '50',
    'additional_classes' => '',
  );
  $export['ga_mobile_320x50'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'ga_mobile_320x50_relative';
  $box->plugin_key = 'ga_ad';
  $box->title = '';
  $box->description = 'GA: Mobile 320x50 Top Relative';
  $box->options = array(
    'ga_ad_slot' => 'TP4_ROS_728x90_Responsive',
    'ga_ad_gpt_id' => 'div-gpt-ad-1459481133437-0',
    'ga_ad_width' => '320',
    'ga_ad_height' => '50',
    'additional_classes' => '',
  );
  $export['ga_mobile_320x50_relative'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'ga_ros_interstitial';
  $box->plugin_key = 'ga_ad';
  $box->title = '';
  $box->description = 'GA: ROS Interstitial Video Overlay';
  $box->options = array(
    'ga_ad_slot' => 'VideoOverlay_HP',
    'ga_ad_gpt_id' => 'div-gpt-ad-1438889960490-0',
    'additional_classes' => '',
  );
  $export['ga_ros_interstitial'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'optimizely_fresh';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Optimizely JS code';
  $box->options = array(
    'body' => array(
      'value' => '<script src="//cdn.optimizely.com/js/77413453.js"></script>',
      'format' => 'no_wysiwg_full_html',
    ),
  );
  $export['optimizely_fresh'] = $box;

  return $export;
}
