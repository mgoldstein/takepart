<?php
/**
 * @file
 * Blue State Digital Core API.
 *
 * @see http://tools.bluestatedigital.com/pages/our-API
 * @see http://secure.takepart.com/modules/api/resources/v1_0/bsd_api.zip
 */

/**
 * Common exception for all Blue State Digital APIs.
 */
class BlueStateDigitalApiException extends Exception {

  /**
   * @defgroup BlueStateDigitalApiExcpetionCodes BlueStateDigitalApiException
   * Exception Type Codes
   * @{
   * Codes for identifying the level of information available in the exception.
   */
  /**
   * Request error exception code.
   *
   * Used for exceptions thrown prior to receiving a valid HTTP response from
   * the API server. Exceptions using this code will NOT have values for the
   * response code or response body.
   */
  const REQUEST_ERROR = 1;
  /**
   * Failed response code.
   *
   * Used for exceptions thrown as a result of the API response returning an
   * HTTP code that indicates an error. Exceptions using this code will have
   * values for the response code and response body.
   */
  const FAILED_RESPONSE_CODE = 2;
  /**
   * Invalid response body code.
   *
   * Used for exceptions thrown as a result of not being able to parse the API
   * response returned from the API server. Exceptions using this code will
   * have values for the response code and response body.
   */
  const INVALID_RESPONSE_BODY = 3;
  /**
   * @}
   */

  /**
   * Integer HTTP code of the API response.
   *
   * @see http://en.wikipedia.org/wiki/HTTP_status_code
   */
  protected $responseCode = NULL;

  /**
   * String body of the API response.
   */
  protected $responseBody = NULL;

  /**
   * Constructs a BlueStateDigitalApiException.
   *
   * @param string $message
   *   String description of the exception.
   * @param int $code
   *   Integer exception code describing the information available in the
   *   exception, one of the following constants:
   *   - BlueStateDigitalApiException::REQUEST_ERROR
   *   - BlueStateDigitalApiException::FAILED_RESPONSE_CODE
   *   - BlueStateDigitalApiException::INVALID_RESPONSE_BODY
   * @param int $response_code
   *   (optional) Integer HTTP code of the API response.
   * @param string $response_body
   *   (optional) String containing the body of the API response, defaults to
   *   NULL.
   * @param Exception $previous
   *   (optional) The previous exception used for exception chaining, defaults
   *   to NULL.
   */
  public function __construct($message, $code, $response_code = NULL,
    $response_body = NULL, Exception $previous = NULL) {
    parent::__construct($message, $code);
    $this->responseCode = $response_code;
    $this->responseBody = $response_body;
  }

  /**
   * Get the HTTP code of the API response.
   *
   * @return int
   *   The integer HTTP code of the API response, or NULL if the HTTP code is
   *   not available.
   */
  public function getResponseCode() {
    return $this->responseCode;
  }

  /**
   * Get the body of the API response.
   *
   * @return string
   *   The string body of the API response, or NULL if the body is not
   *   available.
   */
  public function getResponseBody() {
    return $this->responseBody;
  }
}

/**
 * Blue State Digital Core API.
 */
class BlueStateDigitalApi {

