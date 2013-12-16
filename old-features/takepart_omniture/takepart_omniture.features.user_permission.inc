<?php
/**
 * @file
 * takepart_omniture.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function takepart_omniture_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer SiteCatalyst configuration.
  $permissions['administer SiteCatalyst configuration'] = array(
    'name' => 'administer SiteCatalyst configuration',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'omniture',
  );

  return $permissions;
}
