<?php
/**
 * @file
 * tpf_content_flashcard.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function tpf_content_flashcard_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create flashcard content'.
  $permissions['create flashcard content'] = array(
    'name' => 'create flashcard content',
    'roles' => array(
      'administrator' => 'administrator',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any flashcard content'.
  $permissions['delete any flashcard content'] = array(
    'name' => 'delete any flashcard content',
    'roles' => array(
      'administrator' => 'administrator',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own flashcard content'.
  $permissions['delete own flashcard content'] = array(
    'name' => 'delete own flashcard content',
    'roles' => array(
      'administrator' => 'administrator',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any flashcard content'.
  $permissions['edit any flashcard content'] = array(
    'name' => 'edit any flashcard content',
    'roles' => array(
      'administrator' => 'administrator',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own flashcard content'.
  $permissions['edit own flashcard content'] = array(
    'name' => 'edit own flashcard content',
    'roles' => array(
      'administrator' => 'administrator',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  return $permissions;
}
