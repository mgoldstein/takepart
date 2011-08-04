<?php
/**
 * @file
 * takepart_video.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function takepart_video_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_series_videos|node|video_series|form';
  $field_group->group_name = 'group_series_videos';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'video_series';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_vs_hz_group';
  $field_group->data = array(
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
  $export['group_series_videos|node|video_series|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_vs_hz_group|node|video_series|form';
  $field_group->group_name = 'group_vs_hz_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'video_series';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
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
  $export['group_vs_hz_group|node|video_series|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_vs_taxonomy|node|video_series|form';
  $field_group->group_name = 'group_vs_taxonomy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'video_series';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_vs_hz_group';
  $field_group->data = array(
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
  $export['group_vs_taxonomy|node|video_series|form'] = $field_group;

  return $export;
}
