<?php
/**
 * @file
 * tpf_content_campaigns.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function tpf_content_campaigns_taxonomy_default_vocabularies() {
  return array(
    'campaign_type' => array(
      'name' => 'Campaign Type',
      'machine_name' => 'campaign_type',
      'description' => 'Campaign Type for analytics and feeds',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
