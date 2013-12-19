<?php
/**
 * @file
 * tpf_content_pledge_action.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function tpf_content_pledge_action_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_alternate_states|node|pledge_action|form';
  $field_group->group_name = 'group_alternate_states';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pledge_action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Alternate States',
    'weight' => '7',
    'children' => array(
      0 => 'field_thank_you_message',
      1 => 'field_closed_message',
      2 => 'field_signed_message',
      3 => 'field_closed_heading',
      4 => 'field_complete_heading',
      5 => 'field_signed_heading',
      6 => 'field_thank_you_heading',
      7 => 'field_complete_message',
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
  $export['group_alternate_states|node|pledge_action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_closed_fields|node|pledge_action|embedaction';
  $field_group->group_name = 'group_closed_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pledge_action';
  $field_group->mode = 'embedaction';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Closed Fields',
    'weight' => '6',
    'children' => array(
      0 => 'field_closed_message',
      1 => 'field_closed_heading',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Closed Fields',
      'instance_settings' => array(
        'classes' => 'signature-state-fields closed inactive group-closed-fields field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_closed_fields|node|pledge_action|embedaction'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_closed_fields|node|pledge_action|embedaction_expanded';
  $field_group->group_name = 'group_closed_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pledge_action';
  $field_group->mode = 'embedaction_expanded';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Closed Fields',
    'weight' => '6',
    'children' => array(
      0 => 'field_closed_message',
      1 => 'field_closed_heading',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Closed Fields',
      'instance_settings' => array(
        'classes' => 'signature-state-fields closed inactive group-closed-fields field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_closed_fields|node|pledge_action|embedaction_expanded'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_closed_fields|node|pledge_action|full';
  $field_group->group_name = 'group_closed_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pledge_action';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Closed Fields',
    'weight' => '5',
    'children' => array(
      0 => 'field_closed_message',
      1 => 'field_closed_heading',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Closed Fields',
      'instance_settings' => array(
        'classes' => 'signature-state-fields closed inactive group-closed-fields field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_closed_fields|node|pledge_action|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_complete_fields|node|pledge_action|embedaction';
  $field_group->group_name = 'group_complete_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pledge_action';
  $field_group->mode = 'embedaction';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Complete Fields',
    'weight' => '3',
    'children' => array(
      0 => 'field_complete_heading',
      1 => 'field_complete_message',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Complete Fields',
      'instance_settings' => array(
        'classes' => 'signature-state-fields complete inactive group-complete-fields field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_complete_fields|node|pledge_action|embedaction'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_complete_fields|node|pledge_action|embedaction_expanded';
  $field_group->group_name = 'group_complete_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pledge_action';
  $field_group->mode = 'embedaction_expanded';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Complete Fields',
    'weight' => '3',
    'children' => array(
      0 => 'field_complete_heading',
      1 => 'field_complete_message',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Complete Fields',
      'instance_settings' => array(
        'classes' => 'signature-state-fields complete inactive group-complete-fields field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_complete_fields|node|pledge_action|embedaction_expanded'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_complete_fields|node|pledge_action|full';
  $field_group->group_name = 'group_complete_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pledge_action';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Complete Fields',
    'weight' => '2',
    'children' => array(
      0 => 'signature_progress_percent',
      1 => 'group_complete_message',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Complete Fields',
      'instance_settings' => array(
        'classes' => 'signature-state-fields signed unsigned closed complete inactive group-complete-fields field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_complete_fields|node|pledge_action|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_complete_message|node|pledge_action|full';
  $field_group->group_name = 'group_complete_message';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pledge_action';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_complete_fields';
  $field_group->data = array(
    'label' => 'Complete Message',
    'weight' => '12',
    'children' => array(
      0 => 'field_complete_heading',
      1 => 'field_complete_message',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Complete Message',
      'instance_settings' => array(
        'classes' => ' group-complete-message field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_complete_message|node|pledge_action|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_main|node|pledge_action|form';
  $field_group->group_name = 'group_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pledge_action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '3',
    'children' => array(
      0 => 'field_actionheaderimghref',
      1 => 'field_actionheaderimg',
      2 => 'field_action_type',
      3 => 'field_action_main_image',
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
  $export['group_main|node|pledge_action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_more_or_less|node|pledge_action|embedaction';
  $field_group->group_name = 'group_more_or_less';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pledge_action';
  $field_group->mode = 'embedaction';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'More or Less Fields',
    'weight' => '1',
    'children' => array(
      0 => 'group_less_view',
      1 => 'group_more_view',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'More or Less Fields',
      'instance_settings' => array(
        'classes' => 'more-or-less-container group-more-or-less field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_more_or_less|node|pledge_action|embedaction'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_more_or_less|node|pledge_action|embedaction_expanded';
  $field_group->group_name = 'group_more_or_less';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pledge_action';
  $field_group->mode = 'embedaction_expanded';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'More of Less',
    'weight' => '1',
    'children' => array(
      0 => 'group_less_view',
      1 => 'group_more_view',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'More of Less',
      'instance_settings' => array(
        'classes' => 'more-or-less-container group-more-or-less field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_more_or_less|node|pledge_action|embedaction_expanded'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_more_or_less|node|pledge_action|full';
  $field_group->group_name = 'group_more_or_less';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pledge_action';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'More or Less',
    'weight' => '1',
    'children' => array(
      0 => 'group_less_view',
      1 => 'group_more_view',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'More or Less',
      'instance_settings' => array(
        'classes' => 'more-or-less-container group-more-or-less field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_more_or_less|node|pledge_action|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_more_view|node|pledge_action|embedaction';
  $field_group->group_name = 'group_more_view';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pledge_action';
  $field_group->mode = 'embedaction';
  $field_group->parent_name = 'group_more_or_less';
  $field_group->data = array(
    'label' => 'More View Fields',
    'weight' => '63',
    'children' => array(
      0 => 'field_pledge_action_long',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'More View Fields',
      'instance_settings' => array(
        'classes' => 'more-or-less-more-view group-more-view field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_more_view|node|pledge_action|embedaction'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_more_view|node|pledge_action|embedaction_expanded';
  $field_group->group_name = 'group_more_view';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pledge_action';
  $field_group->mode = 'embedaction_expanded';
  $field_group->parent_name = 'group_more_or_less';
  $field_group->data = array(
    'label' => 'More View Fields',
    'weight' => '12',
    'children' => array(
      0 => 'field_pledge_action_long',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'More View Fields',
      'instance_settings' => array(
        'classes' => 'more-or-less-more-view group-more-view field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_more_view|node|pledge_action|embedaction_expanded'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_more_view|node|pledge_action|full';
  $field_group->group_name = 'group_more_view';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pledge_action';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_more_or_less';
  $field_group->data = array(
    'label' => 'More View Fields',
    'weight' => '20',
    'children' => array(
      0 => 'field_pledge_action_long',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'More View Fields',
      'instance_settings' => array(
        'classes' => 'more-or-less-more-view group-more-view field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_more_view|node|pledge_action|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_share|node|pledge_action|form';
  $field_group->group_name = 'group_page_share';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pledge_action';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_social_sharing';
  $field_group->data = array(
    'label' => 'Action Page Sharing',
    'weight' => '30',
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
  $export['group_page_share|node|pledge_action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pledge|node|pledge_action|form';
  $field_group->group_name = 'group_pledge';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pledge_action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Pledge',
    'weight' => '5',
    'children' => array(
      0 => 'body',
      1 => 'field_action_form_title',
      2 => 'field_pledge_action_long',
      3 => 'field_short_introduction',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-pledge field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_pledge|node|pledge_action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_signature_fields|node|pledge_action|embedaction';
  $field_group->group_name = 'group_signature_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pledge_action';
  $field_group->mode = 'embedaction';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Signature Fields',
    'weight' => '4',
    'children' => array(
      0 => 'body',
      1 => 'signature_form_ajax',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Signature Fields',
      'instance_settings' => array(
        'classes' => 'signature-state-fields unsigned signed active group-signature-fields field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_signature_fields|node|pledge_action|embedaction'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_signature_fields|node|pledge_action|embedaction_expanded';
  $field_group->group_name = 'group_signature_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pledge_action';
  $field_group->mode = 'embedaction_expanded';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Signature Fields',
    'weight' => '4',
    'children' => array(
      0 => 'body',
      1 => 'signature_form_ajax',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Signature Fields',
      'instance_settings' => array(
        'classes' => 'signature-state-fields unsigned signed active group-signature-fields field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_signature_fields|node|pledge_action|embedaction_expanded'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_signature_fields|node|pledge_action|full';
  $field_group->group_name = 'group_signature_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pledge_action';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Signature Fields',
    'weight' => '3',
    'children' => array(
      0 => 'body',
      1 => 'field_action_form_title',
      2 => 'signature_form_redirect',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Signature Fields',
      'instance_settings' => array(
        'classes' => 'signature-state-fields unsigned active group-signature-fields field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_signature_fields|node|pledge_action|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_signed_fields|node|pledge_action|full';
  $field_group->group_name = 'group_signed_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pledge_action';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Already Signed Fields',
    'weight' => '4',
    'children' => array(
      0 => 'field_signed_message',
      1 => 'field_signed_heading',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Already Signed Fields',
      'instance_settings' => array(
        'classes' => 'signature-state-fields signed inactive group-signed-fields field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_signed_fields|node|pledge_action|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_social_sharing|node|pledge_action|form';
  $field_group->group_name = 'group_social_sharing';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pledge_action';
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
        'classes' => ' group-social-sharing field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_social_sharing|node|pledge_action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sponsor|node|pledge_action|form';
  $field_group->group_name = 'group_sponsor';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pledge_action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sponsor(s)',
    'weight' => '6',
    'children' => array(
      0 => 'field_action_sponsor',
      1 => 'field_action_organizer',
      2 => 'field_action_sponsor_paid',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-sponsor field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_sponsor|node|pledge_action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_summary|node|pledge_action|medium_preview';
  $field_group->group_name = 'group_summary';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pledge_action';
  $field_group->mode = 'medium_preview';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Summary',
    'weight' => '3',
    'children' => array(
      0 => 'field_short_introduction',
      1 => 'signature_progress_goal',
      2 => 'signature_call_to_action',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Summary',
      'instance_settings' => array(
        'classes' => ' group-summary field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_summary|node|pledge_action|medium_preview'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tags|node|pledge_action|form';
  $field_group->group_name = 'group_tags';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pledge_action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tags',
    'weight' => '4',
    'children' => array(
      0 => 'field_display_tag',
      1 => 'field_free_tag',
      2 => 'field_topic',
      3 => 'field_multi_page_campaign',
      4 => 'field_series',
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
  $export['group_tags|node|pledge_action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_takeaction_button|node|pledge_action|form';
  $field_group->group_name = 'group_takeaction_button';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pledge_action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'TakeAction Button',
    'weight' => '10',
    'children' => array(
      0 => 'field_tab_action',
      1 => 'field_tab_internal_title',
      2 => 'field_tab_call_to_action',
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
  $export['group_takeaction_button|node|pledge_action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_thank_you_fields|node|pledge_action|embedaction';
  $field_group->group_name = 'group_thank_you_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pledge_action';
  $field_group->mode = 'embedaction';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Thank You Fields',
    'weight' => '5',
    'children' => array(
      0 => 'field_thank_you_message',
      1 => 'field_thank_you_share_bar',
      2 => 'field_thank_you_heading',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Thank You Fields',
      'instance_settings' => array(
        'classes' => 'signature-state-fields thankyou inactive group-thank-you-fields field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_thank_you_fields|node|pledge_action|embedaction'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_thank_you_fields|node|pledge_action|embedaction_expanded';
  $field_group->group_name = 'group_thank_you_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pledge_action';
  $field_group->mode = 'embedaction_expanded';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Thank You Fields',
    'weight' => '5',
    'children' => array(
      0 => 'field_thank_you_message',
      1 => 'field_thank_you_share_bar',
      2 => 'field_thank_you_heading',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Thank You Fields',
      'instance_settings' => array(
        'classes' => 'signature-state-fields thankyou inactive group-thank-you-fields field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_thank_you_fields|node|pledge_action|embedaction_expanded'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_thank_you_share|node|pledge_action|form';
  $field_group->group_name = 'group_thank_you_share';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pledge_action';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_social_sharing';
  $field_group->data = array(
    'label' => 'Thank You Sharing',
    'weight' => '29',
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
  $export['group_thank_you_share|node|pledge_action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_thank_you_state|node|pledge_action|form';
  $field_group->group_name = 'group_thank_you_state';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pledge_action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Thank You State',
    'weight' => '9',
    'children' => array(
      0 => 'field_thank_you_message',
      1 => 'field_thank_you_share_bar',
      2 => 'field_thank_you_heading',
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
  $export['group_thank_you_state|node|pledge_action|form'] = $field_group;

  return $export;
}
