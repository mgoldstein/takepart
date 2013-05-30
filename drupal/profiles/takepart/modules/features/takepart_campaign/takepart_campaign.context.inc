<?php
/**
 * @file
 * takepart_campaign.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function takepart_campaign_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'multi_page_campaign_default_context';
  $context->description = 'Default Context for Multi-Page Campaigns';
  $context->tag = 'Multipage Campaign';
  $context->conditions = array(
    'context_field' => array(
      'values' => array(
        1 => 1,
        2 => 2,
      ),
      'options' => array(
        'context_field_category' => '',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'context_related_menu-context_related_menu' => array(
          'module' => 'context_related_menu',
          'delta' => 'context_related_menu',
          'region' => 'highlighted',
          'weight' => '-10',
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'campaign-page',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Default Context for Multi-Page Campaigns');
  t('Multipage Campaign');
  $export['multi_page_campaign_default_context'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'takepart_campaign_default';
  $context->description = 'TakePart Campaign Default';
  $context->tag = 'Context Field Default';
  $context->conditions = array(
    'context_field' => array(
      'values' => array(
        1 => 1,
        2 => 2,
      ),
      'options' => array(
        'context_field_category' => '',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'takepart_custom-page_title_h1' => array(
          'module' => 'takepart_custom',
          'delta' => 'page_title_h1',
          'region' => 'highlighted',
          'weight' => '-10',
        ),
        'boxes-box-2988d8fb' => array(
          'module' => 'boxes',
          'delta' => 'box-2988d8fb',
          'region' => 'highlighted',
          'weight' => '-7',
        ),
        'boxes-box-9ececd73' => array(
          'module' => 'boxes',
          'delta' => 'box-9ececd73',
          'region' => 'content',
          'weight' => '0',
        ),
        'boxes-box-1306f48f' => array(
          'module' => 'boxes',
          'delta' => 'box-1306f48f',
          'region' => 'content',
          'weight' => '1',
        ),
        'boxes-box-8a3f206b' => array(
          'module' => 'boxes',
          'delta' => 'box-8a3f206b',
          'region' => 'content',
          'weight' => '2',
        ),
        'boxes-box-907caa9b' => array(
          'module' => 'boxes',
          'delta' => 'box-907caa9b',
          'region' => 'content',
          'weight' => '3',
        ),
        'boxes-box-22165b1a' => array(
          'module' => 'boxes',
          'delta' => 'box-22165b1a',
          'region' => 'content',
          'weight' => '4',
        ),
        'boxes-box-153f08e4' => array(
          'module' => 'boxes',
          'delta' => 'box-153f08e4',
          'region' => 'content',
          'weight' => '5',
        ),
        'boxes-box-97545db1' => array(
          'module' => 'boxes',
          'delta' => 'box-97545db1',
          'region' => 'content',
          'weight' => '6',
        ),
        'boxes-box-81a645d6' => array(
          'module' => 'boxes',
          'delta' => 'box-81a645d6',
          'region' => 'sidebar_first',
          'weight' => '0',
        ),
        'boxes-box-95b55e7' => array(
          'module' => 'boxes',
          'delta' => 'box-95b55e7',
          'region' => 'sidebar_second',
          'weight' => '0',
        ),
        'boxes-box-5cd7d5ce' => array(
          'module' => 'boxes',
          'delta' => 'box-5cd7d5ce',
          'region' => 'sidebar_second',
          'weight' => '1',
        ),
        'boxes-box-4abd00a3' => array(
          'module' => 'boxes',
          'delta' => 'box-4abd00a3',
          'region' => 'sidebar_second',
          'weight' => '2',
        ),
        'boxes-box-33756e58' => array(
          'module' => 'boxes',
          'delta' => 'box-33756e58',
          'region' => 'sidebar_second',
          'weight' => '3',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context Field Default');
  t('TakePart Campaign Default');
  $export['takepart_campaign_default'] = $context;

  return $export;
}
