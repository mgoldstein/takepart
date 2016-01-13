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
      'description' => 'Editorial verticle',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -2,
    ),
    'topic_box' => array(
      'name' => 'Topic Box',
      'machine_name' => 'topic_box',
      'description' => 'Topic Box Badges',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 1,
    ),
  );
}
