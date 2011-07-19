<?php
/**
 * @file
 * takepart_omniture.context.inc
 */

/**
 * Implementation of hook_context_default_contexts().
 */
function takepart_omniture_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'omniture_site_wide';
  $context->description = 'Omniture Settings for the every page';
  $context->tag = 'Omniture';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'context_omniture_reaction' => array(
      'variables' => 's.channel = takepart:[current-page:url-arg:0]:[current-page:url-arg:-1]
s.eVar04 = [node:content-type:machine-name]
',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Omniture');
  t('Omniture Settings for the every page');
  $export['omniture_site_wide'] = $context;

  return $export;
}
