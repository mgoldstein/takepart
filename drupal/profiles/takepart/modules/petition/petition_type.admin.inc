<?php

/**
 * @file
 * Administrative interface for Petition Types
 */

/**
 * Petition Type Admin UI Controller
 */
class PetitionTypeUIController extends EntityDefaultUIController {

  public function hook_menu() {

    // add a link to the Structure admin page
    $items = parent::hook_menu();
    $items[$this->path]['description'] = t('Manage petition types, including adding and removing fields and the display of fields.');
    return $items;
  }
}

/**
 * Petition Type entity form
 */
function petition_type_form($form, &$form_state, $petition_type, $op = 'edit') {

  $form_state['petition_type'] = $petition_type;

  // update the label and reset the type if we are cloning the type
  if ($op == 'clone') {
    $petition_type->label .= ' (cloned)';
    $petition_type->type = '';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => isset($petition_type->label) ? $petition_type->label : '',
    '#description' => t('The human-readable name of the petition type'),
    '#required' => TRUE,
    '#size' => 30,
  );

  $form['type'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($petition_type->type) ? $petition_type->type : '',
    '#maxlength' => 32,
    '#machine_name' => array(
      'exists' => 'petition_get_types',
      'source' => array('label'),
    ),
    '#description' => t('A unqiue machine-readable name for this petition type. It must only contain lowercase letters, numbers and underscores.'),
  );

  $variable = "petition:{$petition_type->type}:restrictions_note";
  $form['restrictions_note'] = array(
    '#type' => 'textfield',
    '#maxlength' => 255,
    '#title' => t('Restrictions note'),
    '#description' => t('Note indicating any restrictions on who can sign the petition.'),
    '#default_value' => variable_get($variable, ''),
  );

  $variable = "petition:{$petition_type->type}:terms_of_use_note";
  $form['terms_of_use_note'] = array(
    '#type' => 'textfield',
    '#maxlength' => 255,
    '#title' => t('Terms of use note'),
    '#description' => t('Note indicating that the user accepts the TakePart Terms of use by signing the petition.'),
    '#default_value' => variable_get($variable, ''),
  );

  $variable = "petition:{$petition_type->type}:signature_display_disclaimer";
  $form['signature_display_disclaimer'] = array(
    '#type' => 'textfield',
    '#maxlength' => 255,
    '#title' => t('Signature display disclaimer'),
    '#description' => t("Text of disclaimer regarding the public sharing of the user's signature."),
    '#default_value' => variable_get($variable, ''),
  );

  $form['actions'] = array('#type' => 'actions');
  $submit = array();
  if (! empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save petition type'),
    '#weight' => 40,
    '#submit' => $submit + array('petition_type_form_submit'),
  );

  // only add the delete button if we are editting an existing petition type
  if (! empty($petition_type->id)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete petition type'),
      '#submit' => $submit + array('petition_type_form_submit_delete'),
      '#weight' => 45,
    );
  }

  $form['actions']['cancel'] = array(
    '#type' => 'markup',
    '#markup' => l(t('Cancel'), 'admin/structure/petition_types'),
    '#weight' => 50,
  );

  return $form;
}

/**
 * Petition Type entity form save (submit) handler
 */
function petition_type_form_submit(&$form, &$form_state) {

  // build the petition type entity from the form
  $petition_type = entity_ui_form_submit_build_entity($form, $form_state);

  // save the petition type variables
  $variable = "petition:{$petition_type->type}:restrictions_note";
  variable_set($variable, $form_state['values']['restrictions_note']);

  $variable = "petition:{$petition_type->type}:terms_of_use_note";
  variable_set($variable, $form_state['values']['terms_of_use_note']);

  $variable = "petition:{$petition_type->type}:signature_display_disclaimer";
  variable_set($variable, $form_state['values']['signature_display_disclaimer']);

  // save the petition type
  $status = $petition_type->save();
  if ($status == SAVED_UPDATED) {
    drupal_set_message(t('The petition type %name has been updated.',
      array('%name' => $petition_type->label)));
  }
  else if ($status == SAVED_NEW) {

    // Add the common fields for a petition signature
    petition_add_signature_email($petition_type->signatureType());
    petition_add_signature_first_name($petition_type->signatureType());
    petition_add_signature_last_name($petition_type->signatureType());
    petition_add_signature_public_display($petition_type->signatureType());

    drupal_set_message(t('The petition type %name has been added.',
      array('%name' => $petition_type->label)));
  }

  // go back to the list of petition types
  $form_state['redirect'] = 'admin/structure/petition_types';
}

/**
 * Petition Type entity form delete (submit) handler
 */
