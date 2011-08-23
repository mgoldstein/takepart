<?php
/**
 * @file
 * takepart_rotator_slide.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function takepart_rotator_slide_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'slide_rotator';
  $view->description = 'This view is used to create slide rotators';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Slide Rotator';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
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
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_slide_featured_item' => 0,
    'field_slide_main_media' => 0,
    'field_slide_headline_override' => 0,
    'field_display_tag' => 0,
    'field_slide_headline' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_slide_featured_item' => 'field_slide_featured_item',
    'field_display_tag' => 'field_display_tag',
    'field_slide_headline' => 'field_slide_headline',
    'field_slide_main_media' => 0,
    'field_slide_headline_override' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['transition_advanced'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['timeout'] = '5000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['speed'] = '700';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['delay'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['pause_on_click'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['start_paused'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['remember_slide'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['remember_slide_days'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['items_per_slide'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartype'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartypenobg'] = 0;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  /* Field: Content: Story Link */
  $handler->display->display_options['fields']['field_slide_featured_item']['id'] = 'field_slide_featured_item';
  $handler->display->display_options['fields']['field_slide_featured_item']['table'] = 'field_data_field_slide_featured_item';
  $handler->display->display_options['fields']['field_slide_featured_item']['field'] = 'field_slide_featured_item';
  $handler->display->display_options['fields']['field_slide_featured_item']['label'] = '';
  $handler->display->display_options['fields']['field_slide_featured_item']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_slide_featured_item']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_slide_featured_item']['alter']['text'] = '[field_slide_featured_item-nid]';
  $handler->display->display_options['fields']['field_slide_featured_item']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_slide_featured_item']['alter']['absolute'] = 1;
  $handler->display->display_options['fields']['field_slide_featured_item']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_slide_featured_item']['alter']['replace_spaces'] = 1;
  $handler->display->display_options['fields']['field_slide_featured_item']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_slide_featured_item']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_slide_featured_item']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_slide_featured_item']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_slide_featured_item']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_slide_featured_item']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_slide_featured_item']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_slide_featured_item']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_slide_featured_item']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_slide_featured_item']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_slide_featured_item']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_slide_featured_item']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_slide_featured_item']['field_api_classes'] = 0;
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_slide_main_media']['id'] = 'field_slide_main_media';
  $handler->display->display_options['fields']['field_slide_main_media']['table'] = 'field_data_field_slide_main_media';
  $handler->display->display_options['fields']['field_slide_main_media']['field'] = 'field_slide_main_media';
  $handler->display->display_options['fields']['field_slide_main_media']['label'] = '';
  $handler->display->display_options['fields']['field_slide_main_media']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_slide_main_media']['alter']['text'] = '[field_slide_featured_item] ';
  $handler->display->display_options['fields']['field_slide_main_media']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_slide_main_media']['alter']['path'] = 'node/[field_slide_featured_item] ';
  $handler->display->display_options['fields']['field_slide_main_media']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_slide_main_media']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_slide_main_media']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_slide_main_media']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_slide_main_media']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_slide_main_media']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_slide_main_media']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_slide_main_media']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_slide_main_media']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_slide_main_media']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_slide_main_media']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_slide_main_media']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_slide_main_media']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_slide_main_media']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_slide_main_media']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_slide_main_media']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_slide_main_media']['type'] = 'media';
  $handler->display->display_options['fields']['field_slide_main_media']['settings'] = array(
    'file_view_mode' => 'media_original',
  );
  $handler->display->display_options['fields']['field_slide_main_media']['field_api_classes'] = 0;
  /* Field: Content: Main Image Headline */
  $handler->display->display_options['fields']['field_slide_headline_override']['id'] = 'field_slide_headline_override';
  $handler->display->display_options['fields']['field_slide_headline_override']['table'] = 'field_data_field_slide_headline_override';
  $handler->display->display_options['fields']['field_slide_headline_override']['field'] = 'field_slide_headline_override';
  $handler->display->display_options['fields']['field_slide_headline_override']['label'] = '';
  $handler->display->display_options['fields']['field_slide_headline_override']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_slide_headline_override']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_slide_headline_override']['alter']['path'] = 'node/[field_slide_featured_item] ';
  $handler->display->display_options['fields']['field_slide_headline_override']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_slide_headline_override']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_slide_headline_override']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_slide_headline_override']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_slide_headline_override']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_slide_headline_override']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_slide_headline_override']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_slide_headline_override']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_slide_headline_override']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_slide_headline_override']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_slide_headline_override']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_slide_headline_override']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_slide_headline_override']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_slide_headline_override']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_slide_headline_override']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_slide_headline_override']['field_api_classes'] = 0;
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
  $handler->display->display_options['fields']['field_display_tag']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_display_tag']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_display_tag']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_display_tag']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_display_tag']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_display_tag']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_display_tag']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_display_tag']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_tag']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_display_tag']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_display_tag']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_display_tag']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_display_tag']['field_api_classes'] = 0;
  /* Field: Content: Headline */
  $handler->display->display_options['fields']['field_slide_headline']['id'] = 'field_slide_headline';
  $handler->display->display_options['fields']['field_slide_headline']['table'] = 'field_data_field_slide_headline';
  $handler->display->display_options['fields']['field_slide_headline']['field'] = 'field_slide_headline';
  $handler->display->display_options['fields']['field_slide_headline']['label'] = '';
  $handler->display->display_options['fields']['field_slide_headline']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_slide_headline']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_slide_headline']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_slide_headline']['alter']['path'] = 'node/[field_slide_featured_item]';
  $handler->display->display_options['fields']['field_slide_headline']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_slide_headline']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_slide_headline']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_slide_headline']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_slide_headline']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_slide_headline']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_slide_headline']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_slide_headline']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_slide_headline']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_slide_headline']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_slide_headline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_slide_headline']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_slide_headline']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_slide_headline']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_slide_headline']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_slide_headline']['field_api_classes'] = 0;
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
    'takepart_slide' => 'takepart_slide',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
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
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_slide_featured_item' => 0,
    'field_slide_main_media' => 0,
    'field_slide_headline_override' => 0,
    'field_display_tag' => 0,
    'field_slide_headline' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_slide_featured_item' => 'field_slide_featured_item',
    'field_display_tag' => 'field_display_tag',
    'field_slide_headline' => 'field_slide_headline',
    'field_slide_main_media' => 0,
    'field_slide_headline_override' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['transition_advanced'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['timeout'] = '5000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['speed'] = '700';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['delay'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['pause_on_click'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['action_advanced'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['start_paused'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['remember_slide'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['remember_slide_days'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['items_per_slide'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartype'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartypenobg'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['slide_rotator'] = $view;

  return $export;
}
