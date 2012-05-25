<?php

/**
 * Admin Form
 */
function takepart_facebookapis_form($form, &$form_state) {

  $form['settings'] = array('#type' => 'fieldset', '#title' => t('Settings'), '#tree' => TRUE);
   
  $form['settings']['fblogin_state'] = array(
      '#type' => 'select',
      '#title' => t('Replace standard login form with the Facebook login plugin?'),
      '#default_value' => variable_get('fblogin_state', 'No'),
      '#options' => array(0 => t('No'), 1 => t('Yes'),),
      '#required' => TRUE,
  );
      
  
  $form['settings']['fblogin_backdoor_url'] = array(
      '#type' => 'textfield',
      '#size' => 60,
      '#maxlength' => 128,
      '#title' => t('Backdoor URL'),
      '#default_value' => variable_get('fblogin_backdoor_url', 'backdoor'),
      '#required' => TRUE,
  );
  
  $form['settings']['fblogin_textoverbutton'] = array(
      '#type' => 'textarea',
      '#rows' => 2,
      '#title' => t('Text in login box'),
      '#required' => TRUE,
      '#default_value' => variable_get('fblogin_textoverbutton', 'If you have a <strong>Facebook Account</strong>'),
  );
  
  if(function_exists('fbconnect_get_config')) {
      
    $conf = fbconnect_get_config();
    
    $form['settingsonfb'] = array('#type' => 'fieldset', '#title' => t('Configuration on Facebook'), '#tree' => TRUE);
    
    $fburls = '<a href = "https://developers.facebook.com/apps/' . $conf['app_id'] . '/summary">Basic</a> | ' . 
              '<a href = "https://developers.facebook.com/apps/' . $conf['app_id'] . '/auth">Auth Dialog</a> | ' .
              '<a href = "https://developers.facebook.com/apps/' . $conf['app_id'] . '/advanced">Advanced</a>';
    
    $form['settingsonfb']['links_a'] = array(
        '#type' => 'item',
        '#title' => t('App Configuration'),
        '#markup' => '<a href = "https://developers.facebook.com/apps/' . $conf['app_id'] . '">General</a>',
    );
    
    $form['settingsonfb']['links_b'] = array(
        '#type' => 'item',
        '#title' => t('Settings'),
        '#markup' => $fburls,
    );

  }

  $form['settings']['fblogin_login_tag'] = array(
      '#type' => 'textarea',
      '#rows' => 2,
      '#title' => t('Facebook Login Tag'),
      '#required' => TRUE,
      '#default_value' => variable_get('fblogin_login_tag_html_a', '<fb:login-button data-scope="email,user_checkins,user_birthday" fb_register="true" fb_only="false" width="530">Log In</fb:login-button>'),
      '#description'=> 'XFBML <a href="http://developers.facebook.com/docs/reference/plugins/login/">login</a> tag with <a href="http://developers.facebook.com/docs/authentication/permissions/">permissions</a> to be collected in addtion to the user\'s basic information.',
  );
  
  
  $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Save settings'),
  );
  
  return $form;
}

/**
 * Save Admin Configuration:
 */
function takepart_facebookapis_form_submit($form, &$form_state) {
    
  $state = $form_state['values']['settings']['fblogin_state'];
  variable_set('fblogin_state', $state);

  $fblogin_login_tag = $form_state['values']['settings']['fblogin_login_tag'];
  variable_set('fblogin_login_tag_html_a', $fblogin_login_tag);
  
  $fblogin_textoverbutton = $form_state['values']['settings']['fblogin_textoverbutton'];
  variable_set('fblogin_textoverbutton', $fblogin_textoverbutton);
  
  $fblogin_backdoor_url = $form_state['values']['settings']['fblogin_backdoor_url'];
  if(variable_get('fblogin_backdoor_url', 'backdoor') != $fblogin_backdoor_url) {
    variable_set('fblogin_backdoor_url', $fblogin_backdoor_url);
    menu_rebuild();
  }
  
  drupal_set_message(t('The settings have been saved.'));
  
}