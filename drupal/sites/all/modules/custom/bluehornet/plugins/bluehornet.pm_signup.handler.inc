<?php
/**
 * Sigunup handler plugin for BlueHornet module.
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
    $this->configuration = (array) $configuration;
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

    $opt_ins = $signup['action.opt-ins.newsletters'];
    foreach ($opt_ins as $opt_in) {
      if ($opt_in->getPluginEnabled('bluehornet.pm_signup.handler')) {
        $configuration = (array) $opt_in->getPluginConfiguration(
          'bluehornet.pm_signup.handler');

        $account = isset($configuration['account'])
          ? $configuration['account'] : NULL;

        $data = array('email' => $signup['email']);
        $response = BlueHornet::Api($account)->addUpdateSubscriber($data,
          $configuration['segments'], $configuration['fields'],
          $configuration['send-welcome']);

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
