<?php
/**
 * @file
 * tpf_taxonomy_series.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function tpf_taxonomy_series_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_graphic_header|taxonomy_term|series|form';
  $field_group->group_name = 'group_graphic_header';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'series';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Graphic Header',
    'weight' => '2',
    'children' => array(
      0 => 'field_series_graphic_header',
      1 => 'field_series_graphic_header_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_graphic_header|taxonomy_term|series|form'] = $field_group;

  return $export;
}
