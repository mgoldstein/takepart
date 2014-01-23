<?php

class JWPlatformMediaInternetChannelProvider extends JWPlatformMediaInternetContentProvider {

  public function __construct($embedCode) {
    parent::__construct($embedCode, 'channel');
  }

  public function getFilename() {
    return "Playlist ({$this->content_key})";
  }
}