function petition_type_form_submit_delete(&$form, &$form_state) {

  // go to the delete confirmation page
  $form_state['redirect'] = 'admin/structure/petition_types/manage/'
    . $form_state['petition_type']->type
    . '/delete?destination=admin/structure/petition_types';
}

function petition_add_field_instance($info) {
  $field = field_info_field($info['instance']['field_name']);
  if (empty($field)) {
    field_create_field($info['field']);
  }
  $instance = field_info_instance($info['instance']['entity_type'],
    $info['instance']['field_name'], $info['instance']['bundle']);
  if (empty($instance)) {
    field_create_instance($info['instance']);
  }
}

function petition_add_signature_email($bundle) {
  $info = array(
    'field' => array(
      'field_name' => 'signature_email',
      'type' => 'text',
      'entity_types' => array('petition_signature'),
    ),
    'instance' => array(
      'field_name' => 'signature_email',
      'entity_type' => 'petition_signature',
      'bundle' => $bundle,
      'label' => t('E-mail'),
      'required' => TRUE,
      'default_value_function' => 'petition_signature_field_default_value',
      'settings' => array(
        'text_processing' => 0,
      ),
      'widget' => array(
        'type' => 'text_textfield',
        'settings' => array(
          'size' => 16,
        ),
      ),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'text_default',
          'settings' => array(),
        ),
      ),
    ),
  );
  petition_add_field_instance($info);
}

function petition_add_signature_first_name($bundle) {
  $info = array(
    'field' => array(
      'field_name' => 'signature_first_name',
      'type' => 'text',
      'entity_types' => array('petition_signature'),
    ),
    'instance' => array(
      'field_name' => 'signature_first_name',
      'entity_type' => 'petition_signature',
      'bundle' => $bundle,
      'label' => t('First Name'),
      'required' => TRUE,
      //'default_value_function' => 'petition_signature_field_default_value',
      'settings' => array(
        'text_processing' => 0,
      ),
      'widget' => array(
        'type' => 'text_textfield',
        'settings' => array(
          'size' => 8,
        ),
      ),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'text_default',
          'settings' => array(),
        ),
      ),
    ),
  );
  petition_add_field_instance($info);
}

function petition_add_signature_last_name($bundle) {
  $info = array(
    'field' => array(
      'field_name' => 'signature_last_name',
      'type' => 'text',
      'entity_types' => array('petition_signature'),
    ),
    'instance' => array(
      'field_name' => 'signature_last_name',
      'entity_type' => 'petition_signature',
      'bundle' => $bundle,
      'label' => t('Last Name'),
      //'default_value_function' => 'petition_signature_field_default_value',
      'required' => TRUE,
      'settings' => array(
        'text_processing' => 0,
      ),
      'widget' => array(
        'type' => 'text_textfield',
        'settings' => array(
          'size' => 8,
        ),
      ),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'text_default',
          'settings' => array(),
        ),
      ),
    ),
  );
  petition_add_field_instance($info);
}

function petition_add_signature_public_display($bundle) {
  $info = array(
    'field' => array(
      'field_name' => 'signature_public_display',
      'type' => 'list_boolean',
      'settings' => array(
        'allowed_values' => array(
          '0' => '0',
          '1' => '1',
        ),
      ),
      'entity_types' => array('petition_signature'),
    ),
    'instance' => array(
      'field_name' => 'signature_public_display',
      'entity_type' => 'petition_signature',
      'bundle' => $bundle,
      'label' => t('Display my signature.'),
      'default_value' => '1',
      'settings' => array(),
      'widget' => array(
        'type' => 'options_onoff',
        'settings' => array(
          'display_label' => 1,
        ),
      ),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'list_default',
          'settings' => array(),
        ),
      ),
    ),
  );
  petition_add_field_instance($info);
}

function petition_add_signature_comment($bundle) {
  $info = array(
    'field' => array(
      'field_name' => 'signature_comment',
      'type' => 'text_long',
      'entity_types' => array('petition_signature'),
    ),
    'instance' => array(
      'field_name' => 'signature_comment',
      'entity_type' => 'petition_signature',
      'bundle' => $bundle,
      'label' => t('Your reason for signing (optional)'),
      'settings' => array(
        'text_processing' => 0,
      ),
      'widget' => array(
        'type' => 'text_textarea',
        'settings' => array(
          'rows' => 5,
        ),
      ),
      'display' => array(
        'default' => array(
          'label' => 'above',
          'type' => 'text_default',
          'settings' => array(),
        ),
      ),
    ),
  );
  petition_add_field_instance($info);
}
