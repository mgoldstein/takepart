<?php
/**
 * @file
 * Drush commands for Signup module
 */

/**
 * Implements hook_drush_command().
 */
function signature_drush_command() {
  return array(
    'signature-action-import' => array(
      'description' => dt('Import actions from TAP.'),
      'arguments' => array(),
      'examples' => array(
        'Standard example' => 'drush signature-action-import',
      ),
      'aliases' => array(
        'sai',
      ),
    ),
    'signature-action-sync' => array(
      'description' => dt('Import actions from TAP.'),
      'arguments' => array(),
      'examples' => array(
        'Standard example' => 'drush signature-action-sync',
      ),
      'aliases' => array(
        'sas',
      ),
    ),
  );
}

/**
 * Drush import actions from TAP.
 */
function drush_signature_action_import() {

  $feed_url = variable_get('signature_import_feed', '');
  $timeout = variable_get('signature_import_timeout', 600);
  $count = 0;
  if (!empty($feed_url)) {
    $count = signature_process_import_feed($feed_url, $timeout);
  }
  drush_log(dt("Processed @count actions", array('@count' => $count)), 'ok');
}

/**
 * Drush sync actions from TAP.
 */
function drush_signature_action_sync() {

  $feed_url = variable_get('signature_import_feed', '');
  $timeout = variable_get('signature_import_timeout', 600);
  $count = 0;
  if (!empty($feed_url)) {
    $count = signature_process_import_feed($feed_url, $timeout, TRUE);
  }
  drush_log(dt("Processed @count actions", array('@count' => $count)), 'ok');
}
