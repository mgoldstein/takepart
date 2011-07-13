<?php
/**
 * Valide the form values
 *
 * @param $form array - raw post values
 *
 * @return string - message if error, empty string if not
 */
function _newsletter_signup_email_check(&$form) {
  if (!valid_email_address($form['email'])) {
    return t('Invalid address, please try again');
  }
  
  $form['email'] = check_plain($form['email'] );
  $form['campaign_id'] = check_plain($form['campaign_id']);
  
  return '';
}

/**
 * Ajax form handler
 * returns a JSON string 
 */     
function _newsletter_signup_form_submit_from_ajax() { 
  $form = $_POST;
  
  $email = $form['email'];
  $campaign_id = $form['campaign_id'];
  //$message = _newsletter_signup_email_check($form);
  
  // if email is BAD
  if ($message) {
    print drupal_json_output(array(0, $message));
    exit();
  }
  
  $result = _save_campaign_signup($email, $campaign_id, 's');
  //$result = _save_campaign_signup($test_email, $test_camp, 's');
  
  if ($result['status'] == 1 ) {
    // loolup entity by campaign id
    $query = new EntityFieldQuery();
    $db_result = $query->entityCondition('entity_type', 'newsletter_campaign')
                    ->propertyCondition('campaign_id', (int)$campaign_id, '=')
                    ->execute();
    $ncids = array_keys($db_result['newsletter_campaign']);
    $camps = entity_load('newsletter_campaign', $ncids);
    // i hate this.
    $camp = $camps[$ncids[0]];
    $result = array('status' => $result['status'], 'message' => $camp->thankyou_message);
  }

  print drupal_json_output($result);
  exit();
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
  
  try {
  
    // contact Pluris first, since it is the 'master'
    $message = _newsletter_signup_alert_pluris($record->mail, $record->campaign_id, $record->status, $record->source, $send_welcome);
    $message = '';
    if (!$message) {
      $record->uid = _is_signee_drupal_user($record->mail);
      if (!$record->uid) {
        $record->uid = 0;
      }
 
      // If we have a row and the action is different the the status update the status
      $status = _is_email_recorded_for_campaign($record->mail, $record->campaign_id);
      
      if ($status) {
        if ($status != $record->status) {
          drupal_write_record("newsletter_signups", $record, array('mail', 'campaign_id'));
          $success = 1; 
        }
        else {
          $message = $status == 's' ? t('You are already subscribed.') : t('You are already unsubscribed.');
        }
      }
      // does not exist
      else {
        drupal_write_record("newsletter_signups", $record);
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


/**
 * Send a 'subscribe' or 'unsubscribe' message to pluris
 *
 * @param $email string - email address of the user to lookup
 * @param $campaign_id string - pluris campaign id
 * @param $action string - 's' for subscribe, 'u' for unsubscribe
 *
 * @return string - empty if no problems, otherwise error message
 */
function _newsletter_signup_alert_pluris($email, $campaign_id, $action = 's',$source = '', $send_welcome = 'y') {
  $message = '';
  try {
    $ws_url = variable_get('takepart_newsletter_signup_pluris_url', 'https://digitalsubscriptions.plurismarketing.com/subscribeRequest.php');
    $params = array(
     'e'=>$email,
     'a'=>$action,
     'c'=>$campaign_id,
     'r'=>variable_get('takepart_newsletter_signup_pluris_requester', 'tp'),
     'w'=>$send_welcome,
     's'=>$source
    );
    if (!$source) {
      unset($params['s']);
    }
    $url = url($ws_url, array('query'=>$params));
    $pluris_code = drupal_http_request($url, array(), 'GET');
  
    if ($pluris_code && $pluris_code->data) {
      $xml = simplexml_load_string($pluris_code->data);
      if ((string)$xml->returnCode) {
        $message = (string)$xml->returnString;
      }
      $xml = null;
    }
    else {
      $message = t('No response from pluris');
    }
  }
  catch(Exception $ex) {
    $message = t('Problem connecting to pluris');
    watchdog('newsletter service', 'Error connecting to pluris. Error: %error for email: %email, campaign id: %campaign', 
      array('%error' => $ex->getMessage(), '%email' => $email, '%campaign' => $campaign));
  }
  
  return $message;
}

/**
 * Query the DB to determine if user is site user
 *
 * @param $email string - email address of the user to lookup
 *
 * @return int - uid if found
 */
function _is_signee_drupal_user($email) {
  $query = db_query("SELECT uid FROM {users} WHERE mail = ?", array($email));
  return $query->fetchField();
}


/**
 * Query the DB to determine if email/campaign id combo exists
 *
 * @param $email string - email address of the user to lookup
 * @param $campaign_id string - email address of the user to lookup
 *
 * @return string - current status if it exists
 */
function _is_email_recorded_for_campaign($email, $campaign_id = '') {
  $result = db_query("SELECT status FROM {newsletter_signups} WHERE mail = ? AND campaign_id = ?", array($email, $campaign_id));
  return $result->fetchField();
}

function _newsletter_local_signup($email, $campaign_id) {
  
}

