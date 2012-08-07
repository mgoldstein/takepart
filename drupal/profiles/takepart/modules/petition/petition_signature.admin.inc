<?php
/**
 * @file
 * Administrative interface for Petition Signatures.
 */

/**
 * Petition Signature Admin UI Controller.
 */
class PetitionSignatureUIController extends EntityDefaultUIController {

  public function hook_menu() {      
    $items = parent::hook_menu();

    $items[$this->path] = array(
      'title' => t('Petition Signatures'),
      'description' => t('Manage the LastCall Water Bill of Rights petition signatures, including publishing and unpublishing.'),
      'page callback' => 'petition_signature_admin',
      'access callback' => 'entity_access',
      'access arguments' => array('view', $this->entityType),
      'file' => 'petition_signature.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module']),
    );
    $items[$this->path . '/new'] = array(
      'title' => t('Published signatures'),
      'type' => MENU_DEFAULT_LOCAL_TASK,
      'weight' => -10,
    );
    $items[$this->path . '/approval'] = array(
      'title' => 'Unapproved signatures',
      'title callback' => 'petition_signature_count_unpublished',
      'page arguments' => array('approval'),
      'access callback' => 'entity_access',
      'access arguments' => array('administer', $this->entityType),
      'type' => MENU_LOCAL_TASK,
    );

    // Don't allow any new petitions to be added. They have been re-worked to be
    // node based signatures.
    unset($items[$this->path . '/add']);

    return $items;
  }
}

function petition_signature_count_unpublished() {
  $result = db_select('petition_signature', 's')
    ->fields('s')
    ->condition('s.status', 0)
    ->execute();
  $count = $result->rowCount();
  return t('Unapproved signatures (@count)', array('@count' => $count));
}

/**
 * Menu callback; present an administrative signature listing.
 */
function petition_signature_admin($type = 'new') {
  $edit = $_POST;
  $is_delete = isset($edit['operation']) && ($edit['operation'] == 'delete');
  $have_signatures = isset($edit['signatures']) && $edit['signatures'];
  if ($is_delete && $have_signatures) {
    return drupal_get_form('petition_signature_multiple_delete_confirm');
  }
  else {
    return drupal_get_form('petition_signature_admin_overview', $type);
  }
}

/**
 * Form builder for the petition signature overview administration form.
 *
 * @param $arg
 *   Current path's fourth component: the type of overview form ('approval' or
 *   'new').
 *
 * @ingroup forms
 * @see petition_signature_admin_overview_validate()
 * @see petition_signature_admin_overview_submit()
 */
