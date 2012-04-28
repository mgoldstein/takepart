<?php 

define('FACEBOOK_APP_ID', '247137505296280');
define('FACEBOOK_APP_SECRET', '9278ba54095f2994812790292750a696');
include("facebook_includes.php"); 

error_reporting(0);

$cookie = get_facebook_cookie(FACEBOOK_APP_ID, FACEBOOK_APP_SECRET);
$user = json_decode(file_get_contents('https://graph.facebook.com/me?access_token=' . $cookie['access_token']));

echo print_r($user);

?>
