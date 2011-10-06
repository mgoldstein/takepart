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

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'brightcove_player';
  $strongarm->value = '28137370001';
  $export['brightcove_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'brightcove_player_key';
  $strongarm->value = 'AQ~~,AAAAAF9gv10~,C2TpzJtBrICuOm2BL_HLMajK2gXBu37r';
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
  $strongarm->name = 'comment_anonymous_openpublish_video';
  $strongarm->value = 0;
  $export['comment_anonymous_openpublish_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_openpublish_video';
  $strongarm->value = 0;
  $export['comment_default_mode_openpublish_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_openpublish_video';
  $strongarm->value = '50';
  $export['comment_default_per_page_openpublish_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_openpublish_video';
  $strongarm->value = 1;
  $export['comment_form_location_openpublish_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_openpublish_video';
  $strongarm->value = '2';
  $export['comment_openpublish_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_openpublish_video';
  $strongarm->value = '0';
  $export['comment_preview_openpublish_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_openpublish_video';
  $strongarm->value = 0;
  $export['comment_subject_field_openpublish_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_openpublish_video';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_openpublish_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_openpublish_video';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_openpublish_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_openpublish_video';
  $strongarm->value = array();
  $export['node_options_openpublish_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_openpublish_video';
  $strongarm->value = 1;
  $export['node_submitted_openpublish_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_view_video_series';
  $strongarm->value = 'TRUE';
  $export['taxonomy_view_video_series'] = $strongarm;

  return $export;
}
