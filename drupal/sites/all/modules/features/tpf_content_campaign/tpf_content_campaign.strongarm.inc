<?php
/**
 * @file
 * tpf_content_campaign.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function tpf_content_campaign_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_takepart_campaign';
  $strongarm->value = 0;
  $export['comment_anonymous_takepart_campaign'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_takepart_campaign';
  $strongarm->value = 1;
  $export['comment_default_mode_takepart_campaign'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_takepart_campaign';
  $strongarm->value = '10';
  $export['comment_default_per_page_takepart_campaign'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_takepart_campaign';
  $strongarm->value = 1;
  $export['comment_form_location_takepart_campaign'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_takepart_campaign';
  $strongarm->value = '0';
  $export['comment_preview_takepart_campaign'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_takepart_campaign';
  $strongarm->value = 0;
  $export['comment_subject_field_takepart_campaign'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_takepart_campaign';
  $strongarm->value = '1';
  $export['comment_takepart_campaign'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__takepart_campaign';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => TRUE,
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
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'embed' => array(
        'custom_settings' => FALSE,
      ),
      'vidpop_map' => array(
        'custom_settings' => TRUE,
      ),
      'embedaction' => array(
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
      'feature_main' => array(
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
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '16',
        ),
        'xmlsitemap' => array(
          'weight' => '4',
        ),
        'metatags' => array(
          'weight' => '21',
        ),
        'redirect' => array(
          'weight' => '19',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__takepart_campaign'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_takepart_campaign';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_takepart_campaign'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_takepart_campaign';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_takepart_campaign'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_takepart_campaign';
  $strongarm->value = array();
  $export['node_options_takepart_campaign'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_takepart_campaign';
  $strongarm->value = '1';
  $export['node_preview_takepart_campaign'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_takepart_campaign';
  $strongarm->value = 0;
  $export['node_submitted_takepart_campaign'] = $strongarm;

  return $export;
}