  /**
   * @defgroup BlueStateDigitalApi_HTTP_CODES BlueStateDigitalApi HTTP Codes
   * @{
   * HTTP codes used by the API to indicate the return status of an API call.
   */
  /**
   * 200 OK
   *
   * The API call was sucessfully processed. The results of the call are
   * contained in the body of the HTTP response.
   */
  const HTTP_CODE_OK = 200;
  /**
   * 202 Accepted
   *
   * The API call was accepted, but results are not immediately available. The
   * body of the HTTP response will contain a deferred_id which can be used to
   * retrieve the results.
   */
  const HTTP_CODE_DEFERRED_RESULT = 202;
  /**
   * 204 No Content
   *
   * The deferred result API call succeeded but produced no output.
   */
  const HTTP_CODE_NO_CONTENT = 204;
  /**
   * 401 Unauthorized
   *
   * Authentication of the supplied credentials failed.
   */
  const HTTP_CODE_UNAUTHORIZED = 401;
  /**
   * 403 Forbidden
   *
   * The api_key used does not have permission to access the requested API
   * call.
   */
  const HTTP_CODE_API_ACCESS_DENIED = 403;
  /**
   * 404 Not Found
   *
   * Returned when attempting to access an unknown API call.
   */
  const HTTP_CODE_NOT_FOUND = 404;
  /**
   * 405 Method Not Allowed
   *
   * Attempt to access an API call that supports only GET using a POST request,
   * or a call that supports only POST using a GET request.
   */
  const HTTP_CODE_METHOD_NOT_ALLOWED = 405;
  /**
   * 409 Conflict
   *
   * The parameters required by the method call are either missing, malformed,
   * or otherwise rejected.
   */
  const HTTP_CODE_CONFLICT = 409;
  /**
   * 410 Gone
   *
   * The results produced by the deferred result API call have already been
   * retrieved and are no longer stored on the server.
   */
  const HTTP_CODE_DEFERRED_RESULT_GONE = 410;
  /**
   * 500 Internal Server Error
   *
   * The system encountered a fatal error while processing your API call. The
   * body of the response may contain more detailed information as well as a
   * Problem ID that can be used to report the issue to Blue State Digital.
   */
  const HTTP_CODE_INTERNAL_SERVER_ERROR = 500;
  /**
   * 503 Service Unavailable
   *
   * The deferred result API call is still compiling the result.
   */
  const HTTP_CODE_RESULT_COMPILING = 503;
  /**
   * @}
   */

  /**
   * @defgroup BlueStateDigitalApi_REST_METHOD_CODES BlueStateDigitalApi REST
   * Methods
   * @{
   * Available methods for connecting to the API.
   */
  /**
   * Use stream wrappers to access the API.
   */
  const REST_METHOD_STREAM_WRAPPER = 0;
  /**
   * Use the curl library to access the API.
   */
  const REST_METHOD_CURL = 1;
  /**
   * @}
   */

  /**
   * The version of the API to use when making requests.
   */
  const API_VER = 1;

  /**
   * API ID to use when accessing the API.
   *
   * This value can be found in the administrative section of the Blue State
   * Digital web console.
   */
  protected $apiId;
  /**
   * API Secret for the API ID used to access the API.
   *
   * This value can be found in the administrative section of the Blue State
   * Digital web console.
   */
  protected $apiSecret;

  /**
   * The method to use when making API requests.
   *
   * Must be one of the following
   * - BlueStateDigitalApi::REST_METHOD_STREAM_WRAPPER
   * - BlueStateDigitalApi::REST_METHOD_CURL
   */
  protected $restMethod;

  /**
   * The base URL for all API calls to the API server.
   */
  protected $httpRequestBase;
  /**
   * The timeout in seconds for API call requests.
   */
  protected $httpRequestTimeout;

  /**
   * Constructs a base BlueStateDigitalApi instance.
   *
   * Constructs a base BlueStateDigitalApi instance for accessing any of the
   * Blue State Digital APIs.
   *
   * @param string $api_id
   *   API ID to use when making API requests.
   * @param string $api_secret
   *   API Secrect for the API ID, used when making API requests.
   * @param int $rest_method
   *   The method to use when making API requrests.
   *   Must be one of the following
   *   - BlueStateDigitalApi::REST_METHOD_STREAM_WRAPPER
   *   - BlueStateDigitalApi::REST_METHOD_CURL
   * @param string $request_base
   *   The base URL for the API server, defaults to
   *   http://secure.takepart.com/page/api/
   * @param int $request_timeout
   *   The timeout in seconds when making requests to the API Server, defaults
   *   to 10 seconds
   */
  public function __construct($api_id, $api_secret, $rest_method,
    $request_base = 'http://secure.takepart.com/page/api/',
    $request_timeout = 10) {

    // Configuration for accessing the API.
    $this->apiId = $api_id;
    $this->apiSecret = $api_secret;
    $this->restMethod = $rest_method;

    // Configuration for connecting to Blue State Digital.
    if (substr($request_base, -1) != '/') {
      $request_base .= '/';
    }
    $this->httpRequestBase = $request_base;
    $this->httpRequestTimeout = $request_timeout;
  }

