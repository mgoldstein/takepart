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
  $box->delta = 'box-208c3905';
  $box->plugin_key = 'view';
  $box->title = 'Most Popular';
  $box->description = 'Popular Videos';
  $box->options = array(
    'view' => 'video--block_2',
    'settings' => array(
      'nid' => '180+31',
    ),
    'view_object' => NULL,
    'view_more_text' => '',
    'view_more_link' => '',
    'additional_classes' => '',
  );
  $export['box-208c3905'] = $box;

  return $export;
}
