<?php
/**
 * @file
 * tpf_content_pledge_action.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function tpf_content_pledge_action_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_pledge_action';
  $strongarm->value = 0;
  $export['comment_anonymous_pledge_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_pledge_action';
  $strongarm->value = 1;
  $export['comment_default_mode_pledge_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_pledge_action';
  $strongarm->value = '50';
  $export['comment_default_per_page_pledge_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_pledge_action';
  $strongarm->value = 1;
  $export['comment_form_location_pledge_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_pledge_action';
  $strongarm->value = '2';
  $export['comment_pledge_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_pledge_action';
  $strongarm->value = '1';
  $export['comment_preview_pledge_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_pledge_action';
  $strongarm->value = 1;
  $export['comment_subject_field_pledge_action'] = $strongarm;

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
  $strongarm->name = 'menu_options_pledge_action';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_pledge_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_pledge_action';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_pledge_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_pledge_action';
  $strongarm->value = array();
  $export['node_options_pledge_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_pledge_action';
  $strongarm->value = '1';
  $export['node_preview_pledge_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_pledge_action';
  $strongarm->value = 1;
  $export['node_submitted_pledge_action'] = $strongarm;

  return $export;
}