  /**
   * Make an API call.
   *
   * @param string $url
   *   String URL relative to the base URL for the API server.
   * @param array $params
   *   (optional) An associative array containing the GET parameters for the
   *   API call, keyed by the parameter name. Defaults to an empty array.
   * @param string $data
   *   (optional) String POST data, defaults to NULL (no POST data).
   *
   * @return array
   *   An associative array containing the following:
   *   - http_code: the HTTP code returned by the API server.
   *   - body: the body of the resposne returned by the API server.
   */
  public function callAPI($url, $params = array(), $data = NULL) {

    // Prepend URL with base path for the API.
    $url = $this->httpRequestBase . $url;

    // Add api_id, timestamp, and version number to query string.
    $params['api_id'] = $this->apiId;
    if (!array_key_exists('api_ts', $params)) {
      $params['api_ts'] = time();
    }
    $params['api_ver'] = self::API_VER;

    // Add api_mac to query string after using existing query and request url
    // to build the api_mac.
    $params['api_mac'] = $this->buildApiMac($url, $params);

    // Add query string to request URL.
    $url .= '?' . http_build_query($params);

    // Send the request.
    if ($this->restMethod == self::REST_METHOD_STREAM_WRAPPER) {
      $response = $this->streamWrapper($url, $data);
    }
    else /* self::REST_METHOD_CURL */ {
      $response = $this->curl($url, $data);
    }

    return $response;
  }

  /**
   * Make a deferred API call.
   *
   * This function adds an explicit check of the HTTP code returned by the API
   * server when making a deferred API call.
   *
   * @param string $url
   *   String URL relative to the base URL for the API server.
   * @param array $params
   *   (optional) An associative array containing the GET parameters for the
   *   API call, keyed by the parameter name. Defaults to an empty array.
   * @param string $data
   *   (optional) String POST data, defaults to NULL (no POST data).
   * @param boolean $block
   *   (optional) Boolean flag for performing deferred API calls as a single
   *   blocking function call, defaults to TRUE.
   *   - TRUE: the call will block until the deferred result is available, or
   *     the maximum number of attempts to retrieve the result has been
   *     exceeded.
   *   - FALSE: the call will NOT block, returning the deferred_id for
   *     retrieving result at some other time.
   *
   * @return array|string
   *   The return value depends on the $block parameter.
   *   - TRUE: An associative array containing:
   *     - http_code: the HTTP code returned by the API server.
   *     - body: the body of the response returned by the API server.
   *   - FALSE: String deferred result ID.
   *
   * @throws BlueStateDigitalApiException
   */
  public function callDeferredAPI($url, $params = array(), $data = NULL,
    $block = TRUE) {

    // Make the request.
    $response = $this->callAPI($url, $params, $data);

    // Immediately retrieve any deferred response if the the call is set to
    // block.
    if ($block && $response['http_code'] == self::HTTP_CODE_DEFERRED_RESULT) {
      $response = $this->waitForDeferredResult($response['body']);
    }

    if (!$block) {
      // Check the response code.
      if ($response['http_code'] != self::HTTP_CODE_DEFERRED_RESULT) {
        throw new BlueStateDigitalApiException(
          'Failed to receive deferred result id.',
          BlueStateDigitalApiException::FAILED_RESPONSE_CODE,
          $response['http_code'], $response['body']);
      }
      // Return the deferred result id.
      return $response['body'];
    }

    // Return the response.
    return $response;
  }

  /**
   * Retrieve a deferred result from the API server.
   *
   * @param string $deferred_id
   *   The deferred_id returned by the initial call to the API server.
   *
   * @return array|boolean
   *   An associative array containing the following:
   *   - http_code: the HTTP code returned by the API server.
   *   - body: the body of the resposne returned by the API server.
   *   Or FALSE if the result is still being compiled.
   *
   * @throws BlueStateDigitalApiException
   */
  public function getDeferredResult($deferred_id) {

    // Attempt to get the result.
    $response = $this->callAPI('get_deferred_results',
      array('deferred_id' => $deferred_id));

    if ($response['http_code'] == self::HTTP_CODE_RESULT_COMPILING) {
      // The deferred result is still being calculated.
      return FALSE;
    }

    // Return the response.
    return $response;
  }

