<?php
/**
 * @file
 * tp_custom_nav.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function tp_custom_nav_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_nav_settings|taxonomy_term|brand|form';
  $field_group->group_name = 'group_nav_settings';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'brand';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Nav Settings',
    'weight' => '0',
    'children' => array(
      0 => 'field_load_context',
      1 => 'field_slim_nav_logo',
      2 => 'field_slim_nav_logo_url',
      3 => 'field_slim_nav_menu',
      4 => 'field_slim_nav_social_menu',
      5 => 'name',
      6 => 'group_slim_nav_colors',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-nav-settings field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_nav_settings|taxonomy_term|brand|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_slim_nav_colors|taxonomy_term|brand|form';
  $field_group->group_name = 'group_slim_nav_colors';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'brand';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_nav_settings';
  $field_group->data = array(
    'label' => 'Color Scheme',
    'weight' => '6',
    'children' => array(
      0 => 'field_slim_nav_bg_color',
      1 => 'field_slim_nav_font_color',
      2 => 'field_slim_nav_mobile_bg',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_slim_nav_colors|taxonomy_term|brand|form'] = $field_group;

  return $export;
}
