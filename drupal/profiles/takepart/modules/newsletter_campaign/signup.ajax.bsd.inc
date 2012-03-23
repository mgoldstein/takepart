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
  $form['signup_form_id'] = check_plain($form['signup_form_id']);

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
  $signup_form_id = $form['signup_form_id'];

  //$message = _newsletter_signup_email_check($form);

  // if email is BAD
  if ($message) {
    print drupal_json_output(array(0, $message));
    exit();
  }

  $result = _save_campaign_signup($email, $campaign_id, 's', null, null, $signup_form_id);
  //$result = _save_campaign_signup($test_email, $test_camp, 's');

  if ($result['status'] == 1 ) {
    // lookup entity by campaign id
    $query = new EntityFieldQuery();
    $db_result = $query->entityCondition('entity_type', 'newsletter_campaign')
    ->propertyCondition('campaign_id', $campaign_id, '=')
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

function _save_campaign_signup($email, $campaign_id, $action = 's', $source = '', $send_welcome = 'y', $signup_form_id) {
  $success = 0;
  try {
    $message = _newsletter_signup_alert_bsd($email, $campaign_id, $action, $source, $send_welcome, $signup_form_id);
    if ((!$message) || (strlen($message)==0)) {
      $success = 1;
    } else {
      $success = 0;
    }
    return array('status' => $success, 'message' => $message);
  }
  catch(Exception $ex) {
    watchdog('newsletter service', 'General error: %error for email: %email, campaign id: %campaign',
    array('%error' => $ex->getMessage(), '%email' => $email, '%campaign' => $campaign));
    $message = $action == 's' ? t('Problem saving email, please try again later.') : t('There was a problem unsubscribing. Please try again later.');
    return array('status' => 0, 'message' => $message);
  }
}


/**
 * Send a 'subscribe' or 'unsubscribe' message to BSD
 *
 * @param $email string - email address of the user to lookup
 * @param $campaign_id string - pluris campaign id
 * @param $action string - 's' for subscribe, 'u' for unsubscribe
 *
 * @return string - empty if no problems, otherwise error message
 * 
 */
function _newsletter_signup_alert_bsd($email, $campaign_id, $action = 's',$source = '', $send_welcome = 'y', $signup_form_id) {
  
  $message = '';  
  if($action = 's') {
    $bsdresponse = takepart_bsd_email_signup($email, $signup_form_id);
    if(!strlen($bsdresponse) == 0) {
      watchdog('bsd', $bsdresponse);
    }
    //$newsletter_signup_form = takepart_bsd_signup_form($signup_form_id);
    //if ($newsletter_signup_form) {
    //  $newslettername = $newsletter_signup_form['signup_form_name'];
    //}
  }elseif($action = 'u') {
    takepart_bsd_email_set_subscription_state($email, 0);
  }
  //Note the the message is ignored if the 
  //caller is _save_campaign_signup:
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

/**
 * callback for the unsubscribe
 */
function _newsletter_unsubscribe_all() {
  global $user;
  drupal_set_title("Unsubscribe from all TakePart newsletters?");

  $email = false;
  // grab email from logged in user if not admin or anonymous
  if($user->uid > 1) {
    $email = $user->mail;
  }

  $campaign_code = variable_get('newsletter_campaign_unsubscribe_all_campaign_code', 'alltpnl');

  return drupal_get_form('_newsletter_unsubscribe_all_form', $campaign_code, $email);
}

/**
 * callback for the unsubscribe
 */
function _newsletter_unsubscribe() {
  drupal_set_title("Unsubscribe from all Takepart newsletters?");
  $email = $_GET['email'];
  $campaign_code = isset($_GET['campaign']) ? $_GET['campaign'] :  'all';
  return drupal_get_form('_newsletter_unsubscribe_all_form', $campaign_code, $email);

}

/**
 * unsubscribe form
 */
function _newsletter_unsubscribe_all_form($form, &$form_state, $campaign_code, $email) {
  $all_code = variable_get('takepart_newsletter_signup_unsubscribe_all_campaign_code', 'alltpnl');
  $query = new EntityFieldQuery();
  $db_result = $query->entityCondition('entity_type', 'newsletter_campaign')
  ->propertyCondition('campaign_id', $campaign_code, '=')
  ->execute();
  $ncids = array_keys($db_result['newsletter_campaign']);
  $camps = entity_load('newsletter_campaign', $ncids);
  // i hate this.
  $campaign = isset($camps[$ncids[0]]) ? $camps[$ncids[0]] : FALSE;

  if ($campaign) {
    drupal_set_title("Unsubscribe from {$campaign->title}?");
    $form['header'] = array(
      '#markup' => "<h2>Unsubscribe from {$campaign->title} newsletters?</h2>"
    );
  }
  else {
    $form['header'] = array(
      '#markup' => '<h2>Unsubscribe from all newsletters?</h2>'
    );

  }

  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email'),
    '#default_value' => $email,
  //'#disabled' => TRUE,
  );

  $form['campaign_id'] = array(
    '#type' => 'hidden',
    '#value' => $campaign_code,
  );

  $form['actions']['confirm'] = array(
    '#type' => 'submit',
    '#value' => t('Unsubscribe'),
    '#prefix' => '<span class="form-button-wrapper">',
    '#suffix' => '</span>&nbsp;'
  );
  $form['actions']['cancel'] = array(
    '#theme' => 'link',
    '#text' => 'Cancel',
    '#path' => "",
    '#options' => array(
      'attributes' => array(),
      'html' => FALSE,
  ),
  );


  if($campaign) {
    $form['actions']['unsubscribe_from_all'] = array(
      '#theme' => 'link',
      '#text' => 'Unsubscribe from all',
      '#path' => "newsletter-unsubscribe",
      '#options' => array(
        'attributes' => array(),
        'html' => FALSE,
        'query' => array("email"=>$email,"campaign"=>$all_code),
    ),
    );
  }

  return $form;
}

/**
 * Implementation of form_validate for newsletter unsubscribe form
 */
function _newsletter_unsubscribe_all_form_validate($form, &$form_state) {

  if (!valid_email_address($form_state['values']['email'])) {
    form_set_error('email', t('Invalid address'));
  }
}

/**
 * submit handler for '_newsletter_unsubscribe_form' form
 */
function _newsletter_unsubscribe_all_form_submit($form, &$form_state) {

  global $user;
  $message = '';
  
  $email = $form_state['values']['email'];
  $campaign_id = $form_state['values']['campaign_id'];
  $signup_form_id = $form_state['values']['signup_form_id'];
  $all_code = variable_get('takepart_newsletter_signup_unsubscribe_all_campaign_code', 'alltpnl');
  
  if ($campaign_id && $campaign_id == $all_code) {
    $message = takepart_bsd_email_set_subscription_state($email, 0);
  }
    // if there is a message, that means there was a problem
  if ($message) {
    drupal_set_message($response['message'], 'error', FALSE);
  }
  else {
    drupal_goto(
       'newsletter-unsubscribe/success', 
    array(
         'query' => array(
           'email' => $email,
           'campaign' => $campaign_id,
        ),
      )
    );
  }
  
}

/*
 * successful unsubscribe page callback
*/
function _newsletter_unsubscribe_success() {
  $email = $_GET['email'];
  $campaign_id = $_GET['campaign'];
  $query = new EntityFieldQuery();
  $db_result = $query->entityCondition('entity_type', 'newsletter_campaign')
  ->propertyCondition('campaign_id', $campaign_id, '=')
  ->execute();
  $ncids = array_keys($db_result['newsletter_campaign']);
  $camps = entity_load('newsletter_campaign', $ncids);
  $campaign = $camps[$ncids[0]];
  $title = $campaign ? $campaign->title : "all campaigns";
  drupal_set_title("Unsubscribed from {$title}.");
  return array(
    '#markup' => "<h2>{$campaign->title} Unsubscribe confirm</h2>You have successfully unsubscribed from {$title}"
  );

}

