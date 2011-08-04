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



//$conf['fb_verbose'] = TRUE; // debug output
//$conf['fb_verbose'] = 'extreme'; // for verbosity fetishists.

// More efficient connect session discovery.
// Required if supporting one connect app and different canvas apps.
//$conf['fb_apikey'] = '123.....XYZ'; // Your connect app's apikey goes here.

// Enable URL rewriting (for canvas page apps).
include "sites/all/modules/contrib/fb/fb_url_rewrite.inc";
include "sites/all/modules/contrib/fb/fb_settings.inc";
//ini_set('error_reporting', !E_NOTICE & !E_WARNING);

/* MemCache Settings */

// the path to the core cache file
  include_once('./includes/cache.inc');
// the path to the memcache cache file
  include_once('./sites/all/modules/contrib/memcache/memcache.inc');


if (!is_array($conf))
  $conf = array(
   'omniture_account_name' => 'takepart',
   'cache_default_class'   => 'MemCacheDrupal',
);
