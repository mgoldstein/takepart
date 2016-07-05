<?php

$APP_ENV               = $_SERVER['APP_ENV'];

// Adobe Analytics 
$omniture_account_name = 'takeparttakepartdev2';
$dtm_script_src        = '//assets.adobedtm.com/1bfdeeddf2a7ac04657b15540f0e8de06d3ee618/satelliteLib-e72f040081d6d4caa0027d0ba1c74cd46d514484-staging.js';

//TAP Integration
$takeaction_domain     = "$APP_ENV-takeaction.takepart.com";
$services_domain       = "$APP_ENV-api.takepart.com";
$tapembed_domain       = "$APP_ENV-tapembed.takepart.com";

$pm_signup_log         = TRUE;

// Shared assets path
$shared_assets_path    = "//s3.amazonaws.com/tab_assets/shared_assets_$APP_ENV/";

// Solr settings
$solr_host             = '10.1.10.30';

// Elasticcache
$memcache_host         = "$APP_ENV-memcached.bxiq81.cfg.use1.cache.amazonaws.com";
$memcache_port         = 11211;

// Campain CSS s3 path
$campaign_css_s3_path  = "https://s3.amazonaws.com/takepart-campaigns/dev/styles/";

// Disqus account
$disqus_id             = 'takepartstage';

// Database settings
$database_username     = 'root';
$database_password     = 'master_user_password';
$database_host         = 'qaphp01.ctvzddorowz4.us-east-1.rds.amazonaws.com';
$database_slave_host   = 'qaphp01-read.ctvzddorowz4.us-east-1.rds.amazonaws.com';

// Scream at the dev, maybe they'll fix something
ini_set('error_reporting', E_ALL & ~E_NOTICE);
