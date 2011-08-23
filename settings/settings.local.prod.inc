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
      'slave' =>
        array (
          'database' => 'takepart',
          'username' => 'takepart-slave',
          'password' => '7mEwdni8tbcXBQ',
          'host' => '172.17.128.111',
          'port' => '',
          'driver' => 'mysql',
          'prefix' => '',
        ),
    ),
);

/* MemCache Settings */
// the path to the core cache file
include_once('./includes/cache.inc');
// the path to the memcache cache file
include_once('./sites/all/modules/contrib/memcache/memcache.inc');

$conf = array(
   'omniture_account_name' => 'takepart',
   'cache_default_class'   => 'MemCacheDrupal',
   'session_inc' => './sites/all/modules/contrib/memcache/memcache-session.inc'

   //'memcache_options' => array(
     // Requires Memcached 1.4 or greater - enables binary protocal (faster).
     //Memcached::OPT_BINARY_PROTOCOL => TRUE
   //),

   'memcache_servers' => array(
        '10.181.229.207:11211' => 'default', // web1.takepart.com
        '10.181.227.7:11211' => 'default', // web2.takepart.com
        '10.181.227.8:11211' => 'default', // web3.takepart.com
        '10.181.227.104:11211' => 'default' // web4.takepart.com
   ),

   'memcache_bins' => array(
        'cache' => 'default',
        'cache_filter' => 'default',
        'cache_menu' => 'default',
        'cache_page' => 'default',
        'session' => 'default',
        'users' => 'default',
   ),
);

//$conf['fb_verbose'] = TRUE; // debug output
//$conf['fb_verbose'] = 'extreme'; // for verbosity fetishists.

// More efficient connect session discovery.
// Required if supporting one connect app and different canvas apps.
//$conf['fb_apikey'] = '123.....XYZ'; // Your connect app's apikey goes here.

// Enable URL rewriting (for canvas page apps).
/*
include "sites/all/modules/contrib/fb/fb_url_rewrite.inc";
include "sites/all/modules/contrib/fb/fb_settings.inc";
*/

