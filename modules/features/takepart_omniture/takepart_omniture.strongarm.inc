<?php
/**
 * @file
 * takepart_omniture.strongarm.inc
 */

/**
 * Implementation of hook_strongarm().
 */
function takepart_omniture_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_codesnippet';
  $strongarm->value = '';
  $export['omniture_codesnippet'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_image_file_location';
  $strongarm->value = 'http://examplecom.112.2O7.net/b/ss/examplecom/1/H.20.3--NS/0';
  $export['omniture_image_file_location'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_js_file_location';
  $strongarm->value = '/profiles/custom/modules/features/takepart_omniture/js/s_code_h23_core.js';
  $export['omniture_js_file_location'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_track_administrator';
  $strongarm->value = 1;
  $export['omniture_track_administrator'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_track_anonymous_user';
  $strongarm->value = 1;
  $export['omniture_track_anonymous_user'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_track_authenticated_user';
  $strongarm->value = 1;
  $export['omniture_track_authenticated_user'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_track_author';
  $strongarm->value = 1;
  $export['omniture_track_author'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_track_contributor';
  $strongarm->value = 1;
  $export['omniture_track_contributor'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_track_editor';
  $strongarm->value = 1;
  $export['omniture_track_editor'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_track_layout_editor';
  $strongarm->value = 1;
  $export['omniture_track_layout_editor'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_var_pagename';
  $strongarm->value = '';
  $export['omniture_var_pagename'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_var_username';
  $strongarm->value = '';
  $export['omniture_var_username'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_version';
  $strongarm->value = 'H.23.0.';
  $export['omniture_version'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_vocabvidvar_1';
  $strongarm->value = '';
  $export['omniture_vocabvidvar_1'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_vocabvidvar_2';
  $strongarm->value = '';
  $export['omniture_vocabvidvar_2'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_vocabvidvar_3';
  $strongarm->value = '';
  $export['omniture_vocabvidvar_3'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_vocabvidvar_4';
  $strongarm->value = '';
  $export['omniture_vocabvidvar_4'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_vocabvidvar_5';
  $strongarm->value = '';
  $export['omniture_vocabvidvar_5'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_vocabvidvar_6';
  $strongarm->value = '';
  $export['omniture_vocabvidvar_6'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_vocabvidvar_7';
  $strongarm->value = '';
  $export['omniture_vocabvidvar_7'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_vocabvidvar_8';
  $strongarm->value = '';
  $export['omniture_vocabvidvar_8'] = $strongarm;

  return $export;
}
