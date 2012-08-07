<?php

class SignatureUIController extends EntityDefaultUIController {

  public function hook_menu() {

    $items = parent::hook_menu();

    $items[$this->path] = array(
      'title' => t('Signatures'),
      'description' => t('List and edit node signatures.'),
      'page callback' => 'signature_admin',
      'access callback' => 'entity_access',
      'access arguments' => array('view', $this->entityType),
      'type' => MENU_LOCAL_TASK | MENU_NORMAL_ITEM,
      'file' => 'signature.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module']),
    );
    $items[$this->path . '/new'] = array(
      'title' => t('Published signatures'),
      'type' => MENU_DEFAULT_LOCAL_TASK,
      'weight' => -10,
    );
    $items[$this->path . '/approval'] = array(
      'title' => 'Unapproved signatures',
      'title callback' => 'signature_count_unpublished',
      'page arguments' => array('approval'),
      'access callback' => 'entity_access',
      'access arguments' => array('administer', $this->entityType),
      'type' => MENU_LOCAL_TASK,
    );
    
    // Remove the add page as signatures require a node.
    unset($items[$this->path . '/add']);
    
    return $items;
  }
}

function signature_count_unpublished() {
  $result = db_select('signature', 's')
    ->fields('s')
    ->condition('s.status', 0)
    ->execute();
  $count = $result->rowCount();
  return t('Unapproved signatures (@count)', array('@count' => $count));
}

/**
 * Menu callback; present an administrative signature listing.
 */
function signature_admin($type = 'new') {
  $edit = $_POST;

  $is_delete = isset($edit['operation']) && ($edit['operation'] == 'delete');
  $have_signatures = isset($edit['signatures']) && $edit['signatures'];
  if ($is_delete && $have_signatures) {
    return drupal_get_form('signature_multiple_delete_confirm');
  }
  else {
    return drupal_get_form('signature_admin_overview', $type);
  }
}

/**
 * Form builder for the signature overview administration form.
 *
 * @param $arg
 *   Current path's fourth component: the type of overview form ('approval' or
 *   'new').
 *
 * @ingroup forms
 * @see signature_admin_overview_validate()
 * @see signature_admin_overview_submit()
 * @see theme_signature_admin_overview()
 */
