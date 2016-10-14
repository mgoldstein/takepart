<?php

define ('ENVIRONMENT', $_SERVER['APP_ENV']);

// Include the environment specific settings.
$env_settings = dirname(__FILE__) . '/' . ENVIRONMENT . '.settings.php';
if (file_exists($env_settings)) {
  include_once $env_settings;
}

// Common values between all environments
$facebook_app_id                 = '247137505296280';
$facebook_access_token           = '247137505296280%7CONdms_LoF5eJXZEUomO8gYNuW5A';
$cache_backends                  = 'sites/all/modules/contrib/memcache/memcache.inc';
$pm_jwplatform_auto_create_tag   = "Admin: TP Auto $APP_ENV";
$solr_name                       = "TakePart SOLR $APP_ENV settings";
$solr_port                       = 8080;
$solr_path                       = '/solr/takepart_core';
$takeaction_publisher_id         = 'd84909c52edcceb20c7bba62052b1b01';
$pm_jwplatform_api_key           = 'NnnOqH8r';
$pm_jwplatform_api_secret        = 'fJoeVtVS5YriI0Bnh8v6lo1i';
$pm_jwplatform_content_domain    = 'content.jwplatform.com';
$pm_jwplatform_content_dns_mask  = 'video.takepart.com';
$tp_video_player_account_token   = 'esP2FhWwEeODmBIxOUCPzg';
$tp_video_player_key             = 'xlvA/gqv5vAkINGetf3aFsus8xjtNRWt+WzQqA==';
$participant_api_accounts_key    = 'db73d53413afcf95324c6d2c0f584cfb';
$participant_api_default_account = 'takepart';
$database_name                   = 'takepart';
$database_port                   = 3306;
$database_driver                 = 'mysql';
$database_prefix                 = '';
