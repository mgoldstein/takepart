<?php
/**
 * @file
 * takepart_search.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function takepart_search_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'block_search';
  $context->description = 'Search';
  $context->tag = 'Block: Search';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'search*' => 'search*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'search_api_facets-site_node_index_field_topic' => array(
          'module' => 'search_api_facets',
          'delta' => 'site_node_index_field_topic',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'search_api_facets-site_node_index_type' => array(
          'module' => 'search_api_facets',
          'delta' => 'site_node_index_type',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'search_api_facets-site_node_index_field_series' => array(
          'module' => 'search_api_facets',
          'delta' => 'site_node_index_field_series',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'search_api_facets-site_node_index_field_blogpost_b' => array(
          'module' => 'search_api_facets',
          'delta' => 'site_node_index_field_blogpost_b',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'search_api_facets-site_node_index_field_free_tag' => array(
          'module' => 'search_api_facets',
          'delta' => 'site_node_index_field_free_tag',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Block: Search');
  t('Search');
  $export['block_search'] = $context;

  return $export;
}
