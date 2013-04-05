<?php
/**
 * @file
 * promo_series_taxonomy.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function promo_series_taxonomy_taxonomy_default_vocabularies() {
  return array(
    'promo_series' => array(
      'name' => 'Promo Series',
      'machine_name' => 'promo_series',
      'description' => 'Taxonomy used in Promo boxes on related content.',
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
