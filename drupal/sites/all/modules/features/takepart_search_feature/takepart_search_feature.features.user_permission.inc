<?php
/**
 * @file
 * takepart_search_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function takepart_search_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access site_search search_api_page'.
  $permissions['access site_search search_api_page'] = array(
    'name' => 'access site_search search_api_page',
    'roles' => array(),
    'module' => 'search_api_page',
  );

  return $permissions;
}
