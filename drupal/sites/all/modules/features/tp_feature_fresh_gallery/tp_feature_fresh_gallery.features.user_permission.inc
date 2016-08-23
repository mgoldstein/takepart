<?php
/**
 * @file
 * tp_feature_fresh_gallery.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function tp_feature_fresh_gallery_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create fresh_gallery content'.
  $permissions['create fresh_gallery content'] = array(
    'name' => 'create fresh_gallery content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any fresh_gallery content'.
  $permissions['delete any fresh_gallery content'] = array(
    'name' => 'delete any fresh_gallery content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own fresh_gallery content'.
  $permissions['delete own fresh_gallery content'] = array(
    'name' => 'delete own fresh_gallery content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any fresh_gallery content'.
  $permissions['edit any fresh_gallery content'] = array(
    'name' => 'edit any fresh_gallery content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own fresh_gallery content'.
  $permissions['edit own fresh_gallery content'] = array(
    'name' => 'edit own fresh_gallery content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  return $permissions;
}
