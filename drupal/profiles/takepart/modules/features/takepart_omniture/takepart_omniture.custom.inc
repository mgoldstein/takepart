<?php
function takepart_omniture_init() {
  // expouse the omniture_account_name to js as omniture.s_account
  $s_account = variable_get('omniture_account_name','takeparttakepartdev2');
  drupal_add_js(array('omniture' => array('s_account' => $s_account)), 'setting');
  drupal_add_js(drupal_get_path('module', 'takepart_omniture') . "/js/takepart_omniture.js");
}