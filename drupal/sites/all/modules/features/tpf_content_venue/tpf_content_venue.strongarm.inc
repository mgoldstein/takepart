<?php
/**
 * @file
 * tpf_content_venue.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function tpf_content_venue_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_venue';
  $strongarm->value = 0;
  $export['comment_anonymous_venue'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_venue';
  $strongarm->value = 1;
  $export['comment_default_mode_venue'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_venue';
  $strongarm->value = '50';
  $export['comment_default_per_page_venue'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_venue';
  $strongarm->value = 1;
  $export['comment_form_location_venue'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_venue';
  $strongarm->value = '1';
  $export['comment_preview_venue'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_venue';
  $strongarm->value = 1;
  $export['comment_subject_field_venue'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_venue';
  $strongarm->value = '2';
  $export['comment_venue'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__venue';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'vidpop_map' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'embedaction' => array(
        'custom_settings' => FALSE,
      ),
      'embed' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'embedaction_expanded' => array(
        'custom_settings' => FALSE,
      ),
      'action_summary' => array(
        'custom_settings' => FALSE,
      ),
      'medium_preview' => array(
        'custom_settings' => FALSE,
      ),
      'inline_content' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '7',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '5',
        ),
        'redirect' => array(
          'weight' => '6',
        ),
        'xmlsitemap' => array(
          'weight' => '4',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__venue'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_venue';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_venue'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_venue';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_venue'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_venue';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_venue'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_venue';
  $strongarm->value = '1';
  $export['node_preview_venue'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_venue';
  $strongarm->value = 1;
  $export['node_submitted_venue'] = $strongarm;

  return $export;
}
