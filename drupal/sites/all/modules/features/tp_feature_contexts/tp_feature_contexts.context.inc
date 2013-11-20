<?php
/**
 * @file
 * tp_feature_contexts.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function tp_feature_contexts_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'homepage';
  $context->description = 'homepage redesign';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-ga_homepage_header' => array(
          'module' => 'boxes',
          'delta' => 'ga_homepage_header',
          'region' => 'header',
          'weight' => '-100',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'tp4_support-tp4_dont_miss' => array(
          'module' => 'tp4_support',
          'delta' => 'tp4_dont_miss',
          'region' => 'preface',
          'weight' => '-10',
        ),
        'views-homepage_columns-block' => array(
          'module' => 'views',
          'delta' => 'homepage_columns-block',
          'region' => 'skinny',
          'weight' => '-10',
        ),
        'views-takeaction_homepage-block' => array(
          'module' => 'views',
          'delta' => 'takeaction_homepage-block',
          'region' => 'skinny',
          'weight' => '-9',
        ),
        'views-latest_headlines-block' => array(
          'module' => 'views',
          'delta' => 'latest_headlines-block',
          'region' => 'sidebar',
          'weight' => '-10',
        ),
        'boxes-ga_homepage_top_right' => array(
          'module' => 'boxes',
          'delta' => 'ga_homepage_top_right',
          'region' => 'sidebar',
          'weight' => '-9',
        ),
        'newsletter_campaign-49' => array(
          'module' => 'newsletter_campaign',
          'delta' => '49',
          'region' => 'sidebar',
          'weight' => '-8',
        ),
        'views-photo_galleries_promo-block' => array(
          'module' => 'views',
          'delta' => 'photo_galleries_promo-block',
          'region' => 'sidebar',
          'weight' => '-7',
        ),
        'boxes-ga_homepage_bottom_right' => array(
          'module' => 'boxes',
          'delta' => 'ga_homepage_bottom_right',
          'region' => 'sidebar',
          'weight' => '-6',
        ),
        'tp4_support-tp4_graveyard' => array(
          'module' => 'tp4_support',
          'delta' => 'tp4_graveyard',
          'region' => 'suffix',
          'weight' => '-10',
        ),
        'boxes-ga_hp_1x1_background' => array(
          'module' => 'boxes',
          'delta' => 'ga_hp_1x1_background',
          'region' => 'suffix',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('homepage redesign');
  $export['homepage'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'topic_general';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'taxonomy_term' => array(
      'values' => array(
        'topic' => 'topic',
      ),
      'options' => array(
        'term_form' => '0',
      ),
    ),
    'theme' => array(
      'values' => array(
        'tp4' => 'tp4',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-topic_listing-block' => array(
          'module' => 'views',
          'delta' => 'topic_listing-block',
          'region' => 'content',
          'weight' => '10',
        ),
        'menu_block-2' => array(
          'module' => 'menu_block',
          'delta' => '2',
          'region' => 'sidebar',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['topic_general'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'tp4_article';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'openpublish_article' => 'openpublish_article',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'theme' => array(
      'values' => array(
        'tp4' => 'tp4',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-takepart' => array(
          'module' => 'boxes',
          'delta' => 'takepart',
          'region' => 'header',
          'weight' => '-100',
        ),
        'bean--of-the-day' => array(
          'module' => 'bean',
          'delta' => '-of-the-day',
          'region' => 'sidebar',
          'weight' => '-2',
        ),
        'boxes-box-18786b90' => array(
          'module' => 'boxes',
          'delta' => 'box-18786b90',
          'region' => 'sidebar',
          'weight' => '-1',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;
  $export['tp4_article'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'tp4_global';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'theme' => array(
      'values' => array(
        'tp4' => 'tp4',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'tp4_support-tp4_fat_header' => array(
          'module' => 'tp4_support',
          'delta' => 'tp4_fat_header',
          'region' => 'header',
          'weight' => '-10',
        ),
        'tp4_support-tp4_footer' => array(
          'module' => 'tp4_support',
          'delta' => 'tp4_footer',
          'region' => 'footer',
          'weight' => '-10',
        ),
        'menu-menu-megamenu' => array(
          'module' => 'menu',
          'delta' => 'menu-megamenu',
          'region' => 'left_drawer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['tp4_global'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'tp4_global_not_front';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~<front>' => '~<front>',
      ),
    ),
    'theme' => array(
      'values' => array(
        'tp4' => 'tp4',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-box-66c05d6f' => array(
          'module' => 'boxes',
          'delta' => 'box-66c05d6f',
          'region' => 'sidebar',
          'weight' => '-9',
        ),
        'newsletter_campaign-49' => array(
          'module' => 'newsletter_campaign',
          'delta' => '49',
          'region' => 'sidebar',
          'weight' => '-8',
        ),
        'boxes-box-1104adce' => array(
          'module' => 'boxes',
          'delta' => 'box-1104adce',
          'region' => 'sidebar',
          'weight' => '9',
        ),
        'boxes-bg_skin_sponsor' => array(
          'module' => 'boxes',
          'delta' => 'bg_skin_sponsor',
          'region' => 'suffix',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;
  $export['tp4_global_not_front'] = $context;

  return $export;
}