function petition_signature_admin_overview($form, &$form_state, $arg) {

  // Build an 'Update options' form.
  $form['options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Update options'),
    '#attributes' => array('class' => array('container-inline')),
  );

  $options = array();
  if ($arg == 'approval') {
    $options['publish'] = t('Publish the selected signatures');
  }
  else {
    $options['unpublish'] = t('Unplublish the selected signatures');
  }
  $options['delete'] = t('Delete the selected signatures');

  $form['options']['operation'] = array(
    '#type' => 'select',
    '#title' => t('Operation'),
    '#title_display' => 'invisible',
    '#options' => $options,
    '#default_value' => 'publish',
  );
  $form['options']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Update'),
  );

  // Load the signatures that need to be displayed.
  $status = ($arg == 'approval') ? FALSE : TRUE;
  $header = array(
    'author' => array(
      'data' => t('Author'),
      'field' => 'email',
    ),
    'reason' => array(
      'data' => t('Reason to sign'),
    ),
    'on_petition' => array(
      'data' => t('Petition'),
      'field' => 'name',
    ),
    'created' => array(
      'data' => t('Created'), 
      'field' => 's.created', 
      'sort' => 'desc',
    ),
    'operations' => array(
      'data' => t('Operations'),
    ),
  );

  $query = db_select('petition_signature', 's')
    ->extend('PagerDefault')
    ->extend('TableSort');
  $query->join('petition', 'p', 'p.petition_id = s.petition_id');
  $query->leftJoin('field_data_signature_email', 'e', implode(' AND ', array(
    "e.entity_id = s.signature_id",
    "e.entity_type = 'petition_signature'",
    "e.bundle = 'water_bill_of_rights_signature'",
    "e.delta = 0",
  )));
  $query->leftJoin('field_data_signature_comment', 'c', implode(' AND ', array(
    "c.entity_id = s.signature_id",
    "c.entity_type = 'petition_signature'",
    "c.bundle = 'water_bill_of_rights_signature'",
    "c.delta = 0",
  )));
  $query->addField('p', 'name', 'name');
  $query->addField('e', 'signature_email_value', 'email');
  $query->addField('c', 'signature_comment_value', 'comment');
  $query->addTag('petition_access');
  $result = $query
    ->fields('s', array('signature_id'))
    ->condition('s.status', $status)
    ->limit(50)
    ->orderByHeader($header)
    ->execute();

  // We collect a sorted list of petition_names during the query to attach to the
  // signatures later.
  $ids = array();
  $emails = array();
  $comments = array();
  $petitions = array();
  foreach ($result as $row) {
    $ids[] = $row->signature_id;
    $emails[] = $row->email;
    $comments[] = isset($row->comment) ? $row->comment : '';
    $petitions[] = $row->name;
  }
  $signatures = entity_load('petition_signature', $ids);

  // Build a table listing the appropriate signatures.
  $options = array();
  $destination = drupal_get_destination();

  foreach ($signatures as $signature) {
    // Remove the first node title from the node_titles array and attach to
    // the signature.
    $comment = array_shift($comments);
    if (strlen($comment) > 50) {
      $comment = substr($comment, 0, 47) . '...';
    }
    $options[$signature->signature_id] = array(
      'author' => array_shift($emails),
      'reason' => check_plain($comment),
      'on_petition' => array(
        'data' => array(
          '#type' => 'link',
          '#title' => array_shift($petitions),
          '#href' => 'admin/config/water-bill-of-rights/petitions/manage/' . $signature->petition_id,
          '#options' => array('query' => $destination),
        ),
      ),
      'created' => format_date($signature->created, 'short'),
      'operations' => array(
        'data' => array(
          '#type' => 'link',
          '#title' => t('edit'),
          '#href' => 'admin/config/water-bill-of-rights/petition_signatures/manage/' . $signature->signature_id,
          '#options' => array('query' => $destination),
        ),
      ),
    );
  }

  $form['signatures'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $options,
    '#empty' => t('No signatures available.'),
  );

  $form['pager'] = array('#theme' => 'pager');

  return $form;
}

/**
 * Validate petition_signature_admin_overview form submissions.
 */
function petition_signature_admin_overview_validate($form, &$form_state) {
  $form_state['values']['signatures']
    = array_diff($form_state['values']['signatures'], array(0));
  // We can't execute any 'Update options' if no signatures were selected.
  if (count($form_state['values']['signatures']) == 0) {
    form_set_error('', t('Select one or more signatures to perform the update on.'));
  }
}

/**
 * Process petition_signature_admin_overview form submissions.
 *
 * Execute the chosen 'Update option' on the selected signatures, such as
 * publishing, unpublishing or deleting.
 */
function petition_signature_admin_overview_submit($form, &$form_state) {
  $operation = $form_state['values']['operation'];
  $ids = $form_state['values']['signatures'];
  if ($operation == 'delete') {
    entity_delete_multiple('petition_signature', $ids);
  }
  else {
    foreach ($ids as $id => $value) {
      $signature = entity_load_single('petition_signature', $value);
      if ($operation == 'unpublish') {
        $signature->status = FALSE;
      }
      elseif ($operation == 'publish') {
        $signature->status = TRUE;
      }
      entity_save('petition_signature', $signature);
    }
  }
  drupal_set_message(t('The update has been performed.'));
  $form_state['redirect'] = 'admin/config/water-bill-of-rights/petition_signatures';
  cache_clear_all();
}

/**
 * List the selected signatures and verify that the admin wants to delete them.
 *
 * @param $form_state
 *   An associative array containing the current state of the form.
 * @return
 *   TRUE if the signatures should be deleted, FALSE otherwise.
 * @ingroup forms
 * @see petition_signature_multiple_delete_confirm_submit()
 */
