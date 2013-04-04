<?php
/**
 * @file
 * article_campaign_taxonomy.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function article_campaign_taxonomy_taxonomy_default_vocabularies() {
  return array(
    'article_campaign' => array(
      'name' => 'Article Campaign',
      'machine_name' => 'article_campaign',
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
