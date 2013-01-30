<?php
/**
 * @file
 * takepart_omniture.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function takepart_omniture_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'omniture_all_content_types';
  $context->description = 'Omniture: All content types';
  $context->tag = 'Omniture';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'action' => 'action',
        'audio' => 'audio',
        'blog_front' => 'blog_front',
        'openpublish_article' => 'openpublish_article',
        'openpublish_blog_post' => 'openpublish_blog_post',
        'openpublish_photo' => 'openpublish_photo',
        'openpublish_photo_gallery' => 'openpublish_photo_gallery',
        'openpublish_video' => 'openpublish_video',
        'profile' => 'profile',
        'section_front' => 'section_front',
        'takepart_campaign' => 'takepart_campaign',
        'takepart_group' => 'takepart_group',
        'takepart_page' => 'takepart_page',
        'takepart_quick_study' => 'takepart_quick_study',
        'takepart_slide' => 'takepart_slide',
        'topic_front' => 'topic_front',
        'venue' => 'venue',
        'webform' => 'webform',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'omniture_reaction' => array(
      'variables' => 's.prop19 = [tp_omniture:date:{node:created:raw}]
s.eVar21 = [tp_omniture:value_or_empty:{node:field_display_tag}]
s.prop20 = [tp_omniture:value_or_empty:{node:field_display_tag}]
s.prop4 = [tp_omniture:value_or_empty:{node:content-type}]
s.eVar18 = [tp_omniture:str_decode:{node:title}]
s.prop17 = [tp_omniture:str_decode:{node:title}]
s.eVar17 = [tp_omniture:get_author:{node:nid}]
s.prop16 = [tp_omniture:get_author:{node:nid}]
s.prop6 = [node:nid]',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Omniture');
  t('Omniture: All content types');
  $export['omniture_all_content_types'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'omniture_blog';
  $context->description = 'Variables to set on blog pages.';
  $context->tag = 'Omniture';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'openpublish_blog_post' => 'openpublish_blog_post',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'omniture_reaction' => array(
      'variables' => 's.eVar19 = [tp_omniture:value_or_empty:{node:field-blogpost-blog:term:name}]
s.prop18 = [tp_omniture:value_or_empty:{node:field-blogpost-blog:term:name}]
s.prop3 = [current-page:url-arg:0]:[tp_omniture:date:{node:created:raw}]:[tp_omniture:str_decode:{node:title}]
s.prop2 = [current-page:url-arg:1]',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Omniture');
  t('Variables to set on blog pages.');
  $export['omniture_blog'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'omniture_registration';
  $context->description = 'Omniture registration page load variables';
  $context->tag = 'Omniture';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/19528' => 'node/19528',
      ),
    ),
  );
  $context->reactions = array(
    'omniture_reaction' => array(
      'variables' => 's.events = event23,event33,event21
s.eVar11 = Logged_In',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Omniture');
  t('Omniture registration page load variables');
  $export['omniture_registration'] = $context;

  $context = new stdClass();
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
'omniture_reaction' => array(
'variables' => 's.channel = [tp_omniture:lowercase:{current-page:url-arg:0}]
s.eVar11 = [f:bool:{current-user:uid}:Logged_In:Anonymous]
s.pageName = takepart:[current-page:url-arg:0]:[tp_omniture:str_decode:{current-page:title}]
s.prop1 = [tp_omniture:lowercase:{current-page:url-arg:0}]
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
