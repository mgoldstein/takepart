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
  $context->description = 'Default Context for topic';
  $context->tag = 'Context Field';
  $context->conditions = array(
    'context_field' => array(
      'values' => array(
        1 => 1,
        2 => 2,
      ),
      'options' => array(
        'context_field_category' => '',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-quick_study-block' => array(
          'module' => 'views',
          'delta' => 'quick_study-block',
          'region' => 'content',
          'weight' => '-70',
        ),
        'views-taxonomy_search_list-block' => array(
          'module' => 'views',
          'delta' => 'taxonomy_search_list-block',
          'region' => 'content',
          'weight' => '-69',
        ),
        'search_api_facets-standard_node_index_type' => array(
          'module' => 'search_api_facets',
          'delta' => 'standard_node_index_type',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'search_api_facets-standard_node_index_field_blogpo' => array(
          'module' => 'search_api_facets',
          'delta' => 'standard_node_index_field_blogpo',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'views-related_campaigns-block_1' => array(
          'module' => 'views',
          'delta' => 'related_campaigns-block_1',
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
  t('Default Context for topic');
  $export['topic_default_context'] = $context;

  return $export;
}
