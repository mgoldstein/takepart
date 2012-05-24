<?php

class IdeasForGoodFinalistUIController extends EntityDefaultUIController {

  public function hook_menu() {

    $items = parent::hook_menu();

    // page for adding finalists
    $items[$this->path . '/add'] = array(
      'title' => t('Add a finalist'),
      'page callback' => 'ideasforgood_finalist_form_wrapper',
      'access callback' => 'ideasforgood_finalist_access',
      'access arguments' => array('edit'),
      'file' => 'finalist.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module']),
      'type' => MENU_LOCAL_ACTION,
    );

    return $items;
  }
}

function ideasforgood_finalist_form_wrapper() {
  $finalist = entity_get_controller('ideasforgood_finalist')->create();
  return entity_ui_get_form('ideasforgood_finalist', $finalist, 'add');
}

function ideasforgood_finalist_form($form, &$form_state, $finalist, $op = 'edit') {

  if ($op == 'clone') {
    $finalist->token .= " (cloned)";
  }

  $form['token'] = array(
    '#type' => 'textfield',
    '#title' => t('Token'),
    '#description' => t('The voting token for the finalist'),
    '#default_value' => isset($finalist->token) ? $finalist->token : '',
    '#required' => TRUE,
    '#maxlength' => 255,
    '#size' => 64,
  );

  $form['voting_group'] = array(
    '#type' => 'textfield',
    '#title' => t('Voting Group'),
    '#description' => t('The voting group to which the finalist belongs.'),
    '#default_value' => isset($finalist->voting_group) ? $finalist->voting_group : '',
    '#required' => TRUE,
    '#maxlength' => 255,
    '#size' => 64,
  );

  $form_state['ideasforgood_finalist'] = $finalist;
  field_attach_form('ideasforgood_finalist', $finalist, $form, $form_state);

  $form['actions'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('form-actions')),
    '#weight' => 400,
  );
  $submit = array();
  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save finalist'),
    '#weight' => 40,
    '#submit' => $submit + array('ideasforgood_finalist_form_submit'),
  );

  // only add the delete button if we are editting an existing petition
  if (! empty($finalist->id)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete finalist '),
      '#submit' => $submit + array('ideasforgood_finalist_form_submit_delete'),
      '#weight' => 45,
    );
  }

  $form['actions']['cancel'] = array(
    '#type' => 'markup',
    '#markup' => l(t('Cancel'), 'admin/content/ideasforgood/finalists'),
    '#weight' => 50,
  );

  $form['#validate'][] = 'ideasforgood_finalist_form_validate';

  return $form;
}

function ideasforgood_finalist_form_validate(&$form, &$form_state) {

  // validate the attached fields
  $finalist = $form_state['ideasforgood_finalist'];
  field_attach_form_validate('ideasforgood_finalist', $finalist, $form, $form_state);
}

function ideasforgood_finalist_form_submit(&$form, &$form_state) {

  // build the petition entity from the form
  $controller = entity_ui_controller('ideasforgood_finalist');
  $finalist = $controller->entityFormSubmitBuildEntity($form, $form_state);

  // save the petition
  $status = $finalist->save();
  if ($status == SAVED_UPDATED) {
    drupal_set_message(t('The finalist %token has been updated.',
      array('%token' => $finalist->token)));
  }
  else if ($status == SAVED_NEW) {
    drupal_set_message(t('The finalist %token has been added.',
      array('%token' => $finalist->token)));
  }

  // go back to the list of petitions
  $form_state['redirect'] = 'admin/content/ideasforgood/finalists';
}

function ideasforgood_finalist_form_submit_delete(&$form, &$form_state) {

  // go to the delete confirmation page
  $form_state['redirect'] = 'admin/content/ideasforgood/finalists/manage/'
    . $form_state['ideasforgood_finalist']->id
    . '/delete?destination=admin/content/ideasforgood/finalists';
}

