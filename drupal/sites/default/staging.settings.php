<?php

// Development & Staging Adobe Analytics Suite
$conf += array(
  'omniture_account_name' => 'takeparttakepartdev2',
  'dtm_script_src' => '//assets.adobedtm.com/1bfdeeddf2a7ac04657b15540f0e8de06d3ee618/satelliteLib-e72f040081d6d4caa0027d0ba1c74cd46d514484-staging.js',
);

// Development & Staging Facebook App ID
$conf += array('facebook_app_id' => '247137505296280');

// QA TAP and Services Integration
$conf += array(
  'takeaction_domain' => 'stage-takeaction.takepart.com',
  'services_domain' => 'stage-api.takepart.com',
  'tapembed_domain' => 'stage-tapembed.takepart.com',
);

// Log signups for debugging
$conf += array('pm_signup_log' => TRUE);

// General logging level
ini_set('error_reporting', E_ALL & ~E_NOTICE);

// JWPlatform video import tag
$conf += array(
  'pm_jwplatform_auto_create_tag' => 'Admin: TP Auto QA',
);

// Shared Assets
$conf['shared_assets_path'] = '//s3.amazonaws.com/tab_assets/shared_assets_stage/';

// Solr Server settings
$conf['search_api_solr_overrides'] = array(
  'takepart_solr_production' => array(
    'name' => t('TakePart SOLR Production (Stage settings)'),
    'options' => array(
	 //'host' => '10.1.15.50', // old host
	 'host' => '10.1.15.30', // new host
	 'port' => 8080,
	 'path' => '/solr/takepart_core',
    ),
  ),
);

// Elasticache
$conf['cache_backends'][] = 'sites/all/modules/contrib/memcache/memcache.inc';
$conf += array(
  'cache_default_class' => 'MemCacheDrupal',
  'cache_class_cache_form' => 'DrupalDatabaseCache',
  'page_cache_without_database' => TRUE,
  'page_cache_invoke_hooks' => FALSE,
  'lock_inc' => 'sites/all/modules/contrib/memcache/memcache-lock.inc',
  'memcache_stampede_protection' => TRUE,
  'memcache_servers' => array(
    'stage-memcached.bxiq81.cfg.use1.cache.amazonaws.com:11211' => 'default',
  ),
  'memcache_key_prefix' => 'stage',
);

$conf['campaign_css_s3_path'] = 'https://s3.amazonaws.com/takepart-campaigns/dev/styles/';
