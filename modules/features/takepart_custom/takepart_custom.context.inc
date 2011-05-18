<?php
/**
 * @file
 * takepart_custom.context.inc
 */

/**
 * Implementation of hook_context_default_contexts().
 */
function takepart_custom_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'free_tags_default_context';
  $context->description = 'Default Context for free_tags';
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
        'views-taxonomy_search_list-block_1' => array(
          'module' => 'views',
          'delta' => 'taxonomy_search_list-block_1',
          'region' => 'content',
          'weight' => '-10',
        ),
        'search_api_facets-standard_node_index_type' => array(
          'module' => 'search_api_facets',
          'delta' => 'standard_node_index_type',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'search_api_facets-standard_node_index_field_topic' => array(
          'module' => 'search_api_facets',
          'delta' => 'standard_node_index_field_topic',
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
  t('Default Context for free_tags');
  $export['free_tags_default_context'] = $context;

  return $export;
}
