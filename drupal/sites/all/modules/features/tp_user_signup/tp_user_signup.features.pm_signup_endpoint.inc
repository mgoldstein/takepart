<?php
/**
 * @file
 * tp_user_signup.features.pm_signup_endpoint.inc
 */

/**
 * Implements hook_pm_signup_endpoint_defaults().
 */
function tp_user_signup_pm_signup_endpoint_defaults() {
  $endpoints = array();
  $endpoints[] = array(
    'type' => 'TakePartUserSignupEndpoint',
    'name' => 'mentor_strong',
    'label' => 'Mentor Strong Search Signup (Pivot Account)',
    'configuration' => array(),
    'plugins' => array(
      'bluehornet.pm_signup.handler' => array(
        'enabled' => TRUE,
        'configuration' => array(
          'account' => 'pivot',
          'segments' => array(
            '1017890',
          ),
          'fields' => array(
            '253169' => 'MentorStrong',
            '253168' => 'MENTOR',
          ),
          'send-welcome' => TRUE,
        ),
      ),
    ),
  );
  $endpoints[] = array(
    'type' => 'TakePartUserSignupEndpoint',
    'name' => 'user_registration_opt_in_yes',
    'label' => 'TakePart User Registation w/ Opt-In',
    'configuration' => array(),
    'plugins' => array(
      'bluestatedigital.pm_signup.handler' => array(
        'enabled' => TRUE,
        'configuration' => array(
          'form-id' => 7,
          'email-field-id' => 80,
          'zip-code-field-id' => 89,
        ),
      ),
      'bluehornet.pm_signup.handler' => array(
        'enabled' => FALSE,
        'configuration' => array(
          'account' => 'takepart',
          'segments' => array(
            '1008359',
            '1008357',
            '1008358',
            '1010762',
          ),
          'fields' => array(
            '252906' => 'Webform',
            '253159' => 'FOODINC',
          ),
          'send-welcome' => TRUE,
        ),
      ),
    ),
  );
  $endpoints[] = array(
    'type' => 'TakePartUserSignupEndpoint',
    'name' => 'user_registration_opt_in_no',
    'label' => 'TakePart User Registation w/o Opt-In',
    'configuration' => array(),
    'plugins' => array(
      'bluestatedigital.pm_signup.handler' => array(
        'enabled' => TRUE,
        'configuration' => array(
          'form-id' => 7,
          'email-field-id' => 80,
          'zip-code-field-id' => 89,
        ),
      ),
      'bluehornet.pm_signup.handler' => array(
        'enabled' => FALSE,
        'configuration' => array(
          'account' => 'takepart',
          'segments' => array('1010762'),
          'fields' => array(
            '253159' => 'REGISTERED',
          ),
          'send-welcome' => TRUE,
        ),
      ),
    ),
  );
  return $endpoints;
}
