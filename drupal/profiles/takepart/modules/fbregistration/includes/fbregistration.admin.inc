<?php

/**
 * Admin Form
 */
function fbregistration_form($form, &$form_state) {

  $form['settings'] = array('#type' => 'fieldset', '#title' => t('Settings'), '#tree' => TRUE);
  
  
  $form['settings']['fbregistration_state'] = array(
      '#type' => 'select',
      '#title' => t('Replace standard registration form with the Facebook Registration plugin?'),
      '#default_value' => variable_get('fbregistration_state', 0),
      '#options' => array(0 => t('No'), 1 => t('Yes'),),
      '#required' => TRUE,
  );
  
  $form['settings']['fbregistration_tag'] = array(
      '#type' => 'textarea',
      '#rows' => 2,
      '#title' => t('Facebook Registration Tag'),
      '#required' => TRUE,
      '#default_value' => variable_get('fbregistration_tag_b', '<fb:registration fb_register="true" fb_only="false" width="530"></fb:registration>'),
  );
  
  $form['settings']['fbregistration_path'] = array(
      '#type' => 'textfield',
      '#title' => t('Registration path to apply FB reg plugin:'),
      '#default_value' => variable_get('fbregistration_path', '/user/register'),
      '#size' => 50,
      '#maxlength' => 255,
      '#required' => TRUE,
  );
  
  $regform = drupal_get_form('user_register_form');
  
  // remove the metatags part of the form
  unset($regform['metatags']); 
  $regform['#submit'] = array_diff($regform['#submit'], array('metatag_metatags_form_submit'));
  
  
  $form['fieldmappings'] = array('#type' => 'fieldset', '#title' => t('Field Mappings'), '#tree' => TRUE);
  
  
  $form['fieldmappings']['link'] = array(
      '#type' => 'item',
      '#title' => t('Account Settings'),
      '#markup' => '<a href="/admin/config/people/accounts/fields">Manage Fields</a>',
  );
  
  

  
  _fbregistration_admin_form_load($regform, $form['fieldmappings']);
  

  //print_r($regform);
  //print_r($form['fieldmappings']);
  
  
  $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Save settings'),
  );
  
  
  drupal_set_title("Facebook Registration Settings");
  
  return $form;
}

/**
 * Save Admin Configuration:
 */
function fbregistration_form_submit($form, &$form_state) {
  
  //@todo: check indexes:
  foreach ($form_state['values']['fieldmappings'] as $key => $value) {
    variable_set('fbregistration_form_mapping_' . $key, $value);
  }
  
  $fbregistration_tag = $form_state['values']['settings']['fbregistration_tag'];
  variable_set('fbregistration_tag_b', $fbregistration_tag);
  
  $path = $form_state['values']['settings']['fbregistration_path'];
  variable_set('fbregistration_path', $path);
  
  drupal_set_message(t('The settings have been saved.'));
  
}
