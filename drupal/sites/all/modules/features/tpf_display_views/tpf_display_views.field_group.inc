<?php
/**
 * @file
 * tpf_display_views.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function tpf_display_views_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_video_config_options|node|video|form';
  $field_group->group_name = 'group_video_config_options';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'video';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Player Config Options',
    'weight' => '20',
    'children' => array(
      0 => 'field_allowed_regions',
      1 => 'field_auto_play',
      2 => 'field_mute_playback',
      3 => 'field_player_embeddable',
      4 => 'field_player_skin',
      5 => 'field_share_url',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Player Config Options',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-player-config-options field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_video_config_options|node|video|form'] = $field_group;

  return $export;
}
