<?php

class SignatureSignup extends Signup {

  public static function fields() {

    // No specific email or phone number field is required, validation will
    // check that something was provided.
    return array(
	 'email' => array(
	   'required' => TRUE,
	   'default' => '',
	 ),
	 'name.first' => array(
	   'required' => FALSE,
	   'default' => '',
	 ),
	 'name.last' => array(
	   'required' => FALSE,
	   'default' => '',
	 ),
	 'address.address' => array(
	   'required' => FALSE,
	   'default' => '',
	 ),
	 'address.city' => array(
	   'required' => FALSE,
	   'default' => '',
	 ),
	 'address.state.code' => array(
	   'required' => FALSE,
	   'default' => '',
	 ),
	 'address.country' => array(
	   'required' => FALSE,
	   'default' => '',
	 ),
	 'address.postal-code' => array(
	   'required' => FALSE,
	   'default' => '',
	 ),
	 'address.postal-code.type' => array(
	   'required' => FALSE,
	   'default' => '',
	 ),
	 'partner.code' => array(
	   'required' => FALSE,
	   'default' => '',
	 ),
	 'action.id' => array(
	   'required' => TRUE,
	   'default' => '',
	 ),
	 'action.signature-type' => array(
	   'required' => FALSE,
	   'default' => '',
	 ),
	 'action.message' => array(
	   'required' => FALSE,
	   'default' => '',
	 ),
	 'action.opt-ins.display' => array(
	   'required' => FALSE,
	   'default' => '',
	 ),
	 'action.opt-ins.newsletters' => array(
	   'required' => FALSE,
	   'default' => '',
	 ),
	 'action.opt-ins.partner' => array(
	   'required' => FALSE,
	   'default' => '',
	 ),
    );
  }

  public function validate() {

    // Do the standard validation.
    parent::validate();

    // Check that the partner opt-ins also have a partner code
    if (isset($this['action.opt-ins.partner']) && !isset($this['partner.code'])) {
	 throw new SignupValidationException(array('partner opt-in requires a partner code'));
    }
  }

  public function key() {
    return array('email', 'action.id');
  }

}

class SignatureSignupEndpoint extends SignupEndpoint {

  // No specific email or phone number field is required, validation will
  // check that something was provided.
  public static function fields() {

    return array(
	 'email' => array(
	   'required' => TRUE,
	   'default' => '',
	 ),
	 'name.first' => array(
	   'required' => FALSE,
	   'default' => '',
	 ),
	 'name.last' => array(
	   'required' => FALSE,
	   'default' => '',
	 ),
	 'address.address' => array(
	   'required' => FALSE,
	   'default' => '',
	 ),
	 'address.city' => array(
	   'required' => FALSE,
	   'default' => '',
	 ),
	 'address.state.code' => array(
	   'required' => FALSE,
	   'default' => '',
	 ),
	 'address.country' => array(
	   'required' => FALSE,
	   'default' => '',
	 ),
	 'address.postal-code' => array(
	   'required' => FALSE,
	   'default' => '',
	 ),
	 'address.postal-code.type' => array(
	   'required' => FALSE,
	   'default' => '',
	 ),
	 'address.postal-code.plus-four' => array(
	   'required' => FALSE,
	   'default' => '',
	 ),
	 'partner.code' => array(
	   'required' => FALSE,
	   'default' => '',
	 ),
	 'action.id' => array(
	   'required' => TRUE,
	   'default' => '',
	 ),
	 'action.signature-type' => array(
	   'required' => FALSE,
	   'default' => '',
	 ),
	 'action.message' => array(
	   'required' => FALSE,
	   'default' => '',
	 ),
	 'action.opt-ins.display' => array(
	   'required' => FALSE,
	   'default' => '',
	 ),
	 'action.opt-ins.newsletters' => array(
	   'required' => FALSE,
	   'default' => '',
	 ),
	 'action.opt-ins.partner' => array(
	   'required' => FALSE,
	   'default' => '',
	 ),
    );
  }

  protected function validate($signup) {

    // Do the standard validation.
    parent::validate($signup);

    // Check that the partner opt-ins also have a partner code
    if (isset($signup['action.opt-ins.partner']) && !isset($signup['partner.code'])) {
	 throw new SignupValidationException(array('partner opt-in requires a partner code'));
    }
  }

  protected function convertOptInsToEndpoints($names) {
    $endpoints = array();
    foreach ($names as $name) {
	 $endpoint = SignupEndpoint::loadByName($name);
	 if ($endpoint !== FALSE) {
	   $endpoints[$name] = $endpoint;
	 } else {
	   $message = 'newsletter opt-in [' . $name . '] not found';
	   throw new SignupValidationException(array($message));
	 }
    }
    return $endpoints;
  }

  public function submit($signup) {
    $this->validate($signup);
    $this->limit($signup);

    // Convert the newsletter opt-ins to endpoints.
    $signup['action.opt-ins.newsletters'] = $this->convertOptInsToEndpoints(
	 $signup['action.opt-ins.newsletters']);

    parent::send($signup);
    $this->record($signup);
  }

}

/**
 * Signature opt-in endpoints.
 */
class PartnerOptInSignupEndpoint extends SimpleOptInSignupEndpoint {

}

class TakePartOptInSignupEndpoint extends SimpleOptInSignupEndpoint {

}
