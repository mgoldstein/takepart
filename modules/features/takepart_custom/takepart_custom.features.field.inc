<?php
/**
 * @file
 * takepart_custom.features.field.inc
 */

/**
 * Implementation of hook_field_default_fields().
 */
function takepart_custom_field_default_fields() {
  $fields = array();

  // Exported field: 'taxonomy_term-free_tags-field_free_tag_context'
  $fields['taxonomy_term-free_tags-field_free_tag_context'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_free_tag_context',
      'foreign keys' => array(),
      'indexes' => array(),
      'module' => 'context_field',
      'settings' => array(
        'global_setting' => 255,
      ),
      'translatable' => '1',
      'type' => 'context_field',
    ),
    'field_instance' => array(
      'bundle' => 'free_tags',
      'default_value' => array(
        0 => array(
          'context' => '',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'context_field',
          'settings' => array(),
          'type' => 'context_field_context',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_free_tag_context',
      'label' => 'Context',
      'required' => 0,
      'settings' => array(
        'allowed_blocks' => array(
          'Boxes for Box' => 0,
          'Boxes for Field Box' => 0,
          'Boxes for View Box' => 0,
          'addthis' => 0,
          'boxes' => 0,
          'comment' => 0,
          'context_ui' => 0,
          'devel' => 0,
          'diff' => 0,
          'menu' => 0,
          'node' => 0,
          'search' => 0,
          'search_api_facets' => 0,
          'shortcut' => 0,
          'system' => 0,
          'user' => 0,
          'views' => 0,
        ),
        'default_context' => 'free_tags_default_context',
        'use_default' => '1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'context_field',
        'settings' => array(
          'widget_setting' => 'bob',
        ),
        'type' => 'context_field',
        'weight' => '1',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Context');

  return $fields;
}
