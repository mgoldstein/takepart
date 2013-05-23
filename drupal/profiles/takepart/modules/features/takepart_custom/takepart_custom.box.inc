<?php
/**
 * @file
 * takepart_custom.box.inc
 */

/**
 * Implements hook_default_box().
 */
function takepart_custom_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-1104adce';
  $box->plugin_key = 'ga_ad';
  $box->title = '';
  $box->description = 'GA: ROS Bottom Right';
  $box->options = array(
    'ga_ad_slot' => 'TP3_ROS_RR_BTF_300x600',
    'ga_ad_gpt_id' => 'div-gpt-ad-1345512885535-0',
    'additional_classes' => 'block-boxes-ga_ad',
  );
  $export['box-1104adce'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-66c05d6f';
  $box->plugin_key = 'ga_ad';
  $box->title = '';
  $box->description = 'GA: ROS Top Right';
  $box->options = array(
    'ga_ad_slot' => 'TP3_ROS_RR_ATF_300x250',
    'ga_ad_gpt_id' => 'div-gpt-ad-1367970740963-0',
    'additional_classes' => 'block-boxes-ga_ad',
  );
  $export['box-66c05d6f'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-7fa6e22c';
  $box->plugin_key = 'view';
  $box->title = 'Popular Galleries';
  $box->description = 'News + Issues - Gallery Right Rail';
  $box->options = array(
    'view' => 'photo_galleries--block_2',
    'settings' => array(
      'nid' => '33541+30259+34847',
    ),
    'view_object' => NULL,
    'view_more_text' => '',
    'view_more_link' => '',
    'expose_filters' => 0,
    'additional_classes' => '',
  );
  $export['box-7fa6e22c'] = $box;

  return $export;
}
