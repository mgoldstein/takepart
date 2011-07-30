<?php
/**
 * @file
 * takepart_blog.context.inc
 */

/**
 * Implementation of hook_context_default_contexts().
 */
function takepart_blog_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blocks_blog_posts';
  $context->description = 'Blog Post Blocks';
  $context->tag = 'Blocks: Content Type';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'openpublish_blog_post' => 'openpublish_blog_post',
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
        'boxes-box-1dae03d3' => array(
          'module' => 'boxes',
          'delta' => 'box-1dae03d3',
          'region' => 'content_top',
          'weight' => 2,
        ),
        'addthis-addthis' => array(
          'module' => 'addthis',
          'delta' => 'addthis',
          'region' => 'sidebar_first',
          'weight' => 0,
        ),
        'boxes-box-4eb62add' => array(
          'module' => 'boxes',
          'delta' => 'box-4eb62add',
          'region' => 'content_bottom',
          'weight' => 0,
        ),
        'comment_block_simple-comment_block' => array(
          'module' => 'comment_block_simple',
          'delta' => 'comment_block',
          'region' => 'content_bottom',
          'weight' => 1,
        ),
        'views-related_campaigns-block_1' => array(
          'module' => 'views',
          'delta' => 'related_campaigns-block_1',
          'region' => 'sidebar_second',
          'weight' => 4,
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
  t('Blog Post Blocks');
  $export['blocks_blog_posts'] = $context;

  return $export;
}
