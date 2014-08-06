<?php namespace Participant\MetaData\Video;

class JWPlatformVideo implements SharedVideo
{
  protected $api;
  protected $key;
  protected $preferred_width;

  public function __construct($api, $key, $preferred_width)
  {
    $this->api = $api;
    $this->key = $key;
    $this->preferred_width = $preferred_width;
  }

  protected function retrieveConversions()
  {
    $response = $this->api->call("/videos/conversions/list", array("video_key" => $this->key));
    if (isset($response['status']) && $response['status'] === 'ok') {
      return $response['conversions'];
    }
    return array();
  }

  protected function getOriginalConversion()
  {
    $conversions = $this->retrieveConversions();
    foreach ($conversions as $conversion) {
      if (isset($conversion['template']['format']['key'])
        && $conversion['template']['format']['key'] == 'original') {
        return $conversion;
      }
    }
    return NULL;
  }

  public function openGraphURL($https = FALSE)
  {
    $video_url = $this->url($https);

    $player_path = drupal_get_path('module', 'pm_core') . '/assets/player.swf';

    $absolute_url = url($player_path, array(
      'absolute' => TRUE,
      'https' => FALSE,
      'query' => array(
        'file' => $video_url,
        'autostart' => 'true',
      ),
      'alias' => TRUE,
    ));

    list(, $resource) = explode('://', $absolute_url, 2);
    $scheme = $https ? 'https://' : 'http://';
    return $scheme . $resource;
  }

  public function url($https = FALSE)
  {
    $video_url  = $https ? 'https://' : 'http://';
    $video_url .= variable_get('pm_jwplatform_content_domain');
    $video_url .= '/videos/' . $this->key . '-' . $this->preferred_width .'.mp4';
    return $video_url;
  }

  public function width()
  {
    return $this->preferred_width;
  }

  public function height()
  {
    $original = $this->getOriginalConversion();
    if (!is_null($original)) {
      return intval(($this->preferred_width * $original['height']) / $original['width']);
    }
    return NULL;
  }
}
