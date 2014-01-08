<?php
/**
 * @file
 * takepart_search.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function takepart_search_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'block_search';
  $context->description = 'Search';
  $context->tag = 'Block: Search';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'search*' => 'search*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'facetapi-VJwGNQ46y4iuJeqIzALpDmDGkirFA0o1' => array(
          'module' => 'facetapi',
          'delta' => 'VJwGNQ46y4iuJeqIzALpDmDGkirFA0o1',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'facetapi-p6j6uydvqzGOZ3pcNbwjsR5fzChT15JY' => array(
          'module' => 'facetapi',
          'delta' => 'p6j6uydvqzGOZ3pcNbwjsR5fzChT15JY',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'facetapi-StCw4MzrvpsV2LTHu4LZiKV1hGHJpKsU' => array(
          'module' => 'facetapi',
          'delta' => 'StCw4MzrvpsV2LTHu4LZiKV1hGHJpKsU',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Block: Search');
  t('Search');
  $export['block_search'] = $context;

  return $export;
}
