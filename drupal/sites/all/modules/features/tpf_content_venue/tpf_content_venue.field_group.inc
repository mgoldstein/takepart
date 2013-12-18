<?php
/**
 * @file
 * tpf_content_venue.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function tpf_content_venue_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_description|node|venue|default';
  $field_group->group_name = 'group_description';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'venue';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_info';
  $field_group->data = array(
    'label' => 'About',
    'weight' => '9',
    'children' => array(
      0 => 'field_storedescription',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-description field-group-htab',
      ),
    ),
  );
  $export['group_description|node|venue|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_description|node|venue|form';
  $field_group->group_name = 'group_description';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'venue';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_info';
  $field_group->data = array(
    'label' => 'About',
    'weight' => '15',
    'children' => array(
      0 => 'field_storedescription',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-description field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_description|node|venue|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info|node|venue|default';
  $field_group->group_name = 'group_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'venue';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Info',
    'weight' => '4',
    'children' => array(
      0 => 'group_description',
      1 => 'group_storeinfo',
      2 => 'group_storemap',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => ' group-info field-group-htabs',
      ),
    ),
  );
  $export['group_info|node|venue|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info|node|venue|form';
  $field_group->group_name = 'group_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'venue';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Info',
    'weight' => '11',
    'children' => array(
      0 => 'group_description',
      1 => 'group_storeinfo',
      2 => 'group_map',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => ' group-info field-group-htabs',
      ),
    ),
  );
  $export['group_info|node|venue|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_map|node|venue|form';
  $field_group->group_name = 'group_map';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'venue';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_info';
  $field_group->data = array(
    'label' => 'Map',
    'weight' => '17',
    'children' => array(
      0 => 'field_google_map',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-map field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_map|node|venue|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_storeinfo|node|venue|default';
  $field_group->group_name = 'group_storeinfo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'venue';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_info';
  $field_group->data = array(
    'label' => 'Info',
    'weight' => '10',
    'children' => array(
      0 => 'field_storeinfo',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-storeinfo field-group-htab',
      ),
    ),
  );
  $export['group_storeinfo|node|venue|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_storeinfo|node|venue|form';
  $field_group->group_name = 'group_storeinfo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'venue';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_info';
  $field_group->data = array(
    'label' => 'Info',
    'weight' => '16',
    'children' => array(
      0 => 'field_storeinfo',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-storeinfo field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_storeinfo|node|venue|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_storemap|node|venue|default';
  $field_group->group_name = 'group_storemap';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'venue';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_info';
  $field_group->data = array(
    'label' => 'Map',
    'weight' => '11',
    'children' => array(
      0 => 'field_google_map',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-storemap field-group-htab',
      ),
    ),
  );
  $export['group_storemap|node|venue|default'] = $field_group;

  return $export;
}
