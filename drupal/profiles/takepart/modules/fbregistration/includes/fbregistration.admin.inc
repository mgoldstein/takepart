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

  $form['settings']['fbregistration_page_title'] = array(
      '#type' => 'textfield',
      '#size' => 60,
      '#maxlength' => 128,
      '#title' => t('Register Page Title'),
      '#default_value' => variable_get('fbregistration_page_title', 'Register'),
      '#required' => TRUE,
  );

  $form['settings']['fbregistration_type'] = array(
      '#type' => 'select',
      '#title' => t('Plugin Type'),
      '#default_value' => variable_get('fbregistration_type', 0),
      '#options' => array(0 => t('XFBML'), 1 => t('Iframe'),),
      '#required' => TRUE,
  );

  $form['settings']['fbregistration_tag'] = array(
      '#type' => 'textarea',
      '#rows' => 2,
      '#title' => t('Facebook Registration Tag (XFBML)'),
      '#required' => TRUE,
      '#default_value' => variable_get('fbregistration_tag_b', '<fb:registration fb_register="true" fb_only="false" width="530"></fb:registration>'),
  );

  $form['settings']['fbregistration_tag_iframe'] = array(
      '#type' => 'textarea',
      '#rows' => 2,
      '#title' => t('Facebook Registration Tag (Iframe)'),
      '#required' => TRUE,
      '#default_value' => variable_get('fbregistration_tag_iframe', '<iframe scrolling="auto" frameborder="no" style="border:none" allowTransparency="true" width="100%" height="530"></iframe>'),
  );

  $form['settings']['fbregistration_validation'] = array(
      '#type' => 'textarea',
      '#rows' => 4,
      '#title' => t('Facebook Registration Validation Code (Use fbuserdata JS Variable)'),
      '#required' => TRUE,
      '#default_value' => variable_get('fbregistration_validation', _fbregistration_default_validation()),
  );


  $form['settings']['fbregistration_path'] = array(
      '#type' => 'textfield',
      '#title' => t('Registration path to apply FB reg plugin:'),
      '#default_value' => variable_get('fbregistration_path', '/user/register'),
      '#size' => 50,
      '#maxlength' => 255,
      '#required' => TRUE,
  );

  $form['settings']['fbregistration_foreign_zip'] = array(
      '#type' => 'textfield',
      '#title' => t('Foriegn Label for ZIP:'),
      '#default_value' => variable_get('fbregistration_foreign_zip', 'Postal Code'),
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

  $fbregistration_tag_iframe = $form_state['values']['settings']['fbregistration_tag_iframe'];
  variable_set('fbregistration_tag_iframe', $fbregistration_tag_iframe);

  $fbregistration_validation = $form_state['values']['settings']['fbregistration_validation'];
  variable_set('fbregistration_validation', $fbregistration_validation);

  $path = $form_state['values']['settings']['fbregistration_path'];
  variable_set('fbregistration_path', $path);

  $fbregistration_foreign_zip = $form_state['values']['settings']['fbregistration_foreign_zip'];
  variable_set('fbregistration_foreign_zip', $fbregistration_foreign_zip);

  $fbregistration_state = $form_state['values']['settings']['fbregistration_state'];
  variable_set('fbregistration_state', $fbregistration_state);

  $fbregistration_type = $form_state['values']['settings']['fbregistration_type'];
  variable_set('fbregistration_type', $fbregistration_type);

  $fbregistration_page_title = $form_state['values']['settings']['fbregistration_page_title'];
  variable_set('fbregistration_page_title', $fbregistration_page_title);

  drupal_set_message(t('The settings have been saved.'));
}
