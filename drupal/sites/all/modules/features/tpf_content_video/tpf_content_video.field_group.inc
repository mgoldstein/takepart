<?php
/**
 * @file
 * tpf_content_video.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function tpf_content_video_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_player_config|node|video|form';
  $field_group->group_name = 'group_player_config';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'video';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Player Configuration',
    'weight' => '10',
    'children' => array(
      0 => 'field_ads_client',
      1 => 'field_ads_tag',
      2 => 'field_allowed_regions',
      3 => 'field_auto_play',
      4 => 'field_mute_playback',
      5 => 'field_player_skin',
      6 => 'field_playlist_layout',
      7 => 'field_playlist_position',
      8 => 'field_playlist_size',
      9 => 'field_sharing_enabled',
      10 => 'field_share_url',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-player-config field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_player_config|node|video|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_promo|node|video|form';
  $field_group->group_name = 'group_promo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'video';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Promo',
    'weight' => '8',
    'children' => array(
      0 => 'field_promo_headline',
      1 => 'field_promo_short_headline',
      2 => 'field_promo_text',
      3 => 'field_thumbnail',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-promo field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_promo|node|video|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tagging|node|video|form';
  $field_group->group_name = 'group_tagging';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'video';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tagging',
    'weight' => '9',
    'children' => array(
      0 => 'field_admin_tag',
      1 => 'field_display_tag',
      2 => 'field_free_tag',
      3 => 'field_series',
      4 => 'field_significance',
      5 => 'field_topic',
      6 => 'field_topic_box',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tagging field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tagging|node|video|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_video_main|node|openpublish_video|form';
  $field_group->group_name = 'group_video_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'openpublish_video';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '3',
    'children' => array(
      0 => 'body',
      1 => 'field_author',
      2 => 'field_subhead',
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
  $export['group_video_main|node|openpublish_video|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_video_media|node|openpublish_video|form';
  $field_group->group_name = 'group_video_media';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'openpublish_video';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Media',
    'weight' => '4',
    'children' => array(
      0 => 'field_video_embedded',
      1 => 'field_main_image',
      2 => 'field_thumbnail',
      3 => 'field_video_display_mode',
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
  $export['group_video_media|node|openpublish_video|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_video_promo|node|openpublish_video|form';
  $field_group->group_name = 'group_video_promo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'openpublish_video';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Promo',
    'weight' => '5',
    'children' => array(
      0 => 'field_promo_headline',
      1 => 'field_promo_text',
      2 => 'field_promo_short_headline',
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
  $export['group_video_promo|node|openpublish_video|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_video_related|node|openpublish_video|form';
  $field_group->group_name = 'group_video_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'openpublish_video';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related',
    'weight' => '6',
    'children' => array(
      0 => 'field_video_related',
      1 => 'field_suggest_actions',
      2 => 'field_related_actions',
      3 => 'field_suggest_video',
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
  $export['group_video_related|node|openpublish_video|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_video_tags|node|openpublish_video|form';
  $field_group->group_name = 'group_video_tags';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'openpublish_video';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tags',
    'weight' => '7',
    'children' => array(
      0 => 'field_free_tag',
      1 => 'field_series',
      2 => 'field_topic',
      3 => 'field_multi_page_campaign',
      4 => 'field_video_series',
      5 => 'field_display_tag',
      6 => 'field_admin_tag',
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
  $export['group_video_tags|node|openpublish_video|form'] = $field_group;

  return $export;
}
