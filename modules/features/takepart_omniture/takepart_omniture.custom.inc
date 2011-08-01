<?php
function takepart_omniture_init() {
  // expouse the omniture_account_name to js as omniture.s_account
 $s_account = variable_get('omniture_account_name','takeparttakepartdev2');
 drupal_add_js(array('omniture' => array('s_account' => $s_account)), 'setting');
}