  /**
   * Wait for a deferred result from the API server.
   *
   * @param string $deferred_id
   *   The deferred_id returned by the initial call to the API server.
   * @param int $wait_interval
   *   (optional) The delay in seconds before each attempt to retrieve the
   *   deferred result. Defaults to 5 seconds.
   * @param int $max_attempts
   *   (optional) The maximum number of attempts to retrieve the deferred
   *   result. Defaults to 3 attempts.
   *
   * @return array
   *   An associative array containing the following:
   *   - http_code: the HTTP code returned by the API server.
   *   - body: the body of the resposne returned by the API server.
   *
   * @throws BlueStateDigitalApiException
   */
  protected function waitForDeferredResult($deferred_id, $wait_interval = 5,
    $max_attempts = 3) {

    $attempt = 0;

    // Loop until result is ready or until we give up.
    do {
      // Delay between calls (in seconds).
      sleep($wait_interval);

      // Check to see if result is ready.
      $response = $this->callAPI('get_deferred_results',
        array('deferred_id' => $deferred_id));

      // Increment attempt counter.
      $attempt++;

    } while ($response['http_code'] == self::HTTP_CODE_RESULT_COMPILING
      && $attempt < $max_attempts);

    // Check if the result is still compiling.
    if ($response['http_code'] == self::HTTP_CODE_RESULT_COMPILING) {
      $message
        = sprintf('Unable to retrieve deferred result after %d attempt(s).',
          $attempt);
      throw new BlueStateDigitalApiException($message,
        BlueStateDigitalApiException::REQUEST_ERROR);
    }

    // Return the deferred result.
    return $response;
  }

  /**
   * Calculate the api_mac.
   *
   * Calculate the api_mac used by the API server to verify the source of all
   * API calls.
   *
   * @param string $url
   *   The URL of the API call w/o any GET parameters.
   * @param array $query
   *   The GET parameters of the API call. This MUST contain at least the
   *   following:
   *   - api_id: The API ID created in the Blue State Diginal web console.
   *   - api_ts: The time of the request as a UNIX timestamp (epoch seconds).
   *   - api_ver: The integer version of the API.
   *
   * @return string
   *   The Base64 encoded api_mac as a string.
   */
  protected function buildApiMac($url, $query) {

    // Break URL into parts to get the path.
    $url_parts = parse_url($url);

    // Build query string from given parameters.
    $query_string = urldecode(http_build_query($query));

    // Combine strings to build the signing string.
    $signing_string = $query['api_id'] . "\n" .
      $query['api_ts'] . "\n" .
      $url_parts['path'] . "\n" .
      $query_string;

    // Encode and return the signing string.
    return base64_encode(hash_hmac('sha1', $signing_string, $this->apiSecret,
      TRUE));
  }

  /**
   * Make a call to the API server using stream wrappers.
   *
   * The method used to make the API call (GET or POST) is determined by the
   * presence of POST data to be sent to the API server. If there is a value
   * in the $data parameter the POST method is used, otherwise the GET method
   * is used.
   *
   * @param string $url
   *   The string URL of the API call
   * @param string $data
   *   (optional) String data to be posted to the API call. Defaults to NULL
   *   (no POST data).
   *
   * @return array
   *   An associative array containing the following:
   *   - http_code: the HTTP code returned by the API server.
   *   - body: the body of the resposne returned by the API server.
   *
   * @throws
   *   BlueStateDigitalApiException
   */
  protected function streamWrapper($url, $data = NULL) {

    // Build the request context.
    if (!empty($data)) {
      $params = array(
        'http' => array(
          'method' => 'POST',
          'content' => $data,
        ),
      );
    }
    else {
      $params = array(
        'http' => array(
          'method' => 'GET',
        ),
      );
    }
    $ctx = stream_context_create($params);

    // Make the request.
    try {
      $response = NULL;
      $fp = @fopen($url, 'rb', FALSE, $ctx);
      if ($fp !== FALSE) {
        $response = @stream_get_contents($fp);
        @fclose($fp);
      }
    }
    catch (Exception $ex) {
      // Re-throw the exception wrapped in a BlueStateDigitalApiException.
      $message = sprintf('Request exception. REST method = %d.',
        $this->restMethod);
      throw new BlueStateDigitalApiException($message,
        BlueStateDigitalApiException::REQUEST_ERROR, NULL, NULL, $ex);
    }

    if (empty($http_response_header)) {
      $message = sprintf('Response headers not available. REST method = %d.',
        $this->restMethod);
      throw new BlueStateDigitalApiException($message,
        BlueStateDigitalApiException::REQUEST_ERROR);
    }

    // Get the response code from the header variable.
    $status = explode(' ', $http_response_header[0]);
    $status = array_map('trim', $status);
    $status = array_filter($status, 'strlen');

    // Return the response http code and body.
    return array(
      'http_code' => $status[1],
      'body' => $response,
    );
  }

