<?php
/**
 * @file
 * tpf_content_action.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function tpf_content_action_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_action_media|node|action|form';
  $field_group->group_name = 'group_action_media';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'action';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_actions_main';
  $field_group->data = array(
    'label' => 'Media',
    'weight' => '15',
    'children' => array(
      0 => 'field_action_main_image',
      1 => 'field_thumbnail',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_action_media|node|action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_actions_main|node|action|form';
  $field_group->group_name = 'group_actions_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '2',
    'children' => array(
      0 => 'group_action_body',
      1 => 'group_action_content',
      2 => 'group_action_media',
      3 => 'group_action_sponsors',
      4 => 'group_action_terms',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_actions_main|node|action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_deprecated|node|action|form';
  $field_group->group_name = 'group_deprecated';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Deprecated',
    'weight' => '15',
    'children' => array(
      0 => 'field_display_tag',
      1 => 'body',
      2 => 'field_actionheaderimg',
      3 => 'field_actionheaderimghref',
      4 => 'field_altcontent',
      5 => 'field_featured',
      6 => 'field_html_title',
      7 => 'field_multi_page_campaign',
      8 => 'field_short_introduction',
      9 => 'field_tab_internal_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Deprecated',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-deprecated field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_deprecated|node|action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tagging|node|action|form';
  $field_group->group_name = 'group_tagging';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tagging',
    'weight' => '7',
    'children' => array(
      0 => 'field_free_tag',
      1 => 'field_topic',
      2 => 'field_admin_tag',
      3 => 'field_series',
      4 => 'field_sponsored',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tagging field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tagging|node|action|form'] = $field_group;

  return $export;
}
