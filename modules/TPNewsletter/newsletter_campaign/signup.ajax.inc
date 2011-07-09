<?php

/**
 * Ajax form handler
 * returns a JSON string 
 */      
function _newsletter_signup_form_submit_from_ajax() { 
  $form = $_POST;
  
  $message = _newsletter_signup_form_validate_from_ajax($form);
  
  if ($message) {
    print drupal_json_output(array(0, $message));
    exit();
  }
   
  $email = $form['email'];
  $campaign_id = $form['campaign_id'];
  
  if (!variable_get('takepart_newsletter_signup_client_direct_save', 0)) {
    $result = takepart_newsletter_signup_client_call_webservice($email, $campaign_id);
  } 
  else {
    $result = _save_campaign_signup($email, $campaign_id, 's');
  }
  if ($result['status'] == 1 ) {
    $nid = takepart_newsletter_signup_client_get_campaign_nid($campaign_id);
    
    // switch to entity
    if ($nid) {
      $campaign = node_load($nid);
      $message = $campaign->field_newsletter_thanks_text[0]['value'];
    }

    $result = array('status' => $result['status'], 'message' => $message);
  }
  print drupal_json_output($result);
  
  exit();
} 


/**
 * Valide the form values
 *
 * @param $form array - raw post values
 *
 * @return string - message if error, empty string if not
 */
function _newsletter_signup_form_validate_from_ajax(&$form) {

  if (!valid_email_address($form['email'])) {
    return t('Invalid address, please try again');
  }
  
  $form['email'] = check_plain($form['email'] );
  $form['campaign_id'] = check_plain($form['campaign_id']);
  
  return '';
}

/**
 * Saves email/campaign id combo to the database
 *
 * @param $email string - email address
 * @param $campaign_id string - pluris campaign id for subscription
 * @param $direct_save string - is this using the webservice
 *
 * @return string - empty if success, message if error
 */
function _save_campaign_signup($email, $campaign_id, $action = 's', $source = '', $send_welcome = 'y') {
  $record = new stdClass();
  $record->mail = $email;
  $record->campaign_id = $campaign_id;
  $record->status = $action;
  $record->source = $source;
  switch ($action) {
    case 's' : $record->subscribe_date = time(); break;
    case 'u' : $record->unsubscribe_date = time(); break;
  }

  $success = 0;
  //drupal_set_message(json_encode($record));
  
  try {
  
    // contact Pluris first, since it is the 'master'
    $message = takepart_newsletter_signup_alert_pluris($record->mail, $record->campaign_id, $record->status, $record->source, $send_welcome);

    if (!$message) {
      $record->uid = takepart_newsletter_signup_is_drupal_user($record->mail);
      if (!$record->uid) {
        $record->uid = 0;
      }
 
      // If we have a row and the action is different the the status update the status
      if ($status = takepart_newsletter_signup_is_email_recorded_for_campaign($record->mail, $record->campaign_id)) {
        if ($status != $record->status) {
          print 'Update';
          drupal_write_record("tp_newsletter_signups", $record, array('mail', 'campaign_id'));
          $success = 1; 
        }
        else {
          $message = $status == 's' ? t('You are already subscribed.') : t('You are already unsubscribed.');
        }
      }
      else {
        print 'Insert';
        drupal_write_record("tp_newsletter_signups", $record);
        $message = 'success';
        $success = 1; 
      }
    }
      
    return array('status' => $success, 'message' => $message);
  }
  catch(Exception $ex) {
    watchdog('newsletter service', 'General error: %error for email: %email, campaign id: %campaign', 
      array('%error' => $ex->getMessage(), '%email' => $email, '%campaign' => $campaign)
    );
    $message = $action == 's' ? t('Problem saving email, please try again later.') : t('There was a problem unsubscribing. Please try again later.');
    
    return array('status' => 0, 'message' => $message);
  } 
}

