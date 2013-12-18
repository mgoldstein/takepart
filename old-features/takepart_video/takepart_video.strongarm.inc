<?php
/**
 * @file
 * takepart_video.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function takepart_video_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_view_video_series';
  $strongarm->value = 'TRUE';
  $export['taxonomy_view_video_series'] = $strongarm;

  return $export;
}
