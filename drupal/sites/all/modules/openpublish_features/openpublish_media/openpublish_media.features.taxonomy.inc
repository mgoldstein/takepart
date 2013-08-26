<?php
/**
 * @file
 * openpublish_media.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function openpublish_media_taxonomy_default_vocabularies() {
  return array(
    'admin_tag' => array(
      'name' => 'Admin Tag',
      'machine_name' => 'admin_tag',
      'description' => 'Internal taxonomy for distributing content (for example, to RSS feeds) that is not visible to external users',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '-9',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
