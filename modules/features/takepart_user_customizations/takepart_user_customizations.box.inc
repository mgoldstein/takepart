<?php
/**
 * @file
 * takepart_user_customizations.box.inc
 */

/**
 * Implements hook_default_box().
 */
function takepart_user_customizations_default_box() {
  $export = array();

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'user_not_a_member_join';
  $box->plugin_key = 'simple';
  $box->title = 'Not a member?';
  $box->description = 'A quick link for non-registered users to the registration page';
  $box->options = array(
    'body' => '<div class="boxes-box-content"><p>Members can participate in discussions surrounding TakePart.com content for no obligation.</p>
<div id="join-login-box">
<ul id="user-nav">
<li><a href="/user/register" class="join-takepart">JOIN</a></li>
</ul>
</div> 
</div>',
  );
  $export['user_not_a_member_join'] = $box;

  return $export;
}
