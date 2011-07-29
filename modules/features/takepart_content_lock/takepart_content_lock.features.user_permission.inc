<?php
/**
 * @file
 * takepart_content_lock.features.user_permission.inc
 */

/**
 * Implementation of hook_user_default_permissions().
 */
function takepart_content_lock_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer checked out documents
  $permissions['administer checked out documents'] = array(
    'name' => 'administer checked out documents',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'content_lock',
  );

  // Exported permission: check out documents
  $permissions['check out documents'] = array(
    'name' => 'check out documents',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
      2 => 'editor',
    ),
    'module' => 'content_lock',
  );

  return $permissions;
}
