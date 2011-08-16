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
  $strongarm->name = 'taxonomy_view_video_series';
  $strongarm->value = 'TRUE';
  $export['taxonomy_view_video_series'] = $strongarm;

  return $export;
}
