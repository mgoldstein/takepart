<?php

/**
 * Saves email/campaign id combo to the database
 *
 * @param $email string - email address
 * @param $campaign_id string - pluris campaign id for subscription
 * @param $direct_save string - is this using the webservice
 *
 * @return string - empty if success, message if error
 */
function takepart_newsletter_save_campaign($email, $campaign_id, $action = 's', $source = '', $send_welcome = 'y') {
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
    watchdog('newsletter service', 'General error: %error for email: %email, campaign id: %campaign', array('%error' => $ex->getMessage(), '%email' => $email, '%campaign' => $campaign));
    $message = $action == 's' ? t('Problem saving email, please try again later.') : t('There was a problem unsubscribing. Please try again later.');
    
    return array('status' => 0, 'message' => $message);
  } 
}


/**
 * Remove email/campaign entry
 *
 * @param $email string - email address
 * @param $campaign_id string - pluris campaign id for subscription
 *
 * return string - message if error, empty string if not
 */
function takepart_newsletter_delete_campaign($email, $campaign_id) {
  $all_code = variable_get('takepart_newsletter_signup_unsubscribe_all_campaign_code', 'alltpnl');
  
  if ($campaign_id == $all_code) {
    
    $success = 0;
    $message = '';
    
    try {
      $ws_url = variable_get('takepart_newsletter_signup_pluris_unsubscribe_url', 'https://digitalsubscriptions.plurismarketing.com/unsubscribeAll.php');
      $params = array(
        'e'=>$email,
        'r'=>variable_get('takepart_newsletter_signup_pluris_requester', 'tp'),
      );
      $url = url($ws_url, array('query'=>$params));
       
      $pluris_code = drupal_http_request($url, array(), 'GET');
  
      if ($pluris_code && $pluris_code->data) {
        $xml = simplexml_load_string($pluris_code->data);
        if ((string)$xml->returnCode) {
          $message = (string)$xml->returnString;
        }
        $xml = null;
        
        $record = new stdClass();
		$record->mail = $email;
		$record->status = 'u';
		$record->unsubscribe_date = time();

		db_query("UPDATE {tp_newsletter_signups} SET status = 'u', unsubscribe_date = %d WHERE mail = '%s'", time(), $email);
        $success = 1;
      }
      else {
        $message = t('No response from pluris');
      }
    }
    catch(Exception $ex) {
      $message = t('Problem connecting to pluris');
      watchdog('newsletter service', 'Error connecting to pluris. Error: %error for email: %email, campaign id: %campaign', array('%error' => $ex->getMessage(), '%email' => $email, '%campaign' => $campaign));
    }
    return array('status' => $success, 'message' => $message); 
  }
  
  return takepart_newsletter_save_campaign($email, $campaign_id, 'u');
}


/**
 *  Look up the campaign node id based on pluris campaign id
 *
 *  @param $campaign_id string - campaign id from pluris
 *
 *  @return int - node id from drupal node
 */
function takepart_newsletter_signup_get_campaign_nid($campaign_id) {
  return db_result(db_query("SELECT n.nid FROM {node} n INNER JOIN {content_type_newsletter_campaign} c ON n.vid = c.vid WHERE c.field_newsletter_campaign_id_value = '%s'", $campaign_id));
}


/**
 * Query the DB to determine if user is site user
 *
 * @param $email string - email address of the user to lookup
 *
 * @return int - uid if found
 */
function takepart_newsletter_signup_is_drupal_user($email) {
  return db_result(db_query("SELECT uid FROM {users} WHERE mail = '%s'", $email));
}


/**
 * Query the DB to determine if email is db
 *
 * @param $email string - email address of the user to lookup
 *
 * @return string - mail if found
 */
function takepart_newsletter_signup_is_email_recorded($email) {
  return db_result(db_query("SELECT mail FROM {tp_newsletter_signups} WHERE mail = '%s'", $email));
}


/**
 * Update records for a given email, with the given uid
 *
 * @param $email string - email address
 * @param $email int - user id
 *
 */
function takepart_newsletter_signup_add_uid_to_email_records($email, $uid) {
  db_query("UPDATE {tp_newsletter_signups} SET uid = %n WHERE mail = '%s'", $uid, $email);
}


/**
 * Query the DB to determine if email/campaign id combo exists
 *
 * @param $email string - email address of the user to lookup
 * @param $campaign_id string - email address of the user to lookup
 *
 * @return string - current status if it exists
 */
function takepart_newsletter_signup_is_email_recorded_for_campaign($email, $campaign_id = '') {
  return db_result(db_query("SELECT status FROM {tp_newsletter_signups} WHERE mail = '%s' AND campaign_id = '%s'", $email, $campaign_id));
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
function takepart_newsletter_signup_alert_pluris($email, $campaign_id, $action = 's',$source = '', $send_welcome = 'y') {
  $message = '';
  try {
    $ws_url = variable_get('takepart_newsletter_signup_pluris_url', 'https://tp_email.plurismarketing.com/subscribeRequest.php');
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
    watchdog('newsletter service', 'Error connecting to pluris. Error: %error for email: %email, campaign id: %campaign', array('%error' => $ex->getMessage(), '%email' => $email, '%campaign' => $campaign));
  }
  
  return $message;
}
