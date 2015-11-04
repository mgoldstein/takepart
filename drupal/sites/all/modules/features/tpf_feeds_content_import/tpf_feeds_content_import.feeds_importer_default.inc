<?php
/**
 * @file
 * tpf_feeds_content_import.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function tpf_feeds_content_import_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_articles';
  $feeds_importer->config = array(
    'name' => 'Import Articles',
    'description' => 'For importing TakePart articles',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'direct' => FALSE,
        'allowed_extensions' => 'txt csv tsv xml opml',
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'bundle' => 'openpublish_article',
        'update_existing' => '0',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'nid',
            'target' => 'nid',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'permanent title',
            'target' => 'field_permanent_title',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'subhead',
            'target' => 'field_article_subhead',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'author',
            'target' => 'field_author:nid',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'body',
            'target' => 'body',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'inline replacements',
            'target' => 'field_inline_replacements:etid',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'related stories',
            'target' => 'field_related_stories:nid',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'related stories',
            'target' => 'field_tab_action_override:nid',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'promo headline',
            'target' => 'field_promo_headline',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'short headline',
            'target' => 'field_promo_short_headline',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'promo text',
            'target' => 'field_promo_text',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'status',
            'target' => 'status',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'published',
            'target' => 'created',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'path',
            'target' => 'path_alias',
            'pathauto_override' => 1,
          ),
          16 => array(
            'source' => 'admin tag',
            'target' => 'field_admin_tag',
            'term_search' => '1',
            'autocreate' => 0,
          ),
          17 => array(
            'source' => 'free tag',
            'target' => 'field_free_tag',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          18 => array(
            'source' => 'series',
            'target' => 'field_series',
            'term_search' => '1',
            'autocreate' => 0,
          ),
          19 => array(
            'source' => 'sponsored',
            'target' => 'field_sponsored',
            'term_search' => '1',
            'autocreate' => 0,
          ),
          20 => array(
            'source' => 'topic',
            'target' => 'field_topic',
            'term_search' => '1',
            'autocreate' => 0,
          ),
        ),
        'input_format' => 'full_html',
        'author' => '179962',
        'authorize' => 0,
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['import_articles'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_author_profiles';
  $feeds_importer->config = array(
    'name' => 'Import Author Profiles',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'direct' => FALSE,
        'allowed_extensions' => 'txt csv tsv xml opml',
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'bundle' => 'profile',
        'update_existing' => '0',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'nid',
            'target' => 'nid',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'HTML title tag',
            'target' => 'field_html_title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'permanent title',
            'target' => 'field_permanent_title',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'first name',
            'target' => 'field_profile_first_name',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'last name',
            'target' => 'field_profile_last_name',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'organization',
            'target' => 'field_profile_organization',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'summary',
            'target' => 'body:summary',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'body',
            'target' => 'body',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'photo',
            'target' => 'field_profile_photo',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'email',
            'target' => 'field_profile_email',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'follow me google',
            'target' => 'field_follow_google:title',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'google url',
            'target' => 'field_follow_google:url',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'follow me twitter',
            'target' => 'field_follow_twitter:title',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'twitter url',
            'target' => 'field_follow_twitter:url',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'published',
            'target' => 'status',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'path',
            'target' => 'path_alias',
            'unique' => FALSE,
          ),
        ),
        'input_format' => 'full_html',
        'author' => '179962',
        'authorize' => 0,
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['import_author_profiles'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_former_editors';
  $feeds_importer->config = array(
    'name' => 'Import Former Editors',
    'description' => 'Import user accounts for former TakePart editors',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'direct' => FALSE,
        'allowed_extensions' => 'txt csv tsv xml opml',
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsUserProcessor',
      'config' => array(
        'roles' => array(
          3 => 0,
          8 => 0,
          5 => 0,
          6 => 0,
          7 => 0,
        ),
        'update_existing' => '0',
        'status' => '0',
        'mappings' => array(
          0 => array(
            'source' => 'uid',
            'target' => 'uid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'name',
            'target' => 'name',
            'unique' => 0,
          ),
          2 => array(
            'source' => 'mail',
            'target' => 'mail',
            'unique' => 1,
          ),
          3 => array(
            'source' => 'created',
            'target' => 'created',
            'unique' => FALSE,
          ),
        ),
        'defuse_mail' => 0,
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'user',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['import_former_editors'] = $feeds_importer;

  return $export;
}
