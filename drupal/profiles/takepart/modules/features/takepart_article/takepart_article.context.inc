<?php
/**
 * @file
 * takepart_article.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function takepart_article_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blocks_article';
  $context->description = 'Article Blocks';
  $context->tag = 'Blocks: Content Type';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'openpublish_article' => 'openpublish_article',
      ),
      'options' => array(
        'node_form' => '1',
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
        'boxes-box-9753089b' => array(
          'module' => 'boxes',
          'delta' => 'box-9753089b',
          'region' => 'content_top',
          'weight' => 2,
        ),
        'boxes-box-4eb62add' => array(
          'module' => 'boxes',
          'delta' => 'box-4eb62add',
          'region' => 'content_bottom',
          'weight' => 1,
        ),
        'comment_block_simple-comment_block' => array(
          'module' => 'comment_block_simple',
          'delta' => 'comment_block',
          'region' => 'content_bottom',
          'weight' => 2,
        ),
        'boxes-box-66c05d6f' => array(
          'module' => 'boxes',
          'delta' => 'box-66c05d6f',
          'region' => 'sidebar_second',
          'weight' => 0,
        ),
        'views-related_actions-block' => array(
          'module' => 'views',
          'delta' => 'related_actions-block',
          'region' => 'sidebar_second',
          'weight' => 1,
        ),
        'views-related_content-block' => array(
          'module' => 'views',
          'delta' => 'related_content-block',
          'region' => 'sidebar_second',
          'weight' => 2,
        ),
        'boxes-box-1104adce' => array(
          'module' => 'boxes',
          'delta' => 'box-1104adce',
          'region' => 'sidebar_second',
          'weight' => 3,
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
  t('Article Blocks');
  t('Blocks: Content Type');
  $export['blocks_article'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'series_default_context';
  $context->description = 'Default Context for series';
  $context->tag = 'Context Field Default';
  $context->conditions = array(
    'context_field' => array(
      'values' => array(
        'context_field' => 'context_field',
        1 => 1,
        2 => 2,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'takepart_custom-page_title_h1' => array(
          'module' => 'takepart_custom',
          'delta' => 'page_title_h1',
          'region' => 'content_top',
          'weight' => 0,
        ),
        'views-taxonomy_search_list-block_2' => array(
          'module' => 'views',
          'delta' => 'taxonomy_search_list-block_2',
          'region' => 'content_bottom',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context Field Default');
  t('Default Context for series');
  $export['series_default_context'] = $context;

  return $export;
}
