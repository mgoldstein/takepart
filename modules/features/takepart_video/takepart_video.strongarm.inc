<?php
/**
 * @file
 * takepart_video.strongarm.inc
 */

/**
 * Implementation of hook_strongarm().
 */
function takepart_video_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_video_series';
  $strongarm->value = 0;
  $export['comment_anonymous_video_series'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_video_series';
  $strongarm->value = 0;
  $export['comment_default_mode_video_series'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_video_series';
  $strongarm->value = '50';
  $export['comment_default_per_page_video_series'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_video_series';
  $strongarm->value = 0;
  $export['comment_form_location_video_series'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_video_series';
  $strongarm->value = '1';
  $export['comment_preview_video_series'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_video_series';
  $strongarm->value = 0;
  $export['comment_subject_field_video_series'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_video_series';
  $strongarm->value = '1';
  $export['comment_video_series'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_video_series';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_video_series'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_video_series';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_video_series'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_video_series';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_video_series'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_video_series';
  $strongarm->value = 1;
  $export['node_submitted_video_series'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_openpublish_video_pattern';
  $strongarm->value = 'video/[node:title]';
  $export['pathauto_node_openpublish_video_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_video_series_pattern';
  $strongarm->value = 'video-series/[node:title]';
  $export['pathauto_node_video_series_pattern'] = $strongarm;

  return $export;
}
