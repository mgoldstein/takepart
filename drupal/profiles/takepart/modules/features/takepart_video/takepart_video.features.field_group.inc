<?php
/**
 * @file
 * takepart_video.features.field_group.inc
 */

/**
 * Implementation of hook_field_group_default_field_groups().
 */
function takepart_video_field_group_default_field_groups() {
  $field_groups = array();

  // Exported field_group: 'node-video_series-form-group_series_videos'
  $field_groups['node-video_series-form-group_series_videos'] = array(
    'group_name' => 'group_series_videos',
    'entity_type' => 'node',
    'bundle' => 'video_series',
    'mode' => 'form',
    'parent_name' => 'group_vs_hz_group',
    'label' => 'Series',
    'weight' => '7',
    'children' => array(
      0 => 'field_series_videos_by_tag',
      1 => 'field_series_videos_refs',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );

  // Exported field_group: 'node-video_series-form-group_vs_hz_group'
  $field_groups['node-video_series-form-group_vs_hz_group'] = array(
    'group_name' => 'group_vs_hz_group',
    'entity_type' => 'node',
    'bundle' => 'video_series',
    'mode' => 'form',
    'parent_name' => '',
    'label' => 'Series and Taxonomy',
    'weight' => '8',
    'children' => array(
      0 => 'group_series_videos',
      1 => 'group_vs_taxonomy',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );

  // Exported field_group: 'node-video_series-form-group_vs_taxonomy'
  $field_groups['node-video_series-form-group_vs_taxonomy'] = array(
    'group_name' => 'group_vs_taxonomy',
    'entity_type' => 'node',
    'bundle' => 'video_series',
    'mode' => 'form',
    'parent_name' => 'group_vs_hz_group',
    'label' => 'Taxonomy',
    'weight' => '8',
    'children' => array(
      0 => 'field_vs_free_term',
      1 => 'field_vs_topic_term',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );

  return $field_groups;
}
