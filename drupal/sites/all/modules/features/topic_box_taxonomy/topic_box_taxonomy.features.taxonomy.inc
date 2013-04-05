<?php
/**
 * @file
 * topic_box_taxonomy.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function topic_box_taxonomy_taxonomy_default_vocabularies() {
  return array(
    'topic_box' => array(
      'name' => 'Topic Box',
      'machine_name' => 'topic_box',
      'description' => 'Topic Box Badges',
      'hierarchy' => '1',
      'module' => 'taxonomy',
      'weight' => '0',
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
