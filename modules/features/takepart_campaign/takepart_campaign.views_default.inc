<?php
/**
 * @file
 * takepart_campaign.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function takepart_campaign_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'campaigns';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Campaigns';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Campaigns';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
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
  /* Sort criterion: Arguments: Multi-item Argument Order */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'views_sort_by_arg_order';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'takepart_campaign' => 'takepart_campaign',
  );
  
  /* Display: List of Campaigns */
  $handler = $view->new_display('block', 'List of Campaigns', 'block');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Featured Campaigns (Excluded) */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['ui_name'] = 'Featured Campaigns (Excluded)';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['nid']['not'] = 1;
  
  /* Display: Featured Campaigns */
  $handler = $view->new_display('block', 'Featured Campaigns', 'block_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
    'image_style' => 'tp_campaign_cover',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_tp_campaign_cover_image']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
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
  $handler->display->display_options['fields']['field_tp_campaign_subheadline']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_tp_campaign_subheadline']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_tp_campaign_subheadline']['field_api_classes'] = 0;
  $export['related_campaigns'] = $view;

  return $export;
}
