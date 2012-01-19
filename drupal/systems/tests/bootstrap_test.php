<?php

// Tests drupal bootstrap.
error_reporting(E_ALL);
ini_set('display_errors','On');
chdir('../../');
define('DRUPAL_ROOT', getcwd());

require_once DRUPAL_ROOT . '/includes/install.inc';
require_once DRUPAL_ROOT . '/includes/bootstrap.inc';

$dstrap = drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

if ($dstrap == true)
{
  echo "Drupal Bootstrap - OK";
  
}
else
{
  echo "Drupal Boostrap - FAILURE";
}

?>
