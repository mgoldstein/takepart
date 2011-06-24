<?php

function takepart_newsletter_signup_bulk_feature_drush_command() {

  $items = array();

  $items['tp-nl-queue-next'] = array(
    'callback' => 'drush_tp_nl_queue_next',
    'description' => dt('populates queue'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL, 
    'drupal dependencies' => array('takepart_newsletter_signup_bulk_feature'),
  );
  $items['tp-nl-process-items'] = array(
    'callback' => 'drush_tp_nl_process_items',
    'description' => dt('process set amount of items from the queue'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL, 
    'drupal dependencies' => array('takepart_newsletter_signup_bulk_feature'),
  );
  $items['tp-nl-generate-next'] = array(
    'callback' => 'drush_tp_nl_generate_next',
    'description' => dt('Generate report for next node finished'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL, 
    'drupal dependencies' => array('takepart_newsletter_signup_bulk_feature'),
  );
  return $items;
}

function drush_tp_nl_queue_next() {
  takepart_newsletter_signup_bulk_feature_populate_queue_next_node();
}

function drush_tp_nl_process_items() {
  takepart_newsletter_signup_bulk_feature_process_items();
}
function drush_tp_nl_generate_next() {
  takepart_newsletter_signup_bulk_feature_generate_next_report();
}

function takepart_newsletter_signup_bulk_feature_drush_help($section) {
  switch($section) {
    case 'drush:tp-populate-queue':
      return dt("Will pull the next bulk import file and load it in the queue");
      break;
  }
}
