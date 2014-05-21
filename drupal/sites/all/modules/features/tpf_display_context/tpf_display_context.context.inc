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
  $context->name = 'ad_exclude_campaign';
  $context->description = 'Context used by general_ad to exclude ads from pages/sections';
  $context->tag = 'Ads';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'action' => 'action',
        'openpublish_article' => 'openpublish_article',
        'openpublish_blog_post' => 'openpublish_blog_post',
        'openpublish_photo_gallery' => 'openpublish_photo_gallery',
        'takepart_campaign' => 'takepart_campaign',
        'takepart_group' => 'takepart_group',
        'takepart_list' => 'takepart_list',
        'takepart_quick_study' => 'takepart_quick_study',
        'takepart_slide' => 'takepart_slide',
        'webform' => 'webform',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'home' => 'home',
        'free-tag*' => 'free-tag*',
        'topic*' => 'topic*',
        'afinefrenzy' => 'afinefrenzy',
        'thepeoplespeak' => 'thepeoplespeak',
        'wavesofaction' => 'wavesofaction',
        'congowomen' => 'congowomen',
        'crisisinegypt' => 'crisisinegypt',
        'journeyofaction' => 'journeyofaction',
        'skollworldforum' => 'skollworldforum',
        'thejohnalexanderproject' => 'thejohnalexanderproject',
        'casinojack/followthemoney' => 'casinojack/followthemoney',
        'thecove/gotmercury' => 'thecove/gotmercury',
        'searchforcommonground' => 'searchforcommonground',
        'underourskin' => 'underourskin',
        'eradicatewaterborneillnesses' => 'eradicatewaterborneillnesses',
        'teachinggarden' => 'teachinggarden',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-box-4f9af2b4' => array(
          'module' => 'boxes',
          'delta' => 'box-4f9af2b4',
          'region' => 'header',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Ads');
  t('Context used by general_ad to exclude ads from pages/sections');
  $export['ad_exclude_campaign'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'addthis_blocks';
  $context->description = 'AddThis share list';
  $context->tag = 'Blocks: AddThis';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'openpublish_blog_post' => 'openpublish_blog_post',
        'openpublish_video' => 'openpublish_video',
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
          'weight' => 3,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('AddThis share list');
  t('Blocks: AddThis');
  $export['addthis_blocks'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'addthis_leftpanel_blocks';
  $context->description = '';
  $context->tag = 'Blocks: AddThis';
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
        'boxes-box-72e1be3c' => array(
          'module' => 'boxes',
          'delta' => 'box-72e1be3c',
          'region' => 'sidebar_first',
          'weight' => 0,
        ),
        'takepart_addthis-addthis_full' => array(
          'module' => 'takepart_addthis',
          'delta' => 'addthis_full',
          'region' => 'sidebar_first',
          'weight' => 1,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks: AddThis');
  $export['addthis_leftpanel_blocks'] = $context;

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
        'facetapi-VJwGNQ46y4iuJeqIzALpDmDGkirFA0o1' => array(
          'module' => 'facetapi',
          'delta' => 'VJwGNQ46y4iuJeqIzALpDmDGkirFA0o1',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'facetapi-p6j6uydvqzGOZ3pcNbwjsR5fzChT15JY' => array(
          'module' => 'facetapi',
          'delta' => 'p6j6uydvqzGOZ3pcNbwjsR5fzChT15JY',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'facetapi-StCw4MzrvpsV2LTHu4LZiKV1hGHJpKsU' => array(
          'module' => 'facetapi',
          'delta' => 'StCw4MzrvpsV2LTHu4LZiKV1hGHJpKsU',
          'region' => 'sidebar_second',
          'weight' => '-8',
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
  $context->name = 'blocks_action';
  $context->description = 'Action Blocks';
  $context->tag = 'Blocks: Content Type';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'action' => 'action',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-box-41040ece' => array(
          'module' => 'boxes',
          'delta' => 'box-41040ece',
          'region' => 'highlighted',
          'weight' => '0',
        ),
        'menu-menu-takeaction-button-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-takeaction-button-menu',
          'region' => 'highlighted',
          'weight' => '1',
        ),
        'boxes-box-66c05d6f' => array(
          'module' => 'boxes',
          'delta' => 'box-66c05d6f',
          'region' => 'sidebar_second',
          'weight' => '0',
        ),
        'views-related_content-block' => array(
          'module' => 'views',
          'delta' => 'related_content-block',
          'region' => 'sidebar_second',
          'weight' => '1',
        ),
        'boxes-box-7fa6e22c' => array(
          'module' => 'boxes',
          'delta' => 'box-7fa6e22c',
          'region' => 'sidebar_second',
          'weight' => '2',
        ),
        'boxes-box-1104adce' => array(
          'module' => 'boxes',
          'delta' => 'box-1104adce',
          'region' => 'sidebar_second',
          'weight' => '3',
        ),
        'boxes-box-6c13820e' => array(
          'module' => 'boxes',
          'delta' => 'box-6c13820e',
          'region' => 'content_top',
          'weight' => '0',
        ),
        'boxes-action_header_image' => array(
          'module' => 'boxes',
          'delta' => 'action_header_image',
          'region' => 'content_top',
          'weight' => '1',
        ),
        'boxes-action_topic_and_share' => array(
          'module' => 'boxes',
          'delta' => 'action_topic_and_share',
          'region' => 'content_top',
          'weight' => '2',
        ),
        'takepart_custom-page_title_h1' => array(
          'module' => 'takepart_custom',
          'delta' => 'page_title_h1',
          'region' => 'content_top',
          'weight' => '3',
        ),
        'boxes-box-4eb62add' => array(
          'module' => 'boxes',
          'delta' => 'box-4eb62add',
          'region' => 'content_bottom',
          'weight' => '0',
        ),
        'views-content_updates-block' => array(
          'module' => 'views',
          'delta' => 'content_updates-block',
          'region' => 'content_bottom',
          'weight' => '1',
        ),
        'comment_block_simple-comment_block' => array(
          'module' => 'comment_block_simple',
          'delta' => 'comment_block',
          'region' => 'content_bottom',
          'weight' => '2',
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'multipage-campaign',
    ),
    'title' => array(
      'title_off' => 1,
      'title_override' => '',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Action Blocks');
  t('Blocks: Content Type');
  $export['blocks_action'] = $context;

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
  $context->name = 'blocks_blog_posts';
  $context->description = 'Blog Post Blocks';
  $context->tag = 'Blocks: Content Type';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'openpublish_blog_post' => 'openpublish_blog_post',
      ),
      'options' => array(
        'node_form' => '1',
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
        'views-blogs-block_3' => array(
          'module' => 'views',
          'delta' => 'blogs-block_3',
          'region' => 'content_top',
          'weight' => 1,
        ),
        'takepart_custom-page_title_h1' => array(
          'module' => 'takepart_custom',
          'delta' => 'page_title_h1',
          'region' => 'content_top',
          'weight' => 2,
        ),
        'boxes-box-1dae03d3' => array(
          'module' => 'boxes',
          'delta' => 'box-1dae03d3',
          'region' => 'content_top',
          'weight' => 3,
        ),
        'boxes-box-4eb62add' => array(
          'module' => 'boxes',
          'delta' => 'box-4eb62add',
          'region' => 'content_bottom',
          'weight' => 1,
        ),
        'boxes-box-34ee1b08' => array(
          'module' => 'boxes',
          'delta' => 'box-34ee1b08',
          'region' => 'content_bottom',
          'weight' => 2,
        ),
        'comment_block_simple-comment_block' => array(
          'module' => 'comment_block_simple',
          'delta' => 'comment_block',
          'region' => 'content_bottom',
          'weight' => 3,
        ),
        'boxes-box-66c05d6f' => array(
          'module' => 'boxes',
          'delta' => 'box-66c05d6f',
          'region' => 'sidebar_second',
          'weight' => 0,
        ),
        'boxes-box-bedd1fbb' => array(
          'module' => 'boxes',
          'delta' => 'box-bedd1fbb',
          'region' => 'sidebar_second',
          'weight' => 1,
        ),
        'newsletter_campaign-10' => array(
          'module' => 'newsletter_campaign',
          'delta' => '10',
          'region' => 'sidebar_second',
          'weight' => 2,
        ),
        'views-related_content-block' => array(
          'module' => 'views',
          'delta' => 'related_content-block',
          'region' => 'sidebar_second',
          'weight' => 3,
        ),
        'boxes-box-7fa6e22c' => array(
          'module' => 'boxes',
          'delta' => 'box-7fa6e22c',
          'region' => 'sidebar_second',
          'weight' => 4,
        ),
        'views-related_actions-block' => array(
          'module' => 'views',
          'delta' => 'related_actions-block',
          'region' => 'sidebar_second',
          'weight' => 5,
        ),
        'boxes-box-1104adce' => array(
          'module' => 'boxes',
          'delta' => 'box-1104adce',
          'region' => 'sidebar_second',
          'weight' => 6,
        ),
      ),
    ),
    'title' => array(
      'title_off' => 1,
      'title_override' => '',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks: Content Type');
  t('Blog Post Blocks');
  $export['blocks_blog_posts'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blocks_group';
  $context->description = 'Group Blocks';
  $context->tag = 'Blocks: Content Type';
  $context->conditions = array(
    'node' => array(
      'values' => array(
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
        'takepart_custom-page_title_h1' => array(
          'module' => 'takepart_custom',
          'delta' => 'page_title_h1',
          'region' => 'highlighted',
          'weight' => '0',
        ),
        'boxes-box-c5c30007' => array(
          'module' => 'boxes',
          'delta' => 'box-c5c30007',
          'region' => 'highlighted',
          'weight' => '1',
        ),
        'boxes-box-f070c115' => array(
          'module' => 'boxes',
          'delta' => 'box-f070c115',
          'region' => 'sidebar_first',
          'weight' => '0',
        ),
        'views-related_actions-block_2' => array(
          'module' => 'views',
          'delta' => 'related_actions-block_2',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
      ),
    ),
    'title' => array(
      'title_off' => 1,
      'title_override' => '',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks: Content Type');
  t('Group Blocks');
  $export['blocks_group'] = $context;

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
  $context->name = 'blocks_quick_study';
  $context->description = 'Quick Study Blocks';
  $context->tag = 'Blocks: Content Type';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'takepart_quick_study' => 'takepart_quick_study',
      ),
      'options' => array(
        'node_form' => '1',
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
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks: Content Type');
  t('Quick Study Blocks');
  $export['blocks_quick_study'] = $context;

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
  $context->name = 'general_ad';
  $context->description = 'Place basic ad on most pages';
  $context->tag = 'Ads';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        '~ad_exclude_campaign' => '~ad_exclude_campaign',
      ),
    ),
    'node' => array(
      'values' => array(
        'action' => 'action',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        '~user*' => '~user*',
        'series*' => 'series*',
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
        'boxes-box-1104adce' => array(
          'module' => 'boxes',
          'delta' => 'box-1104adce',
          'region' => 'sidebar_second',
          'weight' => '3',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Ads');
  t('Place basic ad on most pages');
  $export['general_ad'] = $context;

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
          'delta' => 'multi_page_campaign_default_cont',
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
  $context->name = 'omniture_action';
  $context->description = 'Variables to set on action pages.';
  $context->tag = 'Omniture';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'action' => 'action',
        'petition_action' => 'petition_action',
        'pledge_action' => 'pledge_action',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'omniture_reaction' => array(
      'variables' => 's.events = event55
s.prop53 = [tp_omniture:str_decode:{node:title}]
s.eVar53 = [tp_omniture:str_decode:{node:title}]
s.prop54 = [tp_omniture:str_decode:{node:url}]
s.eVar54 = [tp_omniture:str_decode:{node:url}]
s.prop55 = [tp_omniture:first_word:{node:content-type}]
s.eVar55 = [tp_omniture:first_word:{node:content-type}]
s.prop56 = [tp_omniture:value_or_empty:{node:field_display_tag}]
s.eVar56 = [tp_omniture:value_or_empty:{node:field_display_tag}]
s.eVar58 = [tp_omniture:get_tab_uid:{current-user:uid}]
s.prop58 = [tp_omniture:get_tab_uid:{current-user:uid}]
s.prop66 = Action Page View
s.prop67 = takepart:[current-page:url-arg:0]:[tp_omniture:str_decode:{node:title}]',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Omniture');
  t('Variables to set on action pages.');
  $export['omniture_action'] = $context;

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
        'blog_front' => 'blog_front',
        'campaign' => 'campaign',
        'feature_article' => 'feature_article',
        'flashcard' => 'flashcard',
        'openpublish_article' => 'openpublish_article',
        'openpublish_blog_post' => 'openpublish_blog_post',
        'openpublish_photo_gallery' => 'openpublish_photo_gallery',
        'openpublish_video' => 'openpublish_video',
        'poll' => 'poll',
        'profile' => 'profile',
        'section_front' => 'section_front',
        'section_front_wide' => 'section_front_wide',
        'takepart_campaign' => 'takepart_campaign',
        'takepart_group' => 'takepart_group',
        'takepart_list' => 'takepart_list',
        'takepart_page' => 'takepart_page',
        'topic_front' => 'topic_front',
        'venue' => 'venue',
        'video' => 'video',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'omniture_reaction' => array(
      'variables' => 's.pageName = takepart:[current-page:url-arg:0]:[tp_omniture:str_decode:{current-page:title}]
s.channel = [tp_omniture:lowercase:{current-page:url-arg:0}]
s.prop1 = [tp_omniture:lowercase:{current-page:url-arg:0}]
s.prop2 = [tp_omniture:lowercase:{current-page:url-arg:0}]:[tp_omniture:lowercase:{current-page:url-arg:1}]
s.prop3 = [tp_omniture:lowercase:{current-page:url-arg:0}]:[tp_omniture:lowercase:{current-page:url-arg:1}]:[tp_omniture:lowercase:{current-page:url-arg:2}]
s.prop4 = [tp_omniture:value_or_empty:{node:content-type}]
s.prop6 = [node:nid]
s.prop16 = [tp_omniture:get_author:{node:nid}]
s.prop17 = [tp_omniture:str_decode:{node:title}]
s.prop18 = [tp_omniture:value_or_empty:{node:field_series}]
s.prop19 = [tp_omniture:date:{node:created:raw}]
s.prop20 = [tp_omniture:primary_topic:{node:nid}]
s.prop22 = [tp_omniture:value_or_empty:{node:field_free_tag}]
s.list2 = [tp_omniture:value_or_empty:{node:field_free_tag}]
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
      'variables' => 's.pageName = takepart:[current-page:url-arg:0]:[tp_omniture:str_decode:{current-page:title}]
s.channel = [tp_omniture:lowercase:{current-page:url-arg:0}]
s.prop1 = [tp_omniture:lowercase:{current-page:url-arg:0}]
s.prop2 = [tp_omniture:lowercase:{current-page:url-arg:0}]:[tp_omniture:lowercase:{current-page:url-arg:1}]
s.prop3 = [tp_omniture:lowercase:{current-page:url-arg:0}]:[tp_omniture:lowercase:{current-page:url-arg:1}]:[tp_omniture:lowercase:{current-page:url-arg:2}]
s.events = event6
s.prop4 = [tp_omniture:value_or_empty:{node:content-type}]
s.prop6 = [node:nid]
s.prop16 = [tp_omniture:get_author:{node:nid}]
s.prop17 = [tp_omniture:str_decode:{node:title}]
s.prop18 = [tp_omniture:value_or_empty:{node:field_series}]
s.prop19 = [tp_omniture:date:{node:created:raw}]
s.prop20 = [tp_omniture:primary_topic:{node:nid}]
s.prop22 = [tp_omniture:value_or_empty:{node:field_free_tag}]
s.list2  = [tp_omniture:value_or_empty:{node:field_free_tag}]
s.prop43 = [tp_omniture:campaign_context:{node:nid}]',
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
      'variables' => 's.pageName = takepart:[current-page:url-arg:0]:[tp_omniture:str_decode:{current-page:title}]
s.channel = [tp_omniture:lowercase:{current-page:url-arg:0}]
s.prop1 = [tp_omniture:lowercase:{current-page:url-arg:0}]
s.prop2 = [tp_omniture:lowercase:{current-page:url-arg:0}]:[tp_omniture:lowercase:{current-page:url-arg:1}]
s.prop3 = [tp_omniture:lowercase:{current-page:url-arg:0}]:[tp_omniture:lowercase:{current-page:url-arg:1}]:[tp_omniture:lowercase:{current-page:url-arg:2}]
s.prop2 = [current-page:url-arg:1]
s.prop3 = [current-page:url-arg:0]:[tp_omniture:date:{node:created:raw}]:[tp_omniture:str_decode:{node:title}]
s.eVar19 = [tp_omniture:value_or_empty:{node:field-blogpost-blog:term:name}]
s.prop18 = [tp_omniture:value_or_empty:{node:field-blogpost-blog:term:name}]
s.prop22 = [tp_omniture:value_or_empty:{node:field_free_tag}]
s.list2 = [tp_omniture:value_or_empty:{node:field_free_tag}]',
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
  $context->name = 'omniture_flashcard';
  $context->description = 'Variables to set on flashcard pages';
  $context->tag = 'Omniture';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'flashcard' => 'flashcard',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'omniture_reaction' => array(
      'variables' => 's.pageName = takepart:[current-page:url-arg:0]:[tp_omniture:str_decode:{current-page:title}]
s.channel = [tp_omniture:lowercase:{current-page:url-arg:0}]
s.prop1 = [tp_omniture:lowercase:{current-page:url-arg:0}]
s.prop2 = [tp_omniture:lowercase:{current-page:url-arg:0}]:[tp_omniture:lowercase:{current-page:url-arg:1}]
s.prop3 = [tp_omniture:lowercase:{current-page:url-arg:0}]:[tp_omniture:lowercase:{current-page:url-arg:1}]:[tp_omniture:lowercase:{current-page:url-arg:2}]
s.prop4 = [tp_omniture:value_or_empty:{node:content-type}]
s.prop6 = [node:nid]
s.prop17 = [tp_omniture:str_decode:{node:title}]
s.prop19 = [tp_omniture:date:{node:created:raw}]
s.prop20 = [tp_omniture:primary_topic:{node:nid}]
',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Omniture');
  t('Variables to set on flashcard pages');
  $export['omniture_flashcard'] = $context;

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
      'variables' => 's.pageName = takepart:[current-page:url-arg:0]:[tp_omniture:str_decode:{current-page:title}]
s.channel = [tp_omniture:lowercase:{current-page:url-arg:0}]
s.prop1 = [tp_omniture:lowercase:{current-page:url-arg:0}]
s.prop2 = [tp_omniture:lowercase:{current-page:url-arg:0}]:[tp_omniture:lowercase:{current-page:url-arg:1}]
s.prop3 = [tp_omniture:lowercase:{current-page:url-arg:0}]:[tp_omniture:lowercase:{current-page:url-arg:1}]:[tp_omniture:lowercase:{current-page:url-arg:2}]
s.prop16 = [tp_omniture:get_author:{node:nid}]
s.prop20 = [tp_omniture:primary_topic:{node:nid}]
s.prop22 = [tp_omniture:value_or_empty:{node:field_free_tag}]
s.list2 = [tp_omniture:value_or_empty:{node:field_free_tag}]',
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
      'variables' => 's.pageName = takepart:home:TakePart Home
s.channel = home
s.prop1 = home
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
      'variables' => 's.pageName = takepart:[current-page:url-arg:0]:[tp_omniture:str_decode:{current-page:title}]
s.channel = [tp_omniture:lowercase:{current-page:url-arg:0}]
s.prop1 = [tp_omniture:lowercase:{current-page:url-arg:0}]
s.prop2 = [tp_omniture:lowercase:{current-page:url-arg:0}]:[tp_omniture:lowercase:{current-page:url-arg:1}]
s.prop3 = [tp_omniture:lowercase:{current-page:url-arg:0}]:[tp_omniture:lowercase:{current-page:url-arg:1}]:[tp_omniture:lowercase:{current-page:url-arg:2}]
s.events = event23,event33,event21
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
  $context->name = 'omniture_seriesfront';
  $context->description = 'Variables set on series landing pages';
  $context->tag = 'Omniture';
  $context->conditions = array(
    'taxonomy_term' => array(
      'values' => array(
        'series' => 'series',
        'video_series' => 'video_series',
      ),
      'options' => array(
        'term_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'omniture_reaction' => array(
      'variables' => 's.pageName = takepart:[current-page:url-arg:0]:[tp_omniture:str_decode:{current-page:title}]
s.channel = [tp_omniture:lowercase:{current-page:url-arg:0}]
s.prop1 = [tp_omniture:lowercase:{current-page:url-arg:0}]
s.prop2 = [tp_omniture:lowercase:{current-page:url-arg:0}]:[tp_omniture:lowercase:{current-page:url-arg:1}]
s.prop3 = [tp_omniture:lowercase:{current-page:url-arg:0}]:[tp_omniture:lowercase:{current-page:url-arg:1}]:[tp_omniture:lowercase:{current-page:url-arg:2}]
s.prop18 = [tp_omniture:str_decode:{current-page:title}]
s.eVar19 = [tp_omniture:str_decode:{current-page:title}]',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Omniture');
  t('Variables set on series landing pages');
  $export['omniture_seriesfront'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'omniture_site_wide';
  $context->description = 'Omniture Settings for the every page';
  $context->tag = 'Omniture';
  $context->conditions = array(
    'context_all' => array(
      'values' => array(
        '~tp4_campaign_cards' => '~tp4_campaign_cards',
        '~tp4_campaign_pages' => '~tp4_campaign_pages',
      ),
    ),
    'path' => array(
      'values' => array(
        '~<front>' => '~<front>',
      ),
    ),
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'omniture_reaction' => array(
      'variables' => 's.pageName = takepart:[current-page:url-arg:0]:[tp_omniture:str_decode:{current-page:title}]
s.channel = [tp_omniture:lowercase:{current-page:url-arg:0}]
s.prop1 = [tp_omniture:lowercase:{current-page:url-arg:0}]
s.prop2 = [tp_omniture:lowercase:{current-page:url-arg:0}]:[tp_omniture:lowercase:{current-page:url-arg:1}]
s.prop3 = [tp_omniture:lowercase:{current-page:url-arg:0}]:[tp_omniture:lowercase:{current-page:url-arg:1}]:[tp_omniture:lowercase:{current-page:url-arg:2}]',
    ),
  );
  $context->condition_mode = 1;

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
  $context->name = 'omniture_teach_campaign';
  $context->description = 'Analytics configuration for Teach campaign pages';
  $context->tag = 'Omniture';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'wordlet/teach_share_your_story' => 'wordlet/teach_share_your_story',
      ),
    ),
  );
  $context->reactions = array(
    'omniture_reaction' => array(
      'variables' => 's.events = event86',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Analytics configuration for Teach campaign pages');
  t('Omniture');
  $export['omniture_teach_campaign'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'omniture_topicfront';
  $context->description = 'Variables set on topic front page load';
  $context->tag = 'Omniture';
  $context->conditions = array(
    'taxonomy_term' => array(
      'values' => array(
        'topic' => 'topic',
      ),
      'options' => array(
        'term_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'omniture_reaction' => array(
      'variables' => 's.pageName = takepart:[current-page:url-arg:0]:[tp_omniture:str_decode:{current-page:title}]
s.channel = [tp_omniture:lowercase:{current-page:url-arg:0}]
s.prop1 = [tp_omniture:lowercase:{current-page:url-arg:0}]
s.prop2 = [tp_omniture:lowercase:{current-page:url-arg:0}]:[tp_omniture:lowercase:{current-page:url-arg:1}]
s.prop3 = [tp_omniture:lowercase:{current-page:url-arg:0}]:[tp_omniture:lowercase:{current-page:url-arg:1}]:[tp_omniture:lowercase:{current-page:url-arg:2}]
s.prop4 = topic front
s.prop20 = [tp_omniture:stringfixes:{current-page:title}]
',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Omniture');
  t('Variables set on topic front page load');
  $export['omniture_topicfront'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'omniture_user_profile';
  $context->description = 'Variables set on user profile pages';
  $context->tag = 'Omniture';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'user' => 'user',
      ),
    ),
  );
  $context->reactions = array(
    'omniture_reaction' => array(
      'variables' => 's.pageName = takepart:[current-page:url-arg:0]:[tp_omniture:str_decode:{current-page:title}]
s.channel = [tp_omniture:lowercase:{current-page:url-arg:0}]
s.prop1 = [tp_omniture:lowercase:{current-page:url-arg:0}]
s.prop2 = [tp_omniture:lowercase:{current-page:url-arg:0}]:[tp_omniture:lowercase:{current-page:url-arg:1}]
s.prop3 = [tp_omniture:lowercase:{current-page:url-arg:0}]:[tp_omniture:lowercase:{current-page:url-arg:1}]:[tp_omniture:lowercase:{current-page:url-arg:2}]
s.prop7 =[current-user:uid]
s.prop20 = [tp_omniture:stringfixes:{current-page:title}]',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Omniture');
  t('Variables set on user profile pages');
  $export['omniture_user_profile'] = $context;

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
  $context->condition_mode = 1;
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
        'bean-tpl-live-long' => array(
          'module' => 'bean',
          'delta' => 'tpl-live-long',
          'region' => 'sidebar',
          'weight' => '-9',
        ),
        'bean--of-the-day' => array(
          'module' => 'bean',
          'delta' => '-of-the-day',
          'region' => 'sidebar',
          'weight' => '-4',
        ),
      ),
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
        'campaign_card_branding' => 'campaign_card_branding',
        'campaign_card_empty' => 'campaign_card_empty',
        'campaign_card_iframe' => 'campaign_card_iframe',
        'campaign_card_media' => 'campaign_card_media',
        'campaign_card_news' => 'campaign_card_news',
        'campaign_card_social' => 'campaign_card_social',
        'campaign_card_text' => 'campaign_card_text',
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
        'pm_interstitial-interstitials' => array(
          'module' => 'pm_interstitial',
          'delta' => 'interstitials',
          'region' => 'suffix',
          'weight' => '-10',
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
          'weight' => '-10',
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
        'bean-tpl-live-long' => array(
          'module' => 'bean',
          'delta' => 'tpl-live-long',
          'region' => 'sidebar',
          'weight' => '-9',
        ),
        'newsletter_campaign-48' => array(
          'module' => 'newsletter_campaign',
          'delta' => '48',
          'region' => 'sidebar',
          'weight' => '-8',
        ),
        'boxes-box-1104adce' => array(
          'module' => 'boxes',
          'delta' => 'box-1104adce',
          'region' => 'sidebar',
          'weight' => '-7',
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
  $context->name = 'tp4_video';
  $context->description = 'Right rail content for TP4 videos (plus leaderboard)';
  $context->tag = 'TP4';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'video' => 'video',
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
        'bean-tpl-live-long' => array(
          'module' => 'bean',
          'delta' => 'tpl-live-long',
          'region' => 'sidebar',
          'weight' => '-9',
        ),
        'newsletter_campaign-51' => array(
          'module' => 'newsletter_campaign',
          'delta' => '51',
          'region' => 'sidebar',
          'weight' => '-8',
        ),
        'boxes-right_rail_video_promo_articles' => array(
          'module' => 'boxes',
          'delta' => 'right_rail_video_promo_articles',
          'region' => 'sidebar',
          'weight' => '-6',
        ),
        'boxes-box-1104adce' => array(
          'module' => 'boxes',
          'delta' => 'box-1104adce',
          'region' => 'sidebar',
          'weight' => '-5',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Right rail content for TP4 videos (plus leaderboard)');
  t('TP4');
  $export['tp4_video'] = $context;

  return $export;
}
