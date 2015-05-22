<?php
/**
 * @file
 * tpf_content_flashcard.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function tpf_content_flashcard_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_definition|node|flashcard|default';
  $field_group->group_name = 'group_definition';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'flashcard';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Definition',
    'weight' => '3',
    'children' => array(
      0 => 'field_flashcard_display_name',
      1 => 'field_flashcard_pronunciation',
      2 => 'field_flashcard_short_definition',
    ),
    'format_type' => 'html5',
    'format_settings' => array(
      'label' => 'Definition',
      'instance_settings' => array(
        'classes' => 'flashcard-definition',
        'wrapper' => 'aside',
        'id' => 'node_flashcard_full_group_definition',
      ),
    ),
  );
  $export['group_definition|node|flashcard|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_flashcard_page|node|flashcard|form';
  $field_group->group_name = 'group_flashcard_page';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'flashcard';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Flashcard Page',
    'weight' => '8',
    'children' => array(
      0 => 'body',
      1 => 'field_article_subhead',
      2 => 'group_inline_replacements',
      3 => 'group_related',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-flashcard-page field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_flashcard_page|node|flashcard|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_flashcard_popup|node|flashcard|form';
  $field_group->group_name = 'group_flashcard_popup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'flashcard';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Flashcard Popup',
    'weight' => '7',
    'children' => array(),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-flashcard-popup field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_flashcard_popup|node|flashcard|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_inline_replacements|node|flashcard|form';
  $field_group->group_name = 'group_inline_replacements';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'flashcard';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_flashcard_page';
  $field_group->data = array(
    'label' => 'Inline Replacements',
    'weight' => '10',
    'children' => array(
      0 => 'field_inline_replacements',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Inline Replacements',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-inline-replacements field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_inline_replacements|node|flashcard|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_promo|node|flashcard|form';
  $field_group->group_name = 'group_promo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'flashcard';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Promo',
    'weight' => '13',
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
  $export['group_promo|node|flashcard|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related|node|flashcard|form';
  $field_group->group_name = 'group_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'flashcard';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_flashcard_page';
  $field_group->data = array(
    'label' => 'Related Content',
    'weight' => '11',
    'children' => array(),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-related field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_related|node|flashcard|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tagging|node|flashcard|form';
  $field_group->group_name = 'group_tagging';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'flashcard';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tagging',
    'weight' => '14',
    'children' => array(
      0 => 'field_admin_tag',
      1 => 'field_free_tag',
      2 => 'field_significance',
      3 => 'field_topic',
      4 => 'field_series',
      5 => 'field_sponsored',
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
  $export['group_tagging|node|flashcard|form'] = $field_group;

  return $export;
}
