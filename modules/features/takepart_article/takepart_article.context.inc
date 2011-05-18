<?php
/**
 * @file
 * takepart_article.context.inc
 */

/**
 * Implementation of hook_context_default_contexts().
 */
function takepart_article_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'series_default_context';
  $context->description = 'Default Context for series';
  $context->tag = 'Context Field Default';
  $context->conditions = array(
    'context_field' => array(
      'values' => array(
        1 => 1,
        2 => 2,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-taxonomy_search_list-block_2' => array(
          'module' => 'views',
          'delta' => 'taxonomy_search_list-block_2',
          'region' => 'content',
          'weight' => '-10',
        ),
        'search_api_facets-standard_node_index_field_topic' => array(
          'module' => 'search_api_facets',
          'delta' => 'standard_node_index_field_topic',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'search_api_facets-standard_node_index_type' => array(
          'module' => 'search_api_facets',
          'delta' => 'standard_node_index_type',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context Field Default');
  t('Default Context for series');
  $export['series_default_context'] = $context;

  return $export;
}
