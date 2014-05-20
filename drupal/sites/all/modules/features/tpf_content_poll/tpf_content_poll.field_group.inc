<?php
/**
 * @file
 * tpf_content_poll.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function tpf_content_poll_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_promo|node|poll|form';
  $field_group->group_name = 'group_promo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'poll';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Promo',
    'weight' => '4',
    'children' => array(
      0 => 'field_promo_headline',
      1 => 'field_thumbnail',
      2 => 'field_promo_text',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-promo field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_promo|node|poll|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tagging|node|poll|form';
  $field_group->group_name = 'group_tagging';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'poll';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tagging',
    'weight' => '4',
    'children' => array(
      0 => 'field_admin_tag',
      1 => 'field_free_tag',
      2 => 'field_topic',
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
  $export['group_tagging|node|poll|form'] = $field_group;

  return $export;
}
