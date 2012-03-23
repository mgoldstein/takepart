<?php

/**
 * Generates the petition editing form.
 */
function takepart_petition_form_form($form, &$form_state, $petition, $op = 'edit') {

  if ($op == 'clone') {
    $petition->label .= ' (cloned)';
    // reset the name so it will be set based on the cloned label
    $petition->name = '';
  }
  
  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $petition->label,
    '#description' => t('The human-readable name of this petition form.'),
    '#required' => TRUE,
    '#size' => 30,
  );
  
  // Machine-readable type name.
  $form['name'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($petition->name) ? $petition->name : '',
    '#maxlength' => 32,
    '#disabled' => $petition->isLocked() && $op != 'clone',
    '#machine_name' => array(
      'exists' => 'takepart_petition_forms',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this petition form. It must only contain lowercase letters, numbers, and underscores.'),
  );
  
  $form['goal'] = array(
    '#type' => 'textfield',
    '#title' => t('Signature Goal'),
    '#description' => t('Total number of signatures set as the goal for this petition.'),
    '#max_length' => 12,
    '#size' => 12,
    '#required' => TRUE,
    '#default_value' => $petition->goal,
  );

  // get the list of bsd signup forms
  $form['petition_form_id'] = takepart_bsd_form_id_select_field($petition->petition_form_id);
  $form['petition_form_id']['#description'] = t('ID Code for signup form that serves this petition.');
  $form['petition_form_id']['#title'] = t('Petition Form');
  $form['petition_form_id']['#required'] = TRUE;
    
  $form['mail_field_id'] = array(
    '#title' => t('Email Field ID'),
    '#type' => 'textfield',
    '#default_value' => $petition->mail_field_id,
    '#description' => t('ID Code of field on the petition form containing the email address.'),
    '#required' => TRUE,
    '#max_length' => 12,
    '#size' => 12,
  );
  $form['last_name_field_id'] = array(
    '#title' => t('Last Name Field ID'),
    '#type' => 'textfield',
    '#default_value' => $petition->last_name_field_id,
    '#description' => t('ID Code of field on the petition form containing the last name.'),
    '#required' => TRUE,
    '#max_length' => 12,
    '#size' => 12,
  );
  $form['first_name_field_id'] = array(
    '#title' => t('First Name Field ID'),
    '#type' => 'textfield',
    '#default_value' => $petition->first_name_field_id,
    '#description' => t('ID Code of field on the petition form containing the first name.'),
    '#required' => TRUE,
    '#max_length' => 12,
    '#size' => 12,
  );
  $form['zip_code_field_id'] = array(
    '#title' => t('ZIP Cocde Field ID'),
    '#type' => 'textfield',
    '#default_value' => $petition->zip_code_field_id,
    '#description' => t('ID Code of field on the petition form containing the zip code.'),
    '#required' => TRUE,
    '#max_length' => 12,
    '#size' => 12,
  );
  $form['comment_field_id'] = array(
    '#title' => t('Comment Field ID'),
    '#type' => 'textfield',
    '#default_value' => $petition->comment_field_id,
    '#description' => t('ID Code of field on the petition form containing the comment.'),
    '#required' => TRUE,
    '#max_length' => 12,
    '#size' => 12,
  );

  $form['source_ngo_field_id'] = array(
    '#title' => t('Source NGO Field ID'),
    '#type' => 'textfield',
    '#default_value' => $petition->source_ngo_field_id,
    '#description' => t('ID Code of field on the petition form containing the source NGO.'),
    '#required' => TRUE,
    '#max_length' => 12,
    '#size' => 12,
  );
  $form['ngo_opt_in_field_id'] = array(
    '#title' => t('NGO Opt-In Value Field ID'),
    '#type' => 'textfield',
    '#default_value' => $petition->ngo_opt_in_field_id,
    '#description' => t('ID Code of field on the petition form containing the NGO list opt-in value.'),
    '#required' => TRUE,
    '#max_length' => 12,
    '#size' => 12,
  );
  $form['campaign_opt_in_field_id'] = array(
    '#title' => t('Campaign Opt-In Value Field ID'),
    '#type' => 'textfield',
    '#default_value' => $petition->campaign_opt_in_field_id,
    '#description' => t('ID Code of field on the petition form containing the campaign list opt-in value.'),
    '#required' => TRUE,
    '#max_length' => 12,
    '#size' => 12,
  );

  $form['campaign_signup_form_id'] = takepart_bsd_form_id_select_field($petition->campaign_signup_form_id);
  $form['campaign_signup_form_id']['#description'] = t('ID Code for signup form that serves campaign mailing list.');
  $form['campaign_signup_form_id']['#title'] = t('Campaign Mailing List Form');
  $form['campaign_signup_form_id']['#required'] = TRUE;

  $form['campaign_mail_field_id'] = array(
    '#title' => t('Campaign Form Email Field ID'),
    '#type' => 'textfield',
    '#default_value' => $petition->campaign_mail_field_id,
    '#description' => t('ID Code of field on the campaign form containing the email address.'),
    '#required' => TRUE,
    '#max_length' => 12,
    '#size' => 12,
  );

  $form['water_bill_of_rights_thank_you'] = array(
    '#title' => t('Thank You Page URL'),
    '#type' => 'textfield',
    '#description' => t('URL relative to http://takepart.com/ for the petition thank you page'),
    '#required' => TRUE,
    '#max_length' => 255,
    '#default_value' => variable_get('water_bill_of_rights_thank_you'),
  );

  $form['water_bill_of_rights_progress'] = array(
    '#title' => t('Progress Page URL'),
    '#type' => 'textfield',
    '#description' => t('URL relative to http://takepart.com/ for the petition progress page'),
    '#required' => TRUE,
    '#max_length' => 255,
    '#default_value' => variable_get('water_bill_of_rights_progress'),
  );
  
  $form['water_bill_of_rights_reason_to_sign'] = array(
    '#title' => t('Markup for modal prompt'),
    '#type' => 'textarea',
    '#resizable' => TRUE,
    '#default_value' => variable_get('water_bill_of_rights_reason_to_sign'),
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save petition form'),
    '#weight' => 40,
  );

  if (!$petition->isLocked() && $op != 'add' && $op != 'clone') {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete petition form'),
      '#weight' => 45,
      '#limit_validation_errors' => array(),
      '#submit' => array('takepart_petition_form_form_submit_delete')
    );
  }
  
  $form['#validate'][] = 'takepart_petition_form_form_validate';

  return $form;
}

