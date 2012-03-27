<?php

//Marigold specific forms:

function takepart_contests_contest_entry_form_1($form, &$form_state, $entry, $op) {


  // add the entity fields to the form
  // the entity itself needs to be stored in the form state with
  // the name of the entity (the key used in the entity_info hook) as the key
  $form_state['takepart_contests_contest_entry'] = $entry;
  field_attach_form('takepart_contests_contest_entry', $entry, $form, $form_state);

  $callback = 'takepart_contests_contest_entry_form_callback_1';
  $wrapper = 'takepart_contests_form_wrapper_1';
  $submit = 'takepart_contests_contest_entry_form_submit_1';
  $reqtext = '<span class="reqtext"><span class="form-required">*</span>Indicates required field</span>';

  $form['#tree'] = TRUE; // We want to deal with hierarchical form values.

  $step = empty($form_state['storage']['step']) ? 1 : $form_state['storage']['step'];
  $form_state['storage']['step'] = $step;
  
  
  //Fill form with 
  _takepart_contests_refillfromstep($form, $form_state, $step);


  foreach ($form as $key => $value) {
    if ((is_array($form[$key])) && (isset($form[$key]['und'][0]['value']['#description'])) && (!empty($form[$key]['und'][0]['value']['#description']))) {
      $form[$key]['und'][0]['value']['#title'] = $form[$key]['und'][0]['value']['#description'];
      $form[$key]['und'][0]['value']['#description'] = "";
    }
  }

  //Itterate through field groups, if we're on a step that matches a group,
  //assign field settings to the applicable fields in that group:
  foreach ($form['#fieldgroups'] as $key => $value) {
    if($value->{'group_name'} == 'group_step'.$step) {
      if(is_array($value->{'children'})) {
        for($i = 0; $i < count($value->{'children'}); $i++) {
          //Describe your idea:
          if('field_custom_265' == $value->{'children'}[$i]){
            if (array_key_exists($value->{'children'}[$i], $form)) {
              if(isset($form[$value->{'children'}[$i]]['und'][0]['value'])) {
                //$form[$value->{'children'}[$i]]['und'][0]['value']['#required'] = TRUE;
                $form[$value->{'children'}[$i]]['und'][0]['value']['#columns'] = 40;
                $form[$value->{'children'}[$i]]['und'][0]['value']['#rows'] = 2;     
                if($step == 4) {
                  $form[$value->{'children'}[$i]]['und'][0]['value']['#attributes'] = array('maxlength' => "140", 'readonly' => "readonly");
                } else {
                  $form[$value->{'children'}[$i]]['und'][0]['value']['#attributes'] = array('maxlength' => "140");
                }
              }
            }
          }
          //How does your idea address a community:
          if('field_custom_266' == $value->{'children'}[$i]){
            if (array_key_exists($value->{'children'}[$i], $form)) {
              if(isset($form[$value->{'children'}[$i]]['und'][0]['value'])) {
                //$form[$value->{'children'}[$i]]['und'][0]['value']['#required'] = FALSE;
                $form[$value->{'children'}[$i]]['und'][0]['value']['#columns'] = 40;
                $form[$value->{'children'}[$i]]['und'][0]['value']['#rows'] = 8;
                if($step == 4) {
                  $form[$value->{'children'}[$i]]['und'][0]['value']['#attributes'] = array('maxlength' => "700", 'readonly' => "readonly");
                } else {
                  $form[$value->{'children'}[$i]]['und'][0]['value']['#attributes'] = array('maxlength' => "700");
                }
              }
            }
          }
          //How would winning $5000:
          if('field_custom_267' == $value->{'children'}[$i]){
            if (array_key_exists($value->{'children'}[$i], $form)) {
              if(isset($form[$value->{'children'}[$i]]['und'][0]['value'])) {
                //$form[$value->{'children'}[$i]]['und'][0]['value']['#required'] = FALSE;
                $form[$value->{'children'}[$i]]['und'][0]['value']['#columns'] = 40;
                $form[$value->{'children'}[$i]]['und'][0]['value']['#rows'] = 8;
                if($step == 4) {
                  $form[$value->{'children'}[$i]]['und'][0]['value']['#attributes'] = array('maxlength' => "700", 'readonly' => "readonly");
                } else {
                  $form[$value->{'children'}[$i]]['und'][0]['value']['#attributes'] = array('maxlength' => "700");
                }
              }
            }
          }
          //What inspires you about this idea:
          if('field_custom_270' == $value->{'children'}[$i]){
            if (array_key_exists($value->{'children'}[$i], $form)) {
              if(isset($form[$value->{'children'}[$i]]['und'][0]['value'])) {
                //$form[$value->{'children'}[$i]]['und'][0]['value']['#required'] = FALSE;
                $form[$value->{'children'}[$i]]['und'][0]['value']['#columns'] = 40;
                $form[$value->{'children'}[$i]]['und'][0]['value']['#rows'] = 8;
                if($step == 4) {
                  $form[$value->{'children'}[$i]]['und'][0]['value']['#attributes'] = array('maxlength' => "700", 'readonly' => "readonly");
                } else {
                  $form[$value->{'children'}[$i]]['und'][0]['value']['#attributes'] = array('maxlength' => "700");
                }
              }
            }
          }
          //How will your work and life experiance help you:
          if('field_custom_271' == $value->{'children'}[$i]){
            if (array_key_exists($value->{'children'}[$i], $form)) {
              if(isset($form[$value->{'children'}[$i]]['und'][0]['value'])) {
                //$form[$value->{'children'}[$i]]['und'][0]['value']['#required'] = FALSE;
                $form[$value->{'children'}[$i]]['und'][0]['value']['#columns'] = 40;
                $form[$value->{'children'}[$i]]['und'][0]['value']['#rows'] = 8;
                if($step == 4) {
                  $form[$value->{'children'}[$i]]['und'][0]['value']['#attributes'] = array('maxlength' => "700", 'readonly' => "readonly");
                } else {
                  $form[$value->{'children'}[$i]]['und'][0]['value']['#attributes'] = array('maxlength' => "700");
                }
              }
            }
          }
        }
      }
    }
  }
  
  if($step == 3) {
    $form['confirm_msg'] = array(
        '#markup' => "<div class=\"confirm_msg\">Please confirm your information below to finalize your submission.</div>",
    );    
    //Add confirm msg to field group:
    foreach ($form['#fieldgroups'] as $key => $value) {
      if($value->{'group_name'} == 'group_step3') {
        if(is_array($value->{'children'})) {
          $form['#fieldgroups'][$key]->{'children'} = array_merge(array('confirm_msg'),  $form['#fieldgroups'][$key]->{'children'});
          if(array_key_exists('#group_children', $form)) {
            $form['#group_children']['confirm_msg'] = 'group_step3';
          }        
        }
      }
    }
  }

  if($step == 4) {
    if(is_array($form['#groups']) && isset($form['#groups']['group_step4_idea'])) {
      if(is_array($form['#groups']['group_step4_idea']->{'format_settings'}) && isset($form['#groups']['group_step4_idea']->{'format_settings'}['instance_settings']['description'])) {
        //this should not be visible, see: themes.inc
        $ideamarkup = ($form['#groups']['group_step4_idea']->{'format_settings'}['instance_settings']['description']);
        $form['ideamarkup'] = array(
            '#markup' => $ideamarkup,
        );
      }
    }
  }

 /*
  $form['submit_test'] = array(
      '#type' => 'submit',
      '#submit' => array($submit),
      '#value' => t("Test Submit"),
      '#weight' => 3000,
  );
*/

  if ($step < 4) {
    $form['reqtext'] = array(
        '#markup' => $reqtext,
        '#weight' => 1990,
    );
    $form['next'] = array(
        '#type' => 'submit',
        '#value' => t('Next step'),
        '#submit' => array($submit),
        '#ajax' => array(
            'wrapper' => $wrapper,
            'callback' => $callback,
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
        '#submit' => array($submit),
        '#ajax' => array(
            'wrapper' => $wrapper,
            'callback' => $callback,
        ),
        '#weight' => 2010,
    );
  }
  if ($step == 4) {
    $form['submit'] = array(
        '#type' => 'submit',
        '#submit' => array($submit),
        '#value' => t("Submit your information"),
        '#weight' => 2005,
    );
  }

  $form['#step'] = array('#type' => 'hidden', '#value' => $step);

  return $form;
}

function takepart_contests_form_takepart_contests_contest_entry_form_1_alter(&$form, &$form_state, $form_id) {

  // remove the metatags part of the form
  unset($form['metatags']);
  $form['#submit'] = array_diff($form['#submit'], array('metatag_metatags_form_submit'));
}

function takepart_contests_contest_entry_form_validate_1($form, $form_state) {

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

function takepart_contests_contest_entry_form_submit_1(&$form, &$form_state) {

  global $user;
  
  // Save away the current information.
  $current_step = 'step' . $form_state['storage']['step'];

  if (!empty($form_state['values'])) {
    $form_state['storage']['values'][$current_step] = $form_state['values'];
  }

  // Increment or decrement the step as needed. Recover values if they exist.
  if ($form_state['triggering_element']['#value'] == t('Next step')) {
    $form_state['storage']['step']++;
    // Recover our values from $form_state['storage'] to pre-populate them.
    $step_name = 'step' . $form_state['storage']['step'];
    if (!empty($form_state['storage']['values'][$step_name])) {
      $form_state['values'][$step_name] = $form_state['storage']['values'][$step_name];
    }
    $form_state['rebuild'] = TRUE;
  }
  if ($form_state['triggering_element']['#value'] == t('Previous step')) {
    $form_state['storage']['step']--;
    // Recover our values from $form_state['storage'] to pre-populate them.
    $step_name = 'step' . $form_state['storage']['step'];
    if (!empty($form_state['storage']['values'][$step_name])) {
      $form_state['values'][$step_name] = $form_state['storage']['values'][$step_name];
    }
    $form_state['rebuild'] = TRUE;
  }

  if ($form_state['triggering_element']['#value'] == t('Test Submit')) {
    $form_state['storage']['step']++;
    $form_state['rebuild'] = TRUE;
  }

  $submit_trigger = $form_state['triggering_element']['#value'];
  $final_submit = ($submit_trigger == t('Submit your information'));
  $test_submit = ($submit_trigger == t('Test Submit'));
  if ($final_submit || $test_submit) {

    // get the working entry
    $entry = $form_state['takepart_contests_contest_entry'];
    
    // check if the entry is allowed
    if (takepart_contests_contest_entry_allowed($entry)) {
    
      // build the contest entry entity from the form
      entity_form_submit_build_entity('takepart_contests_contest_entry', $entry,
        $form, $form_state);
    
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
      
        // set the entered metric cookie
        $contest = takepart_contests_contest_load($entry->contest_id);
        setcookie('contest_entered', $contest->name);
      
        // redirect to the thank you page
        drupal_goto('marigold/thanks');
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
