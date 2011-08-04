<?php
/**
 * @file
 * takepart_campaign.features.field_group.inc
 */

/**
 * Implementation of hook_field_group_default_field_groups().
 */
function takepart_campaign_field_group_default_field_groups() {
  $field_groups = array();

  // Exported field_group: 'group_tp_campaign_cover|node|takepart_campaign|form'
  $field_groups['group_tp_campaign_cover|node|takepart_campaign|form'] = array(
    'group_name' => 'group_tp_campaign_cover',
    'entity_type' => 'node',
    'bundle' => 'takepart_campaign',
    'mode' => 'form',
    'parent_name' => 'group_tp_campaign_vtab1',
    'label' => 'Cover',
    'weight' => '4',
    'children' => array(
      0 => 'field_tp_campaign_5_things_head',
      1 => 'field_tp_campaign_4_things_link',
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

  // Exported field_group: 'group_tp_campaign_groups|node|takepart_campaign|form'
  $field_groups['group_tp_campaign_groups|node|takepart_campaign|form'] = array(
    'group_name' => 'group_tp_campaign_groups',
    'entity_type' => 'node',
    'bundle' => 'takepart_campaign',
    'mode' => 'form',
    'parent_name' => 'group_tp_campaign_vtab1',
    'label' => 'Groups',
    'weight' => '6',
    'children' => array(
      0 => 'field_tp_campaign_sponsors',
      1 => 'field_tp_campaign_alliances',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );

  // Exported field_group: 'group_tp_campaign_intro|node|takepart_campaign|form'
  $field_groups['group_tp_campaign_intro|node|takepart_campaign|form'] = array(
    'group_name' => 'group_tp_campaign_intro',
    'entity_type' => 'node',
    'bundle' => 'takepart_campaign',
    'mode' => 'form',
    'parent_name' => 'group_tp_campaign_vtab1',
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

  // Exported field_group: 'group_tp_campaign_rel|node|takepart_campaign|form'
  $field_groups['group_tp_campaign_rel|node|takepart_campaign|form'] = array(
    'group_name' => 'group_tp_campaign_rel',
    'entity_type' => 'node',
    'bundle' => 'takepart_campaign',
    'mode' => 'form',
    'parent_name' => 'group_tp_campaign_vtab1',
    'label' => 'Related Actions',
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

  // Exported field_group: 'group_tp_campaign_seg_1|node|takepart_campaign|form'
  $field_groups['group_tp_campaign_seg_1|node|takepart_campaign|form'] = array(
    'group_name' => 'group_tp_campaign_seg_1',
    'entity_type' => 'node',
    'bundle' => 'takepart_campaign',
    'mode' => 'form',
    'parent_name' => 'group_tp_campaign_vtab1',
    'label' => 'Segment 1',
    'weight' => '9',
    'children' => array(
      0 => 'field_tp_campaign_seg_1_label',
      1 => 'field_tp_campaign_seg_1_rel',
      2 => 'field_tp_campaign_seg_1_html',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );

  // Exported field_group: 'group_tp_campaign_seg_2|node|takepart_campaign|form'
  $field_groups['group_tp_campaign_seg_2|node|takepart_campaign|form'] = array(
    'group_name' => 'group_tp_campaign_seg_2',
    'entity_type' => 'node',
    'bundle' => 'takepart_campaign',
    'mode' => 'form',
    'parent_name' => 'group_tp_campaign_vtab1',
    'label' => 'Segment 2',
    'weight' => '9',
    'children' => array(
      0 => 'field_tp_campaign_seg_2_label',
      1 => 'field_tp_campaign_seg_2_rel',
      2 => 'field_tp_campaign_seg_2_html',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );

  // Exported field_group: 'group_tp_campaign_seg_3|node|takepart_campaign|form'
  $field_groups['group_tp_campaign_seg_3|node|takepart_campaign|form'] = array(
    'group_name' => 'group_tp_campaign_seg_3',
    'entity_type' => 'node',
    'bundle' => 'takepart_campaign',
    'mode' => 'form',
    'parent_name' => 'group_tp_campaign_vtab1',
    'label' => 'Segment 3',
    'weight' => '9',
    'children' => array(
      0 => 'field_tp_campaign_seg_3_label',
      1 => 'field_tp_campaign_seg_3_rel',
      2 => 'field_tp_campaign_seg_3_html',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );

  // Exported field_group: 'group_tp_campaign_seg_4|node|takepart_campaign|form'
  $field_groups['group_tp_campaign_seg_4|node|takepart_campaign|form'] = array(
    'group_name' => 'group_tp_campaign_seg_4',
    'entity_type' => 'node',
    'bundle' => 'takepart_campaign',
    'mode' => 'form',
    'parent_name' => 'group_tp_campaign_vtab1',
    'label' => 'Segment 4',
    'weight' => '12',
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

  // Exported field_group: 'group_tp_campaign_sl|node|takepart_campaign|form'
  $field_groups['group_tp_campaign_sl|node|takepart_campaign|form'] = array(
    'group_name' => 'group_tp_campaign_sl',
    'entity_type' => 'node',
    'bundle' => 'takepart_campaign',
    'mode' => 'form',
    'parent_name' => 'group_tp_campaign_vtab1',
    'label' => 'Spotlight',
    'weight' => '7',
    'children' => array(
      0 => 'field_tp_campaign_sl_image',
      1 => 'field_tp_campaign_sl_nodes',
      2 => 'field_tp_campaign_sl_html',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );

  // Exported field_group: 'group_tp_campaign_vtab1|node|takepart_campaign|form'
  $field_groups['group_tp_campaign_vtab1|node|takepart_campaign|form'] = array(
    'group_name' => 'group_tp_campaign_vtab1',
    'entity_type' => 'node',
    'bundle' => 'takepart_campaign',
    'mode' => 'form',
    'parent_name' => '',
    'label' => 'vtab1',
    'weight' => '3',
    'children' => array(
      0 => 'group_tp_campaign_intro',
      1 => 'group_tp_campaign_cover',
      2 => 'group_tp_campaign_groups',
      3 => 'group_tp_campaign_sl',
      4 => 'group_tp_campaign_rel',
      5 => 'group_tp_campaign_seg_4',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => NULL,
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );

  return $field_groups;
}
