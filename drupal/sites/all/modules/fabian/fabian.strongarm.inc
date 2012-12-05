<?php
/**
 * @file
 * fabian.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function fabian_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_audio';
  $strongarm->value = 0;
  $export['comment_anonymous_audio'] = $strongarm;

  return $export;
}
