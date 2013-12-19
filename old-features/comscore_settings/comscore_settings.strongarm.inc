<?php
/**
 * @file
 * comscore_settings.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function comscore_settings_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comscore_direct_id';
  $strongarm->value = '14223123';
  $export['comscore_direct_id'] = $strongarm;

  return $export;
}
