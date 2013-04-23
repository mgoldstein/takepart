<?php
/**
 * @file
 * Blue State Digital Simple Cache.
 */

class BlueStateDigitalCacheController {

  private $bin;

  public function __construct() {
    $this->clear();
  }

  public function get($key, $value) {
    if (in_array($key, $this->bin)) {
      $value = $this->bin[$key];
      return TRUE;
    }
    return FALSE;
  }

  public function set($key, $value) {
    $this->bin[$key] = $value;
    return TRUE;
  }

  public function clear() {
    $this->bin = array();
  }
}
