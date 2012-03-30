<?php

//Marigold specific forms:

function takepart_contests_contest_entry_form_1($form, &$form_state, $entry) {

  // needed for the metrics begin contest tracking cookie
  drupal_add_library('system','jquery.cookie');
  
  if (! isset($form_state['storage'])) {
    $form_state['storage'] = array(
      'step' => 1,
      'values' => array(),
    );
  }
  $step = $form_state['storage']['step'];

  // add the entity fields to the form
  // the entity itself needs to be stored in the form state with
  // the name of the entity (the key used in the entity_info hook) as the key
  $form_state['takepart_contests_contest_entry'] = $entry;
  field_attach_form('takepart_contests_contest_entry', $entry, $form, $form_state);

  // set the maxlength property on the textarea fields
  // TODO: Remove the hardcode field names once we have installed the maxlength
  // module
  $language = $form['field_custom_265']['#language'];
  $form['field_custom_265'][$language][0]['value']['#rows'] = 8;
  $form['field_custom_265'][$language][0]['value']['#attributes'] += array(
    'maxlength' => 700,
    'columns' => 40,
  );
  $language = $form['field_custom_266']['#language'];
  $form['field_custom_266'][$language][0]['value']['#rows'] = 8;
  $form['field_custom_266'][$language][0]['value']['#attributes'] += array(
    'maxlength' => 700,
    'columns' => 40,
  );
  $language = $form['field_custom_267']['#language'];
  $form['field_custom_267'][$language][0]['value']['#rows'] = 8;
  $form['field_custom_267'][$language][0]['value']['#attributes'] += array(
    'maxlength' => 700,
    'columns' => 40,
  );
  $language = $form['field_custom_270']['#language'];
  $form['field_custom_270'][$language][0]['value']['#rows'] = 8;
  $form['field_custom_270'][$language][0]['value']['#attributes'] += array(
    'maxlength' => 700,
    'columns' => 40,
  );
  $language = $form['field_custom_271']['#language'];
  $form['field_custom_271'][$language][0]['value']['#rows'] = 8;
  $form['field_custom_271'][$language][0]['value']['#attributes'] += array(
    'maxlength' => 700,
    'columns' => 40,
  );
  
  // Set the tab order of the Final Information fields
  if ($step == 3 || $step == 4) {
    $final_information_fields = array(
      'field_profile_email', 'field_profile_first_name', 'field_profile_last_name',
      'field_profile_addr1', 'field_profile_addr2', 'field_profile_city',
      'field_profile_state', 'field_profile_zip', 'field_profile_phone',);
    $tabindex = _takepart_contests_gettabindex($form, 'field_profile_email');
    foreach ($final_information_fields as $field_name) {
      $language = $form[$field_name]['#language'];
      if (! isset($form[$field_name][$language][0]['value']['#attributes'])) {
        $form[$field_name][$language][0]['value']['#attributes'] = array();
      }
      $form[$field_name][$language][0]['value']['#attributes'] += array(
        'tabindex' => $tabindex,
      );
      $tabindex += 1;
    }
  }
  
  // update the titles of fields that need to use the help text to get around
  // the length limitation of the title property
  // TODO: Replace with the takepart_longlabels module
  foreach ($form as $field_name => &$field) {
    if (is_array($field)) {
      if (! empty($field['und'][0]['value']['#description'])) {
        $field['und'][0]['value']['#title'] = 
          $field['und'][0]['value']['#description'];
        $field['und'][0]['value']['#description'] = '';
      }
    }
  }

  // add the confirmation label to group 3
  if ($step == 3) {
    $form['confirm_msg'] = array(
      '#markup' => "<div class=\"confirm_msg\">Please confirm your information below to finalize your submission.</div>",
    );
    $form['#fieldgroups']['group_step3']->children = array_merge(
      array('confirm_msg',), $form['#fieldgroups']['group_step3']->children);
    $form['#group_children']['confirm_msg'] = 'group_step3'; 
  }

  
  // show only those fields for the current step
  if($step != 4) {
    $current_group = 'group_step' . $step;
    foreach ($form['#group_children'] as $field_name => $group_name) {
      $form[$field_name]['#access'] = ($group_name == $current_group);
    }
  }
  
  // create the appropriate navigation buttons
  if ($step < 4) {
    $form['reqtext'] = array(
      '#markup' => '<span class="reqtext"><span class="form-required">*</span>Indicates required field</span>',
      '#weight' => 1990,
    );
    $form['next'] = array(
      '#type' => 'submit',
      '#value' => t('Next step'),
      '#submit' => array('takepart_contests_contest_entry_form_submit_1'),
      '#ajax' => array(
        'wrapper' => 'takepart_contests_form_wrapper_1',
        'callback' => 'takepart_contests_contest_entry_form_callback_1',
      ),
      '#weight' => 2000,
    );
  }
  if ($step > 1) {
    $form['prev'] = array(
      '#type' => 'submit',
      '#value' => t("Previous step"),
      // Don't validate when going back:
      '#limit_validation_errors' => array(),
      // #submit is required to use #limit_validation_errors
      '#submit' => array('takepart_contests_contest_entry_form_submit_1'),
      '#ajax' => array(
        'wrapper' => 'takepart_contests_form_wrapper_1',
        'callback' => 'takepart_contests_contest_entry_form_callback_1',
      ),
      '#weight' => 2010,
    );
  }
  if ($step == 4) {
    $form['submit'] = array(
      '#type' => 'submit',
      '#submit' => array('takepart_contests_contest_entry_form_submit_1'),
      '#value' => t("Submit your information"),
      '#weight' => 2005,
    );
  }

  // style the navigation buttons for the current step
  switch ($step) {
  
    case 1:
      $form['next']['#attributes']['class'][] = 'aboutyou';
      $form['next']['#takepart_before'] = 'next: ';
      $form['next']['#theme_wrappers'] = array('takepart_contests_contest_entry_form_1_button_next');
      break;
    case 2:
      $form['next']['#attributes']['class'][] = 'finalinfo';
      $form['next']['#takepart_before'] = 'next: ';
      $form['next']['#theme_wrappers'] = array('takepart_contests_contest_entry_form_1_button_next');
      $form['prev']['#attributes']['class'][] = 'backtostepone';
      $form['prev']['#theme_wrappers'] = array('takepart_contests_contest_entry_form_1_button_prev');
      break;
    case 3:
      $form['next']['#attributes']['class'][] = 'reviewentry';
      $form['next']['#takepart_before'] = 'next: ';
      $form['next']['#theme_wrappers'] = array('takepart_contests_contest_entry_form_1_button_next');
      $form['prev']['#attributes']['class'][] = 'backtosteptwo';
      $form['prev']['#theme_wrappers'] = array('takepart_contests_contest_entry_form_1_button_prev');
      break; 
    case 4:
      $form['submit']['#attributes']['class'][] = 'submitentry';
      $form['submit']['#takepart_before'] = '';
      $form['submit']['#theme_wrappers'] = array('takepart_contests_contest_entry_form_1_button_next');
      $form['prev']['#attributes']['class'][] = 'backtostepthree';
      $form['prev']['#theme_wrappers'] = array('takepart_contests_contest_entry_form_1_button_prev');
      break;
  }

  $form['#tree'] = TRUE; // We want to deal with hierarchical form values.

  // step field used by theme template to adjust display of step 4
  $form['#step'] = array('#type' => 'hidden', '#value' => $step);
  
  // the date field is a little finicky
  if (($step == 2 || $step == 4) && isset($form_state['storage']['values']['field_custom_273'])) {
    $language = $form['field_custom_273']['#language'];
    $stored_date = $form_state['storage']['values']['field_custom_273'][$language][0]['value'];
    $default_date = date('Y-m-d H:i:s', strtotime($stored_date));
    $form['field_custom_273'][$language][0]['#default_value']['value'] = $default_date;
  }
  
  //Fill form with 
  //_takepart_contests_refillfromstep($form, $form_state, $step);

//  _takepart_contests_setrequired($form, $step);

  
  return $form;
}

