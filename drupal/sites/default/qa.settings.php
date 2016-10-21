<?php

$APP_ENV               = $_SERVER['APP_ENV'];

// Adobe Analytics
$omniture_account_name = 'takeparttakepartdev2';
$dtm_script_src        = '//assets.adobedtm.com/1bfdeeddf2a7ac04657b15540f0e8de06d3ee618/satelliteLib-e72f040081d6d4caa0027d0ba1c74cd46d514484-staging.js';


// SMTP Configuration -- SYS-2054
// The PHPMailer used to use the local SMTP server, however, that's been
// an insurmountable challenge in Docker. Peter Ong cannot figure out how to
// run Sendmail inside of a container.

// While Postfix, a much simpler MTA, would be an easy drop-in replacement,
// he does not want to have different MTAs between containers and physical
// servers. And with Puppet, maintenance of the difference would hardly incur
// any cost in time and effort. That said, it still would be more elegant to
// simply configure Drupal to relay to Sendgrid directly.

// The default MTA in CentOS is Sendmail. All of our AWS EC2
// instances use Sendmail. Peter Ong will continue to figure out how to run
// Sendmail in a container, but he will no longer let this slow down the
// progress of our containerization project.

$smtp_host             = 'smtp.sendgrid.net';
$smtp_password         = 'mctMz73]#m&z43*nkw2,';
$smtp_port             = 587;
$smtp_username         = 'qa-takepart';

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

// Cloudinary Bucket Name
$cloudinary_bucket     = 'takepartqa';

//Setting Base URL
$base_protocol = empty($_SERVER['HTTPS']) || strtolower($_SERVER['HTTPS']) != 'on' ? 'http' : 'https';

$base_url = $base_protocol . '://qa.takepart.com';

// Scream at the dev, maybe they'll fix something
ini_set('error_reporting', E_ALL & ~E_NOTICE);
