<?php

class IdeasForGoodVotingGroupUIController extends EntityDefaultUIController {

  public function hook_menu() {

    $items = parent::hook_menu();

    // page for adding groups
    $items[$this->path . '/add'] = array(
      'title' => t('Add a group'),
      'page callback' => 'ideasforgood_voting_group_form_wrapper',
      'access callback' => 'ideasforgood_finalist_access',
      'access arguments' => array('edit'),
      'file' => 'voting_group.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module']),
      'type' => MENU_LOCAL_ACTION,
    );

    $items[$this->path . '/autocomplete'] = array(
      'title' => 'Marigold Ideas for Good voting group autocomplete',
      'page callback' => 'ideasforgood_voting_group_autocomplete',
      'access callback' => 'ideasforgood_finalist_access',
      'access arguments' => array('view'),
      'type' => MENU_CALLBACK,
    );

    return $items;
  }
}

function ideasforgood_voting_group_form_wrapper() {
  $group = entity_get_controller('ideasforgood_voting_group')->create();
  return entity_ui_get_form('ideasforgood_voting_group', $group, 'add');
}

function ideasforgood_voting_group_form($form, &$form_state, $group, $op = 'edit') {

  if ($op == 'clone') {
    $group->name .= " (cloned)";
  }

  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#description' => t('The name of the voting group'),
    '#default_value' => isset($group->name) ? $group->name : '',
    '#required' => TRUE,
    '#maxlength' => 32,
    '#size' => 24,
  );

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
    '#value' => t('Save group'),
    '#weight' => 40,
    '#submit' => $submit + array('ideasforgood_voting_group_form_submit'),
  );

  // only add the delete button if we are editting an existing petition
  if (! empty($group->id)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete group '),
      '#submit' => $submit + array('ideasforgood_voting_group_form_submit_delete'),
      '#weight' => 45,
    );
  }

  $form['actions']['cancel'] = array(
    '#type' => 'markup',
    '#markup' => l(t('Cancel'), 'admin/content/ideasforgood/groups'),
    '#weight' => 50,
  );

  return $form;
}

function ideasforgood_voting_group_form_submit(&$form, &$form_state) {

  // build the petition entity from the form
  $controller = entity_ui_controller('ideasforgood_voting_group');
  $group = $controller->entityFormSubmitBuildEntity($form, $form_state);

  // save the petition
  $status = $group->save();
  if ($status == SAVED_UPDATED) {
    drupal_set_message(t('The group %name has been updated.',
      array('%name' => $group->name)));
  }
  else if ($status == SAVED_NEW) {
    drupal_set_message(t('The group %name has been added.',
      array('%name' => $group->name)));
  }

  // go back to the list of petitions
  $form_state['redirect'] = 'admin/content/ideasforgood/groups';
}

function ideasforgood_voting_group_form_submit_delete(&$form, &$form_state) {

  // go to the delete confirmation page
  $form_state['redirect'] = 'admin/content/ideasforgood/groups/manage/'
    . $form_state['ideasforgood_voting_group']->id
    . '/delete?destination=admin/content/ideasforgood/groups';
}

function ideasforgood_voting_group_autocomplete($string = '') {
  $matches = array();
  if ($string) {
    $results = db_select('ideasforgood_voting_group', 'g')
      ->fields('g', array('name'))
      ->condition('name', db_like($string) . '%', 'LIKE')
      ->range(0, 10)
      ->execute();
    foreach($results as $result) {
      $group = $result['name'];
      $matches[$group] = check_plain($group);
    }
  }
  drupal_json_output($matches);
}

