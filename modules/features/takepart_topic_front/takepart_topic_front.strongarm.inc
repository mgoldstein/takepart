<?php
/**
 * @file
 * takepart_topic_front.strongarm.inc
 */

/**
 * Implementation of hook_strongarm().
 */
function takepart_topic_front_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_topic_front';
  $strongarm->value = 0;
  $export['comment_anonymous_topic_front'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_topic_front';
  $strongarm->value = 1;
  $export['comment_default_mode_topic_front'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_topic_front';
  $strongarm->value = '10';
  $export['comment_default_per_page_topic_front'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_topic_front';
  $strongarm->value = 1;
  $export['comment_form_location_topic_front'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_topic_front';
  $strongarm->value = '1';
  $export['comment_preview_topic_front'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_topic_front';
  $strongarm->value = 0;
  $export['comment_subject_field_topic_front'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_topic_front';
  $strongarm->value = '1';
  $export['comment_topic_front'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_topic_front';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_topic_front'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_view_topic';
  $strongarm->value = 'TRUE';
  $export['taxonomy_view_topic'] = $strongarm;

  return $export;
}
