<?php
/**
 * @file
 * takepart_share.box.inc
 */

/**
 * Implements hook_default_box().
 */
function takepart_share_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-72e1be3c';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Take Action Button';
  $box->options = array(
    'body' => '<div class="takepart-take-action"></div>',
    'additional_classes' => '',
  );
  $export['box-72e1be3c'] = $box;

  return $export;
}
