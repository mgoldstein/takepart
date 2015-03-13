<?php

// Development & Staging Adobe Analytics Suite
$conf += array(
    'omniture_account_name' => 'takeparttakepartdev2',
    'dtm_script_src' => '//assets.adobedtm.com/1bfdeeddf2a7ac04657b15540f0e8de06d3ee618/satelliteLib-e72f040081d6d4caa0027d0ba1c74cd46d514484-staging.js',
);

// TAP and Services don't have an integration environment, point at
// QA by default or update settings.local.inc to point to local instances.
$conf += array(
    'takeaction_domain' => 'qa-tab.takepart.com',
    'services_domain' => 'qa-api.takepart.com',
);

// Development & Staging Facebook App ID
$conf += array('facebook_app_id' => '247137505296280');

// Turn off page compression and CSS and JS preprocessing

/* THE BELOW SHOULD NOT BE APART OF SETTINGS.PHP */
// $conf += array(
//   'page_compression' => FALSE,
//   'preprocess_css' => FALSE,
//   'preprocess_js' => FALSE,
// );
// Log signups for debugging
$conf += array('pm_signup_log' => TRUE);

// JWPlatform video import tag
$conf += array(
    'pm_jwplatform_auto_create_tag' => 'Admin: TP Auto Dev',
);


// Scream at the dev, maybe they'll fix something
ini_set('error_reporting', E_ALL & ~E_NOTICE);
