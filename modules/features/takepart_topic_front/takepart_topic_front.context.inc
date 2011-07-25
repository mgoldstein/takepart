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
        'context_field' => 'context_field',
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
        'boxes-box-bb0b625d' => array(
          'module' => 'boxes',
          'delta' => 'box-bb0b625d',
          'region' => 'content_top',
          'weight' => 0,
        ),
        'takepart_custom-page_title_h1' => array(
          'module' => 'takepart_custom',
          'delta' => 'page_title_h1',
          'region' => 'content_top',
          'weight' => 1,
        ),
        'views-quick_study-block' => array(
          'module' => 'views',
          'delta' => 'quick_study-block',
          'region' => 'content_top',
          'weight' => 2,
        ),
        'views-taxonomy_search_list-block' => array(
          'module' => 'views',
          'delta' => 'taxonomy_search_list-block',
          'region' => 'content_bottom',
          'weight' => 0,
        ),
        'views-related_campaigns-block_1' => array(
          'module' => 'views',
          'delta' => 'related_campaigns-block_1',
          'region' => 'sidebar_second',
          'weight' => 0,
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
