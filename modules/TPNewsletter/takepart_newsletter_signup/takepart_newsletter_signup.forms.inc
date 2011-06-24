<?php


/**
 * Returns unsubscribe form
 *
 * @param $form_state array - needed from api, not used
 *
 * @return array - raw form array
 */
function takepart_newsletter_signup_unsubscribe_form(&$form_state) {
  $path = drupal_get_path('module', 'takepart_newsletter_signup');
  drupal_add_css($path .'/takepart_newsletter_signup.css');
  
  $all_code = variable_get('takepart_newsletter_signup_unsubscribe_all_campaign_code', 'alltpnl');
  
  $email = check_plain($_GET['email']);
  $campaign_id = check_plain($_GET['campaign']); 

  if ($campaign_id != $all_code) {
    $campaign_nid = takepart_newsletter_signup_get_campaign_nid($campaign_id);
  }
  
  if ($campaign_nid) {
    $campaign_node = node_load($campaign_nid);
  }
  
  if ($campaign_node && $campaign_node->field_newsletter_campaign_logo[0]['filepath']) {
    $logo = theme('image', $campaign_node->field_newsletter_campaign_logo[0]['filepath'], $campaign_node->field_newsletter_campaign_logo[0]['title'], $campaign_node->field_newsletter_campaign_logo[0]['title']);
  } 
  
  $form = array();
  
  if (valid_email_address($email) && (($campaign_id && $campaign_node->title) || ($campaign_id == $all_code))) {
    $campaign_title = ($campaign_node) ? $campaign_node->title : 'All Campaigns';
    $subscribed_to_mailings = false;
    
    drupal_set_title("Unsubscribe from $campaign_title?");
    
    if ($logo) {
      $form['logo'] = array(
        '#value' => "<div id='newsletter-unsubscribe-logo'>$logo</div>",
      );
    }
    
    $campaign_titles = array();
    
    if ($campaign_id == $all_code) {
      $mailings = db_query("SELECT t.campaign_id, n.title FROM {tp_newsletter_signups} t LEFT OUTER JOIN {content_type_newsletter_campaign} c ON c.field_newsletter_campaign_id_value = t.campaign_id LEFT OUTER JOIN {node} n ON n.vid = c.vid WHERE mail = '%s' AND t.status = 's' ORDER BY n.title", $email);
      
      while($mailing = db_fetch_array($mailings)) {
        $subscribed_to_mailings = true;
        if ($mailing['campaign_id'] == 'tpnews1') {
          $campaign_titles[] = 'TakePart newsletters and alerts';
        }
        else if ($mailing['campaign_id'] == 'mpemails') {
          $campaign_titles[] = 'Members Project updates and info';
        }
        else {
          $campaign_titles[] = $mailing['title'];
        }
      }
      
      if (!empty($campaign_titles)) {
        $form['intro'] = array(
          '#value' => '<br/>'.t(variable_get('takepart_newsletter_signup_unsubscribe_all_text', 'Please confirm that we should unsubscribe %email from all TakePart campaigns'), array('%email' => $email)).'<br/><br/>'
        );
      }
    }
    else {
       $form['intro'] = array(
        '#value' => '<br/>'.t(variable_get('takepart_newsletter_signup_unsubscribe_text', 'Please confirm that we should unsubscribe %email from the %campaign_title'), array('%email' => $email, '%campaign_title' => $campaign_node->title)).'<br/><br/>'
      );
    }
    
    if ($campaign_id == $all_code) {
      if (!empty($campaign_titles)) {
        asort($campaign_titles);
        $form['signup_listings'] = array(
          '#value' => implode("<br/>", $campaign_titles).'<br/><br/>',
        );
      }
      else {
        $form['signup_listings'] = array(
          '#value' => '<br/><p>'.t('You are currently unsubscribed from all mailings.').'</p>',
        );
      }
    }
      
    $form['email'] = array(
      '#type' => 'hidden',
      '#value' => $email,
    );
  
    $form['campaign_id'] = array(
      '#type' => 'hidden',
      '#value' => $campaign_id,
    );
  
    $form['cancel'] = array(
      '#type' => 'submit',
      '#value' => t('Cancel'),
      '#prefix' => '<span class="form-button-wrapper button-functionality">',
      '#suffix' => '</span>'
    );
    
    if (($subscribed_to_mailings && $campaign_id == $all_code) || $campaign_id != $all_code)  {
    
      $form['confirm'] = array(
        '#type' => 'submit',
        '#value' => t('Unsubscribe'),
        '#prefix' => '<span class="form-button-wrapper">',
        '#suffix' => '</span>&nbsp;'
      );
    }
    
    if ($campaign_id != $all_code) {
      $form['all_link'] = array(
        '#value' => '<br/><br/>'.l(t(variable_get('takepart_newsletter_signup_unsubscribe_all_link_text', 'Unsubscribe from all TakePart mailings')), variable_get('takepart_newsletter_signup_unsubscribe_page', 'newsletter-unsubscribe'), array('query' => array('email' => $email, 'campaign' => $all_code, 'destination' => variable_get('takepart_newsletter_signup_unsubscribe_page', 'newsletter-unsubscribe').'?email='.$email.'&campaign='.$campaign_id))),
      );
    }
    
  }
  else {
    $form['intro'] = array(
      '#value' => t('Invalid arguments supplied')
    );
  }
  
  return $form;
}


