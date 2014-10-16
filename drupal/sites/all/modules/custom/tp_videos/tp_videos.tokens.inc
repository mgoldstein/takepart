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
        'attached-video-length' => array(
          'name' => 'Video length',
          'description' => "The length (in seconds) of the video in the node's video field",
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
          $replacements[$original] = tp_videos_token_iframe_embed_markup($node);
          break;
        case 'iframe-embed-src':
          $replacements[$original] = tp_videos_token_iframe_embed_src($node, TRUE);
          break;
        case 'iframe-embed-width':
          $replacements[$original] = tp_videos_token_iframe_embed_width($node);
          break;
        case 'iframe-embed-height':
          $replacements[$original] = tp_videos_token_iframe_embed_height($node);
          break;
        case 'attached-video-file-secure-url':
          $replacements[$original] = tp_videos_token_attached_video_file_url($node, TRUE);
          break;
        case 'attached-video-url':
          $replacements[$original] = tp_videos_token_attached_video_url($node);
          break;
        case 'attached-video-secure-url':
          $replacements[$original] = tp_videos_token_attached_video_url($node, TRUE);
          break;
        case 'attached-video-width':
          $replacements[$original] = tp_videos_token_attached_video_width($node);
          break;
        case 'attached-video-height':
          $replacements[$original] = tp_videos_token_attached_video_height($node);
          break;
        case 'attached-video-length':
          $replacements[$original] = tp_videos_token_attached_video_length($node);
          break;
        case 'attached-video-image':
          $replacements[$original] = tp_videos_token_attached_video_image($node);
          break;
        case 'attached-video-secure-image':
          $replacements[$original] = tp_videos_token_attached_video_image($node, TRUE);
          break;
      }
    }
  }
  return $replacements;
}

function tp_videos_token_attached_file($node, $field_name) {
  $file = field_get_items('node', $node, $field_name);
  if ($file !== FALSE && count($file) > 0) {
    $data = reset($file);
    return file_load($data['fid']);
  }
  return FALSE;
}

function tp_videos_token_iframe_embed_markup($node) {
  $replacement = NULL;
  if ($file = tp_videos_token_attached_file($node, 'field_video')) {

    $iframe_attributes = array(
      'id' => 'entity_iframe_node_' . $node->nid,
      'src' => tp_videos_token_iframe_embed_src($node, FALSE),
      'class' => 'entity_iframe entity_iframe_node '. $node->type,
      // Style the iframe to fill a responsive container div.
      'style' => 'position:absolute;top:0;left:0;',
      'width' => '100%',
      'height' => '100%',
      'frameborder' => '0',
    );
    $iframe_markup = _entity_iframe_build_iframe($iframe_attributes, 'video-embed');

    // Assume 16:9 aspect ratio.
    $aspect_ratio = 56.25;
    // With no additional chrome on the player.
    $fixed_size = 0;

    if ($node->type === 'video') {
      // Set the aspect ratio based on the video dimensions.
      if (isset($file->tp_videos_metadata)) {
        $aspect_ratio = ($file->tp_videos_metadata->height
          / $file->tp_videos_metadata->width) * 100.0;
      }
    }

    $container_attributes = array(
      'class' => array(
        'embed-container',
      ),
      'style' => array(
        'position:relative;',
        'height:0;',
        "padding-bottom:{$aspect_ratio}%;",
        "padding-top:{$fixed_size}px;",
      ),
    );

    $replacement = '<div' . drupal_attributes($container_attributes)
      . '>' . $iframe_markup . '</div>';
  }
  return $replacement;
}

function tp_videos_token_iframe_embed_src($node, $secure = FALSE) {
  global $base_url;
  $src_url = $base_url . '/entity_iframe/node/' . $node->nid;
  list(, $resource) = explode('://', $src_url, 2);
  $scheme = $https ? 'https://' : 'http://';
  return $scheme . $resource;
}

function tp_videos_token_iframe_embed_width($node) {
  $replacement = NULL;
  if ($file = tp_videos_token_attached_file($node, 'field_video')) {
    if (isset($file->tp_videos_metadata)) {
      return variable_get('tp_videos_iframe_embed_width', 480);
    }
  }
  return $replacement;
}

