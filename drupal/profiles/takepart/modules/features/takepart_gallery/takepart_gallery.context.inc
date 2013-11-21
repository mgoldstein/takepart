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
        'boxes-box-66c05d6f' => array(
          'module' => 'boxes',
          'delta' => 'box-66c05d6f',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'newsletter_campaign-48' => array(
          'module' => 'newsletter_campaign',
          'delta' => '48',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'bean--of-the-day' => array(
          'module' => 'bean',
          'delta' => '-of-the-day',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'boxes-box-1104adce' => array(
          'module' => 'boxes',
          'delta' => 'box-1104adce',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'boxes-box-944fcfe9' => array(
          'module' => 'boxes',
          'delta' => 'box-944fcfe9',
          'region' => 'full_width_top',
          'weight' => '0',
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
