<?php

abstract class JWPlatformContentStreamWrapper extends MediaReadOnlyStreamWrapper {

  protected $dns_mask;

  public function __construct() {
    global $is_https;
    $dns_mask = variable_get('pm_jwplatform_content_domain', 'content.jwplatform.com');
    $scheme = $is_https ? 'https' : 'http';
    $this->base_url = "{$scheme}://{$dns_mask}/";
  }

  public function getJavaScriptUrl() {
    if ($parameters = $this->get_parameters()) {
      $filename = $parameters['key'];
      if (isset($parameters['player'])) {
        $filename .= '-' . $parameters['player'];
      }
      return $this->base_url . 'players/' . $filename . '.js';
    }
  }

  public function getOriginalThumbnailPath() {
    $parameters = $this->get_parameters();
    return 'http://content.jwplatform.com/thumbs/'
      . check_plain($parameters['key']) . '-120.jpg';
  }

  public function saveThumbnail($local_path) {
    $dirname = drupal_dirname($local_path);
    file_prepare_directory($dirname,
      FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);
    $response = drupal_http_request($this->getOriginalThumbnailPath());
    if (!isset($response->error)) {
      file_unmanaged_save_data($response->data, $local_path, TRUE);
      return TRUE;
    }
    return FALSE;
  }

  public function getLocalThumbnailPath() {
    $parameters = $this->get_parameters();
    $local_path = 'public://jwplatform-thumbnails/'
      . check_plain($parameters['key']) . '.jpg';
    if (!file_exists($local_path)) {
      if (!$this->saveThumbnail($local_path)) {
        return NULL;
      }
    }
    return $local_path;
  }
}
