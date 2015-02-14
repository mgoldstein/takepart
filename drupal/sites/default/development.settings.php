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


// BlueHornet accounts
if (!array_key_exists('bluehornet_api_accounts', $conf)) {
  $conf['bluehornet_api_accounts'] = array();
}
$conf['bluehornet_api_accounts'] += array(
  'takepart' => array(
    'domain' => 'bluehornet-proxy.dev.takepart.com:8180',
    'key' => '40465d9afd847a0e862b857e8e7387b8',
    'secret' => 'a00072e1755a2d2f797971742c97df45',
  ),
  'pivot' => array(
    'domain' => 'bluehornet-proxy.dev.takepart.com:8180',
    'key' => 'c0cf51a9f440562b91727bab1293ff29',
    'secret' => '28606de9e00dabcbf5049f7b734ff724',
  ),
);
$conf += array('bluehornet_default_account' => 'takepart');
