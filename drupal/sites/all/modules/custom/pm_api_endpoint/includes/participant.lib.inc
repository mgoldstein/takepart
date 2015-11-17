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
    $this->apiURL = "https://$api_domain/v1/esp/list";
    $this->responseType = 'json';
  }

  /**
   * sendToServer It is a CURL call to the domain
   * @param array $data
   * @return array $response
   */
  private function sendToServer($data) {
    //Make the data JSON
    $vars = 'post='.json_encode($data);

    //Submit call via CURL
    $ch = curl_init();
    curl_setopt($ch, CURLOPT_URL, $this->apiURL);
    curl_setopt($ch, CURLOPT_POST, true);
    curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false);
    curl_setopt($ch, CURLOPT_POSTFIELDS, $vars);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);

    //$output = curl_exec($ch);

    $this->error = curl_error($ch);

    curl_close($ch);

    $response = $output;

    return $response;
  }

  /**
   * addUpdateSubscriber the public call to this api class
   * @param array $data
   * @return string $response[0]['responseData']
   */
  public function addUpdateSubscriber($data) {

    $data['api_key'] = $this->apiKey;

    $response = $this->sendToServer($data);

    return $response[0]['responseData'];
  }
}
