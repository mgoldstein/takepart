<?php
/**
 * @file
 * Administrative interface for Petitions.
 */

/**
 * Petition Admin UI Controller.
 */
class PetitionUIController extends EntityDefaultUIController {

  public function hook_menu() {  
    $items = parent::hook_menu();

    // Update the description for the main admin page.
    $items[$this->path]['description'] = implode(' ', array(
      'Manage the LastCall Water Bill of Rights petition, including the',
      'signature goal, sharing copy and alternate view pages.',
    ));

    // Don't allow any new petitions to be added. They have been re-worked to be
    // node based signatures.
    unset($items[$this->path . '/add']);

    return $items;
  }
}

/**
 * Petition entity form
 */
function petition_form($form, &$form_state, $entity, $op = 'edit') {

  $form_state['petition'] = $entity;

  if ($op == 'clone') {
    $entity->petition_id = '';
    $entity->name .= ' (cloned)';
    $entity->is_new = TRUE;
  }

  $form['name'] = array(
    '#title' => t('Name'),
    '#description' => t('The human-readable name of the petition'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#size' => 30,
    '#default_value' => $entity->name,
  );

  $form['goal'] = array(
    '#title' => t('Goal'),
    '#description' => t('The target number of signatures for the petition.'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#element_validate' => array('_element_validate_integer_positive',),
    '#default_value' => $entity->goal,
  );

  $form['thank_you_page'] = array(
    '#title' => t('Thank You Page'),
    '#description' => t('The path to the petition thank you page relative to the site root.'),
    '#type' => 'textfield',
    '#default_value' => $entity->thank_you_page,
  );

  $form['updates_page'] = array(
    '#title' => t('Update Page'),
    '#description' => t('The path to the petition updates page relative to the site root.'),
    '#type' => 'textfield',
    '#default_value' => $entity->updates_page,
  );

  $form['share_url'] = array(
    '#title' => t('Share URL'),
    '#description' => t('The URL to share through AddThis.'),
    '#type' => 'textfield',
    '#default_value' => $entity->share_url,
  );

  $form['email_share_msg'] = array(
    '#title' => t('Email Share Message'),
    '#description' => t('The default message for AddThis email sharing.'),
    '#type' => 'textarea',
    '#maxlength' => 255,
    '#default_value' => $entity->email_share_msg,
  );

  $form['twitter_share_msg'] = array(
    '#title' => t('Twitter Share Message'),
    '#description' => t('The default message for AddThis Twitter sharing.'),
    '#type' => 'textfield',
    '#maxlength' => 255,
    '#default_value' => $entity->twitter_share_msg,
  );

  field_attach_form('petition', $form_state['petition'], $form, $form_state);

  $form['actions'] = array('#type' => 'actions');
  $submit = array();
  if (! empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save petition'),
    '#weight' => 40,
    '#submit' => $submit + array('petition_form_submit'),
  );

  // only add the delete button if we are editting an existing petition
  $id = $entity->identifier();
  if (! empty($id)) {
    $form['actions']['delete'] = array(
      '#value' => t('Delete petition'),
      '#type' => 'submit',
      '#weight' => 45,
      '#submit' => array('petition_form_submit_delete'),
    );
  }

  $form['actions']['cancel'] = array(
    '#type' => 'markup',
    '#markup' => l(t('Cancel'), 'admin/config/water-bill-of-rights/petitions'),
    '#weight' => 50,
  );

  $form['#validate'][] = 'petition_form_validate';

  return $form;
}

/**
 * Petition entity form validation handler
 */
function petition_form_validate(&$form, &$form_state) {
  // Validate the attached fields.
  field_attach_form_validate('petition', $form_state['petition'], $form,
    $form_state);
}

/**
 * Petition entity form save (submit) handler
 */
function petition_form_submit(&$form, &$form_state) {

  // Build entity from the form.
  $entity = entity_ui_form_submit_build_entity($form, $form_state);

  // Save the entity.
  $status = $entity->save();
  if ($status == SAVED_UPDATED) {
    drupal_set_message(t('The petition %name has been updated.',
      array('%name' => $entity->name)));
  }
  else if ($status == SAVED_NEW) {
    drupal_set_message(t('The petition %name has been added.',
      array('%name' => $entity->name)));
  }

  // Go back to the list of entities.
  $form_state['redirect'] = 'admin/config/water-bill-of-rights/petitions';
}

/**
 * Petition entity form delete (submit) handler
 */
function petition_form_submit_delete(&$form, &$form_state) {
  // Go to the delete confirmation page.
  $form_state['redirect'] = array(
    'admin/config/water-bill-of-rights/petitions/manage/'
      . (string) $form_state['petition']->identifier() . '/delete',
    array(
      'query' => array(
        'destination' => 'admin/config/water-bill-of-rights/petitions',
      ),
    ),
  );
}
