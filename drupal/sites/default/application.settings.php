<?php

// Bring in unique settings for each environment
$common_settings = dirname(__FILE__) . '/common.settings.php';
if (file_exists($common_settings)) {
  include_once $common_settings;
}

// Database configuration
// Ensure the database configuration happens before any of the $conf array elements are defined.
// Else, you run into the possibility of the variables for the databases not being populated yet.
// I can't explain it, but the behavior is solid when database definitions precede the $conf
// definitions.

// Master database
$databases['default']['default'] = array(
  'database' => $database_name,
  'username' => $database_username,
  'password' => $database_password,
  'host'     => $database_host,
  'port'     => $database_port,
  'driver'   => $database_driver,
  'prefix'   => $database_prefix,
);
// One or more slaves
if ($database_slave_host) {
  $databases['default']['slave'][] = array(
    'database' => $database_name,
    'username' => $database_username,
    'password' => $database_password,
    'host'     => $database_slave_host,
    'port'     => $database_port,
    'driver'   => $database_driver,
    'prefix'   => $database_prefix,
  );
}
// Solr Server settings
$conf['search_api_solr_overrides'] = array(
  'takepart_solr_production' => array(
    'name'    => t($solr_name),
    'options' => array(
    'host'    => $solr_host,
    'port'    => $solr_port,
    'path'    => $solr_path,
    ),
  ),
);

// Ingest application settings into the application here
$conf += array(
  'campaign_css_s3_path'               => $campaign_css_s3_path,
  'centralized_login_widget_js'        => "https://$services_domain/assets/login_widget.js",
  'cloudinary_bucket'                  => $cloudinary_bucket,
  'dtm_script_src'                     => $dtm_script_src,
  'facebook_app_id'                    => $facebook_app_id,
  'facebook_access_token'              => $facebook_access_token,
  'https'                              => TRUE,
  'omniture_account_name'              => $omniture_account_name,
  'participant_api_default_account'    => $participant_api_default_account,
  'pm_signup_log'                      => $pm_signup_log,
  'pm_jwplatform_auto_create_tag'      => $pm_jwplatform_auto_create_tag,
  'pm_jwplatform_api_key'              => $pm_jwplatform_api_key,
  'pm_jwplatform_api_secret'           => $pm_jwplatform_api_secret,
  'pm_jwplatform_content_domain'       => $pm_jwplatform_content_domain,
  'pm_jwplatform_content_dns_mask'     => $pm_jwplatform_content_dns_mask,
  'shared_assets_path'                 => $shared_assets_path,
  'signature_action_import_tap_domain' => "$takeaction_domain",
  'signature_import_feed'              => "https://$takeaction_domain/api/actions",
  'smtp_host'                          => $smtp_host,
  'smtp_password'                      => $smtp_password,
  'smtp_port'                          => $smtp_port,
  'smtp_username'                      => $smtp_username,
  'takeaction_awareness_script'        => "//$takeaction_domain/assets/awareness.js",
  'takeaction_domain'                  => $takeaction_domain,
  'takeaction_influence_overlay_js'    => "//$takeaction_domain/assets/influence.js",
  'takeaction_publisher_id'            => $takeaction_publisher_id,
  'takeaction_widget_host'             => "https://$takeaction_domain",
  'takeaction_widget_script'           => '/assets/publisher.js?v=3.7',
  'takepart_api_domain'                => "http://$services_domain",
  'tap_embed_script'                   => "https://$tapembed_domain/embed.js?publisher=$takeaction_publisher_id",
  'tapembed_domain'                    => $tapembed_domain,
  'tp_video_player_account_token'      => $tp_video_player_account_token,
  'tp_video_player_key'                => $tp_video_player_key,
);

// Elasticache
if ($memcache_host) {
  $conf['cache_backends'][] = $cache_backends;
  $conf += array(
    'cache_default_class'          => 'MemCacheDrupal',
    'cache_class_cache_form'       => 'DrupalDatabaseCache',
    'page_cache_without_database'  => TRUE,
    'page_cache_invoke_hooks'      => FALSE,
    'lock_inc'                     => 'sites/all/modules/contrib/memcache/memcache-lock.inc',
    'memcache_stampede_protection' => TRUE,
    'memcache_servers'             => array(
      "$memcache_host:$memcache_port" => 'default',
    ),
    'memcache_key_prefix'          => $APP_ENV,
  );
}

// SSL handling
if (isset($_SERVER['HTTP_X_FORWARDED_PROTO']) && $_SERVER['HTTP_X_FORWARDED_PROTO'] == 'https') {
  $_SERVER['HTTPS'] = 'on';
}

// Email Personalization Integration
$conf += array(
  'tp_content_feeds_tag_vocabularies' => array('topic'),
  'tp_content_feeds_content_types'    => array(
    'feature_article',
    'openpublish_article',
    'openpublish_photo_gallery',
    'video',
  ),
);

// Participant API accounts
if (!array_key_exists('participant_api_accounts', $conf)) {
  $conf['participant_api_accounts'] = array();
}

$domain_array = array(
  'domain' => $services_domain,
  'key'    => $participant_api_accounts_key,
);

$conf['participant_api_accounts'] += array(
  'takepart'    => $domain_array,
  'pivot'       => $domain_array,
  'participant' => $domain_array,
);

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
    } else {
	 break;
    }
  }
}

/**
* Fast 404 settings:
*/
// This path may need to be changed if the fast 404 module is in a different location.
include_once('./sites/all/modules/contrib/fast_404/fast_404.inc');

# Disallowed extensions. Any extension in here will not be served by Drupal and
# will get a fast 404.
$conf['fast_404_exts'] = '/^(?!robots).*\.(txt|png|gif|jpe?g|css|js|ico|swf|flv|cgi|bat|pl|dll|exe|asp)$/i';

# Array of whitelisted URL fragment strings that conflict with fast_404.
$conf['fast_404_string_whitelisting'] = array('cdn/farfuture', '/advagg_');

# Default fast 404 error message.
$conf['fast_404_html'] = '<html xmlns="http://www.w3.org/1999/xhtml"><head><title>404 Not Found</title></head><body><h1>Not Found</h1><p>The page you are looking for may have moved. Please visit <a href="http://www.takepart.com">takepart.com</a> and use the search box for the information.</p></body></html>';

# Call the extension checking now. This will skip any logging of 404s.
fast_404_ext_check();
