<?php
/**
 * @file
 * takepart_campaign.field_group.inc
 */

/**
 * Implementation of hook_field_group_info().
 */
function takepart_campaign_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tp_campaign_cover|node|takepart_campaign|form';
  $field_group->group_name = 'group_tp_campaign_cover';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'takepart_campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tp_campaign_vtab1';
  $field_group->data = array(
    'label' => 'Cover',
    'weight' => '4',
    'children' => array(
      0 => 'field_tp_campaign_4_things_link',
      1 => 'field_tp_campaign_5_things_head',
      2 => 'field_tp_campaign_cover_image',
      3 => 'field_tp_campaign_cover_intro',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_tp_campaign_cover|node|takepart_campaign|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tp_campaign_groups|node|takepart_campaign|form';
  $field_group->group_name = 'group_tp_campaign_groups';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'takepart_campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tp_campaign_vtab1';
  $field_group->data = array(
    'label' => 'Groups',
    'weight' => '6',
    'children' => array(
      0 => 'field_tp_campaign_alliances',
      1 => 'field_tp_campaign_sponsors',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_tp_campaign_groups|node|takepart_campaign|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tp_campaign_intro|node|takepart_campaign|form';
  $field_group->group_name = 'group_tp_campaign_intro';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'takepart_campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tp_campaign_vtab1';
  $field_group->data = array(
    'label' => 'Intro',
    'weight' => '3',
    'children' => array(
      0 => 'field_tp_campaign_intro_html',
      1 => 'field_tp_campaign_intro_media',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_tp_campaign_intro|node|takepart_campaign|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tp_campaign_rel|node|takepart_campaign|form';
  $field_group->group_name = 'group_tp_campaign_rel';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'takepart_campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tp_campaign_vtab1';
  $field_group->data = array(
    'label' => 'Releated Actions',
    'weight' => '5',
    'children' => array(
      0 => 'field_action_related',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_tp_campaign_rel|node|takepart_campaign|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tp_campaign_seg_1|node|takepart_campaign|form';
  $field_group->group_name = 'group_tp_campaign_seg_1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'takepart_campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tp_campaign_vtab1';
  $field_group->data = array(
    'label' => 'Segment 1',
    'weight' => '8',
    'children' => array(
      0 => 'field_tp_campaign_seg_1_html',
      1 => 'field_tp_campaign_seg_1_label',
      2 => 'field_tp_campaign_seg_1_rel',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_tp_campaign_seg_1|node|takepart_campaign|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tp_campaign_seg_2|node|takepart_campaign|form';
  $field_group->group_name = 'group_tp_campaign_seg_2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'takepart_campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tp_campaign_vtab1';
  $field_group->data = array(
    'label' => 'Segment 2',
    'weight' => '9',
    'children' => array(
      0 => 'field_tp_campaign_seg_2_html',
      1 => 'field_tp_campaign_seg_2_label',
      2 => 'field_tp_campaign_seg_2_rel',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_tp_campaign_seg_2|node|takepart_campaign|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tp_campaign_seg_3|node|takepart_campaign|form';
  $field_group->group_name = 'group_tp_campaign_seg_3';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'takepart_campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tp_campaign_vtab1';
  $field_group->data = array(
    'label' => 'Segment 3',
    'weight' => '10',
    'children' => array(
      0 => 'field_tp_campaign_seg_3_html',
      1 => 'field_tp_campaign_seg_3_label',
      2 => 'field_tp_campaign_seg_3_rel',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_tp_campaign_seg_3|node|takepart_campaign|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tp_campaign_seg_4|node|takepart_campaign|form';
  $field_group->group_name = 'group_tp_campaign_seg_4';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'takepart_campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tp_campaign_vtab1';
  $field_group->data = array(
    'label' => 'Segment 4',
    'weight' => '11',
    'children' => array(
      0 => 'field_tp_campaign_seg_4_html',
      1 => 'field_tp_campaign_seg_4_label',
      2 => 'field_tp_campaign_seg_4_rel',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_tp_campaign_seg_4|node|takepart_campaign|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tp_campaign_sl|node|takepart_campaign|form';
  $field_group->group_name = 'group_tp_campaign_sl';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'takepart_campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tp_campaign_vtab1';
  $field_group->data = array(
    'label' => 'Spotlight',
    'weight' => '7',
    'children' => array(
      0 => 'field_tp_campaign_sl_html',
      1 => 'field_tp_campaign_sl_image',
      2 => 'field_tp_campaign_sl_nodes',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_tp_campaign_sl|node|takepart_campaign|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tp_campaign_vtab1|node|takepart_campaign|form';
  $field_group->group_name = 'group_tp_campaign_vtab1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'takepart_campaign';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'vtab1',
    'weight' => '3',
    'children' => array(
      0 => 'group_tp_campaign_cover',
      1 => 'group_tp_campaign_groups',
      2 => 'group_tp_campaign_intro',
      3 => 'group_tp_campaign_rel',
      4 => 'group_tp_campaign_seg_1',
      5 => 'group_tp_campaign_seg_2',
      6 => 'group_tp_campaign_seg_3',
      7 => 'group_tp_campaign_seg_4',
      8 => 'group_tp_campaign_sl',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => NULL,
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_tp_campaign_vtab1|node|takepart_campaign|form'] = $field_group;

  return $export;
}
