<?php
/**
 * @file
 * takepart_blog.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function takepart_blog_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_openpublish_blog_post';
  $strongarm->value = '';
  $export['additional_settings__active_tab_openpublish_blog_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_blog_front';
  $strongarm->value = 0;
  $export['comment_anonymous_blog_front'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_openpublish_blog_post';
  $strongarm->value = 0;
  $export['comment_anonymous_openpublish_blog_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_blog_front';
  $strongarm->value = '1';
  $export['comment_blog_front'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_blog_front';
  $strongarm->value = 1;
  $export['comment_default_mode_blog_front'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_openpublish_blog_post';
  $strongarm->value = 1;
  $export['comment_default_mode_openpublish_blog_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_blog_front';
  $strongarm->value = '10';
  $export['comment_default_per_page_blog_front'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_openpublish_blog_post';
  $strongarm->value = '50';
  $export['comment_default_per_page_openpublish_blog_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_blog_front';
  $strongarm->value = 1;
  $export['comment_form_location_blog_front'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_openpublish_blog_post';
  $strongarm->value = 1;
  $export['comment_form_location_openpublish_blog_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_openpublish_blog_post';
  $strongarm->value = '2';
  $export['comment_openpublish_blog_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_blog_front';
  $strongarm->value = '0';
  $export['comment_preview_blog_front'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_openpublish_blog_post';
  $strongarm->value = '0';
  $export['comment_preview_openpublish_blog_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_blog_front';
  $strongarm->value = 0;
  $export['comment_subject_field_blog_front'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_openpublish_blog_post';
  $strongarm->value = 0;
  $export['comment_subject_field_openpublish_blog_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'enable_revisions_page_openpublish_blog_post';
  $strongarm->value = 1;
  $export['enable_revisions_page_openpublish_blog_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_blog_front';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_blog_front'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_openpublish_blog_post';
  $strongarm->value = array();
  $export['menu_options_openpublish_blog_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_blog_front';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_blog_front'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_openpublish_blog_post';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_openpublish_blog_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_blog_front';
  $strongarm->value = array();
  $export['node_options_blog_front'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_openpublish_blog_post';
  $strongarm->value = array();
  $export['node_options_openpublish_blog_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_blog_front';
  $strongarm->value = '1';
  $export['node_preview_blog_front'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_openpublish_blog_post';
  $strongarm->value = '1';
  $export['node_preview_openpublish_blog_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_blog_front';
  $strongarm->value = 1;
  $export['node_submitted_blog_front'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_openpublish_blog_post';
  $strongarm->value = 0;
  $export['node_submitted_openpublish_blog_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeblock_blog_front';
  $strongarm->value = '0';
  $export['nodeblock_blog_front'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeblock_openpublish_blog_post';
  $strongarm->value = '0';
  $export['nodeblock_openpublish_blog_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_blog_pattern';
  $strongarm->value = 'blogs/[user:name]';
  $export['pathauto_blog_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_blog_front_pattern';
  $strongarm->value = '[node:title]';
  $export['pathauto_node_blog_front_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_openpublish_blog_post_pattern';
  $strongarm->value = '[node:field-blogpost-blog:term:url:relative]/[node:created:custom:Y]/[node:created:custom:m]/[node:created:custom:d]/[node:title]';
  $export['pathauto_node_openpublish_blog_post_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_diff_inline_openpublish_blog_post';
  $strongarm->value = 0;
  $export['show_diff_inline_openpublish_blog_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_preview_changes_blog_front';
  $strongarm->value = 1;
  $export['show_preview_changes_blog_front'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_preview_changes_openpublish_blog_post';
  $strongarm->value = 1;
  $export['show_preview_changes_openpublish_blog_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_view_blog';
  $strongarm->value = 'TRUE';
  $export['taxonomy_view_blog'] = $strongarm;

  return $export;
}
