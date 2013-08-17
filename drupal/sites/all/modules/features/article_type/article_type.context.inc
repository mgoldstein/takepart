<?php
/**
 * @file
 * article_type.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function article_type_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'article_v2_blocks';
  $context->description = 'Blocks for the Article content type';
  $context->tag = 'Blocks: Article';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'article' => 'article',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-ga_articles_top_right' => array(
          'module' => 'boxes',
          'delta' => 'ga_articles_top_right',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'newsletter_campaign-48' => array(
          'module' => 'newsletter_campaign',
          'delta' => '48',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'boxes-ga_articles_bottom_right' => array(
          'module' => 'boxes',
          'delta' => 'ga_articles_bottom_right',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'node-type-article',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks for the Article content type');
  t('Blocks: Article');
  $export['article_v2_blocks'] = $context;

  return $export;
}