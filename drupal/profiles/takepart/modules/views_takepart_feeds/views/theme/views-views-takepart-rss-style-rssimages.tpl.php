<?php
/**
 * Template file for rssimage feed
 */
  if (isset($view->override_path)) {       // inside live preview
    print htmlspecialchars($xml);
  }
  elseif ($options['using_views_api_mode']) {     // We're in Views API mode.
    print $xml;
  }
  else {
    $u_agent = $_SERVER['HTTP_USER_AGENT'];
    /*Render as XML for browsers that don't have built in RSS support:
    if(preg_match('/Chrome/i',$u_agent)) {
      drupal_add_http_header('Content-Type', 'text/xml; charset=utf-8');
    } elseif(preg_match('/Safari/i',$u_agent)) {
      drupal_add_http_header('Content-Type', 'text/xml; charset=utf-8');   
    } else { */
      drupal_add_http_header('Content-Type', 'application/rss+xml; charset=utf-8');
	 // drupal_add_http_header('Content-Type', 'text/xml');
    //}
    print $xml;
    exit;
  }