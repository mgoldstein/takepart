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

// BlueHornet accounts
if (!array_key_exists('bluehornet_api_accounts', $conf)) {
  $conf['bluehornet_api_accounts'] = array();
}
$conf['bluehornet_api_accounts'] += array(
  'takepart' => array(
    'domain' => 'echo.bluehornet.com',
    'key' => '40465d9afd847a0e862b857e8e7387b8',
    'secret' => 'a00072e1755a2d2f797971742c97df45',
  ),
  'pivot' => array(
    'domain' => 'echo.bluehornet.com',
    'key' => 'c0cf51a9f440562b91727bab1293ff29',
    'secret' => '28606de9e00dabcbf5049f7b734ff724',
  ),
);
$conf += array('bluehornet_default_account' => 'takepart');

