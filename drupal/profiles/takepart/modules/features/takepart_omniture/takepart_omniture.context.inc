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
      'variables' => 's.prop4 = [tp_omniture:value_or_empty:{node:content-type}]
s.prop6 = [node:nid]
s.prop16 = [tp_omniture:get_author:{node:nid}]
s.prop17 = [tp_omniture:str_decode:{node:title}]
s.prop18 = [tp_omniture:value_or_empty:{node:field_series}]
s.prop19 = [tp_omniture:date:{node:created:raw}]
s.prop20 = [tp_omniture:lowercase:{node:field_topic}]
s.prop43 = [tp_omniture:campaign_context:{node:nid}]',
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
  $context->name = 'omniture_article_v2';
  $context->description = 'Variables to set on second generation article pages.';
  $context->tag = 'Omniture';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'openpublish_article' => 'openpublish_article',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'omniture_reaction' => array(
      'variables' => 's.events = event6
s.prop4 = [tp_omniture:value_or_empty:{node:content-type}]
s.prop6 = [node:nid]
s.prop16 = [tp_omniture:value_or_empty:{node:field_author}]
s.prop17 = [tp_omniture:str_decode:{node:title}]
s.eVar17 = [tp_omniture:value_or_empty:{node:field_author}]
s.prop18 = [tp_omniture:value_or_empty:{node:field_series}]
s.eVar18 = [tp_omniture:str_decode:{node:title}]
s.eVar19 = [tp_omniture:value_or_empty:{node:field_series}]
s.prop19 = [tp_omniture:date:{node:created:raw}]
s.prop20 = [tp_omniture:value_or_empty:{node:field_topic}]
s.eVar21 = [tp_omniture:value_or_empty:{node:field_topic}]
s.prop43 = [tp_omniture:campaign_context:{node:nid}]
s.eVar43 = [tp_omniture:campaign_context:{node:nid}]',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Omniture');
  t('Variables to set on second generation article pages.');
  $export['omniture_article_v2'] = $context;

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
  $context->name = 'omniture_gallery';
  $context->description = 'Variables to set on gallery pages.';
  $context->tag = 'Omniture';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'openpublish_photo_gallery' => 'openpublish_photo_gallery',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'omniture_reaction' => array(
      'variables' => 's.prop14 = [tp_omniture:str_decode:{node:title}]
s.eVar14 = [tp_omniture:str_decode:{node:title}]
s.prop15 = [tp_omniture:get_first_photo_title:{node:nid}]
s.eVar15 = [tp_omniture:get_first_photo_title:{node:nid}]
s.prop16 = [tp_omniture:value_or_empty:{node:field_author}]
s.eVar17 = [tp_omniture:value_or_empty:{node:field_author}]
s.prop20 = [tp_omniture:lowercase:{node:field_topic}]
s.eVar21 = [tp_omniture:lowercase:{node:field_topic}]',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Omniture');
  t('Variables to set on gallery pages.');
  $export['omniture_gallery'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'omniture_homepage';
  $context->description = 'Homepage SiteCatalyst settings';
  $context->tag = 'Omniture';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'omniture_reaction' => array(
      'variables' => 's.channel = home
s.pageName = takepart:home:TakePart Home
s.prop1 = [tp_omniture:lowercase:{current-page:url-arg:0}]
s.prop2 = home
s.prop4 = home
s.prop7 =[current-user:uid]
s.eVar30 = takepart:home:TakePart Home',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Homepage SiteCatalyst settings');
  t('Omniture');
  $export['omniture_homepage'] = $context;

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

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'omniture_tab_landing_page';
  $context->description = 'Omniture parameters for the TAB Landing Page';
  $context->tag = 'Omniture';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/31701' => 'node/31701',
      ),
    ),
  );
  $context->reactions = array(
    'omniture_reaction' => array(
      'variables' => 's.prop66 = Action Landing Page
s.prop67 = takepart:[current-page:url-arg:0]:[tp_omniture:str_decode:{node:title}]',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Omniture');
  t('Omniture parameters for the TAB Landing Page');
  $export['omniture_tab_landing_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'omniture_tab_thank_you';
  $context->description = 'Omniture parameters for TAB Thank You page';
  $context->tag = 'Omniture';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/31703' => 'node/31703',
      ),
    ),
  );
  $context->reactions = array(
    'omniture_reaction' => array(
      'variables' => 's.events = event57
s.prop66 = Thank You Page View
s.prop67 = takepart:[current-page:url-arg:0]:[tp_omniture:str_decode:{node:title}]',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Omniture');
  t('Omniture parameters for TAB Thank You page');
  $export['omniture_tab_thank_you'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'omniture_topicfront';
  $context->description = 'Variables set on topic front page load';
  $context->tag = 'Omniture';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'topic_front' => 'topic_front',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'omniture_reaction' => array(
      'variables' => 's.prop20 = [tp_omniture:str_decode:{node:title}]
s.eVar21 = [tp_omniture:str_decode:{node:title}]',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Omniture');
  t('Variables set on topic front page load');
  $export['omniture_topicfront'] = $context;

  return $export;
}
