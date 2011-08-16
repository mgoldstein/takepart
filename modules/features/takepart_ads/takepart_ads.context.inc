<?php
/**
 * @file
 * takepart_ads.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function takepart_ads_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ad_exclude_campaign';
  $context->description = 'Context used by general_ad to exclude ads from pages/sections';
  $context->tag = 'Ads';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'action' => 'action',
        'openpublish_article' => 'openpublish_article',
        'openpublish_blog_post' => 'openpublish_blog_post',
        'openpublish_photo_gallery' => 'openpublish_photo_gallery',
        'openpublish_video' => 'openpublish_video',
        'takepart_campaign' => 'takepart_campaign',
        'takepart_group' => 'takepart_group',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'video' => 'video',
        'photos' => 'photos',
        'afinefrenzy' => 'afinefrenzy',
        'thepeoplespeak' => 'thepeoplespeak',
        'wavesofaction' => 'wavesofaction',
        'congowomen' => 'congowomen',
        'crisisinegypt' => 'crisisinegypt',
        'journeyofaction' => 'journeyofaction',
        'skollworldforum' => 'skollworldforum',
        'thejohnalexanderproject' => 'thejohnalexanderproject',
        'casinojack/followthemoney' => 'casinojack/followthemoney',
        'thecove/gotmercury' => 'thecove/gotmercury',
        'searchforcommonground' => 'searchforcommonground',
        'underourskin' => 'underourskin',
        'eradicatewaterborneillnesses' => 'eradicatewaterborneillnesses',
        'teachinggarden' => 'teachinggarden',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Ads');
  t('Context used by general_ad to exclude ads from pages/sections');
  $export['ad_exclude_campaign'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'general_ad';
  $context->description = 'Place Basic add on most Pages';
  $context->tag = 'Ads';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        '~ad_exclude_campaign' => '~ad_exclude_campaign',
      ),
    ),
    'path' => array(
      'values' => array(
        '~user*' => '~user*',
        '~<front>' => '~<front>',
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
          'weight' => 1,
        ),
        'boxes-box-1104adce' => array(
          'module' => 'boxes',
          'delta' => 'box-1104adce',
          'region' => 'sidebar_second',
          'weight' => 4,
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Ads');
  t('Place Basic add on most Pages');
  $export['general_ad'] = $context;

  return $export;
}
