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

  // Exported field_base: 'field_syndication'
  $field_bases['field_syndication'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_syndication',
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
        0 => 'Exclude from Syndication',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_integer',
  );

  return $field_bases;
}
