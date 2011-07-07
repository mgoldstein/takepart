<?php
/**
 * @file
 * takepart_action.field_group.inc
 */

/**
 * Implementation of hook_field_group_info().
 */
function takepart_action_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_action_actions|node|action|form';
  $field_group->group_name = 'group_action_actions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'action';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_actions_main';
  $field_group->data = array(
    'label' => 'Actions',
    'weight' => '12',
    'children' => array(
      0 => 'field_action_related',
      1 => 'field_action_type',
      2 => 'field_action_url',
      3 => 'field_suggest_actions',
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
  $export['group_action_actions|node|action|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_action_body|node|action|form';
  $field_group->group_name = 'group_action_body';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'action';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_actions_main';
  $field_group->data = array(
    'label' => 'Body Content',
    'weight' => '13',
    'children' => array(
      0 => 'body',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Body Content',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_action_body|node|action|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_action_campaigns|node|action|form';
  $field_group->group_name = 'group_action_campaigns';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'action';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_actions_main';
  $field_group->data = array(
    'label' => 'Campaigns',
    'weight' => '18',
    'children' => array(
      0 => 'field_multi_page_campaign',
      1 => 'field_suggest_campaigns',
      2 => 'field_related_campaigns',
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
  $export['group_action_campaigns|node|action|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_action_content|node|action|form';
  $field_group->group_name = 'group_action_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'action';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_actions_main';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '19',
    'children' => array(
      0 => 'field_related_content',
      1 => 'field_suggest_content',
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
  $export['group_action_content|node|action|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_action_htab1|node|action|form';
  $field_group->group_name = 'group_action_htab1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'action';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '2',
    'children' => array(
      0 => 'group_actions_main',
    ),
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

  $field_group = new stdClass;
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

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_action_promos|node|action|form';
  $field_group->group_name = 'group_action_promos';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'action';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_actions_main';
  $field_group->data = array(
    'label' => 'Promos',
    'weight' => '17',
    'children' => array(
      0 => 'field_promo_headline',
      1 => 'field_promo_text',
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
  $export['group_action_promos|node|action|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_action_sponsors|node|action|form';
  $field_group->group_name = 'group_action_sponsors';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'action';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_actions_main';
  $field_group->data = array(
    'label' => 'Sponsors',
    'weight' => '16',
    'children' => array(
      0 => 'field_action_sponsor',
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
  $export['group_action_sponsors|node|action|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_action_terms|node|action|form';
  $field_group->group_name = 'group_action_terms';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'action';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_actions_main';
  $field_group->data = array(
    'label' => 'Tags',
    'weight' => '20',
    'children' => array(
      0 => 'field_free_tag',
      1 => 'field_topic',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Tags',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_action_terms|node|action|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_actions_main|node|action|form';
  $field_group->group_name = 'group_actions_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'action';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_action_htab1';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '5',
    'children' => array(
      0 => 'group_action_campaigns',
      1 => 'group_action_content',
      2 => 'group_action_actions',
      3 => 'group_action_promos',
      4 => 'group_action_sponsors',
      5 => 'group_action_media',
      6 => 'group_action_terms',
      7 => 'group_action_body',
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

  return $export;
}
