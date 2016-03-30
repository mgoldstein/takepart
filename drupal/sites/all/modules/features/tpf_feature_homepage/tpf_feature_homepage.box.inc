<?php
/**
 * @file
 * tpf_feature_homepage.box.inc
 */

/**
 * Implements hook_default_box().
 */
function tpf_feature_homepage_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'ga_homepage_header';
  $box->plugin_key = 'ga_ad';
  $box->title = '';
  $box->description = 'GA: Homepage Leaderboard';
  $box->options = array(
    'ga_ad_slot' => 'TP_HP_728x90_Responsive',
    'ga_ad_gpt_id' => 'div-gpt-ad-1459362243577-0',
    'ga_ad_width' => '728',
    'ga_ad_height' => '50',
    'additional_classes' => 'leaderboard ad-large-center',
  );
  $export['ga_homepage_header'] = $box;

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

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'ga_hp_1x1_background';
  $box->plugin_key = 'ga_ad';
  $box->title = '';
  $box->description = 'GA: Homepage Background Take-over';
  $box->options = array(
    'ga_ad_slot' => 'TP3_Homepage_Background_1x1',
    'ga_ad_gpt_id' => 'div-gpt-ad-1376947700448-0',
    'additional_classes' => '',
  );
  $export['ga_hp_1x1_background'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'mod_tracking';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Tracking pixel for the Merchants of Doubt campaign';
  $box->options = array(
    'body' => array(
      'value' => '<script language=\'JavaScript1.1\' src=\'//pixel.mathtag.com/event/js?mt_id=837890&mt_adid=148781&v1=&v2=&v3=&s1=&s2=&s3=\'></script>',
      'format' => 'no_wysiwg_full_html',
    ),
  );
  $export['mod_tracking'] = $box;

  return $export;
}
