<?php
/**
 * @file
 * tp_feature_feature_article.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function tp_feature_feature_article_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create feature_article content'.
  $permissions['create feature_article content'] = array(
    'name' => 'create feature_article content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any feature_article content'.
  $permissions['delete any feature_article content'] = array(
    'name' => 'delete any feature_article content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own feature_article content'.
  $permissions['delete own feature_article content'] = array(
    'name' => 'delete own feature_article content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any feature_article content'.
  $permissions['edit any feature_article content'] = array(
    'name' => 'edit any feature_article content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own feature_article content'.
  $permissions['edit own feature_article content'] = array(
    'name' => 'edit own feature_article content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  return $permissions;
}
