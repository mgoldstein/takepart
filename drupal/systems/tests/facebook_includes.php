<?php

function get_facebook_cookie($app_id, $app_secret) {
  if ($_COOKIE['fbsr_' . $app_id] != '') {
    return get_new_facebook_cookie($app_id, $app_secret);
  } else {
    return get_old_facebook_cookie($app_id, $app_secret);
  }
}


function get_old_facebook_cookie($app_id, $app_secret) {
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

function get_new_facebook_cookie($app_id, $app_secret) {
  $signed_request = parse_signed_request($_COOKIE['fbsr_' . $app_id], $app_secret);
  // $signed_request should now have most of the old elements
  $signed_request[uid] = $signed_request[user_id]; // for compatibility
  if (!is_null($signed_request)) {
    // the cookie is valid/signed correctly
    // lets change "code" into an "access_token"
    $access_token_response = file_get_contents("https://graph.facebook.com/oauth/access_token?client_id=$app_id&redirect_uri=&client_secret=$app_secret&code=$signed_request[code]");
    parse_str($access_token_response);
    $signed_request[access_token] = $access_token;
    $signed_request[expires] = time() + $expires;
  }
  
//  print "Key/Access Token:". $signed_request[access_token] . "<br/>";
  
  return $signed_request;
}

function parse_signed_request($signed_request, $secret) {
  list($encoded_sig, $payload) = explode('.', $signed_request, 2);

  // decode the data
  $sig = base64_url_decode($encoded_sig);
  $data = json_decode(base64_url_decode($payload), true);

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

function base64_url_decode($input) {
  return base64_decode(strtr($input, '-_', '+/'));
}

?>
