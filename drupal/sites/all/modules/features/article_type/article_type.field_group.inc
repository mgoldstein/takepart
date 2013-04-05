<?php
/**
 * @file
 * article_type.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function article_type_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_promo_fields|node|article|form';
  $field_group->group_name = 'group_promo_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Promo Fields',
    'weight' => '19',
    'children' => array(
      0 => 'field_article_campaign_terms',
      1 => 'field_article_series_terms',
      2 => 'field_article_topic_terms',
      3 => 'field_promo_image',
      4 => 'field_url',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_promo_fields|node|article|form'] = $field_group;

  return $export;
}
