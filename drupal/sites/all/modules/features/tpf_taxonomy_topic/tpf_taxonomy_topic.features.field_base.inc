<?php
/**
 * @file
 * tpf_taxonomy_topic.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function tpf_taxonomy_topic_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_topic_context'
  $field_bases['field_topic_context'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_topic_context',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'context_field',
    'settings' => array(
      'global_setting' => 255,
    ),
    'translatable' => 1,
    'type' => 'context_field',
  );

  return $field_bases;
}
