<?php
/**
 * @file
 * tpf_config_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function tpf_config_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access comments'.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'access search_api_page'.
  $permissions['access search_api_page'] = array(
    'name' => 'access search_api_page',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search_api_page',
  );

  // Exported permission: 'administer add another'.
  $permissions['administer add another'] = array(
    'name' => 'administer add another',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'addanother',
  );

  // Exported permission: 'administer checked out documents'.
  $permissions['administer checked out documents'] = array(
    'name' => 'administer checked out documents',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'content_lock',
  );

  // Exported permission: 'administer comments'.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'administer files'.
  $permissions['administer files'] = array(
    'name' => 'administer files',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer mini panels'.
  $permissions['administer mini panels'] = array(
    'name' => 'administer mini panels',
    'roles' => array(),
    'module' => 'panels_mini',
  );

  // Exported permission: 'administer panels layouts'.
  $permissions['administer panels layouts'] = array(
    'name' => 'administer panels layouts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels styles'.
  $permissions['administer panels styles'] = array(
    'name' => 'administer panels styles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer pathauto'.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'administer publication date'.
  $permissions['administer publication date'] = array(
    'name' => 'administer publication date',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'publication_date',
  );

  // Exported permission: 'administer search'.
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'administer search_api'.
  $permissions['administer search_api'] = array(
    'name' => 'administer search_api',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search_api',
  );

  // Exported permission: 'administer simplify'.
  $permissions['administer simplify'] = array(
    'name' => 'administer simplify',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'simplify',
  );

  // Exported permission: 'create field_admin_tag'.
  $permissions['create field_admin_tag'] = array(
    'name' => 'create field_admin_tag',
    'roles' => array(
      'administrator' => 'administrator',
      'layout editor' => 'layout editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_main_image_format'.
  $permissions['create field_main_image_format'] = array(
    'name' => 'create field_main_image_format',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_promo_short_headline'.
  $permissions['create field_promo_short_headline'] = array(
    'name' => 'create field_promo_short_headline',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_promo_text'.
  $permissions['create field_promo_text'] = array(
    'name' => 'create field_promo_text',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create files'.
  $permissions['create files'] = array(
    'name' => 'create files',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'create mini panels'.
  $permissions['create mini panels'] = array(
    'name' => 'create mini panels',
    'roles' => array(),
    'module' => 'panels_mini',
  );

  // Exported permission: 'edit field_admin_tag'.
  $permissions['edit field_admin_tag'] = array(
    'name' => 'edit field_admin_tag',
    'roles' => array(
      'administrator' => 'administrator',
      'layout editor' => 'layout editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_main_image_format'.
  $permissions['edit field_main_image_format'] = array(
    'name' => 'edit field_main_image_format',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_promo_short_headline'.
  $permissions['edit field_promo_short_headline'] = array(
    'name' => 'edit field_promo_short_headline',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_promo_text'.
  $permissions['edit field_promo_text'] = array(
    'name' => 'edit field_promo_text',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own comments'.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'edit own field_admin_tag'.
  $permissions['edit own field_admin_tag'] = array(
    'name' => 'edit own field_admin_tag',
    'roles' => array(
      'administrator' => 'administrator',
      'layout editor' => 'layout editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_main_image_format'.
  $permissions['edit own field_main_image_format'] = array(
    'name' => 'edit own field_main_image_format',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_promo_short_headline'.
  $permissions['edit own field_promo_short_headline'] = array(
    'name' => 'edit own field_promo_short_headline',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_promo_text'.
  $permissions['edit own field_promo_text'] = array(
    'name' => 'edit own field_promo_text',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'import media'.
  $permissions['import media'] = array(
    'name' => 'import media',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'media',
  );

  // Exported permission: 'post comments'.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'search content'.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search',
  );

  // Exported permission: 'set any published on date'.
  $permissions['set any published on date'] = array(
    'name' => 'set any published on date',
    'roles' => array(
      'administrator' => 'administrator',
      'layout editor' => 'layout editor',
    ),
    'module' => 'publication_date',
  );

  // Exported permission: 'show format selection for field_collection_item'.
  $permissions['show format selection for field_collection_item'] = array(
    'name' => 'show format selection for field_collection_item',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for inline_content'.
  $permissions['show format selection for inline_content'] = array(
    'name' => 'show format selection for inline_content',
    'roles' => array(
      'administrator' => 'administrator',
      'layout editor' => 'layout editor',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'skip comment approval'.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'use add another'.
  $permissions['use add another'] = array(
    'name' => 'use add another',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'addanother',
  );

  // Exported permission: 'use advanced search'.
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search',
  );

  // Exported permission: 'use panels dashboard'.
  $permissions['use panels dashboard'] = array(
    'name' => 'use panels dashboard',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use search_api_sorts'.
  $permissions['use search_api_sorts'] = array(
    'name' => 'use search_api_sorts',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search_api_sorts',
  );

  // Exported permission: 'view any unpublished content'.
  $permissions['view any unpublished content'] = array(
    'name' => 'view any unpublished content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
      'preview' => 'preview',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view field_admin_tag'.
  $permissions['view field_admin_tag'] = array(
    'name' => 'view field_admin_tag',
    'roles' => array(
      'administrator' => 'administrator',
      'layout editor' => 'layout editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_main_image_format'.
  $permissions['view field_main_image_format'] = array(
    'name' => 'view field_main_image_format',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_promo_short_headline'.
  $permissions['view field_promo_short_headline'] = array(
    'name' => 'view field_promo_short_headline',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_promo_text'.
  $permissions['view field_promo_text'] = array(
    'name' => 'view field_promo_text',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view hidden fields'.
  $permissions['view hidden fields'] = array(
    'name' => 'view hidden fields',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'simplify',
  );

  // Exported permission: 'view own field_admin_tag'.
  $permissions['view own field_admin_tag'] = array(
    'name' => 'view own field_admin_tag',
    'roles' => array(
      'administrator' => 'administrator',
      'layout editor' => 'layout editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_main_image_format'.
  $permissions['view own field_main_image_format'] = array(
    'name' => 'view own field_main_image_format',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_promo_short_headline'.
  $permissions['view own field_promo_short_headline'] = array(
    'name' => 'view own field_promo_short_headline',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_promo_text'.
  $permissions['view own field_promo_text'] = array(
    'name' => 'view own field_promo_text',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
