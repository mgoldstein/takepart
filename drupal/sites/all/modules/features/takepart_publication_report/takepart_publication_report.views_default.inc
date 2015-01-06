<?php
/**
 * @file
 * takepart_publication_report.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function takepart_publication_report_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'publication_report';
  $view->description = 'Form for finding content published between specified dates';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Publication Report';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Publication Report';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    7 => '7',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'published_at' => 'published_at',
    'title' => 'title',
    'type' => 'type',
  );
  $handler->display->display_options['row_options']['separator'] = ' -- ';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Instructions';
  $handler->display->display_options['header']['area']['content'] = '<p>Publication dates are stored with the time down to the second, so exact matches on a date value will not return any results.
Instead, select two dates to search for all content published between those dates. Set the date range below using YYYY-MM-DD format.</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '<h3>Total Results: @total</h3>';
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['label'] = 'Total Results';
  $handler->display->display_options['footer']['result']['content'] = '<br><p>Total Results: @total</p>';
  /* Field: Node: Published at */
  $handler->display->display_options['fields']['published_at']['id'] = 'published_at';
  $handler->display->display_options['fields']['published_at']['table'] = 'publication_date';
  $handler->display->display_options['fields']['published_at']['field'] = 'published_at';
  $handler->display->display_options['fields']['published_at']['label'] = '';
  $handler->display->display_options['fields']['published_at']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['published_at']['date_format'] = 'short';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Node: Published at */
  $handler->display->display_options['sorts']['published_at']['id'] = 'published_at';
  $handler->display->display_options['sorts']['published_at']['table'] = 'publication_date';
  $handler->display->display_options['sorts']['published_at']['field'] = 'published_at';
  $handler->display->display_options['sorts']['published_at']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['published_at']['expose']['label'] = 'Published at';
  $handler->display->display_options['sorts']['published_at']['granularity'] = 'day';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Title';
  /* Sort criterion: Content: Type */
  $handler->display->display_options['sorts']['type']['id'] = 'type';
  $handler->display->display_options['sorts']['type']['table'] = 'node';
  $handler->display->display_options['sorts']['type']['field'] = 'type';
  $handler->display->display_options['sorts']['type']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['type']['expose']['label'] = 'Type';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'openpublish_article' => 'openpublish_article',
    'campaign' => 'campaign',
    'feature_article' => 'feature_article',
    'flashcard' => 'flashcard',
    'takepart_campaign' => 'takepart_campaign',
    'takepart_page' => 'takepart_page',
    'openpublish_photo_gallery' => 'openpublish_photo_gallery',
    'video' => 'video',
    'video_playlist' => 'video_playlist',
  );
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Content Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => 0,
    5 => '5',
    6 => '6',
    7 => '7',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['type']['group_info']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['group_info']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['type']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Node: Published at */
  $handler->display->display_options['filters']['published_at']['id'] = 'published_at';
  $handler->display->display_options['filters']['published_at']['table'] = 'publication_date';
  $handler->display->display_options['filters']['published_at']['field'] = 'published_at';
  $handler->display->display_options['filters']['published_at']['operator'] = 'between';
  $handler->display->display_options['filters']['published_at']['value']['min'] = '2014-01-01';
  $handler->display->display_options['filters']['published_at']['value']['max'] = '2014-01-02';
  $handler->display->display_options['filters']['published_at']['exposed'] = TRUE;
  $handler->display->display_options['filters']['published_at']['expose']['operator_id'] = 'published_at_op';
  $handler->display->display_options['filters']['published_at']['expose']['label'] = 'Published between';
  $handler->display->display_options['filters']['published_at']['expose']['operator'] = 'published_at_op';
  $handler->display->display_options['filters']['published_at']['expose']['identifier'] = 'published_at';
  $handler->display->display_options['filters']['published_at']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['published_at']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['published_at']['expose']['remember_roles'] = array(
    2 => 0,
    5 => '5',
    6 => '6',
    7 => '7',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Field: Topic (field_topic) */
  $handler->display->display_options['filters']['field_topic_tid']['id'] = 'field_topic_tid';
  $handler->display->display_options['filters']['field_topic_tid']['table'] = 'field_data_field_topic';
  $handler->display->display_options['filters']['field_topic_tid']['field'] = 'field_topic_tid';
  $handler->display->display_options['filters']['field_topic_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_topic_tid']['expose']['operator_id'] = 'field_topic_tid_op';
  $handler->display->display_options['filters']['field_topic_tid']['expose']['label'] = 'Primary Topic';
  $handler->display->display_options['filters']['field_topic_tid']['expose']['operator'] = 'field_topic_tid_op';
  $handler->display->display_options['filters']['field_topic_tid']['expose']['identifier'] = 'field_topic_tid';
  $handler->display->display_options['filters']['field_topic_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_topic_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_topic_tid']['vocabulary'] = 'topic';
  /* Filter criterion: Content: Author(s) (field_author) */
  $handler->display->display_options['filters']['field_author_nid']['id'] = 'field_author_nid';
  $handler->display->display_options['filters']['field_author_nid']['table'] = 'field_data_field_author';
  $handler->display->display_options['filters']['field_author_nid']['field'] = 'field_author_nid';
  $handler->display->display_options['filters']['field_author_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_author_nid']['expose']['operator_id'] = 'field_author_nid_op';
  $handler->display->display_options['filters']['field_author_nid']['expose']['label'] = 'Author(s)';
  $handler->display->display_options['filters']['field_author_nid']['expose']['operator'] = 'field_author_nid_op';
  $handler->display->display_options['filters']['field_author_nid']['expose']['identifier'] = 'field_author_nid';
  $handler->display->display_options['filters']['field_author_nid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_author_nid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_author_nid']['expose']['remember_roles'] = array(
    2 => 0,
    6 => '6',
    7 => '7',
    1 => 0,
    3 => 0,
    5 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'reports/publication-report';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%exposed-Publication_Report.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Node: Published at */
  $handler->display->display_options['fields']['published_at']['id'] = 'published_at';
  $handler->display->display_options['fields']['published_at']['table'] = 'publication_date';
  $handler->display->display_options['fields']['published_at']['field'] = 'published_at';
  $handler->display->display_options['fields']['published_at']['label'] = '';
  $handler->display->display_options['fields']['published_at']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['published_at']['date_format'] = 'short';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Field: Topic */
  $handler->display->display_options['fields']['field_topic']['id'] = 'field_topic';
  $handler->display->display_options['fields']['field_topic']['table'] = 'field_data_field_topic';
  $handler->display->display_options['fields']['field_topic']['field'] = 'field_topic';
  $handler->display->display_options['fields']['field_topic']['label'] = '';
  $handler->display->display_options['fields']['field_topic']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_topic']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_topic']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_topic']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['path'] = 'reports/publication-report/export';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $export['publication_report'] = $view;

  return $export;
}
