<?php
/**
 * @file
 */

class MediaInternetBitsOnTheRunHandler extends MediaInternetBaseHandler {

  public function parse($embed_code) {
    $patterns = array(
      '@dashboard.bitsontherun.com/(videos|channels)/([A-Za-z0-9]+)@i',
    );
    foreach ($patterns as $pattern) {
      $matches = array();
      preg_match($pattern, $embed_code, $matches);
      if (isset($matches[1]) && isset($matches[2])) {
        $type = $matches[1] === 'videos' ? 'v' : 'p';
        $uri = 'botr://' . $type . '/' . $matches[2];
        return file_stream_wrapper_uri_normalize($uri);
      }
    }
  }

  public function claim($embed_code) {
    return $this->parse($embed_code) ? TRUE : FALSE;
  }

  public function getFileObject() {
    if (!$this->fileObject) {
      $uri = $this->parse($this->embedCode);
      $this->fileObject = file_uri_to_object($uri, TRUE);
    }
    return $this->fileObject;
  }
}
