<?php
/**
 * @file
 * takepart_list.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function takepart_list_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__takepart_list';
  $strongarm->value = array(
    'view_modes' => array(
      'of_the_day' => array(
        'custom_settings' => FALSE,
      ),
      'inline_content' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'xmlsitemap' => array(
          'weight' => '8',
        ),
        'path' => array(
          'weight' => '7',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__takepart_list'] = $strongarm;

  return $export;
}
