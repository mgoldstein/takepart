<?php
/**
 * @file
 * takepart_omniture.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function takepart_omniture_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_about_the_petition|node|petition_action|embedaction';
  $field_group->group_name = 'group_about_the_petition';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'petition_action';
  $field_group->mode = 'embedaction';
  $field_group->parent_name = 'group_petition_tabs';
  $field_group->data = array(
    'label' => 'About The Petition',
    'weight' => '15',
    'children' => array(
      0 => 'field_petition_about',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'About The Petition',
      'instance_settings' => array(
        'classes' => 'same-height-adjust',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_about_the_petition|node|petition_action|embedaction'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_about_the_petition|node|petition_action|embedaction_expanded';
  $field_group->group_name = 'group_about_the_petition';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'petition_action';
  $field_group->mode = 'embedaction_expanded';
  $field_group->parent_name = 'group_petition_tabs';
  $field_group->data = array(
    'label' => 'About The Petition',
    'weight' => '20',
    'children' => array(
      0 => 'field_petition_about',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'About The Petition',
      'instance_settings' => array(
        'classes' => 'same-height-adjust',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_about_the_petition|node|petition_action|embedaction_expanded'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_alternate_content|node|petition_action|form';
  $field_group->group_name = 'group_alternate_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'petition_action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Alternate States',
    'weight' => '13',
    'children' => array(
      0 => 'field_closed_message',
      1 => 'field_signed_message',
      2 => 'field_signed_heading',
      3 => 'field_closed_heading',
      4 => 'field_complete_heading',
      5 => 'field_complete_message',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Alternate States',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'Content for alternate states of the petition.',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_alternate_content|node|petition_action|form'] = $field_group;

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
    'weight' => '10',
    'children' => array(
      0 => 'field_closed_message',
      1 => 'field_signed_message',
      2 => 'field_closed_heading',
      3 => 'field_complete_heading',
      4 => 'field_signed_heading',
      5 => 'field_complete_message',
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
  $export['group_alternate_states|node|pledge_action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_closed_fields|node|petition_action|embedaction';
  $field_group->group_name = 'group_closed_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'petition_action';
  $field_group->mode = 'embedaction';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Closed Fields',
    'weight' => '8',
    'children' => array(
      0 => 'field_closed_message',
      1 => 'field_closed_heading',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Closed Fields',
      'instance_settings' => array(
        'classes' => 'signature-state-fields closed inactive',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_closed_fields|node|petition_action|embedaction'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_closed_fields|node|petition_action|embedaction_expanded';
  $field_group->group_name = 'group_closed_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'petition_action';
  $field_group->mode = 'embedaction_expanded';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Closed Fields',
    'weight' => '7',
    'children' => array(
      0 => 'field_closed_message',
      1 => 'field_closed_heading',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Closed Fields',
      'instance_settings' => array(
        'classes' => 'signature-state-fields closed inactive',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_closed_fields|node|petition_action|embedaction_expanded'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_closed_fields|node|petition_action|full';
  $field_group->group_name = 'group_closed_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'petition_action';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Closed Fields',
    'weight' => '8',
    'children' => array(
      0 => 'field_closed_message',
      1 => 'field_closed_heading',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Closed Fields',
      'instance_settings' => array(
        'classes' => 'signature-fields-closed',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_closed_fields|node|petition_action|full'] = $field_group;

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
        'classes' => 'signature-state-fields closed inactive',
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
        'classes' => 'signature-state-fields closed inactive',
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
        'classes' => 'signature-state-fields closed inactive',
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
  $field_group->identifier = 'group_complete_fields|node|petition_action|embedaction';
  $field_group->group_name = 'group_complete_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'petition_action';
  $field_group->mode = 'embedaction';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Complete Fields',
    'weight' => '5',
    'children' => array(
      0 => 'field_complete_heading',
      1 => 'field_complete_message',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Complete Fields',
      'instance_settings' => array(
        'classes' => 'signature-state-fields complete inactive',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_complete_fields|node|petition_action|embedaction'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_complete_fields|node|petition_action|embedaction_expanded';
  $field_group->group_name = 'group_complete_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'petition_action';
  $field_group->mode = 'embedaction_expanded';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Complete Fields',
    'weight' => '4',
    'children' => array(
      0 => 'field_complete_heading',
      1 => 'field_complete_message',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Complete Fields',
      'instance_settings' => array(
        'classes' => 'signature-state-fields complete inactive',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_complete_fields|node|petition_action|embedaction_expanded'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_complete_fields|node|petition_action|full';
  $field_group->group_name = 'group_complete_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'petition_action';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Complete Fields',
    'weight' => '5',
    'children' => array(
      0 => 'signature_progress_percent',
      1 => 'group_complete_message',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Complete Fields',
      'instance_settings' => array(
        'classes' => 'signature-state-fields signed unsigned closed complete inactive',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_complete_fields|node|petition_action|full'] = $field_group;

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
        'classes' => 'signature-state-fields complete inactive',
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
        'classes' => 'signature-state-fields complete inactive',
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
        'classes' => 'signature-state-fields signed unsigned closed complete inactive',
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
  $field_group->identifier = 'group_complete_message|node|petition_action|full';
  $field_group->group_name = 'group_complete_message';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'petition_action';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_complete_fields';
  $field_group->data = array(
    'label' => 'Complete Message',
    'weight' => '14',
    'children' => array(
      0 => 'field_complete_heading',
      1 => 'field_complete_message',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Complete Message',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_complete_message|node|petition_action|full'] = $field_group;

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
        'classes' => '',
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
        'classes' => '',
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
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_description|node|venue|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fields_to_remove|node|petition_action|form';
  $field_group->group_name = 'group_fields_to_remove';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'petition_action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Fields To Remove',
    'weight' => '22',
    'children' => array(
      0 => 'field_altcontent',
      1 => 'field_petition_text',
      2 => 'field_petition_sponsor',
      3 => 'field_updates_message',
      4 => 'field_signatures',
      5 => 'field_tab_update_text',
      6 => 'field_tab_content_link',
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
  $export['group_fields_to_remove|node|petition_action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fields_to_remove|node|pledge_action|form';
  $field_group->group_name = 'group_fields_to_remove';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pledge_action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Fields to Remove',
    'weight' => '20',
    'children' => array(
      0 => 'field_altcontent',
      1 => 'field_pledge_issue',
      2 => 'field_petition_sponsor',
      3 => 'field_updates_message',
      4 => 'field_tab_content_link',
      5 => 'field_tab_update_text',
      6 => 'group_short_version',
      7 => 'group_long_version',
      8 => 'group_supporting_content',
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
  $export['group_fields_to_remove|node|pledge_action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_full_petition_text|node|petition_action|embedaction';
  $field_group->group_name = 'group_full_petition_text';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'petition_action';
  $field_group->mode = 'embedaction';
  $field_group->parent_name = 'group_petition_tabs';
  $field_group->data = array(
    'label' => 'Full Petition Text',
    'weight' => '14',
    'children' => array(
      0 => 'body',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Full Petition Text',
      'instance_settings' => array(
        'classes' => 'signature-tab-signed same-height-adjust',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_full_petition_text|node|petition_action|embedaction'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_full_petition_text|node|petition_action|embedaction_expanded';
  $field_group->group_name = 'group_full_petition_text';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'petition_action';
  $field_group->mode = 'embedaction_expanded';
  $field_group->parent_name = 'group_petition_tabs';
  $field_group->data = array(
    'label' => 'Full Petition Text',
    'weight' => '18',
    'children' => array(
      0 => 'body',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Full Petition Text',
      'instance_settings' => array(
        'classes' => 'signature-tab-signed same-height-adjust',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_full_petition_text|node|petition_action|embedaction_expanded'] = $field_group;

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
        'classes' => '',
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
        'classes' => '',
      ),
    ),
  );
  $export['group_info|node|venue|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_less_view|node|pledge_action|embedaction';
  $field_group->group_name = 'group_less_view';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pledge_action';
  $field_group->mode = 'embedaction';
  $field_group->parent_name = 'group_more_or_less';
  $field_group->data = array(
    'label' => 'Less View Fields',
    'weight' => '62',
    'children' => array(
      0 => 'field_pledge_action_short',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Less View Fields',
      'instance_settings' => array(
        'classes' => 'more-or-less-less-view',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_less_view|node|pledge_action|embedaction'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_less_view|node|pledge_action|embedaction_expanded';
  $field_group->group_name = 'group_less_view';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pledge_action';
  $field_group->mode = 'embedaction_expanded';
  $field_group->parent_name = 'group_more_or_less';
  $field_group->data = array(
    'label' => 'Less View Field',
    'weight' => '11',
    'children' => array(
      0 => 'field_pledge_action_short',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Less View Field',
      'instance_settings' => array(
        'classes' => 'more-or-less-less-view',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_less_view|node|pledge_action|embedaction_expanded'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_less_view|node|pledge_action|full';
  $field_group->group_name = 'group_less_view';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pledge_action';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_more_or_less';
  $field_group->data = array(
    'label' => 'Less View Fields',
    'weight' => '19',
    'children' => array(
      0 => 'field_pledge_action_short',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Less View Fields',
      'instance_settings' => array(
        'classes' => 'more-or-less-less-view',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_less_view|node|pledge_action|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_main|node|petition_action|form';
  $field_group->group_name = 'group_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'petition_action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '6',
    'children' => array(
      0 => 'field_actionheaderimg',
      1 => 'field_actionheaderimghref',
      2 => 'field_action_main_image',
      3 => 'field_action_type',
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
  $export['group_main|node|petition_action|form'] = $field_group;

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
    'weight' => '6',
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
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_main|node|pledge_action|form'] = $field_group;

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
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_map|node|venue|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_more_or_less|node|petition_action|full';
  $field_group->group_name = 'group_more_or_less';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'petition_action';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'More or Less Fields',
    'weight' => '4',
    'children' => array(
      0 => 'group_less_view',
      1 => 'group_more_view',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'More or Less Fields',
      'instance_settings' => array(
        'classes' => 'more-or-less-container',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_more_or_less|node|petition_action|full'] = $field_group;

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
        'classes' => 'more-or-less-container',
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
        'classes' => 'more-or-less-container',
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
        'classes' => 'more-or-less-container',
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
  $field_group->identifier = 'group_more_view|node|petition_action|full';
  $field_group->group_name = 'group_more_view';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'petition_action';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_more_or_less';
  $field_group->data = array(
    'label' => 'More View Field',
    'weight' => '63',
    'children' => array(
      0 => 'body',
      1 => 'field_petition_about',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'More View Field',
      'instance_settings' => array(
        'classes' => 'more-or-less-more-view',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_more_view|node|petition_action|full'] = $field_group;

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
        'classes' => 'more-or-less-more-view',
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
        'classes' => 'more-or-less-more-view',
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
        'classes' => 'more-or-less-more-view',
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
  $field_group->identifier = 'group_petition_tabs|node|petition_action|embedaction';
  $field_group->group_name = 'group_petition_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'petition_action';
  $field_group->mode = 'embedaction';
  $field_group->parent_name = 'group_signature_fields';
  $field_group->data = array(
    'label' => 'Petition Tabs',
    'weight' => '17',
    'children' => array(
      0 => 'group_sign_the_petition',
      1 => 'group_full_petition_text',
      2 => 'group_about_the_petition',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_petition_tabs|node|petition_action|embedaction'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_petition_tabs|node|petition_action|embedaction_expanded';
  $field_group->group_name = 'group_petition_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'petition_action';
  $field_group->mode = 'embedaction_expanded';
  $field_group->parent_name = 'group_signature_fields';
  $field_group->data = array(
    'label' => 'Petition Tabs',
    'weight' => '14',
    'children' => array(
      0 => 'group_about_the_petition',
      1 => 'group_sign_the_petition',
      2 => 'group_full_petition_text',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_petition_tabs|node|petition_action|embedaction_expanded'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_petition|node|petition_action|form';
  $field_group->group_name = 'group_petition';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'petition_action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Petition',
    'weight' => '7',
    'children' => array(
      0 => 'body',
      1 => 'field_petition_about',
      2 => 'field_action_form_title',
      3 => 'field_short_introduction',
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
  $export['group_petition|node|petition_action|form'] = $field_group;

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
    'weight' => '7',
    'children' => array(
      0 => 'body',
      1 => 'field_action_form_title',
      2 => 'field_pledge_action_short',
      3 => 'field_pledge_action_long',
      4 => 'field_short_introduction',
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
  $export['group_pledge|node|pledge_action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_promo|node|petition_action|form';
  $field_group->group_name = 'group_promo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'petition_action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Promo Head / Text',
    'weight' => '15',
    'children' => array(
      0 => 'field_promo_headline',
      1 => 'field_promo_text',
      2 => 'field_thumbnail',
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
  $export['group_promo|node|petition_action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_promo|node|pledge_action|form';
  $field_group->group_name = 'group_promo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pledge_action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Promo Head / Text',
    'weight' => '12',
    'children' => array(
      0 => 'field_promo_headline',
      1 => 'field_promo_text',
      2 => 'field_thumbnail',
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
  $export['group_promo|node|pledge_action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related|node|petition_action|form';
  $field_group->group_name = 'group_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'petition_action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related',
    'weight' => '16',
    'children' => array(
      0 => 'field_suggest_actions',
      1 => 'field_suggest_campaigns',
      2 => 'field_suggest_content',
      3 => 'field_action_related',
      4 => 'field_related_campaigns',
      5 => 'field_related_content',
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
  $export['group_related|node|petition_action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related|node|pledge_action|form';
  $field_group->group_name = 'group_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pledge_action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related',
    'weight' => '13',
    'children' => array(
      0 => 'field_suggest_actions',
      1 => 'field_suggest_campaigns',
      2 => 'field_suggest_content',
      3 => 'field_action_related',
      4 => 'field_related_campaigns',
      5 => 'field_related_content',
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
  $export['group_related|node|pledge_action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_signature_fields|node|petition_action|full';
  $field_group->group_name = 'group_signature_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'petition_action';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Signature Fields',
    'weight' => '6',
    'children' => array(
      0 => 'field_action_form_title',
      1 => 'signature_form_redirect',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Signature Fields',
      'instance_settings' => array(
        'classes' => 'signature-state-fields unsigned active',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_signature_fields|node|petition_action|full'] = $field_group;

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
        'classes' => 'signature-state-fields unsigned signed active',
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
        'classes' => 'signature-state-fields unsigned signed active',
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
        'classes' => 'signature-state-fields unsigned active',
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
  $field_group->identifier = 'group_signed_fields|node|petition_action|full';
  $field_group->group_name = 'group_signed_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'petition_action';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Already Signed Fields',
    'weight' => '7',
    'children' => array(
      0 => 'field_signed_message',
      1 => 'field_signed_heading',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Already Signed Fields',
      'instance_settings' => array(
        'classes' => 'signature-state-fields signed inactive',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_signed_fields|node|petition_action|full'] = $field_group;

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
        'classes' => 'signature-state-fields signed inactive',
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
    'weight' => '11',
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
  $export['group_social_sharing|node|pledge_action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sponsor_recipient|node|petition_action|form';
  $field_group->group_name = 'group_sponsor_recipient';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'petition_action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sponsor / Recipient',
    'weight' => '8',
    'children' => array(
      0 => 'field_petition_recipient',
      1 => 'field_action_sponsor',
      2 => 'field_action_organizer',
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
  $export['group_sponsor_recipient|node|petition_action|form'] = $field_group;

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
    'weight' => '8',
    'children' => array(
      0 => 'field_action_sponsor',
      1 => 'field_action_organizer',
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
  $export['group_sponsor|node|pledge_action|form'] = $field_group;

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
        'classes' => '',
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
        'classes' => '',
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
        'classes' => '',
      ),
    ),
  );
  $export['group_storemap|node|venue|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_summary|node|petition_action|medium_preview';
  $field_group->group_name = 'group_summary';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'petition_action';
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
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_summary|node|petition_action|medium_preview'] = $field_group;

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
        'classes' => '',
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
  $field_group->identifier = 'group_tags|node|petition_action|form';
  $field_group->group_name = 'group_tags';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'petition_action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tags',
    'weight' => '17',
    'children' => array(
      0 => 'field_multi_page_campaign',
      1 => 'field_topic',
      2 => 'field_free_tag',
      3 => 'field_display_tag',
      4 => 'field_series',
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
  $export['group_tags|node|petition_action|form'] = $field_group;

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
    'weight' => '14',
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
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tags|node|pledge_action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_takeaction_button|node|petition_action|form';
  $field_group->group_name = 'group_takeaction_button';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'petition_action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'TakeAction Button',
    'weight' => '18',
    'children' => array(
      0 => 'field_tab_action',
      1 => 'field_tab_internal_title',
      2 => 'field_tab_internal_desc',
      3 => 'field_tab_external_title',
      4 => 'field_tab_external_desc',
      5 => 'field_tab_call_to_action',
      6 => 'field_tab_exclude',
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
  $export['group_takeaction_button|node|petition_action|form'] = $field_group;

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
    'weight' => '15',
    'children' => array(
      0 => 'field_tab_action',
      1 => 'field_tab_internal_title',
      2 => 'field_tab_internal_desc',
      3 => 'field_tab_external_title',
      4 => 'field_tab_external_desc',
      5 => 'field_tab_call_to_action',
      6 => 'field_tab_exclude',
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
  $export['group_takeaction_button|node|pledge_action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_thank_you_fields|node|petition_action|embedaction';
  $field_group->group_name = 'group_thank_you_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'petition_action';
  $field_group->mode = 'embedaction';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Thank You Fields',
    'weight' => '7',
    'children' => array(
      0 => 'field_thank_you_message',
      1 => 'field_thank_you_share_bar',
      2 => 'field_thank_you_heading',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Thank You Fields',
      'instance_settings' => array(
        'classes' => 'signature-state-fields thankyou inactive',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_thank_you_fields|node|petition_action|embedaction'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_thank_you_fields|node|petition_action|embedaction_expanded';
  $field_group->group_name = 'group_thank_you_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'petition_action';
  $field_group->mode = 'embedaction_expanded';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Thank You Fields',
    'weight' => '6',
    'children' => array(
      0 => 'field_thank_you_message',
      1 => 'field_thank_you_share_bar',
      2 => 'field_thank_you_heading',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Thank You Fields',
      'instance_settings' => array(
        'classes' => 'signature-state-fields thankyou inactive',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_thank_you_fields|node|petition_action|embedaction_expanded'] = $field_group;

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
        'classes' => 'signature-state-fields thankyou inactive',
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
        'classes' => 'signature-state-fields thankyou inactive',
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
  $field_group->identifier = 'group_thank_you_sharing|node|petition_action|form';
  $field_group->group_name = 'group_thank_you_sharing';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'petition_action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Social Sharing',
    'weight' => '14',
    'children' => array(
      0 => 'field_social_share_bar',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Social Sharing',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_thank_you_sharing|node|petition_action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_thank_you_state|node|petition_action|form';
  $field_group->group_name = 'group_thank_you_state';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'petition_action';
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
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_thank_you_state|node|petition_action|form'] = $field_group;

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
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_thank_you_state|node|pledge_action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_updates_fields|node|pledge_action|embedaction_expanded';
  $field_group->group_name = 'group_updates_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pledge_action';
  $field_group->mode = 'embedaction_expanded';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Updates Fields',
    'weight' => '14',
    'children' => array(
      0 => 'field_updates_message',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(),
    ),
  );
  $export['group_updates_fields|node|pledge_action|embedaction_expanded'] = $field_group;

  return $export;
}
