<?php
/**
 * Sigunup handler plugin for Waterfall module.
 */

include_once dirname(__FILE__) . '/../includes/waterfallapi.inc';

$plugin = array(
  'handler' => array(
    'class' => 'WaterfalllSignupHandler',
  ),
);

class WaterfalllSignupHandler {

  protected $plugin;
  protected $configuration;

  public function __construct($plugin, $configuration) {
    $this->plugin = $plugin;
    $this->configuration = $configuration;
  }

  protected function submitNewsletterCampaignSignup($signup) {

    $phone = $signup->getPhoneNumber('');
    if (!empty($phone)) {

      $area_code = $signup->getAreaCode();
      $is_canadian = PhoneCampaigns::IsCanadianAreaCode($area_code);

      if ($is_canadian && isset($this->configuration['canada-flow-id'])) {
        Waterfall::Api()->post('authenticate', array(
          'username' => 'TakePart',
          'password' => 'sms4takepart',
        ));
        PhoneCampaigns::Canada()->initiateFlow(
          $this->configuration['canada-flow-id'], $phone);
        Waterfall::Api()->post('authenticate/logout');
      }
      elseif (isset($this->configuration['us-flow-id'])) {
        Waterfall::Api()->post('authenticate', array(
          'username' => 'TakePart',
          'password' => 'sms4takepart',
        ));
        PhoneCampaigns::US()->initiateFlow($this->configuration['us-flow-id'],
          $phone);
        Waterfall::Api()->post('authenticate/logout');
      }
    }
  }

  public function submit($signup) {
    if (get_class($signup) === 'NewsletterCampaignSignup') {
      $this->submitNewsletterCampaignSignup($signup);
    }
  }
}
