<?php
/**
 * @file
 * tpf_content_video.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function tpf_content_video_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: node:openpublish_video.
  $config['node:openpublish_video'] = array(
    'instance' => 'node:openpublish_video',
    'config' => array(
      'description' => array(
        'value' => '[node:field_subhead]',
      ),
      'abstract' => array(
        'value' => '[node:field_subhead]',
      ),
      'og:description' => array(
        'value' => '[node:field_subhead]',
      ),
      'tab-keywords' => array(
        'value' => '[tab_metatags:topic_freetags:{node:field_topic}, {node:field_free_tag}]',
      ),
    ),
  );

  // Exported Metatag config instance: node:video.
  $config['node:video'] = array(
    'instance' => 'node:video',
    'config' => array(
      'description' => array(
        'value' => '[node:field_article_subhead]',
      ),
      'abstract' => array(
        'value' => '[node:field_article_subhead]',
      ),
      'og:description' => array(
        'value' => '[node:field_article_subhead]',
      ),
      'twitter:title' => array(
        'value' => '[node:title]',
      ),
      'twitter:description' => array(
        'value' => '[node:field_article_subhead]',
      ),
      'twitter:image' => array(
        'value' => '[tp_og_image:thumbnail:{node:nid}]',
      ),
    ),
  );

  return $config;
}
