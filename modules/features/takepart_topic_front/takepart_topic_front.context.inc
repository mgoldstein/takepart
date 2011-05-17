<?php
/**
 * @file
 * takepart_topic_front.context.inc
 */

/**
 * Implementation of hook_context_default_contexts().
 */
function takepart_topic_front_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'topic_default_context';
  $context->description = '';
  $context->tag = 'Context Field';
  $context->conditions = array(
    'context_field' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-taxonomy_search_list-block' => array(
          'module' => 'views',
          'delta' => 'taxonomy_search_list-block',
          'region' => 'content',
          'weight' => '-10',
        ),
        'search_api_facets-standard_node_index_field_blogpo' => array(
          'module' => 'search_api_facets',
          'delta' => 'standard_node_index_field_blogpo',
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
  t('Context Field');
  $export['topic_default_context'] = $context;

  return $export;
}
