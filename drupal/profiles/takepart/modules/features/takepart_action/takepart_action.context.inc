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

  $context = new stdClass();
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
        'boxes-box-41040ece' => array(
          'module' => 'boxes',
          'delta' => 'box-41040ece',
          'region' => 'highlighted',
          'weight' => '0',
        ),
        'menu-menu-takeaction-button-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-takeaction-button-menu',
          'region' => 'highlighted',
          'weight' => '1',
        ),
        'boxes-box-66c05d6f' => array(
          'module' => 'boxes',
          'delta' => 'box-66c05d6f',
          'region' => 'sidebar_second',
          'weight' => '0',
        ),
        'views-related_content-block' => array(
          'module' => 'views',
          'delta' => 'related_content-block',
          'region' => 'sidebar_second',
          'weight' => '1',
        ),
        'boxes-box-7fa6e22c' => array(
          'module' => 'boxes',
          'delta' => 'box-7fa6e22c',
          'region' => 'sidebar_second',
          'weight' => '2',
        ),
        'boxes-box-1104adce' => array(
          'module' => 'boxes',
          'delta' => 'box-1104adce',
          'region' => 'sidebar_second',
          'weight' => '3',
        ),
        'boxes-box-6c13820e' => array(
          'module' => 'boxes',
          'delta' => 'box-6c13820e',
          'region' => 'content_top',
          'weight' => '0',
        ),
        'boxes-action_header_image' => array(
          'module' => 'boxes',
          'delta' => 'action_header_image',
          'region' => 'content_top',
          'weight' => '1',
        ),
        'boxes-action_topic_and_share' => array(
          'module' => 'boxes',
          'delta' => 'action_topic_and_share',
          'region' => 'content_top',
          'weight' => '2',
        ),
        'takepart_custom-page_title_h1' => array(
          'module' => 'takepart_custom',
          'delta' => 'page_title_h1',
          'region' => 'content_top',
          'weight' => '3',
        ),
        'boxes-box-4eb62add' => array(
          'module' => 'boxes',
          'delta' => 'box-4eb62add',
          'region' => 'content_bottom',
          'weight' => '0',
        ),
        'views-content_updates-block' => array(
          'module' => 'views',
          'delta' => 'content_updates-block',
          'region' => 'content_bottom',
          'weight' => '1',
        ),
        'comment_block_simple-comment_block' => array(
          'module' => 'comment_block_simple',
          'delta' => 'comment_block',
          'region' => 'content_bottom',
          'weight' => '2',
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'multipage-campaign',
    ),
    'title' => array(
      'title_off' => 1,
      'title_override' => '',
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
