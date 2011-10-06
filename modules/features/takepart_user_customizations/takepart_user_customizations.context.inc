<?php
/**
 * @file
 * takepart_user_customizations.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function takepart_user_customizations_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'user_registration_breadcrumbs';
  $context->description = '';
  $context->tag = 'Breadcrumbs';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'user' => 'user',
        'user/*' => 'user/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-user_not_a_member_join' => array(
          'module' => 'boxes',
          'delta' => 'user_not_a_member_join',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Breadcrumbs');
  $export['user_registration_breadcrumbs'] = $context;

  return $export;
}
