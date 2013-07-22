<?php
/**
 * @file
 * Administrative interface for Ideas for Good Voting Groups.
 */

/**
 * Ideas for Good Voting Group Admin UI Controller
 */
class IdeasForGoodVotingGroupUIController extends EntityDefaultUIController {

  public function hook_menu() {
    $items = parent::hook_menu();

    // Update the description for the main admin page.
    $items[$this->path]['description'] = 'Manage Ideas for Good voting groups.';

    $items[$this->path . '/autocomplete'] = array(
      'title' => 'Voting Group autocomplete',
      'page callback' => 'ideasforgood_voting_group_autocomplete',
      'access callback' => 'user_access',
      'access arguments' => array('view ideasforgood ideasforgood_voting_group'),
      'file' => 'voting_group.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module']),
      'type' => MENU_CALLBACK,
    );

    return $items;
  }
}

/**
 * Voting Group name JSON callback
 */
function ideasforgood_voting_group_autocomplete($string = '') {
  $matches = array();
  if ($string) {
    $result = db_select('ideasforgood_voting_group', 'g')
      ->fields('g', array('name'))
      ->condition('g.name', db_like($string) . '%', 'LIKE')
      ->range(0, 10)
      ->execute();
    foreach ($result as $group) {
      $matches[$group->name] = check_plain($group->name);
    }
  }
  drupal_json_output($matches);
}

/**
 * Voting Group entity form
 */
function ideasforgood_voting_group_form($form, &$form_state, $entity,
  $op = 'edit') {

  $form_state['ideasforgood_voting_group'] = $entity;

  if ($op == 'clone' && !isset($form_state['values'])) {
    $entity->id = '';
    $entity->name .= " (cloned)";
    $entity->is_new = TRUE;
  }

  $defaults = array(
    'name' => $entity->name,
    'contest' => $entity->contest,
    'voting_form_id' => $entity->voting_form_id,
    'email_field_id' => $entity->email_field_id,
    'vote_field_id' => $entity->vote_field_id,
    'opt_in_field_id' => $entity->opt_in_field_id,
  );
  $values = array();
  foreach ($defaults as $name => $value) {
    if (isset($form_state['values'][$name])) {
      $values[$name] = $form_state['values'][$name];
    }
    else {
      $values[$name] = $value;
    }
  }

  $form['name'] = array(
    '#title' => t('Name'),
    '#description' => t('The name of the voting group'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#maxlength' => 255,
    '#size' => 64,
    '#default_value' => $values['name'],
  );

  $contest_names = array(
   $values['contest'] => $values['contest'],
  );
  foreach (entity_load('takepart_contests_contest') as $id => $contest) {
    $contest_names[$contest->name] = $contest->name;
  }
  $form['contest'] = array(
    '#title' => t('Contest'),
    '#description' => t('The name of the contest for which votes are being submitted'),
    '#type' => 'select',
    '#required' => TRUE,
    '#options' => $contest_names,
    '#default_value' => $values['contest'],
  );

  field_attach_form('ideasforgood_voting_group',
    $form_state['ideasforgood_voting_group'], $form, $form_state);

  $form['actions'] = array('#type' => 'actions');
  $submit = array();
  if (! empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save group'),
    '#weight' => 40,
    '#submit' => $submit + array('ideasforgood_voting_group_form_submit'),
  );

  // only add the delete button if we are editting an existing entity
  $id = $entity->identifier();
  if (! empty($id)) {
    $form['actions']['delete'] = array(
      '#value' => t('Delete group'),
      '#type' => 'submit',
      '#weight' => 45,
      '#submit' => array('ideasforgood_voting_group_form_submit_delete'),
    );
  }

  $form['actions']['cancel'] = array(
    '#type' => 'markup',
    '#markup' => l(t('Cancel'), 'admin/config/marigold-ideasforgood/groups'),
    '#weight' => 50,
  );

  $form['#validate'][] = 'ideasforgood_voting_group_form_validate';

  return $form;
}

/**
 * Voting Group entity form validation handler
 */
function ideasforgood_voting_group_form_validate(&$form, &$form_state) {
  // Validate the attached fields.
  field_attach_form_validate('ideasforgood_voting_group',
    $form_state['ideasforgood_voting_group'], $form, $form_state);
}

/**
 * Voting Group entity form save handler
 */
function ideasforgood_voting_group_form_submit(&$form, &$form_state) {

  // build the contest entity from the form
  $entity = entity_ui_form_submit_build_entity($form, $form_state);

  // Save the entity.
  $status = $entity->save();
  if ($status == SAVED_UPDATED) {
    drupal_set_message(t('The group %name has been updated.',
      array('%name' => $entity->name)));
  }
  else if ($status == SAVED_NEW) {
    drupal_set_message(t('The group %name has been added.',
      array('%name' => $entity->name)));
  }

  // Go back to the list of entities.
  $form_state['redirect'] = 'admin/config/marigold-ideasforgood/groups';
}

/**
 * Voting Group entity form delete handler
 */
function ideasforgood_voting_group_form_submit_delete(&$form, &$form_state) {
  // Go to the delete confirmation page.
  $form_state['redirect'] = array(
    'admin/config/marigold-ideasforgood/groups/manage/'
      . (string) $form_state['ideasforgood_voting_group']->identifier()
      . '/delete',
    array(
      'query' => array(
        'destination' => 'admin/config/marigold-ideasforgood/groups',
      ),
    ),
  );
}
