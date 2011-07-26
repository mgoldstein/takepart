<?php
/**
 * @file
 * takepart_custom.context.inc
 */

/**
 * Implementation of hook_context_default_contexts().
 */
function takepart_custom_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'free_tags_default_context';
  $context->description = 'Default Context for free_tags';
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
        'views-taxonomy_search_list-block_1' => array(
          'module' => 'views',
          'delta' => 'taxonomy_search_list-block_1',
          'region' => 'content',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context Field Default');
  t('Default Context for free_tags');
  $export['free_tags_default_context'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'related_content_curated';
  $context->description = '';
  $context->tag = 'Blocks: Related';
  $context->conditions = array(
    'field_bool' => array(
      'values' => array(
        'field_suggest_content' => 'field_suggest_content',
      ),
      'options' => array(
        'bool_field_value' => '0',
      ),
    ),
    'node' => array(
      'values' => array(
        'action' => 'action',
        'openpublish_article' => 'openpublish_article',
        'openpublish_blog_post' => 'openpublish_blog_post',
        'openpublish_photo_gallery' => 'openpublish_photo_gallery',
        'openpublish_video' => 'openpublish_video',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-related_content-block' => array(
          'module' => 'views',
          'delta' => 'related_content-block',
          'region' => 'sidebar_second',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks: Related');
  $export['related_content_curated'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'related_content_suggested';
  $context->description = '';
  $context->tag = 'Blocks: Related';
  $context->conditions = array(
    'field_bool' => array(
      'values' => array(
        'field_suggest_content' => 'field_suggest_content',
      ),
      'options' => array(
        'bool_field_value' => '1',
      ),
    ),
    'node' => array(
      'values' => array(
        'action' => 'action',
        'openpublish_article' => 'openpublish_article',
        'openpublish_blog_post' => 'openpublish_blog_post',
        'openpublish_photo_gallery' => 'openpublish_photo_gallery',
        'openpublish_video' => 'openpublish_video',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-related_content-block_1' => array(
          'module' => 'views',
          'delta' => 'related_content-block_1',
          'region' => 'sidebar_second',
          'weight' => 2,
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks: Related');
  $export['related_content_suggested'] = $context;

  return $export;
}
