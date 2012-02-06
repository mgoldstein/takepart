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

  $context = new stdClass;
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
        'boxes-box-bb0b625d' => array(
          'module' => 'boxes',
          'delta' => 'box-bb0b625d',
          'region' => 'highlighted',
          'weight' => '0',
        ),
        'takepart_custom-page_title_h1' => array(
          'module' => 'takepart_custom',
          'delta' => 'page_title_h1',
          'region' => 'highlighted',
          'weight' => '1',
        ),
        'boxes-box-7fdc48e2' => array(
          'module' => 'boxes',
          'delta' => 'box-7fdc48e2',
          'region' => 'highlighted',
          'weight' => '2',
        ),
        'takepart_custom-slideshow_controls' => array(
          'module' => 'takepart_custom',
          'delta' => 'slideshow_controls',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'takepart_addthis-addthis_rightrail' => array(
          'module' => 'takepart_addthis',
          'delta' => 'addthis_rightrail',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'boxes-box-66c05d6f' => array(
          'module' => 'boxes',
          'delta' => 'box-66c05d6f',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'views-related_content-block' => array(
          'module' => 'views',
          'delta' => 'related_content-block',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'views-related_actions-block' => array(
          'module' => 'views',
          'delta' => 'related_actions-block',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
        'boxes-box-1104adce' => array(
          'module' => 'boxes',
          'delta' => 'box-1104adce',
          'region' => 'sidebar_second',
          'weight' => '-5',
        ),
        'boxes-box-7d1ce087' => array(
          'module' => 'boxes',
          'delta' => 'box-7d1ce087',
          'region' => 'content_bottom',
          'weight' => '0',
        ),
        'comment_block_simple-comment_block' => array(
          'module' => 'comment_block_simple',
          'delta' => 'comment_block',
          'region' => 'content_bottom',
          'weight' => '1',
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
  t('Photo Gallery Blocks');
  $export['blocks_photo_gallery'] = $context;

  return $export;
}
