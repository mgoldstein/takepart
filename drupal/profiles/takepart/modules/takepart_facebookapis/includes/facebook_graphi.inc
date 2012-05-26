<?php

function _takepart_facebookapis_get_facebook_cookie($app_id, $app_secret) {
  if ($_COOKIE['fbsr_' . $app_id] != '') {
    return _takepart_facebookapis_get_new_facebook_cookie($app_id, $app_secret);
  } else {
    return _takepart_facebookapis_get_old_facebook_cookie($app_id, $app_secret);
  }
}

function _takepart_facebookapis_get_old_facebook_cookie($app_id, $app_secret) {
  $args = array();
  parse_str(trim($_COOKIE['fbsr_' . $app_id], '\\"'), $args);
  ksort($args);
  $payload = '';
  foreach ($args as $key => $value) {
    if ($key != 'sig') {
      $payload .= $key . '=' . $value;
    }
  }
  if (md5($payload . $app_secret) != $args['sig']) {
    return null;
  }
  return $args;
}

function _takepart_facebookapis_get_new_facebook_cookie($app_id, $app_secret) {
  $signed_request = _takepart_facebookapis_parse_signed_request($_COOKIE['fbsr_' . $app_id], $app_secret);
  // $signed_request should now have most of the old elements
  $signed_request[uid] = $signed_request[user_id]; // for compatibility
  if (!is_null($signed_request)) {
    // the cookie is valid/signed correctly
    // lets change "code" into an "access_token"
    $access_token_response = _takepart_facebookapis_curl("https://graph.facebook.com/oauth/access_token?client_id=$app_id&redirect_uri=&client_secret=$app_secret&code=$signed_request[code]");
    parse_str($access_token_response);
    $signed_request[access_token] = $access_token;
    $signed_request[expires] = time() + $expires;
  }
  
//  print "Key/Access Token:". $signed_request[access_token] . "<br/>";
  
  return $signed_request;
}

function _takepart_facebookapis_curl($url) {
  $ch = curl_init();
  curl_setopt($ch, CURLOPT_URL, $url);
  curl_setopt($ch, CURLOPT_TIMEOUT, variable_get('fblogin_curl_timeout', '10'));
  curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
  curl_setopt($ch, CURLOPT_HEADER, 0);
  return curl_exec($ch);
}


function _takepart_facebookapis_parse_signed_request($signed_request, $secret) {
  list($encoded_sig, $payload) = explode('.', $signed_request, 2);

  // decode the data
  $sig = _takepart_facebookapis_base64_url_decode($encoded_sig);
  $data = json_decode(_takepart_facebookapis_base64_url_decode($payload), true);

  if (strtoupper($data['algorithm']) !== 'HMAC-SHA256') {
    error_log('Unknown algorithm. Expected HMAC-SHA256');
    return null;
  }

  // check sig
  $expected_sig = hash_hmac('sha256', $payload, $secret, $raw = true);
  if ($sig !== $expected_sig) {
    error_log('Bad Signed JSON signature!');
    return null;
  }

  return $data;
}

function _takepart_facebookapis_base64_url_decode($input) {
  return base64_decode(strtr($input, '-_', '+/'));
}