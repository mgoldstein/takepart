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
  foreach ($form_state['storage']['values']['step' . $step] as $fieldKey => $storagevalue) {
       
    if (array_key_exists($fieldKey, $form) && is_array($form[$fieldKey])) {
      foreach ($storagevalue['und'] as $und_key => $und_value) {
        if(array_key_exists('#default_value', $form[$fieldKey]['und']) && is_array($form[$fieldKey]['und']['#default_value'])) {
          $form[$fieldKey]['und']['#default_value'][$und_key] = $und_value['value'];
          if($form[$fieldKey]['und']['#type'] = "checkboxes") {
            $form[$fieldKey]['und'][$und_value['value']]['#attributes'] = array('checked' => 'checked');
          }          
        } else if (array_key_exists($und_key, $form[$fieldKey]['und']) && is_array($form[$fieldKey]['und'])) {

            
          if($form[$fieldKey]['und'][$und_key]['#type'] == 'date_combo') {
            
            if(is_array($form[$fieldKey]['und'][$und_key]['#default_value'])) {
              $form[$fieldKey]['und'][$und_key]['#default_value']['value'] = date('Y-m-d H:i:s', strtotime($und_value['value']));
            } 
            
          } else {
            $form[$fieldKey]['und'][$und_key]['value']['#default_value'] = $und_value['value'];
                        
          }
          
        }
      }
    }
  }

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
                $form[$value->{'children'}[$i]]['und'][0]['value']['#required'] = TRUE;
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
                $form[$value->{'children'}[$i]]['und'][0]['value']['#required'] = FALSE;
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
                $form[$value->{'children'}[$i]]['und'][0]['value']['#required'] = FALSE;
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
                $form[$value->{'children'}[$i]]['und'][0]['value']['#required'] = FALSE;
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
                $form[$value->{'children'}[$i]]['und'][0]['value']['#required'] = FALSE;
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
        '#markup' => "<div>Please confirm your information below to finalize your submission.</div>",
    );
    //Add confirm msg to field group:
    foreach ($form['#fieldgroups'] as $key => $value) {
      if($value->{'group_name'} == 'group_step3') {
        if(is_array($value->{'children'})) {
          $form['#fieldgroups']['$key']->{'children'} = array_merge(array('confirm_msg'),  $form['#fieldgroups']['$key']->{'children'});
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
        //'#limit_validation_errors' => array(),
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

  if (($form_state['triggering_element']['#value'] == t('Submit your information')) || ($form_state['triggering_element']['#value'] == t('Test Submit'))) {

    

    
    
    // build the contest entry entity from the form
    entity_form_submit_build_entity('takepart_contests_contest_entry', $form_state['takepart_contests_contest_entry'], $form, $form_state);
    $entry = $form_state['takepart_contests_contest_entry'];
    
    // set/update the created and changed timestamps
    $entry->is_new = isset($entry->is_new) ? $entry->is_new : 0;
    if ($entry->is_new) {
      $entry->created = time();
    }
    $entry->changed = time();
    
    // set the associated user
    $entry->uid = $user->uid;
    
    // save the entry
    $entry->save();
    
    $id_to_read_back = $entry->entry_id;
    
    if(isset($entry->entry_id)) {
       //Where to trigger omniture? 
    }
    
    // read back the entry to make sure that works
    $entry = takepart_contests_contest_entry_load($id_to_read_back);
    
    $contest_name = '';
    
    $result = _takepart_contests_getlist();
    if(!is_null($result)) {
      foreach ($result as $row) {
        if(($row->contest_id) == 1) {
          $contest_name = $row->name;
        }
      }
    }
    
    if(!isnull($entry->entry_id)) {   
      setcookie("contest_entered", $contest_name);
    }
      
    //drupal_set_message(t('The contest entry %id has been saved and read back.', array('%id' => $entry->entry_id)));
    
  }
 

}