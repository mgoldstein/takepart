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

$conf['omniture_account_name'] = 'takeparttakepartdev2';
$conf['cache_default_class']   = 'MemCacheDrupal';
$conf['session_inc'] = './sites/all/modules/contrib/memcache/memcache-session.inc';

// $conf['memcache_options'] = array(
//  Requires Memcached 1.4 or greater - enables binary protocal (faster).
//  Memcached::OPT_BINARY_PROTOCOL => TRUE
// ); 

require_once('sites/all/modules/contrib/fb/fb_settings.inc');

ini_set('error_reporting', !E_NOTICE & !E_WARNING);
ini_set('memory_limit','512M');