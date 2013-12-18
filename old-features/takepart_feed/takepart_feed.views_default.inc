<?php
/**
 * @file
 * takepart_feed.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function takepart_feed_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'content_types_posts_feed';
  $view->description = '';
  $view->tag = 'takepart_feed';
  $view->base_table = 'node';
  $view->human_name = 'Content Types Posts Feed';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '300';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '300';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_inline_replacements_target_id']['id'] = 'field_inline_replacements_target_id';
  $handler->display->display_options['relationships']['field_inline_replacements_target_id']['table'] = 'field_data_field_inline_replacements';
  $handler->display->display_options['relationships']['field_inline_replacements_target_id']['field'] = 'field_inline_replacements_target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Action Header Image */
  $handler->display->display_options['fields']['field_actionheaderimg']['id'] = 'field_actionheaderimg';
  $handler->display->display_options['fields']['field_actionheaderimg']['table'] = 'field_data_field_actionheaderimg';
  $handler->display->display_options['fields']['field_actionheaderimg']['field'] = 'field_actionheaderimg';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Type */
  $handler->display->display_options['arguments']['type']['id'] = 'type';
  $handler->display->display_options['arguments']['type']['table'] = 'node';
  $handler->display->display_options['arguments']['type']['field'] = 'type';
  $handler->display->display_options['arguments']['type']['default_action'] = 'default';
  $handler->display->display_options['arguments']['type']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['type']['default_argument_options']['argument'] = 'all';
  $handler->display->display_options['arguments']['type']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['type']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['type']['summary_options']['items_per_page'] = '25';
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
    'openpublish_article' => 'openpublish_article',
    'petition_action' => 'petition_action',
    'openpublish_photo_gallery' => 'openpublish_photo_gallery',
    'pledge_action' => 'pledge_action',
  );

  /* Display: Content Types Feed */
  $handler = $view->new_display('feed', 'Content Types Feed', 'feed_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['style_options']['description'] = 'News, Lifestyle and Social Action';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['row_options']['item_length'] = 'title';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'openpublish_article' => 'openpublish_article',
    'petition_action' => 'petition_action',
    'openpublish_photo_gallery' => 'openpublish_photo_gallery',
    'pledge_action' => 'pledge_action',
  );
  $handler->display->display_options['path'] = 'content/%/feed_old.xml';

  /* Display: Content Types Feed Page */
  $handler = $view->new_display('page', 'Content Types Feed Page', 'page_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_takepart_rss_style';
  $handler->display->display_options['style_options']['schema'] = 'rssimages';
  $handler->display->display_options['style_options']['title'] = 'TAKEPART';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Display Tag */
  $handler->display->display_options['fields']['field_display_tag']['id'] = 'field_display_tag';
  $handler->display->display_options['fields']['field_display_tag']['table'] = 'field_data_field_display_tag';
  $handler->display->display_options['fields']['field_display_tag']['field'] = 'field_display_tag';
  $handler->display->display_options['fields']['field_display_tag']['label'] = '';
  $handler->display->display_options['fields']['field_display_tag']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_display_tag']['alter']['text'] = '<br> [field_display_tag]';
  $handler->display->display_options['fields']['field_display_tag']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_tag']['hide_alter_empty'] = FALSE;
  /* Field: Content: Thumbnail */
  $handler->display->display_options['fields']['field_thumbnail']['id'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['table'] = 'field_data_field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['field'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_thumbnail']['type'] = 'image';
  $handler->display->display_options['fields']['field_thumbnail']['settings'] = array(
    'image_style' => 'large',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_thumbnail']['group_column'] = 'fid';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'D, d M Y H:i:s T';
  /* Field: Content: Author(s) */
  $handler->display->display_options['fields']['field_author']['id'] = 'field_author';
  $handler->display->display_options['fields']['field_author']['table'] = 'field_data_field_author';
  $handler->display->display_options['fields']['field_author']['field'] = 'field_author';
  $handler->display->display_options['fields']['field_author']['label'] = '';
  $handler->display->display_options['fields']['field_author']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_author']['type'] = 'node_reference_plain';
  $handler->display->display_options['fields']['field_author']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Promo Text */
  $handler->display->display_options['fields']['field_promo_text']['id'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['table'] = 'field_data_field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['field'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['label'] = '';
  $handler->display->display_options['fields']['field_promo_text']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_promo_text']['alter']['text'] = '<br/>[field_promo_text]';
  $handler->display->display_options['fields']['field_promo_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_text']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'openpublish_article' => 'openpublish_article',
    'petition_action' => 'petition_action',
    'openpublish_photo_gallery' => 'openpublish_photo_gallery',
    'pledge_action' => 'pledge_action',
    'openpublish_video' => 'openpublish_video',
  );
  $handler->display->display_options['path'] = 'content/%/feed.xml ';

  /* Display: Yahoo Feed */
  $handler = $view->new_display('page', 'Yahoo Feed', 'page_2');
  $handler->display->display_options['display_description'] = 'Full content RSS feed formatted for Yahoo';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '300';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '300';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_takepart_rss_style';
  $handler->display->display_options['style_options']['schema'] = 'rssimages';
  $handler->display->display_options['style_options']['title'] = 'TAKEPART';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'D, d M Y H:i:s T';
  /* Field: Content: Author(s) */
  $handler->display->display_options['fields']['field_author']['id'] = 'field_author';
  $handler->display->display_options['fields']['field_author']['table'] = 'field_data_field_author';
  $handler->display->display_options['fields']['field_author']['field'] = 'field_author';
  $handler->display->display_options['fields']['field_author']['label'] = '';
  $handler->display->display_options['fields']['field_author']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_author']['type'] = 'node_reference_plain';
  $handler->display->display_options['fields']['field_author']['delta_offset'] = '0';
  /* Field: Content: Promo Text */
  $handler->display->display_options['fields']['field_promo_text']['id'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['table'] = 'field_data_field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['field'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['label'] = '';
  $handler->display->display_options['fields']['field_promo_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_text']['hide_alter_empty'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['preserve_tags'] = '<p><br><strong><em><b><i><a><hr><div><span><embed><object><param>';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '1200',
  );
  /* Field: Content: Inline Content: Embedded Content */
  $handler->display->display_options['fields']['inline_content_embedded']['id'] = 'inline_content_embedded';
  $handler->display->display_options['fields']['inline_content_embedded']['table'] = 'node';
  $handler->display->display_options['fields']['inline_content_embedded']['field'] = 'inline_content_embedded';
  $handler->display->display_options['fields']['inline_content_embedded']['label'] = '';
  $handler->display->display_options['fields']['inline_content_embedded']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['inline_content_embedded']['list']['separator'] = ',,,';
  $handler->display->display_options['fields']['inline_content_embedded']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['inline_content_embedded']['view_mode'] = 'full';
  /* Field: Content: Related Stories */
  $handler->display->display_options['fields']['field_related_stories']['id'] = 'field_related_stories';
  $handler->display->display_options['fields']['field_related_stories']['table'] = 'field_data_field_related_stories';
  $handler->display->display_options['fields']['field_related_stories']['field'] = 'field_related_stories';
  $handler->display->display_options['fields']['field_related_stories']['label'] = '';
  $handler->display->display_options['fields']['field_related_stories']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_related_stories']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_related_stories']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_related_stories']['separator'] = ',,,';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['php']['alter']['text'] = '[field_related_stories][php][inline_content_embedded]';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
if (!empty($data->_field_data[\'nid\'][\'entity\']->field_related_stories) && !empty($data->_entity_properties[\'inline_content_embedded\'])) {
  $separator = \',,,\';
} else {
  $separator = \'\';
}
echo $separator;
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'openpublish_article' => 'openpublish_article',
  );
  $handler->display->display_options['path'] = 'content/%/yahoo_feed.xml ';

  /* Display: Content Types Feed Page */
  $handler = $view->new_display('page', 'Content Types Feed Page', 'page_3');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_takepart_rss_style';
  $handler->display->display_options['style_options']['schema'] = 'rssimages';
  $handler->display->display_options['style_options']['title'] = 'TAKEPART';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Thumbnail */
  $handler->display->display_options['fields']['field_thumbnail']['id'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['table'] = 'field_data_field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['field'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_thumbnail']['type'] = 'image';
  $handler->display->display_options['fields']['field_thumbnail']['settings'] = array(
    'image_style' => 'large',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_thumbnail']['group_column'] = 'fid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'D, d M Y H:i:s T';
  /* Field: Content: Author(s) */
  $handler->display->display_options['fields']['field_author']['id'] = 'field_author';
  $handler->display->display_options['fields']['field_author']['table'] = 'field_data_field_author';
  $handler->display->display_options['fields']['field_author']['field'] = 'field_author';
  $handler->display->display_options['fields']['field_author']['label'] = '';
  $handler->display->display_options['fields']['field_author']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_author']['type'] = 'node_reference_plain';
  $handler->display->display_options['fields']['field_author']['delta_offset'] = '0';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '1200',
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = 'Read More';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Read More on TAKEPART';
  $handler->display->display_options['path'] = 'content/%/full_feed.xml ';

  /* Display: Video Feed Page */
  $handler = $view->new_display('page', 'Video Feed Page', 'page_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'TakePart Video RSS Feed';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_takepart_rss_style';
  $handler->display->display_options['style_options']['schema'] = 'rssimages';
  $handler->display->display_options['style_options']['title'] = 'TAKEPART';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Display Tag */
  $handler->display->display_options['fields']['field_display_tag']['id'] = 'field_display_tag';
  $handler->display->display_options['fields']['field_display_tag']['table'] = 'field_data_field_display_tag';
  $handler->display->display_options['fields']['field_display_tag']['field'] = 'field_display_tag';
  $handler->display->display_options['fields']['field_display_tag']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_display_tag']['alter']['text'] = '<br> [field_display_tag]';
  $handler->display->display_options['fields']['field_display_tag']['hide_alter_empty'] = FALSE;
  /* Field: Content: Thumbnail */
  $handler->display->display_options['fields']['field_thumbnail']['id'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['table'] = 'field_data_field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['field'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_thumbnail']['type'] = 'image';
  $handler->display->display_options['fields']['field_thumbnail']['settings'] = array(
    'image_style' => 'large',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_thumbnail']['group_column'] = 'fid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'D, d M Y H:i:s T';
  /* Field: Content: Promo Text */
  $handler->display->display_options['fields']['field_promo_text']['id'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['table'] = 'field_data_field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['field'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['label'] = '';
  $handler->display->display_options['fields']['field_promo_text']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_promo_text']['alter']['text'] = '<br/>[field_promo_text]';
  $handler->display->display_options['fields']['field_promo_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_text']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'openpublish_video' => 'openpublish_video',
  );
  $handler->display->display_options['path'] = 'content/openpublish_video/feed.xml';

  /* Display: Admin Tag Feed Page */
  $handler = $view->new_display('page', 'Admin Tag Feed Page', 'page_5');
  $handler->display->display_options['display_description'] = 'Generate an RSS feed based on an Admin Tag';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_takepart_rss_style';
  $handler->display->display_options['style_options']['schema'] = 'rssimages';
  $handler->display->display_options['style_options']['title'] = 'TAKEPART';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Display Tag */
  $handler->display->display_options['fields']['field_display_tag']['id'] = 'field_display_tag';
  $handler->display->display_options['fields']['field_display_tag']['table'] = 'field_data_field_display_tag';
  $handler->display->display_options['fields']['field_display_tag']['field'] = 'field_display_tag';
  $handler->display->display_options['fields']['field_display_tag']['label'] = '';
  $handler->display->display_options['fields']['field_display_tag']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_display_tag']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_display_tag']['alter']['text'] = '<br> [field_display_tag]';
  $handler->display->display_options['fields']['field_display_tag']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_tag']['hide_alter_empty'] = FALSE;
  /* Field: Content: Thumbnail */
  $handler->display->display_options['fields']['field_thumbnail']['id'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['table'] = 'field_data_field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['field'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_thumbnail']['type'] = 'image';
  $handler->display->display_options['fields']['field_thumbnail']['settings'] = array(
    'image_style' => 'large',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_thumbnail']['group_column'] = 'fid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'D, d M Y H:i:s T';
  /* Field: Content: Promo Text */
  $handler->display->display_options['fields']['field_promo_text']['id'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['table'] = 'field_data_field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['field'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['label'] = '';
  $handler->display->display_options['fields']['field_promo_text']['alter']['text'] = '<br/>[field_promo_text]';
  $handler->display->display_options['fields']['field_promo_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_text']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Admin Tag (field_admin_tag) */
  $handler->display->display_options['arguments']['field_admin_tag_tid']['id'] = 'field_admin_tag_tid';
  $handler->display->display_options['arguments']['field_admin_tag_tid']['table'] = 'field_data_field_admin_tag';
  $handler->display->display_options['arguments']['field_admin_tag_tid']['field'] = 'field_admin_tag_tid';
  $handler->display->display_options['arguments']['field_admin_tag_tid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_admin_tag_tid']['exception']['value'] = '';
  $handler->display->display_options['arguments']['field_admin_tag_tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_admin_tag_tid']['title'] = '%1 Feed';
  $handler->display->display_options['arguments']['field_admin_tag_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_admin_tag_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_admin_tag_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_admin_tag_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_admin_tag_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_admin_tag_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_admin_tag_tid']['validate_options']['vocabularies'] = array(
    'admin_tag' => 'admin_tag',
  );
  $handler->display->display_options['arguments']['field_admin_tag_tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['field_admin_tag_tid']['validate']['fail'] = 'empty';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'openpublish_article' => 'openpublish_article',
    'openpublish_photo_gallery' => 'openpublish_photo_gallery',
    'openpublish_video' => 'openpublish_video',
  );
  $handler->display->display_options['path'] = 'content/%/admin_feed.xml';
  $export['content_types_posts_feed'] = $view;

  $view = new view();
  $view->name = 'terms_posts_feed';
  $view->description = '';
  $view->tag = 'takepart_feed';
  $view->base_table = 'node';
  $view->human_name = 'Terms Posts Feed';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'TakePart Blogs Feed';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['slave'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Field: Topic (field_topic) */
  $handler->display->display_options['arguments']['field_topic_tid']['id'] = 'field_topic_tid';
  $handler->display->display_options['arguments']['field_topic_tid']['table'] = 'field_data_field_topic';
  $handler->display->display_options['arguments']['field_topic_tid']['field'] = 'field_topic_tid';
  $handler->display->display_options['arguments']['field_topic_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_topic_tid']['summary']['format'] = 'default_summary';
  /* Contextual filter: Content: Series (field_series) */
  $handler->display->display_options['arguments']['field_series_tid']['id'] = 'field_series_tid';
  $handler->display->display_options['arguments']['field_series_tid']['table'] = 'field_data_field_series';
  $handler->display->display_options['arguments']['field_series_tid']['field'] = 'field_series_tid';
  $handler->display->display_options['arguments']['field_series_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_series_tid']['summary']['format'] = 'default_summary';
  /* Contextual filter: Content: Video Series (field_video_series) */
  $handler->display->display_options['arguments']['field_video_series_tid']['id'] = 'field_video_series_tid';
  $handler->display->display_options['arguments']['field_video_series_tid']['table'] = 'field_data_field_video_series';
  $handler->display->display_options['arguments']['field_video_series_tid']['field'] = 'field_video_series_tid';
  $handler->display->display_options['arguments']['field_video_series_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_video_series_tid']['summary']['format'] = 'default_summary';
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
    'openpublish_blog_post' => 'openpublish_blog_post',
  );
  $handler->display->display_options['filters']['type']['group'] = '0';

  /* Display: Blog Feed */
  $handler = $view->new_display('feed', 'Blog Feed', 'feed_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['row_options']['item_length'] = 'title';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Blog (field_blogpost_blog) */
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['id'] = 'field_blogpost_blog_tid';
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['table'] = 'field_data_field_blogpost_blog';
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['field'] = 'field_blogpost_blog_tid';
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_blogpost_blog_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'blog/%/feed.xml';
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: Series Feed */
  $handler = $view->new_display('feed', 'Series Feed', 'feed_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'TakePart Series Feed';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['row_options']['item_length'] = 'title';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Series (field_series) */
  $handler->display->display_options['arguments']['field_series_tid']['id'] = 'field_series_tid';
  $handler->display->display_options['arguments']['field_series_tid']['table'] = 'field_data_field_series';
  $handler->display->display_options['arguments']['field_series_tid']['field'] = 'field_series_tid';
  $handler->display->display_options['arguments']['field_series_tid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_series_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_series_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_series_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_series_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'series/%/feed.xml';
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: Video Series Feed */
  $handler = $view->new_display('feed', 'Video Series Feed', 'feed_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'TakePart Video Series Feed';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['row_options']['item_length'] = 'title';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Video Series (field_video_series) */
  $handler->display->display_options['arguments']['field_video_series_tid']['id'] = 'field_video_series_tid';
  $handler->display->display_options['arguments']['field_video_series_tid']['table'] = 'field_data_field_video_series';
  $handler->display->display_options['arguments']['field_video_series_tid']['field'] = 'field_video_series_tid';
  $handler->display->display_options['arguments']['field_video_series_tid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_video_series_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_video_series_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_video_series_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_video_series_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'video-series/%/feed.xml';
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: Topic Feed */
  $handler = $view->new_display('feed', 'Topic Feed', 'feed_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'TakePart Topic Feed';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['row_options']['item_length'] = 'title';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Topic (field_topic) */
  $handler->display->display_options['arguments']['field_topic_tid']['id'] = 'field_topic_tid';
  $handler->display->display_options['arguments']['field_topic_tid']['table'] = 'field_data_field_topic';
  $handler->display->display_options['arguments']['field_topic_tid']['field'] = 'field_topic_tid';
  $handler->display->display_options['arguments']['field_topic_tid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_topic_tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_topic_tid']['title'] = '%1';
  $handler->display->display_options['arguments']['field_topic_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_topic_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_topic_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_topic_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'topic/%/feed.xml';
  $handler->display->display_options['sitename_title'] = 0;
  $export['terms_posts_feed'] = $view;

  return $export;
}
