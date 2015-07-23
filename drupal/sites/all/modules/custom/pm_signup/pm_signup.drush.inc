<?php
/**
 * @file
 * Drush commands for Signup module
 */

/**
 * Implements hook_drush_command().
 */
function pm_signup_drush_command() {
  return array(
    'signup-endpoint-create' => array(
      'description' => dt('Create a named signup endpoint.'),
      'arguments' => array(
        'label' => dt('label of the signup endpoint'),
        'name' => dt('optional name of the signup endpoint'),
      ),
      'required-arguments' => 1,
      'examples' => array(
        'Standard example' => 'drush signup-endpoint-create "Example Signup Endpoint" [example_signup_endpoint]',
      ),
      'aliases' => array(
        'supc',
      ),
    ),
    'signup-endpoint-delete' => array(
      'description' => dt('Delete a named signup endpoint.'),
      'arguments' => array(
        'name' => dt('name of the signup endpoint'),
      ),
      'required-arguments' => TRUE,
      'examples' => array(
        'Standard example' => 'drush signup-endpoint-delete example_signup_endpoint',
      ),
      'aliases' => array(
        'supd',
      ),
    ),
  );
}

/**
 * Drush create signup endpoint
 */
function drush_pm_signup_signup_endpoint_create($label, $name = NULL) {

  $endpoint = new DefaultSignupEndpoint();
  $endpoint->labelForExport($label, $name);
  $name = $endpoint->getName();

  $check = SignupEndpoint::loadByName($name);
  if ($check === FALSE) {
    $endpoint->save();
    drush_log(dt("Signup endpoint @name created", array('@name' => $name)), 'ok');
  }
  else {
    drush_set_error(dt("Signup endpoint @name already exists", array('@name' => $name)));
  }
}

/**
 * Drush delete signup endpoint
 */
function drush_pm_signup_signup_endpoint_delete($name) {
  $endpoint = SignupEndpoint::loadByName($name);
  if ($endpoint !== FALSE) {
    $endpoint->delete();
    drush_log(dt("Signup endpoint @name deleted", array('@name' => $name)), 'ok');
  }
  else {
    drush_set_error(dt("Signup endpoint @name does not exist", array('@name' => $name)));
  }
}
