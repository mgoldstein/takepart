<?php

/**
 * Participant Media API class
 */
class ParticipantAPI {

  /**
   * __construct takes in the domain and apikey
   * @param $api_domain
   * @param $api_key
   */
  function __construct($api_domain, $api_key) {
    $this->apiKey = $api_key;
    $this->apiURL = "https://$api_domain/api/v1/esp/lists";
    $this->responseType = 'json';
  }

  /**
   * sendToServer It is a CURL call to the domain
   * @param array $data
   * @return array $response
   */
  private function sendToServer($data) {
    //Make the data JSON
    $vars = json_encode($data);

    $result = file_get_contents($this->apiURL, null, stream_context_create(array(
    'http' => array(
    'method' => 'POST',
    'header' => 'Content-Type: application/json' . "\r\n"
    . 'Accept: application/json' . "\r\n"
    . 'Content-Length: ' . strlen($vars) . "\r\n",
    'content' => $vars,
    ),
    )));

    return json_decode($result);
  }

  /**
   * addUpdateSubscriber the public call to this api class
   * @param array $data
   * @return string $response[0]['responseData']
   */
  public function addUpdateSubscriber($data) {

    $data['api_key'] = $this->apiKey;

    $response = $this->sendToServer($data);

    return $response;
  }
}
