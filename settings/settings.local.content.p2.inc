<?php
$databases = array (
  'default' =>
    array (
      'default' =>
        array (
          'database' => 'takepart_content',
          'username' => 'takepart_conten',
          'password' => '7b65aada',
          'host' => 'localhost',
          'port' => '',
          'driver' => 'mysql',
          'prefix' => '',
        ),
    ),
  'migrate' =>
    array (
      'default' =>
        array (
          'database' => 'bblake_takepart2',
          'username' => 'root',
          'password' => 'papa16',
          'host' => 'localhost',
          'port' => '',
          'driver' => 'mysql',
          'prefix' => '',
        ),
    ),    
);

//// Code to add to settings.php:
/////////////////////////////////
/**
 * Drupal for Facebook settings.
 */

if (!is_array($conf))
  $conf = array(
   'omniture_account_name' => 'takeparttakepartdev2',
);

//$conf['fb_verbose'] = TRUE; // debug output
//$conf['fb_verbose'] = 'extreme'; // for verbosity fetishists.

// More efficient connect session discovery.
// Required if supporting one connect app and different canvas apps.
//$conf['fb_apikey'] = '123.....XYZ'; // Your connect app's apikey goes here.

// Enable URL rewriting (for canvas page apps).
include "sites/all/modules/contrib/fb/fb_url_rewrite.inc";
include "sites/all/modules/contrib/fb/fb_settings.inc";
ini_set('error_reporting', !E_NOTICE & !E_WARNING);
ini_set('memory_limit','512M');
// end of settings.php
