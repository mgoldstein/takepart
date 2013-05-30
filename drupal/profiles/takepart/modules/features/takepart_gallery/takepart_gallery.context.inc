<?php
/**
 * @file
 * takepart_gallery.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function takepart_gallery_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blocks_photo_gallery';
  $context->description = 'Photo Gallery Blocks';
  $context->tag = 'Blocks: Content Type';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'openpublish_photo_gallery' => 'openpublish_photo_gallery',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-box-944fcfe9' => array(
          'module' => 'boxes',
          'delta' => 'box-944fcfe9',
          'region' => 'full_width_top',
          'weight' => '0',
        ),
        'boxes-box-66c05d6f' => array(
          'module' => 'boxes',
          'delta' => 'box-66c05d6f',
          'region' => 'sidebar_second',
          'weight' => '0',
        ),
        'newsletter_campaign-10' => array(
          'module' => 'newsletter_campaign',
          'delta' => '10',
          'region' => 'sidebar_second',
          'weight' => '1',
        ),
        'boxes-box-7fa6e22c' => array(
          'module' => 'boxes',
          'delta' => 'box-7fa6e22c',
          'region' => 'sidebar_second',
          'weight' => '2',
        ),
        'views-related_content-block' => array(
          'module' => 'views',
          'delta' => 'related_content-block',
          'region' => 'sidebar_second',
          'weight' => '3',
        ),
        'boxes-box-1104adce' => array(
          'module' => 'boxes',
          'delta' => 'box-1104adce',
          'region' => 'sidebar_second',
          'weight' => '4',
        ),
        'boxes-box-6c13820e' => array(
          'module' => 'boxes',
          'delta' => 'box-6c13820e',
          'region' => 'content_top',
          'weight' => '0',
        ),
        'boxes-box-bb0b625d' => array(
          'module' => 'boxes',
          'delta' => 'box-bb0b625d',
          'region' => 'content_top',
          'weight' => '1',
        ),
        'takepart_custom-page_title_h1' => array(
          'module' => 'takepart_custom',
          'delta' => 'page_title_h1',
          'region' => 'content_top',
          'weight' => '2',
        ),
        'boxes-box-7fdc48e2' => array(
          'module' => 'boxes',
          'delta' => 'box-7fdc48e2',
          'region' => 'content_top',
          'weight' => '3',
        ),
        'boxes-box-e15d1292' => array(
          'module' => 'boxes',
          'delta' => 'box-e15d1292',
          'region' => 'content_top',
          'weight' => '4',
        ),
        'takepart_addthis-addthis_full' => array(
          'module' => 'takepart_addthis',
          'delta' => 'addthis_full',
          'region' => 'content_top',
          'weight' => '5',
        ),
        'boxes-box-4eb62add' => array(
          'module' => 'boxes',
          'delta' => 'box-4eb62add',
          'region' => 'content_bottom',
          'weight' => '0',
        ),
        'boxes-box-34ee1b08' => array(
          'module' => 'boxes',
          'delta' => 'box-34ee1b08',
          'region' => 'content_bottom',
          'weight' => '1',
        ),
        'boxes-box-7d1ce087' => array(
          'module' => 'boxes',
          'delta' => 'box-7d1ce087',
          'region' => 'content_bottom',
          'weight' => '2',
        ),
        'comment_block_simple-comment_block' => array(
          'module' => 'comment_block_simple',
          'delta' => 'comment_block',
          'region' => 'content_bottom',
          'weight' => '3',
        ),
      ),
    ),
    'title' => array(
      'title_off' => 1,
      'title_override' => '',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks: Content Type');
  t('Photo Gallery Blocks');
  $export['blocks_photo_gallery'] = $context;

  return $export;
}
