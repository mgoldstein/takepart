<?php
/**
 * Sigunup handler plugin for BlueStateDigital module.
 */

$plugin = array(
  'handler' => array(
    'class' => 'BlueStateDigitalSignupHandler',
  ),
);

class BlueStateDigitalSignupHandler {

  protected $plugin;
  protected $configuration;

  public function __construct($plugin, $configuration) {
    $this->plugin = $plugin;
    $this->configuration = (array) $configuration;
  }

  public function getLabel() {
    return t('Blue State Digital');
  }

  public static function validateConfiguration($type, $configuration) {
    return array();
  }

  protected function sendSignupToServer($signup){
    try {
      $api = bluestatedigital_get_api('signup');
      $api->processSignup($signup);
    }
    catch (BlueStateDigitalApiException $ex) {
      $message = t('Error sending email signup [@code] @body', array(
        '@code' => $ex->getResponseCode(),
        '@body' => $ex->getResponseBody(),
      ));
      throw new SignupHandlerException($message);
    }
  }

  protected function submitNewsletterCampaignSignup($signup) {

    $fields = array();

    if (isset($this->configuration['email-field-id'])) {
      $email_field_id = $this->configuration['email-field-id'];
      $fields[$email_field_id]['value'] = array(
        'type' => 'value',
        'value' => $signup['email'],
      );
    }

    if (isset($this->configuration['phone-field-id'])) {
      $phone_field_id = $this->configuration['phone-field-id'];
      $fields[$phone_field_id]['value'] = array(
        'type' => 'value',
        'value' => $signup->getPhoneNumber(),
      );
    }

    $form_id = $this->configuration['form-id'];
    $bsd_signup = array($form_id => $fields);
    $this->sendSignupToServer($bsd_signup);
  }

  protected function submitSignatureSignup($signup) {

    $fields = array();
    foreach ($this->configuration['field-ids'] as $name => $id) {
      $fields[$id] = array(
        'value' => array(
          'type' => 'value',
          'value' => $signup[$name],
        ),
      );
    }

    $opt_ins = $signup['action.opt-ins.newsletters'];
    foreach ($opt_ins as $name => $opt_in) {
      if ($opt_in->getPluginEnabled('bluestatedigital.pm_signup.handler')) {
        $opt_in_field_ids = $this->configuration['opt-ins']['field-ids'];
        if (isset($opt_in_field_ids[$name])) {
          $id = $opt_in_field_ids[$name];
          $fields[$id] = array(
            'value' => array(
              'type' => 'value',
              'value' => '1',
            ),
          );
        }
      }
    }

    $form_id = $this->configuration['form-id'];
    $bsd_signup = array($form_id => $fields);
    $this->sendSignupToServer($bsd_signup);
  }

  protected function submitTakePartUserSignup($signup) {

    $fields = array();

    $email_field_id = $this->configuration['email-field-id'];
    $fields[$email_field_id]['value'] = array(
      'type' => 'value',
      'value' => $signup['email'],
    );

    $form_id = $this->configuration['form-id'];
    $bsd_signup = array($form_id => $fields);
    $this->sendSignupToServer($bsd_signup);
  }

  protected function submitFoodIncAwardsSignup($signup) {

    $fields = array();
    foreach ($this->configuration['field-ids'] as $name => $id) {
      $fields[$id] = array(
        'value' => array(
          'type' => 'value',
          'value' => $signup[$name],
        ),
      );
    }

    $form_id = $this->configuration['form-id'];
    $bsd_signup = array($form_id => $fields);
    $this->sendSignupToServer($bsd_signup);
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
    elseif ($signup_type === 'FoodIncAwardsSignup') {
      $this->submitFoodIncAwardsSignup($signup);
    }
  }
}
