<?php
/**
 * @file
 * Administrative interface for Signature Types
 */

/**
 * Signature Type API UI Controller
 */
class SignatureTypeUIController extends EntityDefaultUIController {

  public function hook_menu() {

    // Add a link to the Structure admin page.
    $items = parent::hook_menu();
    $items[$this->path]['description'] = t('Manage signature types, including adding and removing fields and the display of fields.');

    return $items;
  }
}

/**
 * Signature Type entity form.
 */
function signature_type_form($form, &$form_state, $signature_type, $op = 'edit') {

  $form_state['signature_type'] = $signature_type;

  // Update the label and reset the type if we are cloning the type.
  if ($op == 'clone') {
    $signature_type->id = '';
    $signature_type->type = '';
    $signature_type->label .= ' (cloned)';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#description' => t('The human-readable name of the signature type'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#size' => 30,
    '#default_value' => $signature_type->label,
  );

  $form['type'] = array(
    '#description' => t('A unqiue machine-readable name for this signature type. It must only contain lowercase letters, numbers and underscores.'),
    '#type' => 'machine_name',
    '#maxlength' => 32,
    '#machine_name' => array(
      'exists' => 'signature_type_load',
      'source' => array('label'),
    ),
    '#default_value' => $signature_type->type,
  );

  $form['actions'] = array('#type' => 'actions');
  $submit = array();
  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#value' => t('Save signature type'),
    '#type' => 'submit',
    '#weight' => 40,
    '#submit' => $submit + array('signature_type_form_submit'),
  );

  // Only add the delete button if we are editting an existing signature type.
  $id = $signature_type->identifier();
  if (!empty($id)) {
    $form['actions']['delete'] = array(
      '#value' => t('Delete signature type'),
      '#type' => 'submit',
      '#submit' => array('signature_type_form_submit_delete'),
      '#weight' => 45,
    );
  }

  $form['actions']['cancel'] = array(
    '#type' => 'markup',
    '#markup' => l(t('Cancel'), 'admin/structure/signature_types'),
    '#weight' => 50,
  );

  return $form;
}

/**
 * Signature Type entity form save (submit) handler.
 */
function signature_type_form_submit(&$form, &$form_state) {

  // Build the signature type entity from the form.
  $signature_type = entity_ui_form_submit_build_entity($form, $form_state);

  // Save the signature type.
  $status = $signature_type->save();
  if ($status == SAVED_UPDATED) {
    drupal_set_message(t('The signature type %name has been updated.',
      array('%name' => $signature_type->label)));
  }
  elseif ($status == SAVED_NEW) {
    drupal_set_message(t('The signature type %name has been added.',
      array('%name' => $signature_type->label)));
  }

  // Go back to the list of signature types.
  $form_state['redirect'] = 'admin/structure/signature_types';
}

/**
 * Signature Type entity form delete (submit) handler.
 */
function signature_type_form_submit_delete(&$form, &$form_state) {

  // Go to the delete confirmation page.
  $form_state['redirect'] = array(
    'admin/structure/signature_types/manage/'
    . $form_state['signature_type']->identifier() . '/delete',
    array(
      'query' => array(
        'destination' => 'admin/structure/signature_types',
      ),
    ),
  );
}
