<?php
/**
 * @file
 * takepart_blog.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function takepart_blog_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'blog_posts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Blog Posts';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Blog Posts';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['slave'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'blog' => 'blog',
    'action_type' => 0,
    'agency' => 0,
    'free_tags' => 0,
    'group_type' => 0,
    'photo_credit' => 0,
    'series' => 0,
    'topic' => 0,
    'video_series' => 0,
  );
  /* Relationship: Taxonomy term: Content using Topic */
  $handler->display->display_options['relationships']['reverse_field_group_topic_node']['id'] = 'reverse_field_group_topic_node';
  $handler->display->display_options['relationships']['reverse_field_group_topic_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_group_topic_node']['field'] = 'reverse_field_group_topic_node';
  $handler->display->display_options['relationships']['reverse_field_group_topic_node']['relationship'] = 'term_node_tid';
  /* Field: Content: Thumbnail Image */
  $handler->display->display_options['fields']['field_thumbnail']['id'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['table'] = 'field_data_field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['field'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_thumbnail']['type'] = 'image';
  $handler->display->display_options['fields']['field_thumbnail']['settings'] = array(
    'image_style' => '70x70_thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_thumbnail']['group_column'] = 'fid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Taxonomy term: Override */
  $handler->display->display_options['fields']['field_blog_override']['id'] = 'field_blog_override';
  $handler->display->display_options['fields']['field_blog_override']['table'] = 'field_data_field_blog_override';
  $handler->display->display_options['fields']['field_blog_override']['field'] = 'field_blog_override';
  $handler->display->display_options['fields']['field_blog_override']['relationship'] = 'term_node_tid';
  $handler->display->display_options['fields']['field_blog_override']['label'] = '';
  $handler->display->display_options['fields']['field_blog_override']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_blog_override']['alter']['text'] = '&raquo; More';
  $handler->display->display_options['fields']['field_blog_override']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_blog_override']['alter']['path'] = 'node/[field_blog_override-nid]';
  $handler->display->display_options['fields']['field_blog_override']['element_class'] = 'more';
  $handler->display->display_options['fields']['field_blog_override']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_blog_override']['hide_alter_empty'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Blogs [taxonomy_term] */
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['id'] = 'field_blogpost_blog_tid';
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['table'] = 'field_data_field_blogpost_blog';
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['field'] = 'field_blogpost_blog_tid';
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['ui_name'] = 'Blogs [taxonomy_term]';
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['default_argument_options']['vocabularies'] = array(
    'action_type' => 0,
    'agency' => 0,
    'blog' => 0,
    'free_tags' => 0,
    'group_type' => 0,
    'photo_credit' => 0,
    'series' => 0,
    'topic' => 0,
  );
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Blog Summary */
  $handler = $view->new_display('block', 'Blog Summary', 'block');
  $handler->display->display_options['display_description'] = 'List Blog post limited by blog bases on an argument';

  /* Display: Blog Front List */
  $handler = $view->new_display('block', 'Blog Front List', 'block_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  /* Display: Our Blogs Summary */
  $handler = $view->new_display('block', 'Our Blogs Summary', 'block_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Blog (field_blogpost_blog) */
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['id'] = 'field_blogpost_blog_tid';
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['table'] = 'field_data_field_blogpost_blog';
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['field'] = 'field_blogpost_blog_tid';
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['block_description'] = 'Our Blogs Summary';
  $export['blog_posts'] = $view;

  $view = new view();
  $view->name = 'blogs';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Blogs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'blogs';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['slave'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = 'field_blog_branding_image';
  $handler->display->display_options['row_plugin'] = 'term';
  $handler->display->display_options['row_options']['view_mode'] = 'summary';
  $handler->display->display_options['row_options']['links'] = 0;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  /* Field: Taxonomy term: Branding Image */
  $handler->display->display_options['fields']['field_blog_branding_image']['id'] = 'field_blog_branding_image';
  $handler->display->display_options['fields']['field_blog_branding_image']['table'] = 'field_data_field_blog_branding_image';
  $handler->display->display_options['fields']['field_blog_branding_image']['field'] = 'field_blog_branding_image';
  $handler->display->display_options['fields']['field_blog_branding_image']['label'] = '';
  $handler->display->display_options['fields']['field_blog_branding_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_blog_branding_image']['click_sort_column'] = 'fid';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Sort criterion: Arguments: Multi-item Argument Order */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'views_sort_by_arg_order';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['order'] = 'DESC';
  $handler->display->display_options['sorts']['weight']['argument_number'] = '0';
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['break_phrase'] = TRUE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'blog' => 'blog',
  );

  /* Display: Summary */
  $handler = $view->new_display('block', 'Summary', 'block');
  $handler->display->display_options['display_description'] = 'List Blogs limited by argument';

  /* Display: Our Blogs Summary */
  $handler = $view->new_display('block', 'Our Blogs Summary', 'block_1');
  $handler->display->display_options['display_description'] = 'curated Our Blogs limited by argument';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = 'field_blog_branding_image';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'term';
  $handler->display->display_options['row_options']['view_mode'] = 'our_blogs_summary';
  $handler->display->display_options['row_options']['links'] = 0;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Arguments: Multi-item Argument Order */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'views_sort_by_arg_order';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['order'] = 'DESC';
  $handler->display->display_options['sorts']['weight']['argument_number'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['break_phrase'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'blog' => 'blog',
  );

  /* Display: Our Blogs Landing Page */
  $handler = $view->new_display('block', 'Our Blogs Landing Page', 'block_2');
  $handler->display->display_options['display_description'] = 'Our Blogs landing page block limited by argument';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = 'field_blog_branding_image';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'term';
  $handler->display->display_options['row_options']['view_mode'] = 'summary';
  $handler->display->display_options['row_options']['links'] = 0;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Arguments: Multi-item Argument Order */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'views_sort_by_arg_order';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['order'] = 'DESC';
  $handler->display->display_options['sorts']['weight']['argument_number'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['break_phrase'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'blog' => 'blog',
  );

  /* Display: Blog Header */
  $handler = $view->new_display('block', 'Blog Header', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Branding Image */
  $handler->display->display_options['fields']['field_blog_branding_image']['id'] = 'field_blog_branding_image';
  $handler->display->display_options['fields']['field_blog_branding_image']['table'] = 'field_data_field_blog_branding_image';
  $handler->display->display_options['fields']['field_blog_branding_image']['field'] = 'field_blog_branding_image';
  $handler->display->display_options['fields']['field_blog_branding_image']['label'] = '';
  $handler->display->display_options['fields']['field_blog_branding_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_blog_branding_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_blog_branding_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_blog_branding_image']['type'] = 'image';
  $handler->display->display_options['fields']['field_blog_branding_image']['settings'] = array(
    'image_style' => '',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_blog_branding_image']['group_column'] = 'fid';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'field';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['field'] = 'content_taxonomy::field_blogpost_blog';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['settings'] = array(
    'content_taxonomy_format' => 'tid',
  );
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['break_phrase'] = TRUE;
  $export['blogs'] = $view;

  return $export;
}
