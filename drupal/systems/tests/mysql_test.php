<?php

// Simple tests of database.

error_reporting(E_ALL);
ini_set('display_errors','On');
chdir('../../');
define('DRUPAL_ROOT', getcwd());

require_once DRUPAL_ROOT . '/includes/install.inc';
include_once DRUPAL_ROOT . '/sites/default/settings.local.inc';
include_once DRUPAL_ROOT . '/includes/bootstrap.inc';

$link = mysql_connect("{$databases['default']['default']['host']}", "{$databases['default']['default']['username']}", "{$databases['default']['default']['password']}");

if (!$link) {
  echo "MySQL Connection - FAILURE\n<br> . mysql_error()";
}
else
{
  echo "MySQL Connection - OK\n<BR>\n";
}

// Select first row for users table.  If uid does not equal 0, fail.
$query = "select uid from {$databases['default']['default']['database']}.users where uid=0;";
$result = mysql_query($query);

while ($row = mysql_fetch_array($result)) {
  if ($row['uid'] == 0)
    echo "MySQL SELECT - OK";
  else
    echo "MySQL SELECT - FAILURE";
}

mysql_close($link);
?>
