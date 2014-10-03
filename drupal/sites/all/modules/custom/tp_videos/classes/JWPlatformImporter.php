<?php

class TakePart_JWPlatformImporter extends TakePart_VideoImporter {

  public function claim($url) {

    // Use the same embed code expression so all matches with look the same
    $embed_pattern = '([A-Za-z0-9]+)(-([A-Za-z0-9]+))?';
    $patterns = array(
      '@^' . $embed_pattern . '$@i',
      '@dashboard\.bitsontherun\.com/channels/([A-Za-z0-9]+)@i',
      '@content\.bitsontherun\.com/players/' . $embed_pattern . '@i',
      '@dashboard\.bitsontherun\.com/videos/([A-Za-z0-9]+)@i',
      '@dashboard\.jwplatform\.com/channels/([A-Za-z0-9]+)@i',
      '@content\.jwplatform\.com/players/' . $embed_pattern . '@i',
      '@dashboard\.jwplatform\.com/videos/([A-Za-z0-9]+)@i',
      '@video\.takepart\.com/channels/([A-Za-z0-9]+)@i',
      '@video\.takepart\.com/players/' . $embed_pattern . '@i',
      '@video\.takepart\.com/videos/([A-Za-z0-9]+)@i',
      // Internal refresh format
      '@TakePart_JWPlatformVideo:([A-Za-z0-9]+)@i',
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

  private function api() {
    return pm_jwplatform_get_api();
  }

  private function callShowAPI($token) {
    $response = $this->api()->call('/videos/show', array(
      'video_key' => $token,
    ));
    if ($response['status'] === 'error') {
      $response = $this->api()->call('/channels/show', array(
        'channel_key' => $token,
      ));
    }
    return $response;
  }

  private function fetchFirstVideoInChannel($token) {
    $response = $this->api()->call('/channels/videos/list', array(
      'channel_key' => $token,
      'result_limit' => 1,
    ));
    if ($response['status'] === 'ok' && count($response['videos']) > 0) {
      $video = reset($response['videos']);
      return $this->callShowApi($video['key']);
    }
    return NULL;
  }

  private function fetchVideoConversions($token) {
    $response = $this->api()->call('/videos/conversions/list', array(
      'video_key' => $token,
    ));
    if ($response['status'] === 'ok') {
      return $response['conversions'];
    }
    return NULL;
  }

  protected function fetchVideoData($token) {

    $type = NULL;
    $title = NULL;
    $video = NULL;
    $response = $this->callShowAPI($token);
    if ($response['status'] === 'ok') {
      if (isset($response['video'])) {
        $type = 'video';
        $title = $response['video']['title'];
        $video = $response['video'];
      }
      elseif (isset($response['channel'])) {
        $type = 'channel';
        $title = $response['channel']['title'];
        $response = $this->fetchFirstVideoInChannel($token);
        if ($response['status'] === 'ok') {
          $video = $response['video'];
        }
      }
    }

    if (!is_null($video)) {
      $conversions = $this->fetchVideoConversions($video['key']);
      if (!is_null($conversions)) {
        return array(
          'type' => $type,
          'title' => $title,
          'video' => $video,
          'conversions' => $conversions,
        );
      }
    }

    return NULL;
  }

  private function getOriginalConversion($conversions) {
    foreach ($conversions as $conversion) {
      if (isset($conversion['template']['format']['key'])
        && $conversion['template']['format']['key'] == 'original') {
        return $conversion;
      }
    }
    return NULL;
  }

  private function getVideoDimensions($conversions) {
    $original = $this->getOriginalConversion($conversions);
    if (!is_null($original)) {
      return array(intval($original['width']), intval($original['height']));
    }
    return array(0, 0);
  }

  protected function buildVideo($token, $data) {

    list($width, $height) = $this->getVideoDimensions($data['conversions']);

    $js_src = '//content.jwplatform.com/players/' . $token . '.js';
    $embed_code = '<script type="text/javascript" src="' . $js_src . '"></script>';

    $thumb_src = '//content.jwplatform.com/thumbs/' . $data['video']['key'] . '-720.jpg';

    return new TakePart_JWPlatformVideo(array(
      'external_key' => $token,
      'external_type' => $data['type'],
      'title' => $data['title'],
      'width' => $width,
      'height' => $height,
      'length' => intval($data['video']['duration']),
      'thumbnail_image' => $thumb_src,
      'embed_code' => $embed_code,
    ));
  }
}
