<?php
/**
 * @file
 * tpf_content_petition_action.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function tpf_content_petition_action_strongarm() {
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
  $strongarm->name = 'comment_default_mode_petition_action';
  $strongarm->value = 1;
  $export['comment_default_mode_petition_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_petition_action';
  $strongarm->value = '50';
  $export['comment_default_per_page_petition_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_petition_action';
  $strongarm->value = 1;
  $export['comment_form_location_petition_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_petition_action';
  $strongarm->value = '2';
  $export['comment_petition_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_petition_action';
  $strongarm->value = '1';
  $export['comment_preview_petition_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_petition_action';
  $strongarm->value = 1;
  $export['comment_subject_field_petition_action'] = $strongarm;

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
  $strongarm->name = 'menu_options_petition_action';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_petition_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_petition_action';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_petition_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_petition_action';
  $strongarm->value = array();
  $export['node_options_petition_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_petition_action';
  $strongarm->value = '1';
  $export['node_preview_petition_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_petition_action';
  $strongarm->value = 1;
  $export['node_submitted_petition_action'] = $strongarm;

  return $export;
}
