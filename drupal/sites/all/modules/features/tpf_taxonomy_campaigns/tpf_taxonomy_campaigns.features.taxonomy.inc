<?php
/**
 * @file
 * tpf_taxonomy_campaigns.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function tpf_taxonomy_campaigns_taxonomy_default_vocabularies() {
  return array(
    'campaign_categories' => array(
      'name' => 'Campaign Categories',
      'machine_name' => 'campaign_categories',
      'description' => 'Allows editors to categorize campaigns.',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'social_follow' => array(
      'name' => 'Social Follow',
      'machine_name' => 'social_follow',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
