<?php

include_once dirname(__FILE__) . '/bluehornet.lib.inc';

/**
 * BlueHornet API Wrapper
 */
class BlueHornet {

  public static function Api($account = NULL) {
    static $instance = NULL;
    if ($instance === NULL) {
      if ($account === NULL) {
        $account = variable_get('bluehornet_default_account', '');
      }
      $api_accounts = variable_get('bluehornet_api_accounts', NULL);
      $api_domain = $api_key = $shared_secret = '';
      if (isset($api_accounts) && isset($api_accounts[$account])) {
        $api_domain = $api_accounts[$account]['domain'];
        $api_key = $api_accounts[$account]['key'];
        $shared_secret = $api_accounts[$account]['secret'];
      }
      $instance = new BlueHornet($api_domain, $api_key, $shared_secret);
    }
    return $instance;
  }

  private $core;

  private function __construct($api_domain, $api_key, $shared_secret) {
    $auth = array(
      'apiKey' => $api_key,
      'sharedSecret' => $shared_secret,
      'apiDomain' => $api_domain,
    );
    $this->core = new BF_Esp_Bluehornet($auth);
  }

  public function addUpdateSubscriber($data, $segments, $custom_fields,
    $send_welcome) {

    // Include the segments to which the user should be added (if any).
    if (count($segments) > 0) {
      $data['grp'] = implode(',', $segments);
    }

    // Add any custom field values.
    foreach($custom_fields as $number => $value) {
      $data["custval{$number}"] = $value;
    }

    if ($send_welcome) {
      $data['welcomeletter'] = '1';
    }

    if (variable_get('pm_signup_log', FALSE)) {
      db_insert('pm_signup_log')
        ->fields(array(
          'handler' => 'bluehornet.api.inc',
          'message' => 'api request',
          'exception' => print_r($data, true),
          'backtrace' => '',
          'created' => REQUEST_TIME,
        ))
        ->execute();
    }

    // Add or update the subscriber.
    $response = $this->core->addUpdateSubscriber($data);

    return $response;
  }
}
