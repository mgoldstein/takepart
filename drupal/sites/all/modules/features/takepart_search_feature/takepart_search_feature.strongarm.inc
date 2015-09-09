<?php
/**
 * @file
 * takepart_search_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function takepart_search_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_active_modules';
  $strongarm->value = array(
    'node' => 'node',
    'file_entity' => 0,
    'user' => 0,
  );
  $export['search_active_modules'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_api_facets_search_ids';
  $strongarm->value = array(
    'standard_node_index' => array(
      'search_api_views:taxonomy_search_list' => 'search_api_views:taxonomy_search_list',
      'search_api_views:taxonomy_search_list:block' => 'search_api_views:taxonomy_search_list:block',
      'search_api_views:taxonomy_search_list:block_2' => 'search_api_views:taxonomy_search_list:block_2',
      'search_api_views:taxonomy_search_list:block_1' => 'search_api_views:taxonomy_search_list:block_1',
    ),
    'site_node_index' => array(
      'search_api_page:search' => 'search_api_page:search',
      'search_api_views:taxonomy_search_list:block' => 'search_api_views:taxonomy_search_list:block',
      'search_api_views:taxonomy_search_list:block_1' => 'search_api_views:taxonomy_search_list:block_1',
      'search_api_views:taxonomy_search_list:block_2' => 'search_api_views:taxonomy_search_list:block_2',
      'search_api_views:taxonomy_search_list:page_1' => 'search_api_views:taxonomy_search_list:page_1',
      'search_api_views:taxonomy_search_list:tag_feeds' => 'search_api_views:taxonomy_search_list:tag_feeds',
      'search_api_views:taxonomy_search_list:block_3' => 'search_api_views:taxonomy_search_list:block_3',
    ),
  );
  $export['search_api_facets_search_ids'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_api_sorts_default_order';
  $strongarm->value = 'desc';
  $export['search_api_sorts_default_order'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_api_sorts_default_sort';
  $strongarm->value = 'created';
  $export['search_api_sorts_default_sort'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_cron_limit';
  $strongarm->value = '20';
  $export['search_cron_limit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_default_module';
  $strongarm->value = 'node';
  $export['search_default_module'] = $strongarm;

  return $export;
}
