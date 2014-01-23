<?php

abstract class JWPlatformMediaInternetContentProvider extends MediaInternetBaseHandler {

  protected $content_type = NULL;

  protected $content_key = NULL;
  protected $player_key = NULL;

  public function __construct($embedCode, $content_type) {
    parent::__construct($embedCode);
    $this->content_type = $content_type;
  }

  public function getStreamUri() {
    if (isset($this->content_key)) {
      $uri = 'jwplatform-' . $this->content_type . '://key/'
        . $this->content_key;
      if (isset($this->player_key)) {
        $uri .= '/player/' . $this->player_key;
      }
      return file_stream_wrapper_uri_normalize($uri);
    }
    return NULL;
  }

  abstract public function getFilename();

  protected function getPatterns() {

    // Use the same embed code expression so all matches with look the same
    $embed_pattern = '([A-Za-z0-9]+)(-([A-Za-z0-9]+))?';

    // Embed code using the BotR domain name
    $patterns = array(
      '@dashboard.bitsontherun.com/' . $this->content_type . 's/([A-Za-z0-9]+)@',
      '@dashboard.jwplatform.com/' . $this->content_type . 's/([A-Za-z0-9]+)@',
      '@content.bitsontherun.com/players/' . $embed_pattern . '@',
    );

    // Embed code using DNS mask (if one is provided)
    $dns_mask = variable_get('pm_jwplatform_content_dns_mask',
      'content.bitsontherun.com');
    if ($dns_mask !== 'content.bitsontherun.com') {
        $patterns[] = '@' . $dns_mask . '/players/' . $embed_pattern . '@';
    }

    // Embed strictly by itself
    $patterns[] = '/^' . $embed_pattern . '$/';

    return $patterns;
  }

  public static function callApiTypeShow($type, $key) {
    $api = pm_jwplatform_get_api();
    if ($api !== FALSE) {
      $response = $api->call("/{$type}s/show", array("{$type}_key" => $key));
      if (isset($response['status']) && $response['status'] === 'ok') {
        return $response[$type];
      }
    }
    return FALSE;
  }

  public static function getApiTypeInfo($type, $key) {
    static $cache = array();
    $cid = "{$type}:{$key}";
    if (!isset($cache[$cid])) {
      $cache[$cid] = cache_get($cid, 'cache_pm_jwplatform');
      if ($cache[$cid] === FALSE) {
        $cache[$cid] = self::callApiTypeShow($type, $key);
        if ($cache[$cid] !== FALSE) {
          cache_set($cid, $cache[$cid], 'cache_pm_jwplatform');
        }
      }
    }
    return $cache[$cid];
  }

  public function getContentInfo() {
    return self::getApiTypeInfo($this->content_type, $this->content_key);
  }

  public function getPlayerInfo() {
    if (isset($this->player_key)) {
      return self::getApiTypeInfo('player', $this->player_key);
    }
    return FALSE;
  }

  public function parse($embed_code) {
    foreach ($this->getPatterns() as $pattern) {
      $matches = array();
      preg_match($pattern, $embed_code, $matches);
      if (isset($matches[1])) {
        $this->content_key = $matches[1];
        $this->player_key = isset($matches[3]) ? $matches[3] : NULL;
        return TRUE;
      }
    }
    return FALSE;
  }

  public function claim($embed_code) {
    if ($this->parse($embed_code)) {
      return ($this->getContentInfo() !== FALSE);
    }
    return FALSE;
  }

  public function getFileObject() {
    if (empty($this->fileObject) && $this->claim($this->embedCode)) {
      $this->fileObject = file_uri_to_object($this->getStreamUri(), TRUE);
      $this->fileObject->filename = $this->getFilename();
    }
    return $this->fileObject;
  }
}
