<?php
/**
 * @file
 * takepart_publication_report.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function takepart_publication_report_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 6,
  );

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => 4,
  );

  // Exported role: layout editor.
  $roles['layout editor'] = array(
    'name' => 'layout editor',
    'weight' => 5,
  );

  return $roles;
}
