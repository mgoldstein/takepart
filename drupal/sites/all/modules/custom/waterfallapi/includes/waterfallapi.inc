<?php

/**
 * Waterfall API Wrapper
 */
class Waterfall {

  public static function Api() {
    static $instance = NULL;
    if ($instance === NULL) {
      $instance = new Waterfall(
        'http://three.waterfallmobile.com/api/v1/', 10, '/tmp'
      );
    }
    return $instance;
  }

  private $base;
  private $timeout;
  private $cookieJar;

  private function __construct($base, $timeout, $sessions) {

    $this->base = $base;
    if (substr($this->base, -1) != '/') {
      $this->base .= '/';
    }
    $this->timeout = $timeout;

    $this->cookieJar = tempnam($sessions, 'waterfall.session.');
    $fp = fopen($this->cookieJar, 'w+');
    fclose($fp);
  }

  function __destruct() {
    unlink($this->cookieJar);
  }

  protected function makeRequest($method, $url, $params = array(), $payload = array()) {

    $url = $this->base . $url;
    if (!empty($params)) {
      // Add query string to request URL.
      $url .= '?' . http_build_query($params);
    }

    $ch = curl_init();

    if ($method !== 'GET' && $method !== 'POST') {
      curl_setopt($ch, CURLOPT_CUSTOMREQUEST, $method);
    }

    curl_setopt($ch, CURLOPT_URL, $url);
    curl_setopt($ch, CURLOPT_TIMEOUT, $this->timeout);

    // COOOOOOKIEEEEES!!!
    curl_setopt($ch, CURLOPT_COOKIEJAR, $this->cookieJar);
    curl_setopt($ch, CURLOPT_COOKIEFILE, $this->cookieJar);

    // Return the transfer as a string.
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, TRUE);

    // Include headers in the request.
    $headers = array(
      "Content-Type: application/json",
      // Instruct the API to return JSON
      "Accept: application/json",
    );
    curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);

    // Include the header in result.
    curl_setopt($ch, CURLOPT_HEADER, 1);

    // Add in the payload.
    if ($method !== 'GET' && !empty($payload)) {
      curl_setopt($ch, CURLOPT_POST, 1);
      $json = json_encode($payload);
      curl_setopt($ch, CURLOPT_POSTFIELDS, $json);
    }

    $response = @curl_exec($ch);
    $http_code = curl_getinfo($ch, CURLINFO_HTTP_CODE);
    $header_length = curl_getinfo($ch, CURLINFO_HEADER_SIZE);
    $body = trim(substr($response, $header_length));

    curl_close($ch);

    if ($http_code === 200) {
      return json_decode($body);
    }
    elseif($http_code === 204) {
      return TRUE;
    }
    else {
      return json_decode($body);
    }
  }

  public function get($url, $params = NULL) {
    return $this->makeRequest('GET', $url, $params);
  }

  public function post($url, $payload = NULL, $params = NULL) {
    return $this->makeRequest('POST', $url, $params, $payload);
  }

  public function put($url, $payload = NULL, $params = NULL) {
    return $this->makeRequest('PUT', $url, $params, $payload);
  }

  public function delete($url, $payload = NULL, $params = NULL) {
    return $this->makeRequest('DELETE', $url, $params, $payload);
  }
}

/**
 * Mobile phone campaign management API.
 */
class PhoneCampaigns {

  const US_SHORT_CODE = '50ac121203644bd985ef24d4';
  const CANADIAN_SHORT_CODE = '505b80e60364fb7d2e2f10e6';

  public static function US() {
    static $instance = NULL;
    if ($instance === NULL) {
      $instance = new PhoneCampaigns(self::US_SHORT_CODE);
    }
    return $instance;
  }

  public static function Canada() {
    static $instance = NULL;
    if ($instance === NULL) {
      $instance = new PhoneCampaigns(self::CANADIAN_SHORT_CODE);
    }
    return $instance;
  }

  public static function Sanitize($number) {
    return str_replace(array('(',')',' ','-','.'), '', "{$number}");
  }

  public static function ForAreaCode($number) {
    $number = self::Sanitize($number);
    if (strlen($number) > 3) {
      $number = substr($number, 0, 3);
    }
    return self::IsCanadianAreaCode($number) ? self::Canada() : self::US();
  }

  public static function IsCanadianAreaCode($area_code) {
    static $canadianAreaCodes = array(
      204, 226, 236, 249, 250, 289, 306, 343, 365,
      416, 418, 431, 437, 438, 450, 483, 506, 514,
      519, 579, 581, 587, 613, 639, 647, 705, 709,
      778, 780, 807, 819, 867, 873, 902, 905,
    );
    return in_array($area_code, $canadianAreaCodes);
  }

  private $shortCode;

  private function __construct($short_code) {
    $this->shortCode = $short_code;
  }

  public function flows() {
    $flows = Waterfall::Api()->get('mobileflow', array(
      'shortCode' => $this->shortCode
    ));
    return $flows->collection;
  }

