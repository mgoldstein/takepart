<?php
/**
 * @file
 * takepart_video.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function takepart_video_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blocks_video';
  $context->description = 'Video Blocks';
  $context->tag = 'Blocks: Content Type';
  $context->conditions = array(
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
        'boxes-box-bb0b625d' => array(
          'module' => 'boxes',
          'delta' => 'box-bb0b625d',
          'region' => 'content_top',
          'weight' => 0,
        ),
        'views-video-block_8' => array(
          'module' => 'views',
          'delta' => 'video-block_8',
          'region' => 'content_bottom',
          'weight' => 0,
        ),
        'boxes-box-208c3905' => array(
          'module' => 'boxes',
          'delta' => 'box-208c3905',
          'region' => 'content_bottom',
          'weight' => 1,
        ),
        'views-video-block' => array(
          'module' => 'views',
          'delta' => 'video-block',
          'region' => 'sidebar_second',
          'weight' => 2,
        ),
        'views-related_actions-block' => array(
          'module' => 'views',
          'delta' => 'related_actions-block',
          'region' => 'sidebar_second',
          'weight' => 3,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks: Content Type');
  t('Video Blocks');
  $export['blocks_video'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blocks_video_series';
  $context->description = 'Default Context for the video series taxonomy term';
  $context->tag = 'Context Field: Default';
  $context->conditions = array(
    'context_field' => array(
      'values' => array(
        'context_field' => 'context_field',
        1 => 1,
        2 => 2,
      ),
      'options' => array(
        'context_field_category' => '',
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
        'views-video-block_3' => array(
          'module' => 'views',
          'delta' => 'video-block_3',
          'region' => 'content',
          'weight' => 0,
        ),
        'views-video-block_6' => array(
          'module' => 'views',
          'delta' => 'video-block_6',
          'region' => 'content',
          'weight' => 1,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context Field: Default');
  t('Default Context for the video series taxonomy term');
  $export['blocks_video_series'] = $context;

  return $export;
}
