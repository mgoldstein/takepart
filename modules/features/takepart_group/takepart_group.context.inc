<?php
/**
 * @file
 * takepart_group.context.inc
 */

/**
 * Implementation of hook_context_default_contexts().
 */
function takepart_group_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blocks_group';
  $context->description = 'Group Blocks';
  $context->tag = 'Blocks: Content Type';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'takepart_group' => 'takepart_group',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-related_actions-block_2' => array(
          'module' => 'views',
          'delta' => 'related_actions-block_2',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks: Content Type');
  t('Group Blocks');
  $export['blocks_group'] = $context;

  return $export;
}
