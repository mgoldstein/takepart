<?

//@todo: Add check for these:
require_once 'Crypt/HMAC.php';
require_once 'HTTP/Request.php';

class BSD_API {
    
    var $api_id;
    var $api_secret;
    
    var $http_request_base;
    var $http_request_options;
    
    var $deferred_result_call_interval;
    var $deferred_result_call_max_attempts;
    
    var $output_format;
    
    const HTTP_CODE_OK                          = 200;
    const HTTP_CODE_DEFERRED_RESULT             = 202;
    const HTTP_CODE_DEFERRED_RESULT_COMPILING   = 503;
    
    const OUTPUT_40CHARHEX = 1;
    const OUTPUT_BASE64 = 2;
    
    const API_VER = 1;
    
    public function __construct($api_id, $api_secret) {
        // store vars requied by BSD API
        $this->api_id = $api_id;
        $this->api_secret = $api_secret;
        
        // set deferred result defaults
        
        // *these are sample values and may be modified as you see fit*
        $this->deferred_result_call_interval = 30; // in seconds
        $this->deferred_result_call_max_attempts = 20;
        
        $this->output_format = self::OUTPUT_40CHARHEX;
        
        // store options to be used by HTTP_Request
        
        // *modify the value below*
        //$this->http_request_base = 'http://www.mydomain.com/page/api/';
        $this->http_request_base = 'https://tkprt.bluestatedigital.com/page/api/';
        
        $this->http_request_options = array(
            'timeout' => 10,
            'readTimeout' => array(10, 0),
            'allowRedirects' => true,
            'maxRedirects' => 3,
        );
    }
    
    public function callApi($url, $query_params = array()) {
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
        $req = new HTTP_Request($url, $this->http_request_options);
        
        // send request to API url
        $result = $req->sendRequest();
        
        // is this a deferred result?
        if($req->getResponseCode() == self::HTTP_CODE_DEFERRED_RESULT) {
            // reroute this request for more processing. the _deferredResult function should 
            // return a new HTTP_Request object with the actual requested content
            $req = $this->_deferredResult( $req->getResponseBody() );
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
        
        // return encrypted hash
        $signer = new Crypt_HMAC($this->api_secret, 'sha1');
        
        $hash = $signer->hash($signing_string);
        
        if($this->output_format == self::OUTPUT_BASE64) {
            $hash = $this->_hex2b64($hash);
        }
        // else, output_format is the default self::OUTPUT_40CHARHEX
        
        return $hash;
        
    }
    
    private function _deferredResult($deferred_id) {
        $attempt = 0;
        
        // loop until result is ready or until we give up
        do {
            // delay between calls (in seconds)
            sleep($this->deferred_result_call_interval); 
            
            // check to see if result is ready
            $req = $this->callApi('get_deferred_results', array('deferred_id' => $deferred_id));
            
            // increment attempts counter
            $attempt++;
        } while($req->getResponseCode() == self::HTTP_CODE_DEFERRED_RESULT_COMPILING && $attempt < $this->deferred_result_call_max_attempts);
        
        // if the response code isn't HTTP_CODE_OK then we didn't get the result we wanted
        if($req->getResponseCode() != self::HTTP_CODE_OK) {
            // did we go over our "max attempts"?
            if($iteration >= $this->deferred_result_call_max_attempts) {
                throw new Exception('Could not retrieve deferred result.  Max attempts reached.', 1);
            }
            // we must have received an unexpected HTTP code
            else {
                throw new Exception('Could not retrieve deferred result.  HTTP Code ' . 
                    $req->getResponseCode() . ' was returned, with the following message: ' . 
                    $req->getResponseBody(), 2);
            }
        }
        
        // return request result
        return $req;
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
