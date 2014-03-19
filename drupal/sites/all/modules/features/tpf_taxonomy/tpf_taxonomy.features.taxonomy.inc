<?php
/**
 * @file
 * tpf_taxonomy.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function tpf_taxonomy_taxonomy_default_vocabularies() {
  return array(
    'admin_tag' => array(
      'name' => 'Admin Tag',
      'machine_name' => 'admin_tag',
      'description' => 'Internal taxonomy for distributing content (for example, to RSS feeds) that is not visible to external users',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -9,
    ),
    'agency' => array(
      'name' => 'Agency',
      'machine_name' => 'agency',
      'description' => 'Asset provider',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -9,
    ),
    'free_tags' => array(
      'name' => 'Free Tags',
      'machine_name' => 'free_tags',
      'description' => 'These tags will be pretty fine-grained and will support more broad categorizations of content via the Topic vocabulary',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -6,
    ),
    'group_type' => array(
      'name' => 'Group Type',
      'machine_name' => 'group_type',
      'description' => 'Used to store the different group types available.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -5,
    ),
    'photo_credit' => array(
      'name' => 'Photo Credit',
      'machine_name' => 'photo_credit',
      'description' => 'Free tagging for images.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -5,
    ),
    'significance' => array(
      'name' => 'Significance',
      'machine_name' => 'significance',
      'description' => 'Taxonomy to describe the significance of a piece of content',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'topic_box' => array(
      'name' => 'Topic Box',
      'machine_name' => 'topic_box',
      'description' => 'Topic Box Badges',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 1,
    ),
    'video_series' => array(
      'name' => 'Video Series',
      'machine_name' => 'video_series',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => -1,
    ),
  );
}
