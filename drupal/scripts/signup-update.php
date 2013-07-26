<?php

$actions = db_select('signature_node', 'n')
      ->fields('n', array('nid', 'bsd_form'))
      ->execute()
      ->fetchAllKeyed();

$all_errors = array();
foreach ($actions as $nid => $bsd_form) {
  if (!empty($bsd_form)) {
    $errors = array();

    $endpoint = signature_configure_signup_endpoint($bsd_form, 0, $errors);

    $endpoint->save();
    db_update('signature_node')
      ->fields(array(
        'pm_signup_endpoint_id' => $endpoint->getID(),
      ))
      ->condition('nid', $nid)
      ->execute();

    array_push($all_errors, $errors);
  }
}
