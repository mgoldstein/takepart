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
        'feature_article' => 'feature_article',
        'openpublish_article' => 'openpublish_article',
        'openpublish_photo_gallery' => 'openpublish_photo_gallery',
        'profile' => 'profile',
        'takepart_page' => 'takepart_page',
        'video' => 'video',
        'video_playlist' => 'video_playlist',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Ads');
  t('Background skin takeover ad');
  $export['bg_skin_ad'] = $context;

  return $export;
}
