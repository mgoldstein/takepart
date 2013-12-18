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

  $context = new stdClass();
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
        'boxes-box-6c13820e' => array(
          'module' => 'boxes',
          'delta' => 'box-6c13820e',
          'region' => 'help',
          'weight' => 0,
        ),
        'boxes-box-bb0b625d' => array(
          'module' => 'boxes',
          'delta' => 'box-bb0b625d',
          'region' => 'content_top',
          'weight' => 0,
        ),
        'boxes-box-4eb62add' => array(
          'module' => 'boxes',
          'delta' => 'box-4eb62add',
          'region' => 'content_bottom',
          'weight' => 1,
        ),
        'views-video-block_8' => array(
          'module' => 'views',
          'delta' => 'video-block_8',
          'region' => 'content_bottom',
          'weight' => 2,
        ),
        'views-video-block' => array(
          'module' => 'views',
          'delta' => 'video-block',
          'region' => 'content_bottom',
          'weight' => 4,
        ),
        'comment_block_simple-comment_block' => array(
          'module' => 'comment_block_simple',
          'delta' => 'comment_block',
          'region' => 'content_bottom',
          'weight' => 5,
        ),
        'boxes-box-66c05d6f' => array(
          'module' => 'boxes',
          'delta' => 'box-66c05d6f',
          'region' => 'sidebar_second',
          'weight' => 0,
        ),
        'boxes-box-7fa6e22c' => array(
          'module' => 'boxes',
          'delta' => 'box-7fa6e22c',
          'region' => 'sidebar_second',
          'weight' => 1,
        ),
        'views-photo_galleries-block' => array(
          'module' => 'views',
          'delta' => 'photo_galleries-block',
          'region' => 'sidebar_second',
          'weight' => 2,
        ),
        'views-related_actions-block' => array(
          'module' => 'views',
          'delta' => 'related_actions-block',
          'region' => 'sidebar_second',
          'weight' => 3,
        ),
        'boxes-box-1104adce' => array(
          'module' => 'boxes',
          'delta' => 'box-1104adce',
          'region' => 'sidebar_second',
          'weight' => 4,
        ),
        'views-photo_galleries-block_2' => array(
          'module' => 'views',
          'delta' => 'photo_galleries-block_2',
          'region' => 'sidebar_second',
          'weight' => 5,
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

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blocks_video_series';
  $context->description = 'Default Context for the video series taxonomy term';
  $context->tag = 'Context Field: Default';
  $context->conditions = array(
    'context_field' => array(
      'values' => array(
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
        'views-video-block_3' => array(
          'module' => 'views',
          'delta' => 'video-block_3',
          'region' => 'content',
          'weight' => '0',
        ),
        'views-video-block_6' => array(
          'module' => 'views',
          'delta' => 'video-block_6',
          'region' => 'content',
          'weight' => '1',
        ),
        'boxes-box-66c05d6f' => array(
          'module' => 'boxes',
          'delta' => 'box-66c05d6f',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'boxes-box-e9e8814f' => array(
          'module' => 'boxes',
          'delta' => 'box-e9e8814f',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'boxes-box-1104adce' => array(
          'module' => 'boxes',
          'delta' => 'box-1104adce',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'takepart_custom-page_title_h1' => array(
          'module' => 'takepart_custom',
          'delta' => 'page_title_h1',
          'region' => 'content_top',
          'weight' => '0',
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
