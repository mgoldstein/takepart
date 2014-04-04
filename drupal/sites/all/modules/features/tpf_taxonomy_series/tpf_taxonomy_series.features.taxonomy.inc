<?php
/**
 * @file
 * tpf_taxonomy_series.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function tpf_taxonomy_series_taxonomy_default_vocabularies() {
  return array(
    'series' => array(
      'name' => 'Series',
      'machine_name' => 'series',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -3,
    ),
  );
}
