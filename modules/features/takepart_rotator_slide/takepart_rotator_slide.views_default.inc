<?php
/**
 * @file
 * takepart_rotator_slide.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
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
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
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
    'title' => 0,
    'field_slide_featured_item' => 0,
    'field_slide_aux_link' => 0,
    'field_slide_main_media' => 0,
    'field_slide_headline' => 0,
    'field_slide_label' => 0,
    'field_slide_headline_override' => 0,
    'field_slide_preview_media' => 0,
    'field_slide_style' => 0,
    'field_slide_teaser' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'title' => 0,
    'field_slide_featured_item' => 0,
    'field_slide_aux_link' => 0,
    'field_slide_main_media' => 0,
    'field_slide_headline' => 0,
    'field_slide_label' => 0,
    'field_slide_headline_override' => 0,
    'field_slide_preview_media' => 0,
    'field_slide_style' => 0,
    'field_slide_teaser' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  /* Field: Content: Story Link */
  $handler->display->display_options['fields']['field_slide_featured_item']['id'] = 'field_slide_featured_item';
  $handler->display->display_options['fields']['field_slide_featured_item']['table'] = 'field_data_field_slide_featured_item';
  $handler->display->display_options['fields']['field_slide_featured_item']['field'] = 'field_slide_featured_item';
  $handler->display->display_options['fields']['field_slide_featured_item']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_slide_featured_item']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_slide_featured_item']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_slide_featured_item']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_slide_featured_item']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_slide_featured_item']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_slide_featured_item']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_slide_featured_item']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_slide_featured_item']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_slide_featured_item']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_slide_featured_item']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_slide_featured_item']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_slide_featured_item']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_slide_featured_item']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_slide_featured_item']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_slide_featured_item']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_slide_featured_item']['click_sort_column'] = 'nid';
  $handler->display->display_options['fields']['field_slide_featured_item']['field_api_classes'] = 0;
  /* Field: Content: Teaser Links */
  $handler->display->display_options['fields']['field_slide_aux_link']['id'] = 'field_slide_aux_link';
  $handler->display->display_options['fields']['field_slide_aux_link']['table'] = 'field_data_field_slide_aux_link';
  $handler->display->display_options['fields']['field_slide_aux_link']['field'] = 'field_slide_aux_link';
  $handler->display->display_options['fields']['field_slide_aux_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_slide_aux_link']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_slide_aux_link']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_slide_aux_link']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_slide_aux_link']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_slide_aux_link']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_slide_aux_link']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_slide_aux_link']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_slide_aux_link']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_slide_aux_link']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_slide_aux_link']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_slide_aux_link']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_slide_aux_link']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_slide_aux_link']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_slide_aux_link']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_slide_aux_link']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_slide_aux_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_slide_aux_link']['type'] = 'url';
  $handler->display->display_options['fields']['field_slide_aux_link']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_slide_aux_link']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_slide_aux_link']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_slide_aux_link']['field_api_classes'] = 0;
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_slide_main_media']['id'] = 'field_slide_main_media';
  $handler->display->display_options['fields']['field_slide_main_media']['table'] = 'field_data_field_slide_main_media';
  $handler->display->display_options['fields']['field_slide_main_media']['field'] = 'field_slide_main_media';
  $handler->display->display_options['fields']['field_slide_main_media']['label'] = '';
  $handler->display->display_options['fields']['field_slide_main_media']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_slide_main_media']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_slide_main_media']['alter']['path'] = '[view_node]';
  $handler->display->display_options['fields']['field_slide_main_media']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_slide_main_media']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_slide_main_media']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_slide_main_media']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_slide_main_media']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_slide_main_media']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_slide_main_media']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_slide_main_media']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_slide_main_media']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_slide_main_media']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_slide_main_media']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_slide_main_media']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_slide_main_media']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_slide_main_media']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_slide_main_media']['type'] = 'styles_media_slide_rotator_main';
  $handler->display->display_options['fields']['field_slide_main_media']['field_api_classes'] = 0;
  /* Field: Content: Headline */
  $handler->display->display_options['fields']['field_slide_headline']['id'] = 'field_slide_headline';
  $handler->display->display_options['fields']['field_slide_headline']['table'] = 'field_data_field_slide_headline';
  $handler->display->display_options['fields']['field_slide_headline']['field'] = 'field_slide_headline';
  $handler->display->display_options['fields']['field_slide_headline']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_slide_headline']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_slide_headline']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_slide_headline']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_slide_headline']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_slide_headline']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_slide_headline']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_slide_headline']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_slide_headline']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_slide_headline']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_slide_headline']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_slide_headline']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_slide_headline']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_slide_headline']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_slide_headline']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_slide_headline']['field_api_classes'] = 0;
  /* Field: Content: Label */
  $handler->display->display_options['fields']['field_slide_label']['id'] = 'field_slide_label';
  $handler->display->display_options['fields']['field_slide_label']['table'] = 'field_data_field_slide_label';
  $handler->display->display_options['fields']['field_slide_label']['field'] = 'field_slide_label';
  $handler->display->display_options['fields']['field_slide_label']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_slide_label']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_slide_label']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_slide_label']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_slide_label']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_slide_label']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_slide_label']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_slide_label']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_slide_label']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_slide_label']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_slide_label']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_slide_label']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_slide_label']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_slide_label']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_slide_label']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_slide_label']['field_api_classes'] = 0;
  /* Field: Content: Preview Headline */
  $handler->display->display_options['fields']['field_slide_headline_override']['id'] = 'field_slide_headline_override';
  $handler->display->display_options['fields']['field_slide_headline_override']['table'] = 'field_data_field_slide_headline_override';
  $handler->display->display_options['fields']['field_slide_headline_override']['field'] = 'field_slide_headline_override';
  $handler->display->display_options['fields']['field_slide_headline_override']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_slide_headline_override']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_slide_headline_override']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_slide_headline_override']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_slide_headline_override']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_slide_headline_override']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_slide_headline_override']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_slide_headline_override']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_slide_headline_override']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_slide_headline_override']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_slide_headline_override']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_slide_headline_override']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_slide_headline_override']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_slide_headline_override']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_slide_headline_override']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_slide_headline_override']['field_api_classes'] = 0;
  /* Field: Content: Preview Image */
  $handler->display->display_options['fields']['field_slide_preview_media']['id'] = 'field_slide_preview_media';
  $handler->display->display_options['fields']['field_slide_preview_media']['table'] = 'field_data_field_slide_preview_media';
  $handler->display->display_options['fields']['field_slide_preview_media']['field'] = 'field_slide_preview_media';
  $handler->display->display_options['fields']['field_slide_preview_media']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_slide_preview_media']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_slide_preview_media']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_slide_preview_media']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_slide_preview_media']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_slide_preview_media']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_slide_preview_media']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_slide_preview_media']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_slide_preview_media']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_slide_preview_media']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_slide_preview_media']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_slide_preview_media']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_slide_preview_media']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_slide_preview_media']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_slide_preview_media']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_slide_preview_media']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_slide_preview_media']['type'] = 'media';
  $handler->display->display_options['fields']['field_slide_preview_media']['field_api_classes'] = 0;
  /* Field: Content: Style */
  $handler->display->display_options['fields']['field_slide_style']['id'] = 'field_slide_style';
  $handler->display->display_options['fields']['field_slide_style']['table'] = 'field_data_field_slide_style';
  $handler->display->display_options['fields']['field_slide_style']['field'] = 'field_slide_style';
  $handler->display->display_options['fields']['field_slide_style']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_slide_style']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_slide_style']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_slide_style']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_slide_style']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_slide_style']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_slide_style']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_slide_style']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_slide_style']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_slide_style']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_slide_style']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_slide_style']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_slide_style']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_slide_style']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_slide_style']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_slide_style']['field_api_classes'] = 0;
  /* Field: Content: Teaser */
  $handler->display->display_options['fields']['field_slide_teaser']['id'] = 'field_slide_teaser';
  $handler->display->display_options['fields']['field_slide_teaser']['table'] = 'field_data_field_slide_teaser';
  $handler->display->display_options['fields']['field_slide_teaser']['field'] = 'field_slide_teaser';
  $handler->display->display_options['fields']['field_slide_teaser']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_slide_teaser']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_slide_teaser']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_slide_teaser']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_slide_teaser']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_slide_teaser']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_slide_teaser']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_slide_teaser']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_slide_teaser']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_slide_teaser']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_slide_teaser']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_slide_teaser']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_slide_teaser']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_slide_teaser']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_slide_teaser']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_slide_teaser']['field_api_classes'] = 0;
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
  $translatables['slide_rotator'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Story Link'),
    t('Teaser Links'),
    t('[view_node]'),
    t('Headline'),
    t('Label'),
    t('Preview Headline'),
    t('Preview Image'),
    t('Style'),
    t('Teaser'),
    t('Block'),
  );
  $export['slide_rotator'] = $view;

  return $export;
}