/**
 * Implementation of form_validate for newsletter unsubscribe form
 */
function takepart_newsletter_signup_unsubscribe_form_validate($form, &$form_state) {
  if (!valid_email_address($form_state['values']['email'])) {
    form_set_error('email', t('Invalid address'));
  }
  
  $form_state['values']['email'] = check_plain($form_state['values']['email'] );
  $form_state['values']['campaign_id'] = check_plain($form_state['values']['campaign_id']);
}


/**
 * Implementation of form_submit for newsletter unsubscribe signup form
 * Updates data in the local database and calls pluris
 */
function takepart_newsletter_signup_unsubscribe_form_submit($form, &$form_state) {
  $email = check_plain($form_state['values']['email'] );
  $campaign_id = check_plain($form_state['values']['campaign_id']);
  
  if ($form_state['values']['op'] == 'Unsubscribe') {
    global $user;
  
    // check if user signing up is currently logged in or has an account
    $uid = 0;
    if ($user->mail == $email) {
      $uid = $user->uid;
    }
    else { 
      $uid = takepart_newsletter_signup_is_drupal_user($email);
    }
  
    $response = takepart_newsletter_delete_campaign($email, $campaign_id);
    unset($_REQUEST['destination']);
    
    // if there is a message, that means there was a problem
    if (!$response['status']) {
      drupal_set_message($response['message'], 'error', FALSE);
      drupal_goto(variable_get('takepart_newsletter_signup_unsubscribe_problem_page', 'newsletter-unsubscribe-problem'));
    }
    else {
      drupal_goto(variable_get('takepart_newsletter_signup_unsubscribe_confirmation_page', 'newsletter-unsubscribe-confirmation'));
    }
  }
  else {
    $dest = urlencode(check_plain($_REQUEST['destination']));
    if ($dest) {
      drupal_goto('destination='.$dest);
    }
    else {
      drupal_goto();
    }
  }
}


/**
 * Returns the admin settings for the module
 */
