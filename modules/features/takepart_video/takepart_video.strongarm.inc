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
  $strongarm->name = 'brightcove_player';
  $strongarm->value = '96360173001';
  $export['brightcove_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'brightcove_player_key';
  $strongarm->value = 'AQ~~,AAAAAF9gv10~,C2TpzJtBrIC5tt2efHDX6tIKw36G5cHq';
  $export['brightcove_player_key'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'brightcove_read_api_key';
  $strongarm->value = 'x0mYnpoSXoAdsH5O1ASnihgPJzzcyu_BUcoCM9WAfbs.';
  $export['brightcove_read_api_key'] = $strongarm;

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
  $strongarm->value = '10';
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

  return $export;
}
