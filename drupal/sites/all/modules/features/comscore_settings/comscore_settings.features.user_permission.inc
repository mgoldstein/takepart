<?php
/**
 * @file
 * comscore_settings.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function comscore_settings_user_default_permissions() {
  $permissions = array();

  // Exported permission: Administer comScore direct.
  $permissions['Administer comScore direct'] = array(
    'name' => 'Administer comScore direct',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'comscore_direct',
  );

  return $permissions;
}
