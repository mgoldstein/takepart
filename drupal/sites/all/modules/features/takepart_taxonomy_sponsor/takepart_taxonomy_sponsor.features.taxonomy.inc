<?php
/**
 * @file
 * takepart_taxonomy_sponsor.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function takepart_taxonomy_sponsor_taxonomy_default_vocabularies() {
  return array(
    'sponsor' => array(
      'name' => 'Sponsor',
      'machine_name' => 'sponsor',
      'description' => 'Sponsored content',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
