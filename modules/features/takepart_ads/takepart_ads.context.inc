<?php
/**
 * @file
 * takepart_ads.context.inc
 */

/**
 * Implementation of hook_context_default_contexts().
 */
function takepart_ads_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ad_exclude_campaign';
  $context->description = 'Context used by general_ad to exclude ads from campaigns';
  $context->tag = 'Ads';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'takepart_campaign' => 'takepart_campaign',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Ads');
  t('Context used by general_ad to exclude ads from campaigns');
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
        'boxes-box-f130b806' => array(
          'module' => 'boxes',
          'delta' => 'box-f130b806',
          'region' => 'sidebar_second',
          'weight' => '100000000',
        ),
        'boxes-box-3981ef30' => array(
          'module' => 'boxes',
          'delta' => 'box-3981ef30',
          'region' => 'sidebar_second',
          'weight' => '-100000000',
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
