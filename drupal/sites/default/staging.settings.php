<?php

// Development & Staging Adobe Analytics Suite
$conf += array(
  'omniture_account_name' => 'takeparttakepartdev2',
  'dtm_script_src' => '//assets.adobedtm.com/1bfdeeddf2a7ac04657b15540f0e8de06d3ee618/satelliteLib-e72f040081d6d4caa0027d0ba1c74cd46d514484-staging.js',
);

// Development & Staging Facebook App ID
$conf += array('facebook_app_id' => '247137505296280');

// QA TAP and Services Integration
$conf += array(
  'takeaction_domain' => 'qa-takeaction.takepart.com',
  'services_domain' => 'qa-api.takepart.com',
  // 'takeaction_domain' => 'stage-takeaction.takepart.com',
  // 'services_domain' => 'stage-api.takepart.com',
  );

// TAP Integration
$conf += array(
  'takeaction_widget_host' => "https://{$conf['takeaction_domain']}",
  'takeaction_influence_overlay_js' => "//{$conf['takeaction_domain']}/assets/influence.js",
  'signature_action_import_tap_domain' => "{$conf['takeaction_domain']}",
  'signature_import_feed' => "http://{$conf['takeaction_domain']}/api/actions",
  'takeaction_publisher_id' => 'd84909c52edcceb20c7bba62052b1b01',
  'takeaction_widget_script' => '/assets/publisher.js?v=3.7',
  'takeaction_awareness_script' => "//{$conf['takeaction_domain']}/assets/awareness.js",
);
  
// Log signups for debugging
$conf += array('pm_signup_log' => TRUE);

// General logging level
ini_set('error_reporting', E_ALL & ~E_NOTICE);

// JWPlatform video import tag
$conf += array(
  'pm_jwplatform_auto_create_tag' => 'Admin: TP Auto QA',
);

// Shared Assets
$conf['shared_assets_path'] = '//s3.amazonaws.com/tab_assets/shared_assets_stage/';

// Solr Server settings
$conf['search_api_solr_overrides'] = array(
  'takepart_solr_production' => array(
    'name' => t('TakePart SOLR Production (Stage settings)'),
    'options' => array(
      'host' => '10.1.15.30',
      'port' => 8080,
      'path' => '/solr/takepart_core',
    ),
  ),
);
