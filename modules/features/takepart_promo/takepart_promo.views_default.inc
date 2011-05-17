<?php
/**
 * @file
 * takepart_promo.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
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
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
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
  $handler->display->display_options['fields']['field_display_tag']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_display_tag']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_display_tag']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_display_tag']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_display_tag']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_display_tag']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_display_tag']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_display_tag']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_display_tag']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_display_tag']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_display_tag']['click_sort_column'] = 'tid';
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
  $handler->display->display_options['fields']['field_thumbnail_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_thumbnail_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_thumbnail_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_thumbnail_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_thumbnail_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_thumbnail_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_thumbnail_1']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_thumbnail_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_thumbnail_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_thumbnail_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_thumbnail_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_thumbnail_1']['type'] = 'media_preview';
  $handler->display->display_options['fields']['field_thumbnail_1']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;

  /* Display: My Take */
  $handler = $view->new_display('block', 'My Take', 'block_2');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Fields: Author(s) (field_author) - nid */
  $handler->display->display_options['relationships']['field_author_nid']['id'] = 'field_author_nid';
  $handler->display->display_options['relationships']['field_author_nid']['table'] = 'field_data_field_author';
  $handler->display->display_options['relationships']['field_author_nid']['field'] = 'field_author_nid';
  $handler->display->display_options['relationships']['field_author_nid']['required'] = 0;
  $handler->display->display_options['relationships']['field_author_nid']['delta'] = '-1';
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
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
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
  $handler->display->display_options['fields']['field_profile_photo']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_profile_photo']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_profile_photo']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_photo']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_photo']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_photo']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_photo']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_profile_photo']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_photo']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_profile_photo']['empty_zero'] = 0;
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
  $handler->display->display_options['fields']['field_promo_headline']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['strip_tags'] = 0;
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
  $translatables['promo'] = array(
    t('Master'),
    t('My Take'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('All'),
    t('News to Know'),
    t('Features'),
    t('field_author'),
    t('node/[nid]'),
  );
  $export['promo'] = $view;

  return $export;
}
