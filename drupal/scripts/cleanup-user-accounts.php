<?php

/*
 * Delete all external user accounts, save only accounts with internal user
 * permissions.
 */

// define static var
define('DRUPAL_ROOT', getcwd());
// include bootstrap
include_once('./includes/bootstrap.inc');
// initialize stuff
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

function _get_users() {
  $sql = "SELECT u.uid FROM users u LEFT JOIN users_roles r ON u.uid = r.uid WHERE r.uid IS NULL";
  $results = db_query($sql);
  return $results;
}

function _delete_users($results) {
  $found = $results->rowCount();
  $i = 0;
  foreach ($results as $row) {
    if ($row->uid > 0) {
	 $i++;
	 user_delete($row->uid);
	 echo "Deleted user ID " . $row->uid . " (" . $i . " of " . $found . ")\r\n";
    }
  }
}

$users = _get_users();
_delete_users($users);
