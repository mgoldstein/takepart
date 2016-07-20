<?php
/**
 * @file
 * tp_feature_fresh_gallery.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function tp_feature_fresh_gallery_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fresh_gallery_promo|node|fresh_gallery|form';
  $field_group->group_name = 'group_fresh_gallery_promo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'fresh_gallery';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Promo',
    'weight' => '0',
    'children' => array(
      0 => 'field_promo_headline',
      1 => 'field_promo_short_headline',
      2 => 'field_promo_text',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-fresh-gallery-promo field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_fresh_gallery_promo|node|fresh_gallery|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_gallery_tagging|node|fresh_gallery|form';
  $field_group->group_name = 'group_gallery_tagging';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'fresh_gallery';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tagging',
    'weight' => '11',
    'children' => array(
      0 => 'field_topic_box',
      1 => 'field_topic',
      2 => 'field_free_tag',
      3 => 'field_sponsored',
      4 => 'field_admin_tag',
      5 => 'field_series',
      6 => 'field_editor_campaign_reference',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-gallery-tagging field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_gallery_tagging|node|fresh_gallery|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Promo');
  t('Tagging');

  return $field_groups;
}
