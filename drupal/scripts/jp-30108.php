<?php

// Grant all petition permissions to administrators
$permissions = array();
foreach (petition_permission() as $perm => $desc) {
  $permissions[$perm] = 1;
}
foreach (array(5, 6, 7) as $rid) {
  user_role_change_permissions($rid, $permissions);
}

// Rebuild the menu router
menu_rebuild();
