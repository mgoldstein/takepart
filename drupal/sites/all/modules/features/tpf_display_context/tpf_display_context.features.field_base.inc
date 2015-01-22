<?php
/**
 * @file
 * tpf_display_context.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function tpf_display_context_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_social_share_bar'
  $field_bases['field_social_share_bar'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_social_share_bar',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'takepart_addthis',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'share_bar',
  );

  return $field_bases;
}
