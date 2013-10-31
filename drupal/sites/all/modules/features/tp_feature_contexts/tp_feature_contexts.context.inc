<?php
/**
 * @file
 * tp_feature_contexts.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function tp_feature_contexts_context_default_contexts() {
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
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'tp4_support-tp4_footer' => array(
          'module' => 'tp4_support',
          'delta' => 'tp4_footer',
          'region' => 'footer',
          'weight' => '-10',
        ),
        'tp4_support-tp4_dont_miss' => array(
          'module' => 'tp4_support',
          'delta' => 'tp4_dont_miss',
          'region' => 'preface',
          'weight' => '-10',
        ),
        'views-homepage_columns-block' => array(
          'module' => 'views',
          'delta' => 'homepage_columns-block',
          'region' => 'skinny',
          'weight' => '-10',
        ),
        'views-latest_headlines-block' => array(
          'module' => 'views',
          'delta' => 'latest_headlines-block',
          'region' => 'sidebar',
          'weight' => '-10',
        ),
        'boxes-ga_homepage_top_right' => array(
          'module' => 'boxes',
          'delta' => 'ga_homepage_top_right',
          'region' => 'sidebar',
          'weight' => '-9',
        ),
        'newsletter_campaign-49' => array(
          'module' => 'newsletter_campaign',
          'delta' => '49',
          'region' => 'sidebar',
          'weight' => '-8',
        ),
        'views-photo_galleries_promo-block' => array(
          'module' => 'views',
          'delta' => 'photo_galleries_promo-block',
          'region' => 'sidebar',
          'weight' => '-7',
        ),
        'tp4_support-tp4_graveyard' => array(
          'module' => 'tp4_support',
          'delta' => 'tp4_graveyard',
          'region' => 'suffix',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('homepage redesign');
  $export['homepage'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'tp4_global';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'theme' => array(
      'values' => array(
        'tp4' => 'tp4',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'tp4_support-tp4_fat_header' => array(
          'module' => 'tp4_support',
          'delta' => 'tp4_fat_header',
          'region' => 'header',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['tp4_global'] = $context;

  return $export;
}
