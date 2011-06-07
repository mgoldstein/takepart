<?php
/**
 * @file
 * takepart_custom.features.user_role.inc
 */

/**
 * Implementation of hook_user_default_roles().
 */
function takepart_custom_user_default_roles() {
  $roles = array();

  // Exported role: administrator
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => '6',
  );

  // Exported role: author
  $roles['author'] = array(
    'name' => 'author',
    'weight' => '3',
  );

  // Exported role: contributor
  $roles['contributor'] = array(
    'name' => 'contributor',
    'weight' => '2',
  );

  // Exported role: editor
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => '4',
  );

  // Exported role: layout editor
  $roles['layout editor'] = array(
    'name' => 'layout editor',
    'weight' => '5',
  );

  return $roles;
}
