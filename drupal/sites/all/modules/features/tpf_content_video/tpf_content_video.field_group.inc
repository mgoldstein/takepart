<?php
/**
 * @file
 * tpf_content_video.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function tpf_content_video_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_autoload_settings|node|video_playlist|form';
  $field_group->group_name = 'group_autoload_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'video_playlist';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Autoload Settings',
    'weight' => '20',
    'children' => array(
      0 => 'field_autoload',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-autoload-settings field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_autoload_settings|node|video_playlist|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_autoload_settings|node|video|form';
  $field_group->group_name = 'group_autoload_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'video';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Autoload Settings',
    'weight' => '55',
    'children' => array(
      0 => 'field_autoload',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-autoload-settings field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_autoload_settings|node|video|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_editorial_dates|node|video_playlist|form';
  $field_group->group_name = 'group_editorial_dates';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'video_playlist';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Editorial Info',
    'weight' => '21',
    'children' => array(
      0 => 'field_assigned_editor',
      1 => 'field_due_date',
      2 => 'field_run_date',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Editorial Info',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_editorial_dates|node|video_playlist|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_editorial_dates|node|video|form';
  $field_group->group_name = 'group_editorial_dates';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'video';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Editorial Info',
    'weight' => '59',
    'children' => array(
      0 => 'field_assigned_editor',
      1 => 'field_due_date',
      2 => 'field_run_date',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Editorial Info',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_editorial_dates|node|video|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_player_config|node|video_playlist|form';
  $field_group->group_name = 'group_player_config';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'video_playlist';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Player Configuration',
    'weight' => '11',
    'children' => array(
      0 => 'field_allowed_regions',
      1 => 'field_playlist_view_mode',
      2 => 'field_sharing_inline',
      3 => 'field_show_title',
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
  $field_groups['group_player_config|node|video_playlist|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_playlist_settings|node|video_playlist|form';
  $field_group->group_name = 'group_playlist_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'video_playlist';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Playlist Settings',
    'weight' => '4',
    'children' => array(
      0 => 'field_playlist_filter',
      1 => 'field_playlist_filter_sorting',
      2 => 'field_playlist_items_count',
      3 => 'field_video_list',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-playlist-settings field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_playlist_settings|node|video_playlist|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_promo|node|video_playlist|form';
  $field_group->group_name = 'group_promo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'video_playlist';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Promo',
    'weight' => '9',
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
  $field_groups['group_promo|node|video_playlist|form'] = $field_group;

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
    'weight' => '10',
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
  $field_groups['group_promo|node|video|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tagging|node|video_playlist|form';
  $field_group->group_name = 'group_tagging';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'video_playlist';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tagging',
    'weight' => '10',
    'children' => array(
      0 => 'field_admin_tag',
      1 => 'field_free_tag',
      2 => 'field_series',
      3 => 'field_topic',
      4 => 'field_sponsored',
      5 => 'field_topic_box',
      6 => 'field_editor_campaign_reference',
      7 => 'field_campaign_promo_opt_out',
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
  $field_groups['group_tagging|node|video_playlist|form'] = $field_group;

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
    'weight' => '11',
    'children' => array(
      0 => 'field_admin_tag',
      1 => 'field_free_tag',
      2 => 'field_series',
      3 => 'field_topic',
      4 => 'field_sponsored',
      5 => 'field_topic_box',
      6 => 'field_editor_campaign_reference',
      7 => 'field_campaign_promo_opt_out',
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
  $field_groups['group_tagging|node|video|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Autoload Settings');
  t('Editorial Info');
  t('Player Configuration');
  t('Playlist Settings');
  t('Promo');
  t('Tagging');

  return $field_groups;
}
