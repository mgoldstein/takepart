<?php
/**
 * @file
 * takepart_blog.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function takepart_blog_context_default_contexts() {
  $export = array();

  $context = new stdClass();
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
        'views-blogs-block_3' => array(
          'module' => 'views',
          'delta' => 'blogs-block_3',
          'region' => 'content_top',
          'weight' => 1,
        ),
        'takepart_custom-page_title_h1' => array(
          'module' => 'takepart_custom',
          'delta' => 'page_title_h1',
          'region' => 'content_top',
          'weight' => 2,
        ),
        'boxes-box-1dae03d3' => array(
          'module' => 'boxes',
          'delta' => 'box-1dae03d3',
          'region' => 'content_top',
          'weight' => 3,
        ),
        'boxes-box-4eb62add' => array(
          'module' => 'boxes',
          'delta' => 'box-4eb62add',
          'region' => 'content_bottom',
          'weight' => 1,
        ),
        'boxes-box-34ee1b08' => array(
          'module' => 'boxes',
          'delta' => 'box-34ee1b08',
          'region' => 'content_bottom',
          'weight' => 2,
        ),
        'comment_block_simple-comment_block' => array(
          'module' => 'comment_block_simple',
          'delta' => 'comment_block',
          'region' => 'content_bottom',
          'weight' => 3,
        ),
        'boxes-box-66c05d6f' => array(
          'module' => 'boxes',
          'delta' => 'box-66c05d6f',
          'region' => 'sidebar_second',
          'weight' => 0,
        ),
        'boxes-box-bedd1fbb' => array(
          'module' => 'boxes',
          'delta' => 'box-bedd1fbb',
          'region' => 'sidebar_second',
          'weight' => 1,
        ),
        'newsletter_campaign-10' => array(
          'module' => 'newsletter_campaign',
          'delta' => '10',
          'region' => 'sidebar_second',
          'weight' => 2,
        ),
        'views-related_content-block' => array(
          'module' => 'views',
          'delta' => 'related_content-block',
          'region' => 'sidebar_second',
          'weight' => 3,
        ),
        'boxes-box-7fa6e22c' => array(
          'module' => 'boxes',
          'delta' => 'box-7fa6e22c',
          'region' => 'sidebar_second',
          'weight' => 4,
        ),
        'views-related_actions-block' => array(
          'module' => 'views',
          'delta' => 'related_actions-block',
          'region' => 'sidebar_second',
          'weight' => 5,
        ),
        'boxes-box-1104adce' => array(
          'module' => 'boxes',
          'delta' => 'box-1104adce',
          'region' => 'sidebar_second',
          'weight' => 6,
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
