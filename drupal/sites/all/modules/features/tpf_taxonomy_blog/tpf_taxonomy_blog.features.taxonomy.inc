<?php
/**
 * @file
 * tpf_taxonomy_blog.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function tpf_taxonomy_blog_taxonomy_default_vocabularies() {
  return array(
    'blog' => array(
      'name' => 'Blog',
      'machine_name' => 'blog',
      'description' => 'Organizational vocabulary for blog contributors or sections',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => -7,
    ),
  );
}
