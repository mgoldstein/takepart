<?php
/**
 * @file
 * TakeAction Button API.
 */

/**
 * Common exception for all TakeAction Button APIs.
 */
class TakeActionApiException extends Exception {

  /**
   * @defgroup TakeActionApiExcpetionCodes TakeActionApiException
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
   * Constructs a TakeActionApiException.
   *
   * @param string $message
   *   String description of the exception.
   * @param int $code
   *   Integer exception code describing the information available in the
   *   exception, one of the following constants:
   *   - TakeActionApiException::REQUEST_ERROR
   *   - TakeActionApiException::FAILED_RESPONSE_CODE
   *   - TakeActionApiException::INVALID_RESPONSE_BODY
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
 * TakeAction Core API.
 */
class TakeActionApi {

  /**
   * @defgroup TakeActionApi_HTTP_CODES TakeActionApi HTTP Codes
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
   * @defgroup TakeActionApi_REST_METHOD_CODES TakeActionApi REST
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
   * API key to use when accessing the API.
   *
   * This value can be found in the Drupal Take Action Button configuration
   * section.
   */
  protected $apiKey;

  /**
   * The method to use when making API requests.
   *
   * Must be one of the following
   * - TakeActionApi::REST_METHOD_STREAM_WRAPPER
   * - TakeActionApi::REST_METHOD_CURL
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
   * Constructs a base TakeActionApi instance.
   *
   * Constructs a base TakeActionApi instance for accessing the TakeAction API.
   *
   * @param string $api_key
   *   API key to use when making API requests.
   * @param int $rest_method
   *   The method to use when making API requrests.
   *   Must be one of the following
   *   - TakeActionApi::REST_METHOD_STREAM_WRAPPER
   *   - TakeActionApi::REST_METHOD_CURL
   * @param string $request_base
   *   The base URL for the API server, defaults to
   *   http://tabcode.dev.takepart.com/api/
   * @param int $request_timeout
   *   The timeout in seconds when making requests to the API server, defaults
   *   to 10 seconds
   */
  public function __construct($api_key, $rest_method,
    $request_base = 'http://tabcode.dev.takepart.com/api/',
    $request_timeout = 10) {

    // Configuration for accessing the API.
    $this->apiKey = $api_key;
    $this->restMethod = $rest_method;

    // Configuration for connecting to the TakeAction Button API server.
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
  public function callAPI($url, $params = array(), $data = NULL, $put = FALSE) {

    // Prepend URL with base path for the API.
    $url = $this->httpRequestBase . $url;

    // Add query string to request URL.
    if (!empty($params)) {
      $url .= '?' . http_build_query($params);
    }

    // Send the request.
    if ($this->restMethod == self::REST_METHOD_STREAM_WRAPPER) {
      $response = $this->streamWrapper($url, $data, $put);
    }
    else /* self::REST_METHOD_CURL */ {
      $response = $this->curl($url, $data, $put);
    }

    return $response;
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
   *   TakeActionApiException
   */
  protected function streamWrapper($url, $data = NULL, $put = FALSE) {

    $header = "Authorization: Token token=\"{$this->apiKey}\"\r\n";

    // Build the request context.
    if (!empty($data)) {
      $json = drupal_json_encode($data);
      $params = array(
        'http' => array(
          'method' => $put ? 'PUT' : 'POST',
          'header' => $header,
          'content' => $json,
        ),
      );
    }
    else {
      $params = array(
        'http' => array(
          'method' => 'GET',
          'header' => $header,
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
      // Re-throw the exception wrapped in a TakeActionApiException.
      $message = sprintf('Request exception. REST method = %d.',
        $this->restMethod);
      throw new TakeActionApiException($message,
        TakeActionApiException::REQUEST_ERROR, NULL, NULL, $ex);
    }

    if (empty($http_response_header)) {
      $message = sprintf('Response headers not available. REST method = %d.',
        $this->restMethod);
      throw new TakeActionApiException($message,
        TakeActionApiException::REQUEST_ERROR);
    }

    // Get the response code from the header variable.
    $chunks = explode(' ', $http_response_header[0]);
    $tokens = array_map('trim', $chunks);
    $status = array_filter($tokens, 'strlen');

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
   *   TakeActionApiException
   */
  protected function curl($url, $data = NULL, $put = FALSE) {

    $ch = curl_init();
    curl_setopt($ch, CURLOPT_URL, $url);
    curl_setopt($ch, CURLOPT_TIMEOUT, $this->httpRequestTimeout);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, TRUE);
    if (!empty($data) && $put) {
      curl_setopt($ch, CURLOPT_HTTPHEADER, array(
        "Content-Type: application/json",
        "Authorization: Token token=\"{$this->apiKey}\"",
        "X-HTTP-Method-Override: PUT",
      ));
    }
    else {
      curl_setopt($ch, CURLOPT_HTTPHEADER, array(
        "Content-Type: application/json",
        "Authorization: Token token=\"{$this->apiKey}\"",
      ));
    }

    // Include the header in result.
    curl_setopt($ch, CURLOPT_HEADER, 1);

    // Add in the post data.
    if (!empty($data)) {
      $json = drupal_json_encode($data);
      if (!$put) { curl_setopt($ch, CURLOPT_POST, 1); }
      curl_setopt($ch, CURLOPT_POSTFIELDS, $json);
    }

    // Make the request.
    try {
      $response = curl_exec($ch);
      $http_code = curl_getinfo($ch, CURLINFO_HTTP_CODE);
    }
    catch (Exception $ex) {
      @curl_close($ch);
      // Re-throw the exception wrapped in a TakeActionApiException.
      $message = sprintf('Request exception. REST method = %d.',
        $this->restMethod);
      throw new TakeActionApiException($message,
        TakeActionApiException::REQUEST_ERROR, NULL, NULL, $ex);
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
   * Report a user action to the TakeAction Button system.
   *
   * @param string $guid
   *   The guid of the user that took the action.
   * @param int $nid
   *   The id of the action taken.
   * @param float $transacted_amount
   *   The options amount of the action transaction, for contributions only.
   */
  public function addUserAction($guid, $nid, $transacted_amount = NULL) {
    $data = array(
      'user_id' => $guid,
      'action_id' => (int) $nid,
    );
    if (isset($transacted_amount)) {
      $data['transacted_amount'] = $transacted_amount;
    }
    $response = $this->callAPI('user_actions', array(), $data);
    if ($response['http_code'] != self::HTTP_CODE_OK) {
      throw new TakeActionApiException(
        'Unexpected response status code.',
        TakeActionApiException::FAILED_RESPONSE_CODE,
        $response['http_code'], $response['body']);
    }
  }

  /**
   * Reassign tracking events from one user to another.
   *
   * @param string $src
   *   The guid of the source user.
   * @param string $dest
   *   The guid of the destination user.
   */
  public function reassignTrackingEvents($src, $dest) {
    $data = array(
      'old_user_id' => $src,
      'new_user_id' => $dest,
    );
    $response = $this->callAPI('user_actions/reassign', array(), $data, TRUE);
    if ($response['http_code'] != self::HTTP_CODE_OK) {
      throw new TakeActionApiException(
        'Unexpected response status code.',
        TakeActionApiException::FAILED_RESPONSE_CODE,
        $response['http_code'], $response['body']);
    }
  }
  
  public function actionInfo($action_id) {
    $response = $this->callAPI("actions/{$action_id}");
    if ($response['http_code'] != self::HTTP_CODE_OK) {
      throw new TakeActionApiException(
        'Unexpected response status code.',
        TakeActionApiException::FAILED_RESPONSE_CODE,
        $response['http_code'], $response['body']);
    }
    return json_decode($response['body']);
  }
}
