<?php

// Development & Staging Adobe Analytics Suite
$conf += array(
  'omniture_account_name' => 'takeparttakepartdev2',
  'dtm_script_src' => '//assets.adobedtm.com/1bfdeeddf2a7ac04657b15540f0e8de06d3ee618/satelliteLib-67f52c9fb4acac0165b6ab3557a90e9fc355338e-staging.js',
);

// TAP and Services don't have an integration environment, point at
// QA by default or update settings.local.inc to point to local instances.
$conf += array(
  'takeaction_domain' => 'qa-tab.dev.takepart.com',
  'services_domain' => 'qa-api.takepart.com',
);

// Development & Staging Facebook App ID
$conf += array('facebook_app_id' => '804910456185646');

// Turn off page compression and CSS and JS preprocessing

$conf += array(
  'page_compression' => FALSE,
  'preprocess_css' => FALSE,
  'preprocess_js' => FALSE,
);

// Log signups for debugging
$conf += array('pm_signup_log' => TRUE);

// JWPlatform video import tag
$conf += array(
  'pm_jwplatform_auto_create_tag' => 'Admin: TP Auto Dev',
);

// Scream at the dev, maybe they'll fix something
ini_set('error_reporting', E_ALL & ~E_NOTICE);
