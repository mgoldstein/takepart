<?php
/**
 * @file
 * takepart_gallery.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function takepart_gallery_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_openpublish_photo_gallery_pattern';
  $strongarm->value = 'photos/[node:title]';
  $export['pathauto_node_openpublish_photo_gallery_pattern'] = $strongarm;

  return $export;
}
