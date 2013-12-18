<?php
/**
 * @file
 * takepart_action.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function takepart_action_taxonomy_default_vocabularies() {
  return array(
    'action_type' => array(
      'name' => 'Action Type',
      'machine_name' => 'action_type',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '-10',
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
