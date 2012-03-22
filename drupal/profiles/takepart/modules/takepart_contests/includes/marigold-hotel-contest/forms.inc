<?php

//Marigold specific forms:

function takepart_contests_contest_entry_form_1($form, &$form_state, $entry, $op) {


  // add the entity fields to the form
  // the entity itself needs to be stored in the form state with
  // the name of the entity (the key used in the entity_info hook) as the key
  $form_state['takepart_contests_contest_entry'] = $entry;
  field_attach_form('takepart_contests_contest_entry', $entry, $form, $form_state);

  $callback = 'takepart_contests_contest_entry_form_callback_1';
  $wrapper = 'takepart_contests_wrapper_1';
  $submit = 'takepart_contests_contest_entry_form_submit_1';

  $form['#tree'] = TRUE; // We want to deal with hierarchical form values.

  $step = empty($form_state['storage']['step']) ? 1 : $form_state['storage']['step'];
  $form_state['storage']['step'] = $step;

  if ($step == 4) {
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t("Submit your information"),
        '#weight' => 2000,
    );
  }
  if ($step < 4) {
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

        // Since all info will be discarded, don't validate on 'prev'.
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

  $form_state['rebuild'] = TRUE;

  // Save away the current information.
  $current_step = 'step' . $form_state['storage']['step'];
  if (!empty($form_state['values'][$current_step])) {
    $form_state['storage']['values'][$current_step] = $form_state['values'][$current_step];
  }

  // Increment or decrement the step as needed. Recover values if they exist.
  if ($form_state['triggering_element']['#value'] == t('Next step')) {
    $form_state['storage']['step']++;
    // If values have already been entered for this step, recover them from
    // $form_state['storage'] to pre-populate them.
    $step_name = 'step' . $form_state['storage']['step'];
    if (!empty($form_state['storage']['values'][$step_name])) {
      $form_state['values'][$step_name] = $form_state['storage']['values'][$step_name];
    }
  }
  if ($form_state['triggering_element']['#value'] == t('Previous step')) {
    $form_state['storage']['step']--;
    // Recover our values from $form_state['storage'] to pre-populate them.
    $step_name = 'step' . $form_state['storage']['step'];
    $form_state['values'][$step_name] = $form_state['storage']['values'][$step_name];
  }

}