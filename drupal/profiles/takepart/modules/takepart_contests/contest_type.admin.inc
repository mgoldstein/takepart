<?php

/**
 * @file
 * Administrative interface for Contest Types
 */

/**
 * Contest Type Admin UI Controller
 */
class TakePartContestTypeUIController extends EntityDefaultUIController {

  public function hook_menu() {

    // add a link to the Structure admin page
    $items = parent::hook_menu();
    $items[$this->path]['description'] = 'Manage contest types, including adding and removing fields and the display of fields.';

    return $items;
  }
}

/**
 * Contest Type entity form
 */
function takepart_contests_contest_type_form($form, &$form_state, $contest_type, $op = 'edit') {

  $form_state['contest_type'] = $contest_type;

  // update the label and reset the type if we are cloning the type
  if ($op == 'clone') {
    $contest_type->label .= ' (cloned)';
    $contest_type->type = '';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => isset($contest_type->label) ? $contest_type->label : '',
    '#description' => t('The human-readable name of the contest type'),
    '#required' => TRUE,
    '#size' => 30,
  );

  $form['type'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($contest_type->type) ? $contest_type->type : '',
    '#maxlength' => 32,
    '#machine_name' => array(
      'exists' => 'takepart_contests_get_types',
      'source' => array('label'),
    ),
    '#description' => t('A unqiue machine-readable name for this contest type. It must only contain lowercase letters, numbers and underscores.'),
  );

  $form['actions'] = array('#type' => 'actions');
  $submit = array();
  if (! empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save contest type'),
    '#weight' => 40,
    '#submit' => $submit + array('takepart_contests_contest_type_form_submit'),
  );

  // only add the delete button if we are editting an existing contest type
  if (! empty($contest_type->id)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete contest type'),
      '#submit' => $submit + array('takepart_contests_contest_type_form_submit_delete'),
      '#weight' => 45,
    );
  }

  $form['actions']['cancel'] = array(
    '#type' => 'markup',
    '#markup' => l(t('Cancel'), 'admin/structure/contest_types'),
    '#weight' => 50,
  );

  return $form;
}

/**
 * Contest Type entity form save handler
 */
function takepart_contests_contest_type_form_submit(&$form, &$form_state) {

  // build the contest type entity from the form
  $contest_type = entity_ui_form_submit_build_entity($form, $form_state);

  // save the contest type
  $status = $contest_type->save();
  if ($status == SAVED_UPDATED) {
    drupal_set_message(t('The contest type %name has been updated.',
      array('%name' => $contest_type->label)));
  }
  else if ($status == SAVED_NEW) {
    drupal_set_message(t('The contest type %name has been added.',
      array('%name' => $contest_type->label)));
  }

  // go back to the list of content types
  $form_state['redirect'] = 'admin/structure/contest_types';
}

/**
 * Contest Type entity form delete handler
 */
function takepart_contests_contest_type_form_submit_delete(&$form, &$form_state) {

  // go to the delete confirmation page
  $type = $form_state['contest_type']->type;
  $form_state['redirect'] = 'admin/structure/contest_types/manage/' . $type . '/delete?destination=admin/structure/contest_types';
}
