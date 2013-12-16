<?php
/**
 * @file
 * takepart_custom.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function takepart_custom_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'takepart_registration_confirmation_page_url';
  $strongarm->value = 'node/19528';
  $export['takepart_registration_confirmation_page_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_view_free_tags';
  $strongarm->value = 'TRUE';
  $export['taxonomy_view_free_tags'] = $strongarm;

  return $export;
}
