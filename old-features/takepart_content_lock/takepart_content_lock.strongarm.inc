<?php
/**
 * @file
 * takepart_content_lock.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function takepart_content_lock_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_lock_admin_cancelbutton';
  $strongarm->value = 1;
  $export['content_lock_admin_cancelbutton'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_lock_admin_verbose';
  $strongarm->value = 1;
  $export['content_lock_admin_verbose'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_lock_allowed_formats';
  $strongarm->value = array(
    'full_html' => 0,
    'limited_html' => 0,
    'plain_text' => 0,
  );
  $export['content_lock_allowed_formats'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_lock_allowed_node_types';
  $strongarm->value = array(
    'openpublish_article' => 0,
    'openpublish_blog_post' => 0,
    'openpublish_photo' => 0,
    'openpublish_photo_gallery' => 0,
    'openpublish_video' => 0,
    'action' => 0,
    'audio' => 0,
    'blog_front' => 0,
    'takepart_campaign' => 0,
    'takepart_group' => 0,
    'takepart_page' => 0,
    'takepart_quick_study' => 0,
    'takepart_slide' => 0,
    'topic_front' => 0,
    'video_series' => 0,
    'openpublish_site_page' => 0,
    'profile' => 0,
    'section_front' => 0,
    'webform' => 0,
  );
  $export['content_lock_allowed_node_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_lock_timeout_minutes';
  $strongarm->value = '30';
  $export['content_lock_timeout_minutes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_lock_timeout_on_edit';
  $strongarm->value = 1;
  $export['content_lock_timeout_on_edit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_lock_unload_js';
  $strongarm->value = 1;
  $export['content_lock_unload_js'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_lock_unload_js_message';
  $strongarm->value = 'If you proceed, ALL of your changes will be lost.';
  $export['content_lock_unload_js_message'] = $strongarm;

  return $export;
}
