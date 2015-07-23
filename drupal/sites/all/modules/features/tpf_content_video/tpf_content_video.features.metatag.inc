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
      'fb:admins' => array(
        'value' => 1327833247,
      ),
      'og:type' => array(
        'value' => '',
      ),
      'og:title' => array(
        'value' => '[node:title][f:bool:{node:field_sponsored}: (Promoted):]',
      ),
      'og:description' => array(
        'value' => '[node:field_article_subhead]',
      ),
      'og:video' => array(
        'value' => '[f:bool:{node:field_sharing_inline}:{node:attached-video-url}:]',
      ),
      'og:video:secure_url' => array(
        'value' => '[f:bool:{node:field_sharing_inline}:{node:attached-video-secure-url}:]',
      ),
      'og:video:width' => array(
        'value' => '[f:bool:{node:field_sharing_inline}:{node:attached-video-width}:]',
      ),
      'og:video:height' => array(
        'value' => '[f:bool:{node:field_sharing_inline}:{node:attached-video-height}:]',
      ),
      'og:video:type' => array(
        'value' => '[f:bool:{node:field_sharing_inline}:application/x-shockwave-flash:]',
      ),
      'twitter:card' => array(
        'value' => 'player',
      ),
      'twitter:title' => array(
        'value' => '[node:title][f:bool:{node:field_sponsored}: (Promoted):] ',
      ),
      'twitter:description' => array(
        'value' => '[node:field_article_subhead]',
      ),
      'twitter:image:src' => array(
        'value' => '[tp_og_image:thumbnail:{node:nid}]',
      ),
      'twitter:player' => array(
        'value' => '[f:bool:{node:field_sharing_inline}:{node:iframe-embed-src}:]',
      ),
      'twitter:player:width' => array(
        'value' => '[f:bool:{node:field_sharing_inline}:{node:iframe-embed-width}:]',
      ),
      'twitter:player:height' => array(
        'value' => '[f:bool:{node:field_sharing_inline}:{node:iframe-embed-height}:]',
      ),
      'twitter:player:stream' => array(
        'value' => '[f:bool:{node:field_sharing_inline}:{node:attached-video-file-secure-url}:]',
      ),
      'twitter:player:stream:content_type' => array(
        'value' => 'video/mp4',
      ),
    ),
  );

  return $config;
}
