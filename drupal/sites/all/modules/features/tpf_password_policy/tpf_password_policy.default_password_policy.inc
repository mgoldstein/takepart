<?php
/**
 * @file
 * tpf_password_policy.default_password_policy.inc
 */

/**
 * Implements hook_default_password_policy().
 */
function tpf_password_policy_default_password_policy() {
  $export = array();

  $password_policy = new stdClass();
  $password_policy->disabled = FALSE; /* Edit this to true to make a default password_policy disabled initially */
  $password_policy->api_version = 1;
  $password_policy->name = 'TakePart Internal Users';
  $password_policy->description = 'Password policy for CMS users';
  $password_policy->enabled = TRUE;
  $password_policy->policy = array(
    'alphanumeric' => '1',
    'history' => 'all',
    'length' => '7',
    'lowercase' => '1',
    'uppercase' => '1',
    'username' => '1',
  );
  $password_policy->created = 1426202926;
  $password_policy->expiration = 90;
  $password_policy->warning = '7,3,2,1';
  $password_policy->weight = FALSE;
  $export['TakePart Internal Users'] = $password_policy;

  return $export;
}
