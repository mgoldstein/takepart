<?php

// Grant all newsletter permissions to administrators
$permissions = array();
foreach (newsletter_campaign_permission() as $perm => $desc) {
  $permissions[$perm] = 1;
}
foreach (array(6, 7) as $rid) {
  user_role_change_permissions($rid, $permissions);
}

// Update the bsd form and field mappings
$mapping = array(
  10 => array('bsd_form_id' =>  5, 'bsd_field_id' =>  52),
  11 => array('bsd_form_id' =>  8, 'bsd_field_id' =>  94),
  18 => array('bsd_form_id' =>  0, 'bsd_field_id' =>   0),
  19 => array('bsd_form_id' => 10, 'bsd_field_id' => 122),
  20 => array('bsd_form_id' =>  9, 'bsd_field_id' => 108),
  21 => array('bsd_form_id' =>  3, 'bsd_field_id' =>  24),
  24 => array('bsd_form_id' =>  6, 'bsd_field_id' =>  66),
  25 => array('bsd_form_id' =>  7, 'bsd_field_id' =>  80),
  26 => array('bsd_form_id' => 11, 'bsd_field_id' => 138),
  27 => array('bsd_form_id' =>  4, 'bsd_field_id' =>  38),
  31 => array('bsd_form_id' => 16, 'bsd_field_id' => 220),
);
foreach ($mapping as $ncid => $fields) {
  // Update all the newsletter signup form mappings
  db_update('newsletter_campaign')
    ->fields($fields)
    ->condition('ncid', $ncid, '=')
    ->execute();
} 

// Rebuild the menu router
menu_rebuild();
