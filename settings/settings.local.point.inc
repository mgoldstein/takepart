<?php
$databases = array (
  'default' =>
    array (
      'default' =>
        array (
          'database' => 'takepart',
          'username' => 'takepart',
          'password' => 'FXZ7MEDFzrW3zw',
          'host' => '10.179.191.14',
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


if (!is_array($conf))
  $conf = array(
   'omniture_account_name' => 'takeparttakepartdev2',
    'cache_default_class'   => 'MemCacheDrupal',

  'memcache_options' => array(
    // Requires Memcached 1.4 or greater - enables binary protocal (faster).
    Memcached::OPT_BINARY_PROTOCOL => TRUE
  )
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