/**
 * Submit handler for creating/editing petitions.
 */
function takepart_petition_form_form_submit(&$form, &$form_state) {
  $petition = entity_ui_form_submit_build_entity($form, $form_state);
  variable_set('water_bill_of_rights_thank_you', $form_state['values']['water_bill_of_rights_thank_you']);
  variable_set('water_bill_of_rights_progress', $form_state['values']['water_bill_of_rights_progress']);
  variable_set('water_bill_of_rights_reason_to_sign', $form_state['values']['water_bill_of_rights_reason_to_sign']);
  // Save and go back.
  takepart_petition_form_save($petition);
  // Redirect user back to list of petitions.
  $form_state['redirect'] = 'admin/structure/petitions/forms';
}

function takepart_petition_form_form_submit_delete(&$form, &$form_state) {
  // Redirect user back to the delete confirmation.
  $form_state['redirect'] = 'admin/structure/petitions/forms/manage/' . $form_state['takepart_petition_form']->name . '/delete';
}

function takepart_petition_form_form_validate($form, &$form_state) {

  $value = $form_state['values']['goal'];
  if (strlen(trim($value)) > 0) {
    if ((!is_numeric($value)) || ($value <= 0)) {
      form_set_error('TakePart Petition Forms', t('The signature goal must be a number greater than zero.'));
    }
  }

  $value = $form_state['values']['bsd_form_id'];
  if (strlen(trim($value)) > 0) {
    if ((!is_numeric($value)) || ($value < 0)) {
      form_set_error('TakePart Petition Forms', t('The Petition Form ID must be a positive integer.'));
    }
  }

  $value = $form_state['values']['mail_field_id'];
  if (strlen(trim($value)) > 0) {
    if ((!is_numeric($value)) || ($value < 0)) {
      form_set_error('TakePart Petition Forms', t('The Email Field ID must be a positive integer.'));
    }
  }

  $value = $form_state['values']['last_name_field_id'];
  if (strlen(trim($value)) > 0) {
    if ((!is_numeric($value)) || ($value < 0)) {
      form_set_error('TakePart Petition Forms', t('The Last Name Field ID must be a positive integer.'));
    }
  }

  $value = $form_state['values']['first_name_field_id'];
  if (strlen(trim($value)) > 0) {
    if ((!is_numeric($value)) || ($value < 0)) {
      form_set_error('TakePart Petition Forms', t('The First Name Field ID must be a positive integer.'));
    }
  }

  $value = $form_state['values']['zip_code_field_id'];
  if (strlen(trim($value)) > 0) {
    if ((!is_numeric($value)) || ($value < 0)) {
      form_set_error('TakePart Petition Forms', t('The ZIP Code Field ID must be a positive integer.'));
    }
  }

  $value = $form_state['values']['comment_field_id'];
  if (strlen(trim($value)) > 0) {
    if ((!is_numeric($value)) || ($value < 0)) {
      form_set_error('TakePart Petition Forms', t('The Comment Field ID must be a positive integer.'));
    }
  }

  $value = $form_state['values']['source_ngo_field_id'];
  if (strlen(trim($value)) > 0) {
    if ((!is_numeric($value)) || ($value < 0)) {
      form_set_error('TakePart Petition Forms', t('The Source NGO Field ID must be a positive integer.'));
    }
  }

  $value = $form_state['values']['ngo_opt_in_field_id'];
  if (strlen(trim($value)) > 0) {
    if ((!is_numeric($value)) || ($value < 0)) {
      form_set_error('TakePart Petition Forms', t('The NGO Opt-In Value Field ID must be a positive integer.'));
    }
  }

  $value = $form_state['values']['campaign_opt_in_field_id'];
  if (strlen(trim($value)) > 0) {
    if ((!is_numeric($value)) || ($value < 0)) {
      form_set_error('TakePart Petition Forms', t('The Campaign Opt-In Value Field ID must be a positive integer.'));
    }
  }

  $value = $form_state['values']['campaign_signup_form_id'];
  if (strlen(trim($value)) > 0) {
    if ((!is_numeric($value)) || ($value < 0)) {
      form_set_error('TakePart Petition Forms', t('The Campaign Mailing List Form ID must be a positive integer.'));
    }
  }

  $value = $form_state['values']['campaign_mail_field_id'];
  if (strlen(trim($value)) > 0) {
    if ((!is_numeric($value)) || ($value < 0)) {
      form_set_error('TakePart Petition Forms', t('The Campaign Form Email Field ID must be a positive integer.'));
    }
  }
}


