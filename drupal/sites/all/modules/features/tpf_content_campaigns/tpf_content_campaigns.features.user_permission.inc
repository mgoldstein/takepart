<?php
/**
 * @file
 * tpf_content_campaigns.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function tpf_content_campaigns_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'use text format campaign_full_html'.
  $permissions['use text format campaign_full_html'] = array(
    'name' => 'use text format campaign_full_html',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'filter',
  );

  return $permissions;
}
