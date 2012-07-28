<?php

// Grant all contest permissions to administrators
$permissions = array();
foreach (takepart_contests_permission() as $perm => $desc) {
  $permissions[$perm] = 1;
}
foreach (array(6, 7) as $rid) {
  user_role_change_permissions($rid, $permissions);
}
$permissions = array();
foreach (ideasforgood_permission() as $perm => $desc) {
  $permissions[$perm] = 1;
}
foreach (array(6, 7) as $rid) {
  user_role_change_permissions($rid, $permissions);
}
// Set all the contest entries to published
db_update('takepart_contests_contest_entry')
  ->fields(array('status' => 1))
  ->execute();

// Rebuild the menu router
menu_rebuild();
