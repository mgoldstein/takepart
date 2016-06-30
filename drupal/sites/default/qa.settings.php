<?php

// Development & Staging Adobe Analytics Suite
$conf += array(
  'omniture_account_name' => 'takeparttakepartdev2',
  'dtm_script_src' => '//assets.adobedtm.com/1bfdeeddf2a7ac04657b15540f0e8de06d3ee618/satelliteLib-e72f040081d6d4caa0027d0ba1c74cd46d514484-staging.js',
);

// TAP and Services don't have an integration environment, point at
// QA by default or update settings.local.inc to point to local instances.
$conf += array(
  'takeaction_domain' => 'qa-takeaction.takepart.com',
  'services_domain' => 'qa-api.takepart.com',
  'tapembed_domain' => 'qa-tapembed.takepart.com',
);

// Development & Staging Facebook App ID
$conf += array('facebook_app_id' => '247137505296280');

// Log signups for debugging
$conf += array('pm_signup_log' => TRUE);

// JWPlatform video import tag
$conf += array(
  'pm_jwplatform_auto_create_tag' => 'Admin: TP Auto Dev',
);

// Shared Assets
$conf['shared_assets_path'] = '//s3.amazonaws.com/tab_assets/shared_assets_qa/';

// Scream at the dev, maybe they'll fix something
// ini_set('error_reporting', E_ALL & ~E_NOTICE);
// Solr Server settings
$conf['search_api_solr_overrides'] = array(
  'takepart_solr_production' => array(
    'name' => t('TakePart SOLR Production (QA settings)'),
    'options' => array(
	 'host' => '10.1.10.30',
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
    'qa-memcached.bxiq81.cfg.use1.cache.amazonaws.com:11211' => 'default',
  ),
  'memcache_key_prefix' => 'qa',
);

$conf['campaign_css_s3_path'] = 'https://s3.amazonaws.com/takepart-campaigns/dev/styles/';

$conf['disqus_id'] = 'takepartstage';
