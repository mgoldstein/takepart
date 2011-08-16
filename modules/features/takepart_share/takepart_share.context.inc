<?php
/**
 * @file
 * takepart_share.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function takepart_share_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'addthis_blocks';
  $context->description = 'Embeds AddThis blocks on shareable pages.';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'action' => 'action',
        'openpublish_article' => 'openpublish_article',
        'openpublish_blog_post' => 'openpublish_blog_post',
        'openpublish_video' => 'openpublish_video',
        'takepart_campaign' => 'takepart_campaign',
        'takepart_group' => 'takepart_group',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'takepart_addthis-addthis_footer' => array(
          'module' => 'takepart_addthis',
          'delta' => 'addthis_footer',
          'region' => 'content_bottom',
          'weight' => 0,
        ),
       'takepart_addthis-addthis_simple' => array(
        'module' => 'takepart_addthis',
        'delta' => 'addthis_simple',
        'region' => 'header',
        'weight' => 0,
        ),

      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Embeds AddThis blocks on shareable pages.');
  $export['addthis_blocks'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'addthis_leftpanel_blocks';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'openpublish_article' => 'openpublish_article',
        'openpublish_blog_post' => 'openpublish_blog_post',
        'takepart_group' => 'takepart_group',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'takepart_addthis-addthis_full' => array(
          'module' => 'takepart_addthis',
          'delta' => 'addthis_full',
          'region' => 'sidebar_first',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['addthis_leftpanel_blocks'] = $context;

  return $export;
}
