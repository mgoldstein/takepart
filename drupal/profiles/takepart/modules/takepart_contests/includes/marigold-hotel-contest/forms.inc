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

  //pull values from session:
  foreach ($form_state['storage']['values']['step'.$step] as $key => $value) {
    if (array_key_exists($key, $form)) {
      if(is_array($form[$key]) && isset($form[$key]['und'][0]['value']) && isset($value['und'][0]['value'])) {
        $form[$key]['und'][0]['value']['#default_value'] = $value['und'][0]['value'];
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
                $form[$value->{'children'}[$i]]['und'][0]['value']['#attributes'] = array('maxlength' => "140");
              }
            }
          }
          //How does your idea address a community:
          if('field_custom_266' == $value->{'children'}[$i]){
            if (array_key_exists($value->{'children'}[$i], $form)) {
              if(isset($form[$value->{'children'}[$i]]['und'][0]['value'])) {
                $form[$value->{'children'}[$i]]['und'][0]['value']['#required'] = TRUE;
                $form[$value->{'children'}[$i]]['und'][0]['value']['#columns'] = 40;
                $form[$value->{'children'}[$i]]['und'][0]['value']['#rows'] = 8;
                $form[$value->{'children'}[$i]]['und'][0]['value']['#attributes'] = array('maxlength' => "700");
              }
            }
          }
          //How would winning $5000:
          if('field_custom_267' == $value->{'children'}[$i]){
            if (array_key_exists($value->{'children'}[$i], $form)) {
              if(isset($form[$value->{'children'}[$i]]['und'][0]['value'])) {
                $form[$value->{'children'}[$i]]['und'][0]['value']['#required'] = TRUE;
                $form[$value->{'children'}[$i]]['und'][0]['value']['#columns'] = 40;
                $form[$value->{'children'}[$i]]['und'][0]['value']['#rows'] = 8;
                $form[$value->{'children'}[$i]]['und'][0]['value']['#attributes'] = array('maxlength' => "700");
              }
            }
          }
          //What inspires you about this idea:
          if('field_custom_270' == $value->{'children'}[$i]){
            if (array_key_exists($value->{'children'}[$i], $form)) {
              if(isset($form[$value->{'children'}[$i]]['und'][0]['value'])) {
                $form[$value->{'children'}[$i]]['und'][0]['value']['#required'] = TRUE;
                $form[$value->{'children'}[$i]]['und'][0]['value']['#columns'] = 40;
                $form[$value->{'children'}[$i]]['und'][0]['value']['#rows'] = 8;
                $form[$value->{'children'}[$i]]['und'][0]['value']['#attributes'] = array('maxlength' => "700");
              }
            }
          }
        }
      }
    }
  }

  /*
  $form['test'] = array(
      '#markup' => '<div>'. t('Step:' . $step) . ' / ' . t('Time:' . time()) . '</div>',
  );
  */


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
       '#value' => t("TEST SUBMIT"),
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

function takepart_contests_contest_entry_form_submit_1(&$form, &$form_state) {

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

}