<?php
/**
 * @file
 * takepart_default_content.box.inc
 */

/**
 * Implementation of hook_default_box().
 */
function takepart_default_content_default_box() {
  $export = array();

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-b3bfef52';
  $box->plugin_key = 'view';
  $box->title = '<none>';
  $box->description = 'Blog list';
  $box->options = array(
    'view' => 'blogs--block',
    'settings' => array(
      'tid' => '3+4',
    ),
    'view_object' => NULL,
    'view_more_text' => '',
    'view_more_link' => '',
    'additional_classes' => '',
  );
  $export['box-b3bfef52'] = $box;

  return $export;
}
