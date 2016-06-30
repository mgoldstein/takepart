<?php

// Production Adobe Analytics Suite
$conf += array(
  // 'omniture_account_name' => 'takepartprod',
  // 'dtm_script_src' => '//assets.adobedtm.com/1bfdeeddf2a7ac04657b15540f0e8de06d3ee618/satelliteLib-67f52c9fb4acac0165b6ab3557a90e9fc355338e.js',
    'omniture_account_name' => 'takepart-dtm-test',
    'dtm_script_src' => '//assets.adobedtm.com/1bfdeeddf2a7ac04657b15540f0e8de06d3ee618/satelliteLib-e72f040081d6d4caa0027d0ba1c74cd46d514484.js',
);

// Production Facebook App ID
$conf += array('facebook_app_id' => '247137505296280');

// Production TAP and Services Integration
$conf += array(
  'takeaction_domain' => 'takeaction.takepart.com',
  'services_domain' => 'api.takepart.com',
  'tapembed_domain' => 'tapembed.takepart.com',
);

// Do not log signups in production
$conf += array('pm_signup_log' => FALSE);

// JWPlatform video import tag
$conf += array(
  'pm_jwplatform_auto_create_tag' => 'Admin: TP Auto',
);

// Tone down the logging
ini_set('error_reporting', E_ALL & ~E_NOTICE & ~E_WARNING & ~E_DEPRECATED);

// Shared Assets
$conf['shared_assets_path'] = '//s3.amazonaws.com/tab_assets/shared_assets/';

// Solr Server settings
$conf['search_api_solr_overrides'] = array(
  'takepart_solr_production' => array(
    'name' => t('TakePart SOLR (Production settings)'),
    'options' => array(
	 'host' => 'prod-solr.takepart.com', // new host
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
    'prod-memcached.bxiq81.cfg.use1.cache.amazonaws.com:11211' => 'default',
  ),
  'memcache_key_prefix' => 'prod',
);

$conf['campaign_css_s3_path'] = 'https://s3.amazonaws.com/takepart-campaigns/prod/styles/';

$conf['disqus_id'] = 'takepart';
