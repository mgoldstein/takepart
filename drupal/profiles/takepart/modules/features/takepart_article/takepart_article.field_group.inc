<?php
/**
 * @file
 * takepart_article.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function takepart_article_field_group_info() {
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
    'label' => 'Main',
    'weight' => '17',
    'children' => array(
      0 => 'group_article_related',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_article_main|node|openpublish_article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_article_related|node|openpublish_article|form';
  $field_group->group_name = 'group_article_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'openpublish_article';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_article_main';
  $field_group->data = array(
    'label' => 'Related',
    'weight' => '33',
    'children' => array(
      0 => 'field_related_actions',
      1 => 'field_related_content',
      2 => 'field_suggest_campaigns',
      3 => 'field_suggest_content',
      4 => 'field_related_campaigns',
      5 => 'field_suggest_actions',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_article_related|node|openpublish_article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_graphic_header|taxonomy_term|series|form';
  $field_group->group_name = 'group_graphic_header';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'series';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Graphic Header',
    'weight' => '2',
    'children' => array(
      0 => 'field_series_graphic_header',
      1 => 'field_series_graphic_header_link',
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
  $export['group_graphic_header|taxonomy_term|series|form'] = $field_group;

  return $export;
}
