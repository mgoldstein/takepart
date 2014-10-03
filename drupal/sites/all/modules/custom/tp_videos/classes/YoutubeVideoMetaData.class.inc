<?php

class YoutubeVideoMetaData
{
  protected $key;
  protected $preferred_width;

  public function __construct($key, $preferred_width)
  {
    $this->key = $key;
    $this->preferred_width = $preferred_width;
  }

  protected function getOpenGraphProperties()
  {
    static $openGraph = FALSE;
    if ($openGraph === FALSE) {
      $options = array('getBiggerImage' => TRUE);
      $url = "https://www.youtube.com/watch?v={$this->key}";
      $info = \Embed\Embed::create($url, $options);
      $openGraph = $info->providers['OpenGraph'];
    }
    return $openGraph;
  }

  public function openGraphURL($https = FALSE)
  {
    $openGraph = $this->getOpenGraphProperties();
    $url = $openGraph->get('video');
    list(, $resource) = explode('://', $url, 2);
    $scheme = $https ? 'https://' : 'http://';
    return $scheme . $resource;
  }

  public function url($https = FALSE)
  {
    $scheme = $https ? 'https' : 'http';
    return "{$scheme}://www.youtube.com/embed/{$this->key}";
  }

  public function width()
  {
    $openGraph = $this->getOpenGraphProperties();
    return $openGraph->get('video:width');
  }

  public function height()
  {
    $openGraph = $this->getOpenGraphProperties();
    return $openGraph->get('video:height');
  }
}
