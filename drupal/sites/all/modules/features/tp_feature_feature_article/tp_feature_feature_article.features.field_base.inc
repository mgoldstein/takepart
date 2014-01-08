<?php
/**
 * @file
 * tp_feature_feature_article.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function tp_feature_feature_article_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_title_color'
  $field_bases['field_title_color'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_title_color',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'white' => 'White',
        'black' => 'Black',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
