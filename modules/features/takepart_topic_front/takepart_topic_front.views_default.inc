<?php
/**
 * @file
 * takepart_topic_front.views_default.inc
 */

/**
 * Implements hook_views_default_views().
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
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_gallery_main_image']['id'] = 'field_gallery_main_image';
  $handler->display->display_options['fields']['field_gallery_main_image']['table'] = 'field_data_field_gallery_main_image';
  $handler->display->display_options['fields']['field_gallery_main_image']['field'] = 'field_gallery_main_image';
  $handler->display->display_options['fields']['field_gallery_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_gallery_main_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_gallery_main_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_gallery_main_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_gallery_main_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_gallery_main_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_gallery_main_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_gallery_main_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_gallery_main_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_gallery_main_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_gallery_main_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_gallery_main_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_gallery_main_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_gallery_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_gallery_main_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_gallery_main_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_gallery_main_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_gallery_main_image']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_gallery_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_gallery_main_image']['type'] = 'image';
  $handler->display->display_options['fields']['field_gallery_main_image']['settings'] = array(
    'image_style' => 'tp_promo_feature_thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_gallery_main_image']['field_api_classes'] = 0;
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_article_main_image']['id'] = 'field_article_main_image';
  $handler->display->display_options['fields']['field_article_main_image']['table'] = 'field_data_field_article_main_image';
  $handler->display->display_options['fields']['field_article_main_image']['field'] = 'field_article_main_image';
  $handler->display->display_options['fields']['field_article_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_article_main_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_article_main_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_article_main_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_article_main_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_article_main_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_article_main_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_article_main_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_article_main_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_article_main_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_article_main_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_article_main_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_article_main_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_article_main_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_article_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_article_main_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_article_main_image']['empty'] = '[field_gallery_main_image]';
  $handler->display->display_options['fields']['field_article_main_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_article_main_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_article_main_image']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_article_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_article_main_image']['type'] = 'image';
  $handler->display->display_options['fields']['field_article_main_image']['settings'] = array(
    'image_style' => 'tp_promo_feature_thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_article_main_image']['field_api_classes'] = 0;
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_page_main_image']['id'] = 'field_page_main_image';
  $handler->display->display_options['fields']['field_page_main_image']['table'] = 'field_data_field_page_main_image';
  $handler->display->display_options['fields']['field_page_main_image']['field'] = 'field_page_main_image';
  $handler->display->display_options['fields']['field_page_main_image']['label'] = '';
  $handler->display->display_options['fields']['field_page_main_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_page_main_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_page_main_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_page_main_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_page_main_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_page_main_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_page_main_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_page_main_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_page_main_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_page_main_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_page_main_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_page_main_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_page_main_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_page_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_page_main_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_page_main_image']['empty'] = '[field_article_main_image]';
  $handler->display->display_options['fields']['field_page_main_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_page_main_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_page_main_image']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_page_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_page_main_image']['type'] = 'image';
  $handler->display->display_options['fields']['field_page_main_image']['settings'] = array(
    'image_style' => 'tp_promo_feature_thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_page_main_image']['field_api_classes'] = 0;
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
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_blogpost_main_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_blogpost_main_image']['empty'] = '[field_page_main_image]';
  $handler->display->display_options['fields']['field_blogpost_main_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_blogpost_main_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_blogpost_main_image']['type'] = 'image';
  $handler->display->display_options['fields']['field_blogpost_main_image']['settings'] = array(
    'image_style' => 'tp_promo_feature_thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_blogpost_main_image']['field_api_classes'] = 0;
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
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
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
  $handler->display->display_options['fields']['php']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim'] = 0;
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
$value = l($value, "node/{$entity->nid}");
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
  $handler->display->display_options['fields']['path']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['path']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['path']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['path']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['path']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['path']['alter']['html'] = 0;
  $handler->display->display_options['fields']['path']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['path']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['path']['hide_empty'] = 0;
  $handler->display->display_options['fields']['path']['empty_zero'] = 0;
  $handler->display->display_options['fields']['path']['absolute'] = 0;
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
    'image_style' => 'tp_secondary_feature_thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_thumbnail']['field_api_classes'] = 0;
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
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
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
  $handler->display->display_options['fields']['php']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim'] = 0;
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
$value = l($value, "node/{$entity->nid}");
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
  $handler->display->display_options['fields']['path']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['path']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['path']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['path']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['path']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['path']['alter']['html'] = 0;
  $handler->display->display_options['fields']['path']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['path']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['path']['hide_empty'] = 0;
  $handler->display->display_options['fields']['path']['empty_zero'] = 0;
  $handler->display->display_options['fields']['path']['absolute'] = 0;
  $export['featured_items'] = $view;

  $view = new view;
  $view->name = 'quick_study';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Quick Study';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Quick Study';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
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
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'field';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['field'] = 'nodereference::field_topic_featured_quick_study';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
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
    'takepart_quick_study' => 'takepart_quick_study',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['quick_study'] = $view;

  $view = new view;
  $view->name = 'taxonomy_search_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_site_node_index';
  $view->human_name = 'Taxonomy Search List';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Empty';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'There is no associated content';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
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
  /* Field: Content: Promo Headline */
  $handler->display->display_options['fields']['field_promo_headline']['id'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['fields']['field_promo_headline']['field'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['label'] = '';
  $handler->display->display_options['fields']['field_promo_headline']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['text'] = '[field_promo_headline] now';
  $handler->display->display_options['fields']['field_promo_headline']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_promo_headline']['alter']['path'] = '[url]';
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
  $handler->display->display_options['fields']['field_promo_headline']['empty_zero'] = 1;
  /* Field: Content: Content type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'search_api_index_site_node_index';
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
  /* Field: Linked Headline */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['ui_name'] = 'Linked Headline';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['url']['alter']['text'] = '[field_promo_headline] ';
  $handler->display->display_options['fields']['url']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['url']['alter']['path'] = '[url]';
  $handler->display->display_options['fields']['url']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['url']['alter']['external'] = 0;
  $handler->display->display_options['fields']['url']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['url']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['url']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['url']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['url']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['url']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['url']['alter']['html'] = 0;
  $handler->display->display_options['fields']['url']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['url']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['url']['hide_empty'] = 0;
  $handler->display->display_options['fields']['url']['empty_zero'] = 0;
  /* Field: Content: Promo Text */
  $handler->display->display_options['fields']['field_promo_text']['id'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['table'] = 'search_api_index_site_node_index';
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
  /* Contextual filter: Topics [taxonomy_term] */
  $handler->display->display_options['arguments']['field_topic_1']['id'] = 'field_topic_1';
  $handler->display->display_options['arguments']['field_topic_1']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['arguments']['field_topic_1']['field'] = 'field_topic';
  $handler->display->display_options['arguments']['field_topic_1']['ui_name'] = 'Topics [taxonomy_term]';
  $handler->display->display_options['arguments']['field_topic_1']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_topic_1']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_topic_1']['default_argument_options']['term_page'] = 1;
  $handler->display->display_options['arguments']['field_topic_1']['default_argument_options']['node'] = 0;
  $handler->display->display_options['arguments']['field_topic_1']['default_argument_options']['limit'] = 0;
  $handler->display->display_options['arguments']['field_topic_1']['default_argument_options']['vocabularies'] = array(
    'action_type' => 0,
    'agency' => 0,
    'blog' => 0,
    'free_tags' => 0,
    'group_type' => 0,
    'photo_credit' => 0,
    'series' => 0,
    'topic' => 0,
  );
  $handler->display->display_options['arguments']['field_topic_1']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_topic_1']['summary']['format'] = 'default_summary';
  /* Filter criterion: Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'action' => 'action',
    'openpublish_article' => 'openpublish_article',
    'audio' => 'audio',
    'openpublish_blog_post' => 'openpublish_blog_post',
    'takepart_group' => 'takepart_group',
    'openpublish_photo_gallery' => 'openpublish_photo_gallery',
    'takepart_quick_study' => 'takepart_quick_study',
    'openpublish_video' => 'openpublish_video',
  );

  /* Display: Topic */
  $handler = $view->new_display('block', 'Topic', 'block');

  /* Display: Free Tag */
  $handler = $view->new_display('block', 'Free Tag', 'block_1');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Free Tags [taxonomy_term] */
  $handler->display->display_options['arguments']['field_free_tag']['id'] = 'field_free_tag';
  $handler->display->display_options['arguments']['field_free_tag']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['arguments']['field_free_tag']['field'] = 'field_free_tag';
  $handler->display->display_options['arguments']['field_free_tag']['ui_name'] = 'Free Tags [taxonomy_term]';
  $handler->display->display_options['arguments']['field_free_tag']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_free_tag']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_free_tag']['default_argument_options']['term_page'] = 1;
  $handler->display->display_options['arguments']['field_free_tag']['default_argument_options']['node'] = 0;
  $handler->display->display_options['arguments']['field_free_tag']['default_argument_options']['limit'] = 0;
  $handler->display->display_options['arguments']['field_free_tag']['default_argument_options']['vocabularies'] = array(
    'action_type' => 0,
    'agency' => 0,
    'blog' => 0,
    'free_tags' => 0,
    'group_type' => 0,
    'photo_credit' => 0,
    'series' => 0,
    'topic' => 0,
  );
  $handler->display->display_options['arguments']['field_free_tag']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_free_tag']['summary']['format'] = 'default_summary';

  /* Display: Series */
  $handler = $view->new_display('block', 'Series', 'block_2');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Series [taxonomy_term] */
  $handler->display->display_options['arguments']['field_series']['id'] = 'field_series';
  $handler->display->display_options['arguments']['field_series']['table'] = 'search_api_index_site_node_index';
  $handler->display->display_options['arguments']['field_series']['field'] = 'field_series';
  $handler->display->display_options['arguments']['field_series']['ui_name'] = 'Series [taxonomy_term]';
  $handler->display->display_options['arguments']['field_series']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_series']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_series']['default_argument_options']['term_page'] = 1;
  $handler->display->display_options['arguments']['field_series']['default_argument_options']['node'] = 0;
  $handler->display->display_options['arguments']['field_series']['default_argument_options']['limit'] = 0;
  $handler->display->display_options['arguments']['field_series']['default_argument_options']['vocabularies'] = array(
    'action_type' => 0,
    'agency' => 0,
    'blog' => 0,
    'free_tags' => 0,
    'group_type' => 0,
    'photo_credit' => 0,
    'series' => 0,
    'topic' => 0,
  );
  $handler->display->display_options['arguments']['field_series']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_series']['summary']['format'] = 'default_summary';
  $export['taxonomy_search_list'] = $view;

  return $export;
}
