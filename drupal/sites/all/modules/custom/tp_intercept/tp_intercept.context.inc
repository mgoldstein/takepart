<?php
/**
 * @file
 * tp_intercept.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function tp_intercept_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'tp_intercept';
  $context->description = '';
  $context->tag = 'Global';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~<front>' => '~<front>',
        '~interstitials' => '~interstitials',
        '~interstitials/*' => '~interstitials/*',
      ),
    ),
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'tp_intercept' => array(
      'enable_tp_intercept' => '1',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Global');
  $export['tp_intercept'] = $context;

  return $export;
}
