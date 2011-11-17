<?php
/**
 * @file
 * takepart_facebook.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function takepart_facebook_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer fb apps
  $permissions['administer fb apps'] = array(
    'name' => 'administer fb apps',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'fb',
  );

  // Exported permission: delete own fb_user authmap
  $permissions['delete own fb_user authmap'] = array(
    'name' => 'delete own fb_user authmap',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'fb_user',
  );

  return $permissions;
}
