<?php
/**
 * @file
 * tp_latest_headlines_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function tp_latest_headlines_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'tp_latest_headline';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/structure/nodequeue/2' => 'admin/structure/nodequeue/2',
        'admin/structure/nodequeue/2/view/2' => 'admin/structure/nodequeue/2/view/2',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-87e72108321fe9d9def8074a8c3817ec' => array(
          'module' => 'views',
          'delta' => '87e72108321fe9d9def8074a8c3817ec',
          'region' => 'content',
          'weight' => '100',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['tp_latest_headline'] = $context;

  return $export;
}
