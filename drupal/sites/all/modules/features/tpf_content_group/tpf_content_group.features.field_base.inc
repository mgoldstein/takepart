<?php
/**
 * @file
 * tpf_content_group.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function tpf_content_group_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_group_topic'
  $field_bases['field_group_topic'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_group_topic',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'topic',
          'parent' => 0,
          'depth' => '',
        ),
      ),
      'options_list_callback' => 'content_taxonomy_allowed_values',
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  return $field_bases;
}
