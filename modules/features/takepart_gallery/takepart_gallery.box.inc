<?php
/**
 * @file
 * takepart_gallery.box.inc
 */

/**
 * Implements hook_default_box().
 */
function takepart_gallery_default_box() {
  $export = array();

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-7d1ce087';
  $box->plugin_key = 'view';
  $box->title = 'Popular Galleries';
  $box->description = 'Popular Galleries';
  $box->options = array(
    'view' => 'photo_galleries--block',
    'settings' => array(
      'nid' => '169+66+105',
    ),
    'view_object' => NULL,
    'view_more_text' => '',
    'view_more_link' => '',
    'additional_classes' => '',
  );
  $export['box-7d1ce087'] = $box;

  return $export;
}
