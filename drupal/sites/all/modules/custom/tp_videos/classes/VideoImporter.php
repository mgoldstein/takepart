<?php

abstract class TakePart_VideoImporter {

  public function claim($url) {
    return NULL;
  }

  public function import($url, $reset = FALSE) {

    $token = $this->claim($url);
    if (is_null($token)) { return NULL; }

    $klass = get_class($this);
    $key = "tp_video:{$klass}:$token";

    static $data = NULL;
    if (is_null($data) || $reset) {
      if ((!$reset) && ($cache = cache_get($key))) {
        $data = $cache->data;
      }
      else {
        $data = $this->fetchVideoData($token);
        if (!is_null($data)) {
          cache_set($key, $data);
        }
      }
    }

    if (!is_null($data)) {
      return $this->buildVideo($token, $data);
    }
    return NULL;
  }

  abstract protected function fetchVideoData($token);

  abstract protected function buildVideo($token, $data);
}
