<?
/**
* BSD API Class.
* @see
*  http://tkprt.bluestatedigital.com/modules/api/resources/v1_0/bsd_api.zip
**/
class BSD_API {

  var $api_id;
  var $api_secret;

  var $http_request_base;
  var $http_request_options;

  var $deferred_result_call_interval;
  var $deferred_result_call_max_attempts;
  var $deferred_result_attempts;

  var $output_format;

  const API_VER = 1;
  

  public function __construct($api_id, $api_secret) {
    // store vars requied by BSD API
    $this->api_id = $api_id;
    $this->api_secret = $api_secret;

    // set deferred result defaults

    // *these are sample values and may be modified as you see fit*
    $this->deferred_result_call_interval = 5; // in seconds
    $this->deferred_result_call_max_attempts = 20;
    $this->deferred_result_attempts = 0;
    
    // *modify the value below*
    //$this->http_request_base = 'http://www.mydomain.com/page/api/';
    $this->http_request_base = 'http://tkprt.bluestatedigital.com/page/api/';

    $this->http_request_options = array(
            'timeout' => 10,
            'readTimeout' => array(10, 0),
            'allowRedirects' => true,
            'maxRedirects' => 3,
    );
  }
  

  public function callApi($url, $query_params = array(), $data = null) {
    // prepend URL with base path for the API
    $url = $this->http_request_base . $url;

    // add api_id, timestamp, and version number to query string
    $query_params['api_id'] = $this->api_id;
    if(!array_key_exists('api_ts', $query_params)) {
      $query_params['api_ts'] = time();
    }
    $query_params['api_ver'] = self::API_VER;

    // add api_mac to query string after using existing query and request url to build
    // the api_mac
    $query_params['api_mac'] = $this->_buildApiMac($url, $query_params);

    // add query string to request URL
    $url .= '?' . http_build_query($query_params);

    // create new request object and pass it connection options
    //$req = new HTTP_Request($url, $this->http_request_options);

    //@charles: changed to eliminate need for request pear module:
    //note that this will not work with deffered requests:
    if($data) {
      try {
        $req = $this->_post($url, $data);
      } catch(Exception $ex) {
          $message = t('Problem connecting to pluris');
          watchdog('bsd', $ex->getMessage());
      }
    } else {
      $req = file_get_contents($url);
      if(stripos($http_response_header[0], '202 Accepted') !== false) {
        $deferred_id = $req;
        do {
          $this->deferred_result_attempts++;
          sleep($this->deferred_result_call_interval);
          $req = $this->callApi("get_deferred_results", array("deferred_id"=>$deferred_id));
        } while ((stripos($http_response_header[0], '503') !== false) && ($this->deferred_result_attempts <= $this->deferred_result_call_max_attempts));
      }
    }
    return $req;
  }
  

  private function _buildApiMac($url, $query) {
    // break URL into parts to get the path
    $url_parts = parse_url($url);

    // build query string from given parameters
    $query_string = urldecode(http_build_query($query));

    // combine strings to build the signing string
    $signing_string = $query['api_id'] . "\n" .
    $query['api_ts'] . "\n" .
    $url_parts['path'] . "\n" .
    $query_string;

    //@charles: changed to eliminate need for HMAC pear module:
    $hash = base64_encode(hash_hmac('sha1', $signing_string, $this->api_secret, true));
    return $hash;

  }


  private function _post($url, $data, $optional_headers = null) {
    $params = array('http' => array(
                  'method' => 'POST',
                  'content' => $data
    ));
    if ($optional_headers !== null) {
      $params['http']['header'] = $optional_headers;
    }
    $ctx = stream_context_create($params);
    $fp = @fopen($url, 'rb', false, $ctx);
    if (!$fp) {
      throw new Exception("Problem with $url, $php_errormsg");
    }
    $response = @stream_get_contents($fp);
    if ($response === false) {
      throw new Exception("Problem reading data from $url, $php_errormsg");
    }
    return $response;
  }


  protected function _hex2b64($str) {
    $raw = '';
    for ($i=0; $i < strlen($str); $i+=2) {
      $raw .= chr(hexdec(substr($str, $i, 2)));
    }
    return base64_encode($raw);
  }

}

?>
