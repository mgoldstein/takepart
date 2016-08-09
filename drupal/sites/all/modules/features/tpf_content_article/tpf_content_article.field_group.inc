<?php
/**
 * @file
 * tpf_content_article.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function tpf_content_article_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_article_main|node|openpublish_article|form';
  $field_group->group_name = 'group_article_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'openpublish_article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Deprectated',
    'weight' => '21',
    'children' => array(
      0 => 'field_article_action',
      1 => 'field_display_tag',
      2 => 'field_related_actions',
      3 => 'field_related_content',
      4 => 'field_suggest_campaigns',
      5 => 'field_suggest_content',
      6 => 'field_related_campaigns',
      7 => 'field_suggest_actions',
      8 => 'field_multi_page_campaign',
      9 => 'field_tp_campaign_show_title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Deprectated',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_article_main|node|openpublish_article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_autoload_settings|node|openpublish_article|form';
  $field_group->group_name = 'group_autoload_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'openpublish_article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Autoload Settings',
    'weight' => '23',
    'children' => array(
      0 => 'field_autoload',
      1 => 'field_auto_free_tagged',
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
  $field_groups['group_autoload_settings|node|openpublish_article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_deprecated|node|openpublish_article|form';
  $field_group->group_name = 'group_deprecated';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'openpublish_article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Deprecated',
    'weight' => '16',
    'children' => array(
      0 => 'field_display_tag',
      1 => 'field_multi_page_campaign',
      2 => 'field_article_action',
      3 => 'field_html_title',
      4 => 'field_related_actions',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_deprecated|node|openpublish_article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_editorial_dates|node|openpublish_article|form';
  $field_group->group_name = 'group_editorial_dates';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'openpublish_article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Editorial Info',
    'weight' => '24',
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
  $field_groups['group_editorial_dates|node|openpublish_article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_promo|node|openpublish_article|form';
  $field_group->group_name = 'group_promo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'openpublish_article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Promo',
    'weight' => '0',
    'children' => array(
      0 => 'field_promo_headline',
      1 => 'field_promo_text',
      2 => 'field_promo_short_headline',
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
  $field_groups['group_promo|node|openpublish_article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tagging|node|openpublish_article|form';
  $field_group->group_name = 'group_tagging';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'openpublish_article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tagging',
    'weight' => '14',
    'children' => array(
      0 => 'field_free_tag',
      1 => 'field_series',
      2 => 'field_topic',
      3 => 'field_admin_tag',
      4 => 'field_sponsored',
      5 => 'field_topic_box',
      6 => 'field_campaign_promo_opt_out',
      7 => 'field_editor_campaign_reference',
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
  $field_groups['group_tagging|node|openpublish_article|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Autoload Settings');
  t('Deprecated');
  t('Deprectated');
  t('Editorial Info');
  t('Promo');
  t('Tagging');

  return $field_groups;
}
