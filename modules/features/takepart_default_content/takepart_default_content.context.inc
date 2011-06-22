<?php
/**
 * @file
 * takepart_default_content.context.inc
 */

/**
 * Implementation of hook_context_default_contexts().
 */
function takepart_default_content_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'context_field-node-blogs_landing_page';
  $context->description = '';
  $context->tag = 'Context Field';
  $context->conditions = array(
    'context_field' => array(
      'values' => array(
        'context_field' => 'context_field',
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-box-ecdb5429' => array(
          'module' => 'boxes',
          'delta' => 'box-ecdb5429',
          'region' => 'content',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context Field');
  $export['context_field-node-blogs_landing_page'] = $context;

  return $export;
}
