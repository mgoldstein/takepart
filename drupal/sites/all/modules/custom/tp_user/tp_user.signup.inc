<?php

class TakePartUserSignup extends Signup {

  public static function fields() {
    return array(
      'email' => array(
        'required' => TRUE,
        'default' => '',
      ),
      'address.postal-code' => array(
        'required' => FALSE,
        'default' => '',
      ),
    );
  }
}


class TakePartUserSignupEndpoint extends SignupEndpoint {

  public static function fields() {
    return array(
      'email' => array(
        'required' => TRUE,
        'default' => '',
      ),
      'address.postal-code' => array(
        'required' => FALSE,
        'default' => '',
      ),
    );
  }
}
