<?php
/**
 * @file
 * takepart_topic_front.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function takepart_topic_front_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'featured_items';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Featured Items';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Primary';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_blogpost_main_image']['id'] = 'field_blogpost_main_image';
  $handler->display->display_options['fields']['field_blogpost_main_image']['table'] = 'field_data_field_blogpost_main_image';
  $handler->display->display_options['fields']['field_blogpost_main_image']['field'] = 'field_blogpost_main_image';
  $handler->display->display_options['fields']['field_blogpost_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_blogpost_main_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_blogpost_main_image']['field_api_classes'] = 0;
  /* Field: Content: Promo Headline */
  $handler->display->display_options['fields']['field_action_promo_headline']['id'] = 'field_action_promo_headline';
  $handler->display->display_options['fields']['field_action_promo_headline']['table'] = 'field_data_field_action_promo_headline';
  $handler->display->display_options['fields']['field_action_promo_headline']['field'] = 'field_action_promo_headline';
  $handler->display->display_options['fields']['field_action_promo_headline']['label'] = '';
  $handler->display->display_options['fields']['field_action_promo_headline']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_action_promo_headline']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_action_promo_headline']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_action_promo_headline']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_action_promo_headline']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_action_promo_headline']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_action_promo_headline']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_action_promo_headline']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_action_promo_headline']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_action_promo_headline']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_action_promo_headline']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_action_promo_headline']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_action_promo_headline']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_action_promo_headline']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_action_promo_headline']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_action_promo_headline']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_action_promo_headline']['field_api_classes'] = 0;
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
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Headline */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'Headline';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['php']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['php']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$entity = $data->_field_data[\'nid\'][\'entity\'];
if(isset($entity->field_promo_headline[$entity->language])) {
  $promo_headline_array = $entity->field_promo_headline[$entity->language];
  $value = !empty($promo_headline_array) ? $promo_headline_array[0][\'safe_value\'] : $data->node_title;
}
else {
  $value = $data->node_title;
}
$value = l($value, "/node{$entity->nid}");
print $value;
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
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
  $handler->display->display_options['fields']['field_promo_text']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_promo_text']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_promo_text']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_promo_text']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_promo_text']['field_api_classes'] = 0;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['path']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['path']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['path']['alter']['external'] = 0;
  $handler->display->display_options['fields']['path']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['path']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['path']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['path']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['path']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['path']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['path']['alter']['html'] = 0;
  $handler->display->display_options['fields']['path']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['path']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['path']['hide_empty'] = 0;
  $handler->display->display_options['fields']['path']['empty_zero'] = 0;
  $handler->display->display_options['fields']['path']['absolute'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Included Content */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['ui_name'] = 'Included Content';
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

  /* Display: Primary */
  $handler = $view->new_display('block', 'Primary', 'block');

  /* Display: Secondary */
  $handler = $view->new_display('block', 'Secondary', 'block_1');
  $translatables['featured_items'] = array(
    t('Master'),
    t('Primary'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('Secondary'),
  );
  $export['featured_items'] = $view;

  $view = new view;
  $view->name = 'taxonomy_search_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_standard_node_index';
  $view->human_name = 'Taxonomy Search List';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'search block';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_standard_node_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  /* Contextual filter: Node: Topic */
  $handler->display->display_options['arguments']['field_topic']['id'] = 'field_topic';
  $handler->display->display_options['arguments']['field_topic']['table'] = 'search_api_index_standard_node_index';
  $handler->display->display_options['arguments']['field_topic']['field'] = 'field_topic';
  $handler->display->display_options['arguments']['field_topic']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_topic']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_topic']['summary']['format'] = 'default_summary';

  /* Display: Taxonomy Search List by Type */
  $handler = $view->new_display('block', 'Taxonomy Search List by Type', 'block');
  $translatables['taxonomy_search_list'] = array(
    t('Master'),
    t('search block'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Title'),
    t('All'),
    t('Taxonomy Search List by Type'),
  );
  $export['taxonomy_search_list'] = $view;

  return $export;
}
