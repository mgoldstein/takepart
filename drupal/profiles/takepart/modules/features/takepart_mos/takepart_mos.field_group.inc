<?php
/**
 * @file
 * takepart_mos.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function takepart_mos_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_alternate_states|node|mos_action|form';
  $field_group->group_name = 'group_alternate_states';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mos_action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Alternate States',
    'weight' => '6',
    'children' => array(
      0 => 'field_closed_heading',
      1 => 'field_closed_message',
      2 => 'field_complete_heading',
      3 => 'field_complete_message',
      4 => 'field_signed_message',
      5 => 'field_signed_heading',
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
  $export['group_alternate_states|node|mos_action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_main|node|mos_action|form';
  $field_group->group_name = 'group_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mos_action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '2',
    'children' => array(
      0 => 'field_action_main_image',
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
  $export['group_main|node|mos_action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mos|node|mos_action|form';
  $field_group->group_name = 'group_mos';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mos_action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Message of Support',
    'weight' => '3',
    'children' => array(
      0 => 'body',
      1 => 'field_mos_about',
      2 => 'field_mos_user_message_label',
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
  $export['group_mos|node|mos_action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sponsor_recipient|node|mos_action|form';
  $field_group->group_name = 'group_sponsor_recipient';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mos_action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sponsor / Recipient',
    'weight' => '7',
    'children' => array(
      0 => 'field_mos_recipient',
      1 => 'field_action_organizer',
      2 => 'field_action_sponsor',
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
  $export['group_sponsor_recipient|node|mos_action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_takeaction_button|node|mos_action|form';
  $field_group->group_name = 'group_takeaction_button';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mos_action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'TakeAction Button',
    'weight' => '5',
    'children' => array(
      0 => 'field_tab_call_to_action',
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
  $export['group_takeaction_button|node|mos_action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_thank_you_sharing|node|mos_action|form';
  $field_group->group_name = 'group_thank_you_sharing';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mos_action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Social Sharing',
    'weight' => '4',
    'children' => array(
      0 => 'field_social_share_bar',
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
  $export['group_thank_you_sharing|node|mos_action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_thank_you_state|node|mos_action|form';
  $field_group->group_name = 'group_thank_you_state';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mos_action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Thank You State',
    'weight' => '8',
    'children' => array(
      0 => 'field_thank_you_message',
      1 => 'field_thank_you_heading',
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
  $export['group_thank_you_state|node|mos_action|form'] = $field_group;

  return $export;
}
