<?php
/**
 * @file
 * takepart_campaign.strongarm.inc
 */

/**
 * Implementation of hook_strongarm().
 */
function takepart_campaign_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_takepart_campaign';
  $strongarm->value = 0;
  $export['comment_anonymous_takepart_campaign'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_takepart_campaign';
  $strongarm->value = 1;
  $export['comment_default_mode_takepart_campaign'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_takepart_campaign';
  $strongarm->value = '50';
  $export['comment_default_per_page_takepart_campaign'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_takepart_campaign';
  $strongarm->value = 1;
  $export['comment_form_location_takepart_campaign'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_takepart_campaign';
  $strongarm->value = '1';
  $export['comment_preview_takepart_campaign'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_takepart_campaign';
  $strongarm->value = 1;
  $export['comment_subject_field_takepart_campaign'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_takepart_campaign';
  $strongarm->value = '1';
  $export['comment_takepart_campaign'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_takepart_campaign';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_takepart_campaign'] = $strongarm;

  return $export;
}
