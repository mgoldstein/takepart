<?php
/**
 * @file
 * tpf_display_context.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function tpf_display_context_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_action_body|node|action|form';
  $field_group->group_name = 'group_action_body';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '3',
    'children' => array(
      0 => 'field_action_main_image',
      1 => 'field_action_type',
      2 => 'field_altcontent',
      3 => 'field_actionheaderimghref',
      4 => 'field_actionheaderimg',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_action_body|node|action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_action_terms|node|action|form';
  $field_group->group_name = 'group_action_terms';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tags',
    'weight' => '4',
    'children' => array(
      0 => 'field_free_tag',
      1 => 'field_topic',
      2 => 'field_multi_page_campaign',
      3 => 'field_display_tag',
      4 => 'field_series',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_action_terms|node|action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_action|node|action|form';
  $field_group->group_name = 'group_action';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Action',
    'weight' => '5',
    'children' => array(
      0 => 'body',
      1 => 'field_action_url',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Action',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'Fields specific to a simple action.',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_action|node|action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_deprecated_fields|node|action|form';
  $field_group->group_name = 'group_deprecated_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Deprecated Fields',
    'weight' => '13',
    'children' => array(
      0 => 'body',
      1 => 'field_multi_page_campaign',
      2 => 'field_altcontent',
      3 => 'field_actionheaderimghref',
      4 => 'field_actionheaderimg',
      5 => 'field_html_title',
      6 => 'field_series',
      7 => 'field_tab_action',
      8 => 'field_tab_internal_title',
      9 => 'field_tab_link_only',
      10 => 'field_short_introduction',
      11 => 'field_featured',
      12 => 'field_admin_tag',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Deprecated Fields',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_deprecated_fields|node|action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_summary|node|action|medium_preview';
  $field_group->group_name = 'group_summary';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'action';
  $field_group->mode = 'medium_preview';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Summary',
    'weight' => '3',
    'children' => array(
      0 => 'field_short_introduction',
      1 => 'signature_call_to_action',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Summary',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'id' => 'node_action_medium_preview_group_summary',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_summary|node|action|medium_preview'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_takeaction_button|node|action|form';
  $field_group->group_name = 'group_takeaction_button';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'TakeAction Button',
    'weight' => '6',
    'children' => array(
      0 => 'field_tab_action',
      1 => 'field_tab_internal_title',
      2 => 'field_tab_call_to_action',
      3 => 'field_tab_link_only',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_takeaction_button|node|action|form'] = $field_group;

  return $export;
}
