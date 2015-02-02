<?php
/**
 * @file
 * tpf_feature_newsletter_curation.features.inc
 */

/**
 * Implements hook_views_api().
 */
function tpf_feature_newsletter_curation_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function tpf_feature_newsletter_curation_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: weekly_featured_video
  $nodequeues['weekly_featured_video'] = array(
    'name' => 'weekly_featured_video',
    'title' => 'Weekly Featured Video',
    'subqueue_title' => '',
    'size' => 10,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'video',
      1 => 'video_playlist',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: weekly_newsletter_stories
  $nodequeues['weekly_newsletter_stories'] = array(
    'name' => 'weekly_newsletter_stories',
    'title' => 'Weekly Newsletter Stories',
    'subqueue_title' => '',
    'size' => 30,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'feature_article',
      1 => 'openpublish_article',
      2 => 'openpublish_photo_gallery',
      3 => 'video',
      4 => 'video_playlist',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: weekly_photo_gallery
  $nodequeues['weekly_photo_gallery'] = array(
    'name' => 'weekly_photo_gallery',
    'title' => 'Weekly Photo Gallery',
    'subqueue_title' => '',
    'size' => 10,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'openpublish_photo_gallery',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}
