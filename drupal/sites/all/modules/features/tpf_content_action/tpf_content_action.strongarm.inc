<?php
/**
 * @file
 * tpf_content_action.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function tpf_content_action_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_action';
  $strongarm->value = '2';
  $export['comment_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_action';
  $strongarm->value = 0;
  $export['comment_anonymous_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_action';
  $strongarm->value = 1;
  $export['comment_default_mode_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_action';
  $strongarm->value = '50';
  $export['comment_default_per_page_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_action';
  $strongarm->value = 1;
  $export['comment_form_location_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_action';
  $strongarm->value = '1';
  $export['comment_preview_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_action';
  $strongarm->value = 0;
  $export['comment_subject_field_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__action';
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
        'custom_settings' => TRUE,
      ),
      'embedaction' => array(
        'custom_settings' => FALSE,
      ),
      'vidpop_map' => array(
        'custom_settings' => TRUE,
      ),
      'embedaction_expanded' => array(
        'custom_settings' => FALSE,
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
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '9',
        ),
        'xmlsitemap' => array(
          'weight' => '10',
        ),
        'metatags' => array(
          'weight' => '11',
        ),
        'redirect' => array(
          'weight' => '8',
        ),
        'locations' => array(
          'weight' => '12',
        ),
      ),
      'display' => array(
        'signature_progress_days_left' => array(
          'default' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
          'vidpop_map' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'action_summary' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
          'medium_preview' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
          'embed' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'inline_content' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
        ),
        'signature_action_label' => array(
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'vidpop_map' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'action_summary' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'medium_preview' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'embed' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'inline_content' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
        'signature_call_to_action' => array(
          'default' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'vidpop_map' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'action_summary' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
          'medium_preview' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'embed' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'inline_content' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
        ),
        'signature_action_taken' => array(
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'vidpop_map' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'action_summary' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'medium_preview' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'embed' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'inline_content' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_action';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_action';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_action';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_action';
  $strongarm->value = '1';
  $export['node_preview_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_action';
  $strongarm->value = 1;
  $export['node_submitted_action'] = $strongarm;

  return $export;
}
