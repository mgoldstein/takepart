<?php

// Development & Staging Adobe Analytics Suite
$conf += array(
  'omniture_account_name' => 'takeparttakepartdev2',
  'dtm_script_src' => '//assets.adobedtm.com/1bfdeeddf2a7ac04657b15540f0e8de06d3ee618/satelliteLib-e72f040081d6d4caa0027d0ba1c74cd46d514484-staging.js',
);

// Development & Staging Facebook App ID
$conf += array('facebook_app_id' => '804910456185646');

// QA TAP and Services Integration
$conf += array(
  'takeaction_domain' => 'qa-tab.takepart.com',
  'services_domain' => 'qa-api.takepart.com',
);

// Log signups for debugging
$conf += array('pm_signup_log' => TRUE);

// General logging level
ini_set('error_reporting', E_ALL & ~E_NOTICE);

// JWPlatform video import tag
$conf += array(
  'pm_jwplatform_auto_create_tag' => 'Admin: TP Auto QA',
);
