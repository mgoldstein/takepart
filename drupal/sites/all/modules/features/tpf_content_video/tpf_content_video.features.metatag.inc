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
      'robots' => array(
        'value' => array(
          'index' => 0,
          'follow' => 0,
          'noindex' => 0,
          'nofollow' => 0,
          'noarchive' => 0,
          'nosnippet' => 0,
          'noodp' => 0,
          'noydir' => 0,
          'noimageindex' => 0,
          'notranslate' => 0,
        ),
      ),
      'og:type' => array(
        'value' => 'movie',
      ),
      'og:description' => array(
        'value' => '[node:field_article_subhead]',
      ),
      'og:image' => array(
        'value' => '[node:attached-video-image]',
      ),
      'og:image:secure_url' => array(
        'value' => '[node:attached-video-secure-image]',
      ),
      'og:video' => array(
        'value' => '[node:attached-video-url]',
      ),
      'og:video:secure_url' => array(
        'value' => '[node:attached-video-secure-url]',
      ),
      'og:video:width' => array(
        'value' => '[node:attached-video-width]',
      ),
      'og:video:height' => array(
        'value' => '[node:attached-video-height]',
      ),
      'og:video:type' => array(
        'value' => 'application/x-shockwave-flash',
      ),
      'twitter:card' => array(
        'value' => 'player',
      ),
      'twitter:title' => array(
        'value' => '[node:title]',
      ),
      'twitter:description' => array(
        'value' => '[node:field_article_subhead]',
      ),
      'twitter:image:src' => array(
        'value' => '[tp_og_image:thumbnail:{node:nid}]',
      ),
      'twitter:player' => array(
        'value' => '[node:iframe-embed-src]',
      ),
      'twitter:player:width' => array(
        'value' => '[node:iframe-embed-width]',
      ),
      'twitter:player:height' => array(
        'value' => '[node:iframe-embed-height]',
      ),
      'twitter:player:stream' => array(
        'value' => '[node:attached-video-file-secure-url]',
      ),
      'twitter:player:stream:content_type' => array(
        'value' => 'video/mp4',
      ),
    ),
  );

  return $config;
}
