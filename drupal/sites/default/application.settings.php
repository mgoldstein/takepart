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
}
else {
 include_once('./includes/cache.inc');
 include_once('./sites/all/modules/contrib/memcache/memcache.inc');
 $conf += array(
   'cache_default_class' => 'MemCacheDrupal',
   'session_inc' => './sites/all/modules/contrib/memcache/memcache-session.inc',
   'memcache_bins' => array(
     'cache' => 'default',
     'cache_filter' => 'default',
     'cache_menu' => 'default',
     'cache_page' => 'default',
     'session' => 'default',
     'users' => 'default',
   ),
   'memcache_servers' => array(
     'localhost:11211' => 'default',
   ),
   'memcache_key_prefix' => 'local',
 );
}


// HTTPS
if (!array_key_exists('https', $conf)) { $conf['https'] = FALSE; }
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


// TAP Integration
if (!array_key_exists('takeaction_domain', $conf)) {
  $conf['takeaction_domain'] = 'takeaction.takepart.com';
}
$conf += array(
  'takeaction_widget_host' => "https://{$conf['takeaction_domain']}",
  'takeaction_influence_overlay_js' => "//{$conf['takeaction_domain']}/assets/influence.js",
  'signature_action_import_tap_domain' => "{$conf['takeaction_domain']}",
  'signature_import_feed' => "http://{$conf['takeaction_domain']}/api/actions",
  'takeaction_publisher_id' => 'd84909c52edcceb20c7bba62052b1b01',
  'takeaction_widget_script' => '/assets/publisher.js?v=3.7',
  'takeaction_awareness_script' => "//{$conf['takeaction_domain']}/assets/awareness.js",
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
    'domain' => 'bluehornet-proxy.dev.takepart.com:8180',
    // 'domain' => 'echo.bluehornet.com',
    'key' => '40465d9afd847a0e862b857e8e7387b8',
    'secret' => 'a00072e1755a2d2f797971742c97df45',
  ),
  'pivot' => array(
    'domain' => 'bluehornet-proxy.dev.takepart.com:8180',
    // 'domain' => 'echo.bluehornet.com',
    'key' => 'c0cf51a9f440562b91727bab1293ff29',
    'secret' => '28606de9e00dabcbf5049f7b734ff724',
  ),
);
$conf += array('bluehornet_default_account' => 'takepart');