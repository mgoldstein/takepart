<?php
/**
 * @file
 * takepart_campaign.context.inc
 */

/**
 * Implementation of hook_context_default_contexts().
 */
function takepart_campaign_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'related_campaign_curated';
  $context->description = '';
  $context->tag = 'Blocks: Related';
  $context->conditions = array(
    'field_bool' => array(
      'values' => array(
        'field_suggest_campaigns' => 'field_suggest_campaigns',
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
        'views-related_campaigns-block' => array(
          'module' => 'views',
          'delta' => 'related_campaigns-block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks: Related');
  $export['related_campaign_curated'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'related_campaign_suggested';
  $context->description = '';
  $context->tag = 'Blocks: Related';
  $context->conditions = array(
    'field_bool' => array(
      'values' => array(
        'field_suggest_campaigns' => 'field_suggest_campaigns',
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
        'views-related_campaigns-block_1' => array(
          'module' => 'views',
          'delta' => 'related_campaigns-block_1',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks: Related');
  $export['related_campaign_suggested'] = $context;

  return $export;
}
