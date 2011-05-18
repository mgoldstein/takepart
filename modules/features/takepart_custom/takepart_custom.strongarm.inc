<?php
/**
 * @file
 * takepart_custom.strongarm.inc
 */

/**
 * Implementation of hook_strongarm().
 */
function takepart_custom_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_view_free_tags';
  $strongarm->value = 'TRUE';
  $export['taxonomy_view_free_tags'] = $strongarm;

  return $export;
}
