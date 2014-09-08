<?php
/**
 * @file
 * tpf_content_photo.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function tpf_content_photo_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_openpublish_photo';
  $strongarm->value = 0;
  $export['comment_anonymous_openpublish_photo'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_openpublish_photo';
  $strongarm->value = 1;
  $export['comment_default_mode_openpublish_photo'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_openpublish_photo';
  $strongarm->value = '50';
  $export['comment_default_per_page_openpublish_photo'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_openpublish_photo';
  $strongarm->value = 1;
  $export['comment_form_location_openpublish_photo'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_openpublish_photo';
  $strongarm->value = '2';
  $export['comment_openpublish_photo'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_openpublish_photo';
  $strongarm->value = '1';
  $export['comment_preview_openpublish_photo'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_openpublish_photo';
  $strongarm->value = 1;
  $export['comment_subject_field_openpublish_photo'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__openpublish_photo';
  $strongarm->value = array(
    'view_modes' => array(
      'inline_content' => array(
        'custom_settings' => FALSE,
      ),
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'vidpop_map' => array(
        'custom_settings' => TRUE,
      ),
      'feature_main' => array(
        'custom_settings' => TRUE,
      ),
      'feature_main_tpl' => array(
        'custom_settings' => TRUE,
      ),
      'feature_secondary' => array(
        'custom_settings' => TRUE,
      ),
      'feature_topic' => array(
        'custom_settings' => TRUE,
      ),
      'feature_video' => array(
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
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'embedaction' => array(
        'custom_settings' => FALSE,
      ),
      'embedaction_expanded' => array(
        'custom_settings' => FALSE,
      ),
      'iframe' => array(
        'custom_settings' => FALSE,
      ),
      'embed' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '4',
        ),
        'xmlsitemap' => array(
          'weight' => '3',
        ),
        'locations' => array(
          'weight' => '5',
        ),
        'metatags' => array(
          'weight' => '7',
        ),
        'redirect' => array(
          'weight' => '6',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__openpublish_photo'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_openpublish_photo';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_openpublish_photo'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_openpublish_photo';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_openpublish_photo'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_openpublish_photo';
  $strongarm->value = array();
  $export['node_options_openpublish_photo'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_openpublish_photo';
  $strongarm->value = '1';
  $export['node_preview_openpublish_photo'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_openpublish_photo';
  $strongarm->value = 1;
  $export['node_submitted_openpublish_photo'] = $strongarm;

  return $export;
}
