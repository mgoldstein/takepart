<?php

// Production Adobe Analytics Suite
$conf += array(
  'omniture_account_name' => 'takepartprod',
  'dtm_script_src' => '//assets.adobedtm.com/1bfdeeddf2a7ac04657b15540f0e8de06d3ee618/satelliteLib-67f52c9fb4acac0165b6ab3557a90e9fc355338e.js',
);

// Production Facebook App ID
$conf += array('facebook_app_id' => '247137505296280');

// Production TAP and Services Integration
$conf += array(
  'takeaction_domain' => 'takeaction.takepart.com',
  'services_domain' => 'accounts.takepart.com',
);

// Do not log signups in production
$conf += array('pm_signup_log' => FALSE);

// JWPlatform video import tag
$conf += array(
  'pm_jwplatform_auto_create_tag' => 'Admin: TP Auto',
);

// Tone down the logging
ini_set('error_reporting', E_ALL & ~E_NOTICE & ~E_WARNING & ~E_DEPRECATED);

// Always have set the drupal private key
$drupal_hash_salt = '59e4eeebbe8724ee6725901b7095082b6584db81239939be778fa58cfe32777c';
$conf['drupal_private_key'] = '2ouRrHH1wfSvtzOfDZ2hpBVX92Z_tXhvG-Yl3BGl8Ek';
