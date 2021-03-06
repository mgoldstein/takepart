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
  $context->tag = 'TP4';
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
        'boxes-ga_ros_interstitial' => array(
          'module' => 'boxes',
          'delta' => 'ga_ros_interstitial',
          'region' => 'footer',
          'weight' => '-9',
        ),
        'boxes-mod_tracking' => array(
          'module' => 'boxes',
          'delta' => 'mod_tracking',
          'region' => 'footer',
          'weight' => '-8',
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
        'bean-takepart-video-media-block' => array(
          'module' => 'bean',
          'delta' => 'takepart-video-media-block',
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
  t('TP4');
  t('homepage redesign');
  $export['homepage'] = $context;

  return $export;
}
