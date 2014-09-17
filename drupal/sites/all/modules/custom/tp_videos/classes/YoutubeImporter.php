<?php

class TakePart_YoutubeImporter extends TakePart_VideoImporter {

  public function claim($url) {

    $patterns = array(
      '@youtube\.com/watch[#\?].*?v=([^"\& ]+)@i',
      '@youtube\.com/embed/([^"\&\? ]+)@i',
      '@youtube\.com/v/([^"\&\? ]+)@i',
      '@youtube\.com/\?v=([^"\& ]+)@i',
      '@youtu\.be/([^"\&\? ]+)@i',
      // Internal refresh format
      '@TakePart_YoutubeVideo:([^"\& ]+)@i',
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

  private function fetchOEmbedData($token) {
    $video_url = rawurlencode("http://www.youtube.com/watch?v={$token}");
    $oembed_url = "http://www.youtube.com/oembed?url={$video_url}&format=json";
    $response = drupal_http_request($oembed_url);
    if ($response->code == 200) {
      return json_decode($response->data, TRUE);
    }
    return NULL;
  }

  private function fetchVideoLength($token) {
    $url = "http://gdata.youtube.com/feeds/api/videos/{$token}";
    $response = drupal_http_request($url);
    if ($response->code == 200) {
      $dom = new SimpleXMLElement($response->data);
      $dom->registerXPathNamespace('media', 'http://search.yahoo.com/mrss/');
      $dom->registerXPathNamespace('yt', 'http://gdata.youtube.com/schemas/2007');
      $elements = $dom->xpath('//media:group/yt:duration[@seconds]');
      if ($elements !== FALSE) {
        $element = reset($elements);
        return intval($element['seconds'] . '');
      }
    }
    return 0;
  }

  protected function fetchVideoData($token) {
    $data = $this->fetchOEmbedData($token);
    if (!is_null($data)) {
      $data['length'] = $this->fetchVideoLength($token);
    }
    return $data;
  }

  protected function buildVideo($token, $data) {
    return new TakePart_YoutubeVideo(array(
      'external_key' => $token,
      'external_type' => $data['type'],
      'title' => $data['title'],
      'width' => $data['width'],
      'height' => $data['height'],
      'length' => $data['length'],
      'thumbnail_image' => $data['thumbnail_url'],
      'embed_code' => $data['html'],
    ));
  }
}
