<?php
/**
 * @file
 * tpf_display_views.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function tpf_display_views_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'bg_skin_ad';
  $context->description = 'Background skin takeover ad';
  $context->tag = 'Ads';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'openpublish_article' => 'openpublish_article',
        'openpublish_photo_gallery' => 'openpublish_photo_gallery',
        'openpublish_video' => 'openpublish_video',
        'profile' => 'profile',
        'section_front' => 'section_front',
        'takepart_group' => 'takepart_group',
        'takepart_page' => 'takepart_page',
        'venue' => 'venue',
        'video' => 'video',
        'video_playlist' => 'video_playlist',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-bg_skin_sponsor' => array(
          'module' => 'boxes',
          'delta' => 'bg_skin_sponsor',
          'region' => 'content_bottom',
          'weight' => '0',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Ads');
  t('Background skin takeover ad');
  $export['bg_skin_ad'] = $context;

  return $export;
}
