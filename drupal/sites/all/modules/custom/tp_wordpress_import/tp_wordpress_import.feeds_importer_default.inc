<?php
/**
 * @file
 * tp_wordpress_import.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function tp_wordpress_import_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'takepart_wordpress_xml';
  $feeds_importer->config = array(
    'name' => 'Takepart - Wordpress XML',
    'description' => 'Allows Takepart to injest a XML from Wordpress. Note that some items are coded into the parser.',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'xml',
        'direct' => 0,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          'public' => 'public',
          'private' => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'tp_wordpress_import_xml_parser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '36759',
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'admin_tag',
            'target' => 'field_admin_tag',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'tagging',
            'target' => 'field_topic',
            'term_search' => '0',
            'autocreate' => 0,
          ),
          3 => array(
            'source' => 'title',
            'target' => 'field_permanent_title',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'content',
            'target' => 'body',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'title',
            'target' => 'field_promo_headline',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'title',
            'target' => 'field_promo_short_headline',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'author',
            'target' => 'field_author:nid',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'openpublish_article',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['takepart_wordpress_xml'] = $feeds_importer;

  return $export;
}