function takepart_contests_form_takepart_contests_contest_entry_form_1_alter(&$form, &$form_state, $form_id) {

  // remove the metatags part of the form
  unset($form['metatags']);
  $form['#submit'] = array_diff($form['#submit'], array('metatag_metatags_form_submit'));
}

function takepart_contests_contest_entry_form_1_validate($form, $form_state) {

  // validate the attached fields
  $entry = $form_state['takepart_contests_contest_entry'];
  field_attach_form_validate('takepart_contests_contest_entry', $entry, $form, $form_state);
}

function takepart_contests_contest_entry_form_callback_1($form, $form_state) {
  return $form;
}

function _takepart_contests_refillfromstep(&$form, &$form_state, $step) {
  if(array_key_exists('#fieldgroups', $form)) {
    //Itterate through groups and find the fields applicable to the groups:
    foreach ($form['#fieldgroups'] as $gkey => $gvalue) {
      if(strrpos($gkey, 'group_step') > -1) {
        $groupstep = substr($gkey, strlen('group_step'), strlen($gkey));
        $fieldset = $gvalue->children;
        //Itterate through the form state, and match up saved fields with their cooresponding groups:
        if(isset($form_state['storage']['values']['step' . $groupstep])) {
          foreach ($form_state['storage']['values']['step' . $groupstep] as $fieldKey => $storagevalue) {
            //If we're on step 4, fill them all, otherwise fill the fields in the group/step we are on:
            if (((!is_null(array_search($fieldKey, $fieldset))) || ($step ==4)) && array_key_exists($fieldKey, $form) && is_array($form[$fieldKey])) {
              //Place the values from form state back into the form:
              foreach ($storagevalue['und'] as $und_key => $und_value) {
                if(array_key_exists('#default_value', $form[$fieldKey]['und']) && is_array($form[$fieldKey]['und']['#default_value'])) {
                  //Fill Checkboxes:
                  if(array_key_exists('#type', $form[$fieldKey]['und']) && $form[$fieldKey]['und']['#type'] == "checkboxes") {
                    $form[$fieldKey]['und']['#default_value'][$und_key] = $und_value['value'];
                    $form[$fieldKey]['und'][$und_value['value']]['#attributes'] = array('checked' => 'checked');
                  }
                  //Fill Selects:
                  if(array_key_exists('#type', $form[$fieldKey]['und']) && $form[$fieldKey]['und']['#type'] == "select") {
                    $form[$fieldKey]['und']['#default_value'][$und_key] = $und_value['value'];
                  }
                } else if (array_key_exists($und_key, $form[$fieldKey]['und']) && is_array($form[$fieldKey]['und'])) {
                  //Fill Date Combos:
                  if(array_key_exists('#type', $form[$fieldKey]['und'][$und_key]) && $form[$fieldKey]['und'][$und_key]['#type'] == 'date_combo') {
                    if(is_array($form[$fieldKey]['und'][$und_key]['#default_value'])) {
                      $form[$fieldKey]['und'][$und_key]['#default_value']['value'] = date('Y-m-d H:i:s', strtotime($und_value['value']));
                    }
                  } else {
                    //Fill Text Areas and Text Fields:
                    if(array_key_exists('#type', $form[$fieldKey]['und'][$und_key]['value']) && ($form[$fieldKey]['und'][$und_key]['value']['#type'] == 'textarea' || $form[$fieldKey]['und'][$und_key]['value']['#type'] == 'textfield')) {
                      $form[$fieldKey]['und'][$und_key]['value']['#default_value'] = $und_value['value'];
                    }
                  }
                }

              }
            }
          }
        }
      }
    }
  }
}

