<?php
/**
 * @file
 * takepart_topics.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function takepart_topics_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'terms_posts_feed_rss';
  $view->description = '';
  $view->tag = 'takepart_feed';
  $view->base_table = 'node';
  $view->human_name = 'Terms Posts Feed';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'TakePart Blogs Feed';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['slave'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_takepart_rss_style';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'D, d M Y H:i:s T';
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_blogpost_main_image']['id'] = 'field_blogpost_main_image';
  $handler->display->display_options['fields']['field_blogpost_main_image']['table'] = 'field_data_field_blogpost_main_image';
  $handler->display->display_options['fields']['field_blogpost_main_image']['field'] = 'field_blogpost_main_image';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Field: Topic (field_topic) */
  $handler->display->display_options['arguments']['field_topic_tid']['id'] = 'field_topic_tid';
  $handler->display->display_options['arguments']['field_topic_tid']['table'] = 'field_data_field_topic';
  $handler->display->display_options['arguments']['field_topic_tid']['field'] = 'field_topic_tid';
  $handler->display->display_options['arguments']['field_topic_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_topic_tid']['summary']['format'] = 'default_summary';
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
    'action' => 'action',
    'openpublish_article' => 'openpublish_article',
    'audio' => 'audio',
    'openpublish_blog_post' => 'openpublish_blog_post',
    'openpublish_photo_gallery' => 'openpublish_photo_gallery',
    'openpublish_video' => 'openpublish_video',
  );

  /* Display: Blog Feed (old) */
  $handler = $view->new_display('feed', 'Blog Feed (old)', 'feed_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['row_options']['item_length'] = 'title';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Blog (field_blogpost_blog) */
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['id'] = 'field_blogpost_blog_tid';
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['table'] = 'field_data_field_blogpost_blog';
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['field'] = 'field_blogpost_blog_tid';
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['not'] = 0;
  $handler->display->display_options['path'] = 'blog/%/feed_old.xml';
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: Series Feed (old) */
  $handler = $view->new_display('feed', 'Series Feed (old)', 'feed_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'TakePart Series Feed';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['row_options']['item_length'] = 'title';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Series (field_series) */
  $handler->display->display_options['arguments']['field_series_tid']['id'] = 'field_series_tid';
  $handler->display->display_options['arguments']['field_series_tid']['table'] = 'field_data_field_series';
  $handler->display->display_options['arguments']['field_series_tid']['field'] = 'field_series_tid';
  $handler->display->display_options['arguments']['field_series_tid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_series_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_series_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_series_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_series_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_series_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_series_tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_series_tid']['not'] = 0;
  $handler->display->display_options['path'] = 'series/%/feed_old.xml';
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: Video Series Feed (old) */
  $handler = $view->new_display('feed', 'Video Series Feed (old)', 'feed_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'TakePart Video Series Feed';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['row_options']['item_length'] = 'title';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Video Series (field_video_series) */
  $handler->display->display_options['arguments']['field_video_series_tid']['id'] = 'field_video_series_tid';
  $handler->display->display_options['arguments']['field_video_series_tid']['table'] = 'field_data_field_video_series';
  $handler->display->display_options['arguments']['field_video_series_tid']['field'] = 'field_video_series_tid';
  $handler->display->display_options['arguments']['field_video_series_tid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_video_series_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_video_series_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_video_series_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_video_series_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_video_series_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_video_series_tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_video_series_tid']['not'] = 0;
  $handler->display->display_options['path'] = 'video-series/%/feed_old.xml';
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: Topic Feed (old) */
  $handler = $view->new_display('feed', 'Topic Feed (old)', 'feed_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'TakePart Topic Feed';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['row_options']['item_length'] = 'title';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Topic (field_topic) */
  $handler->display->display_options['arguments']['field_topic_tid']['id'] = 'field_topic_tid';
  $handler->display->display_options['arguments']['field_topic_tid']['table'] = 'field_data_field_topic';
  $handler->display->display_options['arguments']['field_topic_tid']['field'] = 'field_topic_tid';
  $handler->display->display_options['arguments']['field_topic_tid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_topic_tid']['title_enable'] = 1;
  $handler->display->display_options['arguments']['field_topic_tid']['title'] = '%1';
  $handler->display->display_options['arguments']['field_topic_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_topic_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_topic_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_topic_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_topic_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_topic_tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_topic_tid']['not'] = 0;
  $handler->display->display_options['path'] = 'topic/%/feed_old.xml';
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: Blog Feed Page */
  $handler = $view->new_display('page', 'Blog Feed Page', 'blog_feeds');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_takepart_rss_style';
  $handler->display->display_options['style_options']['schema'] = 'rssimages';
  $handler->display->display_options['style_options']['title'] = 'TakePart: ';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_blogpost_main_image']['id'] = 'field_blogpost_main_image';
  $handler->display->display_options['fields']['field_blogpost_main_image']['table'] = 'field_data_field_blogpost_main_image';
  $handler->display->display_options['fields']['field_blogpost_main_image']['field'] = 'field_blogpost_main_image';
  $handler->display->display_options['fields']['field_blogpost_main_image']['label'] = 'Blogs Main Image';
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_blogpost_main_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_blogpost_main_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_blogpost_main_image']['type'] = 'image';
  $handler->display->display_options['fields']['field_blogpost_main_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_blogpost_main_image']['field_api_classes'] = 0;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'D, d M Y H:i:s T';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Blog (field_blogpost_blog) */
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['id'] = 'field_blogpost_blog_tid';
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['table'] = 'field_data_field_blogpost_blog';
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['field'] = 'field_blogpost_blog_tid';
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'openpublish_blog_post' => 'openpublish_blog_post',
  );
  $handler->display->display_options['path'] = 'blog/%/feed.xml';

  /* Display: Series Feed Page */
  $handler = $view->new_display('page', 'Series Feed Page', 'series_feeds');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'TakePart Series Feed';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_takepart_rss_style';
  $handler->display->display_options['style_options']['schema'] = 'rssimages';
  $handler->display->display_options['style_options']['title'] = 'TakePart: ';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'D, d M Y H:i:s T';
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_blogpost_main_image']['id'] = 'field_blogpost_main_image';
  $handler->display->display_options['fields']['field_blogpost_main_image']['table'] = 'field_data_field_blogpost_main_image';
  $handler->display->display_options['fields']['field_blogpost_main_image']['field'] = 'field_blogpost_main_image';
  $handler->display->display_options['fields']['field_blogpost_main_image']['label'] = 'Blog Main Image';
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_blogpost_main_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_blogpost_main_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_blogpost_main_image']['type'] = 'image';
  $handler->display->display_options['fields']['field_blogpost_main_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_blogpost_main_image']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Series (field_series) */
  $handler->display->display_options['arguments']['field_series_tid']['id'] = 'field_series_tid';
  $handler->display->display_options['arguments']['field_series_tid']['table'] = 'field_data_field_series';
  $handler->display->display_options['arguments']['field_series_tid']['field'] = 'field_series_tid';
  $handler->display->display_options['arguments']['field_series_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_series_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_series_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_series_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_series_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_series_tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_series_tid']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  );
  $handler->display->display_options['path'] = 'series/%/feed.xml ';

  /* Display: Video Series Feed Page */
  $handler = $view->new_display('page', 'Video Series Feed Page', 'video_feeds');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_takepart_rss_style';
  $handler->display->display_options['style_options']['schema'] = 'rssimages';
  $handler->display->display_options['style_options']['title'] = 'TakePart: ';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'D, d M Y H:i:s T';
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_blogpost_main_image']['id'] = 'field_blogpost_main_image';
  $handler->display->display_options['fields']['field_blogpost_main_image']['table'] = 'field_data_field_blogpost_main_image';
  $handler->display->display_options['fields']['field_blogpost_main_image']['field'] = 'field_blogpost_main_image';
  $handler->display->display_options['fields']['field_blogpost_main_image']['label'] = 'Blog Main Image';
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_blogpost_main_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_blogpost_main_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_blogpost_main_image']['type'] = 'image';
  $handler->display->display_options['fields']['field_blogpost_main_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_blogpost_main_image']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Video Series (field_video_series) */
  $handler->display->display_options['arguments']['field_video_series_tid']['id'] = 'field_video_series_tid';
  $handler->display->display_options['arguments']['field_video_series_tid']['table'] = 'field_data_field_video_series';
  $handler->display->display_options['arguments']['field_video_series_tid']['field'] = 'field_video_series_tid';
  $handler->display->display_options['arguments']['field_video_series_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_video_series_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_video_series_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_video_series_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_video_series_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_video_series_tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_video_series_tid']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'openpublish_video' => 'openpublish_video',
  );
  $handler->display->display_options['path'] = 'video-series/%/feed.xml';

  /* Display: Topic Feed Page */
  $handler = $view->new_display('page', 'Topic Feed Page', 'topic_feeds');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'TakePart Topic Feed ';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_takepart_rss_style';
  $handler->display->display_options['style_options']['schema'] = 'rssimages';
  $handler->display->display_options['style_options']['title'] = 'TakePart: ';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'D, d M Y H:i:s T';
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_blogpost_main_image']['id'] = 'field_blogpost_main_image';
  $handler->display->display_options['fields']['field_blogpost_main_image']['table'] = 'field_data_field_blogpost_main_image';
  $handler->display->display_options['fields']['field_blogpost_main_image']['field'] = 'field_blogpost_main_image';
  $handler->display->display_options['fields']['field_blogpost_main_image']['label'] = 'Blog Main Image';
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_blogpost_main_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_blogpost_main_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_blogpost_main_image']['type'] = 'image';
  $handler->display->display_options['fields']['field_blogpost_main_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_blogpost_main_image']['field_api_classes'] = 0;
  /* Field: Content: Promo Text */
  $handler->display->display_options['fields']['field_promo_text']['id'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['table'] = 'field_data_field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['field'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_promo_text']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_promo_text']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_promo_text']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_promo_text']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Topic (field_topic) */
  $handler->display->display_options['arguments']['field_topic_tid']['id'] = 'field_topic_tid';
  $handler->display->display_options['arguments']['field_topic_tid']['table'] = 'field_data_field_topic';
  $handler->display->display_options['arguments']['field_topic_tid']['field'] = 'field_topic_tid';
  $handler->display->display_options['arguments']['field_topic_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_topic_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_topic_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_topic_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_topic_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_topic_tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_topic_tid']['not'] = 0;
  $handler->display->display_options['path'] = 'topic/%/feed.xml';
  $export['terms_posts_feed_rss'] = $view;

  return $export;
}
