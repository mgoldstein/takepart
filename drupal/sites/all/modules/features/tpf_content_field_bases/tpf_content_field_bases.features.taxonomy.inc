<?php
/**
 * @file
 * tpf_content_field_bases.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function tpf_content_field_bases_taxonomy_default_vocabularies() {
  return array(
    'video_type' => array(
      'name' => 'Video Type',
      'machine_name' => 'video_type',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
