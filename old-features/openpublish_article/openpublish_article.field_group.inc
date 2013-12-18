<?php
/**
 * @file
 * openpublish_article.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function openpublish_article_field_group_info() {
  $export = array();

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
    'weight' => '20',
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
      10 => 'field_related_stories',
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
  $export['group_article_main|node|openpublish_article|form'] = $field_group;

  return $export;
}
