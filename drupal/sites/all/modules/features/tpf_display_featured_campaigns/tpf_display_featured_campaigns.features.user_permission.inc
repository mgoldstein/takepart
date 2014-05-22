<?php
/**
 * @file
 * tpf_display_featured_campaigns.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function tpf_display_featured_campaigns_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create any featured_campaigns_module bean'.
  $permissions['create any featured_campaigns_module bean'] = array(
    'name' => 'create any featured_campaigns_module bean',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any featured_campaigns_module bean'.
  $permissions['delete any featured_campaigns_module bean'] = array(
    'name' => 'delete any featured_campaigns_module bean',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any featured_campaigns_module bean'.
  $permissions['edit any featured_campaigns_module bean'] = array(
    'name' => 'edit any featured_campaigns_module bean',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any featured_campaigns_module bean'.
  $permissions['view any featured_campaigns_module bean'] = array(
    'name' => 'view any featured_campaigns_module bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  return $permissions;
}
