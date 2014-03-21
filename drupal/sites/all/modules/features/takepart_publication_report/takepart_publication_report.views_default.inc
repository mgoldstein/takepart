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
  $view->description = '';
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
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
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
  $handler->display->display_options['sorts']['published_at']['order'] = 'DESC';
  $handler->display->display_options['sorts']['published_at']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['published_at']['expose']['label'] = 'Published at';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Title';
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
    'feature_article' => 'feature_article',
    'openpublish_photo_gallery' => 'openpublish_photo_gallery',
    'video' => 'video',
  );
  /* Filter criterion: Node: Published at */
  $handler->display->display_options['filters']['published_at']['id'] = 'published_at';
  $handler->display->display_options['filters']['published_at']['table'] = 'publication_date';
  $handler->display->display_options['filters']['published_at']['field'] = 'published_at';
  $handler->display->display_options['filters']['published_at']['operator'] = 'between';
  $handler->display->display_options['filters']['published_at']['value']['min'] = '2014-01-30';
  $handler->display->display_options['filters']['published_at']['value']['max'] = '2014-01-31';
  $handler->display->display_options['filters']['published_at']['value']['value'] = '2014-01-06';
  $handler->display->display_options['filters']['published_at']['exposed'] = TRUE;
  $handler->display->display_options['filters']['published_at']['expose']['operator_id'] = 'published_at_op';
  $handler->display->display_options['filters']['published_at']['expose']['label'] = 'Published at';
  $handler->display->display_options['filters']['published_at']['expose']['description'] = 'Date the content was published';
  $handler->display->display_options['filters']['published_at']['expose']['use_operator'] = TRUE;
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'reports/publication-report';
  $export['publication_report'] = $view;

  return $export;
}
