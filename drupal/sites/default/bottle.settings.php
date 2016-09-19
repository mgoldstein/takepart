<?php

$APP_ENV               = $_SERVER['APP_ENV'];

// Adobe Analytics
$omniture_account_name = 'takeparttakepartdev2';
$dtm_script_src        = '//assets.adobedtm.com/1bfdeeddf2a7ac04657b15540f0e8de06d3ee618/satelliteLib-e72f040081d6d4caa0027d0ba1c74cd46d514484-staging.js';

//TAP Integration
$takeaction_domain     = "dev-takeaction.takepart.com";
$services_domain       = "dev-api.takepart.com";
$tapembed_domain       = "dev-tapembed.takepart.com";

$pm_signup_log         = TRUE;

// Shared assets path
$shared_assets_path    = "//s3.amazonaws.com/tab_assets/shared_assets_dev/";

// Solr settings
$solr_host             = '10.1.5.30';

// Elasticcache
$memcache_host         = "192.168.56.180";
$memcache_port         = 11211;

// Campain CSS s3 path
$campaign_css_s3_path  = "https://s3.amazonaws.com/takepart-campaigns/dev/styles/";

// Database settings
$database_username     = 'root';
$database_password     = 'master_user_password';
$database_host         = '192.168.56.180';
$database_slave_host   = '192.168.56.180';

// Cloudinary Bucket Name
$cloudinary_bucket = 'takepartprod';

// Scream at the dev, maybe they'll fix something
ini_set('error_reporting', E_ALL & ~E_NOTICE);
