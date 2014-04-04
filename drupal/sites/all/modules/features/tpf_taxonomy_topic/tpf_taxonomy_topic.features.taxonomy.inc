<?php
/**
 * @file
 * tpf_taxonomy_topic.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function tpf_taxonomy_topic_taxonomy_default_vocabularies() {
  return array(
    'topic' => array(
      'name' => 'Topic',
      'machine_name' => 'topic',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -2,
    ),
  );
}
