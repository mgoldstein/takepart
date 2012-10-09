<?php
/**
 * @file
 * Administrative interface for Follow Up Types
 */

/**
 * Follow Up Type API UI Controller
 */
class FollowUpTypeUIController extends EntityDefaultUIController {

  /**
   * Overrides EntityDefaultUIController::hook_menu().
   */
  public function hook_menu() {

    // Add a link to the Structure admin page.
    $items = parent::hook_menu();
    $items[$this->path]['description'] = t('Manage follow up types, including adding and removing fields and the display of fields.');

    return $items;
  }
}

/**
 * Follow Up Type entity form.
 */
function followup_type_form($form, &$form_state, $followup_type, $op = 'edit') {

  $form_state['followup_type'] = $followup_type;

  // Update the label and reset the type if we are cloning the type.
  if ($op == 'clone') {
    $followup_type->id = '';
    $followup_type->type = '';
    $followup_type->label .= ' (cloned)';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#description' => t('The human-readable name of the follow up type'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#size' => 30,
    '#default_value' => $followup_type->label,
  );

  $form['type'] = array(
    '#description' => t('A unqiue machine-readable name for the follow up type. It must only contain lowercase letters, numbers and underscores.'),
    '#type' => 'machine_name',
    '#maxlength' => 32,
    '#machine_name' => array(
      'exists' => 'followup_type_load',
      'source' => array('label'),
    ),
    '#default_value' => $followup_type->type,
  );

  $form['description'] = array(
    '#title' => t('Description'),
    '#description' => t('A brief description of this type.'),
    '#type' => 'textarea',
    '#rows' => 5,
    '#default_value' => $followup_type->description,
  );

  $form['actions'] = array('#type' => 'actions');
  $submit = array();
  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#value' => t('Save follow up type'),
    '#type' => 'submit',
    '#weight' => 40,
    '#submit' => $submit + array('followup_type_form_submit'),
  );

  // Only add the delete button if we are editting an existing follow up type.
  $id = $followup_type->identifier();
  if (!empty($id)) {
    $form['actions']['delete'] = array(
      '#value' => t('Delete follow up type'),
      '#type' => 'submit',
      '#submit' => array('followup_type_form_submit_delete'),
      '#weight' => 45,
    );
  }

  $form['actions']['cancel'] = array(
    '#type' => 'markup',
    '#markup' => l(t('Cancel'), 'admin/structure/followup_types'),
    '#weight' => 50,
  );

  return $form;
}

/**
 * Follow Up Type entity form save (submit) handler.
 */
function followup_type_form_submit(&$form, &$form_state) {

  // Build the follow up type entity from the form.
  $followup_type = entity_ui_form_submit_build_entity($form, $form_state);

  // Save the follow up type.
  $status = $followup_type->save();
  if ($status == SAVED_UPDATED) {
    drupal_set_message(t('The follow up type %name has been updated.',
      array('%name' => $followup_type->label)));
  }
  elseif ($status == SAVED_NEW) {
    drupal_set_message(t('The follow up type %name has been added.',
      array('%name' => $followup_type->label)));
  }

  // Go back to the list of followup types.
  $form_state['redirect'] = 'admin/structure/followup_types';
}

/**
 * Follow Up Type entity form delete (submit) handler.
 */
function followup_type_form_submit_delete(&$form, &$form_state) {

  // Go to the delete confirmation page.
  $form_state['redirect'] = array(
    'admin/structure/followup_types/manage/'
    . $form_state['followup_type']->identifier() . '/delete',
    array(
      'query' => array(
        'destination' => 'admin/structure/followup_types',
      ),
    ),
  );
}
