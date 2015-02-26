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
  $field_group->identifier = 'group_background_image|node|campaign_card_tap_widget|form';
  $field_group->group_name = 'group_background_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_tap_widget';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_background';
  $field_group->data = array(
    'label' => 'Background Image',
    'weight' => '14',
    'children' => array(
      0 => 'field_campaign_background',
      1 => 'field_campaign_bgw_image',
      2 => 'field_campaign_bg_crop',
      3 => 'field_campaign_bg_image_position',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-background-image field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_background_image|node|campaign_card_tap_widget|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background|node|campaign_card_tap_widget|form';
  $field_group->group_name = 'group_background';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'campaign_card_tap_widget';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Background',
    'weight' => '11',
    'children' => array(
      0 => 'field_campaign_bg_color',
      1 => 'field_campaign_bgw',
      2 => 'group_background_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-background field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_background|node|campaign_card_tap_widget|form'] = $field_group;

  return $export;
}
