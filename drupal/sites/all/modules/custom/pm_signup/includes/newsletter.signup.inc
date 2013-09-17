<?php

class NewsletterCampaignSignup extends Signup {

  public static function fields() {

    // No specific email or phone number field is required, validation will
    // check that something was provided.
    return array(
      'email' => array(
        'required' => FALSE,
        'default' => '',
      ),
      'phone-number' => array(
        'required' => FALSE,
        'default' => '',
      ),
      'phone-number.area-code' => array(
        'required' => FALSE,
        'default' => '',
      ),
      'phone-number.exchange' => array(
        'required' => FALSE,
        'default' => '',
      ),
      'phone-number.number' => array(
        'required' => FALSE,
        'default' => '',
      ),
    );
  }

  public function validate() {

    // Do the standard validation.
    parent::validate();

    // Check if the email or a phone number is set
    if (!isset($this['email']) && $this->getSanitizedPhoneNumber() === FALSE) {
      throw new SignupValidationException(array('an email or phone number is required'));
    }
  }
}


class NewsletterCampaignSignupEndpoint extends SignupEndpoint {

  public static function namedEnpoints() {
    return db_select('pm_signup_endpoint', 'ep')
      ->fields('ep', array('name', 'label'))
      ->condition('type', 'NewsletterCampaignSignupEndpoint')
      ->isNotNull('name')
      ->execute()
      ->fetchAllKeyed();
  }

  public static function fields() {

    // No specific email or phone number field is required, validation will
    // check that something was provided.
    return array(
      'email' => array(
        'required' => FALSE,
        'default' => '',
      ),
      'phone-number' => array(
        'required' => FALSE,
        'default' => '',
      ),
      'phone-number.area-code' => array(
        'required' => FALSE,
        'default' => '',
      ),
      'phone-number.exchange' => array(
        'required' => FALSE,
        'default' => '',
      ),
      'phone-number.number' => array(
        'required' => FALSE,
        'default' => '',
      ),
    );
  }

  protected function validate($signup) {

    // Do the standard validation.
    parent::validate($signup);

    // Check if the email or a phone number is set
    if (!isset($signup['email']) && $signup->getSanitizedPhoneNumber() === FALSE) {
      throw new SignupValidationException(array('an email or phone number is required'));
    }
  }
}