<?php
/**
 * @file
 * tpf_display_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function tpf_display_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'author_contributions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Author Contributions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Author Contributions';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['slave'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Field: Thumbnail Image */
  $handler->display->display_options['fields']['field_thumbnail']['id'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['table'] = 'field_data_field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['field'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_thumbnail']['element_class'] = 'float-right';
  $handler->display->display_options['fields']['field_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_thumbnail']['type'] = 'image';
  $handler->display->display_options['fields']['field_thumbnail']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['hide_alter_empty'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_class'] = 'view-article-date';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'M j Y';
  /* Field: Field: Promo Headline */
  $handler->display->display_options['fields']['field_promo_headline']['id'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['table'] = 'field_data_field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['field'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['label'] = '';
  $handler->display->display_options['fields']['field_promo_headline']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_promo_headline']['element_type'] = 'h3';
  $handler->display->display_options['fields']['field_promo_headline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_headline']['empty'] = '[title]';
  $handler->display->display_options['fields']['field_promo_headline']['hide_alter_empty'] = FALSE;
  /* Field: Field: Promo Text */
  $handler->display->display_options['fields']['field_promo_text']['id'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['table'] = 'field_data_field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['field'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['label'] = '';
  $handler->display->display_options['fields']['field_promo_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_text']['hide_alter_empty'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Author(s) (field_author) */
  $handler->display->display_options['arguments']['field_author_nid']['id'] = 'field_author_nid';
  $handler->display->display_options['arguments']['field_author_nid']['table'] = 'field_data_field_author';
  $handler->display->display_options['arguments']['field_author_nid']['field'] = 'field_author_nid';
  $handler->display->display_options['arguments']['field_author_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_author_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_author_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_author_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_author_nid']['summary_options']['items_per_page'] = '25';
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
    'feature_article' => 'feature_article',
    'openpublish_video' => 'openpublish_video',
    'takepart_page' => 'takepart_page',
    'openpublish_photo_gallery' => 'openpublish_photo_gallery',
    'video' => 'video',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'author-contributions';

  /* Display: Author Contributions Block */
  $handler = $view->new_display('block', 'Author Contributions Block', 'block');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'view-author-contributions';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = 'First';
  $handler->display->display_options['pager']['options']['tags']['previous'] = 'Previous';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'Next';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'Last';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Field: Thumbnail Image */
  $handler->display->display_options['fields']['field_thumbnail']['id'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['table'] = 'field_data_field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['field'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_thumbnail']['type'] = 'image';
  $handler->display->display_options['fields']['field_thumbnail']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['hide_alter_empty'] = FALSE;
  /* Field: Field: Promo Headline */
  $handler->display->display_options['fields']['field_promo_headline']['id'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['table'] = 'field_data_field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['field'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['label'] = '';
  $handler->display->display_options['fields']['field_promo_headline']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_promo_headline']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_promo_headline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_headline']['empty'] = '[title]';
  $handler->display->display_options['fields']['field_promo_headline']['hide_alter_empty'] = FALSE;
  /* Field: Field: Promo Text */
  $handler->display->display_options['fields']['field_promo_text']['id'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['table'] = 'field_data_field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['field'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['label'] = '';
  $handler->display->display_options['fields']['field_promo_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_text']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['block_description'] = 'Contributions';
  $export['author_contributions'] = $view;

  $view = new view();
  $view->name = 'campaign_spotlight_nodes';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Campaign Spotlight Nodes';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  /* Field: Field: Promo Headline */
  $handler->display->display_options['fields']['field_promo_headline']['id'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['table'] = 'field_data_field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['field'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['label'] = '';
  $handler->display->display_options['fields']['field_promo_headline']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_promo_headline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_headline']['hide_alter_empty'] = FALSE;
  /* Field: Field: Promo Text */
  $handler->display->display_options['fields']['field_promo_text']['id'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['table'] = 'field_data_field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['field'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['label'] = '';
  $handler->display->display_options['fields']['field_promo_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_text']['hide_alter_empty'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Promo Display */
  $handler = $view->new_display('block', 'Promo Display', 'block_1');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'field';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['field'] = 'nodereference::field_tp_campaign_sl_nodes';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['settings'] = array(
    'argument_default_field_nodereference_format' => 'nid',
    'argument_default_field_nodereference_delta' => '0',
  );
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $export['campaign_spotlight_nodes'] = $view;

  $view = new view();
  $view->name = 'campaigns';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Campaigns';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Campaigns';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['slave'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Sort criterion: Arguments: Multi-item Argument Order */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'views_sort_by_arg_order';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['order'] = 'DESC';
  $handler->display->display_options['sorts']['weight']['argument_number'] = '0';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
  /* Contextual filter: Featured Campaigns */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['ui_name'] = 'Featured Campaigns';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
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
    'takepart_campaign' => 'takepart_campaign',
  );

  /* Display: List of Campaigns */
  $handler = $view->new_display('block', 'List of Campaigns', 'block');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '1';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Featured Campaigns (Excluded) */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['ui_name'] = 'Featured Campaigns (Excluded)';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  $handler->display->display_options['arguments']['nid']['not'] = TRUE;

  /* Display: Featured Campaigns */
  $handler = $view->new_display('block', 'Featured Campaigns', 'block_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['id'] = 'field_tp_campaign_cover_image';
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['table'] = 'field_data_field_tp_campaign_cover_image';
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['field'] = 'field_tp_campaign_cover_image';
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['label'] = '';
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['type'] = 'image';
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['settings'] = array(
    'image_style' => 'tp_campaign_cover',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Sub Headline */
  $handler->display->display_options['fields']['field_tp_campaign_subheadline']['id'] = 'field_tp_campaign_subheadline';
  $handler->display->display_options['fields']['field_tp_campaign_subheadline']['table'] = 'field_data_field_tp_campaign_subheadline';
  $handler->display->display_options['fields']['field_tp_campaign_subheadline']['field'] = 'field_tp_campaign_subheadline';
  $handler->display->display_options['fields']['field_tp_campaign_subheadline']['label'] = '';
  $handler->display->display_options['fields']['field_tp_campaign_subheadline']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;

  /* Display: Featured Campaigns Basic */
  $handler = $view->new_display('block', 'Featured Campaigns Basic', 'block_2');
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Arguments: Multi-item Argument Order */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'views_sort_by_arg_order';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['order'] = 'DESC';
  $handler->display->display_options['sorts']['weight']['argument_number'] = '0';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Featured Campaigns */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['ui_name'] = 'Featured Campaigns';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  $handler->display->display_options['block_description'] = 'All Participant Media Films';
  $export['campaigns'] = $view;

  $view = new view();
  $view->name = 'content_types_posts_feed';
  $view->description = 'TakePart.com RSS feed filtered by content type';
  $view->tag = 'takepart_feed';
  $view->base_table = 'node';
  $view->human_name = 'RSS Feed by Content Type';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_inline_replacements_target_id']['id'] = 'field_inline_replacements_target_id';
  $handler->display->display_options['relationships']['field_inline_replacements_target_id']['table'] = 'field_data_field_inline_replacements';
  $handler->display->display_options['relationships']['field_inline_replacements_target_id']['field'] = 'field_inline_replacements_target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Action Header Image */
  $handler->display->display_options['fields']['field_actionheaderimg']['id'] = 'field_actionheaderimg';
  $handler->display->display_options['fields']['field_actionheaderimg']['table'] = 'field_data_field_actionheaderimg';
  $handler->display->display_options['fields']['field_actionheaderimg']['field'] = 'field_actionheaderimg';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Type */
  $handler->display->display_options['arguments']['type']['id'] = 'type';
  $handler->display->display_options['arguments']['type']['table'] = 'node';
  $handler->display->display_options['arguments']['type']['field'] = 'type';
  $handler->display->display_options['arguments']['type']['default_action'] = 'default';
  $handler->display->display_options['arguments']['type']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['type']['default_argument_options']['argument'] = 'all';
  $handler->display->display_options['arguments']['type']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['type']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['type']['summary_options']['items_per_page'] = '25';
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
    'campaign' => 'campaign',
    'feature_article' => 'feature_article',
    'flashcard' => 'flashcard',
    'openpublish_photo_gallery' => 'openpublish_photo_gallery',
    'video' => 'video',
    'video_playlist' => 'video_playlist',
  );

  /* Display: Short Feed */
  $handler = $view->new_display('page', 'Short Feed', 'page_1');
  $handler->display->display_options['display_description'] = 'Feed of brief descriptions filtered by content type';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_takepart_rss_style';
  $handler->display->display_options['style_options']['schema'] = 'rssimages';
  $handler->display->display_options['style_options']['title'] = 'TAKEPART';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Display Tag */
  $handler->display->display_options['fields']['field_display_tag']['id'] = 'field_display_tag';
  $handler->display->display_options['fields']['field_display_tag']['table'] = 'field_data_field_display_tag';
  $handler->display->display_options['fields']['field_display_tag']['field'] = 'field_display_tag';
  $handler->display->display_options['fields']['field_display_tag']['label'] = '';
  $handler->display->display_options['fields']['field_display_tag']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_display_tag']['alter']['text'] = '<br> [field_display_tag]';
  $handler->display->display_options['fields']['field_display_tag']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_tag']['hide_alter_empty'] = FALSE;
  /* Field: Field: Thumbnail Image */
  $handler->display->display_options['fields']['field_thumbnail']['id'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['table'] = 'field_data_field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['field'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_thumbnail']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_thumbnail']['alter']['text'] = '[field_thumbnail-fid]';
  $handler->display->display_options['fields']['field_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_thumbnail']['type'] = 'image';
  $handler->display->display_options['fields']['field_thumbnail']['settings'] = array(
    'image_style' => 'large',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_thumbnail']['group_column'] = 'fid';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'D, d M Y H:i:s T';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Author(s) */
  $handler->display->display_options['fields']['field_author']['id'] = 'field_author';
  $handler->display->display_options['fields']['field_author']['table'] = 'field_data_field_author';
  $handler->display->display_options['fields']['field_author']['field'] = 'field_author';
  $handler->display->display_options['fields']['field_author']['label'] = '';
  $handler->display->display_options['fields']['field_author']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_author']['type'] = 'node_reference_plain';
  $handler->display->display_options['fields']['field_author']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Promo Text */
  $handler->display->display_options['fields']['field_promo_text']['id'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['table'] = 'field_data_field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['field'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['label'] = '';
  $handler->display->display_options['fields']['field_promo_text']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_promo_text']['alter']['text'] = '<br/>[field_promo_text]';
  $handler->display->display_options['fields']['field_promo_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_text']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
    'campaign' => 'campaign',
    'feature_article' => 'feature_article',
    'flashcard' => 'flashcard',
    'openpublish_photo_gallery' => 'openpublish_photo_gallery',
    'video' => 'video',
    'video_playlist' => 'video_playlist',
  );
  $handler->display->display_options['path'] = 'content/%/feed.xml ';

  /* Display: Full Feed */
  $handler = $view->new_display('page', 'Full Feed', 'page_3');
  $handler->display->display_options['display_description'] = 'Full content feed filtered by content type';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_takepart_rss_style';
  $handler->display->display_options['style_options']['schema'] = 'rssimages';
  $handler->display->display_options['style_options']['title'] = 'TAKEPART';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Thumbnail Image */
  $handler->display->display_options['fields']['field_thumbnail']['id'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['table'] = 'field_data_field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['field'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_thumbnail']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_thumbnail']['alter']['text'] = '[field_thumbnail-fid]';
  $handler->display->display_options['fields']['field_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_thumbnail']['type'] = 'image';
  $handler->display->display_options['fields']['field_thumbnail']['settings'] = array(
    'image_style' => 'large',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_thumbnail']['group_column'] = 'fid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'D, d M Y H:i:s T';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Author(s) */
  $handler->display->display_options['fields']['field_author']['id'] = 'field_author';
  $handler->display->display_options['fields']['field_author']['table'] = 'field_data_field_author';
  $handler->display->display_options['fields']['field_author']['field'] = 'field_author';
  $handler->display->display_options['fields']['field_author']['label'] = '';
  $handler->display->display_options['fields']['field_author']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_author']['type'] = 'node_reference_plain';
  $handler->display->display_options['fields']['field_author']['delta_offset'] = '0';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '1200',
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = 'Read More';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Read More on TAKEPART';
  $handler->display->display_options['path'] = 'content/%/full_feed.xml ';

  /* Display: Yahoo Feed */
  $handler = $view->new_display('page', 'Yahoo Feed', 'yahoo_feed');
  $handler->display->display_options['display_description'] = 'Full content RSS feed formatted for Yahoo';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_takepart_rss_style';
  $handler->display->display_options['style_options']['schema'] = 'rssimages';
  $handler->display->display_options['style_options']['title'] = 'TAKEPART';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Page Headline */
  $handler->display->display_options['fields']['field_flashcard_page_headline']['id'] = 'field_flashcard_page_headline';
  $handler->display->display_options['fields']['field_flashcard_page_headline']['table'] = 'field_data_field_flashcard_page_headline';
  $handler->display->display_options['fields']['field_flashcard_page_headline']['field'] = 'field_flashcard_page_headline';
  $handler->display->display_options['fields']['field_flashcard_page_headline']['label'] = '';
  $handler->display->display_options['fields']['field_flashcard_page_headline']['element_label_colon'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'D, d M Y H:i:s T';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Author(s) */
  $handler->display->display_options['fields']['field_author']['id'] = 'field_author';
  $handler->display->display_options['fields']['field_author']['table'] = 'field_data_field_author';
  $handler->display->display_options['fields']['field_author']['field'] = 'field_author';
  $handler->display->display_options['fields']['field_author']['label'] = '';
  $handler->display->display_options['fields']['field_author']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_author']['type'] = 'node_reference_plain';
  $handler->display->display_options['fields']['field_author']['delta_offset'] = '0';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['preserve_tags'] = '<p><br><strong><em><b><i><a><hr><div><span><embed><object><param>';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '1200',
  );
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_article_main_image']['id'] = 'field_article_main_image';
  $handler->display->display_options['fields']['field_article_main_image']['table'] = 'field_data_field_article_main_image';
  $handler->display->display_options['fields']['field_article_main_image']['field'] = 'field_article_main_image';
  $handler->display->display_options['fields']['field_article_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_article_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_article_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_article_main_image']['type'] = 'image';
  $handler->display->display_options['fields']['field_article_main_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Inline Content: Embedded Content */
  $handler->display->display_options['fields']['inline_content_embedded']['id'] = 'inline_content_embedded';
  $handler->display->display_options['fields']['inline_content_embedded']['table'] = 'node';
  $handler->display->display_options['fields']['inline_content_embedded']['field'] = 'inline_content_embedded';
  $handler->display->display_options['fields']['inline_content_embedded']['label'] = '';
  $handler->display->display_options['fields']['inline_content_embedded']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['inline_content_embedded']['list']['separator'] = ',,,';
  $handler->display->display_options['fields']['inline_content_embedded']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['inline_content_embedded']['view_mode'] = 'full';
  /* Field: Content: Related Stories */
  $handler->display->display_options['fields']['field_related_stories']['id'] = 'field_related_stories';
  $handler->display->display_options['fields']['field_related_stories']['table'] = 'field_data_field_related_stories';
  $handler->display->display_options['fields']['field_related_stories']['field'] = 'field_related_stories';
  $handler->display->display_options['fields']['field_related_stories']['label'] = '';
  $handler->display->display_options['fields']['field_related_stories']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_related_stories']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_related_stories']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_related_stories']['separator'] = ',,,';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['php']['alter']['text'] = '[field_related_stories][php][inline_content_embedded]';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
if (!empty($data->_field_data[\'nid\'][\'entity\']->field_related_stories) && !empty($data->_entity_properties[\'inline_content_embedded\'])) {
  $separator = \',,,\';
} else {
  $separator = \'\';
}
echo $separator;
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
    'feature_article' => 'feature_article',
  );
  /* Filter criterion: Content: Syndication (field_syndication) */
  $handler->display->display_options['filters']['field_syndication_value']['id'] = 'field_syndication_value';
  $handler->display->display_options['filters']['field_syndication_value']['table'] = 'field_data_field_syndication';
  $handler->display->display_options['filters']['field_syndication_value']['field'] = 'field_syndication_value';
  $handler->display->display_options['filters']['field_syndication_value']['operator'] = 'empty';
  $handler->display->display_options['path'] = 'content/%/yahoo_feed.xml ';

  /* Display: Admin Tag Feed */
  $handler = $view->new_display('page', 'Admin Tag Feed', 'page_5');
  $handler->display->display_options['display_description'] = 'Generate an RSS feed based on an Admin Tag';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_takepart_rss_style';
  $handler->display->display_options['style_options']['schema'] = 'rssimages';
  $handler->display->display_options['style_options']['title'] = 'TAKEPART';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Display Tag */
  $handler->display->display_options['fields']['field_display_tag']['id'] = 'field_display_tag';
  $handler->display->display_options['fields']['field_display_tag']['table'] = 'field_data_field_display_tag';
  $handler->display->display_options['fields']['field_display_tag']['field'] = 'field_display_tag';
  $handler->display->display_options['fields']['field_display_tag']['label'] = '';
  $handler->display->display_options['fields']['field_display_tag']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_display_tag']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_display_tag']['alter']['text'] = '<br> [field_display_tag]';
  $handler->display->display_options['fields']['field_display_tag']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_tag']['hide_alter_empty'] = FALSE;
  /* Field: Field: Thumbnail Image */
  $handler->display->display_options['fields']['field_thumbnail']['id'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['table'] = 'field_data_field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['field'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_thumbnail']['type'] = 'image';
  $handler->display->display_options['fields']['field_thumbnail']['settings'] = array(
    'image_style' => 'large',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_thumbnail']['group_column'] = 'fid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'D, d M Y H:i:s T';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Admin Tag (field_admin_tag) */
  $handler->display->display_options['arguments']['field_admin_tag_tid']['id'] = 'field_admin_tag_tid';
  $handler->display->display_options['arguments']['field_admin_tag_tid']['table'] = 'field_data_field_admin_tag';
  $handler->display->display_options['arguments']['field_admin_tag_tid']['field'] = 'field_admin_tag_tid';
  $handler->display->display_options['arguments']['field_admin_tag_tid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_admin_tag_tid']['exception']['value'] = '';
  $handler->display->display_options['arguments']['field_admin_tag_tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_admin_tag_tid']['title'] = '%1 Feed';
  $handler->display->display_options['arguments']['field_admin_tag_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_admin_tag_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_admin_tag_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_admin_tag_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_admin_tag_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_admin_tag_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_admin_tag_tid']['validate_options']['vocabularies'] = array(
    'admin_tag' => 'admin_tag',
  );
  $handler->display->display_options['arguments']['field_admin_tag_tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['field_admin_tag_tid']['validate']['fail'] = 'empty';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
    'campaign' => 'campaign',
    'feature_article' => 'feature_article',
    'flashcard' => 'flashcard',
    'openpublish_photo_gallery' => 'openpublish_photo_gallery',
    'video' => 'video',
    'video_playlist' => 'video_playlist',
  );
  $handler->display->display_options['path'] = 'content/%/admin_feed.xml';

  /* Display: Mashable Full Feed */
  $handler = $view->new_display('page', 'Mashable Full Feed', 'mashable_full');
  $handler->display->display_options['display_description'] = 'Full content RSS feed formatted for Mashable';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_takepart_rss_style';
  $handler->display->display_options['style_options']['schema'] = 'rssimages';
  $handler->display->display_options['style_options']['title'] = 'TAKEPART';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Subhead */
  $handler->display->display_options['fields']['field_article_subhead']['id'] = 'field_article_subhead';
  $handler->display->display_options['fields']['field_article_subhead']['table'] = 'field_data_field_article_subhead';
  $handler->display->display_options['fields']['field_article_subhead']['field'] = 'field_article_subhead';
  $handler->display->display_options['fields']['field_article_subhead']['label'] = '';
  $handler->display->display_options['fields']['field_article_subhead']['element_label_colon'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'D, d M Y H:i:s T';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['preserve_tags'] = '<p><br><strong><em><b><i><a><hr><div><span><embed><object><param>';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '1200',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'flashcard' => 'flashcard',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Syndication (field_syndication) */
  $handler->display->display_options['filters']['field_syndication_value']['id'] = 'field_syndication_value';
  $handler->display->display_options['filters']['field_syndication_value']['table'] = 'field_data_field_syndication';
  $handler->display->display_options['filters']['field_syndication_value']['field'] = 'field_syndication_value';
  $handler->display->display_options['filters']['field_syndication_value']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_syndication_value']['group'] = 1;
  /* Filter criterion: Content: Admin Tag (field_admin_tag) */
  $handler->display->display_options['filters']['field_admin_tag_tid']['id'] = 'field_admin_tag_tid';
  $handler->display->display_options['filters']['field_admin_tag_tid']['table'] = 'field_data_field_admin_tag';
  $handler->display->display_options['filters']['field_admin_tag_tid']['field'] = 'field_admin_tag_tid';
  $handler->display->display_options['filters']['field_admin_tag_tid']['value'] = array(
    0 => '115599',
  );
  $handler->display->display_options['filters']['field_admin_tag_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_admin_tag_tid']['vocabulary'] = 'admin_tag';
  /* Filter criterion: Content: Post date */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'node';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = '>=';
  $handler->display->display_options['filters']['created']['value']['value'] = '-7 days';
  $handler->display->display_options['filters']['created']['value']['type'] = 'offset';
  $handler->display->display_options['filters']['created']['group'] = 1;
  $handler->display->display_options['path'] = 'content/%/mashable_feed.xml';

  /* Display: Mashable Short Feed */
  $handler = $view->new_display('page', 'Mashable Short Feed', 'mashable_short');
  $handler->display->display_options['display_description'] = 'Brief content RSS feed formatted for Mashable';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_takepart_rss_style';
  $handler->display->display_options['style_options']['schema'] = 'rssimages';
  $handler->display->display_options['style_options']['title'] = 'TAKEPART';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Subhead */
  $handler->display->display_options['fields']['field_article_subhead']['id'] = 'field_article_subhead';
  $handler->display->display_options['fields']['field_article_subhead']['table'] = 'field_data_field_article_subhead';
  $handler->display->display_options['fields']['field_article_subhead']['field'] = 'field_article_subhead';
  $handler->display->display_options['fields']['field_article_subhead']['label'] = '';
  $handler->display->display_options['fields']['field_article_subhead']['element_label_colon'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'D, d M Y H:i:s T';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'flashcard' => 'flashcard',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Syndication (field_syndication) */
  $handler->display->display_options['filters']['field_syndication_value']['id'] = 'field_syndication_value';
  $handler->display->display_options['filters']['field_syndication_value']['table'] = 'field_data_field_syndication';
  $handler->display->display_options['filters']['field_syndication_value']['field'] = 'field_syndication_value';
  $handler->display->display_options['filters']['field_syndication_value']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_syndication_value']['group'] = 1;
  /* Filter criterion: Content: Admin Tag (field_admin_tag) */
  $handler->display->display_options['filters']['field_admin_tag_tid']['id'] = 'field_admin_tag_tid';
  $handler->display->display_options['filters']['field_admin_tag_tid']['table'] = 'field_data_field_admin_tag';
  $handler->display->display_options['filters']['field_admin_tag_tid']['field'] = 'field_admin_tag_tid';
  $handler->display->display_options['filters']['field_admin_tag_tid']['value'] = array(
    0 => '115599',
  );
  $handler->display->display_options['filters']['field_admin_tag_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_admin_tag_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_admin_tag_tid']['vocabulary'] = 'admin_tag';
  /* Filter criterion: Content: Post date */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'node';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = '>=';
  $handler->display->display_options['filters']['created']['value']['value'] = '-7 days';
  $handler->display->display_options['filters']['created']['value']['type'] = 'offset';
  $handler->display->display_options['path'] = 'content/%/mashable_feed_short.xml';

  /* Display: Feed Block */
  $handler = $view->new_display('block', 'Feed Block', 'block_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'view-all-feed';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Latest Stories';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<h2>Latest Stories from takepart</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Field: Thumbnail Image */
  $handler->display->display_options['fields']['field_thumbnail']['id'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['table'] = 'field_data_field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['field'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_thumbnail']['type'] = 'image';
  $handler->display->display_options['fields']['field_thumbnail']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_thumbnail']['group_column'] = 'entity_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['block_description'] = 'Latest Stories';
  $export['content_types_posts_feed'] = $view;

  $view = new view();
  $view->name = 'display_tag_search';
  $view->description = 'Diagnostic to find missing display tags, per issue #29975';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Display Tag Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Display Tag Search';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    7 => '7',
    5 => '5',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_display_tag' => 'field_display_tag',
    'name' => 'name',
    'title' => 'title',
    'status' => 'status',
    'created' => 'created',
    'nid' => 'nid',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_display_tag' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'nid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'This report lists nodes, showing their display tags and taxonomy terms. You may click on any blue column head to sort by that field. You may also filter results by entering a term in the "Name" box; this may be a full term name or just the start of one. You may click on the edit link to change or add a display tag.';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Relationship: Content: Display Tag (field_display_tag) */
  $handler->display->display_options['relationships']['field_display_tag_tid']['id'] = 'field_display_tag_tid';
  $handler->display->display_options['relationships']['field_display_tag_tid']['table'] = 'field_data_field_display_tag';
  $handler->display->display_options['relationships']['field_display_tag_tid']['field'] = 'field_display_tag_tid';
  /* Field: Content: Display Tag */
  $handler->display->display_options['fields']['field_display_tag']['id'] = 'field_display_tag';
  $handler->display->display_options['fields']['field_display_tag']['table'] = 'field_data_field_display_tag';
  $handler->display->display_options['fields']['field_display_tag']['field'] = 'field_display_tag';
  $handler->display->display_options['fields']['field_display_tag']['hide_alter_empty'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_display_tag_tid';
  $handler->display->display_options['fields']['name']['label'] = 'Term';
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['hide_alter_empty'] = FALSE;
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'field_display_tag_tid';
  $handler->display->display_options['filters']['name']['operator'] = 'starts';
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'action' => 'action',
    'openpublish_article' => 'openpublish_article',
    'blog_front' => 'blog_front',
    'openpublish_blog_post' => 'openpublish_blog_post',
    'openpublish_photo' => 'openpublish_photo',
    'openpublish_video' => 'openpublish_video',
  );
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['multiple'] = TRUE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/reports/display_tag_search';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Display Tag Search';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $export['display_tag_search'] = $view;

  $view = new view();
  $view->name = 'featured_items';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Featured Items';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Primary';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '1800';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '1800';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_gallery_main_image']['id'] = 'field_gallery_main_image';
  $handler->display->display_options['fields']['field_gallery_main_image']['table'] = 'field_data_field_gallery_main_image';
  $handler->display->display_options['fields']['field_gallery_main_image']['field'] = 'field_gallery_main_image';
  $handler->display->display_options['fields']['field_gallery_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_gallery_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_gallery_main_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_gallery_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_gallery_main_image']['type'] = 'image';
  $handler->display->display_options['fields']['field_gallery_main_image']['settings'] = array(
    'image_style' => 'tp_promo_feature_thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_article_main_image']['id'] = 'field_article_main_image';
  $handler->display->display_options['fields']['field_article_main_image']['table'] = 'field_data_field_article_main_image';
  $handler->display->display_options['fields']['field_article_main_image']['field'] = 'field_article_main_image';
  $handler->display->display_options['fields']['field_article_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_article_main_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_article_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_article_main_image']['empty'] = '[field_gallery_main_image]';
  $handler->display->display_options['fields']['field_article_main_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_article_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_article_main_image']['type'] = 'image';
  $handler->display->display_options['fields']['field_article_main_image']['settings'] = array(
    'image_style' => 'tp_promo_feature_thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_page_main_image']['id'] = 'field_page_main_image';
  $handler->display->display_options['fields']['field_page_main_image']['table'] = 'field_data_field_page_main_image';
  $handler->display->display_options['fields']['field_page_main_image']['field'] = 'field_page_main_image';
  $handler->display->display_options['fields']['field_page_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_page_main_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_page_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_page_main_image']['empty'] = '[field_article_main_image]';
  $handler->display->display_options['fields']['field_page_main_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_page_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_page_main_image']['type'] = 'image';
  $handler->display->display_options['fields']['field_page_main_image']['settings'] = array(
    'image_style' => 'tp_promo_feature_thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_blogpost_main_image']['id'] = 'field_blogpost_main_image';
  $handler->display->display_options['fields']['field_blogpost_main_image']['table'] = 'field_data_field_blogpost_main_image';
  $handler->display->display_options['fields']['field_blogpost_main_image']['field'] = 'field_blogpost_main_image';
  $handler->display->display_options['fields']['field_blogpost_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_blogpost_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_blogpost_main_image']['empty'] = '[field_page_main_image]';
  $handler->display->display_options['fields']['field_blogpost_main_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_blogpost_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_blogpost_main_image']['type'] = 'image';
  $handler->display->display_options['fields']['field_blogpost_main_image']['settings'] = array(
    'image_style' => 'tp_promo_feature_thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Headline */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'Headline';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$entity = $data->_field_data[\'nid\'][\'entity\'];
if(isset($entity->field_promo_headline[$entity->language])) {
  $promo_headline_array = $entity->field_promo_headline[$entity->language];
  $value = !empty($promo_headline_array) ? $promo_headline_array[0][\'value\'] : $data->node_title;
}
else {
  $value = $data->node_title;
}
$value = l($value, "node/{$entity->nid}");
print $value;
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Field: Promo Text */
  $handler->display->display_options['fields']['field_promo_text']['id'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['table'] = 'field_data_field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['field'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['label'] = '';
  $handler->display->display_options['fields']['field_promo_text']['element_label_colon'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['element_default_classes'] = FALSE;
  /* Field: Field: Thumbnail Image */
  $handler->display->display_options['fields']['field_thumbnail']['id'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['table'] = 'field_data_field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['field'] = 'field_thumbnail';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  /* Contextual filter: Included Content */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['ui_name'] = 'Included Content';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Primary */
  $handler = $view->new_display('block', 'Primary', 'block');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'primary-feature';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Thumbnail Image */
  $handler->display->display_options['fields']['field_thumbnail']['id'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['table'] = 'field_data_field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['field'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_thumbnail']['type'] = 'image';
  $handler->display->display_options['fields']['field_thumbnail']['settings'] = array(
    'image_style' => 'tp_promo_feature_thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Headline */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'Headline';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$entity = $data->_field_data[\'nid\'][\'entity\'];
if(isset($entity->field_promo_headline[$entity->language])) {
  $promo_headline_array = $entity->field_promo_headline[$entity->language];
  $value = !empty($promo_headline_array) ? $promo_headline_array[0][\'value\'] : $data->node_title;
}
else {
  $value = $data->node_title;
}
$value = l($value, "node/{$entity->nid}");
print $value;
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['element_default_classes'] = FALSE;
  $handler->display->display_options['block_description'] = 'Primary feature';

  /* Display: Secondary */
  $handler = $view->new_display('block', 'Secondary', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Secondary';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'secondary-feature';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Thumbnail Image */
  $handler->display->display_options['fields']['field_thumbnail']['id'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['table'] = 'field_data_field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['field'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_thumbnail']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_thumbnail']['type'] = 'image';
  $handler->display->display_options['fields']['field_thumbnail']['settings'] = array(
    'image_style' => 'tp_secondary_feature_thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_page_main_image']['id'] = 'field_page_main_image';
  $handler->display->display_options['fields']['field_page_main_image']['table'] = 'field_data_field_page_main_image';
  $handler->display->display_options['fields']['field_page_main_image']['field'] = 'field_page_main_image';
  $handler->display->display_options['fields']['field_page_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_page_main_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_page_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_page_main_image']['empty'] = '[field_thumbnail]';
  $handler->display->display_options['fields']['field_page_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_page_main_image']['type'] = 'image';
  $handler->display->display_options['fields']['field_page_main_image']['settings'] = array(
    'image_style' => 'tp_secondary_feature_thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_action_main_image']['id'] = 'field_action_main_image';
  $handler->display->display_options['fields']['field_action_main_image']['table'] = 'field_data_field_action_main_image';
  $handler->display->display_options['fields']['field_action_main_image']['field'] = 'field_action_main_image';
  $handler->display->display_options['fields']['field_action_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_action_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_action_main_image']['empty'] = '[field_page_main_image]';
  $handler->display->display_options['fields']['field_action_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_action_main_image']['type'] = 'image';
  $handler->display->display_options['fields']['field_action_main_image']['settings'] = array(
    'image_style' => 'tp_secondary_feature_thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Headline */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'Headline';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$entity = $data->_field_data[\'nid\'][\'entity\'];
if(isset($entity->field_promo_headline[$entity->language])) {
  $promo_headline_array = $entity->field_promo_headline[$entity->language];
  $value = !empty($promo_headline_array) ? $promo_headline_array[0][\'value\'] : $data->node_title;
}
else {
  $value = $data->node_title;
}
$value = l($value, "node/{$entity->nid}");
print $value;
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Arguments: Multi-item Argument Order */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'views_sort_by_arg_order';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['order'] = 'DESC';
  $handler->display->display_options['sorts']['weight']['argument_number'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['block_description'] = 'Secondary features';
  $export['featured_items'] = $view;

  $view = new view();
  $view->name = 'flashcard_organizations_experts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'field_collection_item';
  $view->human_name = 'Flashcard Organizations & Experts';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Organizations & Experts';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Flashcard */
  $handler->display->display_options['relationships']['field_flashcard_organizations_node']['id'] = 'field_flashcard_organizations_node';
  $handler->display->display_options['relationships']['field_flashcard_organizations_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_flashcard_organizations_node']['field'] = 'field_flashcard_organizations_node';
  $handler->display->display_options['relationships']['field_flashcard_organizations_node']['ui_name'] = 'Flashcard';
  $handler->display->display_options['relationships']['field_flashcard_organizations_node']['label'] = 'flashcard';
  $handler->display->display_options['relationships']['field_flashcard_organizations_node']['required'] = TRUE;
  /* Field: Field collection item: Link */
  $handler->display->display_options['fields']['field_organizaiton_link']['id'] = 'field_organizaiton_link';
  $handler->display->display_options['fields']['field_organizaiton_link']['table'] = 'field_data_field_organizaiton_link';
  $handler->display->display_options['fields']['field_organizaiton_link']['field'] = 'field_organizaiton_link';
  $handler->display->display_options['fields']['field_organizaiton_link']['label'] = '';
  $handler->display->display_options['fields']['field_organizaiton_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_organizaiton_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organizaiton_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_organizaiton_link']['type'] = 'link_absolute';
  /* Field: Field collection item: Name */
  $handler->display->display_options['fields']['field_organization_name']['id'] = 'field_organization_name';
  $handler->display->display_options['fields']['field_organization_name']['table'] = 'field_data_field_organization_name';
  $handler->display->display_options['fields']['field_organization_name']['field'] = 'field_organization_name';
  $handler->display->display_options['fields']['field_organization_name']['label'] = '';
  $handler->display->display_options['fields']['field_organization_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_organization_name']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Image */
  $handler->display->display_options['fields']['field_organization_image']['id'] = 'field_organization_image';
  $handler->display->display_options['fields']['field_organization_image']['table'] = 'field_data_field_organization_image';
  $handler->display->display_options['fields']['field_organization_image']['field'] = 'field_organization_image';
  $handler->display->display_options['fields']['field_organization_image']['label'] = '';
  $handler->display->display_options['fields']['field_organization_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_organization_image']['alter']['path'] = '[field_organizaiton_link]';
  $handler->display->display_options['fields']['field_organization_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_organization_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_image']['element_wrapper_class'] = 'flashcard-organization-image';
  $handler->display->display_options['fields']['field_organization_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_organization_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_organization_image']['type'] = 'image';
  $handler->display->display_options['fields']['field_organization_image']['settings'] = array(
    'image_style' => 'tp_100_wide',
    'image_link' => '',
  );
  /* Field: Field collection item: Label */
  $handler->display->display_options['fields']['field_organization_label']['id'] = 'field_organization_label';
  $handler->display->display_options['fields']['field_organization_label']['table'] = 'field_data_field_organization_label';
  $handler->display->display_options['fields']['field_organization_label']['field'] = 'field_organization_label';
  $handler->display->display_options['fields']['field_organization_label']['label'] = '';
  $handler->display->display_options['fields']['field_organization_label']['element_type'] = '0';
  $handler->display->display_options['fields']['field_organization_label']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_label']['element_wrapper_type'] = 'h4';
  $handler->display->display_options['fields']['field_organization_label']['element_wrapper_class'] = 'flashcard-organization-label';
  $handler->display->display_options['fields']['field_organization_label']['element_default_classes'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_organization_name]';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = '[field_organizaiton_link]';
  $handler->display->display_options['fields']['nothing']['alter']['alt'] = '[field_organization_label]: [field_organization_name]';
  $handler->display->display_options['fields']['nothing']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['nothing']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'h3';
  $handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'flashcard-organization-name';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_flashcard_organizations_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['flashcard_organizations_experts'] = $view;

  $view = new view();
  $view->name = 'flashcards';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Flashcards';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Flashcards on TakePart';
  $handler->display->display_options['css_class'] = 'view-topic-listing';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Field: Thumbnail Image */
  $handler->display->display_options['fields']['field_thumbnail']['id'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['table'] = 'field_data_field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['field'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_thumbnail']['type'] = 'image';
  $handler->display->display_options['fields']['field_thumbnail']['settings'] = array(
    'image_style' => 'topic_thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Page Headline */
  $handler->display->display_options['fields']['field_flashcard_page_headline']['id'] = 'field_flashcard_page_headline';
  $handler->display->display_options['fields']['field_flashcard_page_headline']['table'] = 'field_data_field_flashcard_page_headline';
  $handler->display->display_options['fields']['field_flashcard_page_headline']['field'] = 'field_flashcard_page_headline';
  $handler->display->display_options['fields']['field_flashcard_page_headline']['label'] = '';
  $handler->display->display_options['fields']['field_flashcard_page_headline']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_flashcard_page_headline']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_flashcard_page_headline']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'flashcard' => 'flashcard',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'flashcards';
  $export['flashcards'] = $view;

  $view = new view();
  $view->name = 'photo_galleries';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Photo Galleries';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Photo Gallery';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '300';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '300';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['slave'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_gallery_main_image']['id'] = 'field_gallery_main_image';
  $handler->display->display_options['fields']['field_gallery_main_image']['table'] = 'field_data_field_gallery_main_image';
  $handler->display->display_options['fields']['field_gallery_main_image']['field'] = 'field_gallery_main_image';
  $handler->display->display_options['fields']['field_gallery_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_gallery_main_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_gallery_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_gallery_main_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_gallery_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_gallery_main_image']['type'] = 'image';
  $handler->display->display_options['fields']['field_gallery_main_image']['settings'] = array(
    'image_style' => 'tp_popular_gallery_thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Field: Thumbnail Image */
  $handler->display->display_options['fields']['field_thumbnail']['id'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['table'] = 'field_data_field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['field'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['empty'] = '[field_gallery_main_image]';
  $handler->display->display_options['fields']['field_thumbnail']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_thumbnail']['type'] = 'image';
  $handler->display->display_options['fields']['field_thumbnail']['settings'] = array(
    'image_style' => 'tp_popular_gallery_thumbnail',
    'image_link' => 'content',
  );
  /* Field: Field: Promo Headline */
  $handler->display->display_options['fields']['field_promo_headline']['id'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['table'] = 'field_data_field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['field'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['label'] = '';
  $handler->display->display_options['fields']['field_promo_headline']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_promo_headline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_headline']['empty'] = '[title]';
  $handler->display->display_options['fields']['field_promo_headline']['hide_alter_empty'] = FALSE;
  /* Sort criterion: Arguments: Multi-item Argument Order */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'views_sort_by_arg_order';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['order'] = 'DESC';
  $handler->display->display_options['sorts']['weight']['argument_number'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'openpublish_photo_gallery' => 'openpublish_photo_gallery',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = '0';

  /* Display: Currated */
  $handler = $view->new_display('block', 'Currated', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';

  /* Display: Photo Page List */
  $handler = $view->new_display('block', 'Photo Page List', 'block_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '2';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_gallery_main_image']['id'] = 'field_gallery_main_image';
  $handler->display->display_options['fields']['field_gallery_main_image']['table'] = 'field_data_field_gallery_main_image';
  $handler->display->display_options['fields']['field_gallery_main_image']['field'] = 'field_gallery_main_image';
  $handler->display->display_options['fields']['field_gallery_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_gallery_main_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_gallery_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_gallery_main_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_gallery_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_gallery_main_image']['type'] = 'image';
  $handler->display->display_options['fields']['field_gallery_main_image']['settings'] = array(
    'image_style' => 'tp_promo_feature_thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Field: Thumbnail Image */
  $handler->display->display_options['fields']['field_thumbnail']['id'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['table'] = 'field_data_field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['field'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['empty'] = '[field_gallery_main_image]';
  $handler->display->display_options['fields']['field_thumbnail']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_thumbnail']['type'] = 'image';
  $handler->display->display_options['fields']['field_thumbnail']['settings'] = array(
    'image_style' => 'tp_promo_feature_thumbnail',
    'image_link' => 'content',
  );
  /* Field: Field: Promo Headline */
  $handler->display->display_options['fields']['field_promo_headline']['id'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['table'] = 'field_data_field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['field'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['label'] = '';
  $handler->display->display_options['fields']['field_promo_headline']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_promo_headline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_headline']['empty'] = '[title]';
  $handler->display->display_options['fields']['field_promo_headline']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;

  /* Display: Curated Vertical   */
  $handler = $view->new_display('block', 'Curated Vertical  ', 'block_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_gallery_main_image']['id'] = 'field_gallery_main_image';
  $handler->display->display_options['fields']['field_gallery_main_image']['table'] = 'field_data_field_gallery_main_image';
  $handler->display->display_options['fields']['field_gallery_main_image']['field'] = 'field_gallery_main_image';
  $handler->display->display_options['fields']['field_gallery_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_gallery_main_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_gallery_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_gallery_main_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_gallery_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_gallery_main_image']['type'] = 'image';
  $handler->display->display_options['fields']['field_gallery_main_image']['settings'] = array(
    'image_style' => 'tp_large_rail_wide',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Field: Thumbnail Image */
  $handler->display->display_options['fields']['field_thumbnail']['id'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['table'] = 'field_data_field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['field'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['empty'] = '[field_gallery_main_image]';
  $handler->display->display_options['fields']['field_thumbnail']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_thumbnail']['type'] = 'image';
  $handler->display->display_options['fields']['field_thumbnail']['settings'] = array(
    'image_style' => 'tp_large_rail_wide',
    'image_link' => 'content',
  );
  /* Field: Field: Promo Headline */
  $handler->display->display_options['fields']['field_promo_headline']['id'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['table'] = 'field_data_field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['field'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['label'] = '';
  $handler->display->display_options['fields']['field_promo_headline']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_promo_headline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_headline']['empty'] = '[title]';
  $handler->display->display_options['fields']['field_promo_headline']['hide_alter_empty'] = FALSE;
  $export['photo_galleries'] = $view;

  $view = new view();
  $view->name = 'photo_galleries_promo';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Photo Galleries Promo';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'photo galleries';
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['use_more_text'] = '';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<a href="/photos" class="more">See more photo galleries</a>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'photo_galleries_promo' => 'photo_galleries_promo',
    'latest_headlines' => 0,
    'promo_features_columns' => 0,
    'promo_take_action' => 0,
    'promo_tpl' => 0,
    'promo_lifestyle' => 0,
    'promo_in_the_news' => 0,
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Field: Thumbnail Image */
  $handler->display->display_options['fields']['field_thumbnail']['id'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['table'] = 'field_data_field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['field'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_thumbnail']['type'] = 'image';
  $handler->display->display_options['fields']['field_thumbnail']['settings'] = array(
    'image_style' => 'homepage_featured_image',
    'image_link' => 'content',
  );
  /* Field: Field: Promo Headline */
  $handler->display->display_options['fields']['field_promo_headline']['id'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['table'] = 'field_data_field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['field'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['label'] = '';
  $handler->display->display_options['fields']['field_promo_headline']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_promo_headline']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_promo_headline']['element_class'] = '[type]';
  $handler->display->display_options['fields']['field_promo_headline']['element_label_colon'] = FALSE;
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['photo_galleries_promo'] = $view;

  $view = new view();
  $view->name = 'photo_gallery';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Photo Gallery';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Photo Gallery';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['slave'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['slideshow_type'] = 'views_slideshow_cycle';
  $handler->display->display_options['style_options']['slideshow_skin'] = 'default';
  $handler->display->display_options['style_options']['skin_info'] = array(
    'class' => 'default',
    'name' => 'Default',
    'module' => 'views_slideshow',
    'path' => '',
    'stylesheets' => array(),
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['hide_on_single_slide'] = 1;
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_jcarousel_pager';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_gallery_images_1' => 'field_gallery_images_1',
    'field_gallery_images' => 0,
    'field_image_title' => 0,
    'field_media_caption' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_jcarousel_pager_skin'] = 'takepart';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_jcarousel_pager_orientation'] = '0';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_jcarousel_pager_scroll'] = '3';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_jcarousel_pager_visible'] = '6';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_jcarousel_pager_wrap'] = '';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_gallery_images_1' => 'field_gallery_images_1',
    'field_gallery_images' => 0,
    'field_image_title' => 0,
    'field_media_caption' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_jcarousel_pager_orientation'] = '0';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_jcarousel_pager_scroll'] = '3';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_jcarousel_pager_visible'] = '3';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_jcarousel_pager_wrap'] = '';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['transition_advanced'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['timeout'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['speed'] = '700';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['delay'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['pause'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['action_advanced'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['start_paused'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['remember_slide_days'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['fixed_height'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['items_per_slide'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['wait_for_image_load_timeout'] = '3000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartype'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartypenobg'] = 0;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Gallery Images (field_gallery_images:fid) */
  $handler->display->display_options['relationships']['field_gallery_images_fid']['id'] = 'field_gallery_images_fid';
  $handler->display->display_options['relationships']['field_gallery_images_fid']['table'] = 'field_data_field_gallery_images';
  $handler->display->display_options['relationships']['field_gallery_images_fid']['field'] = 'field_gallery_images_fid';
  $handler->display->display_options['relationships']['field_gallery_images_fid']['required'] = TRUE;
  /* Field: Content: Gallery Images */
  $handler->display->display_options['fields']['field_gallery_images']['id'] = 'field_gallery_images';
  $handler->display->display_options['fields']['field_gallery_images']['table'] = 'field_data_field_gallery_images';
  $handler->display->display_options['fields']['field_gallery_images']['field'] = 'field_gallery_images';
  $handler->display->display_options['fields']['field_gallery_images']['label'] = '';
  $handler->display->display_options['fields']['field_gallery_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_gallery_images']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_gallery_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_gallery_images']['type'] = 'image';
  $handler->display->display_options['fields']['field_gallery_images']['settings'] = array(
    'image_style' => 'tp_content_wide',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_gallery_images']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_gallery_images']['delta_offset'] = '0';
  /* Field: Thumbnails */
  $handler->display->display_options['fields']['field_gallery_images_1']['id'] = 'field_gallery_images_1';
  $handler->display->display_options['fields']['field_gallery_images_1']['table'] = 'field_data_field_gallery_images';
  $handler->display->display_options['fields']['field_gallery_images_1']['field'] = 'field_gallery_images';
  $handler->display->display_options['fields']['field_gallery_images_1']['ui_name'] = 'Thumbnails';
  $handler->display->display_options['fields']['field_gallery_images_1']['label'] = '';
  $handler->display->display_options['fields']['field_gallery_images_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_gallery_images_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_gallery_images_1']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_gallery_images_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_gallery_images_1']['type'] = 'image';
  $handler->display->display_options['fields']['field_gallery_images_1']['settings'] = array(
    'image_style' => 'tp_gallery_photo_thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_gallery_images_1']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_gallery_images_1']['delta_offset'] = '0';
  /* Field: File: Title */
  $handler->display->display_options['fields']['field_image_title']['id'] = 'field_image_title';
  $handler->display->display_options['fields']['field_image_title']['table'] = 'field_data_field_image_title';
  $handler->display->display_options['fields']['field_image_title']['field'] = 'field_image_title';
  $handler->display->display_options['fields']['field_image_title']['relationship'] = 'field_gallery_images_fid';
  $handler->display->display_options['fields']['field_image_title']['label'] = '';
  $handler->display->display_options['fields']['field_image_title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['field_image_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_title']['hide_alter_empty'] = FALSE;
  /* Field: File: Caption */
  $handler->display->display_options['fields']['field_media_caption']['id'] = 'field_media_caption';
  $handler->display->display_options['fields']['field_media_caption']['table'] = 'field_data_field_media_caption';
  $handler->display->display_options['fields']['field_media_caption']['field'] = 'field_media_caption';
  $handler->display->display_options['fields']['field_media_caption']['relationship'] = 'field_gallery_images_fid';
  $handler->display->display_options['fields']['field_media_caption']['label'] = '';
  $handler->display->display_options['fields']['field_media_caption']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_media_caption']['hide_alter_empty'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');

  /* Display: Embed thumbnails */
  $handler = $view->new_display('block', 'Embed thumbnails', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Thumbnails */
  $handler->display->display_options['fields']['field_gallery_images_1']['id'] = 'field_gallery_images_1';
  $handler->display->display_options['fields']['field_gallery_images_1']['table'] = 'field_data_field_gallery_images';
  $handler->display->display_options['fields']['field_gallery_images_1']['field'] = 'field_gallery_images';
  $handler->display->display_options['fields']['field_gallery_images_1']['ui_name'] = 'Thumbnails';
  $handler->display->display_options['fields']['field_gallery_images_1']['label'] = '';
  $handler->display->display_options['fields']['field_gallery_images_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_gallery_images_1']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_gallery_images_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_gallery_images_1']['type'] = 'image';
  $handler->display->display_options['fields']['field_gallery_images_1']['settings'] = array(
    'image_style' => 'embed_gallery_thumb',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_gallery_images_1']['group_column'] = 'fid';
  $handler->display->display_options['fields']['field_gallery_images_1']['delta_limit'] = '4';
  $handler->display->display_options['fields']['field_gallery_images_1']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_gallery_images_1']['separator'] = '';

  /* Display: Embed gallery */
  $handler = $view->new_display('block', 'Embed gallery', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_gallery_main_image']['id'] = 'field_gallery_main_image';
  $handler->display->display_options['fields']['field_gallery_main_image']['table'] = 'field_data_field_gallery_main_image';
  $handler->display->display_options['fields']['field_gallery_main_image']['field'] = 'field_gallery_main_image';
  $handler->display->display_options['fields']['field_gallery_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_gallery_main_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_gallery_main_image']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_gallery_main_image']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_gallery_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_gallery_main_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_gallery_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_gallery_main_image']['type'] = 'image';
  $handler->display->display_options['fields']['field_gallery_main_image']['settings'] = array(
    'image_style' => 'tp_large_rail_wide',
    'image_link' => '',
  );
  /* Field: Field: Promo Headline */
  $handler->display->display_options['fields']['field_promo_headline']['id'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['table'] = 'field_data_field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['field'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['label'] = '';
  $handler->display->display_options['fields']['field_promo_headline']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_promo_headline']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_promo_headline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_headline']['hide_alter_empty'] = FALSE;
  /* Field: Field: Promo Text */
  $handler->display->display_options['fields']['field_promo_text']['id'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['table'] = 'field_data_field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['field'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['label'] = '';
  $handler->display->display_options['fields']['field_promo_text']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_promo_text']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_promo_text']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_promo_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_text']['hide_alter_empty'] = FALSE;
  $export['photo_gallery'] = $view;

  $view = new view();
  $view->name = 'promo';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Promo';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My Take';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '1800';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '1800';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['slave'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['style_options']['row_class'] = '[type]';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['id'] = 'field_tp_campaign_cover_image';
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['table'] = 'field_data_field_tp_campaign_cover_image';
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['field'] = 'field_tp_campaign_cover_image';
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['label'] = '';
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['type'] = 'image';
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['settings'] = array(
    'image_style' => 'tp_actions_impact_thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_action_main_image']['id'] = 'field_action_main_image';
  $handler->display->display_options['fields']['field_action_main_image']['table'] = 'field_data_field_action_main_image';
  $handler->display->display_options['fields']['field_action_main_image']['field'] = 'field_action_main_image';
  $handler->display->display_options['fields']['field_action_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_action_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_action_main_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_action_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_action_main_image']['type'] = 'image';
  $handler->display->display_options['fields']['field_action_main_image']['settings'] = array(
    'image_style' => 'tp_actions_impact_thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Field: Promo Headline */
  $handler->display->display_options['fields']['field_promo_headline']['id'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['table'] = 'field_data_field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['field'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['label'] = '';
  $handler->display->display_options['fields']['field_promo_headline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_headline']['empty'] = '[title]';
  /* Field: Content: Sub Headline */
  $handler->display->display_options['fields']['field_tp_campaign_subheadline']['id'] = 'field_tp_campaign_subheadline';
  $handler->display->display_options['fields']['field_tp_campaign_subheadline']['table'] = 'field_data_field_tp_campaign_subheadline';
  $handler->display->display_options['fields']['field_tp_campaign_subheadline']['field'] = 'field_tp_campaign_subheadline';
  $handler->display->display_options['fields']['field_tp_campaign_subheadline']['label'] = '';
  $handler->display->display_options['fields']['field_tp_campaign_subheadline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tp_campaign_subheadline']['empty'] = '[field_promo_headline] ';
  /* Field: Field: Promo Text */
  $handler->display->display_options['fields']['field_promo_text']['id'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['table'] = 'field_data_field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['field'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['label'] = '';
  $handler->display->display_options['fields']['field_promo_text']['element_label_colon'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['link_to_node'] = TRUE;
  /* Sort criterion: Arguments: Multi-item Argument Order */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'views_sort_by_arg_order';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['order'] = 'DESC';
  $handler->display->display_options['sorts']['weight']['argument_number'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['ui_name'] = 'Content';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: News to Know */
  $handler = $view->new_display('block', 'News to Know', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'News to Know';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Promo Headline */
  $handler->display->display_options['fields']['field_promo_headline']['id'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['table'] = 'field_data_field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['field'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['label'] = '';
  $handler->display->display_options['fields']['field_promo_headline']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_promo_headline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_headline']['empty'] = '[title]';
  $handler->display->display_options['fields']['field_promo_headline']['hide_alter_empty'] = FALSE;

  /* Display: Features */
  $handler = $view->new_display('block', 'Features', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Features';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'promo-features';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Display Tag */
  $handler->display->display_options['fields']['field_display_tag']['id'] = 'field_display_tag';
  $handler->display->display_options['fields']['field_display_tag']['table'] = 'field_data_field_display_tag';
  $handler->display->display_options['fields']['field_display_tag']['field'] = 'field_display_tag';
  $handler->display->display_options['fields']['field_display_tag']['label'] = '';
  $handler->display->display_options['fields']['field_display_tag']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_tag']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Field: Thumbnail Image */
  $handler->display->display_options['fields']['field_thumbnail_1']['id'] = 'field_thumbnail_1';
  $handler->display->display_options['fields']['field_thumbnail_1']['table'] = 'field_data_field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail_1']['field'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail_1']['label'] = '';
  $handler->display->display_options['fields']['field_thumbnail_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_thumbnail_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail_1']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_thumbnail_1']['type'] = 'image';
  $handler->display->display_options['fields']['field_thumbnail_1']['settings'] = array(
    'image_style' => 'tp_secondary_feature_thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_thumbnail_1']['group_column'] = 'fid';
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_action_main_image']['id'] = 'field_action_main_image';
  $handler->display->display_options['fields']['field_action_main_image']['table'] = 'field_data_field_action_main_image';
  $handler->display->display_options['fields']['field_action_main_image']['field'] = 'field_action_main_image';
  $handler->display->display_options['fields']['field_action_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_action_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_action_main_image']['empty'] = '[field_thumbnail_1]';
  $handler->display->display_options['fields']['field_action_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_action_main_image']['type'] = 'image';
  $handler->display->display_options['fields']['field_action_main_image']['settings'] = array(
    'image_style' => 'tp_secondary_feature_thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Field: Promo Headline */
  $handler->display->display_options['fields']['field_promo_headline']['id'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['table'] = 'field_data_field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['field'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['label'] = '';
  $handler->display->display_options['fields']['field_promo_headline']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_promo_headline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_headline']['empty'] = '[title]';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['type']['machine_name'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '[field_promo_headline]';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['nid']['link_to_node'] = TRUE;

  /* Display: My Take */
  $handler = $view->new_display('block', 'My Take', 'block_2');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author(s) (field_author) */
  $handler->display->display_options['relationships']['field_author_nid']['id'] = 'field_author_nid';
  $handler->display->display_options['relationships']['field_author_nid']['table'] = 'field_data_field_author';
  $handler->display->display_options['relationships']['field_author_nid']['field'] = 'field_author_nid';
  $handler->display->display_options['relationships']['field_author_nid']['delta'] = '1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Photo */
  $handler->display->display_options['fields']['field_profile_photo']['id'] = 'field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['table'] = 'field_data_field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['field'] = 'field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['relationship'] = 'field_author_nid';
  $handler->display->display_options['fields']['field_profile_photo']['label'] = '';
  $handler->display->display_options['fields']['field_profile_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_photo']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_profile_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_photo']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_profile_photo']['group_column'] = 'fid';
  /* Field: Field: Promo Headline */
  $handler->display->display_options['fields']['field_promo_headline']['id'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['table'] = 'field_data_field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['field'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['label'] = '';
  $handler->display->display_options['fields']['field_promo_headline']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_promo_headline']['element_label_colon'] = FALSE;
  /* Field: Author Name */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_author_nid';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Author Name';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Field: Promo Text */
  $handler->display->display_options['fields']['field_promo_text']['id'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['table'] = 'field_data_field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['field'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['label'] = '';
  $handler->display->display_options['fields']['field_promo_text']['element_label_colon'] = FALSE;

  /* Display: Get Involved */
  $handler = $view->new_display('block', 'Get Involved', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Get Involved';
  $export['promo'] = $view;

  $view = new view();
  $view->name = 'related_actions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Related Actions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Take Action';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['empty'] = '[title]';
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Field: Promo Headline */
  $handler->display->display_options['fields']['field_promo_headline']['id'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['table'] = 'field_data_field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['field'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['label'] = '';
  $handler->display->display_options['fields']['field_promo_headline']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_promo_headline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_headline']['empty'] = '[title]';
  $handler->display->display_options['fields']['field_promo_headline']['hide_alter_empty'] = FALSE;
  /* Field: Field: Promo Text */
  $handler->display->display_options['fields']['field_promo_text']['id'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['table'] = 'field_data_field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['field'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['label'] = '';
  $handler->display->display_options['fields']['field_promo_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_text']['hide_alter_empty'] = FALSE;
  /* Sort criterion: Arguments: Multi-item Argument Order */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'views_sort_by_arg_order';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['order'] = 'DESC';
  $handler->display->display_options['sorts']['weight']['inherit_type'] = 0;
  $handler->display->display_options['sorts']['weight']['argument_number'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Null: Promoted/Ordering */
  $handler->display->display_options['arguments']['null']['id'] = 'null';
  $handler->display->display_options['arguments']['null']['table'] = 'views';
  $handler->display->display_options['arguments']['null']['field'] = 'null';
  $handler->display->display_options['arguments']['null']['ui_name'] = 'Null: Promoted/Ordering';
  $handler->display->display_options['arguments']['null']['default_action'] = 'default';
  $handler->display->display_options['arguments']['null']['default_argument_type'] = 'field';
  $handler->display->display_options['arguments']['null']['default_argument_options']['field'] = 'nodereference::field_related_actions';
  $handler->display->display_options['arguments']['null']['default_argument_options']['settings'] = array(
    'argument_default_field_nodereference_format' => 'nid',
    'argument_default_field_nodereference_delta' => '0',
  );
  $handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['null']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['null']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['null']['validate_options']['code'] = 'return TRUE;';
  /* Contextual filter: Null: Suggested Bool */
  $handler->display->display_options['arguments']['null_1']['id'] = 'null_1';
  $handler->display->display_options['arguments']['null_1']['table'] = 'views';
  $handler->display->display_options['arguments']['null_1']['field'] = 'null';
  $handler->display->display_options['arguments']['null_1']['ui_name'] = 'Null: Suggested Bool';
  $handler->display->display_options['arguments']['null_1']['default_action'] = 'default';
  $handler->display->display_options['arguments']['null_1']['default_argument_type'] = 'field';
  $handler->display->display_options['arguments']['null_1']['default_argument_options']['field'] = 'list_boolean::field_suggest_actions';
  $handler->display->display_options['arguments']['null_1']['default_argument_options']['settings'] = array(
    'list_boolean_true' => '',
    'list_boolean_false' => '',
    'list_boolean_null' => '',
  );
  $handler->display->display_options['arguments']['null_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['null_1']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['null_1']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['null_1']['validate_options']['code'] = 'return TRUE;';
  /* Contextual filter: Related NIDs */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['ui_name'] = 'Related NIDs';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'field';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['field'] = 'nodereference::field_related_actions';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['settings'] = array(
    'argument_default_field_nodereference_format' => 'nid',
    'argument_default_field_nodereference_delta' => '0',
  );
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['nid']['validate_options']['code'] = 'if(isset($view->args[1]) && $view->args[1]) {
  $handler->argument = "all";
}
return TRUE;';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  /* Contextual filter: Field: Topic (field_topic) */
  $handler->display->display_options['arguments']['field_topic_tid']['id'] = 'field_topic_tid';
  $handler->display->display_options['arguments']['field_topic_tid']['table'] = 'field_data_field_topic';
  $handler->display->display_options['arguments']['field_topic_tid']['field'] = 'field_topic_tid';
  $handler->display->display_options['arguments']['field_topic_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_topic_tid']['default_argument_type'] = 'field';
  $handler->display->display_options['arguments']['field_topic_tid']['default_argument_options']['field'] = 'content_taxonomy::field_topic';
  $handler->display->display_options['arguments']['field_topic_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_topic_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_topic_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_topic_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_topic_tid']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['field_topic_tid']['validate_options']['code'] = 'if(isset($view->args[1]) && !$view->args[1]) {
  $handler->argument = "all";
}
return TRUE;';
  /* Contextual filter: Exclude Current Node */
  $handler->display->display_options['arguments']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['arguments']['nid_1']['table'] = 'node';
  $handler->display->display_options['arguments']['nid_1']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid_1']['ui_name'] = 'Exclude Current Node';
  $handler->display->display_options['arguments']['nid_1']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid_1']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid_1']['not'] = TRUE;
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
  );

  /* Display: Curated and/or Suggest */
  $handler = $view->new_display('block', 'Curated and/or Suggest', 'block');

  /* Display: By Sponsor */
  $handler = $view->new_display('block', 'By Sponsor', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Sponsored Actions';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_action_sponsor_nid']['id'] = 'field_action_sponsor_nid';
  $handler->display->display_options['arguments']['field_action_sponsor_nid']['table'] = 'field_data_field_action_sponsor';
  $handler->display->display_options['arguments']['field_action_sponsor_nid']['field'] = 'field_action_sponsor_nid';
  $handler->display->display_options['arguments']['field_action_sponsor_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_action_sponsor_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_action_sponsor_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_action_sponsor_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_action_sponsor_nid']['summary_options']['items_per_page'] = '25';

  /* Display: Term Page Curate and Suggest  */
  $handler = $view->new_display('block', 'Term Page Curate and Suggest ', 'block_3');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Promoted Content */
  $handler->display->display_options['arguments']['null']['id'] = 'null';
  $handler->display->display_options['arguments']['null']['table'] = 'views';
  $handler->display->display_options['arguments']['null']['field'] = 'null';
  $handler->display->display_options['arguments']['null']['ui_name'] = 'Promoted Content';
  $handler->display->display_options['arguments']['null']['default_action'] = 'default';
  $handler->display->display_options['arguments']['null']['default_argument_type'] = 'field';
  $handler->display->display_options['arguments']['null']['default_argument_options']['field'] = 'nodereference::field_related_actions';
  $handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['vocabularies'] = array(
    'action_type' => 0,
    'agency' => 0,
    'blog' => 0,
    'free_tags' => 0,
    'group_type' => 0,
    'photo_credit' => 0,
    'series' => 0,
    'topic' => 0,
  );
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['break_phrase'] = TRUE;
  $export['related_actions'] = $view;

  $view = new view();
  $view->name = 'related_campaigns';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Related Campaigns';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Movies That Matter';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Promo Headline */
  $handler->display->display_options['fields']['field_promo_headline']['id'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['table'] = 'field_data_field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['field'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['label'] = '';
  $handler->display->display_options['fields']['field_promo_headline']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_promo_headline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_headline']['empty'] = '[title]';
  $handler->display->display_options['fields']['field_promo_headline']['hide_alter_empty'] = FALSE;
  /* Field: Field: Promo Text */
  $handler->display->display_options['fields']['field_promo_text']['id'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['table'] = 'field_data_field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['field'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['label'] = '';
  $handler->display->display_options['fields']['field_promo_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_text']['hide_alter_empty'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['id'] = 'field_tp_campaign_cover_image';
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['table'] = 'field_data_field_tp_campaign_cover_image';
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['field'] = 'field_tp_campaign_cover_image';
  /* Sort criterion: Arguments: Multi-item Argument Order */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'views_sort_by_arg_order';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['order'] = 'DESC';
  $handler->display->display_options['sorts']['weight']['inherit_type'] = 0;
  $handler->display->display_options['sorts']['weight']['argument_number'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Null Promoted/Ordering */
  $handler->display->display_options['arguments']['null_1']['id'] = 'null_1';
  $handler->display->display_options['arguments']['null_1']['table'] = 'views';
  $handler->display->display_options['arguments']['null_1']['field'] = 'null';
  $handler->display->display_options['arguments']['null_1']['ui_name'] = 'Null Promoted/Ordering';
  $handler->display->display_options['arguments']['null_1']['default_action'] = 'default';
  $handler->display->display_options['arguments']['null_1']['default_argument_type'] = 'field';
  $handler->display->display_options['arguments']['null_1']['default_argument_options']['field'] = 'nodereference::field_related_campaigns';
  $handler->display->display_options['arguments']['null_1']['default_argument_options']['settings'] = array(
    'argument_default_field_nodereference_format' => 'nid',
    'argument_default_field_nodereference_delta' => '0',
  );
  $handler->display->display_options['arguments']['null_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['null_1']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['null_1']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['null_1']['validate_options']['code'] = 'return TRUE;';
  /* Contextual filter: Null: Suggested Bool */
  $handler->display->display_options['arguments']['null']['id'] = 'null';
  $handler->display->display_options['arguments']['null']['table'] = 'views';
  $handler->display->display_options['arguments']['null']['field'] = 'null';
  $handler->display->display_options['arguments']['null']['ui_name'] = 'Null: Suggested Bool';
  $handler->display->display_options['arguments']['null']['default_action'] = 'default';
  $handler->display->display_options['arguments']['null']['default_argument_type'] = 'field';
  $handler->display->display_options['arguments']['null']['default_argument_options']['field'] = 'list_boolean::field_suggest_campaigns';
  $handler->display->display_options['arguments']['null']['default_argument_options']['settings'] = array(
    'list_boolean_true' => '',
    'list_boolean_false' => '',
    'list_boolean_null' => '',
  );
  $handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['null']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['null']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['null']['validate_options']['code'] = 'return TRUE;';
  /* Contextual filter: Related NIDs */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['ui_name'] = 'Related NIDs';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'field';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['field'] = 'nodereference::field_related_campaigns';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['settings'] = array(
    'argument_default_field_nodereference_format' => 'nid',
    'argument_default_field_nodereference_delta' => '0',
  );
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['nid']['validate_options']['code'] = 'if($view->args[1]) {
  $handler->argument = "all";
}
return TRUE;';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  /* Contextual filter: Topics */
  $handler->display->display_options['arguments']['field_topic_tid']['id'] = 'field_topic_tid';
  $handler->display->display_options['arguments']['field_topic_tid']['table'] = 'field_data_field_topic';
  $handler->display->display_options['arguments']['field_topic_tid']['field'] = 'field_topic_tid';
  $handler->display->display_options['arguments']['field_topic_tid']['ui_name'] = 'Topics';
  $handler->display->display_options['arguments']['field_topic_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_topic_tid']['default_argument_type'] = 'field';
  $handler->display->display_options['arguments']['field_topic_tid']['default_argument_options']['field'] = 'content_taxonomy::field_topic';
  $handler->display->display_options['arguments']['field_topic_tid']['default_argument_options']['settings'] = array(
    'content_taxonomy_format' => 'tid',
  );
  $handler->display->display_options['arguments']['field_topic_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_topic_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_topic_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_topic_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_topic_tid']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['field_topic_tid']['validate_options']['code'] = 'if(!$view->args[1]) {
  $handler->argument = "all";
}
return TRUE;';
  $handler->display->display_options['arguments']['field_topic_tid']['break_phrase'] = TRUE;
  /* Contextual filter: Exclude Current Node */
  $handler->display->display_options['arguments']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['arguments']['nid_1']['table'] = 'node';
  $handler->display->display_options['arguments']['nid_1']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid_1']['ui_name'] = 'Exclude Current Node';
  $handler->display->display_options['arguments']['nid_1']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid_1']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid_1']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid_1']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['nid_1']['validate_options']['code'] = 'return TRUE;';
  $handler->display->display_options['arguments']['nid_1']['not'] = TRUE;
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
    'takepart_campaign' => 'takepart_campaign',
  );

  /* Display: Curate and/or Suggest */
  $handler = $view->new_display('block', 'Curate and/or Suggest', 'block');
  $handler->display->display_options['display_description'] = 'Used on pages that have a suggest and curate field';

  /* Display: Term Page Curate and Suggest */
  $handler = $view->new_display('block', 'Term Page Curate and Suggest', 'block_2');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['id'] = 'field_tp_campaign_cover_image';
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['table'] = 'field_data_field_tp_campaign_cover_image';
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['field'] = 'field_tp_campaign_cover_image';
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['label'] = '';
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['type'] = 'image';
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['settings'] = array(
    'image_style' => 'tp_campaign_cover',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['group_column'] = 'fid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Field: Promo Headline */
  $handler->display->display_options['fields']['field_promo_headline']['id'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['table'] = 'field_data_field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['field'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['label'] = '';
  $handler->display->display_options['fields']['field_promo_headline']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_promo_headline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_headline']['empty'] = '[title]';
  $handler->display->display_options['fields']['field_promo_headline']['hide_alter_empty'] = FALSE;
  /* Field: Field: Promo Text */
  $handler->display->display_options['fields']['field_promo_text']['id'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['table'] = 'field_data_field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['field'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['label'] = '';
  $handler->display->display_options['fields']['field_promo_text']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_promo_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_text']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Promoted Content */
  $handler->display->display_options['arguments']['null']['id'] = 'null';
  $handler->display->display_options['arguments']['null']['table'] = 'views';
  $handler->display->display_options['arguments']['null']['field'] = 'null';
  $handler->display->display_options['arguments']['null']['ui_name'] = 'Promoted Content';
  $handler->display->display_options['arguments']['null']['default_action'] = 'default';
  $handler->display->display_options['arguments']['null']['default_argument_type'] = 'field';
  $handler->display->display_options['arguments']['null']['default_argument_options']['field'] = 'nodereference::field_related_campaigns';
  $handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['vocabularies'] = array(
    'action_type' => 0,
    'agency' => 0,
    'blog' => 0,
    'free_tags' => 0,
    'group_type' => 0,
    'photo_credit' => 0,
    'series' => 0,
    'topic' => 0,
  );
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['break_phrase'] = TRUE;
  $export['related_campaigns'] = $view;

  $view = new view();
  $view->name = 'related_content';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Related Content';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Also See';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Promo Headline */
  $handler->display->display_options['fields']['field_promo_headline']['id'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['table'] = 'field_data_field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['field'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['label'] = '';
  $handler->display->display_options['fields']['field_promo_headline']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_promo_headline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_headline']['empty'] = '[title]';
  $handler->display->display_options['fields']['field_promo_headline']['hide_alter_empty'] = FALSE;
  /* Field: Field: Promo Text */
  $handler->display->display_options['fields']['field_promo_text']['id'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['table'] = 'field_data_field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['field'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['label'] = '';
  $handler->display->display_options['fields']['field_promo_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_text']['hide_alter_empty'] = FALSE;
  /* Sort criterion: Arguments: Multi-item Argument Order */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'views_sort_by_arg_order';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['order'] = 'DESC';
  $handler->display->display_options['sorts']['weight']['inherit_type'] = 0;
  $handler->display->display_options['sorts']['weight']['argument_number'] = '1';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Null: Suggested bool */
  $handler->display->display_options['arguments']['null']['id'] = 'null';
  $handler->display->display_options['arguments']['null']['table'] = 'views';
  $handler->display->display_options['arguments']['null']['field'] = 'null';
  $handler->display->display_options['arguments']['null']['ui_name'] = 'Null: Suggested bool';
  $handler->display->display_options['arguments']['null']['default_action'] = 'default';
  $handler->display->display_options['arguments']['null']['default_argument_type'] = 'field';
  $handler->display->display_options['arguments']['null']['default_argument_options']['field'] = 'list_boolean::field_suggest_content';
  $handler->display->display_options['arguments']['null']['default_argument_options']['settings'] = array(
    'list_boolean_true' => '',
    'list_boolean_false' => '',
    'list_boolean_null' => '',
  );
  $handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['null']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['null']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['null']['validate_options']['code'] = 'return TRUE;';
  /* Contextual filter: Null: Promoted/Ordering */
  $handler->display->display_options['arguments']['null_1']['id'] = 'null_1';
  $handler->display->display_options['arguments']['null_1']['table'] = 'views';
  $handler->display->display_options['arguments']['null_1']['field'] = 'null';
  $handler->display->display_options['arguments']['null_1']['ui_name'] = 'Null: Promoted/Ordering';
  $handler->display->display_options['arguments']['null_1']['default_action'] = 'default';
  $handler->display->display_options['arguments']['null_1']['default_argument_type'] = 'field';
  $handler->display->display_options['arguments']['null_1']['default_argument_options']['field'] = 'nodereference::field_related_content';
  $handler->display->display_options['arguments']['null_1']['default_argument_options']['settings'] = array(
    'argument_default_field_nodereference_format' => 'nid',
    'argument_default_field_nodereference_delta' => '0',
  );
  $handler->display->display_options['arguments']['null_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['null_1']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['null_1']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['null_1']['validate_options']['code'] = 'return TRUE;';
  $handler->display->display_options['arguments']['null_1']['validate']['fail'] = 'ignore';
  /* Contextual filter: Related NIDs */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['ui_name'] = 'Related NIDs';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'field';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['field'] = 'nodereference::field_related_content';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['settings'] = array(
    'argument_default_field_nodereference_format' => 'nid',
    'argument_default_field_nodereference_delta' => '0',
  );
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['nid']['validate_options']['code'] = 'if(isset($view->args[0]) && $view->args[0]) {
  $handler->argument = "all";
}
return TRUE;';
  $handler->display->display_options['arguments']['nid']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  /* Contextual filter: Topics */
  $handler->display->display_options['arguments']['field_topic_tid']['id'] = 'field_topic_tid';
  $handler->display->display_options['arguments']['field_topic_tid']['table'] = 'field_data_field_topic';
  $handler->display->display_options['arguments']['field_topic_tid']['field'] = 'field_topic_tid';
  $handler->display->display_options['arguments']['field_topic_tid']['ui_name'] = 'Topics';
  $handler->display->display_options['arguments']['field_topic_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_topic_tid']['default_argument_type'] = 'field';
  $handler->display->display_options['arguments']['field_topic_tid']['default_argument_options']['field'] = 'content_taxonomy::field_topic';
  $handler->display->display_options['arguments']['field_topic_tid']['default_argument_options']['settings'] = array(
    'content_taxonomy_format' => 'tid',
  );
  $handler->display->display_options['arguments']['field_topic_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_topic_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_topic_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_topic_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_topic_tid']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['field_topic_tid']['validate_options']['code'] = 'if(isset($view->args[0]) && !$view->args[0]) {
  $handler->argument = "all";
}
return TRUE;';
  /* Contextual filter: Exclude Current Node */
  $handler->display->display_options['arguments']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['arguments']['nid_1']['table'] = 'node';
  $handler->display->display_options['arguments']['nid_1']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid_1']['ui_name'] = 'Exclude Current Node';
  $handler->display->display_options['arguments']['nid_1']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid_1']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid_1']['not'] = TRUE;
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
  $handler->display->display_options['filters']['type']['operator'] = 'not in';
  $handler->display->display_options['filters']['type']['value'] = array(
    'action' => 'action',
    'audio' => 'audio',
    'takepart_campaign' => 'takepart_campaign',
    'feed' => 'feed',
    'feed_item' => 'feed_item',
    'takepart_group' => 'takepart_group',
    'mos_action' => 'mos_action',
    'article' => 'article',
    'petition_action' => 'petition_action',
    'openpublish_photo' => 'openpublish_photo',
    'pledge_action' => 'pledge_action',
    'profile' => 'profile',
    'takepart_quick_study' => 'takepart_quick_study',
    'takepart_slide' => 'takepart_slide',
    'section_front' => 'section_front',
    'section_front_wide' => 'section_front_wide',
    'topic_front' => 'topic_front',
    'venue' => 'venue',
    'webform' => 'webform',
  );

  /* Display: Curate and/or Suggest */
  $handler = $view->new_display('block', 'Curate and/or Suggest', 'block');
  $handler->display->display_options['display_description'] = 'Used on pages that have a suggest and curate field';
  $export['related_content'] = $view;

  $view = new view();
  $view->name = 'taxonomy_search_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_site_node_index';
  $view->human_name = 'Taxonomy Search List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Empty';
  $handler->display->display_options['empty']['area']['content'] = 'There is no associated content';
  /* Field: Indexed Content: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['nid']['link_to_entity'] = 0;
  /* Field: Indexed Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Indexed Content: Promo Headline */
  $handler->display->display_options['fields']['field_promo_headline']['id'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['fields']['field_promo_headline']['field'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['label'] = '';
  $handler->display->display_options['fields']['field_promo_headline']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['text'] = '[field_promo_headline] now';
  $handler->display->display_options['fields']['field_promo_headline']['alter']['path'] = '[url]';
  $handler->display->display_options['fields']['field_promo_headline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_headline']['empty'] = '[title]';
  $handler->display->display_options['fields']['field_promo_headline']['empty_zero'] = TRUE;
  /* Field: Indexed Content: Content type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Linked Headline */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['ui_name'] = 'Linked Headline';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['url']['alter']['text'] = '[field_promo_headline] ';
  $handler->display->display_options['fields']['url']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['url']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 1;
  /* Field: Indexed Content: Promo Text */
  $handler->display->display_options['fields']['field_promo_text']['id'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['fields']['field_promo_text']['field'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['label'] = '';
  $handler->display->display_options['fields']['field_promo_text']['element_label_colon'] = FALSE;
  /* Sort criterion: Indexed Content: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Topics [taxonomy_term] */
  $handler->display->display_options['arguments']['field_topic_1']['id'] = 'field_topic_1';
  $handler->display->display_options['arguments']['field_topic_1']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['arguments']['field_topic_1']['field'] = 'field_topic';
  $handler->display->display_options['arguments']['field_topic_1']['ui_name'] = 'Topics [taxonomy_term]';
  $handler->display->display_options['arguments']['field_topic_1']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_topic_1']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_topic_1']['default_argument_options']['vocabularies'] = array(
    'action_type' => 0,
    'agency' => 0,
    'blog' => 0,
    'free_tags' => 0,
    'group_type' => 0,
    'photo_credit' => 0,
    'series' => 0,
    'topic' => 0,
  );
  $handler->display->display_options['arguments']['field_topic_1']['summary']['format'] = 'default_summary';
  /* Filter criterion: Indexed Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'action' => 'action',
    'openpublish_article' => 'openpublish_article',
    'openpublish_blog_post' => 'openpublish_blog_post',
    'feature_article' => 'feature_article',
    'flashcard' => 'flashcard',
    'openpublish_video' => 'openpublish_video',
    'takepart_page' => 'takepart_page',
    'openpublish_photo_gallery' => 'openpublish_photo_gallery',
    'video' => 'video',
  );
  $handler->display->display_options['filters']['type']['group'] = '0';
  /* Filter criterion: Indexed Content: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = '0';

  /* Display: Topic */
  $handler = $view->new_display('block', 'Topic', 'block');
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Content: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['nid']['link_to_entity'] = 0;
  /* Field: Indexed Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Indexed Content: Promo Headline */
  $handler->display->display_options['fields']['field_promo_headline']['id'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['fields']['field_promo_headline']['field'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['label'] = '';
  $handler->display->display_options['fields']['field_promo_headline']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['text'] = 'hi[field_promo_headline]now';
  $handler->display->display_options['fields']['field_promo_headline']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_promo_headline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_headline']['empty'] = '[title]';
  $handler->display->display_options['fields']['field_promo_headline']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_promo_headline']['hide_alter_empty'] = FALSE;
  /* Field: Indexed Content: Content type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Linked Headline */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['ui_name'] = 'Linked Headline';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['url']['alter']['text'] = '[field_promo_headline] ';
  $handler->display->display_options['fields']['url']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['url']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['empty'] = '[title]';
  $handler->display->display_options['fields']['url']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 1;
  /* Field: Indexed Content: Promo Text */
  $handler->display->display_options['fields']['field_promo_text']['id'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['fields']['field_promo_text']['field'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['label'] = '';
  $handler->display->display_options['fields']['field_promo_text']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_promo_text']['element_label_colon'] = FALSE;

  /* Display: Free Tag */
  $handler = $view->new_display('block', 'Free Tag', 'block_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'view-free-tags';
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = 'First';
  $handler->display->display_options['pager']['options']['tags']['previous'] = 'Previous';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'Next';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'Last';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Content: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['nid']['link_to_entity'] = 0;
  /* Field: Indexed Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Indexed Content: Thumbnail Image */
  $handler->display->display_options['fields']['field_thumbnail']['id'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['fields']['field_thumbnail']['field'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_thumbnail']['type'] = 'image';
  $handler->display->display_options['fields']['field_thumbnail']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  /* Field: Indexed Content: Promo Headline */
  $handler->display->display_options['fields']['field_promo_headline']['id'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['fields']['field_promo_headline']['field'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['label'] = '';
  $handler->display->display_options['fields']['field_promo_headline']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['text'] = '[field_promo_headline] now';
  $handler->display->display_options['fields']['field_promo_headline']['alter']['path'] = '[url]';
  $handler->display->display_options['fields']['field_promo_headline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_headline']['empty'] = '[title]';
  $handler->display->display_options['fields']['field_promo_headline']['empty_zero'] = TRUE;
  /* Field: Indexed Content: Content type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['type']['format_name'] = 1;
  /* Field: Linked Headline */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['ui_name'] = 'Linked Headline';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['url']['alter']['text'] = '[field_promo_headline] ';
  $handler->display->display_options['fields']['url']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['url']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 1;
  /* Field: Indexed Content: Promo Text */
  $handler->display->display_options['fields']['field_promo_text']['id'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['fields']['field_promo_text']['field'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['label'] = '';
  $handler->display->display_options['fields']['field_promo_text']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_promo_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Free Tags [taxonomy_term] */
  $handler->display->display_options['arguments']['field_free_tag']['id'] = 'field_free_tag';
  $handler->display->display_options['arguments']['field_free_tag']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['arguments']['field_free_tag']['field'] = 'field_free_tag';
  $handler->display->display_options['arguments']['field_free_tag']['ui_name'] = 'Free Tags [taxonomy_term]';
  $handler->display->display_options['arguments']['field_free_tag']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_free_tag']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_free_tag']['default_argument_options']['vocabularies'] = array(
    'action_type' => 0,
    'agency' => 0,
    'blog' => 0,
    'free_tags' => 0,
    'group_type' => 0,
    'photo_credit' => 0,
    'series' => 0,
    'topic' => 0,
  );
  $handler->display->display_options['arguments']['field_free_tag']['summary']['format'] = 'default_summary';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'action' => 'action',
    'openpublish_article' => 'openpublish_article',
    'openpublish_blog_post' => 'openpublish_blog_post',
    'feature_article' => 'feature_article',
    'flashcard' => 'flashcard',
    'openpublish_video' => 'openpublish_video',
    'takepart_page' => 'takepart_page',
    'openpublish_photo_gallery' => 'openpublish_photo_gallery',
    'video' => 'video',
  );
  $handler->display->display_options['filters']['type']['group'] = '0';
  /* Filter criterion: Indexed Content: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = '0';

  /* Display: Series */
  $handler = $view->new_display('block', 'Series', 'block_2');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'view-topic-listing';
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = 'First';
  $handler->display->display_options['pager']['options']['tags']['previous'] = 'Previous';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'Next';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'Last';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Content: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['nid']['link_to_entity'] = 0;
  /* Field: Indexed Content: Thumbnail Image */
  $handler->display->display_options['fields']['field_thumbnail']['id'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['fields']['field_thumbnail']['field'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_thumbnail']['type'] = 'image';
  $handler->display->display_options['fields']['field_thumbnail']['settings'] = array(
    'image_style' => 'topic_thumbnail',
    'image_link' => 'content',
  );
  /* Field: Indexed Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Indexed Content: Promo Headline */
  $handler->display->display_options['fields']['field_promo_headline']['id'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['fields']['field_promo_headline']['field'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['label'] = '';
  $handler->display->display_options['fields']['field_promo_headline']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['text'] = '[field_promo_headline] now';
  $handler->display->display_options['fields']['field_promo_headline']['alter']['path'] = '[url]';
  $handler->display->display_options['fields']['field_promo_headline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_headline']['empty'] = '[title]';
  $handler->display->display_options['fields']['field_promo_headline']['empty_zero'] = TRUE;
  /* Field: Indexed Content: Content type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Linked Headline */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['ui_name'] = 'Linked Headline';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['url']['alter']['text'] = '[field_promo_headline] ';
  $handler->display->display_options['fields']['url']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['url']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 1;
  /* Field: Indexed Content: Promo Text */
  $handler->display->display_options['fields']['field_promo_text']['id'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['fields']['field_promo_text']['field'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['label'] = '';
  $handler->display->display_options['fields']['field_promo_text']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_promo_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Series [taxonomy_term] */
  $handler->display->display_options['arguments']['field_series']['id'] = 'field_series';
  $handler->display->display_options['arguments']['field_series']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['arguments']['field_series']['field'] = 'field_series';
  $handler->display->display_options['arguments']['field_series']['ui_name'] = 'Series [taxonomy_term]';
  $handler->display->display_options['arguments']['field_series']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_series']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_series']['default_argument_options']['vocabularies'] = array(
    'action_type' => 0,
    'agency' => 0,
    'blog' => 0,
    'free_tags' => 0,
    'group_type' => 0,
    'photo_credit' => 0,
    'series' => 0,
    'topic' => 0,
  );
  $handler->display->display_options['arguments']['field_series']['summary']['format'] = 'default_summary';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'action' => 'action',
    'openpublish_article' => 'openpublish_article',
    'openpublish_blog_post' => 'openpublish_blog_post',
    'campaign' => 'campaign',
    'feature_article' => 'feature_article',
    'flashcard' => 'flashcard',
    'openpublish_video' => 'openpublish_video',
    'takepart_page' => 'takepart_page',
    'openpublish_photo_gallery' => 'openpublish_photo_gallery',
    'video' => 'video',
  );
  $handler->display->display_options['filters']['type']['group'] = '0';
  /* Filter criterion: Indexed Content: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = '0';

  /* Display: Free Tag Feed */
  $handler = $view->new_display('page', 'Free Tag Feed', 'tag_feeds');
  $handler->display->display_options['display_description'] = 'Free Tag filter displayed as RSS';
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_takepart_rss_style';
  $handler->display->display_options['style_options']['schema'] = 'rssimages';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Indexed Content: Promo Headline */
  $handler->display->display_options['fields']['field_promo_headline']['id'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['fields']['field_promo_headline']['field'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['label'] = '';
  $handler->display->display_options['fields']['field_promo_headline']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['text'] = '[field_promo_headline] now';
  $handler->display->display_options['fields']['field_promo_headline']['alter']['path'] = '[url]';
  $handler->display->display_options['fields']['field_promo_headline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_headline']['empty'] = '[title]';
  $handler->display->display_options['fields']['field_promo_headline']['empty_zero'] = TRUE;
  /* Field: Indexed Content: Content type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Linked Headline */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['ui_name'] = 'Linked Headline';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['url']['alter']['text'] = '[field_promo_headline] ';
  $handler->display->display_options['fields']['url']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['url']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 1;
  /* Field: Indexed Content: Promo Text */
  $handler->display->display_options['fields']['field_promo_text']['id'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['fields']['field_promo_text']['field'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['label'] = '';
  $handler->display->display_options['fields']['field_promo_text']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_promo_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'action' => 'action',
    'openpublish_article' => 'openpublish_article',
    'openpublish_blog_post' => 'openpublish_blog_post',
    'feature_article' => 'feature_article',
    'flashcard' => 'flashcard',
    'openpublish_video' => 'openpublish_video',
    'takepart_page' => 'takepart_page',
    'openpublish_photo_gallery' => 'openpublish_photo_gallery',
    'video' => 'video',
  );
  $handler->display->display_options['filters']['type']['group'] = '0';
  /* Filter criterion: Indexed Content: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = '0';
  $handler->display->display_options['path'] = 'content/%/tag_feed.xml';

  /* Display: Admin Tag */
  $handler = $view->new_display('block', 'Admin Tag', 'block_3');
  $handler->display->display_options['display_description'] = 'Search results based on Admin tag';
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Content: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['nid']['link_to_entity'] = 0;
  /* Field: Indexed Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Indexed Content: Promo Headline */
  $handler->display->display_options['fields']['field_promo_headline']['id'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['fields']['field_promo_headline']['field'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['label'] = '';
  $handler->display->display_options['fields']['field_promo_headline']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['text'] = '[field_promo_headline] now';
  $handler->display->display_options['fields']['field_promo_headline']['alter']['path'] = '[url]';
  $handler->display->display_options['fields']['field_promo_headline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_headline']['empty'] = '[title]';
  $handler->display->display_options['fields']['field_promo_headline']['empty_zero'] = TRUE;
  /* Field: Indexed Content: Content type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['type']['format_name'] = 1;
  /* Field: Linked Headline */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['ui_name'] = 'Linked Headline';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['url']['alter']['text'] = '[field_promo_headline] ';
  $handler->display->display_options['fields']['url']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['url']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 1;
  /* Field: Indexed Content: Promo Text */
  $handler->display->display_options['fields']['field_promo_text']['id'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['fields']['field_promo_text']['field'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['label'] = '';
  $handler->display->display_options['fields']['field_promo_text']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_promo_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Admin Tag [taxonomy_term] */
  $handler->display->display_options['arguments']['field_admin_tag']['id'] = 'field_admin_tag';
  $handler->display->display_options['arguments']['field_admin_tag']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['arguments']['field_admin_tag']['field'] = 'field_admin_tag';
  $handler->display->display_options['arguments']['field_admin_tag']['ui_name'] = 'Admin Tag [taxonomy_term]';
  $handler->display->display_options['arguments']['field_admin_tag']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_admin_tag']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_admin_tag']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_admin_tag']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_admin_tag']['not'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'action' => 'action',
    'openpublish_article' => 'openpublish_article',
    'openpublish_blog_post' => 'openpublish_blog_post',
    'feature_article' => 'feature_article',
    'flashcard' => 'flashcard',
    'openpublish_video' => 'openpublish_video',
    'takepart_page' => 'takepart_page',
    'openpublish_photo_gallery' => 'openpublish_photo_gallery',
    'video' => 'video',
  );
  $handler->display->display_options['filters']['type']['group'] = '0';
  /* Filter criterion: Indexed Content: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = '0';
  $export['taxonomy_search_list'] = $view;

  $view = new view();
  $view->name = 'terms_posts_feed_rss';
  $view->description = '';
  $view->tag = 'takepart_feed';
  $view->base_table = 'node';
  $view->human_name = 'Taxonomy RSS Feed';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'TakePart Blogs Feed';
  $handler->display->display_options['use_more_always'] = FALSE;
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
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = FALSE;
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
    'openpublish_blog_post' => 'openpublish_blog_post',
    'openpublish_video' => 'openpublish_video',
    'openpublish_photo_gallery' => 'openpublish_photo_gallery',
    'video' => 'video',
  );

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
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'D, d M Y H:i:s T';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Field: Thumbnail Image */
  $handler->display->display_options['fields']['field_thumbnail']['id'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['table'] = 'field_data_field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['field'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_thumbnail']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_thumbnail']['alter']['text'] = '[field_thumbnail-fid]';
  $handler->display->display_options['fields']['field_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_thumbnail']['type'] = 'image';
  $handler->display->display_options['fields']['field_thumbnail']['settings'] = array(
    'image_style' => 'large',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Series (field_series) */
  $handler->display->display_options['arguments']['field_series_tid']['id'] = 'field_series_tid';
  $handler->display->display_options['arguments']['field_series_tid']['table'] = 'field_data_field_series';
  $handler->display->display_options['arguments']['field_series_tid']['field'] = 'field_series_tid';
  $handler->display->display_options['arguments']['field_series_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_series_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_series_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_series_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'D, d M Y H:i:s T';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_blogpost_main_image']['id'] = 'field_blogpost_main_image';
  $handler->display->display_options['fields']['field_blogpost_main_image']['table'] = 'field_data_field_blogpost_main_image';
  $handler->display->display_options['fields']['field_blogpost_main_image']['field'] = 'field_blogpost_main_image';
  $handler->display->display_options['fields']['field_blogpost_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_blogpost_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_blogpost_main_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_blogpost_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_blogpost_main_image']['type'] = 'image';
  $handler->display->display_options['fields']['field_blogpost_main_image']['settings'] = array(
    'image_style' => 'large',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_blogpost_main_image']['group_column'] = 'fid';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Video Series (field_video_series) */
  $handler->display->display_options['arguments']['field_video_series_tid']['id'] = 'field_video_series_tid';
  $handler->display->display_options['arguments']['field_video_series_tid']['table'] = 'field_data_field_video_series';
  $handler->display->display_options['arguments']['field_video_series_tid']['field'] = 'field_video_series_tid';
  $handler->display->display_options['arguments']['field_video_series_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_video_series_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_video_series_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_video_series_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
    'video' => 'video',
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
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'D, d M Y H:i:s T';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Field: Promo Text */
  $handler->display->display_options['fields']['field_promo_text']['id'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['table'] = 'field_data_field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['field'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['label'] = '';
  $handler->display->display_options['fields']['field_promo_text']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_promo_text']['alter']['text'] = '<br/>[field_promo_text]';
  $handler->display->display_options['fields']['field_promo_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_text']['hide_alter_empty'] = FALSE;
  /* Field: Field: Thumbnail Image */
  $handler->display->display_options['fields']['field_thumbnail']['id'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['table'] = 'field_data_field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['field'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_thumbnail']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_thumbnail']['alter']['text'] = '[field_thumbnail-fid]';
  $handler->display->display_options['fields']['field_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_thumbnail']['type'] = 'image';
  $handler->display->display_options['fields']['field_thumbnail']['settings'] = array(
    'image_style' => 'large',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Topic (field_topic) */
  $handler->display->display_options['arguments']['field_topic_tid']['id'] = 'field_topic_tid';
  $handler->display->display_options['arguments']['field_topic_tid']['table'] = 'field_data_field_topic';
  $handler->display->display_options['arguments']['field_topic_tid']['field'] = 'field_topic_tid';
  $handler->display->display_options['arguments']['field_topic_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_topic_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_topic_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_topic_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
    'action' => 'action',
    'openpublish_article' => 'openpublish_article',
    'feature_article' => 'feature_article',
    'openpublish_video' => 'openpublish_video',
    'openpublish_photo_gallery' => 'openpublish_photo_gallery',
    'video' => 'video',
  );
  $handler->display->display_options['path'] = 'topic/%/feed.xml';

  /* Display: Free Tag Feed */
  $handler = $view->new_display('page', 'Free Tag Feed', 'free_tag_feed');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'TakePart Free Tag Feed ';
  $handler->display->display_options['display_description'] = 'Free Tag filter displayed as RSS';
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
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'D, d M Y H:i:s T';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Field: Thumbnail Image */
  $handler->display->display_options['fields']['field_thumbnail']['id'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['table'] = 'field_data_field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['field'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_thumbnail']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_thumbnail']['alter']['text'] = '[field_thumbnail-fid]';
  $handler->display->display_options['fields']['field_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_thumbnail']['settings'] = array(
    'file_view_mode' => 'default',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Free Tag (field_free_tag) */
  $handler->display->display_options['arguments']['field_free_tag_tid']['id'] = 'field_free_tag_tid';
  $handler->display->display_options['arguments']['field_free_tag_tid']['table'] = 'field_data_field_free_tag';
  $handler->display->display_options['arguments']['field_free_tag_tid']['field'] = 'field_free_tag_tid';
  $handler->display->display_options['arguments']['field_free_tag_tid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_free_tag_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_free_tag_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_free_tag_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_free_tag_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'tag/%/feed.xml';
  $export['terms_posts_feed_rss'] = $view;

  $view = new view();
  $view->name = 'topic_listing';
  $view->description = 'A list of thumbnail/content types/titles for nodes of a given topic.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Topic Listing';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Topic List';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '300';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '300';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = 'First';
  $handler->display->display_options['pager']['options']['tags']['previous'] = 'Previous';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'Next';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'Last';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Field: Thumbnail Image */
  $handler->display->display_options['fields']['field_thumbnail']['id'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['table'] = 'field_data_field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['field'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_thumbnail']['type'] = 'image';
  $handler->display->display_options['fields']['field_thumbnail']['settings'] = array(
    'image_style' => 'topic_thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_thumbnail']['group_column'] = 'fid';
  $handler->display->display_options['fields']['field_thumbnail']['group_columns'] = array(
    'title' => 'title',
  );
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
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['link_class'] = 'node-type-[type_1]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['tid']['title'] = 'Latest in %1';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
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
    'openpublish_photo_gallery' => 'openpublish_photo_gallery',
    'video' => 'video',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['topic_listing'] = $view;

  $view = new view();
  $view->name = 'user_count';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'User Count';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'User Count';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: COUNT(User: Uid) */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['group_type'] = 'count';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'user-count';
  $export['user_count'] = $view;

  $view = new view();
  $view->name = 'user_search';
  $view->description = 'This provides an exposed filtered search for users by admin staff.';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'User Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'User Search';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer users';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['slave'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'edit_node' => 'edit_node',
    'name' => 'name',
    'mail' => 'mail',
    'status' => 'status',
    'created' => 'created',
    'access' => 'access',
    'rid' => 'rid',
  );
  $handler->display->display_options['style_options']['default'] = 'name';
  $handler->display->display_options['style_options']['info'] = array(
    'edit_node' => array(
      'align' => 'views-align-left',
      'separator' => '',
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
    ),
    'mail' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => 'views-align-center',
      'separator' => '',
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => 'views-align-left',
      'separator' => '',
    ),
    'access' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => 'views-align-left',
      'separator' => '',
    ),
    'rid' => array(
      'align' => 'views-align-left',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['hide_alter_empty'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Username';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = FALSE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mail']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['mail']['link_to_user'] = 0;
  /* Field: User: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'users';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created on';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: User: Last access */
  $handler->display->display_options['fields']['access']['id'] = 'access';
  $handler->display->display_options['fields']['access']['table'] = 'users';
  $handler->display->display_options['fields']['access']['field'] = 'access';
  $handler->display->display_options['fields']['access']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['access']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['access']['date_format'] = 'time ago';
  /* Field: User: Active */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'users';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    'all' => 'all',
    3 => '3',
    4 => '4',
    5 => '5',
    6 => '6',
    7 => '7',
  );
  $handler->display->display_options['filters']['rid']['group'] = 0;
  $handler->display->display_options['filters']['rid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['rid']['expose']['operator_id'] = 'rid_op';
  $handler->display->display_options['filters']['rid']['expose']['label'] = 'Roles';
  $handler->display->display_options['filters']['rid']['expose']['operator'] = 'rid_op';
  $handler->display->display_options['filters']['rid']['expose']['identifier'] = 'rid';
  $handler->display->display_options['filters']['rid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['rid']['expose']['reduce'] = TRUE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'users';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  $handler->display->display_options['filters']['status_1']['group'] = 0;
  $handler->display->display_options['filters']['status_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status_1']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status_1']['expose']['label'] = 'Active';
  $handler->display->display_options['filters']['status_1']['expose']['operator'] = 'status_1_op';
  $handler->display->display_options['filters']['status_1']['expose']['identifier'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['status_1']['expose']['remember'] = TRUE;
  /* Filter criterion: User: Name (raw) */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'users';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['group'] = 0;
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Username';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember'] = TRUE;
  /* Filter criterion: User: E-mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['operator'] = 'contains';
  $handler->display->display_options['filters']['mail']['group'] = 0;
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'E-mail';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['remember'] = TRUE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/people/search';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'User Search';
  $handler->display->display_options['menu']['description'] = 'Advanced search allowing to filter by role, status, email, and username.';
  $handler->display->display_options['menu']['weight'] = '-20';
  $handler->display->display_options['menu']['name'] = 'management';
  $export['user_search'] = $view;

  $view = new view();
  $view->name = 'venue_pagination';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Venue Pagination';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Path */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['ui_name'] = 'Path';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = 'node/[nid]';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  /* Field: Previous */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Previous';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<span class="label">Previous:</span><span class="title">[title]</span>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Next */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Next';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<span class="label">Next:</span><span class="title">[title]</span>';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Pagination Counter (PHP) */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'Pagination Counter (PHP)';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$nid = arg(1);
$count = count( $view->result );
foreach($view->result as $key => $value) {
  if($nid == $value->{\'nid\'}) {
    $page = $key + 1;
    break;
  }
}
print "<div id=\\"venue_pagination_count\\"> $page / $count </div>";
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Sort criterion: Broken/missing handler */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  /* Contextual filter: Field: Listing (field_associated_content) */
  $handler->display->display_options['arguments']['field_associated_content_nid']['id'] = 'field_associated_content_nid';
  $handler->display->display_options['arguments']['field_associated_content_nid']['table'] = 'field_data_field_associated_content';
  $handler->display->display_options['arguments']['field_associated_content_nid']['field'] = 'field_associated_content_nid';
  $handler->display->display_options['arguments']['field_associated_content_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_associated_content_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_associated_content_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_associated_content_nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'venue' => 'venue',
  );

  /* Display: Los Angeles */
  $handler = $view->new_display('freepager', 'Los Angeles', 'freepager_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'venue' => 'venue',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field: Listing (field_associated_content) */
  $handler->display->display_options['filters']['field_associated_content_nid']['id'] = 'field_associated_content_nid';
  $handler->display->display_options['filters']['field_associated_content_nid']['table'] = 'field_data_field_associated_content';
  $handler->display->display_options['filters']['field_associated_content_nid']['field'] = 'field_associated_content_nid';
  $handler->display->display_options['filters']['field_associated_content_nid']['value'] = array(
    29609 => '29609',
  );
  $handler->display->display_options['filters']['field_associated_content_nid']['group'] = 1;
  $handler->display->display_options['path'] = 'nid';
  $handler->display->display_options['previous'] = 'nothing';
  $handler->display->display_options['current'] = 'php';
  $handler->display->display_options['next'] = 'nothing_1';

  /* Display: All Venues */
  $handler = $view->new_display('freepager', 'All Venues', 'freepager_2');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['path'] = 'nid';
  $handler->display->display_options['previous'] = 'nothing';
  $handler->display->display_options['current'] = 'php';
  $handler->display->display_options['next'] = 'nothing_1';

  /* Display: NYC */
  $handler = $view->new_display('freepager', 'NYC', 'freepager_3');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'venue' => 'venue',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field: Listing (field_associated_content) */
  $handler->display->display_options['filters']['field_associated_content_nid']['id'] = 'field_associated_content_nid';
  $handler->display->display_options['filters']['field_associated_content_nid']['table'] = 'field_data_field_associated_content';
  $handler->display->display_options['filters']['field_associated_content_nid']['field'] = 'field_associated_content_nid';
  $handler->display->display_options['filters']['field_associated_content_nid']['value'] = array(
    29605 => '29605',
  );
  $handler->display->display_options['filters']['field_associated_content_nid']['group'] = 1;
  $handler->display->display_options['path'] = 'nid';
  $handler->display->display_options['previous'] = 'nothing';
  $handler->display->display_options['current'] = 'php';
  $handler->display->display_options['next'] = 'nothing_1';

  /* Display: Chicago */
  $handler = $view->new_display('freepager', 'Chicago', 'freepager_4');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'venue' => 'venue',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field: Listing (field_associated_content) */
  $handler->display->display_options['filters']['field_associated_content_nid']['id'] = 'field_associated_content_nid';
  $handler->display->display_options['filters']['field_associated_content_nid']['table'] = 'field_data_field_associated_content';
  $handler->display->display_options['filters']['field_associated_content_nid']['field'] = 'field_associated_content_nid';
  $handler->display->display_options['filters']['field_associated_content_nid']['value'] = array(
    29611 => '29611',
  );
  $handler->display->display_options['filters']['field_associated_content_nid']['group'] = 1;
  $handler->display->display_options['path'] = 'nid';
  $handler->display->display_options['previous'] = 'nothing';
  $handler->display->display_options['current'] = 'php';
  $handler->display->display_options['next'] = 'nothing_1';

  /* Display: Austin */
  $handler = $view->new_display('freepager', 'Austin', 'freepager_5');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'venue' => 'venue',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field: Listing (field_associated_content) */
  $handler->display->display_options['filters']['field_associated_content_nid']['id'] = 'field_associated_content_nid';
  $handler->display->display_options['filters']['field_associated_content_nid']['table'] = 'field_data_field_associated_content';
  $handler->display->display_options['filters']['field_associated_content_nid']['field'] = 'field_associated_content_nid';
  $handler->display->display_options['filters']['field_associated_content_nid']['value'] = array(
    29613 => '29613',
  );
  $handler->display->display_options['filters']['field_associated_content_nid']['group'] = 1;
  $handler->display->display_options['path'] = 'nid';
  $handler->display->display_options['previous'] = 'nothing';
  $handler->display->display_options['current'] = 'php';
  $handler->display->display_options['next'] = 'nothing_1';

  /* Display: San Fransisco */
  $handler = $view->new_display('freepager', 'San Fransisco', 'freepager_6');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'venue' => 'venue',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field: Listing (field_associated_content) */
  $handler->display->display_options['filters']['field_associated_content_nid']['id'] = 'field_associated_content_nid';
  $handler->display->display_options['filters']['field_associated_content_nid']['table'] = 'field_data_field_associated_content';
  $handler->display->display_options['filters']['field_associated_content_nid']['field'] = 'field_associated_content_nid';
  $handler->display->display_options['filters']['field_associated_content_nid']['value'] = array(
    29615 => '29615',
  );
  $handler->display->display_options['filters']['field_associated_content_nid']['group'] = 1;
  $handler->display->display_options['path'] = 'nid';
  $handler->display->display_options['previous'] = 'nothing';
  $handler->display->display_options['current'] = 'php';
  $handler->display->display_options['next'] = 'nothing_1';

  /* Display: Boston */
  $handler = $view->new_display('freepager', 'Boston', 'freepager_7');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'venue' => 'venue',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field: Listing (field_associated_content) */
  $handler->display->display_options['filters']['field_associated_content_nid']['id'] = 'field_associated_content_nid';
  $handler->display->display_options['filters']['field_associated_content_nid']['table'] = 'field_data_field_associated_content';
  $handler->display->display_options['filters']['field_associated_content_nid']['field'] = 'field_associated_content_nid';
  $handler->display->display_options['filters']['field_associated_content_nid']['value'] = array(
    29617 => '29617',
  );
  $handler->display->display_options['filters']['field_associated_content_nid']['group'] = 1;
  $handler->display->display_options['path'] = 'nid';
  $handler->display->display_options['previous'] = 'nothing';
  $handler->display->display_options['current'] = 'php';
  $handler->display->display_options['next'] = 'nothing_1';

  /* Display: Twin Cities */
  $handler = $view->new_display('freepager', 'Twin Cities', 'freepager_8');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'venue' => 'venue',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field: Listing (field_associated_content) */
  $handler->display->display_options['filters']['field_associated_content_nid']['id'] = 'field_associated_content_nid';
  $handler->display->display_options['filters']['field_associated_content_nid']['table'] = 'field_data_field_associated_content';
  $handler->display->display_options['filters']['field_associated_content_nid']['field'] = 'field_associated_content_nid';
  $handler->display->display_options['filters']['field_associated_content_nid']['value'] = array(
    29619 => '29619',
  );
  $handler->display->display_options['filters']['field_associated_content_nid']['group'] = 1;
  $handler->display->display_options['path'] = 'nid';
  $handler->display->display_options['previous'] = 'nothing';
  $handler->display->display_options['current'] = 'php';
  $handler->display->display_options['next'] = 'nothing_1';

  /* Display: Seattle */
  $handler = $view->new_display('freepager', 'Seattle', 'freepager_9');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'venue' => 'venue',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field: Listing (field_associated_content) */
  $handler->display->display_options['filters']['field_associated_content_nid']['id'] = 'field_associated_content_nid';
  $handler->display->display_options['filters']['field_associated_content_nid']['table'] = 'field_data_field_associated_content';
  $handler->display->display_options['filters']['field_associated_content_nid']['field'] = 'field_associated_content_nid';
  $handler->display->display_options['filters']['field_associated_content_nid']['value'] = array(
    29621 => '29621',
  );
  $handler->display->display_options['filters']['field_associated_content_nid']['group'] = 1;
  $handler->display->display_options['path'] = 'nid';
  $handler->display->display_options['previous'] = 'nothing';
  $handler->display->display_options['current'] = 'php';
  $handler->display->display_options['next'] = 'nothing_1';

  /* Display: Portland */
  $handler = $view->new_display('freepager', 'Portland', 'freepager_10');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'venue' => 'venue',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field: Listing (field_associated_content) */
  $handler->display->display_options['filters']['field_associated_content_nid']['id'] = 'field_associated_content_nid';
  $handler->display->display_options['filters']['field_associated_content_nid']['table'] = 'field_data_field_associated_content';
  $handler->display->display_options['filters']['field_associated_content_nid']['field'] = 'field_associated_content_nid';
  $handler->display->display_options['filters']['field_associated_content_nid']['value'] = array(
    29623 => '29623',
  );
  $handler->display->display_options['filters']['field_associated_content_nid']['group'] = 1;
  $handler->display->display_options['path'] = 'nid';
  $handler->display->display_options['previous'] = 'nothing';
  $handler->display->display_options['current'] = 'php';
  $handler->display->display_options['next'] = 'nothing_1';

  /* Display: Atlanta (2) */
  $handler = $view->new_display('freepager', 'Atlanta (2)', 'freepager_11');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'venue' => 'venue',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field: Listing (field_associated_content) */
  $handler->display->display_options['filters']['field_associated_content_nid']['id'] = 'field_associated_content_nid';
  $handler->display->display_options['filters']['field_associated_content_nid']['table'] = 'field_data_field_associated_content';
  $handler->display->display_options['filters']['field_associated_content_nid']['field'] = 'field_associated_content_nid';
  $handler->display->display_options['filters']['field_associated_content_nid']['value'] = array(
    29625 => '29625',
  );
  $handler->display->display_options['filters']['field_associated_content_nid']['group'] = 1;
  $handler->display->display_options['path'] = 'nid';
  $handler->display->display_options['previous'] = 'nothing';
  $handler->display->display_options['current'] = 'php';
  $handler->display->display_options['next'] = 'nothing_1';

  /* Display: Contextual */
  $handler = $view->new_display('freepager', 'Contextual', 'freepager_12');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Listing (field_associated_content) */
  $handler->display->display_options['arguments']['field_associated_content_nid']['id'] = 'field_associated_content_nid';
  $handler->display->display_options['arguments']['field_associated_content_nid']['table'] = 'field_data_field_associated_content';
  $handler->display->display_options['arguments']['field_associated_content_nid']['field'] = 'field_associated_content_nid';
  $handler->display->display_options['arguments']['field_associated_content_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_associated_content_nid']['default_argument_type'] = 'field';
  $handler->display->display_options['arguments']['field_associated_content_nid']['default_argument_options']['field'] = 'nodereference::field_associated_content';
  $handler->display->display_options['arguments']['field_associated_content_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_associated_content_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_associated_content_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'venue' => 'venue',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['path'] = 'nid';
  $handler->display->display_options['previous'] = 'nothing';
  $handler->display->display_options['current'] = 'php';
  $handler->display->display_options['next'] = 'nothing_1';

  /* Display: Los Angeles (2) */
  $handler = $view->new_display('freepager', 'Los Angeles (2)', 'freepager_13');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'venue' => 'venue',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field: Listing (field_associated_content) */
  $handler->display->display_options['filters']['field_associated_content_nid']['id'] = 'field_associated_content_nid';
  $handler->display->display_options['filters']['field_associated_content_nid']['table'] = 'field_data_field_associated_content';
  $handler->display->display_options['filters']['field_associated_content_nid']['field'] = 'field_associated_content_nid';
  $handler->display->display_options['filters']['field_associated_content_nid']['value'] = array(
    29609 => '29609',
  );
  $handler->display->display_options['filters']['field_associated_content_nid']['group'] = 1;
  $handler->display->display_options['path'] = 'nid';
  $handler->display->display_options['previous'] = 'nothing';
  $handler->display->display_options['current'] = 'php';
  $handler->display->display_options['next'] = 'nothing_1';

  /* Display: NYC (2) */
  $handler = $view->new_display('freepager', 'NYC (2)', 'freepager_14');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'venue' => 'venue',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field: Listing (field_associated_content) */
  $handler->display->display_options['filters']['field_associated_content_nid']['id'] = 'field_associated_content_nid';
  $handler->display->display_options['filters']['field_associated_content_nid']['table'] = 'field_data_field_associated_content';
  $handler->display->display_options['filters']['field_associated_content_nid']['field'] = 'field_associated_content_nid';
  $handler->display->display_options['filters']['field_associated_content_nid']['value'] = array(
    29605 => '29605',
  );
  $handler->display->display_options['filters']['field_associated_content_nid']['group'] = 1;
  $handler->display->display_options['path'] = 'nid';
  $handler->display->display_options['previous'] = 'nothing';
  $handler->display->display_options['current'] = 'php';
  $handler->display->display_options['next'] = 'nothing_1';

  /* Display: Chicago (2) */
  $handler = $view->new_display('freepager', 'Chicago (2)', 'freepager_15');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'venue' => 'venue',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field: Listing (field_associated_content) */
  $handler->display->display_options['filters']['field_associated_content_nid']['id'] = 'field_associated_content_nid';
  $handler->display->display_options['filters']['field_associated_content_nid']['table'] = 'field_data_field_associated_content';
  $handler->display->display_options['filters']['field_associated_content_nid']['field'] = 'field_associated_content_nid';
  $handler->display->display_options['filters']['field_associated_content_nid']['value'] = array(
    29611 => '29611',
  );
  $handler->display->display_options['filters']['field_associated_content_nid']['group'] = 1;
  $handler->display->display_options['path'] = 'nid';
  $handler->display->display_options['previous'] = 'nothing';
  $handler->display->display_options['current'] = 'php';
  $handler->display->display_options['next'] = 'nothing_1';

  /* Display: Austin (2) */
  $handler = $view->new_display('freepager', 'Austin (2)', 'freepager_16');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'venue' => 'venue',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field: Listing (field_associated_content) */
  $handler->display->display_options['filters']['field_associated_content_nid']['id'] = 'field_associated_content_nid';
  $handler->display->display_options['filters']['field_associated_content_nid']['table'] = 'field_data_field_associated_content';
  $handler->display->display_options['filters']['field_associated_content_nid']['field'] = 'field_associated_content_nid';
  $handler->display->display_options['filters']['field_associated_content_nid']['value'] = array(
    29613 => '29613',
  );
  $handler->display->display_options['filters']['field_associated_content_nid']['group'] = 1;
  $handler->display->display_options['path'] = 'nid';
  $handler->display->display_options['previous'] = 'nothing';
  $handler->display->display_options['current'] = 'php';
  $handler->display->display_options['next'] = 'nothing_1';

  /* Display: San Fransisco (2) */
  $handler = $view->new_display('freepager', 'San Fransisco (2)', 'freepager_17');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'venue' => 'venue',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field: Listing (field_associated_content) */
  $handler->display->display_options['filters']['field_associated_content_nid']['id'] = 'field_associated_content_nid';
  $handler->display->display_options['filters']['field_associated_content_nid']['table'] = 'field_data_field_associated_content';
  $handler->display->display_options['filters']['field_associated_content_nid']['field'] = 'field_associated_content_nid';
  $handler->display->display_options['filters']['field_associated_content_nid']['value'] = array(
    29615 => '29615',
  );
  $handler->display->display_options['filters']['field_associated_content_nid']['group'] = 1;
  $handler->display->display_options['path'] = 'nid';
  $handler->display->display_options['previous'] = 'nothing';
  $handler->display->display_options['current'] = 'php';
  $handler->display->display_options['next'] = 'nothing_1';

  /* Display: Boston (2) */
  $handler = $view->new_display('freepager', 'Boston (2)', 'freepager_18');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'venue' => 'venue',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field: Listing (field_associated_content) */
  $handler->display->display_options['filters']['field_associated_content_nid']['id'] = 'field_associated_content_nid';
  $handler->display->display_options['filters']['field_associated_content_nid']['table'] = 'field_data_field_associated_content';
  $handler->display->display_options['filters']['field_associated_content_nid']['field'] = 'field_associated_content_nid';
  $handler->display->display_options['filters']['field_associated_content_nid']['value'] = array(
    29617 => '29617',
  );
  $handler->display->display_options['filters']['field_associated_content_nid']['group'] = 1;
  $handler->display->display_options['path'] = 'nid';
  $handler->display->display_options['previous'] = 'nothing';
  $handler->display->display_options['current'] = 'php';
  $handler->display->display_options['next'] = 'nothing_1';

  /* Display: Twin Cities (2) */
  $handler = $view->new_display('freepager', 'Twin Cities (2)', 'freepager_19');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'venue' => 'venue',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field: Listing (field_associated_content) */
  $handler->display->display_options['filters']['field_associated_content_nid']['id'] = 'field_associated_content_nid';
  $handler->display->display_options['filters']['field_associated_content_nid']['table'] = 'field_data_field_associated_content';
  $handler->display->display_options['filters']['field_associated_content_nid']['field'] = 'field_associated_content_nid';
  $handler->display->display_options['filters']['field_associated_content_nid']['value'] = array(
    29619 => '29619',
  );
  $handler->display->display_options['filters']['field_associated_content_nid']['group'] = 1;
  $handler->display->display_options['path'] = 'nid';
  $handler->display->display_options['previous'] = 'nothing';
  $handler->display->display_options['current'] = 'php';
  $handler->display->display_options['next'] = 'nothing_1';

  /* Display: Portland (2) */
  $handler = $view->new_display('freepager', 'Portland (2)', 'freepager_20');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'venue' => 'venue',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field: Listing (field_associated_content) */
  $handler->display->display_options['filters']['field_associated_content_nid']['id'] = 'field_associated_content_nid';
  $handler->display->display_options['filters']['field_associated_content_nid']['table'] = 'field_data_field_associated_content';
  $handler->display->display_options['filters']['field_associated_content_nid']['field'] = 'field_associated_content_nid';
  $handler->display->display_options['filters']['field_associated_content_nid']['value'] = array(
    29623 => '29623',
  );
  $handler->display->display_options['filters']['field_associated_content_nid']['group'] = 1;
  $handler->display->display_options['path'] = 'nid';
  $handler->display->display_options['previous'] = 'nothing';
  $handler->display->display_options['current'] = 'php';
  $handler->display->display_options['next'] = 'nothing_1';

  /* Display: Seattle (2) */
  $handler = $view->new_display('freepager', 'Seattle (2)', 'freepager_21');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'venue' => 'venue',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field: Listing (field_associated_content) */
  $handler->display->display_options['filters']['field_associated_content_nid']['id'] = 'field_associated_content_nid';
  $handler->display->display_options['filters']['field_associated_content_nid']['table'] = 'field_data_field_associated_content';
  $handler->display->display_options['filters']['field_associated_content_nid']['field'] = 'field_associated_content_nid';
  $handler->display->display_options['filters']['field_associated_content_nid']['value'] = array(
    29621 => '29621',
  );
  $handler->display->display_options['filters']['field_associated_content_nid']['group'] = 1;
  $handler->display->display_options['path'] = 'nid';
  $handler->display->display_options['previous'] = 'nothing';
  $handler->display->display_options['current'] = 'php';
  $handler->display->display_options['next'] = 'nothing_1';

  /* Display: Atlanta */
  $handler = $view->new_display('freepager', 'Atlanta', 'freepager_22');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'venue' => 'venue',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field: Listing (field_associated_content) */
  $handler->display->display_options['filters']['field_associated_content_nid']['id'] = 'field_associated_content_nid';
  $handler->display->display_options['filters']['field_associated_content_nid']['table'] = 'field_data_field_associated_content';
  $handler->display->display_options['filters']['field_associated_content_nid']['field'] = 'field_associated_content_nid';
  $handler->display->display_options['filters']['field_associated_content_nid']['value'] = array(
    29625 => '29625',
  );
  $handler->display->display_options['filters']['field_associated_content_nid']['group'] = 1;
  $handler->display->display_options['path'] = 'nid';
  $handler->display->display_options['previous'] = 'nothing';
  $handler->display->display_options['current'] = 'php';
  $handler->display->display_options['next'] = 'nothing_1';
  $export['venue_pagination'] = $view;

  $view = new view();
  $view->name = 'venue_pagination_sorter';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Venue Pagination Sorter';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'nid' => 'nid',
    'nothing' => 'nothing',
    'nothing_1' => 'nothing_1',
    'php' => 'php',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
    ),
    'nothing_1' => array(
      'align' => '',
      'separator' => '',
    ),
    'php' => array(
      'align' => '',
      'separator' => '',
    ),
  );
  /* Field: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'node';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['label'] = 'Content to Sort';
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  /* Sort criterion: Broken/missing handler */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  /* Contextual filter: Field: Listing (field_associated_content) */
  $handler->display->display_options['arguments']['field_associated_content_nid']['id'] = 'field_associated_content_nid';
  $handler->display->display_options['arguments']['field_associated_content_nid']['table'] = 'field_data_field_associated_content';
  $handler->display->display_options['arguments']['field_associated_content_nid']['field'] = 'field_associated_content_nid';
  $handler->display->display_options['arguments']['field_associated_content_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_associated_content_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_associated_content_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_associated_content_nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'venue' => 'venue',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'venuesorter';
  $export['venue_pagination_sorter'] = $view;

  $view = new view();
  $view->name = 'video';
  $view->description = 'Views and display pages for all things related to video.';
  $view->tag = 'default video';
  $view->base_table = 'node';
  $view->human_name = 'Video';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Related Videos';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['slave'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['label'] = 'Rotator navigation';
  $handler->display->display_options['header']['php']['php_output'] = '<div class="rotator_nav_bar">
</div>';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_main_image']['id'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['table'] = 'field_data_field_main_image';
  $handler->display->display_options['fields']['field_main_image']['field'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_main_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_main_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_main_image']['type'] = 'image';
  $handler->display->display_options['fields']['field_main_image']['settings'] = array(
    'image_style' => 'tp_large_rail_wide',
    'image_link' => 'content',
  );
  /* Field: Field: Thumbnail Image */
  $handler->display->display_options['fields']['field_thumbnail']['id'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['table'] = 'field_data_field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['field'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['empty'] = '[field_main_image]';
  $handler->display->display_options['fields']['field_thumbnail']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_thumbnail']['type'] = 'image';
  $handler->display->display_options['fields']['field_thumbnail']['settings'] = array(
    'image_style' => 'tp_popular_gallery_thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_thumbnail']['group_column'] = 'fid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Field: Promo Headline */
  $handler->display->display_options['fields']['field_promo_headline']['id'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['table'] = 'field_data_field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['field'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['label'] = '';
  $handler->display->display_options['fields']['field_promo_headline']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_promo_headline']['element_type'] = 'h3';
  $handler->display->display_options['fields']['field_promo_headline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_headline']['empty'] = '[title]';
  $handler->display->display_options['fields']['field_promo_headline']['hide_alter_empty'] = FALSE;
  /* Field: Field: Promo Text */
  $handler->display->display_options['fields']['field_promo_text']['id'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['table'] = 'field_data_field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['field'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['label'] = '';
  $handler->display->display_options['fields']['field_promo_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_text']['hide_alter_empty'] = FALSE;
  /* Sort criterion: Arguments: Multi-item Argument Order */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'views_sort_by_arg_order';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['order'] = 'DESC';
  $handler->display->display_options['sorts']['weight']['inherit_type'] = 0;
  $handler->display->display_options['sorts']['weight']['argument_number'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Post date';
  /* Contextual filter: Null: Promoted/Ordering */
  $handler->display->display_options['arguments']['null']['id'] = 'null';
  $handler->display->display_options['arguments']['null']['table'] = 'views';
  $handler->display->display_options['arguments']['null']['field'] = 'null';
  $handler->display->display_options['arguments']['null']['ui_name'] = 'Null: Promoted/Ordering';
  $handler->display->display_options['arguments']['null']['default_action'] = 'default';
  $handler->display->display_options['arguments']['null']['default_argument_type'] = 'field';
  $handler->display->display_options['arguments']['null']['default_argument_options']['field'] = 'nodereference::field_video_related';
  $handler->display->display_options['arguments']['null']['default_argument_options']['settings'] = array(
    'argument_default_field_nodereference_format' => 'nid',
    'argument_default_field_nodereference_delta' => '0',
  );
  $handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: NULL: Suggested Bool */
  $handler->display->display_options['arguments']['null_1']['id'] = 'null_1';
  $handler->display->display_options['arguments']['null_1']['table'] = 'views';
  $handler->display->display_options['arguments']['null_1']['field'] = 'null';
  $handler->display->display_options['arguments']['null_1']['ui_name'] = 'NULL: Suggested Bool';
  $handler->display->display_options['arguments']['null_1']['default_action'] = 'default';
  $handler->display->display_options['arguments']['null_1']['default_argument_type'] = 'field';
  $handler->display->display_options['arguments']['null_1']['default_argument_options']['field'] = 'list_boolean::field_suggest_video';
  $handler->display->display_options['arguments']['null_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null_1']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Related NIDs */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['ui_name'] = 'Related NIDs';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'field';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['field'] = 'nodereference::field_video_related';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['settings'] = array(
    'argument_default_field_nodereference_format' => 'nid',
    'argument_default_field_nodereference_delta' => '0',
  );
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['nid']['validate_options']['code'] = 'if(isset($view->args[1]) && $view->args[1]) {
  $handler->argument = "all";
}
return TRUE;';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  /* Contextual filter: Topics */
  $handler->display->display_options['arguments']['field_topic_tid']['id'] = 'field_topic_tid';
  $handler->display->display_options['arguments']['field_topic_tid']['table'] = 'field_data_field_topic';
  $handler->display->display_options['arguments']['field_topic_tid']['field'] = 'field_topic_tid';
  $handler->display->display_options['arguments']['field_topic_tid']['ui_name'] = 'Topics';
  $handler->display->display_options['arguments']['field_topic_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_topic_tid']['default_argument_type'] = 'field';
  $handler->display->display_options['arguments']['field_topic_tid']['default_argument_options']['field'] = 'content_taxonomy::field_topic';
  $handler->display->display_options['arguments']['field_topic_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_topic_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_topic_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_topic_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_topic_tid']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['field_topic_tid']['validate_options']['code'] = 'if(isset($view->args[1]) && !$view->args[1]) {
  $handler->argument = "all";
}
return TRUE;';
  $handler->display->display_options['arguments']['field_topic_tid']['break_phrase'] = TRUE;
  /* Contextual filter: Exclude Current Node */
  $handler->display->display_options['arguments']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['arguments']['nid_1']['table'] = 'node';
  $handler->display->display_options['arguments']['nid_1']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid_1']['ui_name'] = 'Exclude Current Node';
  $handler->display->display_options['arguments']['nid_1']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid_1']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid_1']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid_1']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['nid_1']['validate_options']['code'] = 'return TRUE;';
  $handler->display->display_options['arguments']['nid_1']['not'] = TRUE;
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

  /* Display: Currated and Suggest */
  $handler = $view->new_display('block', 'Currated and Suggest', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  /* Display: Currated Only */
  $handler = $view->new_display('block', 'Currated Only', 'block_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'field_thumbnail',
    'field_main_image' => 'field_thumbnail',
    'field_thumbnail' => 'field_thumbnail',
    'title' => 'field_promo_headline',
    'field_promo_headline' => 'field_promo_headline',
    'field_promo_text' => 'field_promo_headline',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_main_image' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_thumbnail' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_promo_headline' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_promo_text' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_main_image']['id'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['table'] = 'field_data_field_main_image';
  $handler->display->display_options['fields']['field_main_image']['field'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_main_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_main_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_main_image']['type'] = 'image';
  $handler->display->display_options['fields']['field_main_image']['settings'] = array(
    'image_style' => 'tp_large_rail_wide',
    'image_link' => 'content',
  );
  /* Field: Field: Thumbnail Image */
  $handler->display->display_options['fields']['field_thumbnail']['id'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['table'] = 'field_data_field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['field'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['empty'] = '[field_main_image]';
  $handler->display->display_options['fields']['field_thumbnail']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_thumbnail']['type'] = 'image';
  $handler->display->display_options['fields']['field_thumbnail']['settings'] = array(
    'image_style' => 'tp_large_rail_wide',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Field: Promo Headline */
  $handler->display->display_options['fields']['field_promo_headline']['id'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['table'] = 'field_data_field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['field'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['label'] = '';
  $handler->display->display_options['fields']['field_promo_headline']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_promo_headline']['element_type'] = 'h3';
  $handler->display->display_options['fields']['field_promo_headline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_headline']['empty'] = '[title]';
  $handler->display->display_options['fields']['field_promo_headline']['hide_alter_empty'] = FALSE;
  /* Field: Field: Promo Text */
  $handler->display->display_options['fields']['field_promo_text']['id'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['table'] = 'field_data_field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['field'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['label'] = '';
  $handler->display->display_options['fields']['field_promo_text']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_promo_text']['alter']['text'] = '<div class="promo-text">[field_promo_text]</div>';
  $handler->display->display_options['fields']['field_promo_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_text']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'field';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['field'] = 'nodereference::field_video_related';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;

  /* Display: TakePart TV */
  $handler = $view->new_display('block', 'TakePart TV', 'block_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'TakePart TV';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Embedded Video */
  $handler->display->display_options['fields']['field_video_embedded']['id'] = 'field_video_embedded';
  $handler->display->display_options['fields']['field_video_embedded']['table'] = 'field_data_field_video_embedded';
  $handler->display->display_options['fields']['field_video_embedded']['field'] = 'field_video_embedded';
  $handler->display->display_options['fields']['field_video_embedded']['label'] = '';
  $handler->display->display_options['fields']['field_video_embedded']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_video_embedded']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_video_embedded']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_video_embedded']['settings'] = array(
    'file_view_mode' => 'media_large',
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  /* Field: Field: Promo Headline */
  $handler->display->display_options['fields']['field_promo_headline']['id'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['table'] = 'field_data_field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['field'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['label'] = '';
  $handler->display->display_options['fields']['field_promo_headline']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_promo_headline']['element_type'] = 'h3';
  $handler->display->display_options['fields']['field_promo_headline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_headline']['hide_alter_empty'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_wrapper_class'] = 'full-video';
  $handler->display->display_options['fields']['view_node']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Full Video';
  /* Field: Field: Promo Text */
  $handler->display->display_options['fields']['field_promo_text']['id'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['table'] = 'field_data_field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['field'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['label'] = '';
  $handler->display->display_options['fields']['field_promo_text']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_promo_text']['alter']['text'] = '[field_promo_text] [view_node]';
  $handler->display->display_options['fields']['field_promo_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_text']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'field';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['field'] = 'nodereference::field_video_related';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;

  /* Display: Currated horizontal */
  $handler = $view->new_display('block', 'Currated horizontal', 'block_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'field';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['field'] = 'nodereference::field_video_related';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;

  /* Display: Featured */
  $handler = $view->new_display('block', 'Featured', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['style_options']['row_class'] = 'featured-video';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_main_image']['id'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['table'] = 'field_data_field_main_image';
  $handler->display->display_options['fields']['field_main_image']['field'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_main_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_main_image']['type'] = 'image';
  $handler->display->display_options['fields']['field_main_image']['settings'] = array(
    'image_style' => 'tp_content_wide',
    'image_link' => 'content',
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node_1']['id'] = 'view_node_1';
  $handler->display->display_options['fields']['view_node_1']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node_1']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node_1']['label'] = 'Play Button';
  $handler->display->display_options['fields']['view_node_1']['element_type'] = '0';
  $handler->display->display_options['fields']['view_node_1']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['view_node_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node_1']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['view_node_1']['text'] = 'View Video';
  /* Field: Field: Promo Headline */
  $handler->display->display_options['fields']['field_promo_headline']['id'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['table'] = 'field_data_field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['field'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['label'] = '';
  $handler->display->display_options['fields']['field_promo_headline']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_promo_headline']['element_type'] = 'h3';
  $handler->display->display_options['fields']['field_promo_headline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_headline']['hide_alter_empty'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node_2']['id'] = 'view_node_2';
  $handler->display->display_options['fields']['view_node_2']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node_2']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node_2']['label'] = '';
  $handler->display->display_options['fields']['view_node_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['view_node_2']['alter']['text'] = '[field_promo_headline]';
  $handler->display->display_options['fields']['view_node_2']['alter']['path'] = 'node/';
  $handler->display->display_options['fields']['view_node_2']['element_type'] = 'h3';
  $handler->display->display_options['fields']['view_node_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node_2']['element_wrapper_class'] = 'views-field-field-promo-headline';
  $handler->display->display_options['fields']['view_node_2']['hide_alter_empty'] = FALSE;
  /* Field: Field: Promo Text */
  $handler->display->display_options['fields']['field_promo_text']['id'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['table'] = 'field_data_field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['field'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['label'] = '';
  $handler->display->display_options['fields']['field_promo_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_text']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'field';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['field'] = 'nodereference::field_feature_video';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['settings'] = array(
    'argument_default_field_nodereference_format' => 'nid',
    'argument_default_field_nodereference_delta' => '0',
  );
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;

  /* Display: Suggested horizontal */
  $handler = $view->new_display('block', 'Suggested horizontal', 'block_5');
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'field';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['field'] = 'content_taxonomy::field_video_series';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['settings'] = array(
    'content_taxonomy_format' => 'tid',
  );
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['reduce_duplicates'] = TRUE;

  /* Display: Series List */
  $handler = $view->new_display('block', 'Series List', 'block_6');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Videos In the Series';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  /* Field: Field: Thumbnail Image */
  $handler->display->display_options['fields']['field_thumbnail']['id'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['table'] = 'field_data_field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['field'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_thumbnail']['type'] = 'image';
  $handler->display->display_options['fields']['field_thumbnail']['settings'] = array(
    'image_style' => 'tp_popular_gallery_thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_thumbnail']['group_column'] = 'fid';
  /* Field: Field: Promo Headline */
  $handler->display->display_options['fields']['field_promo_headline']['id'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['table'] = 'field_data_field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['field'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['label'] = '';
  $handler->display->display_options['fields']['field_promo_headline']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_promo_headline']['element_type'] = 'h3';
  $handler->display->display_options['fields']['field_promo_headline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_headline']['hide_alter_empty'] = FALSE;
  /* Field: Field: Promo Text */
  $handler->display->display_options['fields']['field_promo_text']['id'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['table'] = 'field_data_field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['field'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['label'] = '';
  $handler->display->display_options['fields']['field_promo_text']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_promo_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_text']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Video Series (field_video_series) */
  $handler->display->display_options['arguments']['field_video_series_tid']['id'] = 'field_video_series_tid';
  $handler->display->display_options['arguments']['field_video_series_tid']['table'] = 'field_data_field_video_series';
  $handler->display->display_options['arguments']['field_video_series_tid']['field'] = 'field_video_series_tid';
  $handler->display->display_options['arguments']['field_video_series_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_video_series_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_video_series_tid']['default_argument_options']['vocabularies'] = array(
    'action_type' => 0,
    'agency' => 0,
    'blog' => 0,
    'free_tags' => 0,
    'group_type' => 0,
    'photo_credit' => 0,
    'series' => 0,
    'topic' => 0,
    'video_series' => 0,
  );
  $handler->display->display_options['arguments']['field_video_series_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_video_series_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_video_series_tid']['summary_options']['items_per_page'] = '25';

  /* Display: Series List On Video Node */
  $handler = $view->new_display('block', 'Series List On Video Node', 'block_8');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Videos In Series';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'jcarousel';
  $handler->display->display_options['style_options']['wrap'] = '0';
  $handler->display->display_options['style_options']['skin'] = '';
  $handler->display->display_options['style_options']['visible'] = '3';
  $handler->display->display_options['style_options']['auto'] = '0';
  $handler->display->display_options['style_options']['autoPause'] = 1;
  $handler->display->display_options['style_options']['easing'] = '';
  $handler->display->display_options['style_options']['vertical'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_main_image']['id'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['table'] = 'field_data_field_main_image';
  $handler->display->display_options['fields']['field_main_image']['field'] = 'field_main_image';
  $handler->display->display_options['fields']['field_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_main_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_main_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_main_image']['type'] = 'image';
  $handler->display->display_options['fields']['field_main_image']['settings'] = array(
    'image_style' => 'tp_large_rail_wide',
    'image_link' => 'content',
  );
  /* Field: Field: Thumbnail Image */
  $handler->display->display_options['fields']['field_thumbnail']['id'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['table'] = 'field_data_field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['field'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['empty'] = '[field_main_image]';
  $handler->display->display_options['fields']['field_thumbnail']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_thumbnail']['type'] = 'image';
  $handler->display->display_options['fields']['field_thumbnail']['settings'] = array(
    'image_style' => 'tp_popular_gallery_thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_thumbnail']['group_column'] = 'fid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Field: Promo Headline */
  $handler->display->display_options['fields']['field_promo_headline']['id'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['table'] = 'field_data_field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['field'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['label'] = '';
  $handler->display->display_options['fields']['field_promo_headline']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_promo_headline']['element_type'] = 'h3';
  $handler->display->display_options['fields']['field_promo_headline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_headline']['empty'] = '[title]';
  $handler->display->display_options['fields']['field_promo_headline']['hide_alter_empty'] = FALSE;
  /* Field: Field: Promo Text */
  $handler->display->display_options['fields']['field_promo_text']['id'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['table'] = 'field_data_field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['field'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['label'] = '';
  $handler->display->display_options['fields']['field_promo_text']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_promo_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_text']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Video Series (field_video_series) */
  $handler->display->display_options['arguments']['field_video_series_tid']['id'] = 'field_video_series_tid';
  $handler->display->display_options['arguments']['field_video_series_tid']['table'] = 'field_data_field_video_series';
  $handler->display->display_options['arguments']['field_video_series_tid']['field'] = 'field_video_series_tid';
  $handler->display->display_options['arguments']['field_video_series_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_video_series_tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_video_series_tid']['title'] = 'Videos In %1';
  $handler->display->display_options['arguments']['field_video_series_tid']['default_argument_type'] = 'field';
  $handler->display->display_options['arguments']['field_video_series_tid']['default_argument_options']['field'] = 'content_taxonomy::field_video_series';
  $handler->display->display_options['arguments']['field_video_series_tid']['default_argument_options']['settings'] = array(
    'content_taxonomy_format' => 'tid',
  );
  $handler->display->display_options['arguments']['field_video_series_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_video_series_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_video_series_tid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Global: Null */
  $handler->display->display_options['arguments']['null']['id'] = 'null';
  $handler->display->display_options['arguments']['null']['table'] = 'views';
  $handler->display->display_options['arguments']['null']['field'] = 'null';
  $handler->display->display_options['arguments']['null']['default_action'] = 'default';
  $handler->display->display_options['arguments']['null']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['null']['title'] = 'Videos in %2';
  $handler->display->display_options['arguments']['null']['default_argument_type'] = 'field';
  $handler->display->display_options['arguments']['null']['default_argument_options']['field'] = 'content_taxonomy::field_video_series';
  $handler->display->display_options['arguments']['null']['default_argument_options']['settings'] = array(
    'content_taxonomy_format' => 'name',
  );
  $handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';

  /* Display: Most Recent */
  $handler = $view->new_display('block', 'Most Recent', 'block_7');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Recent Videos';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $export['video'] = $view;

  return $export;
}
