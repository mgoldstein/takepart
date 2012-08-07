<?php
/**
 * @file
 * Administrative interface for Contest Types.
 */

/**
 * Contest Type Admin UI Controller
 */
class TakePartContestTypeUIController extends EntityDefaultUIController {

  public function hook_menu() {
    $items = parent::hook_menu();
    
    // Update the description for the main admin page.
    $items[$this->path]['description'] = 'Manage the Ideas for Good contest type, including mapping fields to BSD signup fields.';

    // Don't allow any new contests to be added. They need to be re-worked to be
    // node based.
    unset($items[$this->path . '/add']);
    unset($items[$this->path . '/import']);
    return $items;
  }
}

/**
 * Contest Type entity form
 */
function takepart_contests_contest_type_form($form, &$form_state, $entity, $op = 'edit') {

  $form_state['takepart_contests_contest_type'] = $entity;

  // update the label and reset the type if we are cloning the type
  if ($op == 'clone') {
    $entity->id = '';
    $entity->type = '';
    $entity->label .= ' (cloned)';
    $entity->is_new = TRUE;
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#description' => t('The human-readable name of the contest type'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#size' => 30,
    '#default_value' => $entity->label,
  );

  $form['type'] = array(
    '#description' => t('A unqiue machine-readable name for this contest type. It must only contain lowercase letters, numbers and underscores.'),
    '#type' => 'machine_name',
    '#maxlength' => 32,
    '#machine_name' => array(
      'exists' => 'takepart_contests_contest_type_load',
      'source' => array('label'),
    ),
    '#default_value' => $entity->type,
  );

  $form['actions'] = array('#type' => 'actions');
  $submit = array();
  if (! empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#value' => t('Save contest type'),
    '#type' => 'submit',
    '#weight' => 40,
    '#submit' => $submit + array('takepart_contests_contest_type_form_submit'),
  );

  // only add the delete button if we are editting an existing entity
  $id = $entity->identifier();
  if (! empty($id)) {
    $form['actions']['delete'] = array(
      '#value' => t('Delete contest type'),
      '#type' => 'submit',
      '#weight' => 45,
      '#submit' => array('takepart_contests_contest_type_form_submit_delete'),
    );
  }

  $form['actions']['cancel'] = array(
    '#type' => 'markup',
    '#markup' => l(t('Cancel'),
      'admin/config/marigold-ideasforgood/contest_types'),
    '#weight' => 50,
  );

  return $form;
}

/**
 * Contest Type entity form save handler
 */
function takepart_contests_contest_type_form_submit(&$form, &$form_state) {

  // Build entity from the form.
  $entity = entity_ui_form_submit_build_entity($form, $form_state);

  // Save the entity.
  $status = $entity->save();
  if ($status == SAVED_UPDATED) {
    drupal_set_message(t('The contest type %name has been updated.',
      array('%name' => $entity->label)));
  }
  else if ($status == SAVED_NEW) {
    drupal_set_message(t('The contest type %name has been added.',
      array('%name' => $entity->label)));
  }

  // Go back to the list of entities.
  $form_state['redirect'] = 'admin/config/marigold-ideasforgood/contest_types';
}

/**
 * Contest Type entity form delete handler
 */
function takepart_contests_contest_type_form_submit_delete(&$form, &$form_state) {
  // Go to the delete confirmation page.
  $form_state['redirect'] = array(
    'admin/config/marigold-ideasforgood/contest_types/manage/'
      . (string) $form_state['contest_type']->identifier() . '/delete',
    array(
      'query' => array(
        'destination' => 'admin/config/marigold-ideasforgood/contest_types',
      ),
    ),
  );
}
