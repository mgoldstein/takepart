<?php
/**
 * @file
 * takepart_action.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function takepart_action_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blocks_action';
  $context->description = 'Action Blocks';
  $context->tag = 'Blocks: Content Type';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'action' => 'action',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-groups-block' => array(
          'module' => 'views',
          'delta' => 'groups-block',
          'region' => 'sidebar_second',
          'weight' => 0,
        ),
        'views-related_content-block' => array(
          'module' => 'views',
          'delta' => 'related_content-block',
          'region' => 'sidebar_second',
          'weight' => 3,
        ),
        'views-related_actions-block' => array(
          'module' => 'views',
          'delta' => 'related_actions-block',
          'region' => 'sidebar_second',
          'weight' => 4,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Action Blocks');
  t('Blocks: Content Type');
  $export['blocks_action'] = $context;

  return $export;
}
