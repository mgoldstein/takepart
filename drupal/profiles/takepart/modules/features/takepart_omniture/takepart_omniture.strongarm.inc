<?php
/**
 * @file
 * takepart_omniture.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function takepart_omniture_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_petition_action';
  $strongarm->value = 0;
  $export['comment_anonymous_petition_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_pledge_action';
  $strongarm->value = 0;
  $export['comment_anonymous_pledge_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_profile';
  $strongarm->value = 0;
  $export['comment_anonymous_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_venue';
  $strongarm->value = 0;
  $export['comment_anonymous_venue'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_petition_action';
  $strongarm->value = 1;
  $export['comment_default_mode_petition_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_pledge_action';
  $strongarm->value = 1;
  $export['comment_default_mode_pledge_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_profile';
  $strongarm->value = 0;
  $export['comment_default_mode_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_venue';
  $strongarm->value = 1;
  $export['comment_default_mode_venue'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_petition_action';
  $strongarm->value = '50';
  $export['comment_default_per_page_petition_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_pledge_action';
  $strongarm->value = '50';
  $export['comment_default_per_page_pledge_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_profile';
  $strongarm->value = '50';
  $export['comment_default_per_page_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_venue';
  $strongarm->value = '50';
  $export['comment_default_per_page_venue'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_petition_action';
  $strongarm->value = 1;
  $export['comment_form_location_petition_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_pledge_action';
  $strongarm->value = 1;
  $export['comment_form_location_pledge_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_profile';
  $strongarm->value = 1;
  $export['comment_form_location_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_venue';
  $strongarm->value = 1;
  $export['comment_form_location_venue'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_petition_action';
  $strongarm->value = '2';
  $export['comment_petition_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_pledge_action';
  $strongarm->value = '2';
  $export['comment_pledge_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_petition_action';
  $strongarm->value = '1';
  $export['comment_preview_petition_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_pledge_action';
  $strongarm->value = '1';
  $export['comment_preview_pledge_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_profile';
  $strongarm->value = '0';
  $export['comment_preview_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_venue';
  $strongarm->value = '1';
  $export['comment_preview_venue'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_profile';
  $strongarm->value = '1';
  $export['comment_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_petition_action';
  $strongarm->value = 1;
  $export['comment_subject_field_petition_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_pledge_action';
  $strongarm->value = 1;
  $export['comment_subject_field_pledge_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_profile';
  $strongarm->value = 0;
  $export['comment_subject_field_profile'] = $strongarm;

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
  $strongarm->name = 'field_bundle_settings_node__petition_action';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'embedaction' => array(
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
      'embed' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'embedaction_expanded' => array(
        'custom_settings' => TRUE,
      ),
      'vidpop_map' => array(
        'custom_settings' => TRUE,
      ),
      'action_summary' => array(
        'custom_settings' => TRUE,
      ),
      'medium_preview' => array(
        'custom_settings' => TRUE,
      ),
      'inline_content' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '19',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '2',
        ),
        'xmlsitemap' => array(
          'weight' => '10',
        ),
        'redirect' => array(
          'weight' => '11',
        ),
      ),
      'display' => array(
        'signature_progress' => array(
          'embedaction' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
          'default' => array(
            'weight' => '9',
            'visible' => FALSE,
          ),
          'embedaction_expanded' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
          'action_summary' => array(
            'weight' => '9',
            'visible' => FALSE,
          ),
          'medium_preview' => array(
            'weight' => '9',
            'visible' => FALSE,
          ),
        ),
        'signature_form' => array(
          'embedaction' => array(
            'weight' => '8',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
          'default' => array(
            'weight' => '11',
            'visible' => FALSE,
          ),
          'embedaction_expanded' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
          'action_summary' => array(
            'weight' => '11',
            'visible' => FALSE,
          ),
          'medium_preview' => array(
            'weight' => '11',
            'visible' => FALSE,
          ),
        ),
        'signature_progress_percent' => array(
          'vidpop_map' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'action_summary' => array(
            'weight' => '9',
            'visible' => TRUE,
          ),
          'medium_preview' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '13',
            'visible' => TRUE,
          ),
          'embedaction' => array(
            'weight' => '15',
            'visible' => TRUE,
          ),
          'embedaction_expanded' => array(
            'weight' => '15',
            'visible' => TRUE,
          ),
          'inline_content' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
        'signature_progress_days_left' => array(
          'vidpop_map' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'action_summary' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
          'medium_preview' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '19',
            'visible' => FALSE,
          ),
          'embedaction' => array(
            'weight' => '16',
            'visible' => TRUE,
          ),
          'embedaction_expanded' => array(
            'weight' => '16',
            'visible' => TRUE,
          ),
          'inline_content' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
        'signature_progress_needed' => array(
          'vidpop_map' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'action_summary' => array(
            'weight' => '12',
            'visible' => FALSE,
          ),
          'medium_preview' => array(
            'weight' => '12',
            'visible' => FALSE,
          ),
          'full' => array(
            'weight' => '15',
            'visible' => FALSE,
          ),
          'embedaction' => array(
            'weight' => '18',
            'visible' => FALSE,
          ),
          'embedaction_expanded' => array(
            'weight' => '18',
            'visible' => FALSE,
          ),
          'inline_content' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
        'signature_progress_count' => array(
          'vidpop_map' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'action_summary' => array(
            'weight' => '9',
            'visible' => FALSE,
          ),
          'medium_preview' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'full' => array(
            'weight' => '9',
            'visible' => FALSE,
          ),
          'embedaction' => array(
            'weight' => '11',
            'visible' => FALSE,
          ),
          'embedaction_expanded' => array(
            'weight' => '11',
            'visible' => FALSE,
          ),
          'inline_content' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
        'signature_progress_goal' => array(
          'vidpop_map' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'action_summary' => array(
            'weight' => '11',
            'visible' => TRUE,
          ),
          'medium_preview' => array(
            'weight' => '12',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '17',
            'visible' => FALSE,
          ),
          'embedaction' => array(
            'weight' => '17',
            'visible' => TRUE,
          ),
          'embedaction_expanded' => array(
            'weight' => '17',
            'visible' => TRUE,
          ),
          'inline_content' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
        'signature_action_label' => array(
          'vidpop_map' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'action_summary' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'medium_preview' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'embedaction' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'embedaction_expanded' => array(
            'weight' => '9',
            'visible' => FALSE,
          ),
          'inline_content' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
        'signature_call_to_action' => array(
          'vidpop_map' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'action_summary' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'medium_preview' => array(
            'weight' => '11',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '11',
            'visible' => FALSE,
          ),
          'embedaction' => array(
            'weight' => '12',
            'visible' => FALSE,
          ),
          'embedaction_expanded' => array(
            'weight' => '12',
            'visible' => FALSE,
          ),
          'inline_content' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
        'signature_action_taken' => array(
          'vidpop_map' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'action_summary' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'medium_preview' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
          'full' => array(
            'weight' => '12',
            'visible' => FALSE,
          ),
          'embedaction' => array(
            'weight' => '13',
            'visible' => FALSE,
          ),
          'embedaction_expanded' => array(
            'weight' => '13',
            'visible' => FALSE,
          ),
          'inline_content' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
        'signature_form_ajax' => array(
          'vidpop_map' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'action_summary' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
          'medium_preview' => array(
            'weight' => '7',
            'visible' => FALSE,
          ),
          'full' => array(
            'weight' => '14',
            'visible' => FALSE,
          ),
          'embedaction' => array(
            'weight' => '12',
            'visible' => TRUE,
          ),
          'embedaction_expanded' => array(
            'weight' => '12',
            'visible' => TRUE,
          ),
          'inline_content' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
        'signature_form_redirect' => array(
          'vidpop_map' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'action_summary' => array(
            'weight' => '7',
            'visible' => FALSE,
          ),
          'medium_preview' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'full' => array(
            'weight' => '25',
            'visible' => TRUE,
          ),
          'embedaction' => array(
            'weight' => '14',
            'visible' => FALSE,
          ),
          'embedaction_expanded' => array(
            'weight' => '14',
            'visible' => FALSE,
          ),
          'inline_content' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__petition_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__pledge_action';
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
      'embedaction' => array(
        'custom_settings' => TRUE,
      ),
      'embed' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'vidpop_map' => array(
        'custom_settings' => TRUE,
      ),
      'embedaction_expanded' => array(
        'custom_settings' => TRUE,
      ),
      'action_summary' => array(
        'custom_settings' => TRUE,
      ),
      'medium_preview' => array(
        'custom_settings' => TRUE,
      ),
      'inline_content' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '16',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '2',
        ),
        'redirect' => array(
          'weight' => '12',
        ),
        'xmlsitemap' => array(
          'weight' => '11',
        ),
      ),
      'display' => array(
        'signature_progress' => array(
          'default' => array(
            'weight' => '17',
            'visible' => FALSE,
          ),
          'full' => array(
            'weight' => '6',
            'visible' => TRUE,
          ),
          'embedaction' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
          'embedaction_expanded' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
          'action_summary' => array(
            'weight' => '17',
            'visible' => FALSE,
          ),
          'medium_preview' => array(
            'weight' => '17',
            'visible' => FALSE,
          ),
        ),
        'signature_form' => array(
          'default' => array(
            'weight' => '19',
            'visible' => FALSE,
          ),
          'full' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
          'embedaction' => array(
            'weight' => '7',
            'visible' => TRUE,
          ),
          'embedaction_expanded' => array(
            'weight' => '7',
            'visible' => TRUE,
          ),
          'action_summary' => array(
            'weight' => '19',
            'visible' => FALSE,
          ),
          'medium_preview' => array(
            'weight' => '19',
            'visible' => FALSE,
          ),
        ),
        'signature_progress_percent' => array(
          'default' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
          'vidpop_map' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '30',
            'visible' => FALSE,
          ),
          'action_summary' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
          'medium_preview' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '11',
            'visible' => TRUE,
          ),
          'embedaction' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
          'embedaction_expanded' => array(
            'weight' => '12',
            'visible' => TRUE,
          ),
          'inline_content' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
        'signature_progress_days_left' => array(
          'default' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
          'vidpop_map' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '31',
            'visible' => FALSE,
          ),
          'action_summary' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
          'medium_preview' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '9',
            'visible' => FALSE,
          ),
          'embedaction' => array(
            'weight' => '11',
            'visible' => TRUE,
          ),
          'embedaction_expanded' => array(
            'weight' => '13',
            'visible' => TRUE,
          ),
          'inline_content' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
        'signature_progress_needed' => array(
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'vidpop_map' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '28',
            'visible' => FALSE,
          ),
          'action_summary' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'medium_preview' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'full' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'embedaction' => array(
            'weight' => '13',
            'visible' => FALSE,
          ),
          'embedaction_expanded' => array(
            'weight' => '15',
            'visible' => FALSE,
          ),
          'inline_content' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
        'signature_progress_count' => array(
          'default' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
          'vidpop_map' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '27',
            'visible' => FALSE,
          ),
          'action_summary' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'medium_preview' => array(
            'weight' => '8',
            'visible' => FALSE,
          ),
          'full' => array(
            'weight' => '7',
            'visible' => FALSE,
          ),
          'embedaction' => array(
            'weight' => '12',
            'visible' => FALSE,
          ),
          'embedaction_expanded' => array(
            'weight' => '11',
            'visible' => FALSE,
          ),
          'inline_content' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
        'signature_progress_goal' => array(
          'default' => array(
            'weight' => '9',
            'visible' => TRUE,
          ),
          'vidpop_map' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '17',
            'visible' => FALSE,
          ),
          'action_summary' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
          'medium_preview' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '43',
            'visible' => FALSE,
          ),
          'embedaction' => array(
            'weight' => '12',
            'visible' => TRUE,
          ),
          'embedaction_expanded' => array(
            'weight' => '14',
            'visible' => TRUE,
          ),
          'inline_content' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
        'signature_action_label' => array(
          'default' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
          'vidpop_map' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '16',
            'visible' => FALSE,
          ),
          'action_summary' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'medium_preview' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '8',
            'visible' => FALSE,
          ),
          'embedaction' => array(
            'weight' => '7',
            'visible' => FALSE,
          ),
          'embedaction_expanded' => array(
            'weight' => '12',
            'visible' => FALSE,
          ),
          'inline_content' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
        'signature_call_to_action' => array(
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'vidpop_map' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '18',
            'visible' => FALSE,
          ),
          'action_summary' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'medium_preview' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '57',
            'visible' => FALSE,
          ),
          'embedaction' => array(
            'weight' => '9',
            'visible' => FALSE,
          ),
          'embedaction_expanded' => array(
            'weight' => '7',
            'visible' => FALSE,
          ),
          'inline_content' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
        'signature_action_taken' => array(
          'default' => array(
            'weight' => '7',
            'visible' => TRUE,
          ),
          'vidpop_map' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '19',
            'visible' => FALSE,
          ),
          'action_summary' => array(
            'weight' => '7',
            'visible' => FALSE,
          ),
          'medium_preview' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
          'full' => array(
            'weight' => '14',
            'visible' => FALSE,
          ),
          'embedaction' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'embedaction_expanded' => array(
            'weight' => '9',
            'visible' => FALSE,
          ),
          'inline_content' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
        'signature_form_ajax' => array(
          'default' => array(
            'weight' => '6',
            'visible' => TRUE,
          ),
          'vidpop_map' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '26',
            'visible' => FALSE,
          ),
          'action_summary' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
          'medium_preview' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'full' => array(
            'weight' => '53',
            'visible' => FALSE,
          ),
          'embedaction' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
          'embedaction_expanded' => array(
            'weight' => '53',
            'visible' => TRUE,
          ),
          'inline_content' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
        'signature_form_redirect' => array(
          'default' => array(
            'weight' => '8',
            'visible' => TRUE,
          ),
          'vidpop_map' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '20',
            'visible' => FALSE,
          ),
          'action_summary' => array(
            'weight' => '8',
            'visible' => FALSE,
          ),
          'medium_preview' => array(
            'weight' => '7',
            'visible' => FALSE,
          ),
          'full' => array(
            'weight' => '8',
            'visible' => TRUE,
          ),
          'embedaction' => array(
            'weight' => '11',
            'visible' => FALSE,
          ),
          'embedaction_expanded' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'inline_content' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__pledge_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__profile';
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
      'embedaction_expanded' => array(
        'custom_settings' => FALSE,
      ),
      'action_summary' => array(
        'custom_settings' => FALSE,
      ),
      'medium_preview' => array(
        'custom_settings' => FALSE,
      ),
      'embed' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'inline_content' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '1',
        ),
        'path' => array(
          'weight' => '13',
        ),
        'xmlsitemap' => array(
          'weight' => '14',
        ),
        'redirect' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__profile'] = $strongarm;

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
  $strongarm->name = 'menu_options_petition_action';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_petition_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_pledge_action';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_pledge_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_profile';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_section_front';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_section_front'] = $strongarm;

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
  $strongarm->name = 'menu_parent_petition_action';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_petition_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_pledge_action';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_pledge_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_profile';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_section_front';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_section_front'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_venue';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_venue'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_petition_action';
  $strongarm->value = array();
  $export['node_options_petition_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_pledge_action';
  $strongarm->value = array();
  $export['node_options_pledge_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_profile';
  $strongarm->value = array();
  $export['node_options_profile'] = $strongarm;

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
  $strongarm->name = 'node_preview_petition_action';
  $strongarm->value = '1';
  $export['node_preview_petition_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_pledge_action';
  $strongarm->value = '1';
  $export['node_preview_pledge_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_profile';
  $strongarm->value = '0';
  $export['node_preview_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_section_front';
  $strongarm->value = '1';
  $export['node_preview_section_front'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_topic_front';
  $strongarm->value = '1';
  $export['node_preview_topic_front'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_venue';
  $strongarm->value = '1';
  $export['node_preview_venue'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_petition_action';
  $strongarm->value = 1;
  $export['node_submitted_petition_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_pledge_action';
  $strongarm->value = 1;
  $export['node_submitted_pledge_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_profile';
  $strongarm->value = 0;
  $export['node_submitted_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_section_front';
  $strongarm->value = 0;
  $export['node_submitted_section_front'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_venue';
  $strongarm->value = 1;
  $export['node_submitted_venue'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_codesnippet';
  $strongarm->value = '';
  $export['omniture_codesnippet'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_image_file_location';
  $strongarm->value = '//takepart.122.2o7.net/b/ss/takeparttakepartdev2/1/H.23.4--NS/0';
  $export['omniture_image_file_location'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_js_file_location';
  $strongarm->value = '/profiles/takepart/modules/features/takepart_omniture/js/s_code_h23_core.js';
  $export['omniture_js_file_location'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_track_administrator';
  $strongarm->value = 0;
  $export['omniture_track_administrator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_track_anonymous_user';
  $strongarm->value = 1;
  $export['omniture_track_anonymous_user'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_track_authenticated_user';
  $strongarm->value = 1;
  $export['omniture_track_authenticated_user'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_track_author';
  $strongarm->value = 1;
  $export['omniture_track_author'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_track_contributor';
  $strongarm->value = 0;
  $export['omniture_track_contributor'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_track_editor';
  $strongarm->value = 0;
  $export['omniture_track_editor'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_track_layout_editor';
  $strongarm->value = 0;
  $export['omniture_track_layout_editor'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_var_pagename';
  $strongarm->value = '';
  $export['omniture_var_pagename'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_var_username';
  $strongarm->value = '';
  $export['omniture_var_username'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_version';
  $strongarm->value = 'H.23.4.';
  $export['omniture_version'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_vocabvidvar_1';
  $strongarm->value = '';
  $export['omniture_vocabvidvar_1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_vocabvidvar_2';
  $strongarm->value = '';
  $export['omniture_vocabvidvar_2'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_vocabvidvar_3';
  $strongarm->value = '';
  $export['omniture_vocabvidvar_3'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_vocabvidvar_4';
  $strongarm->value = '';
  $export['omniture_vocabvidvar_4'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_vocabvidvar_5';
  $strongarm->value = '';
  $export['omniture_vocabvidvar_5'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_vocabvidvar_6';
  $strongarm->value = '';
  $export['omniture_vocabvidvar_6'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_vocabvidvar_7';
  $strongarm->value = '';
  $export['omniture_vocabvidvar_7'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'omniture_vocabvidvar_8';
  $strongarm->value = '';
  $export['omniture_vocabvidvar_8'] = $strongarm;

  return $export;
}
