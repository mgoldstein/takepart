<?php
/**
 * @file
 * tpf_display_featured_campaigns.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function tpf_display_featured_campaigns_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_featured_group|field_collection_item|field_featured_campaigns|form';
  $field_group->group_name = 'group_featured_group';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_featured_campaigns';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Item Fieldset',
    'weight' => '2',
    'children' => array(
      0 => 'field_featured_campaign_link',
      1 => 'field_promo_headline_wysiw',
      2 => 'field_promo_label',
      3 => 'field_thumbnail',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Item Fieldset',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-featured-group field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_featured_group|field_collection_item|field_featured_campaigns|form'] = $field_group;

  return $export;
}