function _takepart_contests_gettabindex(&$form, $match) {
  $x = 0;
  if(array_key_exists('#fieldgroups', $form)) {
    foreach ($form['#fieldgroups'] as $gkey => $gvalue) {
      if(strrpos($gkey, 'group_step') > -1) {
        $groupstep = substr($gkey, strlen('group_step'), strlen($gkey));
        $fieldset = $gvalue->children;
        $matchloc = array_search($match, $fieldset);
        if(empty($matchloc)) {
          $x = $x + count($fieldset);
        } else {
          $x = $x + $matchloc + 1;
        }
      }
    }
  }
  return $x;
}



function takepart_contests_contest_entry_form_submit_1(&$form, &$form_state) {

  global $user;
  
  $current_step = $form_state['storage']['step'];

  $submit_trigger = $form_state['triggering_element']['#value'];
  if ($submit_trigger == t('Next step')) {

    // going on to the next step so save values from this step
    $current_group = 'group_step' . $current_step;
    foreach ($form['#group_children'] as $field_name => $group_name) {
      if ($group_name == $current_group) {
        if (isset($form_state['values'][$field_name])) {
          $form_state['storage']['values'][$field_name] =
            $form_state['values'][$field_name];
        }
      }
    }
 
    // proceed to the next step
    $form_state['storage']['step']++;
    
    // load any values we have for next group in case we have been going
    // back and forth (step 4 gets all the values)
    $current_group = 'group_step' . $current_step;
    foreach ($form['#group_children'] as $field_name => $group_name) {
      if ($group_name == $current_group || $current_step == 4) {
        if (isset($form_state['storage']['values'][$field_name])) {
          $form_state['values'][$field_name] =
            $form_state['storage']['values'][$field_name];
        }
      }
    }
    
    $form_state['rebuild'] = TRUE;
  }
  
  else if ($submit_trigger == t('Previous step')) {
    
    // we have limit validation errors turned on so we don't have access to
    // any partial data the user may have entered
    
    // proceed to the previous step
    $form_state['storage']['step']--;

    // load any values we have for the previous group
    $current_group = 'group_step' . $current_step;
    foreach ($form['#group_children'] as $field_name => $group_name) {
      if ($group_name == $current_group) {
        if (isset($form_state['storage']['values'][$field_name])) {
          $form_state['values'][$field_name] =
            $form_state['storage']['values'][$field_name];
        }
      }
    }
    
    $form_state['rebuild'] = TRUE;
  }
  else if ($submit_trigger == t('Submit your information')) {
    
    // get the working entry
    $entry = $form_state['takepart_contests_contest_entry'];
    
    // build the contest entry entity from the form
    entity_form_submit_build_entity('takepart_contests_contest_entry', $entry,
      $form, $form_state);
    
    // check if the entry is allowed
    if (takepart_contests_contest_entry_allowed($entry)) {
    
      // set/update the created and changed timestamps
      $entry->is_new = isset($entry->is_new) ? $entry->is_new : 0;
      if ($entry->is_new) {
        $entry->created = time();
      }
      $entry->changed = time();
     
      // set the associated user
      $entry->uid = $user->uid;
    
      // save the entry
      if ($entry->save()) {

        // TODO: remove hardcoded referrence to profile email field
        $language = isset($entry->language) ? $entry->language : LANGUAGE_NONE;
        $email = $entry->field_profile_email[$language][0]['value'];
        
        // set the entered metric cookie
        $contest = takepart_contests_contest_load($entry->contest_id);
        setcookie('contest_entered', $contest->name);
        
        // set the contest entered as cookie for use in pre-populating the
        // share email
        setcookie('contest_entered_as', $email);
      
        // redirect to the thank you page
        drupal_goto('marigold/thankyou');
      }
      else {
        drupal_set_message( t('The contest entry could not be saved.'), 'error' );
      }
    }
    else {
      drupal_set_message( t('Your entry for this contest has already been received.'), 'error' );
    }
  }
}