  public function initiateFlow($flow_id, $phone_number) {
    $payload = new StdClass();
    $payload->msisdns = array($phone_number);
    $payload->mobileFlow = $flow_id;
    Waterfall::Api()->post('messaging/sendContent', $payload);
  }
}



















/**
 * Waterfall API Library
 * A simple class for interacting with the
 * Waterfall Mobile API.
 * @see: Charles Toepfer, ctoepfer@takepart.com for questions.
 * @todo: Incomplete and not fully abstracted.
 */
class waterFallAPI {

  const TIMEOUT = 0;
  const BASEDOMAIN = "http://three.waterfallmobile.com";
  public function __construct(){}

  /**
   * Add a subscriber.
   * @param string $list
   *   A GUID representing the list you want to add the subscriber to.
   * @param string $phone
   *   The msisdns or phone number.
   * @param string $confirmMessage
   * @param string $optInMessage
   * @param string $subscribedMessage
   * @param array $metadata
   *   An array including the GUIDs and parameters ([GUID]=param)
   *   for extra data.
   * @param array $basictext
   *   Send a basic text message.
   * @return string
   *   Response from API.
   */
  public function addSubscriber(  $list, $phone, $metadata, $basictext,
                  $confirmMessage = null, $flowid, $shortCode, $optInMessage = null,
                  $subscribedMessage = null) {
    $payload = $this->buildSubscriberJSON($list, $phone, $metadata,
                  $basictext, $flowid, $shortCode, $optInMessage, $confirmMessage,
                  $subscribedMessage);

    //$url = $this::BASEDOMAIN . "/api/v1/messaging/sendContent";
    $url = "http://three.waterfallmobile.com" . "/api/v1/messaging/sendContent";

    watchdog('waterFallAPI_Payload', $url . '|' . $payload);

    $return = $this->curl_post($url, $payload);
    return $return;
  }

  /**
   * Establishes authenticattion needed
   * before making subsequent calls
   * @param string $user
   * @param string $pass
   * @return string
   *   Response from API.
   */
  public function authenticate($user, $pass) {
    $payload = $this->buildLoginJSON($user, $pass);
    //$url = $this::BASEDOMAIN . "/api/v1/authenticate";
    $url = "http://three.waterfallmobile.com" . "/api/v1/authenticate";
    $return = $this->curl_post($url, $payload);
    return $return;
  }

     /**
   * Manually logout
   * @return string
   *   Response from API.
   */
  public function logout() {
    //$url = $this::BASEDOMAIN . "/api/v1/authenticate/logout";
    $url = "http://three.waterfallmobile.com" . "/api/v1/authenticate/logout";
    $return = $this->curl_post($url);
    return $return;
  }

     /**
   * Manually logout
   * @return string
   *   XML Response from API.
   */
  public function whoami() {
    //$url = $this::BASEDOMAIN . "/api/v1/authenticate/whoami";
    $url = "http://three.waterfallmobile.com" . "/api/v1/authenticate/whoami";
    $return = $this->curl_get($url);
    return $return;
  }

  /**
   * Provide basic list information using
   * the list ID.
   * @param string $id
   * @return string
   *   XML response from API.
   */
  public function listInfoByID($id) {
    //$url = $this::BASEDOMAIN . "/api/v1/list/$id";
    $url = "http://three.waterfallmobile.com" . "/api/v1/list/$id";
    $return = $this->curl_get($url);
    return $return;
  }

  /**
   * Provide basic list information using
   * the list Name.
   * @param string $name
   * @return string
   *   XML response from API.
   */
  public function listInfoByName($name) {
    $json = new stdClass();
    $json->{'name'} = $name;
    //$url = $this::BASEDOMAIN . "/api/v1/list";
    $url = "http://three.waterfallmobile.com" . "/api/v1/list";
    $return = $this->curl_post($url, json_encode($json));
    return $return;
  }

  public function addMetadata($metadata, $msisdn) {
    $json = new stdClass();
    if(!empty($metadata)) {
      foreach ($metadata as $k => $v) {
          $json->{'id'} = $k;
          $json->{'value'} = $v;
      }
    }
    $url = "http://three.waterfallmobile.com" . "/api/v1/subscriber/addMetadata/" . $msisdn;
    $json = json_encode($json);

    $return = $this->curl_post($url, $json, "PUT");
    watchdog('addMetadata', $url . '|' . $json . '|' . $return);
    return $return;
  }

  public function setSessionShortCode($id) {
    //$url = $this::BASEDOMAIN . " /api/v1/shortcode/sessionshortcode/" . $id;
    $url = "http://three.waterfallmobile.com" . "/api/v1/shortcode/sessionshortcode/" . $id;
    $return = $this->curl_post($url);
    return $return;
  }

  public function metaDataInfo() {
    //$url = $this::BASEDOMAIN . "/api/v1/metadata";
    $url = "http://three.waterfallmobile.com" . "/api/v1/metadata";
    $return = $this->curl_get($url);
    return $return;
  }

  private function implodePayload($payload) {
    $params = array();
    foreach ($payload as $key => $value) {
      $params[] = $key . '=' . urlencode($value);
    }
    return implode('&', $params);
  }

