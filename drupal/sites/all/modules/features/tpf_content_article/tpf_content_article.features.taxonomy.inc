<?php
/**
 * @file
 * tpf_content_article.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function tpf_content_article_taxonomy_default_vocabularies() {
  return array(
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
