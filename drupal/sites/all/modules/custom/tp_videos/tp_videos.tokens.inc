<?php
/**
 * @file
 * TakePart video node tokens.
 */

/**
 * Implements hook_token_info().
 */
function tp_videos_token_info() {
  return array(
    'tokens' => array(
      'node' => array(
        'iframe-embed-markup' => array(
          'name' => 'iFrame Embed Markup',
          'description' => t('Markup to embed the node in an iframe on another site.'),
          'type' => 'format',
        ),
        'iframe-embed-src' => array(
          'name' => 'iFrame Embed Source',
          'description' => t('Source for a node embed iframe.'),
          'type' => 'format',
        ),
        'iframe-embed-width' => array(
          'name' => 'iFrame Embed Width',
          'description' => t('Width for a node embed iframe.'),
          'type' => 'format',
        ),
        'iframe-embed-height' => array(
          'name' => 'iFrame Embed Height',
          'description' => t('Height for a node embed iframe.'),
          'type' => 'format',
        ),
        'attached-video-file-secure-url' => array(
          'name' => 'Video file URL',
          'description' => t("The URL to the video file referenced in a node's video field."),
          'type' => 'format',
        ),
        'attached-video-width' => array(
          'name' => 'Video width',
          'description' => "The width of the video in the node's video field",
          'type' => 'node',
        ),
        'attached-video-height' => array(
          'name' => 'Video height',
          'description' => "The height of the video in the node's video field",
          'type' => 'node',
        ),
        'attached-video-url' => array(
          'name' => 'Video URL',
          'description' => "Full URL of the video in the node's video field",
          'type' => 'node',
        ),
        'attached-video-secure-url' => array(
          'name' => 'Video URL',
          'description' => "Full secure URL of the video in the node's video field",
          'type' => 'node',
        ),
        'attached-video-image' => array(
          'name' => 'Video URL',
          'description' => "Full URL of the thumbnail for the video in the node's video field",
          'type' => 'node',
        ),
        'attached-video-secure-image' => array(
          'name' => 'Video URL',
          'description' => "Full secure URL of the thumbnail for the video in the node's video field",
          'type' => 'node',
        ),
      ),
    ),
  );
}

/**
 * Implements hook_tokens().
 */
function tp_videos_tokens($type, $tokens, array $data = array(),
  array $options = array()) {
  $replacements = array();
  if ($type == 'node' && !empty($data['node'])) {
    $node = $data['node'];
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'iframe-embed-markup':
          $replacements[$original] = tp_videos_iframe_embed_markup($node);
          break;
        case 'iframe-embed-src':
          $replacements[$original] = tp_videos_iframe_embed_source($node, TRUE);
          break;
        case 'iframe-embed-width':
          $replacements[$original] = variable_get('twitter_player_card_iframe_width', 640);
          break;
        case 'iframe-embed-height':
          $replacements[$original] = variable_get('twitter_player_card_iframe_height', 480);
          break;
        case 'attached-video-file-secure-url':
          $replacements[$original] = tp_videos_attached_video_file_url($node, TRUE);
          break;
        case 'attached-video-url':
          $replacements[$original] = tp_videos_attached_video_opengraph_url($node);
          break;
        case 'attached-video-secure-url':
          $replacements[$original] = tp_videos_attached_video_opengraph_url($node, TRUE);
          break;
        case 'attached-video-width':
          $replacements[$original] = tp_videos_attached_video_width($node);
          break;
        case 'attached-video-height':
          $replacements[$original] = tp_videos_attached_video_height($node);
          break;
        case 'attached-video-image':
          $replacements[$original] = tp_videos_attached_video_image($node);
          break;
        case 'attached-video-secure-image':
          $replacements[$original] = tp_videos_attached_video_image($node, TRUE);
          break;
      }
    }
  }
  return $replacements;
}
