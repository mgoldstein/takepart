<?php
/**
 * @file
 * tpf_feature_homepage.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function tpf_feature_homepage_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'homepage_columns';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Homepage Columns';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'columns';
  $handler->display->display_options['css_class'] = 'columns';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Field: Global: View */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['label'] = '';
  $handler->display->display_options['fields']['view']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view']['view'] = 'latest_article_in_a_series';
  $handler->display->display_options['fields']['view']['arguments'] = '[!tid]';
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  /* Filter criterion: Taxonomy term: Vocabulary */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    3 => '3',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['homepage_columns'] = $view;

  $view = new view();
  $view->name = 'latest_article_in_a_series';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Latest Article in a Series';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Author(s) (field_author) */
  $handler->display->display_options['relationships']['field_author_nid']['id'] = 'field_author_nid';
  $handler->display->display_options['relationships']['field_author_nid']['table'] = 'field_data_field_author';
  $handler->display->display_options['relationships']['field_author_nid']['field'] = 'field_author_nid';
  $handler->display->display_options['relationships']['field_author_nid']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_author_nid']['delta'] = '0';
  /* Relationship: Content: Series (field_series) */
  $handler->display->display_options['relationships']['field_series_tid']['id'] = 'field_series_tid';
  $handler->display->display_options['relationships']['field_series_tid']['table'] = 'field_data_field_series';
  $handler->display->display_options['relationships']['field_series_tid']['field'] = 'field_series_tid';
  $handler->display->display_options['relationships']['field_series_tid']['required'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Author(s) */
  $handler->display->display_options['fields']['field_author']['id'] = 'field_author';
  $handler->display->display_options['fields']['field_author']['table'] = 'field_data_field_author';
  $handler->display->display_options['fields']['field_author']['field'] = 'field_author';
  $handler->display->display_options['fields']['field_author']['label'] = '';
  $handler->display->display_options['fields']['field_author']['element_class'] = 'author';
  $handler->display->display_options['fields']['field_author']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_author']['type'] = 'node_reference_plain';
  $handler->display->display_options['fields']['field_author']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_author']['delta_offset'] = '0';
  /* Field: Content: Photo */
  $handler->display->display_options['fields']['field_profile_photo']['id'] = 'field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['table'] = 'field_data_field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['field'] = 'field_profile_photo';
  $handler->display->display_options['fields']['field_profile_photo']['relationship'] = 'field_author_nid';
  $handler->display->display_options['fields']['field_profile_photo']['label'] = '';
  $handler->display->display_options['fields']['field_profile_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_photo']['type'] = 'image_link_formatter';
  $handler->display->display_options['fields']['field_profile_photo']['settings'] = array(
    'image_style' => '70x70_thumbnail',
    'image_link' => '',
  );
  /* Field: Field: Promo Headline */
  $handler->display->display_options['fields']['field_promo_headline']['id'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['table'] = 'field_data_field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['field'] = 'field_promo_headline';
  $handler->display->display_options['fields']['field_promo_headline']['label'] = '';
  $handler->display->display_options['fields']['field_promo_headline']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_series_tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'openpublish_article' => 'openpublish_article',
    'feature_article' => 'feature_article',
    'openpublish_photo_gallery' => 'openpublish_photo_gallery',
    'video' => 'video',
  );
  $export['latest_article_in_a_series'] = $view;

  $view = new view();
  $view->name = 'latest_headlines';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Latest Headlines';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'latest headlines';
  $handler->display->display_options['css_class'] = 'latest-headlines';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'latest_headlines' => 'latest_headlines',
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['machine_name'] = TRUE;
  /* Field: Content: Promo Short Headline */
  $handler->display->display_options['fields']['field_promo_short_headline']['id'] = 'field_promo_short_headline';
  $handler->display->display_options['fields']['field_promo_short_headline']['table'] = 'field_data_field_promo_short_headline';
  $handler->display->display_options['fields']['field_promo_short_headline']['field'] = 'field_promo_short_headline';
  $handler->display->display_options['fields']['field_promo_short_headline']['label'] = '';
  $handler->display->display_options['fields']['field_promo_short_headline']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_promo_short_headline']['alter']['text'] = '<span class="[type]"><a href="[path]">[field_promo_short_headline]</a></span>';
  $handler->display->display_options['fields']['field_promo_short_headline']['element_label_colon'] = FALSE;
  /* Sort criterion: Nodequeue: Queue ID */
  $handler->display->display_options['sorts']['qid']['id'] = 'qid';
  $handler->display->display_options['sorts']['qid']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['qid']['field'] = 'qid';
  $handler->display->display_options['sorts']['qid']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['sorts']['qid']['order'] = 'DESC';
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
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
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'openpublish_article' => 'openpublish_article',
    'campaign' => 'campaign',
    'campaign_page' => 'campaign_page',
    'feature_article' => 'feature_article',
    'openpublish_video' => 'openpublish_video',
    'openpublish_photo' => 'openpublish_photo',
    'openpublish_photo_gallery' => 'openpublish_photo_gallery',
    'video' => 'video',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Promo Short Headline (field_promo_short_headline) */
  $handler->display->display_options['filters']['field_promo_short_headline_value']['id'] = 'field_promo_short_headline_value';
  $handler->display->display_options['filters']['field_promo_short_headline_value']['table'] = 'field_data_field_promo_short_headline';
  $handler->display->display_options['filters']['field_promo_short_headline_value']['field'] = 'field_promo_short_headline_value';
  $handler->display->display_options['filters']['field_promo_short_headline_value']['operator'] = '!=';
  $handler->display->display_options['filters']['field_promo_short_headline_value']['value'] = 'NULL';
  $handler->display->display_options['filters']['field_promo_short_headline_value']['group'] = 1;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['latest_headlines'] = $view;

  $view = new view();
  $view->name = 'takeaction_homepage';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'TakeAction Homepage';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'TAKE <br>ACTION';
  $handler->display->display_options['css_class'] = 'columns';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<a href="http://takeaction.takepart.com/actions" class="more">Find other ways to Take Action</a>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'takeaction_promo' => 'takeaction_promo',
    'latest_headlines' => 0,
    'photo_galleries_promo' => 0,
  );
  /* Field: Content: Action Type */
  $handler->display->display_options['fields']['field_action_type']['id'] = 'field_action_type';
  $handler->display->display_options['fields']['field_action_type']['table'] = 'field_data_field_action_type';
  $handler->display->display_options['fields']['field_action_type']['field'] = 'field_action_type';
  $handler->display->display_options['fields']['field_action_type']['label'] = '';
  $handler->display->display_options['fields']['field_action_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_action_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_action_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Call to Action Promo */
  $handler->display->display_options['fields']['field_tab_call_to_action']['id'] = 'field_tab_call_to_action';
  $handler->display->display_options['fields']['field_tab_call_to_action']['table'] = 'field_data_field_tab_call_to_action';
  $handler->display->display_options['fields']['field_tab_call_to_action']['field'] = 'field_tab_call_to_action';
  $handler->display->display_options['fields']['field_tab_call_to_action']['label'] = '';
  $handler->display->display_options['fields']['field_tab_call_to_action']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tab_call_to_action']['element_label_colon'] = FALSE;
  /* Field: Content: Action Icon */
  $handler->display->display_options['fields']['field_action_icon']['id'] = 'field_action_icon';
  $handler->display->display_options['fields']['field_action_icon']['table'] = 'field_data_field_action_icon';
  $handler->display->display_options['fields']['field_action_icon']['field'] = 'field_action_icon';
  $handler->display->display_options['fields']['field_action_icon']['label'] = '';
  $handler->display->display_options['fields']['field_action_icon']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_action_icon']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_action_icon']['alter']['text'] = '<img src="[field_action_icon-value]" />';
  $handler->display->display_options['fields']['field_action_icon']['element_label_colon'] = FALSE;
  /* Field: Content: Action URL */
  $handler->display->display_options['fields']['field_action_url']['id'] = 'field_action_url';
  $handler->display->display_options['fields']['field_action_url']['table'] = 'field_data_field_action_url';
  $handler->display->display_options['fields']['field_action_url']['field'] = 'field_action_url';
  $handler->display->display_options['fields']['field_action_url']['label'] = '';
  $handler->display->display_options['fields']['field_action_url']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_action_url']['alter']['text'] = '<div class="action-type">[field_action_type]</div>
<div class="tab-call-to-action">[field_tab_call_to_action]</div>
<div class="action-icon">[field_action_icon]</div>
<div class="action-url">[field_action_url]</div>';
  $handler->display->display_options['fields']['field_action_url']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_action_url']['alter']['path'] = '[field_action_url-url]';
  $handler->display->display_options['fields']['field_action_url']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_action_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_action_url']['click_sort_column'] = 'url';
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Filter criterion: Nodequeue: In queue */
  $handler->display->display_options['filters']['in_queue']['id'] = 'in_queue';
  $handler->display->display_options['filters']['in_queue']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['filters']['in_queue']['field'] = 'in_queue';
  $handler->display->display_options['filters']['in_queue']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['filters']['in_queue']['value'] = '1';
  $handler->display->display_options['filters']['in_queue']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['takeaction_homepage'] = $view;

  return $export;
}
