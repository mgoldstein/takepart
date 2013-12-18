<?php
/**
 * @file
 * tpf_content_petition_action.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function tpf_content_petition_action_field_group_info() {
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
        'classes' => 'same-height-adjust group-about-the-petition field-group-htab',
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
        'classes' => 'same-height-adjust group-about-the-petition field-group-htab',
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
    'weight' => '7',
    'children' => array(
      0 => 'field_thank_you_message',
      1 => 'field_closed_message',
      2 => 'field_signed_message',
      3 => 'field_thank_you_heading',
      4 => 'field_signed_heading',
      5 => 'field_closed_heading',
      6 => 'field_complete_heading',
      7 => 'field_complete_message',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Alternate States',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-alternate-content field-group-tab',
        'description' => 'Content for alternate states of the petition.',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_alternate_content|node|petition_action|form'] = $field_group;

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
        'classes' => 'signature-fields-closed group-closed-fields field-group-div',
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
  $export['group_complete_fields|node|petition_action|full'] = $field_group;

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
  $export['group_complete_message|node|petition_action|full'] = $field_group;

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
        'classes' => 'signature-tab-signed same-height-adjust group-full-petition-text field-group-htab',
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
        'classes' => 'signature-tab-signed same-height-adjust group-full-petition-text field-group-htab',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_full_petition_text|node|petition_action|embedaction_expanded'] = $field_group;

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
    'weight' => '3',
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
        'classes' => ' group-main field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_main|node|petition_action|form'] = $field_group;

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
  $export['group_more_or_less|node|petition_action|full'] = $field_group;

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
  $export['group_more_view|node|petition_action|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_share|node|petition_action|form';
  $field_group->group_name = 'group_page_share';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'petition_action';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_thank_you_sharing';
  $field_group->data = array(
    'label' => 'Action Page Sharing',
    'weight' => '37',
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
  $export['group_page_share|node|petition_action|form'] = $field_group;

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
        'classes' => ' group-petition-tabs field-group-htabs',
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
        'classes' => ' group-petition-tabs field-group-htabs',
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
    'weight' => '5',
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
        'classes' => ' group-petition field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_petition|node|petition_action|form'] = $field_group;

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
  $export['group_signature_fields|node|petition_action|full'] = $field_group;

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
  $export['group_signed_fields|node|petition_action|full'] = $field_group;

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
    'weight' => '6',
    'children' => array(
      0 => 'field_petition_recipient',
      1 => 'field_action_sponsor',
      2 => 'field_action_organizer',
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
  $export['group_sponsor_recipient|node|petition_action|form'] = $field_group;

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
  $export['group_summary|node|petition_action|medium_preview'] = $field_group;

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
    'weight' => '4',
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
        'classes' => ' group-tags field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tags|node|petition_action|form'] = $field_group;

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
    'weight' => '9',
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
  $export['group_takeaction_button|node|petition_action|form'] = $field_group;

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
  $export['group_thank_you_fields|node|petition_action|embedaction_expanded'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_thank_you_share|node|petition_action|form';
  $field_group->group_name = 'group_thank_you_share';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'petition_action';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_thank_you_sharing';
  $field_group->data = array(
    'label' => 'Thank You Sharing',
    'weight' => '36',
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
  $export['group_thank_you_share|node|petition_action|form'] = $field_group;

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
    'weight' => '8',
    'children' => array(
      0 => 'group_thank_you_share',
      1 => 'group_page_share',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Social Sharing',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-thank-you-sharing field-group-tab',
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
        'classes' => ' group-thank-you-state field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_thank_you_state|node|petition_action|form'] = $field_group;

  return $export;
}
