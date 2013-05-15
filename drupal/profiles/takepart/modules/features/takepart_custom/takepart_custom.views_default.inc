<?php
/**
 * @file
 * takepart_custom.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function takepart_custom_views_default_views() {
  $export = array();

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
    'takepart_campaign' => 'takepart_campaign',
    'takepart_group' => 'takepart_group',
  );

  /* Display: Curate and/or Suggest */
  $handler = $view->new_display('block', 'Curate and/or Suggest', 'block');
  $handler->display->display_options['display_description'] = 'Used on pages that have a suggest and curate field';
  $export['related_content'] = $view;

  return $export;
}
