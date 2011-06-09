<?php
/**
 * @file
 * takepart_blog.box.inc
 */

/**
 * Implementation of hook_default_box().
 */
function takepart_blog_default_box() {
  $export = array();

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'our_blogs_summary_1';
  $box->plugin_key = 'view';
  $box->title = '';
  $box->description = 'curated blog listings box for Our Blogs';
  $box->options = array(
    'view' => 'blogs--block_1',
    'settings' => array(),
    'view_object' => NULL,
    'view_more_text' => '',
    'view_more_link' => '',
    'additional_classes' => '',
  );
  $export['our_blogs_summary_1'] = $box;

  return $export;
}
