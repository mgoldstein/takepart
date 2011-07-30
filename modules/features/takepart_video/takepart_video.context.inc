<?php
/**
 * @file
 * takepart_video.context.inc
 */

/**
 * Implementation of hook_context_default_contexts().
 */
function takepart_video_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'related_video_curated';
  $context->description = 'Place of Releate Video Curated Block';
  $context->tag = 'Blocks: Related';
  $context->conditions = array(
    'field_bool' => array(
      'values' => array(
        'field_suggest_related' => 'field_suggest_related',
      ),
      'options' => array(
        'bool_field_value' => '0',
      ),
    ),
    'node' => array(
      'values' => array(
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
        'views-video-block_1' => array(
          'module' => 'views',
          'delta' => 'video-block_1',
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
  t('Place of Releate Video Curated Block');
  $export['related_video_curated'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'related_video_suggested';
  $context->description = '';
  $context->tag = 'Blocks: Related';
  $context->conditions = array(
    'field_bool' => array(
      'values' => array(
        'field_suggest_related' => 'field_suggest_related',
      ),
      'options' => array(
        'bool_field_value' => '1',
      ),
    ),
    'node' => array(
      'values' => array(
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
        'views-video-block' => array(
          'module' => 'views',
          'delta' => 'video-block',
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
  $export['related_video_suggested'] = $context;

  return $export;
}
