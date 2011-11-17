<?php
/**
 * @file
 * takepart_video.box.inc
 */

/**
 * Implements hook_default_box().
 */
function takepart_video_default_box() {
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
  $box->delta = 'box-208c3905';
  $box->plugin_key = 'view';
  $box->title = 'Most Popular';
  $box->description = 'Popular Videos';
  $box->options = array(
    'view' => 'video--block_2',
    'settings' => array(
      'nid' => '180+31+183',
    ),
    'view_object' => NULL,
    'view_more_text' => '',
    'view_more_link' => '',
    'additional_classes' => '',
  );
  $export['box-208c3905'] = $box;

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
  $box->delta = 'box-e9e8814f';
  $box->plugin_key = 'view';
  $box->title = 'Popular Video';
  $box->description = 'Popular Video';
  $box->options = array(
    'view' => 'video--block_1',
    'settings' => array(
      'nid' => '20075+20036+20033',
    ),
    'view_object' => NULL,
    'view_more_text' => '',
    'view_more_link' => '',
    'additional_classes' => '',
  );
  $export['box-e9e8814f'] = $box;

  return $export;
}
