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

    // add a link to the Structure admin page
    $items = parent::hook_menu();
    $items[$this->path]['description'] = t('Manage signature types, including adding and removing fields and the display of fields.');

    // add a local task for mapping the signature type's fields to BSD fields
    $id_count = count(explode('/', $this->path));
    $items[$this->path . '/manage/%entity_object/signup'] = array(
      'title' => t('Manage Mapping'),
      'description' => t('Manage the mapping of Drupal form fields to BSD signup form fields.'),
      'page callback' => 'drupal_get_form',
      'page arguments' => array('signature_mapping_form', $id_count + 1),
      'load arguments' => array($this->entityType),
      'access callback' => 'entity_access',
      'access arguments' => array('update', $this->entityType),
      'type' => MENU_LOCAL_TASK,
      'weight' => 3,
      'file' => 'signature_type.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module']),
    );

    return $items;
  }
}

/**
 * Signature Type field mapping form
 */
function signature_mapping_form($form, &$form_state, $signature_type) {

  // store the signature type for use in the submit handler
  $form_state['signature_type'] = $signature_type;

  // this is an AJAX form, so pull the field values from the form state first
  // then from the signature type itself
  $bsd_form = isset($form_state['values']['bsd_form'])
    ? $form_state['values']['bsd_form'] : $signature_type->bsd_form;

  $form['bsd_form'] = bluestatedigital_forms_signup_form_id($bsd_form);
  $form['bsd_form'] += array(
    '#ajax' => array(
      'event' => 'change',
      'callback' => 'signature_mapping_form_callback',
      'wrapper' => 'signature-field-mappings',
      'progress' => array(
        'type' => 'throbber',
        'message' => NULL,
      ),
    ),
  );

  // get the current mappings for the signature type
  $variable = "signature_mapping_type_{$signature_type->type}";
  $mapping = variable_get($variable, array());
  $form['mapping'] = array(
    '#type' => 'container',
    '#prefix' => '<div id="signature-field-mappings">',
    '#suffix' => '</div>',
    '#tree' => TRUE,
  );

  // the mappings are separated into two groups, first are the properties
  // on every signature
  $form['mapping']['base'] = array(
    '#type' => 'fieldset',
    '#title' => t('Base Field Mapping'),
    '#tree' => TRUE,
  );

  $defaults = array(
    'email' => 0,
    'display' => 0,
    'newsletter' => 0,
  );
  $values = array();
  foreach ($defaults as $name => $default) {
    // Use the value in the working form state first
    if (isset($form_state['values']['mapping']['base'][$name])) {
      $values[$name] = $form_state['values']['mapping']['base'][$name];
    }
    // then check for a stored values
    elseif (isset($mapping[$name])) {
      $values[$name] = $mapping[$name];
    }
    // fallback on the default value
    else {
      $values[$name] = $default;
    }
  }

  $form['mapping']['base']['email'] = bluestatedigital_forms_signup_field_id(
    $bsd_form, $values['email'], TRUE);
  $form['mapping']['base']['email']['#title'] = t('Email');

  $form['mapping']['base']['display'] = bluestatedigital_forms_signup_field_id(
    $bsd_form, $values['display'], TRUE);
  $form['mapping']['base']['display']['#title'] = t('Signature Display Opt-In');

  $form['mapping']['base']['newsletter']
    = bluestatedigital_forms_signup_field_id($bsd_form, $values['newsletter'], 
      TRUE);
  $form['mapping']['base']['newsletter']['#title'] = t('Newsletter Opt-In');

  // the second group of mappings are the fields attached to the signature
  $form['mapping']['attached'] = array(
    '#type' => 'fieldset',
    '#title' => t('Attached Field Mapping'),
    '#tree' => TRUE,
  );

  $instances = field_info_instances('signature', $signature_type->type);
  if (empty($instances)) {
    drupal_set_message(t('There are no fields yet added. You can add new fields'
      . ' on the <a href="@link">Manage fields</a> page.', 
      array('@link' => '../fields')), 'warning');
  }
  foreach ($instances as $instance) {
    $name = $instance['field_name'];
    // Use the value in the working form state first
    if (isset($form_state['values']['mapping']['attached'][$name])) {
      $value = $form_state['values']['mapping']['attached'][$name];
    }
    // then check for a stored values
    elseif (isset($mapping[$name])) {
      $value = $mapping[$name];
    }
    // fallback on the default value
    else {
      $value = 0;
    }
    $field = bluestatedigital_forms_signup_field_id($bsd_form, $value, TRUE);
    $form['mapping']['attached'][$name] = $field; 
    $form['mapping']['attached'][$name]['#title'] = $instance['label'];
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save field mapping'),
  );

  return $form;
}

function signature_mapping_form_callback($form, $form_state) {
  return $form['mapping'];
}

function signature_mapping_form_submit($form, $form_state) {

  // save the signup form id
  $signature_type = $form_state['signature_type'];
  $signature_type->bsd_form = $form_state['values']['bsd_form'];
  $signature_type->save();

  // build the field mapping
  $mapping = array();
  if (! empty($form_state['values']['mapping']['base']['email'])) {
    $mapping['email'] = $form_state['values']['mapping']['base']['email'];
  }
  if (! empty($form_state['values']['mapping']['base']['display'])) {
    $mapping['display'] = $form_state['values']['mapping']['base']['display'];
  }
  if (! empty($form_state['values']['mapping']['base']['newsletter'])) {
    $mapping['newsletter'] = $form_state['values']['mapping']['base']['newsletter'];
  }

  $instances = field_info_instances('signature', $signature_type->type);
  foreach ($instances as $instance) {
    $name = $instance['field_name'];
    if (! empty($form_state['values']['mapping']['attached'][$name])) {
      $mapping[$name] = $form_state['values']['mapping']['attached'][$name];
    }
  }

  // save the field mapping
  variable_set("signature_mapping_type_{$signature_type->type}", $mapping);

  // reassure the user that all is not in fact lost
  $format = 'The field mapping for signature type %name has been saved.';
  drupal_set_message(t($format, array('%name' => $signature_type->label)));
}

/**
 * Signature Type entity form
 */
function signature_type_form($form, &$form_state, $signature_type, $op = 'edit') {

  $form_state['signature_type'] = $signature_type;

  // update the label and reset the type if we are cloning the type
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
  if (! empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#value' => t('Save signature type'),
    '#type' => 'submit',
    '#weight' => 40,
    '#submit' => $submit + array('signature_type_form_submit'),
  );

  // only add the delete button if we are editting an existing signature type
  $id = $signature_type->identifier();
  if (! empty($id)) {
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
 * Signature Type entity form save (submit) handler
 */
function signature_type_form_submit(&$form, &$form_state) {

  // build the signature type entity from the form
  $signature_type = entity_ui_form_submit_build_entity($form, $form_state);

  // save the signature type
  $status = $signature_type->save();
  if ($status == SAVED_UPDATED) {
    drupal_set_message(t('The signature type %name has been updated.',
      array('%name' => $signature_type->label)));
  }
  else if ($status == SAVED_NEW) {
    drupal_set_message(t('The signature type %name has been added.',
      array('%name' => $signature_type->label)));
  }

  // go back to the list of signature types
  $form_state['redirect'] = 'admin/structure/signature_types';
}

/**
 * Signature Type entity form delete (submit) handler
 */
function signature_type_form_submit_delete(&$form, &$form_state) {

  // go to the delete confirmation page
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
