<?php
/**
 * @file
 * takepart_comment.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function takepart_comment_user_default_permissions() {
  $permissions = array();

  // Exported permission: access comments.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
      3 => 'editor',
    ),
    'module' => 'comment',
  );

  // Exported permission: administer comments.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
      2 => 'layout editor',
    ),
    'module' => 'comment',
  );

  // Exported permission: edit own comments.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
      2 => 'editor',
    ),
    'module' => 'comment',
  );

  // Exported permission: post comments.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
      2 => 'editor',
    ),
    'module' => 'comment',
  );

  // Exported permission: skip comment approval.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
      2 => 'editor',
    ),
    'module' => 'comment',
  );

  return $permissions;
}
