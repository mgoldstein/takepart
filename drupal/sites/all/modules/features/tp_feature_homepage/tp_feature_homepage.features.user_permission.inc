<?php
/**
 * @file
 * tp_feature_homepage.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function tp_feature_homepage_user_default_permissions() {
  $permissions = array();

  // Exported permission: use ccl.
  $permissions['use ccl'] = array(
    'name' => 'use ccl',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'ccl',
  );

  return $permissions;
}