function tp_videos_token_iframe_embed_height($node) {
  $replacement = NULL;
  if ($file = tp_videos_token_attached_file($node, 'field_video')) {
    if (isset($file->tp_videos_metadata)) {
      $width = variable_get('tp_videos_iframe_embed_width', 480);
      $height = ($file->tp_videos_metadata->height * $width)
        / $file->tp_videos_metadata->width;
      $replacement = intval($height);
    }
  }
  return $replacement;
}

function tp_videos_token_attached_video_file_url($node, $secure = FALSE) {
  $replacement = NULL;
  if ($file = tp_videos_token_attached_file($node, 'field_video')) {
    if ($file->filemime === 'video/youtube') {
      $params = tp_videos_parse_wrapper_uri($file->uri);
      $token = $params['v'];
      $scheme = $secure ? 'https' : 'http';
      $replacement = "{$scheme}://www.youtube.com/embed/{$token}";
    }
    elseif ($file->filemime === 'video/jwplatform') {
      $params = tp_videos_parse_wrapper_uri($file->uri);
      $token = $params['key'];
      $scheme = $secure ? 'https' : 'http';
      $width = variable_get('tp_videos_jwplatform_width', 640);
      $replacement = "{$scheme}://content.jwplatform.com/videos/{$token}-{$width}.mp4";
    }
  }
  return $replacement;
}

function tp_videos_token_attached_video_url($node, $secure = FALSE) {
  $replacement = NULL;
  if ($file = tp_videos_token_attached_file($node, 'field_video')) {
    if ($file->filemime === 'video/youtube') {
      $params = tp_videos_parse_wrapper_uri($file->uri);
      $token = $params['v'];
      $scheme = $secure ? 'https' : 'http';
      $replacement = "{$scheme}://www.youtube.com/v/{$token}?autohide=1&version=3";
    }
    elseif ($file->filemime === 'video/jwplatform') {
      $params = tp_videos_parse_wrapper_uri($file->uri);
      $token = $params['key'];
      $scheme = $secure ? 'https' : 'http';
      $video_url = tp_videos_token_attached_video_file_url($node, $secure);
      $player_path = drupal_get_path('module', 'tp_videos') . '/assets/player.swf';
      $replacement = url($player_path, array(
        'absolute' => TRUE,
        'https' => $secure,
        'query' => array(
          'file' => $video_url,
          'autostart' => 'true',
        ),
        'alias' => TRUE,
      ));
    }
  }
  return $replacement;
}

function tp_videos_token_attached_video_width($node) {
  $replacement = NULL;
  if ($file = tp_videos_token_attached_file($node, 'field_video')) {
    if (isset($file->tp_videos_metadata)) {
      $replacement = variable_get('tp_videos_jwplatform_width', 640);
    }
  }
  return $replacement;
}

function tp_videos_token_attached_video_height($node) {
  $replacement = NULL;
  if ($file = tp_videos_token_attached_file($node, 'field_video')) {
    if (isset($file->tp_videos_metadata)) {
      $width = variable_get('tp_videos_jwplatform_width', 640);
      $height = ($file->tp_videos_metadata->height * $width)
        / $file->tp_videos_metadata->width;
      $replacement = intval($height);
    }
  }
  return $replacement;
}

function tp_videos_token_attached_video_length($node) {
  $replacement = NULL;
  if ($file = tp_videos_token_attached_file($node, 'field_video')) {
    if (isset($file->tp_videos_metadata)) {
      $replacement = $file->tp_videos_metadata->length;
    }
  }
  return $replacement;
}

function tp_videos_token_attached_video_image($node, $secure = FALSE) {
  $replacement = NULL;
  if ($file = tp_videos_token_attached_file($node, 'field_video')) {
    if (isset($file->tp_videos_metadata)) {
      $url = $file->tp_videos_metadata->thumbnail_image;
      list(, $resource) = explode('//', $url, 2);
      $replacement = ($secure ? 'https://' : 'http://') . $resource;
    }
  }
  return $replacement;
}