function takepart_newsletter_signup_admin_settings() {
  $form = array();

  $form['takepart_newsletter_signup_pluris_url'] = array(
    '#prefix' => '<br/><br/>',
    '#type' => 'textfield',
    '#size' => 60,
    '#title' => t('Pluris URL'),
    '#description' => t('Used for "back-end" processing and is appended with a query string for email, campaign ID and action (subscribe/unsubscribe)'),
    '#default_value' => variable_get('takepart_newsletter_signup_pluris_url', 'https://digitalsubscriptions.plurismarketing.com/subscribeRequest.php'),
  );
  
  $form['takepart_newsletter_signup_pluris_unsubscribe_url'] = array(
    '#type' => 'textfield',
    '#size' => 60,
    '#title' => t('Pluris Unsubscribe URL'),
    '#description' => t('Special URL for unsubscribing to all campaigns'),
    '#default_value' => variable_get('takepart_newsletter_signup_pluris_unsubscribe_url', 'https://digitalsubscriptions.plurismarketing.com/unsubscribeAll.php'),
  ); 
  
  $form['takepart_newsletter_signup_unsubscribe_all_campaign_code'] = array(
    '#type' => 'textfield',
    '#size' => 60,
    '#title' => t('Unsubscribe All Campaign Code'),
    '#description' => t('Campaign Code used to unsubscribe from all mailings'),
    '#default_value' => variable_get('takepart_newsletter_signup_unsubscribe_all_campaign_code', 'alltpnl'),
  ); 
  
  $form['takepart_newsletter_signup_unsubscribe_page'] = array(
    '#type' => 'textfield',
    '#size' => 30,
    '#title' => t('Unsubscribe Path'),
    '#description' => t('Path that the user goes to after clicking the unsubscribe link in their email. This should NOT be an existing path to a current page. The path entered here will use the text below.'),
    '#default_value' => variable_get('takepart_newsletter_signup_unsubscribe_page', 'newsletter-unsubscribe'),
  );
  
  $form['takepart_newsletter_signup_unsubscribe_text'] = array(
    '#type' => 'textfield',
    '#size' => 100,
    '#title' => t('Unsubscribe Text'),
    '#description' => t('Intro text to use on unsubscribe page'),
    '#default_value' => variable_get('takepart_newsletter_signup_unsubscribe_text', 'Please confirm that we should unsubscribe %email from the %campaign_title'),
  );
  
  $form['takepart_newsletter_signup_unsubscribe_all_text'] = array(
    '#type' => 'textfield',
    '#size' => 100,
    '#title' => t('Unsubscribe All Text'),
    '#description' => t('Intro text to use on unsubscribe all page'),
    '#default_value' => variable_get('takepart_newsletter_signup_unsubscribe_all_text', 'Please confirm that we should unsubscribe %email from all TakePart campaigns'),
  );
  
  $form['takepart_newsletter_signup_unsubscribe_all_link_text'] = array(
    '#type' => 'textfield',
    '#size' => 100,
    '#title' => t('Unsubscribe All Link Text'),
    '#description' => t('Text for link to unsubscribe all page'),
    '#default_value' => variable_get('takepart_newsletter_signup_unsubscribe_all_link_text', 'Unsubscribe from all TakePart mailings'),
  );
  
  $form['takepart_newsletter_signup_unsubscribe_confirmation_page'] = array(
    '#type' => 'textfield',
    '#size' => 30,
    '#title' => t('Unsubscribe Success Path'),
    '#description' => t('Path for unsubscribing success. This should NOT be an existing path to a current page. The path entered here will use the text below.'),
    '#default_value' => variable_get('takepart_newsletter_signup_unsubscribe_confirmation_page', 'newsletter-unsubscribe-confirmation'),
  );
  
  $form['takepart_newsletter_signup_unsubscribe_confirmation_text'] = array(
    '#type' => 'textfield',
    '#size' => 60,
    '#title' => t('Unsubscribe Success Text'),
    '#description' => t('Text that will be displayed after a user unsubscribes.'),
    '#default_value' => variable_get('takepart_newsletter_signup_unsubscribe_confirmation_text', 'You have been successfully unsubscribed.'),
  );
  
  $form['takepart_newsletter_signup_unsubscribe_problem_page'] = array(
    '#type' => 'textfield',
    '#size' => 30,
    '#title' => t('Unsubscribe Problem Path'),
    '#description' => t('Path for unsubscribing problems. This should NOT be an existing path to a current page. The path entered here will use the text below.'),
    '#default_value' => variable_get('takepart_newsletter_signup_unsubscribe_problem_page', 'newsletter-unsubscribe-problem'),
  );
  
  $form['takepart_newsletter_signup_unsubscribe_problem_text'] = array(
    '#type' => 'textfield',
    '#size' => 60,
    '#title' => t('Unsubscribe Problem Text'),
    '#description' => t('Text that will be displayed if there is a problem with a user unsubscribing.'),
    '#default_value' => variable_get('takepart_newsletter_signup_unsubscribe_problem_text', 'There was a problem unsubscribing. Please try again later.'),
  );
  
  return system_settings_form($form);  
}
