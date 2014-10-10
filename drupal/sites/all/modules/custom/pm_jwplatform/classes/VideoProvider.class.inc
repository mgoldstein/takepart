<?php

class JWPlatformMediaInternetVideoProvider extends JWPlatformMediaInternetContentProvider {

  public function __construct($embedCode) {
    parent::__construct($embedCode, 'video');
  }

  public function getFilename() {
    return "Video ({$this->content_key})";
  }
}