  /**
   * Make a call to the API server using the curl library.
   *
   * The method used to make the API call (GET or POST) is determined by the
   * presence of POST data to be sent to the API server. If there is a value
   * in the $data parameter the POST method is used, otherwise the GET method
   * is used.
   *
   * @param string $url
   *   The string URL of the API call
   * @param string $data
   *   (optional) String data to be posted to the API call. Defaults to NULL
   *   (no POST data).
   *
   * @return array
   *   An associative array containing the following:
   *   - http_code: the HTTP code returned by the API server.
   *   - body: the body of the resposne returned by the API server.
   *
   * @throws
   *   BlueStateDigitalApiException
   */
  protected function curl($url, $data = NULL) {

    $ch = curl_init();
    curl_setopt($ch, CURLOPT_URL, $url);
    curl_setopt($ch, CURLOPT_TIMEOUT, $this->httpRequestTimeout);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, TRUE);

    // Include the header in result.
    curl_setopt($ch, CURLOPT_HEADER, 1);

    // Add in the post data.
    if (!empty($data)) {
      curl_setopt($ch, CURLOPT_POST, 1);
      curl_setopt($ch, CURLOPT_POSTFIELDS, $data);
    }

    // Make the request.
    try {
      $response = curl_exec($ch);
      $http_code = curl_getinfo($ch, CURLINFO_HTTP_CODE);
    }
    catch (Exception $ex) {
      @curl_close($ch);
      // Re-throw the exception wrapped in a BlueStateDigitalApiException.
      $message = sprintf('Request exception. REST method = %d.',
        $this->restMethod);
      throw new BlueStateDigitalApiException($message,
        BlueStateDigitalApiException::REQUEST_ERROR, NULL, NULL, $ex);
    }

    // Extract the response body.
    $header_length = curl_getinfo($ch, CURLINFO_HEADER_SIZE);
    $body = trim(substr($response, $header_length));

    @curl_close($ch);

    // Return the response http code and body.
    return array(
      'http_code' => $http_code,
      'body' => $body,
    );
  }

  /**
   * Convert timestamps to a single standard format.
   *
   * This funtion converts timestamps to UNIX time (seconds since epoch.)
   *
   * @param string $timestamp
   *   The timestamp to be converted.
   *
   * @return int
   *   Integer UNIX time (seconds since epoch.)
   */
  protected function convertTimestamp($timestamp) {
    // If the timestamp is not already in UNIX time, convert it to UNIX time.
    if (!preg_match('/^[0-9]+$/', $timestamp)) {
      $tz = date_default_timezone_get();
      date_default_timezone_set('UTC');
      $unixtime = strtotime($timestamp);
      date_default_timezone_set($tz);
      return $unixtime;
    }
    return (int) $timestamp;
  }

  /**
   * Check if a response returned no content.
   *
   * This function is a common response parser for deferred result API calls
   * that do not return only a status code and no data.
   *
   * @param array $response
   *   An associative array containing:
   *   - http_code: Integer HTTP code of the response.
   *   - body: String body of the the response.
   *
   * @throws BlueStateDigitalApiException
   */
  protected function checkNoContentResponse($response,
    $code = self::HTTP_CODE_NO_CONTENT) {

    // Check the response code.
    if ($response['http_code'] != $code) {
      throw new BlueStateDigitalApiException(
        'Unexpected response content.',
        BlueStateDigitalApiException::FAILED_RESPONSE_CODE,
        $response['http_code'], $response['body']);
    }
  }
}
