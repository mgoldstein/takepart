<?php
/**
 * @file
 * takepart_action.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function takepart_action_views_default_views() {
  $export = array();

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
  /* Field: Content: Promo Headline */
  $handler->display->display_options['fields']['field_promo_headline']['id'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['table'] = 'field_data_field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['field'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['label'] = '';
  $handler->display->display_options['fields']['field_promo_headline']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_promo_headline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_headline']['empty'] = '[title]';
  $handler->display->display_options['fields']['field_promo_headline']['hide_alter_empty'] = FALSE;
  /* Field: Content: Promo Text */
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
  /* Contextual filter: Content: Empowered By (field_action_sponsor) */
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

  return $export;
}
