<?php
$databases = array (
  'default' =>
    array (
      'default' =>
        array (
          'database' => 'takepart',
          'username' => 'takepart',
          'password' => 'GkA29UFJeumGLB',
          'host' => '172.17.128.100',
          'port' => '',
          'driver' => 'mysql',
          'prefix' => '',
        ),
//      'slave' =>
//        array (
//          'database' => 'takepart',
//          'username' => 'takepart-slave',
//          'password' => '7mEwdni8tbcXBQ',
//          'host' => '172.17.128.111',
//          'port' => '',
//          'driver' => 'mysql',
//          'prefix' => '',
//        ),
    ),
);

/*

$conf['cache_inc'] = './sites/default/modules/takepart/takepart_optimization/takepart_optimization.cache.inc';
$conf['cacherouter'] = array(
        'cache_form' => array(
                'engine' => 'db',
                'servers' => array(),
                'shared' => false,
                'prefix' => '',
                'path' => '',
                'static' => FALSE,
                'fast_cache' => TRUE,
        ),

        'default' => array(
                'engine' => 'memcache',
                'servers' => array(
                        '127.0.0.1:11211'
                ),
                'shared' => false,
                'prefix' => '',
                'path' => '',
                'static' => FALSE,
                'fast_cache' => TRUE,
        ),

);
*/

//// Code to add to settings.php:
/////////////////////////////////
/**
 * Drupal for Facebook settings.
 */
if (!is_array($conf))
  $conf = array(
   'omniture_account_name' = 'takepart',
);


//$conf['fb_verbose'] = TRUE; // debug output
//$conf['fb_verbose'] = 'extreme'; // for verbosity fetishists.

// More efficient connect session discovery.
// Required if supporting one connect app and different canvas apps.
//$conf['fb_apikey'] = '123.....XYZ'; // Your connect app's apikey goes here.

// Enable URL rewriting (for canvas page apps).
include "sites/all/modules/contrib/fb/fb_url_rewrite.inc";
include "sites/all/modules/contrib/fb/fb_settings.inc";
//ini_set('error_reporting', !E_NOTICE & !E_WARNING);
// end of settings.php
