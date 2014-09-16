<?php

class TakePart_VimeoImporter extends TakePart_VideoImporter {

  public function claim($url) {

    $patterns = array(
      '@vimeo\.com/(\d+)@i',
      '@vimeo\.com/video/(\d+)@i',
      '@vimeo\.com/groups/.+/videos/(\d+)@i',
      '@vimeo\.com/channels/.+#(\d+)@i',
      '@vimeo\.com/channels/.+/(\d+)@i',
      // Internal refresh format
      '@TakePart_VimeoVideo:(\d+)@i',
    );

    foreach ($patterns as $pattern) {
      $matches = array();
      preg_match($pattern, $url, $matches);
      if (isset($matches[1])) {
        return $matches[1];
      }
    }

    return NULL;
  }

  protected function fetchVideoData($token) {
    $video_url = rawurlencode("http://vimeo.com/{$token}");
    $oembed_url = "http://vimeo.com/api/oembed.json?url={$video_url}";
    $response = drupal_http_request($oembed_url);
    if ($response->code == 200) {
      return json_decode($response->data, TRUE);
    }
    return NULL;
  }

  protected function buildVideo($token, $data) {
    return new TakePart_VimeoVideo(array(
      'external_key' => $token,
      'external_type' => $data['type'],
      'title' => $data['title'],
      'width' => intval($data['width']),
      'height' => intval($data['height']),
      'length' => intval($data['duration']),
      'thumbnail_image' => $data['thumbnail_url'],
      'embed_code' => $data['html'],
    ));
  }
}
