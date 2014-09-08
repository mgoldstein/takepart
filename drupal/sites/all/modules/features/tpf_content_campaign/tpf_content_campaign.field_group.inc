<?php
/**
 * @file
 * tpf_content_campaign.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function tpf_content_campaign_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_multi_page_campaign|node|takepart_campaign|form';
  $field_group->group_name = 'group_multi_page_campaign';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'takepart_campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Multi Page Campaign',
    'weight' => '15',
    'children' => array(
      0 => 'field_multi_page_campaign',
      1 => 'field_tp_campaign_header',
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
  $export['group_multi_page_campaign|node|takepart_campaign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tp_campaign_cover|node|takepart_campaign|form';
  $field_group->group_name = 'group_tp_campaign_cover';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'takepart_campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Cover',
    'weight' => '6',
    'children' => array(
      0 => 'field_tp_campaign_cover_image',
      1 => 'field_tp_campaign_cover_intro',
      2 => 'field_tp_campaign_cover_link',
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
  $export['group_tp_campaign_cover|node|takepart_campaign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tp_campaign_groups|node|takepart_campaign|form';
  $field_group->group_name = 'group_tp_campaign_groups';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'takepart_campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Groups',
    'weight' => '8',
    'children' => array(
      0 => 'field_tp_campaign_sponsors',
      1 => 'field_tp_campaign_alliances',
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
  $export['group_tp_campaign_groups|node|takepart_campaign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tp_campaign_header|node|takepart_campaign|default';
  $field_group->group_name = 'group_tp_campaign_header';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'takepart_campaign';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Header',
    'weight' => '1',
    'children' => array(
      0 => 'field_tp_campaign_4_things_link',
      1 => 'field_tp_campaign_5_things_head',
      2 => 'field_tp_campaign_intro_html',
      3 => 'field_tp_campaign_intro_media',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
        'id' => 'node_takepart_campaign_full_group_tp_campaign_header',
      ),
    ),
  );
  $export['group_tp_campaign_header|node|takepart_campaign|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tp_campaign_intro|node|takepart_campaign|form';
  $field_group->group_name = 'group_tp_campaign_intro';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'takepart_campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Intro',
    'weight' => '5',
    'children' => array(
      0 => 'field_tp_campaign_4_things_link',
      1 => 'field_tp_campaign_5_things_head',
      2 => 'field_tp_campaign_intro_html',
      3 => 'field_tp_campaign_intro_media',
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
  $export['group_tp_campaign_intro|node|takepart_campaign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tp_campaign_main|node|takepart_campaign|form';
  $field_group->group_name = 'group_tp_campaign_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'takepart_campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '2',
    'children' => array(
      0 => 'body',
      1 => 'field_tp_campaign_subheadline',
      2 => 'field_main_image',
      3 => 'field_thumbnail',
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
  $export['group_tp_campaign_main|node|takepart_campaign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tp_campaign_rel|node|takepart_campaign|form';
  $field_group->group_name = 'group_tp_campaign_rel';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'takepart_campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related Actions',
    'weight' => '7',
    'children' => array(
      0 => 'field_related_actions',
      1 => 'field_suggest_actions',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Related Actions',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_tp_campaign_rel|node|takepart_campaign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tp_campaign_seg_1|node|takepart_campaign|form';
  $field_group->group_name = 'group_tp_campaign_seg_1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'takepart_campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Segment 1',
    'weight' => '10',
    'children' => array(
      0 => 'field_tp_campaign_seg_1_html',
      1 => 'field_tp_campaign_seg_1_label',
      2 => 'field_tp_campaign_seg_1_rel',
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
  $export['group_tp_campaign_seg_1|node|takepart_campaign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tp_campaign_seg_2|node|takepart_campaign|form';
  $field_group->group_name = 'group_tp_campaign_seg_2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'takepart_campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Segment 2',
    'weight' => '11',
    'children' => array(
      0 => 'field_tp_campaign_seg_2_html',
      1 => 'field_tp_campaign_seg_2_label',
      2 => 'field_tp_campaign_seg_2_rel',
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
  $export['group_tp_campaign_seg_2|node|takepart_campaign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tp_campaign_seg_3|node|takepart_campaign|form';
  $field_group->group_name = 'group_tp_campaign_seg_3';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'takepart_campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Segment 3',
    'weight' => '13',
    'children' => array(
      0 => 'field_tp_campaign_seg_3_html',
      1 => 'field_tp_campaign_seg_3_label',
      2 => 'field_tp_campaign_seg_3_rel',
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
  $export['group_tp_campaign_seg_3|node|takepart_campaign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tp_campaign_seg_4|node|takepart_campaign|form';
  $field_group->group_name = 'group_tp_campaign_seg_4';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'takepart_campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Segment 4',
    'weight' => '14',
    'children' => array(
      0 => 'field_tp_campaign_seg_4_html',
      1 => 'field_tp_campaign_seg_4_label',
      2 => 'field_tp_campaign_seg_4_rel',
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
  $export['group_tp_campaign_seg_4|node|takepart_campaign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tp_campaign_sl|node|takepart_campaign|form';
  $field_group->group_name = 'group_tp_campaign_sl';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'takepart_campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Spotlight',
    'weight' => '9',
    'children' => array(
      0 => 'field_tp_campaign_sl_html',
      1 => 'field_tp_campaign_sl_image',
      2 => 'field_tp_campaign_sl_nodes',
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
  $export['group_tp_campaign_sl|node|takepart_campaign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tp_campaign_tags|node|takepart_campaign|form';
  $field_group->group_name = 'group_tp_campaign_tags';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'takepart_campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tags',
    'weight' => '17',
    'children' => array(
      0 => 'field_topic',
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
  $export['group_tp_campaign_tags|node|takepart_campaign|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tp_campaign_vtab1|node|takepart_campaign|form';
  $field_group->group_name = 'group_tp_campaign_vtab1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'takepart_campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '1',
    'children' => array(
      0 => 'body',
      1 => 'field_tp_campaign_subheadline',
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
  $export['group_tp_campaign_vtab1|node|takepart_campaign|form'] = $field_group;

  return $export;
}
