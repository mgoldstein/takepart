<?php

/**
 * Sigunup handler plugin for BlueHornet module.
 */
$plugin = array(
  'handler' => array(
    'class' => 'ParticipantSignupHandler',
  ),
);

class ParticipantSignupHandler {

  protected $plugin;
  protected $configuration;

  public function __construct($plugin, $configuration) {
    $this->plugin = $plugin;
    $this->configuration = (array) $configuration;
  }

  public function getLabel() {
    return t('Participant API');
  }

  public static function validateConfiguration($type, $configuration) {
    return array();
  }

  protected function submitNewsletterCampaignSignup($signup) {

    if (isset($signup['email'])) {

	 $data = array('email' => $signup['email']);

	 $account = isset($this->configuration['account']) ? $this->configuration['account'] : NULL;

   //loop through the configuration setting all the variables to send on through
   foreach($this->configuration AS $k => $conf) {
     //account does not need to be sent
     if($k != 'account') {
       $data[$k] = $conf;
     }
   }

	 $response = ParticipantAPIWrapper::Api($account)->addUpdateSubscriber($data);

	 //Need to check for a type of response
	 if (!is_array($response)) {
	   $message = t('Error sending email signup [@email] @response', array(
		'@email' => $signup['email'],
		'@response' => print_r($response, TRUE),
	   ));
	   throw new SignupHandlerException($message);
	 }
    }
  }

  public function submit($signup) {
    $signup_type = get_class($signup);
    if ($signup_type === 'NewsletterCampaignSignup') {
	 $this->submitNewsletterCampaignSignup($signup);
    }
  }

}
