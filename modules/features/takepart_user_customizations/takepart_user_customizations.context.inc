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
    'breadcrumb_current_page' => array(
      'breadcrumb_show_current_page' => 0,
      'breadcrumb_show_current_page_title' => '',
      'breadcrumb_show_current_page_only' => 0,
      'empty_all_breadcrumbs' => 1,
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Breadcrumbs');
  $export['user_registration_breadcrumbs'] = $context;

  return $export;
}
