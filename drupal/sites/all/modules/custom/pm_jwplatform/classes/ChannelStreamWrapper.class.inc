<?php

class JWPlatformChannelStreamWrapper extends JWPlatformContentStreamWrapper {

  public function interpolateUrl() {
    if ($parameters = $this->get_parameters()) {
      $filename = $parameters['key'];
      return $this->base_url . 'jw6/' . $filename . '.xml';
    }
  }

  public static function getMimeType($uri, $mapping = NULL) {
    if (strncmp($uri, 'jwplatform-channel://', 21) === 0) {
      return 'video/jwplatform';
    }
  }
}
