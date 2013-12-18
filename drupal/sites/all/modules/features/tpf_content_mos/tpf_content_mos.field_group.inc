<?php
/**
 * @file
 * tpf_content_mos.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function tpf_content_mos_field_group_info() {
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
    'weight' => '7',
    'children' => array(
      0 => 'field_closed_heading',
      1 => 'field_closed_message',
      2 => 'field_complete_heading',
      3 => 'field_complete_message',
      4 => 'field_signed_heading',
      5 => 'field_signed_message',
      6 => 'field_thank_you_heading',
      7 => 'field_thank_you_message',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-alternate-states field-group-tab',
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
    'weight' => '3',
    'children' => array(
      0 => 'field_action_main_image',
      1 => 'field_actionheaderimg',
      2 => 'field_actionheaderimghref',
      3 => 'field_action_type',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-main field-group-tab',
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
    'weight' => '5',
    'children' => array(
      0 => 'body',
      1 => 'field_action_form_title',
      2 => 'field_mos_about',
      3 => 'field_mos_user_message_label',
      4 => 'field_short_introduction',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-mos field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_mos|node|mos_action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_share|node|mos_action|form';
  $field_group->group_name = 'group_page_share';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mos_action';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_thank_you_sharing';
  $field_group->data = array(
    'label' => 'Action Page Sharing',
    'weight' => '31',
    'children' => array(
      0 => 'field_social_share_bar',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-page-share field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_page_share|node|mos_action|form'] = $field_group;

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
    'weight' => '6',
    'children' => array(
      0 => 'field_action_organizer',
      1 => 'field_action_sponsor',
      2 => 'field_mos_recipient',
      3 => 'field_action_sponsor_paid',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-sponsor-recipient field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_sponsor_recipient|node|mos_action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tags|node|mos_action|form';
  $field_group->group_name = 'group_tags';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mos_action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tags',
    'weight' => '4',
    'children' => array(
      0 => 'field_display_tag',
      1 => 'field_free_tag',
      2 => 'field_multi_page_campaign',
      3 => 'field_series',
      4 => 'field_topic',
      5 => 'field_admin_tag',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-tags field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tags|node|mos_action|form'] = $field_group;

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
    'weight' => '9',
    'children' => array(
      0 => 'field_tab_action',
      1 => 'field_tab_call_to_action',
      2 => 'field_tab_internal_title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-takeaction-button field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_takeaction_button|node|mos_action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_thank_you_share|node|mos_action|form';
  $field_group->group_name = 'group_thank_you_share';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'mos_action';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_thank_you_sharing';
  $field_group->data = array(
    'label' => 'Thank You Sharing',
    'weight' => '30',
    'children' => array(
      0 => 'field_thank_you_share_bar',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-thank-you-share field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_thank_you_share|node|mos_action|form'] = $field_group;

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
    'weight' => '8',
    'children' => array(
      0 => 'group_thank_you_share',
      1 => 'group_page_share',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-thank-you-sharing field-group-tab',
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
    'weight' => '10',
    'children' => array(
      0 => 'field_thank_you_heading',
      1 => 'field_thank_you_message',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-thank-you-state field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_thank_you_state|node|mos_action|form'] = $field_group;

  return $export;
}