  private function getCookieTempPath() {
    if(!isset($this->cookiefile)) {
      $this->cookiefile = tempnam("/tmp", "CURLCOOKIE");
    }
    return $this->cookiefile;
  }

  public function getCanadianAreaCodes() {
    return explode(",", "867,236,250,778,587,780" .
              "483,306,639,204,431,807" .
              "249,705,226,519,289,365" .
              "905,416,437,647,343,613" .
              "438,514,450,579,819,873" .
              "418,581,506,902,709");
  }

  private function buildSubscriberJSON( &$list, &$phone, &$metadata,
                      &$basictext, &$flowid, &$shortCode, &$optInMessage,
                      &$confirmMessage,  &$subscribedMessage) {
    $json = new stdClass();
    /*
    $json->{'modules'} = array();
    $json->{'modules'}[0] = new stdClass();
    $json->{'modules'}[0]->{'type'} = "SUBSCRIPTION";
    $json->{'modules'}[0]->{'params'} = new stdClass();
    $json->{'modules'}[0]->{'params'}->{'listId'} = $list;
    $json->{'modules'}[0]->{'params'}->{'optInType'} = "singleOptIn";
    if(!is_null($optInMessage)) $json->{'modules'}[0]->{'params'}->{'optInMessage'} = $optInMessage;
    if(!is_null($confirmMessage)) $json->{'modules'}[0]->{'params'}->{'confirmMessage'} = $confirmMessage;
    if(!is_null($subscribedMessage)) $json->{'modules'}[0]->{'params'}->{'optInMessage'} = $subscribedMessage;
    if(!empty($metadata)) {
      $json->{'modules'}[1] = new stdClass();
      $json->{'modules'}[1]->{'type'} = "TAGMETADATA";
      $json->{'modules'}[1]->{'params'} = new stdClass();
      foreach ($metadata as $k => $v) {
          $json->{'modules'}[1]->{'params'}->{$k} = $v;
      }
    }
    if(!empty($basictext)) {
      $json->{'modules'}[2] = new stdClass();
      $json->{'modules'}[2]->{'type'} = "BASICTEXT";
      $json->{'modules'}[2]->{'params'} = new stdClass();
      $json->{'modules'}[2]->{'params'}->{"response"} = $basictext;
    }*/
    $json->{'msisdns'} = array();
    $json->{'msisdns'}[0] = $phone;
    $json->{'shortCode'} = $shortCode;
    $json->{'mobileFlow'} = $flowid;
    return json_encode($json);
  }

  private function buildLoginJSON(&$user, &$pass) {
    $json = new stdClass();
    $json->{'username'} = $user;
    $json->{'password'} = $pass;
    return json_encode($json);
  }

  private function curl_post(&$url, &$payload = null, $customreq = null) {

      //print "<pre>PAYLOAD:";
      //print_r($payload);
      //print "</pre>";

    if (function_exists('curl_init')) {
      $ch = curl_init();

      $headers = array("Accept-Encoding: gzip",
                     "Content-Type: application/json");

      if(!is_null($customreq)) {
        curl_setopt($ch, CURLOPT_CUSTOMREQUEST, $customreq);
      }

      curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);
      curl_setopt($ch, CURLOPT_URL, $url);
      curl_setopt($ch, CURLOPT_POST, 1);
      //curl_setopt($ch, CURLOPT_TIMEOUT, $this::TIMEOUT);
      if(!is_null($payload)) {
        curl_setopt($ch, CURLOPT_POSTFIELDS, $payload);
      } else {
        curl_setopt($ch, CURLOPT_POSTFIELDS, '');
      }
      curl_setopt($ch, CURLOPT_HEADER, 0);

      curl_setopt($ch, CURLOPT_COOKIEJAR, $this->getCookieTempPath());
      curl_setopt($ch, CURLOPT_COOKIEFILE, $this->getCookieTempPath());
      curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);


      $response = @curl_exec($ch);

      //$header_length = curl_getinfo($ch, CURLINFO_HEADER_SIZE);
      //$content_length = curl_getinfo($ch, CURLINFO_CONTENT_LENGTH_DOWNLOAD);
      //$http_code = curl_getinfo($ch, CURLINFO_HTTP_CODE);
      //$body = trim(substr($response, $header_length));

      curl_close($ch);
      //print "<pre>BODY:";
      //print_r($response);
      //print "</pre>";
      return $response;
    }
  }
  private function curl_get(&$url) {
    if (function_exists('curl_init')) {
      $ch = curl_init();
      curl_setopt($ch, CURLOPT_URL, $url);
      //curl_setopt($ch, CURLOPT_TIMEOUT, $this::TIMEOUT);
      curl_setopt($ch, CURLOPT_COOKIEJAR, $this->getCookieTempPath());
      curl_setopt($ch, CURLOPT_COOKIEFILE, $this->getCookieTempPath());
      curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
      $response = @curl_exec($ch);
      curl_close($ch);
      return $response;
    }
  }
}
