<?php
/**
 * @file
 * takepart_gallery.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function takepart_gallery_views_default_views() {
  $export = array();

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
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_gallery_images_1' => 'field_gallery_images_1',
    'field_gallery_images' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_gallery_images_1' => 'field_gallery_images_1',
    'field_gallery_images' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['enable'] = 1;
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
  /* Field: Content: Gallery Images */
  $handler->display->display_options['fields']['field_gallery_images_1']['id'] = 'field_gallery_images_1';
  $handler->display->display_options['fields']['field_gallery_images_1']['table'] = 'field_data_field_gallery_images';
  $handler->display->display_options['fields']['field_gallery_images_1']['field'] = 'field_gallery_images';
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
