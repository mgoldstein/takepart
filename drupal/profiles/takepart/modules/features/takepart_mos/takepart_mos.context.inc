<?php
/**
 * @file
 * takepart_mos.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function takepart_mos_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blocks_mos';
  $context->description = 'Message of Support Blocks';
  $context->tag = 'Blocks: Content Type';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'mos_action' => 'mos_action',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-takepart_mos_signatures-block_1' => array(
          'module' => 'views',
          'delta' => 'takepart_mos_signatures-block_1',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks: Content Type');
  t('Message of Support Blocks');
  $export['blocks_mos'] = $context;

  return $export;
}
