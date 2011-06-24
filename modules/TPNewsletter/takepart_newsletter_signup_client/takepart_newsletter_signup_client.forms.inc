<?php

/**
 * The newsletter form
 *
 * @param $form_state array - required by api; not used
 * @param $campaign_id string - campaign id for subscription
 *
 * @return array - raw form array
 */
function takepart_newsletter_signup_client_newsletter_signup_form(&$form_state, $campaign_id) {
  $form = array();
  
  // adds ajax functionality to the block
  drupal_add_js('
    Drupal.behaviors.takepart_newsletter_signup_'.$campaign_id.' = function(context) {   
      $("#wrapper-form-'.$campaign_id.' .form-submit", context).click(function(e) {
       e.preventDefault();
	   if (takepart_newsletter_isValidEmailAddress($("#wrapper-form-'.$campaign_id.' [name=email]").val(), "'.$campaign_id.'")) {
         $.post("/newsletter-campaign/submit-campaign", $("#wrapper-form-'.$campaign_id.' form").serialize(), 
         function(result) {
           $("#takepart-newsletter-'.$campaign_id.'-body").hide();
           $("#takepart-newsletter-'.$campaign_id.'-results").html(result.message).text();
         }, "json");
       }
        
       return false;
      });
    }', 'inline'
  );

  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email'),
    '#default_value' => ' Enter email address',
    '#size' => 60,
    '#maxlength' => 128,
    '#attributes' => array('onclick' => 'this.value=""; takepart_newsletter_update_css(this)'),
  );
  
  $form['campaign_id'] = array(
    '#type' => 'hidden',
    '#value' => $campaign_id,
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit')
  );
  
  return $form;
}


/**
 * Valide the form values
 *
 * @param $form array - raw post values
 *
 * @return string - message if error, empty string if not
 */
function takepart_newsletter_signup_client_newsletter_signup_form_validate_from_ajax(&$form) {
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
function takepart_newsletter_signup_client_newsletter_signup_form_submit_from_ajax() { 
  $form = $_POST;
  
  $message = takepart_newsletter_signup_client_newsletter_signup_form_validate_from_ajax($form);
  
  if ($message) {
    print drupal_json(array(0, $message));
    exit();
  }
   
  $email = $form['email'];
  $campaign_id = $form['campaign_id'];
  
  if (!variable_get('takepart_newsletter_signup_client_direct_save', 0)) {
    $result = takepart_newsletter_signup_client_call_webservice($email, $campaign_id);
  } 
  else {
    $result = takepart_newsletter_save_campaign($email, $campaign_id, 's');
  }
  if ($result['status'] == 1 ) {
    $nid = takepart_newsletter_signup_client_get_campaign_nid($campaign_id);
    
    if ($nid) {
      $campaign = node_load($nid);
      $message = $campaign->field_newsletter_thanks_text[0]['value'];
    }

    $result = array('status' => $result['status'], 'message' => $message);
  }
  print drupal_json($result);
  
  exit();
}


/**
 *  Calls webservice at www.takepart.com to save email address
 *
 * @param $email string - email address
 * @param $campaign_id string - campaign id for subscription
 *
 * @return string - error message if problem; empty strin if ok
 */
function takepart_newsletter_signup_client_call_webservice($email, $campaign_id) {
  $kid = variable_get('takepart_newsletter_signup_client_api_key', 0);
  $timestamp = (string)time();
  $domain =  variable_get('takepart_newsletter_signup_client_domain', '');
  
  $code = md5(uniqid(rand(), true));
  $nonce = substr($code, 0, 10);
  
  $hash_parameters = array( $timestamp, $domain, $nonce, 'takepart_newsletter_signup.subscribe' );
  $hash = hash_hmac("sha256", implode(';', $hash_parameters), $kid);

  $request_url = variable_get('takepart_newsletter_signup_client_service_url', '').'?';
  $request_url .= "h=$hash&d=$domain&t=$timestamp&n=$nonce&e=$email&c=$campaign_id";
  
  $result = FALSE;
  try {
    $result = drupal_http_request($request_url, array(), 'POST');
    if ($result->code == 200) {
      #the JSON starts with Insert which needs to be removed be fore it can be decoded
      $data = json_decode(preg_replace("/^Insert/","", $result->data), TRUE);
      if (isset($data['status'])) {
        return $data;
      }
    }
    watchdog('newsletter service', 'Error from webservice: '.$result->error.' - '.$request_url);
    return array('success'=>0, 'message'=>t('Problem saving email, please try again later.'));
  }
  catch(Exception $ex) {
    watchdog('newsletter service', 'Error from webservice: '.$ex->getMessage());
    return array('success'=>0, 'message' => t('Problem saving email, please try again later.'));
  }

  return array('success'=>0, 'message' => t('Problem saving email, please try again later.'));
}


/**
 * Returns the admin settings for the module
 */
function takepart_newsletter_signup_client_admin_settings() {
  $form = array();

  $form['takepart_newsletter_signup_client_service_url'] = array(
    '#prefix' => '<br/><br/>',
    '#type' => 'textfield',
    '#size' => 100,
    '#title' => t('Webservice URL'),
    '#description' => t('Full url to the TakePart.com service; i.e., http://www.takepart.com/services/rest/takepart_newsletter_signup.subscribe'),
    '#default_value' => variable_get('takepart_newsletter_signup_client_service_url', 'http://www.takepart.com/services/rest/takepart_newsletter_signup.subscribe'),
  );
  
  $form['takepart_newsletter_signup_client_domain'] = array(
    '#type' => 'textfield',
    '#size' => 30,
    '#title' => t('Domain'),
    '#description' => t('Domain name supplied to TakePart for the API Key'),
    '#default_value' => variable_get('takepart_newsletter_signup_client_domain', ''),
  );
  
  $form['takepart_newsletter_signup_client_api_key'] = array(
    '#type' => 'textfield',
    '#size' => 60,
    '#title' => t('API Key'),
    '#description' => t('API Key to the web service obtained from TakePart'),
    '#default_value' => variable_get('takepart_newsletter_signup_client_api_key', ''),
  );
    
  if (module_exists('takepart_newsletter_signup')) {
    $form['takepart_newsletter_signup_client_direct_save'] = array(
      '#type' => 'checkbox',
      '#title' => t('Direct Save'),
      '#description' => t('Bypass the service and save directly to the database. Only used if TakePart Newsletter Service module is installed'),
      '#default_value' => variable_get('takepart_newsletter_signup_client_direct_save', 0),
    );
  }
  
  return system_settings_form($form);  
  
}
