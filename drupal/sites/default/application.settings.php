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

// TAP Integration
$conf += array(
  'takeaction_widget_host' => "https://{$conf['takeaction_domain']}",
  'takeaction_influence_overlay_js' => "//{$conf['takeaction_domain']}/assets/influence.js",
  'signature_action_import_tap_domain' => "{$conf['takeaction_domain']}",
  'signature_import_feed' => "http://{$conf['takeaction_domain']}/api/actions",
  'takeaction_publisher_id' => 'd84909c52edcceb20c7bba62052b1b01',
  'takeaction_widget_script' => '/assets/publisher.js?v=3.7',
  'takeaction_awareness_script' => "//{$conf['takeaction_domain']}/assets/awareness.js",
  'tap_embed_script' => "https://{$conf['tapembed_domain']}/embed.js?publisher=d84909c52edcceb20c7bba62052b1b01",
);

// Define the global application settings.
// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
// Memcache
if ($conf['memcache_servers'] !== FALSE) {
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
$conf['https'] = TRUE;
if (isset($_SERVER['HTTP_X_FORWARDED_PROTO']) && $_SERVER['HTTP_X_FORWARDED_PROTO'] == 'https') {
  $_SERVER['HTTPS'] = 'on';
}

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

// Participant API accounts
if (!array_key_exists('participant_api_accounts', $conf)) {
  $conf['participant_api_accounts'] = array();
}
switch(ENVIRONMENT) {
  case 'development';
    $domain = 'dev-api.participant.com';
    $conf['takepart_api_domain'] = "http://dev-api.takepart.com";
  break;
  case 'qa':
    $domain = 'qa-api.participant.com';
    $conf['takepart_api_domain'] = "http://qa-api.takepart.com";
  break;
  case 'staging':
    $domain = 'stage-api.participant.com';
    $conf['takepart_api_domain'] = "http://stage-api.takepart.com";
  break;
  case 'production':
  default:
    $domain = 'api.participant.com';
    $conf['takepart_api_domain'] = "http://api.takepart.com";
  break;
}
$conf['participant_api_accounts'] += array(
  'takepart' => array(
    'domain' => $domain,
    'key' => 'db73d53413afcf95324c6d2c0f584cfb',
  ),
  'pivot' => array(
    'domain' => $domain,
    'key' => 'db73d53413afcf95324c6d2c0f584cfb',
  ),
  'participant' => array(
    'domain' => $domain,
    'key' => 'db73d53413afcf95324c6d2c0f584cfb',
  ),
);
$conf += array('participant_api_default_account' => 'takepart');

// reverse proxy support to make sure the real ip gets logged by Drupal
// The next line is commented out inside settings.php
$conf['reverse_proxy'] = TRUE;
if (!isset($conf['reverse_proxy_addresses']) || !is_array($conf['reverse_proxy_addresses'])) {
  $conf['reverse_proxy_addresses'] = array();
}
if (isset($_SERVER['HTTP_X_FORWARDED_FOR'])) {
 $ips = explode(',', $_SERVER['HTTP_X_FORWARDED_FOR']);
 $ips = array_map('trim', $ips);
 // Add REMOTE_ADDR to the X-Forwarded-For list
 //if it is 10. we should add it to the list of reverse proxy addresses so that ip_address will ignore it.
 $ips[] = $_SERVER['REMOTE_ADDR'];
 // Work backwards through the list of IPs, adding 10. addresses to the proxy list
 //  but stop at the first non-10. address we find.
 $ips = array_reverse($ips);
 foreach ($ips as $ip) {
   if (strpos($ip, '10.') === 0) {
     if (!in_array($ip, $conf['reverse_proxy_addresses'])) {
       $conf['reverse_proxy_addresses'][] = $ip;
     }
   }
   else {
     break;
   }
 }
}
