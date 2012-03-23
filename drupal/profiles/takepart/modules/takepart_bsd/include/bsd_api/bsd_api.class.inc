<?
/**
* BSD API Class.
* @see
*  http://tkprt.bluestatedigital.com/modules/api/resources/v1_0/bsd_api.zip
**/
class BSD_API {

  var $api_id;
  var $api_secret;
  var $rest_method;

  var $http_request_base;
  var $http_request_timeout;

  var $deferred_result_call_interval;
  var $deferred_result_call_max_attempts;

  
  const HTTP_CODE_OK                          = 200;
  const HTTP_CODE_DEFERRED_RESULT             = 202;
  const HTTP_CODE_CONFLICT                    = 409;
  const HTTP_CODE_DEFERRED_RESULT_COMPILING   = 503;
    
  const REST_METHOD_STREAM_WRAPPER = 0;
  const REST_METHOD_CURL = 1;

  const API_VER = 1;

  public function __construct($api_id, $api_secret, $rest_method) {
    // store vars requied by BSD API
    $this->api_id = $api_id;
    $this->api_secret = $api_secret;
    $this->rest_method = $rest_method;

    // set deferred result defaults

    // *these are sample values and may be modified as you see fit*
    $this->deferred_result_call_interval = 5; // in seconds
    $this->deferred_result_call_max_attempts = 20;
    
    // *modify the value below*
    $this->http_request_base = 'http://tkprt.bluestatedigital.com/page/api/';
    $this->http_request_timeout = 10;
  }
  
  public function callApi($url, $query_params = array(), $data = NULL, $block = TRUE) {
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

    // send the request
    try {
      if ($this->rest_method == self::REST_METHOD_STREAM_WRAPPER) {
        $response = $this->stream_wrapper($url, $data);
      }
      else /* self::REST_METHOD_CURL */ {
        $response = $this->_curl($url, $data);
      }
      if ($block && $response['http_code'] == self::HTTP_CODE_DEFERRED_RESULT) {
        $response = $this->_deferredResult($response['body']);
      }
      return $response;
    }
    catch (Exception $ex) {
      $message = t('Problem connecting to Blue State Digital');
      watchdog('takepart_bsd', $ex->getMessage());
    }

    return FALSE;  
  }
  
  private function _deferredResult($deferred_id) {
  
    $attempt = 0;
        
    // loop until result is ready or until we give up
    do {
      // delay between calls (in seconds)
      sleep($this->deferred_result_call_interval); 
            
      // check to see if result is ready
      $response = $this->callApi('get_deferred_results', array('deferred_id' => $deferred_id));
            
      // increment attempts counter
      $attempt++;
      
    } while($response['http_code'] == self::HTTP_CODE_DEFERRED_RESULT_COMPILING && $attempt < $this->deferred_result_call_max_attempts);
        
    // if the response code isn't HTTP_CODE_OK then we didn't get the result we wanted
    if($response['http_code'] != self::HTTP_CODE_OK) {
      // did we go over our "max attempts"?
      if($attempt >= $this->deferred_result_call_max_attempts) {
        throw new Exception('Could not retrieve deferred result.  Max attempts reached.', 1);
      }
      // we must have received an unexpected HTTP code
      else {
        throw new Exception('Could not retrieve deferred result.  HTTP Code ' . 
          $response['http_code'] . ' was returned, with the following message: ' . 
          $response['body'], 2);
      }
    }
        
    // return request result
    return $response;
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

  private function _stream_wrapper($url, $data = NULL) {
    
    $http_code = '200';
    
    if ($data) {
      
      $params = array(
        'http' => array(
          'method' => 'POST',
          'content' => $data
        ),
      );
      
      $ctx = stream_context_create($params);
      $fp = @fopen($url, 'rb', FALSE, $ctx);
      if (!$fp) {
        throw new Exception("Problem with $url, $php_errormsg");
      }
      $response = @stream_get_contents($fp);
      if ($response === false) {
        throw new Exception("Problem reading data from $url, $php_errormsg");
      }
      
      $body = $response;
    }
    else {
      
      $response = file_get_contents($url);
      if (! file_get_contents("data:,ok")) {
        watchdog("takepart_bsd", "PHPs stream handlers are not functional.");
      }
      
      $body = $response;
    }
    
    return array(
      'http_code' => $http_code,
      'body' => $body,
    );
  }
  
  private function _curl($url, $data = NULL) {
    
    // make sure curl is installed
    if (! function_exists('curl_init')) {
      watchdog('takepart_bsd', 'Curl is not installed.');
      return '';
    }
    
    $ch = curl_init();
    curl_setopt($ch, CURLOPT_URL, $url);
    curl_setopt($ch, CURLOPT_TIMEOUT, $this->http_request_timeout);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
    // Include header in result:
    curl_setopt($ch, CURLOPT_HEADER, 1);
    if ($data) {
      curl_setopt($ch,CURLOPT_POST, 1);
      curl_setopt($ch,CURLOPT_POSTFIELDS, $data);
    }
    
    $response = curl_exec($ch);
    $header_length = curl_getinfo($ch, CURLINFO_HEADER_SIZE);
    //$content_length = curl_getinfo($ch, CURLINFO_CONTENT_LENGTH_DOWNLOAD);
    $http_code = curl_getinfo($ch, CURLINFO_HTTP_CODE);
    $body = trim(substr($response, $header_length));
    curl_close($ch);
    
    return array(
      'http_code' => $http_code,
      'body' => $body,
    );
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
