<?php


function takepart_newsletter_signup_bulk_feature_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'email_batch_load_node_form') {
    drupal_add_css(Drupal_get_path("module", 'takepart_newsletter_signup_bulk_feature'). "/theme/email-batch-load-form.css");
  }
}

