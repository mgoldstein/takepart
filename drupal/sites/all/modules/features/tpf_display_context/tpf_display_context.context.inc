<?php
/**
 * @file
 * tpf_display_context.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function tpf_display_context_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = '404_feed';
  $context->description = 'The Latest Headlines view for the 404 page';
  $context->tag = 'TP4';
  $context->conditions = array(
    'error' => array(
      'values' => array(
        404 => '404',
      ),
    ),
    'path' => array(
      'values' => array(
        'node/236' => 'node/236',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-latest_headlines-block_1' => array(
          'module' => 'views',
          'delta' => 'latest_headlines-block_1',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('TP4');
  t('The Latest Headlines view for the 404 page');
  $export['404_feed'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'author_contributions';
  $context->description = 'Contributions from this author';
  $context->tag = 'Profiles';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'profile' => 'profile',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-author_contributions-block' => array(
          'module' => 'views',
          'delta' => 'author_contributions-block',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Contributions from this author');
  t('Profiles');
  $export['author_contributions'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'block_search';
  $context->description = 'Search';
  $context->tag = 'Block: Search';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'search*' => 'search*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-takepart' => array(
          'module' => 'boxes',
          'delta' => 'takepart',
          'region' => 'leaderboard',
          'weight' => '-10',
        ),
        'facetapi-VJwGNQ46y4iuJeqIzALpDmDGkirFA0o1' => array(
          'module' => 'facetapi',
          'delta' => 'VJwGNQ46y4iuJeqIzALpDmDGkirFA0o1',
          'region' => 'sidebar',
          'weight' => '-11',
        ),
        'facetapi-p6j6uydvqzGOZ3pcNbwjsR5fzChT15JY' => array(
          'module' => 'facetapi',
          'delta' => 'p6j6uydvqzGOZ3pcNbwjsR5fzChT15JY',
          'region' => 'sidebar',
          'weight' => '-10',
        ),
        'facetapi-jRFxoKf1ESPpk4Z9WOlWyZeObbMDdiy5' => array(
          'module' => 'facetapi',
          'delta' => 'jRFxoKf1ESPpk4Z9WOlWyZeObbMDdiy5',
          'region' => 'sidebar',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Block: Search');
  t('Search');
  $export['block_search'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blocks_article';
  $context->description = 'Article Blocks';
  $context->tag = 'Blocks: Content Type';
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
    'theme_html' => array(
      'class' => 'node-type-article',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Article Blocks');
  t('Blocks: Content Type');
  $export['blocks_article'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blocks_photo_gallery';
  $context->description = 'Photo Gallery Blocks';
  $context->tag = 'Blocks: Content Type';
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
    'block' => array(
      'blocks' => array(
        'boxes-box-66c05d6f' => array(
          'module' => 'boxes',
          'delta' => 'box-66c05d6f',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'newsletter_campaign-48' => array(
          'module' => 'newsletter_campaign',
          'delta' => '48',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'bean--of-the-day' => array(
          'module' => 'bean',
          'delta' => '-of-the-day',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
        'boxes-box-1104adce' => array(
          'module' => 'boxes',
          'delta' => 'box-1104adce',
          'region' => 'sidebar_second',
          'weight' => '-5',
        ),
        'boxes-box-944fcfe9' => array(
          'module' => 'boxes',
          'delta' => 'box-944fcfe9',
          'region' => 'full_width_top',
          'weight' => '0',
        ),
      ),
    ),
    'title' => array(
      'title_off' => 1,
      'title_override' => '',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks: Content Type');
  t('Photo Gallery Blocks');
  $export['blocks_photo_gallery'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blocks_video';
  $context->description = 'Video Blocks';
  $context->tag = 'Blocks: Content Type';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'openpublish_video' => 'openpublish_video',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-box-6c13820e' => array(
          'module' => 'boxes',
          'delta' => 'box-6c13820e',
          'region' => 'help',
          'weight' => 0,
        ),
        'boxes-box-bb0b625d' => array(
          'module' => 'boxes',
          'delta' => 'box-bb0b625d',
          'region' => 'content_top',
          'weight' => 0,
        ),
        'boxes-box-4eb62add' => array(
          'module' => 'boxes',
          'delta' => 'box-4eb62add',
          'region' => 'content_bottom',
          'weight' => 1,
        ),
        'views-video-block_8' => array(
          'module' => 'views',
          'delta' => 'video-block_8',
          'region' => 'content_bottom',
          'weight' => 2,
        ),
        'views-video-block' => array(
          'module' => 'views',
          'delta' => 'video-block',
          'region' => 'content_bottom',
          'weight' => 4,
        ),
        'comment_block_simple-comment_block' => array(
          'module' => 'comment_block_simple',
          'delta' => 'comment_block',
          'region' => 'content_bottom',
          'weight' => 5,
        ),
        'boxes-box-66c05d6f' => array(
          'module' => 'boxes',
          'delta' => 'box-66c05d6f',
          'region' => 'sidebar_second',
          'weight' => 0,
        ),
        'boxes-box-7fa6e22c' => array(
          'module' => 'boxes',
          'delta' => 'box-7fa6e22c',
          'region' => 'sidebar_second',
          'weight' => 1,
        ),
        'views-photo_galleries-block' => array(
          'module' => 'views',
          'delta' => 'photo_galleries-block',
          'region' => 'sidebar_second',
          'weight' => 2,
        ),
        'views-related_actions-block' => array(
          'module' => 'views',
          'delta' => 'related_actions-block',
          'region' => 'sidebar_second',
          'weight' => 3,
        ),
        'boxes-box-1104adce' => array(
          'module' => 'boxes',
          'delta' => 'box-1104adce',
          'region' => 'sidebar_second',
          'weight' => 4,
        ),
        'views-photo_galleries-block_2' => array(
          'module' => 'views',
          'delta' => 'photo_galleries-block_2',
          'region' => 'sidebar_second',
          'weight' => 5,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks: Content Type');
  t('Video Blocks');
  $export['blocks_video'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blocks_video_series';
  $context->description = 'Default Context for the video series taxonomy term';
  $context->tag = 'Context Field: Default';
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
        'views-video-block_3' => array(
          'module' => 'views',
          'delta' => 'video-block_3',
          'region' => 'content',
          'weight' => '0',
        ),
        'views-video-block_6' => array(
          'module' => 'views',
          'delta' => 'video-block_6',
          'region' => 'content',
          'weight' => '1',
        ),
        'boxes-box-66c05d6f' => array(
          'module' => 'boxes',
          'delta' => 'box-66c05d6f',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'boxes-box-e9e8814f' => array(
          'module' => 'boxes',
          'delta' => 'box-e9e8814f',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'boxes-box-1104adce' => array(
          'module' => 'boxes',
          'delta' => 'box-1104adce',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'takepart_custom-page_title_h1' => array(
          'module' => 'takepart_custom',
          'delta' => 'page_title_h1',
          'region' => 'content_top',
          'weight' => '0',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context Field: Default');
  t('Default Context for the video series taxonomy term');
  $export['blocks_video_series'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'free_tags_default_context';
  $context->description = 'Default Context for free_tags';
  $context->tag = 'Context Field';
  $context->conditions = array(
    'context_field' => array(
      'values' => array(
        'context_field' => 'context_field',
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'takepart_custom-page_title_h1' => array(
          'module' => 'takepart_custom',
          'delta' => 'page_title_h1',
          'region' => 'content_top',
          'weight' => 0,
        ),
        'views-taxonomy_search_list-block_1' => array(
          'module' => 'views',
          'delta' => 'taxonomy_search_list-block_1',
          'region' => 'content',
          'weight' => 0,
        ),
        'boxes-box-66c05d6f' => array(
          'module' => 'boxes',
          'delta' => 'box-66c05d6f',
          'region' => 'sidebar_second',
          'weight' => 0,
        ),
        'boxes-box-7fa6e22c' => array(
          'module' => 'boxes',
          'delta' => 'box-7fa6e22c',
          'region' => 'sidebar_second',
          'weight' => 1,
        ),
        'boxes-box-1104adce' => array(
          'module' => 'boxes',
          'delta' => 'box-1104adce',
          'region' => 'sidebar_second',
          'weight' => 2,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context Field');
  t('Default Context for free_tags');
  $export['free_tags_default_context'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'series_default_context';
  $context->description = 'Default Context for series';
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
        'boxes-box-66c05d6f' => array(
          'module' => 'boxes',
          'delta' => 'box-66c05d6f',
          'region' => 'sidebar_second',
          'weight' => '0',
        ),
        'newsletter_campaign-49' => array(
          'module' => 'newsletter_campaign',
          'delta' => '49',
          'region' => 'sidebar_second',
          'weight' => '1',
        ),
        'boxes-box-15362653' => array(
          'module' => 'boxes',
          'delta' => 'box-15362653',
          'region' => 'content_top',
          'weight' => '0',
        ),
        'views-taxonomy_search_list-block_2' => array(
          'module' => 'views',
          'delta' => 'taxonomy_search_list-block_2',
          'region' => 'content_bottom',
          'weight' => '0',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context Field Default');
  t('Default Context for series');
  $export['series_default_context'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'series_landing_page';
  $context->description = 'Series Taxonomy Search List';
  $context->tag = 'Series';
  $context->conditions = array(
    'taxonomy_term' => array(
      'values' => array(
        'series' => 'series',
      ),
      'options' => array(
        'term_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-taxonomy_search_list-block_2' => array(
          'module' => 'views',
          'delta' => 'taxonomy_search_list-block_2',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Series');
  t('Series Taxonomy Search List');
  $export['series_landing_page'] = $context;

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

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'topic_default_context';
  $context->description = 'Default Context for topic';
  $context->tag = 'Context Field';
  $context->conditions = array(
    'context_field' => array(
      'values' => array(
        'context_field' => 'context_field',
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
        'boxes-box-bb0b625d' => array(
          'module' => 'boxes',
          'delta' => 'box-bb0b625d',
          'region' => 'content_top',
          'weight' => 0,
        ),
        'takepart_custom-page_title_h1' => array(
          'module' => 'takepart_custom',
          'delta' => 'page_title_h1',
          'region' => 'content_top',
          'weight' => 1,
        ),
        'views-taxonomy_search_list-block' => array(
          'module' => 'views',
          'delta' => 'taxonomy_search_list-block',
          'region' => 'content_bottom',
          'weight' => 0,
        ),
        'boxes-box-66c05d6f' => array(
          'module' => 'boxes',
          'delta' => 'box-66c05d6f',
          'region' => 'sidebar_second',
          'weight' => 0,
        ),
        'boxes-box-6ab3a933' => array(
          'module' => 'boxes',
          'delta' => 'box-6ab3a933',
          'region' => 'sidebar_second',
          'weight' => 1,
        ),
        'views-related_campaigns-block_2' => array(
          'module' => 'views',
          'delta' => 'related_campaigns-block_2',
          'region' => 'sidebar_second',
          'weight' => 2,
        ),
        'boxes-box-1104adce' => array(
          'module' => 'boxes',
          'delta' => 'box-1104adce',
          'region' => 'sidebar_second',
          'weight' => 3,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context Field');
  t('Default Context for topic');
  $export['topic_default_context'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'topic_general';
  $context->description = 'For Topic taxonomy term pages in TP4';
  $context->tag = 'TP4';
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
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('For Topic taxonomy term pages in TP4');
  t('TP4');
  $export['topic_general'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'tp4_article';
  $context->description = '';
  $context->tag = 'TP4';
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
          'weight' => '-4',
        ),
        'bean-takepart-video-media-block' => array(
          'module' => 'bean',
          'delta' => 'takepart-video-media-block',
          'region' => 'sidebar',
          'weight' => '-3',
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'node-type-article',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('TP4');
  $export['tp4_article'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'tp4_campaign_cards';
  $context->description = '';
  $context->tag = 'TP4';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'campaign_card_ad' => 'campaign_card_ad',
        'campaign_card_branding' => 'campaign_card_branding',
        'campaign_card_empty' => 'campaign_card_empty',
        'campaign_card_iframe' => 'campaign_card_iframe',
        'campaign_card_media' => 'campaign_card_media',
        'campaign_card_multi_column' => 'campaign_card_multi_column',
        'campaign_card_news' => 'campaign_card_news',
        'campaign_card_social' => 'campaign_card_social',
        'campaign_card_tap_widget' => 'campaign_card_tap_widget',
        'campaign_card_text' => 'campaign_card_text',
        'campaign_card_twitter' => 'campaign_card_twitter',
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
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
    'disable_context' => array(
      'disabled' => array(
        'tp4_global' => 'tp4_global',
        'tp4_global_not_front' => 'tp4_global_not_front',
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('TP4');
  $export['tp4_campaign_cards'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'tp4_campaign_pages';
  $context->description = '';
  $context->tag = 'TP4';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'campaign_page' => 'campaign_page',
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
        'boxes-ga_campaign_header' => array(
          'module' => 'boxes',
          'delta' => 'ga_campaign_header',
          'region' => 'header',
          'weight' => '-10',
        ),
        'tp4_support-tp4_slim_nav' => array(
          'module' => 'tp4_support',
          'delta' => 'tp4_slim_nav',
          'region' => 'header',
          'weight' => '-8',
        ),
        'tp_campaigns-tp_campaigns_hero' => array(
          'module' => 'tp_campaigns',
          'delta' => 'tp_campaigns_hero',
          'region' => 'header',
          'weight' => '-7',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'tp4_support-tp4_footer' => array(
          'module' => 'tp4_support',
          'delta' => 'tp4_footer',
          'region' => 'footer',
          'weight' => '-9',
        ),
        'bean-featured-campaigns-module' => array(
          'module' => 'bean',
          'delta' => 'featured-campaigns-module',
          'region' => 'footer',
          'weight' => '-10',
        ),
        'menu-menu-megamenu' => array(
          'module' => 'menu',
          'delta' => 'menu-megamenu',
          'region' => 'left_drawer',
          'weight' => '-9',
        ),
        'tp4_support-tp4_mobile_menu_header' => array(
          'module' => 'tp4_support',
          'delta' => 'tp4_mobile_menu_header',
          'region' => 'left_drawer',
          'weight' => '-10',
        ),
      ),
    ),
    'disable_context' => array(
      'disabled' => array(
        'tp4_global' => 'tp4_global',
        'tp4_global_not_front' => 'tp4_global_not_front',
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('TP4');
  $export['tp4_campaign_pages'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'tp4_dtm';
  $context->description = 'Expose DTM';
  $context->tag = 'DTM';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('DTM');
  t('Expose DTM');
  $export['tp4_dtm'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'tp4_feature';
  $context->description = 'Ad positions for Feature Articles';
  $context->tag = 'TP4';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'feature_article' => 'feature_article',
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
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Ad positions for Feature Articles');
  t('TP4');
  $export['tp4_feature'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'tp4_flashcard';
  $context->description = '';
  $context->tag = 'TP4';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'flashcard' => 'flashcard',
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
          'weight' => '-10',
        ),
        'tp_flashcards-flashcard_related_content' => array(
          'module' => 'tp_flashcards',
          'delta' => 'flashcard_related_content',
          'region' => 'content',
          'weight' => '-10',
        ),
        'tp_flashcards-flashcard_get_more' => array(
          'module' => 'tp_flashcards',
          'delta' => 'flashcard_get_more',
          'region' => 'content',
          'weight' => '-9',
        ),
        'tp_flashcards-flashcard_comments' => array(
          'module' => 'tp_flashcards',
          'delta' => 'flashcard_comments',
          'region' => 'content',
          'weight' => '-8',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'preface',
          'weight' => '-10',
        ),
        'newsletter_campaign-51' => array(
          'module' => 'newsletter_campaign',
          'delta' => '51',
          'region' => 'sidebar',
          'weight' => '-10',
        ),
        'views-92f8036c910f2ff5c341b7002d220886' => array(
          'module' => 'views',
          'delta' => '92f8036c910f2ff5c341b7002d220886',
          'region' => 'sidebar',
          'weight' => '-9',
        ),
        'boxes-box-1104adce' => array(
          'module' => 'boxes',
          'delta' => 'box-1104adce',
          'region' => 'sidebar',
          'weight' => '-8',
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

  // Translatables
  // Included for use with string extractors like potx.
  t('TP4');
  $export['tp4_flashcard'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'tp4_global';
  $context->description = '';
  $context->tag = 'TP4';
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
          'weight' => '-9',
        ),
        'boxes-ga_mobile_320x50_relative' => array(
          'module' => 'boxes',
          'delta' => 'ga_mobile_320x50_relative',
          'region' => 'header',
          'weight' => '-8',
        ),
        'bean-featured-campaigns-module' => array(
          'module' => 'bean',
          'delta' => 'featured-campaigns-module',
          'region' => 'footer',
          'weight' => '-10',
        ),
        'tp4_support-tp4_footer' => array(
          'module' => 'tp4_support',
          'delta' => 'tp4_footer',
          'region' => 'footer',
          'weight' => '-9',
        ),
        'pm_interstitial-interstitials' => array(
          'module' => 'pm_interstitial',
          'delta' => 'interstitials',
          'region' => 'suffix',
          'weight' => '-10',
        ),
        'tp4_support-tp4_mobile_menu_header' => array(
          'module' => 'tp4_support',
          'delta' => 'tp4_mobile_menu_header',
          'region' => 'left_drawer',
          'weight' => '-10',
        ),
        'menu-menu-megamenu' => array(
          'module' => 'menu',
          'delta' => 'menu-megamenu',
          'region' => 'left_drawer',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('TP4');
  $export['tp4_global'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'tp4_global_not_front';
  $context->description = '';
  $context->tag = 'TP4';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~<front>' => '~<front>',
        '~feature/*' => '~feature/*',
        '~video/*' => '~video/*',
        '~flashcards/*' => '~flashcards/*',
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
          'weight' => '-12',
        ),
        'newsletter_campaign-51' => array(
          'module' => 'newsletter_campaign',
          'delta' => '51',
          'region' => 'sidebar',
          'weight' => '-8',
        ),
        'boxes-box-1104adce' => array(
          'module' => 'boxes',
          'delta' => 'box-1104adce',
          'region' => 'sidebar',
          'weight' => '10',
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

  // Translatables
  // Included for use with string extractors like potx.
  t('TP4');
  $export['tp4_global_not_front'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'tp4_photo_gallery';
  $context->description = '';
  $context->tag = 'TP4';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'openpublish_photo_gallery' => 'openpublish_photo_gallery',
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
          'weight' => '-9',
        ),
        'tp4_support-tp4_fat_header' => array(
          'module' => 'tp4_support',
          'delta' => 'tp4_fat_header',
          'region' => 'header',
          'weight' => '-8',
        ),
        'boxes-ga_mobile_320x50_relative' => array(
          'module' => 'boxes',
          'delta' => 'ga_mobile_320x50_relative',
          'region' => 'header',
          'weight' => '-7',
        ),
        'tp4_support-tp4_footer' => array(
          'module' => 'tp4_support',
          'delta' => 'tp4_footer',
          'region' => 'footer',
          'weight' => '-10',
        ),
        'takepart_gallery_support-takepart_gallery_cover_slide' => array(
          'module' => 'takepart_gallery_support',
          'delta' => 'takepart_gallery_cover_slide',
          'region' => 'preface',
          'weight' => '-10',
        ),
        'takepart_gallery_support-takepart_gallery_content' => array(
          'module' => 'takepart_gallery_support',
          'delta' => 'takepart_gallery_content',
          'region' => 'preface',
          'weight' => '-9',
        ),
        'boxes-box-66c05d6f' => array(
          'module' => 'boxes',
          'delta' => 'box-66c05d6f',
          'region' => 'sidebar',
          'weight' => '-10',
        ),
        'newsletter_campaign-48' => array(
          'module' => 'newsletter_campaign',
          'delta' => '48',
          'region' => 'sidebar',
          'weight' => '-8',
        ),
        'pm_interstitial-interstitials' => array(
          'module' => 'pm_interstitial',
          'delta' => 'interstitials',
          'region' => 'suffix',
          'weight' => '-10',
        ),
        'boxes-bg_skin_sponsor' => array(
          'module' => 'boxes',
          'delta' => 'bg_skin_sponsor',
          'region' => 'suffix',
          'weight' => '-9',
        ),
        'menu-menu-megamenu' => array(
          'module' => 'menu',
          'delta' => 'menu-megamenu',
          'region' => 'left_drawer',
          'weight' => '-10',
        ),
      ),
    ),
    'disable_context' => array(
      'disabled' => array(
        'tp4_global' => 'tp4_global',
        'tp4_global_not_front' => 'tp4_global_not_front',
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('TP4');
  $export['tp4_photo_gallery'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'tp4_topic';
  $context->description = 'Ad positions for Topic Fronts';
  $context->tag = 'TP4';
  $context->conditions = array(
    'taxonomy_term' => array(
      'values' => array(
        'free_tags' => 'free_tags',
        'series' => 'series',
        'topic' => 'topic',
      ),
      'options' => array(
        'term_form' => '1',
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
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Ad positions for Topic Fronts');
  t('TP4');
  $export['tp4_topic'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'tp4_video';
  $context->description = 'Right rail content and ad positions for TP4 videos and playlists';
  $context->tag = 'TP4';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'video' => 'video',
        'video_playlist' => 'video_playlist',
      ),
      'options' => array(
        'node_form' => '1',
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
          'weight' => '-11',
        ),
        'boxes-box-66c05d6f' => array(
          'module' => 'boxes',
          'delta' => 'box-66c05d6f',
          'region' => 'sidebar',
          'weight' => '-10',
        ),
        'newsletter_campaign-51' => array(
          'module' => 'newsletter_campaign',
          'delta' => '51',
          'region' => 'sidebar',
          'weight' => '-8',
        ),
        'bean--of-the-day' => array(
          'module' => 'bean',
          'delta' => '-of-the-day',
          'region' => 'sidebar',
          'weight' => '-7',
        ),
        'boxes-box-1104adce' => array(
          'module' => 'boxes',
          'delta' => 'box-1104adce',
          'region' => 'sidebar',
          'weight' => '-6',
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
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Right rail content and ad positions for TP4 videos and playlists');
  t('TP4');
  $export['tp4_video'] = $context;

  return $export;
}
