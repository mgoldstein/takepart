<?php
/**
 * @file
 * takepart_promo.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function takepart_promo_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'promo';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Promo';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My Take';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['slave'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['id'] = 'field_tp_campaign_cover_image';
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['table'] = 'field_data_field_tp_campaign_cover_image';
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['field'] = 'field_tp_campaign_cover_image';
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['label'] = '';
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['type'] = 'image';
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['settings'] = array(
    'image_style' => 'tp_actions_impact_thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['field_api_classes'] = 0;
  /* Field: Content: Article Image */
  $handler->display->display_options['fields']['field_action_main_image']['id'] = 'field_action_main_image';
  $handler->display->display_options['fields']['field_action_main_image']['table'] = 'field_data_field_action_main_image';
  $handler->display->display_options['fields']['field_action_main_image']['field'] = 'field_action_main_image';
  $handler->display->display_options['fields']['field_action_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_action_main_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_action_main_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_action_main_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_action_main_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_action_main_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_action_main_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_action_main_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_action_main_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_action_main_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_action_main_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_action_main_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_action_main_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_action_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_action_main_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_action_main_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_action_main_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_action_main_image']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_action_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_action_main_image']['type'] = 'image';
  $handler->display->display_options['fields']['field_action_main_image']['settings'] = array(
    'image_style' => 'tp_actions_impact_thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_action_main_image']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Promo Headline */
  $handler->display->display_options['fields']['field_promo_headline']['id'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['table'] = 'field_data_field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['field'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['label'] = '';
  $handler->display->display_options['fields']['field_promo_headline']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_promo_headline']['empty'] = '[title]';
  $handler->display->display_options['fields']['field_promo_headline']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['field_api_classes'] = 0;
  /* Field: Content: Sub Headline */
  $handler->display->display_options['fields']['field_tp_campaign_subheadline']['id'] = 'field_tp_campaign_subheadline';
  $handler->display->display_options['fields']['field_tp_campaign_subheadline']['table'] = 'field_data_field_tp_campaign_subheadline';
  $handler->display->display_options['fields']['field_tp_campaign_subheadline']['field'] = 'field_tp_campaign_subheadline';
  $handler->display->display_options['fields']['field_tp_campaign_subheadline']['label'] = '';
  $handler->display->display_options['fields']['field_tp_campaign_subheadline']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_tp_campaign_subheadline']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_tp_campaign_subheadline']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_tp_campaign_subheadline']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_tp_campaign_subheadline']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_tp_campaign_subheadline']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_tp_campaign_subheadline']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_tp_campaign_subheadline']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_tp_campaign_subheadline']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_tp_campaign_subheadline']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_tp_campaign_subheadline']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_tp_campaign_subheadline']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_tp_campaign_subheadline']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_tp_campaign_subheadline']['empty'] = '[field_promo_headline] ';
  $handler->display->display_options['fields']['field_tp_campaign_subheadline']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_tp_campaign_subheadline']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_tp_campaign_subheadline']['field_api_classes'] = 0;
  /* Field: Content: Promo Text */
  $handler->display->display_options['fields']['field_promo_text']['id'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['table'] = 'field_data_field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['field'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['label'] = '';
  $handler->display->display_options['fields']['field_promo_text']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_promo_text']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_promo_text']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_promo_text']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['field_api_classes'] = 0;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['type']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['type']['link_to_node'] = 1;
  $handler->display->display_options['fields']['type']['machine_name'] = 0;
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
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: News to Know */
  $handler = $view->new_display('block', 'News to Know', 'block');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Content: Promo Headline */
  $handler->display->display_options['fields']['field_promo_headline']['id'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['table'] = 'field_data_field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['field'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['label'] = '';
  $handler->display->display_options['fields']['field_promo_headline']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_promo_headline']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_headline']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_promo_headline']['empty'] = '[title]';
  $handler->display->display_options['fields']['field_promo_headline']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['field_api_classes'] = 0;

  /* Display: Features */
  $handler = $view->new_display('block', 'Features', 'block_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Display Tag */
  $handler->display->display_options['fields']['field_display_tag']['id'] = 'field_display_tag';
  $handler->display->display_options['fields']['field_display_tag']['table'] = 'field_data_field_display_tag';
  $handler->display->display_options['fields']['field_display_tag']['field'] = 'field_display_tag';
  $handler->display->display_options['fields']['field_display_tag']['label'] = '';
  $handler->display->display_options['fields']['field_display_tag']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_display_tag']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_display_tag']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_display_tag']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_display_tag']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_display_tag']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_display_tag']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_display_tag']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_display_tag']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_display_tag']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_display_tag']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_display_tag']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_display_tag']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_display_tag']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_display_tag']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_display_tag']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_display_tag']['field_api_classes'] = 0;
  /* Field: Content: Thumbnail Image */
  $handler->display->display_options['fields']['field_thumbnail_1']['id'] = 'field_thumbnail_1';
  $handler->display->display_options['fields']['field_thumbnail_1']['table'] = 'field_data_field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail_1']['field'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail_1']['label'] = '';
  $handler->display->display_options['fields']['field_thumbnail_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_thumbnail_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_thumbnail_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_thumbnail_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_thumbnail_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_thumbnail_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_thumbnail_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_thumbnail_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_thumbnail_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_thumbnail_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_thumbnail_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_thumbnail_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_thumbnail_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_thumbnail_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_thumbnail_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_thumbnail_1']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_thumbnail_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_thumbnail_1']['type'] = 'image';
  $handler->display->display_options['fields']['field_thumbnail_1']['settings'] = array(
    'image_style' => 'tp_secondary_feature_thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_thumbnail_1']['field_api_classes'] = 0;
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

  /* Display: My Take */
  $handler = $view->new_display('block', 'My Take', 'block_2');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author(s) (field_author) */
  $handler->display->display_options['relationships']['field_author_nid']['id'] = 'field_author_nid';
  $handler->display->display_options['relationships']['field_author_nid']['table'] = 'field_data_field_author';
  $handler->display->display_options['relationships']['field_author_nid']['field'] = 'field_author_nid';
  $handler->display->display_options['relationships']['field_author_nid']['required'] = 0;
  $handler->display->display_options['relationships']['field_author_nid']['delta'] = '1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Content: Photo */
  $handler->display->display_options['fields']['field_profile_photo']['id'] = 'field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['table'] = 'field_data_field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['field'] = 'field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['relationship'] = 'field_author_nid';
  $handler->display->display_options['fields']['field_profile_photo']['label'] = '';
  $handler->display->display_options['fields']['field_profile_photo']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_photo']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_profile_photo']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_profile_photo']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_profile_photo']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_profile_photo']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_profile_photo']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_profile_photo']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_photo']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_photo']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_photo']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_profile_photo']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_photo']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_photo']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_profile_photo']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_photo']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_profile_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_photo']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_profile_photo']['field_api_classes'] = 0;
  /* Field: Content: Promo Headline */
  $handler->display->display_options['fields']['field_promo_headline']['id'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['table'] = 'field_data_field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['field'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['label'] = '';
  $handler->display->display_options['fields']['field_promo_headline']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_promo_headline']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_promo_headline']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['field_api_classes'] = 0;
  /* Field: Author Name */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_author_nid';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Author Name';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Promo Text */
  $handler->display->display_options['fields']['field_promo_text']['id'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['table'] = 'field_data_field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['field'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['label'] = '';
  $handler->display->display_options['fields']['field_promo_text']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_promo_text']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_promo_text']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_promo_text']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['field_api_classes'] = 0;

  /* Display: Get Involved */
  $handler = $view->new_display('block', 'Get Involved', 'block_3');
  $export['promo'] = $view;

  return $export;
}