function signature_admin_overview($form, &$form_state, $arg) {

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
      'field' => 's.email'
    ),
    'on_content' => array(
      'data' => t('On Content'),
      'field' => 'node_title'),
    'changed' => array(
      'data' => t('Updated'), 
      'field' => 's.changed', 
      'sort' => 'desc'
    ),
    'operations' => array(
      'data' => t('Operations')
    ),
  );

  $query = db_select('signature', 's')
    ->extend('PagerDefault')
    ->extend('TableSort');
  $query->join('node', 'n', 'n.nid = s.nid');
  $query->addField('n', 'title', 'node_title');
  $query->addTag('node_access');
  $result = $query
    ->fields('s', array('id', 'email', 'changed'))
    ->condition('s.status', $status)
    ->limit(50)
    ->orderByHeader($header)
    ->execute();

  $ids = array();

  // We collect a sorted list of node_titles during the query to attach to the
  // signatures later.
  foreach ($result as $row) {
    $ids[] = $row->id;
    $node_titles[] = $row->node_title;
  }
  $signatures = entity_load('signature', $ids);

  // Build a table listing the appropriate signatures.
  $options = array();
  $destination = drupal_get_destination();

  foreach ($signatures as $signature) {
    // Remove the first node title from the node_titles array and attach to
    // the signature.
    $signature->node_title = array_shift($node_titles);
    $options[$signature->id] = array(
      'author' => $signature->email,
      'on_content' => array(
        'data' => array(
          '#type' => 'link',
          '#title' => $signature->node_title,
          '#href' => 'node/' . $signature->nid,
        ),
      ),
      'changed' => format_date($signature->changed, 'short'),
      'operations' => array(
        'data' => array(
          '#type' => 'link',
          '#title' => t('edit'),
          '#href' => 'signature/' . $signature->id . '/edit',
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
 * Validate signature_admin_overview form submissions.
 */
function signature_admin_overview_validate($form, &$form_state) {
  $form_state['values']['signatures']
    = array_diff($form_state['values']['signatures'], array(0));
  // We can't execute any 'Update options' if no signatures were selected.
  if (count($form_state['values']['signatures']) == 0) {
    form_set_error('', t('Select one or more signatures to perform the update on.'));
  }
}

/**
 * Process signature_admin_overview form submissions.
 *
 * Execute the chosen 'Update option' on the selected signatures, such as
 * publishing, unpublishing or deleting.
 */
function signature_admin_overview_submit($form, &$form_state) {
  $operation = $form_state['values']['operation'];
  $ids = $form_state['values']['signatures'];

  if ($operation == 'delete') {
    entity_delete_multiple('signature', $ids);
  }
  else {
    foreach ($ids as $id => $value) {
      $signature = entity_load_single('signature', $value);
      if ($operation == 'unpublish') {
        $signature->status = FALSE;
      }
      elseif ($operation == 'publish') {
        $signature->status = TRUE;
      }
      entity_save('signature', $signature);
    }
  }
  drupal_set_message(t('The update has been performed.'));
  $form_state['redirect'] = 'admin/content/signature';
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
 * @see signature_multiple_delete_confirm_submit()
 */
function signature_multiple_delete_confirm($form, &$form_state) {
  $edit = $form_state['input'];

  $form['signatures'] = array(
    '#prefix' => '<ul>',
    '#suffix' => '</ul>',
    '#tree' => TRUE,
  );
  // array_filter() returns only elements with actual values.
  $signature_counter = 0;
  foreach (array_filter($edit['signatures']) as $id => $value) {
    $signature = entity_load_single('signature', $id);
    if (is_object($signature) && is_numeric($signature->id)) {
      $email = db_query('SELECT email FROM {signature} WHERE id = :id',
        array(':id' => $id))->fetchField();
      $form['signatures'][$id] = array('#type' => 'hidden', '#value' => $id,
        '#prefix' => '<li>', '#suffix' => check_plain($email) . '</li>');
      $signature_counter++;
    }
  }
  $form['operation'] = array(
    '#type' => 'hidden', 
    '#value' => 'delete'
  );

  if (!$signature_counter) {
    drupal_set_message(t('There do not appear to be any signatures to delete, or your selected signature was deleted by another administrator.'));
    drupal_goto('admin/content/signature');
  }
  else {
    return confirm_form($form,
      t('Are you sure you want to delete these signatures?'),
      'admin/content/signature', t('This action cannot be undone.'),
      t('Delete signatures'), t('Cancel'));
  }
}

/**
 * Process signature_multiple_delete_confirm form submissions.
 */
function signature_multiple_delete_confirm_submit($form, &$form_state) {
  if ($form_state['values']['confirm']) {
    entity_delete_multiple('signature', array_keys($form_state['values']['signatures']));
    cache_clear_all();
    $count = count($form_state['values']['signatures']);
    watchdog('content', 'Deleted @count signatures.', array('@count' => $count));
    drupal_set_message(format_plural($count, 'Deleted 1 signature.',
      'Deleted @count signatures.'));
  }
  $form_state['redirect'] = 'admin/content/signature';
}

/**
 * Signature entity form
 */
function signature_form($form, &$form_state, $entity, $op = 'edit') {

  $form_state['signature'] = $entity;

  if ($op == 'clone') {
    $entity->id = '';
    $entity->is_new = TRUE;
  }

  $form['summary'] = array(
    '#title' => t('Summary'),
    '#type' => 'fieldset',
  );
  
  $form['summary']['node'] = array(
    '#prefix' => '<p><strong>Node: </strong>',
    '#markup' => entity_label('node', $entity->nid),
    '#suffix' => '</p>',      
  );
  
  if (!empty($entity->type)) {
    $signature_type = entity_load_single('signature_type', $entity->type);
    $type_label = $signature_type->type;
  }
  else {
    $type_label = '(None)';
  }
  $form['summary']['type'] = array(
    '#prefix' => '<p><strong>Signature Type: </strong>',
    '#markup' => $type_label,
    '#suffix' => '</p>',      
  );
  
  $form['status'] = array(
    '#title' => t('Published'),
    '#description' => t('The published status of the signature.'),
    '#type' => 'checkbox',
    '#default_value' => $entity->status,
  );
  
  $form['email'] = array(
    '#title' => t('Email'),
    '#description' => t('The email associated with the signature.'),
    '#type' => 'textfield',
    '#maxlength' => 254, // the mail field in the user table is 254 characters
    '#required' => TRUE,
    '#default_value' => $entity->email,
  );
  
  $form['display'] = array(
    '#title' => t('Displayed'),
    '#description' => t('The public display status of the signature.'),
    '#type' => 'checkbox',
    '#default_value' => $entity->display,
  );
  
  $form['newsletter'] = array(
    '#title' => t('Newsletter Opt-In'),
    '#description' => t('The newsletter opt-in value of the signature.'),
    '#type' => 'checkbox',
    '#default_value' => $entity->newsletter,
  );

  field_attach_form('signature', $form_state['signature'], $form, $form_state);

  $form['actions'] = array('#type' => 'actions');
  $submit = array();
  if (! empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save signature'),
    '#weight' => 40,
    '#submit' => $submit + array('signature_form_submit'),
  );

  // only add the delete button if we are editting an existing entity
  $id = $entity->identifier();
  if (! empty($id)) {
    $form['actions']['delete'] = array(
      '#value' => t('Delete signature'),
      '#type' => 'submit',
      '#weight' => 45,
      '#submit' => array('signature_form_submit_delete'),
    );
  }

  $form['actions']['cancel'] = array(
    '#type' => 'markup',
    '#markup' => l(t('Cancel'), 'admin/content/signature'),
    '#weight' => 50,
  );

  $form['#validate'][] = 'signature_form_validate';

  return $form;
}

/**
 * Signature entity form validation handler
 */
function signature_form_validate(&$form, &$form_state) {
  // Validate the attached fields.
  field_attach_form_validate('signature', $form_state['signature'], $form,
    $form_state);
}

/**
 * Signature entity form save (submit) handler.
 */
function signature_form_submit(&$form, &$form_state) {

  // Build entity from the form.
  $entity = entity_ui_form_submit_build_entity($form, $form_state);

  // Save the entity.
  $status = $entity->save();
  if ($status == SAVED_UPDATED) {
    drupal_set_message(t('The signature for @email has been updated.',
      array('@email' => $entity->email)));
  }
  else if ($status == SAVED_NEW) {
    drupal_set_message(t('The signature for @emailhas been added.',
      array('@email' => $entity->email)));
  }

  // Go back to the list of entities.
  $form_state['redirect']
    = 'admin/content/signature';
}

/**
 * Signature entity form delete (submit) handler
 */
function signature_form_submit_delete(&$form, &$form_state) {
  // Go to the delete confirmation page.
  $form_state['redirect'] = array(
    'admin/content/signature/manage/'
      . (string) $form_state['signature']->identifier() . '/delete',
    array(
      'query' => array(
        'destination' => 'admin/content/signature',
      ),
    ),
  );
}