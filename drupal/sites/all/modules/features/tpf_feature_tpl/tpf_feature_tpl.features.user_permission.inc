<?php
/**
 * @file
 * tpf_feature_tpl.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function tpf_feature_tpl_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create any tpl_long bean'.
  $permissions['create any tpl_long bean'] = array(
    'name' => 'create any tpl_long bean',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any tpl_long bean'.
  $permissions['delete any tpl_long bean'] = array(
    'name' => 'delete any tpl_long bean',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any tpl_long bean'.
  $permissions['edit any tpl_long bean'] = array(
    'name' => 'edit any tpl_long bean',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any tpl_long bean'.
  $permissions['view any tpl_long bean'] = array(
    'name' => 'view any tpl_long bean',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'bean',
  );

  return $permissions;
}
