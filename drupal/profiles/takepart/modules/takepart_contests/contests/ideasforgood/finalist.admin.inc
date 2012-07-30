<?php
/**
 * @file
 * Administrative interface for Ideas for Good Finalists.
 */

/**
 * Ideas for Good Finalist Admin UI Controller
 */
class IdeasForGoodFinalistUIController extends EntityDefaultUIController {

  public function hook_menu() {
    $items = parent::hook_menu();
    
    // Update the description for the main admin page.
    $items[$this->path]['description'] = 'Add a Marigold Ideas for Good voting finalist.';

    return $items;
  }
}

/**
 * Finalist entity form
 */
function ideasforgood_finalist_form($form, &$form_state, $entity, $op = 'edit') {

  $form_state['ideasforgood_finalist'] = $entity;

  if ($op == 'clone') {
    $entity->id = '';
    $entity->token .= " (cloned)";
    $entity->is_new = TRUE;
  }

  $form['token'] = array(
    '#title' => t('Token'),
    '#description' => t('The voting token for the finalist'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#maxlength' => 255,
    '#size' => 64,
    '#default_value' => $entity->token,
  );

  $form['voting_group'] = array(
    '#title' => t('Voting Group'),
    '#description' => t('The voting group to which the finalist belongs.'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#maxlength' => 255,
    '#size' => 64,
    //'#autocomplete_path' => 'admin/config/marigold-ideas-for-good/groups/autocomplete',
    '#default_value' => $entity->voting_group,
  );

  field_attach_form('ideasforgood_finalist',
    $form_state['ideasforgood_finalist'], $form, $form_state);

  $form['actions'] = array('#type' => 'actions');
  $submit = array();
  if (! empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save finalist'),
    '#weight' => 40,
    '#submit' => $submit + array('ideasforgood_finalist_form_submit'),
  );

  // only add the delete button if we are editting an existing entity
  $id = $entity->identifier();
  if (! empty($id)) {
    $form['actions']['delete'] = array(
      '#value' => t('Delete finalist'),
      '#type' => 'submit',
      '#weight' => 45,
      '#submit' => array('ideasforgood_finalist_form_submit_delete'),
    );
  }

  $form['actions']['cancel'] = array(
    '#type' => 'markup',
    '#markup' => l(t('Cancel'), 'admin/config/marigold-ideasforgood/finalists'),
    '#weight' => 50,
  );

  $form['#validate'][] = 'ideasforgood_finalist_form_validate';

  return $form;
}

/**
 * Finalist entity form validation handler
 */
function ideasforgood_finalist_form_validate(&$form, &$form_state) {
  // Validate the attached fields.
  field_attach_form_validate('ideasforgood_finalist',
    $form_state['ideasforgood_finalist'], $form, $form_state);
}

/**
 * Finalist entity form save handler
 */
function ideasforgood_finalist_form_submit(&$form, &$form_state) {

  // build the contest entity from the form
  $entity = entity_ui_form_submit_build_entity($form, $form_state);

  // Save the entity.
  $status = $entity->save();
  if ($status == SAVED_UPDATED) {
    drupal_set_message(t('The finalist %name has been updated.',
      array('%name' => $entity->token)));
  }
  else if ($status == SAVED_NEW) {
    drupal_set_message(t('The finalist %name has been added.',
      array('%name' => $entity->token)));
  }

  // Go back to the list of entities.
  $form_state['redirect'] = 'admin/config/marigold-ideasforgood/finalists';
}

/**
 * Finalist entity form delete handler
 */
function ideasforgood_finalist_form_submit_delete(&$form, &$form_state) {
  // Go to the delete confirmation page.
  $form_state['redirect'] = array(
    'admin/config/marigold-ideasforgood/finalists/manage/'
      . (string) $form_state['ideasforgood_finalist']->identifier()
      . '/delete',
    array(
      'query' => array(
        'destination' => 'admin/config/marigold-ideasforgood/finalists',
      ),
    ),
  );
}
