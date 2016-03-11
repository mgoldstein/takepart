<?php

include_once dirname(__FILE__) . '/participant.lib.inc';

/**
 * Participant API Wrapper (Singleton)
 */
class ParticipantAPIWrapper {

  private $lib;

  public static function Api($account = NULL) {
    static $instance = NULL;
    if ($instance === NULL) {
	 if ($account === NULL) {
	   $account = variable_get('participant_api_default_account', '');
	 }
	 $api_accounts = variable_get('participant_api_accounts', NULL);
	 $api_domain = $api_key = '';
	 if (isset($api_accounts) && isset($api_accounts[$account])) {
	   $api_domain = $api_accounts[$account]['domain'];
	   $api_key = $api_accounts[$account]['key'];
	 }
	 $instance = new ParticipantAPIWrapper($api_domain, $api_key);
    }
    return $instance;
  }

  private function __construct($api_domain, $api_key) {
    $this->lib = new ParticipantAPI($api_domain, $api_key);
  }

  public function addUpdateSubscriber($data) {

    if (variable_get('pm_signup_log', FALSE)) {
	 db_insert('pm_signup_log')
	   ->fields(array(
		'handler' => 'participant.api.inc',
		'message' => 'api request',
		'exception' => print_r($data, true),
		'backtrace' => '',
		'created' => REQUEST_TIME,
	   ))
	   ->execute();
    }

    $response = $this->lib->addUpdateSubscriber($data);

    return $response;
  }

}
