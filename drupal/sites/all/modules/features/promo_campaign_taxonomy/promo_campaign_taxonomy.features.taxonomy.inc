<?php
/**
 * @file
 * promo_campaign_taxonomy.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function promo_campaign_taxonomy_taxonomy_default_vocabularies() {
  return array(
    'promo_campaign' => array(
      'name' => 'Promo Campaign',
      'machine_name' => 'promo_campaign',
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
