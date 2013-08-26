<?php
$databases = array (
  'default' =>
    array (
      'default' =>
        array (
          'database' => 'takepart',
          'username' => 'root',
          'password' => 'root',
          'host' => 'localhost',
          'port' => '',
          'driver' => 'mysql',
          'prefix' => '',
        ),
    ),
);
$conf['omniture_account_name'] = 'takeparttakepartdev2';
ini_set('error_reporting', !E_NOTICE & !E_WARNING);
ini_set('memory_limit','512M');

// The session sharing cookie.
$conf['takeaction_session_cookie_domain'] = '.takepart.com';

// The user action tracking cookie
$conf['takeaction_action_cookie_domain'] = '.takepart.com';

// Backend action history API
$conf['takeaction_action_api_url'] = 'http://tab2.dev.takepart.com/api/';

// Integration URLs and Pages
$conf['takeaction_button_js_url'] = 'http://tab2.dev.takepart.com/assets/publisher.js?v=3.7';
$conf['takeaction_more_actions_url'] = 'http://tab2.dev.takepart.com/similar_actions';
$conf['takeaction_dashboard_url'] = 'http://tab2.dev.takepart.com/';

// Action feed
$conf['takeaction_feed_content_domain'] = 'tab2.dev.takepart.com';
$conf['takeaction_tab_api_url'] = 'http://tab2.dev.takepart.com/api/actions';
$conf['takeaction_tab_security_token'] = '14f25ea4822e6d4ea1d4e52dbfcc4bee';