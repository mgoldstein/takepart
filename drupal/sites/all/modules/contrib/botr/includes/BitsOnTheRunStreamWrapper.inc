<?php
/**
 * @file
 * Stream wrapper for Bits on the Run video.
 * e.g. botr://v/[video-code] or botr://p/[playlist-code]
 */
class BitsOnTheRunStreamWrapper extends MediaReadOnlyStreamWrapper {

  protected $base_url = 'http://video.takepart.com/players/';

  function interpolateUrl() {
    if ($parameters = $this->get_parameters()) {
      $filename = $parameters['v'];
      return $this->base_url . $filename . '.js';
    }
  }

  static function getMimeType($uri, $mapping = NULL) {
    if (strncmp($uri, 'botr://v', 8) === 0) {
      return 'video/botr';
    }
    return 'playlist/botr';
  }

  function getOriginalThumbnailPath() {
    $parts = $this->get_parameters();
    $key = isset($parts['v']) ? $parts['v'] : $parts['p'];
    return 'http://content.bitsontherun.com/thumbs/' . check_plain($key) . '-120.jpg';
  }

  function getLocalThumbnailPath() {
    $parts = $this->get_parameters();
    // There's no need to hide thumbnails, always use the public system rather
    // than file_default_scheme().
    $key = isset($parts['v']) ? $parts['v'] : $parts['p'];
    $local_path = 'public://botr-media/' . check_plain($key) . '.jpg';
    if (!file_exists($local_path)) {
      $dirname = drupal_dirname($local_path);
      file_prepare_directory($dirname, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);
      $response = drupal_http_request($this->getOriginalThumbnailPath());
      if (!isset($response->error)) {
        file_unmanaged_save_data($response->data, $local_path, TRUE);
      }
      else {
        @copy($this->getOriginalThumbnailPath(), $local_path);
      }
    }
    return $local_path;
  }
}
