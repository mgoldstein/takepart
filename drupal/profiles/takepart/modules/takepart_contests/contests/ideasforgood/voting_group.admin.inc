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

    return $items;
  }
}

function ideasforgood_voting_group_form_wrapper() {
  $group = entity_get_controller('ideasforgood_voting_group')->create();
  return entity_ui_get_form('ideasforgood_voting_group', $group, 'add');
}

function ideasforgood_field_id_select($form_id, $value) {

  $element = NULL;
  $options = array();

  if (! empty($form_id)) {

    $fields = takepart_bsd_signup_list_form_fields($form_id);

    if (!empty($fields)) {

      if ((!empty($value)) && (!array_key_exists($value, $fields))) {
        $options[$value] = t('Field ID: @id (not available)', array('@id' => $value));
      }

      foreach ($fields as $id => $field) {
        $options[$id] = sprintf('[%d] %s', $id, $field['label']);
      }
    }
    else {
      $element = array(
        '#type' => 'textfield',
        '#size' => 4,
        '#default_value' => $value,
        '#element_validate' => array('_element_validate_integer_positive'),
      );
    }
  }
  else {
    $options[''] = 'Select a Signup Form';
  }

  if (!isset($element)) {
    $element = array(
      '#type' => 'select',
      '#options' => $options,
      '#default_value' => $value,
    );
  }
  return $element;
}

function ideasforgood_voting_group_form($form, &$form_state, $group, $op = 'edit') {

  if ($op == 'clone') {
    $group->name .= " (cloned)";
  }

  $name = isset($form_state['values']['name'])
    ? $form_state['values']['name'] : $group->name;
  $contest = isset($form_state['values']['contest'])
    ? $form_state['values']['name'] : $group->contest;
  $voting_form_id = isset($form_state['values']['voting_form_id'])
    ? $form_state['values']['voting_form_id'] : $group->voting_form_id;
  $email_field_id = isset($form_state['values']['email_field_id'])
    ? $form_state['values']['email_field_id'] : $group->email_field_id;
  $vote_field_id = isset($form_state['values']['vote_field_id'])
    ? $form_state['values']['vote_field_id'] : $group->vote_field_id;
  $opt_in_field_id = isset($form_state['values']['opt_in_field_id'])
    ? $form_state['values']['opt_in_field_id'] : $group->opt_in_field_id;


  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#description' => t('The name of the voting group'),
    '#default_value' => $name,
    '#required' => TRUE,
    '#maxlength' => 255,
    '#size' => 64,
  );

  $form['contest'] = array(
    '#type' => 'textfield',
    '#title' => t('Contest'),
    '#description' => t('The name of the contest for which votes are being submitted'),
    '#default_value' => $contest,
    '#required' => TRUE,
    '#maxlength' => 255,
    '#size' => 64,
  );

  $form['signupform'] = array(
    '#title' => 'Blue State Digital Signup Tracking',
    '#type' => 'fieldset',
    '#description' => t('Select the Blue State Digital signup form and fields for this voting group.'),
    '#tree' => FALSE,
   );

  $form['signupform']['voting_form_id'] =
    takepart_bsd_form_id_select_field($voting_form_id);
  $form['signupform']['voting_form_id'] += array(
    '#ajax' => array(
      'event' => 'change',
      'callback' => 'ideasforgood_signup_form_id_callback',
      'wrapper' => 'ideasforgood-signup-fields-wrapper',
      'progress' => array(
        'type' => 'throbber',
        'message' => t('Loading fields ...'),
      ),
    ),
  );

  $form['signupform']['fields'] = array(
    '#type' => 'container',
    '#tree' => FALSE,
    '#prefix' => '<div id="ideasforgood-signup-fields-wrapper">',
    '#suffix' => '</div>',
  );

  $form['signupform']['fields']['email_field_id'] =
    ideasforgood_field_id_select($voting_form_id, $email_field_id);
  $form['signupform']['fields']['email_field_id'] += array(
    '#title' => 'Email Field ID',
  );

  $form['signupform']['fields']['vote_field_id'] =
    ideasforgood_field_id_select($voting_form_id, $vote_field_id);
  $form['signupform']['fields']['vote_field_id'] += array(
    '#title' => 'Vote Field ID',
  );

  $form['signupform']['fields']['opt_in_field_id'] =
    ideasforgood_field_id_select($voting_form_id, $opt_in_field_id);
  $form['signupform']['fields']['opt_in_field_id'] += array(
    '#title' => 'Opt-In Field ID',
  );

  $form_state['ideasforgood_voting_group'] = $group;
  field_attach_form('ideasforgood_voting_group', $group, $form, $form_state);

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

  $form['#validate'][] = 'ideasforgood_voting_group_form_validate';

  return $form;
}

function ideasforgood_signup_form_id_callback(&$form, $form_state) {
  return $form['signupform']['fields'];
}

function ideasforgood_voting_group_form_validate(&$form, &$form_state) {
  // validate the attached fields
  $group = $form_state['ideasforgood_voting_group'];
  field_attach_form_validate('ideasforgood_voting_group', $group, $form, $form_state);
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
