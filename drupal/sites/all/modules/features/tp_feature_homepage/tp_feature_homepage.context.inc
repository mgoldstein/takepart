<?php
/**
 * @file
 * tp_feature_homepage.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function tp_feature_homepage_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'homepage';
  $context->description = 'homepage redesign';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-latest_headlines-block' => array(
          'module' => 'views',
          'delta' => 'latest_headlines-block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'boxes-box-3981ef30' => array(
          'module' => 'boxes',
          'delta' => 'box-3981ef30',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'newsletter_campaign-48' => array(
          'module' => 'newsletter_campaign',
          'delta' => '48',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'panels_mini-photo_galleries' => array(
          'module' => 'panels_mini',
          'delta' => 'photo_galleries',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'views-homepage_columns-block' => array(
          'module' => 'views',
          'delta' => 'homepage_columns-block',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('homepage redesign');
  $export['homepage'] = $context;

  return $export;
}
