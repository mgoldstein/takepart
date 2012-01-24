<?php
$databases = array (
  'default' =>
    array (
      'default' =>
        array (
          'database' => 'takepart',
          'username' => 'takepart',
          'password' => 'slec5alp8uj3hot9',
          'host' => '192.168.100.100',
          'port' => '',
          'driver' => 'mysql',
          'prefix' => '',
        ),
      'slave' =>
        array (
          'database' => 'takepart',
          'username' => 'takepart-slave',
          'password' => 'veud6uft8yo2he5o',
          'host' => '192.168.100.110',
          'port' => '',
          'driver' => 'mysql',
          'prefix' => '',
        ),
    ),
);
// the path to the core cache file
include_once('./includes/cache.inc');
// the path to the memcache cache file
include_once('./sites/all/modules/contrib/memcache/memcache.inc');

$conf['omniture_account_name'] = 'takeparttakepartdev2';
$conf['cache_default_class']   = 'MemCacheDrupal';
$conf['session_inc'] = './sites/all/modules/contrib/memcache/memcache-session.inc';

$conf['memcache_servers'] = array(
      '10.178.51.179:11211' => 'default', // qa-web1.takepart.com
      '10.178.51.133:11211' => 'default'  // qa-web2.takepart.com
);

$conf['memcache_bins'] = array(
      'cache' => 'default',
      'cache_filter' => 'default',
      'cache_menu' => 'default',
      'cache_page' => 'default',
//      'session' => 'default',
      'users' => 'default',
);

require_once('sites/all/modules/contrib/fb/fb_settings.inc');

// $conf['memcache_options'] = array(
//  Requires Memcached 1.4 or greater - enables binary protocal (faster).
//  Memcached::OPT_BINARY_PROTOCOL => TRUE
// );
