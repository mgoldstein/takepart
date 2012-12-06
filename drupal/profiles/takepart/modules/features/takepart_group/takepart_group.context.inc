<?php
/**
 * @file
 * takepart_group.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function takepart_group_context_default_contexts() {
  $export = array();

  $context = new stdClass();
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
        'takepart_custom-page_title_h1' => array(
          'module' => 'takepart_custom',
          'delta' => 'page_title_h1',
          'region' => 'highlighted',
          'weight' => '0',
        ),
        'boxes-box-c5c30007' => array(
          'module' => 'boxes',
          'delta' => 'box-c5c30007',
          'region' => 'highlighted',
          'weight' => '1',
        ),
        'boxes-box-f070c115' => array(
          'module' => 'boxes',
          'delta' => 'box-f070c115',
          'region' => 'sidebar_first',
          'weight' => '0',
        ),
        'views-related_actions-block_2' => array(
          'module' => 'views',
          'delta' => 'related_actions-block_2',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
      ),
    ),
    'title' => array(
      'title_off' => 1,
      'title_override' => '',
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
