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

  public function submit($signup) {
    if (get_class($signup) === 'NewsletterCampaignSignup') {
      if (isset($signup['email'])) {
        $added_or_updated = BlueHornet::Api()->addUpdateSubscriber($signup['email'],
          $this->configuration['segments'], $this->configuration['fields']);
        if (!$added_or_updated) {
          $message = t('Error sending email signup [@email]', array(
            '@email' => $signup['email'],
          ));
          throw new SignupHandlerException($message);
        }
      }
    }
  }
}
