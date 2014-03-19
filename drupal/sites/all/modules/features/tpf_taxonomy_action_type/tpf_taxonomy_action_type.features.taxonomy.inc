<?php
/**
 * @file
 * tpf_taxonomy_action_type.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function tpf_taxonomy_action_type_taxonomy_default_vocabularies() {
  return array(
    'action_type' => array(
      'name' => 'Action Type',
      'machine_name' => 'action_type',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -10,
    ),
  );
}
