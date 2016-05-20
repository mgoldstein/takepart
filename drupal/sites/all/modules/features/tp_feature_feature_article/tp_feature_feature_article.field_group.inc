<?php
/**
 * @file
 * tp_feature_feature_article.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function tp_feature_feature_article_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_article_hero|node|feature_article|form';
  $field_group->group_name = 'group_article_hero';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'feature_article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Background',
    'weight' => '6',
    'children' => array(
      0 => 'field_article_main_image',
      1 => 'field_thumbnail',
      2 => 'field_main_img_to_thumb',
      3 => 'field_article_background_video',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Background',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => 'group-article-hero field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_article_hero|node|feature_article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_autoload_settings|node|feature_article|form';
  $field_group->group_name = 'group_autoload_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'feature_article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Autoload Settings',
    'weight' => '22',
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
  $field_groups['group_autoload_settings|node|feature_article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_editorial_dates|node|feature_article|form';
  $field_group->group_name = 'group_editorial_dates';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'feature_article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Editorial Info',
    'weight' => '20',
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
  $field_groups['group_editorial_dates|node|feature_article|form'] = $field_group;

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
    'weight' => '9',
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
  $field_groups['group_inline_replacements|node|feature_article|form'] = $field_group;

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
        'classes' => 'group-promo field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_promo|node|feature_article|form'] = $field_group;

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
    'weight' => '12',
    'children' => array(
      0 => 'field_admin_tag',
      1 => 'field_free_tag',
      2 => 'field_series',
      3 => 'field_topic',
      4 => 'field_sponsored',
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
  $field_groups['group_tagging|node|feature_article|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Autoload Settings');
  t('Background');
  t('Editorial Info');
  t('Inline Replacements');
  t('Promo');
  t('Tagging');

  return $field_groups;
}