/**
 * Generates the petition ngo editing form.
 */
function takepart_petition_ngo_form($form, &$form_state, $ngo, $op = 'edit') {

  if ($op == 'clone') {
    $ngo->label .= ' (cloned)';
    // reset the name so it will be set based on the cloned label
    $ngo->token = '';
  }
  
  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $ngo->label,
    '#description' => t('The human-readable name of this NGO.'),
    '#required' => TRUE,
    '#size' => 30,
  );
  
  // Machine-readable type name.
  $form['token'] = array(
    '#title' => t('Token'),
    '#type' => 'machine_name',
    '#default_value' => isset($ngo->token) ? $ngo->token : '',
    '#maxlength' => 16,
    '#disabled' => $ngo->isLocked() && $op != 'clone',
    '#machine_name' => array(
      'exists' => 'takepart_petition_ngos',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable token for this NGO. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save NGO'),
    '#weight' => 40,
  );

  if (!$ngo->isLocked() && $op != 'add' && $op != 'clone') {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete NGO'),
      '#weight' => 45,
      '#limit_validation_errors' => array(),
      '#submit' => array('takepart_petition_ngo_form_submit_delete')
    );
  }
  
  $form['#validate'][] = 'takepart_petition_ngo_form_validate';

  return $form;
}

/**
 * Submit handler for creating/editing petitions.
 */
function takepart_petition_ngo_form_submit(&$form, &$form_state) {
  $entity = entity_ui_form_submit_build_entity($form, $form_state);
  // Save and go back.
  takepart_petition_ngo_save($entity);
  // Redirect user back to list of petitions.
  $form_state['redirect'] = 'admin/structure/petitions/ngos';
}

function takepart_petition_ngo_form_submit_delete(&$form, &$form_state) {
  // Redirect user back to the delete confirmation.
  $form_state['redirect'] = 'admin/structure/petitions/ngos/manage/' . $form_state['takepart_petition_ngo']->token . '/delete';
}

function takepart_petition_ngo_form_validate($form, &$form_state) {
  $value = $form_state['values']['token'];
  if ($value == 'no_ngo') {
    form_set_error('TakePart Petitions', t("The NGO token can not be 'no_ngo', this value is reserved."));
  }
}
