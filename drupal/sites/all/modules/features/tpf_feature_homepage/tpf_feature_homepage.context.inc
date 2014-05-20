<?php
/**
 * @file
 * tpf_feature_homepage.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function tpf_feature_homepage_context_default_contexts() {
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
        'boxes-ga_homepage_header' => array(
          'module' => 'boxes',
          'delta' => 'ga_homepage_header',
          'region' => 'header',
          'weight' => '-100',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
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
        'views-takeaction_homepage-block' => array(
          'module' => 'views',
          'delta' => 'takeaction_homepage-block',
          'region' => 'skinny',
          'weight' => '-9',
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
        'bean-tpl-live-long' => array(
          'module' => 'bean',
          'delta' => 'tpl-live-long',
          'region' => 'sidebar',
          'weight' => '-8',
        ),
        'newsletter_campaign-51' => array(
          'module' => 'newsletter_campaign',
          'delta' => '51',
          'region' => 'sidebar',
          'weight' => '-7',
        ),
        'views-photo_galleries_promo-block' => array(
          'module' => 'views',
          'delta' => 'photo_galleries_promo-block',
          'region' => 'sidebar',
          'weight' => '-6',
        ),
        'tp4_support-tp4_graveyard' => array(
          'module' => 'tp4_support',
          'delta' => 'tp4_graveyard',
          'region' => 'suffix',
          'weight' => '-10',
        ),
        'boxes-ga_hp_1x1_background' => array(
          'module' => 'boxes',
          'delta' => 'ga_hp_1x1_background',
          'region' => 'suffix',
          'weight' => '-8',
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
