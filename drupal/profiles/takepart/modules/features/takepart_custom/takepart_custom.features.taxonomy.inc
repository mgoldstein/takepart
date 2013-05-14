<?php
/**
 * @file
 * takepart_custom.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function takepart_custom_taxonomy_default_vocabularies() {
  return array(
    'free_tags' => array(
      'name' => 'Free Tags',
      'machine_name' => 'free_tags',
      'description' => 'These tags will be pretty fine-grained and will support more broad categorizations of content via the Topic vocabulary',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '-7',
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
    'topic' => array(
      'name' => 'Topic',
      'machine_name' => 'topic',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '-3',
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
