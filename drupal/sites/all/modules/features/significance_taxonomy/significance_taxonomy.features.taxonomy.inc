<?php
/**
 * @file
 * significance_taxonomy.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function significance_taxonomy_taxonomy_default_vocabularies() {
  return array(
    'significance' => array(
      'name' => 'Significance',
      'machine_name' => 'significance',
      'description' => 'Taxonomy to describe the significance of a piece of content',
      'hierarchy' => '0',
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
