<?php
$databases = array (
  'default' =>
    array (
      'default' =>
        array (
          'database' => 'takepart',
          'username' => 'takepart',
          'password' => '53uZoTHMcZvC',
          'host' => 'qa-rds1.dev.takepart.com',
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
      'qa-memcache1.dev.takepart.com:11211' => 'default'
);

$conf['memcache_key_prefix'] = 'qa';

$conf['memcache_bins'] = array(
      'cache' => 'default',
      'cache_filter' => 'default',
      'cache_menu' => 'default',
      'cache_page' => 'default',
      'session' => 'default',
      'users' => 'default',
);

require_once('sites/all/modules/contrib/fb/fb_settings.inc');

