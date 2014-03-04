<?php
/**
 * @file
 * tpf_content_campaigns.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function tpf_content_campaigns_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_card_background|node|campaign_card_iframe|form';
  $field_group->group_name = 'group_card_background';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_iframe';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Background',
    'weight' => '4',
    'children' => array(
      0 => 'field_card_background',
      1 => 'field_campaign_bg_color',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-card-background field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_card_background|node|campaign_card_iframe|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_card_background|node|campaign_card_media|form';
  $field_group->group_name = 'group_card_background';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_media';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Background',
    'weight' => '7',
    'children' => array(
      0 => 'field_campaign_background',
      1 => 'field_campaign_bg_color',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-card-background field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_card_background|node|campaign_card_media|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_media|node|campaign_card_media|form';
  $field_group->group_name = 'group_media';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_media';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Media',
    'weight' => '4',
    'children' => array(
      0 => 'field_campaign_media_photo',
      1 => 'field_campaign_media_video',
      2 => 'field_campaign_media_title',
      3 => 'field_campaign_media_caption',
      4 => 'field_campaign_media_type',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-media field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_media|node|campaign_card_media|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tray_background|node|campaign_tray|form';
  $field_group->group_name = 'group_tray_background';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_tray';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Background',
    'weight' => '3',
    'children' => array(
      0 => 'field_campaign_background',
      1 => 'field_campaign_bg_color',
      2 => 'field_campaign_bg_width',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tray-background field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tray_background|node|campaign_tray|form'] = $field_group;

  return $export;
}
