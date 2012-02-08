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
    'ga_ad_slot' => 'TP3_ROS_RR_BTF_300x600',
  );
  $export['box-1104adce'] = $box;

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-4f9af2b4';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Fix CSS for Five Things';
  $box->options = array(
    'body' => '<style type="text/css">
.field-name-field-tp-campaign-intro-html .field-items { width:520px; }
</style>',
  );
  $export['box-4f9af2b4'] = $box;

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-66c05d6f';
  $box->plugin_key = 'ga_ad';
  $box->title = '';
  $box->description = 'GA: Top Right';
  $box->options = array(
    'ga_ad_slot' => 'TP3_ROS_RR_ATF_300x250',
  );
  $export['box-66c05d6f'] = $box;

  return $export;
}
