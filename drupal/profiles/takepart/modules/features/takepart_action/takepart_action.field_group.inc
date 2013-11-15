<?php
/**
 * @file
 * takepart_action.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function takepart_action_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_action_actions|node|action|form';
  $field_group->group_name = 'group_action_actions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Actions',
    'weight' => '4',
    'children' => array(),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_action_actions|node|action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_action_body|node|action|form';
  $field_group->group_name = 'group_action_body';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '3',
    'children' => array(
      0 => 'field_action_main_image',
      1 => 'field_action_type',
      2 => 'field_altcontent',
      3 => 'field_actionheaderimghref',
      4 => 'field_actionheaderimg',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_action_body|node|action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_action_campaigns|node|action|form';
  $field_group->group_name = 'group_action_campaigns';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Campaigns',
    'weight' => '3',
    'children' => array(),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_action_campaigns|node|action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_action_content|node|action|form';
  $field_group->group_name = 'group_action_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related',
    'weight' => '10',
    'children' => array(
      0 => 'field_action_related',
      1 => 'field_suggest_campaigns',
      2 => 'field_related_content',
      3 => 'field_suggest_content',
      4 => 'field_related_campaigns',
      5 => 'field_suggest_actions',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_action_content|node|action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_action_htab1|node|action|form';
  $field_group->group_name = 'group_action_htab1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '5',
    'children' => array(),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Content',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_action_htab1|node|action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_action_media|node|action|form';
  $field_group->group_name = 'group_action_media';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'action';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_actions_main';
  $field_group->data = array(
    'label' => 'Media',
    'weight' => '15',
    'children' => array(
      0 => 'field_action_main_image',
      1 => 'field_thumbnail',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_action_media|node|action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_action_promos|node|action|form';
  $field_group->group_name = 'group_action_promos';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Promo Head / Text',
    'weight' => '9',
    'children' => array(
      0 => 'field_thumbnail',
      1 => 'field_promo_headline',
      2 => 'field_promo_text',
      3 => 'group_social_sharing',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_action_promos|node|action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_action_sponsors|node|action|form';
  $field_group->group_name = 'group_action_sponsors';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sponsors',
    'weight' => '8',
    'children' => array(
      0 => 'field_action_sponsor',
      1 => 'field_action_organizer',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_action_sponsors|node|action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_action_terms|node|action|form';
  $field_group->group_name = 'group_action_terms';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tags',
    'weight' => '4',
    'children' => array(
      0 => 'field_free_tag',
      1 => 'field_topic',
      2 => 'field_multi_page_campaign',
      3 => 'field_display_tag',
      4 => 'field_series',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_action_terms|node|action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_actions_main|node|action|form';
  $field_group->group_name = 'group_actions_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '2',
    'children' => array(
      0 => 'group_action_body',
      1 => 'group_action_content',
      2 => 'group_action_media',
      3 => 'group_action_promos',
      4 => 'group_action_sponsors',
      5 => 'group_action_terms',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_actions_main|node|action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_action|node|action|form';
  $field_group->group_name = 'group_action';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Action',
    'weight' => '5',
    'children' => array(
      0 => 'body',
      1 => 'field_action_url',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Action',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'Fields specific to a simple action.',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_action|node|action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_share|node|action|form';
  $field_group->group_name = 'group_page_share';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Social Sharing',
    'weight' => '7',
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
  $export['group_page_share|node|action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_social_sharing|node|action|form';
  $field_group->group_name = 'group_social_sharing';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'action';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_action_promos';
  $field_group->data = array(
    'label' => 'Social Sharing',
    'weight' => '5',
    'children' => array(
      0 => 'field_social_share_bar',
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
  $export['group_social_sharing|node|action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_summary|node|action|medium_preview';
  $field_group->group_name = 'group_summary';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'action';
  $field_group->mode = 'medium_preview';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Summary',
    'weight' => '3',
    'children' => array(
      0 => 'field_short_introduction',
      1 => 'signature_call_to_action',
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
  $export['group_summary|node|action|medium_preview'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_supporting_content|node|action|form';
  $field_group->group_name = 'group_supporting_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Supporting Content',
    'weight' => '13',
    'children' => array(
      0 => 'field_tab_content_link',
      1 => 'field_tab_update_text',
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
  $export['group_supporting_content|node|action|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_takeaction_button|node|action|form';
  $field_group->group_name = 'group_takeaction_button';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'TakeAction Button',
    'weight' => '6',
    'children' => array(
      0 => 'field_tab_action',
      1 => 'field_tab_internal_title',
      2 => 'field_tab_call_to_action',
      3 => 'field_tab_link_only',
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
  $export['group_takeaction_button|node|action|form'] = $field_group;

  return $export;
}
