<?php
/**
 * @file
 * tp_custom_nav.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function tp_custom_nav_taxonomy_default_vocabularies() {
  return array(
    'brand' => array(
      'name' => 'Brand',
      'machine_name' => 'brand',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
