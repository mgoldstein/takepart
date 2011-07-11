<?php
/**
 * @file
 * takepart_author.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function takepart_author_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'author_contributions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Author Contributions';
  $view->core = 7;
  $view->api_version = '3.0-rc1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Author Contributions';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Fields: Author(s) (field_author) - nid */
  $handler->display->display_options['arguments']['field_author_nid']['id'] = 'field_author_nid';
  $handler->display->display_options['arguments']['field_author_nid']['table'] = 'field_data_field_author';
  $handler->display->display_options['arguments']['field_author_nid']['field'] = 'field_author_nid';
  $handler->display->display_options['arguments']['field_author_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_author_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_author_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_author_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_author_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_author_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_author_nid']['not'] = 0;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'openpublish_article' => 'openpublish_article',
    'openpublish_blog_post' => 'openpublish_blog_post',
    'openpublish_photo_gallery' => 'openpublish_photo_gallery',
    'openpublish_video' => 'openpublish_video',
    'takepart_page' => 'takepart_page',
    'video_series' => 'video_series',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'author-contributions';
  $translatables['author_contributions'] = array(
    t('Master'),
    t('Author Contributions'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('All'),
    t('Page'),
  );
  $export['author_contributions'] = $view;

  return $export;
}
