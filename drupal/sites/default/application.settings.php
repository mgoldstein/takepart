<?php

// Include the local settings that define the specifics of the instance,
// including the ENVIRONMENT type.
if (file_exists(dirname(__FILE__) . '/settings.local.inc')) {
  include_once dirname(__FILE__) . '/settings.local.inc';
}

// Include the environment specific settings.
$environment_settings_filename = dirname(__FILE__) . '/' . ENVIRONMENT . '.settings.php';
if (file_exists($environment_settings_filename)) {
  include_once $environment_settings_filename;
}

// Define the global application settings.
// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
// Memcache
if (isset($conf['memcache_servers']) && $conf['memcache_servers'] === FALSE) {
  unset($conf['memcache_servers']);
} else {
  $conf['cache_backends'][] = 'sites/all/modules/contrib/memcache/memcache.inc';
  $conf += array(
    'cache_default_class' => 'MemCacheDrupal',
    'cache_class_cache_form' => 'DrupalDatabaseCache',
    'page_cache_without_database' => TRUE,
    'page_cache_invoke_hooks' => FALSE,
    'lock_inc' => 'sites/all/modules/contrib/memcache/memcache-lock.inc',
    'memcache_stampede_protection' => TRUE,
    'memcache_servers' => array(
	 'localhost:11211' => 'default',
    ),
    'memcache_key_prefix' => 'local',
  );
}

// HTTPS
if (!array_key_exists('https', $conf)) {
  $conf['https'] = FALSE;
}
if ($conf['https']) {
  if (file_exists(dirname(__FILE__) . '/https.settings.php')) {
    include_once dirname(__FILE__) . '/https.settings.php';
  }
}
$conf['securepages_enable'] = $conf['https'];

// JWPlatform API account
$conf += array(
  'pm_jwplatform_api_key' => 'NnnOqH8r',
  'pm_jwplatform_api_secret' => 'fJoeVtVS5YriI0Bnh8v6lo1i',
  'pm_jwplatform_content_domain' => 'content.jwplatform.com',
  'pm_jwplatform_content_dns_mask' => 'video.takepart.com',
  'tp_video_player_account_token' => 'esP2FhWwEeODmBIxOUCPzg',
  'tp_video_player_key' => 'xlvA/gqv5vAkINGetf3aFsus8xjtNRWt+WzQqA==',
);

// Services/Login Integration
if (!array_key_exists('services_domain', $conf)) {
  $conf['services_domain'] = 'accounts.takepart.com';
}
$conf += array(
  'centralized_login_widget_js' => "https://{$conf['services_domain']}/assets/login_widget.js",
  'digital_data_wrapper_js' => "https://{$conf['services_domain']}/assets/dtm_data.js",
);

// Email Personalization Integration
$conf += array(
  'tp_content_feeds_tag_vocabularies' => array('topic'),
  'tp_content_feeds_content_types' => array(
    'feature_article',
    'openpublish_article',
    'openpublish_photo_gallery',
    'video',
  ),
);

// BlueHornet accounts
if (!array_key_exists('bluehornet_api_accounts', $conf)) {
  $conf['bluehornet_api_accounts'] = array();
}
$conf['bluehornet_api_accounts'] += array(
  'takepart' => array(
    // 'domain' => 'bluehornet-proxy.dev.takepart.com:8180',
    'domain' => 'echo.bluehornet.com',
    'key' => '40465d9afd847a0e862b857e8e7387b8',
    'secret' => 'a00072e1755a2d2f797971742c97df45',
  ),
  'pivot' => array(
    // 'domain' => 'bluehornet-proxy.dev.takepart.com:8180',
    'domain' => 'echo.bluehornet.com',
    'key' => 'c0cf51a9f440562b91727bab1293ff29',
    'secret' => '28606de9e00dabcbf5049f7b734ff724',
  ),
  'participant' => array(
    'domain' => 'echo.bluehornet.com',
    'key' => '326fda4d900200ddc59855ed494b3fad',
    'secret' => '05ba67e07735907e703867bfde063765',
  ),
);
$conf += array('bluehornet_default_account' => 'takepart');

if (!empty($conf['reverse_proxy_addresses'])) {
$ips = explode(',', $_SERVER['HTTP_X_FORWARDED_FOR']);
  $ips = array_map('trim', $ips);
  // Add REMOTE_ADDR to the X-Forwarded-For list (the ip_address function will
  // also do this) in case it's a 10. internal AWS address; if it is we should
  // add it to the list of reverse proxy addresses so that ip_address will
  // ignore it.
  $ips[] = $_SERVER['REMOTE_ADDR'];
  // Work backwards through the list of IPs, adding 10. addresses to the proxy
  // list but stop at the first non-10. address we find.
  $ips = array_reverse($ips);
  foreach ($ips as $ip) {
    if (strpos($ip, '10.') === 0) {
      if (!in_array($ip, $conf['reverse_proxy_addresses'])) {
        $conf['reverse_proxy_addresses'][] = $ip;
      }
    } else {
    // we hit the first non-10. address, so stop.
    break;
    }
  }
}
