<?php

/**
 * Implements hook_drush_command().
 */
function tp4_support_drush_command() {
  return array(
    'unpublish-expired-actions' => array(
      'description' => dt('Unpublish Drupal actions that have expired in TAP.'),
      'arguments' => array(),
      'examples' => array(
        'Standard example' => 'drush unpublish-expired-actions',
      ),
      'aliases' => array(
        'uea',
      ),
    ),
  );
}

/**
 * Drush unpublish Drupal actions that have expired in TAP.
 */
function drush_tp4_support_unpublish_expired_actions() {
      _tp4_support_action_batch();
      $batch = &batch_get();
      $batch['progressive'] = FALSE; //this is needed to turn off the progressive
      batch_process('');
}

