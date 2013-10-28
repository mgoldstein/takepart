<?php
/**
 * Sigunup handler plugin for BlueStateDigital module.
 */

$plugin = array(
  'handler' => array(
    'class' => 'BlueHornetSignupHandler',
  ),
);

class BlueHornetSignupHandler {

  protected $plugin;
  protected $configuration;

  public function __construct($plugin, $configuration) {
    $this->plugin = $plugin;
    $this->configuration = $configuration;
  }

  public function getLabel() {
    return t('Blue Hornet');
  }

  public static function validateConfiguration($type, $configuration) {
    return array();
  }

  protected function submitNewsletterCampaignSignup($signup) {

    if (isset($signup['email'])) {

      $data = array('email' => $signup['email']);

      $account = isset($this->configuration['account'])
        ? $this->configuration['account'] : NULL;

      $response = BlueHornet::Api($account)->addUpdateSubscriber($data,
        $this->configuration['segments'], $this->configuration['fields'],
        $this->configuration['send-welcome']);

      $added_or_updated = $response['status'] == 1 || $response['status'] == 2;
      if (!$added_or_updated) {
        $message = t('Error sending email signup [@email] @response', array(
          '@email' => $signup['email'],
          '@response' => print_r($response, TRUE),
        ));
        throw new SignupHandlerException($message);
      }
    }
  }

  protected function submitSignatureSignup($signup) {

    $have_at_least_one_opt_in = FALSE;
    $segments = array();
    $fields = array();
    $send_welcome = TRUE;

    $opt_ins = explode(',', $signup['action.opt-ins.newsletters']);
    foreach ($this->configuration['opt-ins'] as $index => $opt_in_config) {
      if (!empty($opt_in_config)) {
        if (isset($opt_ins[$index]) && $opt_ins[$index] === 'true') {
          // We have an opt-in
          $have_at_least_one_opt_in = TRUE;
          // Merge it into the call data.
          $segments += $opt_in_config['segments'];
          $fields += $opt_in_config['fields'];
          if ($opt_in_config['send-welcome']) {
            $send_welcome = TRUE;
          }
        }
      }
    }

    if ($have_at_least_one_opt_in) {

      $data = array('email' => $signup['email']);

      $account = isset($this->configuration['account'])
        ? $this->configuration['account'] : NULL;

      $response = BlueHornet::Api($account)->addUpdateSubscriber($data,
        $segments, $fields, $send_welcome);

      $added_or_updated = $response['status'] == 1 || $response['status'] == 2;
      if (!$added_or_updated) {
        $message = t('Error sending email signup [@email] @response', array(
          '@email' => $signup['email'],
          '@response' => print_r($response, TRUE),
        ));
        throw new SignupHandlerException($message);
      }
    }
  }

  protected function submitTakePartUserSignup($signup) {

    $data = array('email' => $signup['email']);
    if (isset($signup['address.postal-code'])) {
      $data['postal_code'] = $signup['address.postal-code'];
    }

    $account = isset($this->configuration['account'])
      ? $this->configuration['account'] : NULL;

    $response = BlueHornet::Api($account)->addUpdateSubscriber($data,
      $this->configuration['segments'], $this->configuration['fields'],
      $this->configuration['send-welcome']);

    $added_or_updated = $response['status'] == 1 || $response['status'] == 2;
    if (!$added_or_updated) {
      $message = t('Error sending email signup [@email] @response', array(
        '@email' => $signup['email'],
        '@response' => print_r($response, TRUE),
      ));
      throw new SignupHandlerException($message);
    }
  }

  public function submit($signup) {
    $signup_type = get_class($signup);
    if ($signup_type === 'NewsletterCampaignSignup') {
      $this->submitNewsletterCampaignSignup($signup);
    }
    elseif ($signup_type === 'SignatureSignup') {
      $this->submitSignatureSignup($signup);
    }
    elseif ($signup_type === 'TakePartUserSignup') {
      $this->submitTakePartUserSignup($signup);
    }
  }
}
