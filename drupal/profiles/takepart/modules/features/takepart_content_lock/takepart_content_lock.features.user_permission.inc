<?php
/**
 * @file
 * takepart_content_lock.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function takepart_content_lock_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer checked out documents.
  $permissions['administer checked out documents'] = array(
    'name' => 'administer checked out documents',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
      2 => 'layout editor',
    ),
    'module' => 'content_lock',
  );

  // Exported permission: check out documents.
  $permissions['check out documents'] = array(
    'name' => 'check out documents',
    'roles' => array(
      0 => 'administrator',
      1 => 'contributor',
      2 => 'editor',
      3 => 'layout editor',
    ),
    'module' => 'content_lock',
  );

  return $permissions;
}
