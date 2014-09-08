<?php
/**
 * @file
 * tp_feature_feature_article.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function tp_feature_feature_article_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_inline_replacements|node|feature_article|form';
  $field_group->group_name = 'group_inline_replacements';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'feature_article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Inline Replacements',
    'weight' => '7',
    'children' => array(
      0 => 'field_inline_replacements',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-inline-replacements field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_inline_replacements|node|feature_article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_promo|node|feature_article|form';
  $field_group->group_name = 'group_promo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'feature_article';
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
  $export['group_promo|node|feature_article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tagging|node|feature_article|form';
  $field_group->group_name = 'group_tagging';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'feature_article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tagging',
    'weight' => '11',
    'children' => array(
      0 => 'field_admin_tag',
      1 => 'field_free_tag',
      2 => 'field_series',
      3 => 'field_significance',
      4 => 'field_topic',
      5 => 'field_topic_box',
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
  $export['group_tagging|node|feature_article|form'] = $field_group;

  return $export;
}
