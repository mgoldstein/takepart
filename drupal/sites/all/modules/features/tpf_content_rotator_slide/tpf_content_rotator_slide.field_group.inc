<?php
/**
 * @file
 * tpf_content_rotator_slide.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function tpf_content_rotator_slide_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_notes|node|takepart_slide|form';
  $field_group->group_name = 'group_notes';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'takepart_slide';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Notes',
    'weight' => '9',
    'children' => array(
      0 => 'field_description',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => ' group-notes field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_notes|node|takepart_slide|form'] = $field_group;

  return $export;
}
