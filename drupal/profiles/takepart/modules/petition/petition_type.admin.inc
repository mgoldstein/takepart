<?php
/**
 * @file
 * Administrative interface for Petition Types.
 */

/**
 * Petition Type Admin UI Controller.
 */
class PetitionTypeUIController extends EntityDefaultUIController {

  public function hook_menu() {
    $items = parent::hook_menu();
    
    // Update the description for the main admin page.
    $items[$this->path]['description'] = t('Manage the LastCall Water Bill of Rights petition type, including mapping fields to BSD signup fields.');

    // Don't allow any new petitions to be added. They have been re-worked to be
    // node based signatures.
    unset($items[$this->path . '/add']);
    unset($items[$this->path . '/import']);
    return $items;
  }
}

/**
 * Petition Type entity form
 */
function petition_type_form($form, &$form_state, $entity, $op = 'edit') {

  $form_state['petition_type'] = $entity;

  // update the label and reset the type if we are cloning the type
  if ($op == 'clone') {
    $entity->id = '';
    $entity->type = '';
    $entity->label .= ' (cloned)';
    $entity->is_new = TRUE;
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#description' => t('The human-readable name of the petition type'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#size' => 30,
    '#default_value' => $entity->label,
  );

  $form['type'] = array(
    '#description' => t('A unqiue machine-readable name for this petition type. It must only contain lowercase letters, numbers and underscores.'),
    '#type' => 'machine_name',
    '#maxlength' => 32,
    '#machine_name' => array(
      'exists' => 'petition_type_load',
      'source' => array('label'),
    ),
    '#default_value' => $entity->type,
  );

  $form['restrictions_note'] = array(
    '#title' => t('Restrictions note'),
    '#description' => t('Note indicating any restrictions on who can sign the petition.'),
    '#type' => 'textfield',
    '#maxlength' => 255,
    '#default_value' => $entity->restrictions_note,
  );

  $form['terms_of_use_note'] = array(
    '#title' => t('Terms of use note'),
    '#description' => t('Note indicating that the user accepts the TakePart Terms of use by signing the petition.'),
    '#type' => 'textfield',
    '#maxlength' => 255,
    '#default_value' => $entity->terms_of_use_note,
  );

  $form['signature_display_disclaimer'] = array(
    '#title' => t('Signature display disclaimer'),
    '#description' => t("Text of disclaimer regarding the public sharing of the user's signature."),
    '#type' => 'textfield',
    '#maxlength' => 255,
    '#default_value' => $entity->signature_display_disclaimer,
  );

  $form['actions'] = array('#type' => 'actions');
  $submit = array();
  if (! empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#value' => t('Save petition type'),
    '#type' => 'submit',
    '#weight' => 40,
    '#submit' => $submit + array('petition_type_form_submit'),
  );

  // only add the delete button if we are editting an existing petition type
  $id = $entity->identifier();
  if (! empty($id)) {
    $form['actions']['delete'] = array(
      '#value' => t('Delete petition type'),
      '#type' => 'submit',
      '#weight' => 45,
      '#submit' => array('petition_type_form_submit_delete'),
    );
  }

  $form['actions']['cancel'] = array(
    '#type' => 'markup',
    '#markup' => l(t('Cancel'),
      'admin/config/water-bill-of-rights/petition_types'),
    '#weight' => 50,
  );

  return $form;
}

/**
 * Petition Type entity form save (submit) handler
 */
function petition_type_form_submit(&$form, &$form_state) {

  // Build entity from the form.
  $entity = entity_ui_form_submit_build_entity($form, $form_state);

  // Save the entity.
  $status = $entity->save();
  if ($status == SAVED_UPDATED) {

    // Add the common fields for a petition signature
    petition_add_signature_email($entity->signatureType());
    petition_add_signature_first_name($entity->signatureType());
    petition_add_signature_last_name($entity->signatureType());
    petition_add_signature_public_display($entity->signatureType());

    drupal_set_message(t('The petition type %name has been updated.',
      array('%name' => $entity->label)));
  }
  else if ($status == SAVED_NEW) {
    drupal_set_message(t('The petition type %name has been added.',
      array('%name' => $entity->label)));
  }

  // Go back to the list of entities.
  $form_state['redirect'] = 'admin/config/water-bill-of-rights/petition_types';
}

/**
 * Petition Type entity form delete (submit) handler
 */
function petition_type_form_submit_delete(&$form, &$form_state) {
  // Go to the delete confirmation page.
  $form_state['redirect'] = array(
    'admin/config/water-bill-of-rights/petition_types/manage/'
      . (string) $form_state['petition_type']->identifier() . '/delete',
    array(
      'query' => array(
        'destination' => 'admin/config/water-bill-of-rights/petition_types',
      ),
    ),
  );
}

/**
 * Functions for adding commonly used petition fields.
 */
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
