<?php
/**
 * @file
 * tpf_config_permissions.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function tpf_config_permissions_user_default_roles() {
  $roles = array();

  // Exported role: preview.
  $roles['preview'] = array(
    'name' => 'preview',
    'weight' => 2,
  );

  return $roles;
}
