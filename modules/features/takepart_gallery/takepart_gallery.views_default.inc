<?php
/**
 * @file
 * takepart_gallery.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function takepart_gallery_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'photo_galleries';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Photo Galleries';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Photo Gallery';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Thumbnail Image */
  $handler->display->display_options['fields']['field_thumbnail']['id'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['table'] = 'field_data_field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['field'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_thumbnail']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_thumbnail']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_thumbnail']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_thumbnail']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_thumbnail']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_thumbnail']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_thumbnail']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_thumbnail']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_thumbnail']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_thumbnail']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_thumbnail']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_thumbnail']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_thumbnail']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_thumbnail']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_thumbnail']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_thumbnail']['type'] = 'image';
  $handler->display->display_options['fields']['field_thumbnail']['settings'] = array(
    'image_style' => 'tp_popular_gallery_thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_thumbnail']['field_api_classes'] = 0;
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
  $handler->display->display_options['fields']['field_promo_headline']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_headline']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_promo_headline']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['field_api_classes'] = 0;
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
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'openpublish_photo_gallery' => 'openpublish_photo_gallery',
  );

  /* Display: Currated */
  $handler = $view->new_display('block', 'Currated', 'block');

  /* Display: Photo Page List */
  $handler = $view->new_display('block', 'Photo Page List', 'block_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '2';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Thumbnail Image */
  $handler->display->display_options['fields']['field_thumbnail']['id'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['table'] = 'field_data_field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['field'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_thumbnail']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_thumbnail']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_thumbnail']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_thumbnail']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_thumbnail']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_thumbnail']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_thumbnail']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_thumbnail']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_thumbnail']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_thumbnail']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_thumbnail']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_thumbnail']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_thumbnail']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_thumbnail']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_thumbnail']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_thumbnail']['type'] = 'image';
  $handler->display->display_options['fields']['field_thumbnail']['settings'] = array(
    'image_style' => 'tp_promo_feature_thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_thumbnail']['field_api_classes'] = 0;
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
  $handler->display->display_options['fields']['field_promo_headline']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_headline']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_promo_headline']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;

  /* Display: Curated Vertical   */
  $handler = $view->new_display('block', 'Curated Vertical  ', 'block_2');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Thumbnail Image */
  $handler->display->display_options['fields']['field_thumbnail']['id'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['table'] = 'field_data_field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['field'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_thumbnail']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_thumbnail']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_thumbnail']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_thumbnail']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_thumbnail']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_thumbnail']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_thumbnail']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_thumbnail']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_thumbnail']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_thumbnail']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_thumbnail']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_thumbnail']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_thumbnail']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_thumbnail']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_thumbnail']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_thumbnail']['type'] = 'image';
  $handler->display->display_options['fields']['field_thumbnail']['settings'] = array(
    'image_style' => 'tp_large_rail_wide',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_thumbnail']['field_api_classes'] = 0;
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
  $handler->display->display_options['fields']['field_promo_headline']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_headline']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_promo_headline']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['field_api_classes'] = 0;
  $export['photo_galleries'] = $view;

  $view = new view;
  $view->name = 'photo_gallery';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Photo Gallery';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Photo Gallery';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
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
    'field_gallery_images_1' => 'field_gallery_images_1',
    'field_gallery_images' => 0,
    'field_image_title' => 0,
    'field_media_caption' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_gallery_images_1' => 'field_gallery_images_1',
    'field_gallery_images' => 0,
    'field_image_title' => 0,
    'field_media_caption' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['timeout'] = '5000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['speed'] = '700';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['delay'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['start_paused'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['remember_slide_days'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['items_per_slide'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartype'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartypenobg'] = 0;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Gallery Images (field_gallery_images:fid) */
  $handler->display->display_options['relationships']['field_gallery_images_fid']['id'] = 'field_gallery_images_fid';
  $handler->display->display_options['relationships']['field_gallery_images_fid']['table'] = 'field_data_field_gallery_images';
  $handler->display->display_options['relationships']['field_gallery_images_fid']['field'] = 'field_gallery_images_fid';
  $handler->display->display_options['relationships']['field_gallery_images_fid']['required'] = 1;
  $handler->display->display_options['relationships']['field_gallery_images_fid']['delta'] = '-1';
  /* Field: Content: Gallery Images */
  $handler->display->display_options['fields']['field_gallery_images']['id'] = 'field_gallery_images';
  $handler->display->display_options['fields']['field_gallery_images']['table'] = 'field_data_field_gallery_images';
  $handler->display->display_options['fields']['field_gallery_images']['field'] = 'field_gallery_images';
  $handler->display->display_options['fields']['field_gallery_images']['label'] = '';
  $handler->display->display_options['fields']['field_gallery_images']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_gallery_images']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_gallery_images']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_gallery_images']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_gallery_images']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_gallery_images']['type'] = 'image';
  $handler->display->display_options['fields']['field_gallery_images']['settings'] = array(
    'image_style' => 'tp_content_wide',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_gallery_images']['group_rows'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_gallery_images']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['field_api_classes'] = 0;
  /* Field: Thumbnails */
  $handler->display->display_options['fields']['field_gallery_images_1']['id'] = 'field_gallery_images_1';
  $handler->display->display_options['fields']['field_gallery_images_1']['table'] = 'field_data_field_gallery_images';
  $handler->display->display_options['fields']['field_gallery_images_1']['field'] = 'field_gallery_images';
  $handler->display->display_options['fields']['field_gallery_images_1']['ui_name'] = 'Thumbnails';
  $handler->display->display_options['fields']['field_gallery_images_1']['label'] = '';
  $handler->display->display_options['fields']['field_gallery_images_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_gallery_images_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_gallery_images_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_gallery_images_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_gallery_images_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_gallery_images_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_gallery_images_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_gallery_images_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_gallery_images_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_gallery_images_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_gallery_images_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_gallery_images_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_gallery_images_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_gallery_images_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_gallery_images_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_gallery_images_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_gallery_images_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_gallery_images_1']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_gallery_images_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_gallery_images_1']['type'] = 'image';
  $handler->display->display_options['fields']['field_gallery_images_1']['settings'] = array(
    'image_style' => 'tp_gallery_photo_thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_gallery_images_1']['group_rows'] = 0;
  $handler->display->display_options['fields']['field_gallery_images_1']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_gallery_images_1']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_gallery_images_1']['field_api_classes'] = 0;
  /* Field: File: Title */
  $handler->display->display_options['fields']['field_image_title']['id'] = 'field_image_title';
  $handler->display->display_options['fields']['field_image_title']['table'] = 'field_data_field_image_title';
  $handler->display->display_options['fields']['field_image_title']['field'] = 'field_image_title';
  $handler->display->display_options['fields']['field_image_title']['relationship'] = 'field_gallery_images_fid';
  $handler->display->display_options['fields']['field_image_title']['label'] = '';
  $handler->display->display_options['fields']['field_image_title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_image_title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_image_title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_image_title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_image_title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_image_title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_image_title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_image_title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_image_title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_image_title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_image_title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_image_title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_image_title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['field_image_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_image_title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_image_title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_image_title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_image_title']['field_api_classes'] = 0;
  /* Field: File: Caption */
  $handler->display->display_options['fields']['field_media_caption']['id'] = 'field_media_caption';
  $handler->display->display_options['fields']['field_media_caption']['table'] = 'field_data_field_media_caption';
  $handler->display->display_options['fields']['field_media_caption']['field'] = 'field_media_caption';
  $handler->display->display_options['fields']['field_media_caption']['relationship'] = 'field_gallery_images_fid';
  $handler->display->display_options['fields']['field_media_caption']['label'] = '';
  $handler->display->display_options['fields']['field_media_caption']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_media_caption']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_media_caption']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_media_caption']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_media_caption']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_media_caption']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_media_caption']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_media_caption']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_media_caption']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_media_caption']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_media_caption']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_media_caption']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_media_caption']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_media_caption']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_media_caption']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_media_caption']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_media_caption']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_media_caption']['field_api_classes'] = 0;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['photo_gallery'] = $view;

  return $export;
}