function petition_signature_multiple_delete_confirm($form, &$form_state) {
  $edit = $form_state['input'];

  $form['signatures'] = array(
    '#prefix' => '<ul>',
    '#suffix' => '</ul>',
    '#tree' => TRUE,
  );
  // array_filter() returns only elements with actual values.
  $signature_counter = 0;
  foreach (array_filter($edit['signatures']) as $id => $value) {
    $signature = entity_load_single('petition_signature', $value);
    if (is_object($signature) && is_numeric($signature->signature_id)) {
      $lang = $signature->language;
      $email = $signature->signature_email[$lang][0]['value'];
      $form['signatures'][$id] = array(
        '#type' => 'hidden',
        '#value' => $id,
        '#prefix' => '<li>', 
        '#suffix' => check_plain($email) . '</li>'
      );
      $signature_counter++;
    }
  }
  $form['operation'] = array(
    '#type' => 'hidden', 
    '#value' => 'delete'
  );

  if (!$signature_counter) {
    drupal_set_message(t('There do not appear to be any signatures to delete, '
      . 'or your selected signature was deleted by another administrator.'));
    drupal_goto('admin/config/water-bill-of-rights/petition_signatures');
  }
  else {
    return confirm_form($form,
      t('Are you sure you want to delete these signatures?'),
      'admin/config/water-bill-of-rights/petition_signatures',
      t('This action cannot be undone.'),
      t('Delete signatures'), t('Cancel'));
  }
}

/**
 * Process petition_signature_multiple_delete_confirm form submissions.
 */
function petition_signature_multiple_delete_confirm_submit($form, &$form_state) {
  if ($form_state['values']['confirm']) {
    $ids = array_keys($form_state['values']['signatures']);
    entity_delete_multiple('petition_signature', $ids);
    cache_clear_all();
    $count = count($form_state['values']['signatures']);
    watchdog('content', 'Deleted @count signatures.', array('@count' => $count));
    drupal_set_message(format_plural($count, 'Deleted 1 signature.',
      'Deleted @count signatures.'));
  }
  $form_state['redirect'] = 'admin/config/water-bill-of-rights/petition_signatures';
}

/**
 * Petition Signature entity form
 */
function petition_signature_form($form, &$form_state, $entity, $op = 'edit') {

  $form_state['petition_signature'] = $entity;

  if ($op == 'clone') {
    $entity->signature_id = '';
    $entity->is_new = TRUE;
  }

  $form['status'] = array(
    '#title' => t('Published'),
    '#description' => t('The published status of the signature.'),
    '#type' => 'checkbox',
    '#default_value' => $entity->status,
  );

  field_attach_form('petition_signature', $form_state['petition_signature'],
    $form, $form_state);

  $form['actions'] = array('#type' => 'actions');
  $submit = array();
  if (! empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save signature'),
    '#weight' => 40,
    '#submit' => $submit + array('petition_signature_form_submit'),
  );

  // only add the delete button if we are editting an existing entity
  $id = $entity->identifier();
  if (! empty($id)) {
    $form['actions']['delete'] = array(
      '#value' => t('Delete signature'),
      '#type' => 'submit',
      '#weight' => 45,
      '#submit' => array('petition_signature_form_submit_delete'),
    );
  }

  $form['actions']['cancel'] = array(
    '#type' => 'markup',
    '#markup' => l(t('Cancel'), 
      'admin/config/water-bill-of-rights/petition_signatures'),
    '#weight' => 50,
  );

  $form['#validate'][] = 'petition_signature_form_validate';

  return $form;
}

/**
 * Petition Signature entity form validation handler
 */
function petition_signature_form_validate(&$form, &$form_state) {
  // Validate the attached fields.
  field_attach_form_validate('petition_signature',
    $form_state['petition_signature'], $form, $form_state);
}

/**
 * Petition Signature entity form save (submit) handler.
 */
function petition_signature_form_submit(&$form, &$form_state) {

  // Build entity from the form.
  $entity = entity_ui_form_submit_build_entity($form, $form_state);

  // Save the entity.
  $status = $entity->save();
  if ($status == SAVED_UPDATED) {
    drupal_set_message(t('The petition signature has been updated.'));
  }
  else if ($status == SAVED_NEW) {
    drupal_set_message(t('The petition signature has been added.'));
  }

  // Go back to the list of entities.
  $form_state['redirect']
    = 'admin/config/water-bill-of-rights/petition_signatures';
}

/**
 * Petition Signature entity form delete (submit) handler
 */
function petition_signature_form_submit_delete(&$form, &$form_state) {
  // Go to the delete confirmation page.
  $form_state['redirect'] = array(
    'admin/config/water-bill-of-rights/petition_signatures/manage/'
      . (string) $form_state['petition_signature']->identifier() . '/delete',
    array(
      'query' => array(
        'destination' => 'admin/config/water-bill-of-rights/petition_signatures',
      ),
    ),
  );
}
