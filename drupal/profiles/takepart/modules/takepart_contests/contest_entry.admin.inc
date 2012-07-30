<?php
/**
 * @file
 * Administrative interface for Contest Entries.
 */

/**
 * Contest Entries Admin UI Controller.
 */
class TakePartContestEntryUIController extends EntityDefaultUIController {

  public function hook_menu() {      
    $items = parent::hook_menu();

    $items[$this->path] = array(
      'title' => t('Contest Entries'),
      'description' => t('Manage the Marigold Ideas for Good contest entries, including publishing and unpublishing.'),
      'page callback' => 'takepart_contests_contest_entry_admin',
      'access callback' => 'entity_access',
      'access arguments' => array('view', $this->entityType),
      'file' => 'contest_entry.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module']),
    );
    $items[$this->path . '/new'] = array(
      'title' => t('Published entries'),
      'type' => MENU_DEFAULT_LOCAL_TASK,
      'weight' => -10,
    );
    $items[$this->path . '/approval'] = array(
      'title' => 'Unapproved entries',
      'title callback' => 'takepart_contests_contest_entry_count_unpublished',
      'page arguments' => array('approval'),
      'access callback' => 'entity_access',
      'access arguments' => array('administer', $this->entityType),
      'type' => MENU_LOCAL_TASK,
    );

    // Don't allow any new entries to be added. They need to be re-worked to be
    // node based.
    unset($items[$this->path . '/add']);

    return $items;
  }
}

function takepart_contests_contest_entry_count_unpublished() {
  $result = db_select('takepart_contests_contest_entry', 'e')
    ->fields('e')
    ->condition('e.status', 0)
    ->execute();
  $count = $result->rowCount();
  return t('Unapproved entries (@count)', array('@count' => $count));
}

/**
 * Menu callback; present an administrative entry listing.
 */
function takepart_contests_contest_entry_admin($type = 'new') {
  $edit = $_POST;
  $is_delete = isset($edit['operation']) && ($edit['operation'] == 'delete');
  $have_entries = isset($edit['entries']) && $edit['entries'];
  if ($is_delete && $have_entries) {
    return drupal_get_form('takepart_contests_contest_entry_multiple_delete_confirm');
  }
  else {
    return drupal_get_form('takepart_contests_contest_entry_admin_overview', $type);
  }
}

/**
 * Form builder for the contest entry overview administration form.
 *
 * @param $arg
 *   Current path's fourth component: the type of overview form ('approval' or
 *   'new').
 *
 * @ingroup forms
 * @see takepart_contests_contest_entry_admin_overview_validate()
 * @see takepart_contests_contest_entry_admin_overview_submit()
 */
function takepart_contests_contest_entry_admin_overview($form, &$form_state, $arg) {

  // Build an 'Update options' form.
  $form['options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Update options'),
    '#attributes' => array('class' => array('container-inline')),
  );

  $options = array();
  if ($arg == 'approval') {
    $options['publish'] = t('Publish the selected entries');
  }
  else {
    $options['unpublish'] = t('Unplublish the selected entries');
  }
  $options['delete'] = t('Delete the selected entries');

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

  // Load the entries that need to be displayed.
  $status = ($arg == 'approval') ? FALSE : TRUE;
  $header = array(
    'email' => array(
      'data' => t('Email'),
      'field' => 'email',
    ),
    'author' => array(
      'data' => t('Author'),
    ),
    'on_contest' => array(
      'data' => t('Contest'),
      'field' => 'name',
    ),
    'created' => array(
      'data' => t('Created'), 
      'field' => 'e.created', 
      'sort' => 'desc',
    ),
    'operations' => array(
      'data' => t('Operations'),
    ),
  );

  $query = db_select('takepart_contests_contest_entry', 'e')
    ->extend('PagerDefault')
    ->extend('TableSort');
  $query->join('takepart_contests_contest', 'c', 'c.contest_id = e.contest_id');
  $query->leftJoin('field_data_field_profile_email', 'ef', implode(' AND ', array(
    "ef.entity_id = e.entry_id",
    "ef.entity_type = 'takepart_contests_contest_entry'",
    "ef.bundle = 'marigold_hotel_contest_entry'",
    "ef.delta = 0",
  )));
  $query->leftJoin('field_data_field_profile_first_name', 'fnf', implode(' AND ', array(
    "fnf.entity_id = e.entry_id",
    "fnf.entity_type = 'takepart_contests_contest_entry'",
    "fnf.bundle = 'marigold_hotel_contest_entry'",
    "fnf.delta = 0",
  )));
  $query->leftJoin('field_data_field_profile_last_name', 'lnf', implode(' AND ', array(
    "lnf.entity_id = e.entry_id",
    "lnf.entity_type = 'takepart_contests_contest_entry'",
    "lnf.bundle = 'marigold_hotel_contest_entry'",
    "lnf.delta = 0",
  )));
  $query->addField('c', 'name', 'name');
  $query->addField('ef', 'field_profile_email_value', 'email');
  $query->addField('fnf', 'field_profile_first_name_value', 'firstname');
  $query->addField('lnf', 'field_profile_last_name_value', 'lastname');
  $query->addTag('takepart_contests_access');
  $result = $query
    ->fields('e', array('entry_id'))
    ->condition('e.status', $status)
    ->limit(50)
    ->orderByHeader($header)
    ->execute();

  // We collect a sorted list of entry properties during the query to attach to
  // the entries later.
  $ids = array();
  $props = array();
  foreach ($result as $row) {
    $ids[] = $row->entry_id;
    $props[] = array(
      'contest' => isset($row->name) ? $row->name : '',
      'email' => isset($row->email) ? $row->email : '',
      'firstname' => isset($row->firstname) ? $row->firstname : '',
      'lastname' => isset($row->lastname) ? $row->lastname : '',  
    );
  }
  $entries = entity_load('takepart_contests_contest_entry', $ids);

  // Build a table listing the appropriate entries.
  $options = array();
  $destination = drupal_get_destination();

  foreach ($entries as $entry) {
    // Remove the first property set from the props array and attach to
    // the entry.
    $item = array_shift($props);
    $options[$entry->entry_id] = array(
      'email' => $item['email'],
      'author' => implode(', ', array($item['lastname'], $item['firstname'])),
      'on_contest' => array(
        'data' => array(
          '#type' => 'link',
          '#title' => $item['contest'],
          '#href' => 'admin/config/marigold-ideasforgood/contest_entries/manage/' . $entry->contest_id,
          '#options' => array('query' => $destination),
        ),
      ),
      'created' => format_date($entry->created, 'short'),
      'operations' => array(
        'data' => array(
          '#type' => 'link',
          '#title' => t('edit'),
          '#href' => 'admin/config/marigold-ideasforgood/contest_entries/manage/' . $entry->entry_id,
          '#options' => array('query' => $destination),
        ),
      ),
    );
  }

  $form['entries'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $options,
    '#empty' => t('No contest entries available.'),
  );

  $form['pager'] = array('#theme' => 'pager');

  return $form;
}

/**
 * Validate takepart_contests_contest_entry_admin_overview form submissions.
 */
function takepart_contests_contest_entry_admin_overview_validate($form, &$form_state) {
  $form_state['values']['entries']
    = array_diff($form_state['values']['entries'], array(0));
  // We can't execute any 'Update options' if no entries were selected.
  if (count($form_state['values']['entries']) == 0) {
    form_set_error('', t('Select one or more entries to perform the update on.'));
  }
}

/**
 * Process takepart_contests_contest_entry_admin_overview form submissions.
 *
 * Execute the chosen 'Update option' on the selected entries, such as
 * publishing, unpublishing or deleting.
 */
function takepart_contests_contest_entry_admin_overview_submit($form, &$form_state) {
  $operation = $form_state['values']['operation'];
  $ids = $form_state['values']['entries'];
  if ($operation == 'delete') {
    entity_delete_multiple('takepart_contests_contest_entry', $ids);
  }
  else {
    foreach ($ids as $id => $value) {
      $entity = entity_load_single('takepart_contests_contest_entry', $value);
      if ($operation == 'unpublish') {
        $entity->status = FALSE;
      }
      elseif ($operation == 'publish') {
        $entity->status = TRUE;
      }
      entity_save('takepart_contests_contest_entry', $entity);
    }
  }
  drupal_set_message(t('The update has been performed.'));
  $form_state['redirect'] = 'admin/config/marigold-ideasforgood/contest_entries';
  cache_clear_all();
}

/**
 * List the selected entries and verify that the admin wants to delete them.
 *
 * @param $form_state
 *   An associative array containing the current state of the form.
 * @return
 *   TRUE if the entries should be deleted, FALSE otherwise.
 * @ingroup forms
 * @see takepart_contests_contest_entry_multiple_delete_confirm_submit()
 */
function takepart_contests_contest_entry_multiple_delete_confirm($form, &$form_state) {
  $edit = $form_state['input'];

  $form['entries'] = array(
    '#prefix' => '<ul>',
    '#suffix' => '</ul>',
    '#tree' => TRUE,
  );
  // array_filter() returns only elements with actual values.
  $entry_counter = 0;
  foreach (array_filter($edit['entries']) as $id => $value) {
    $entity = entity_load_single('takepart_contests_contest_entry', $value);
    if (is_object($entity) && is_numeric($entity->entry_id)) {
      $lang = $entity->language;
      $email = $entity->field_profile_email[$lang][0]['value'];
      $form['entries'][$id] = array(
        '#type' => 'hidden',
        '#value' => $id,
        '#prefix' => '<li>', 
        '#suffix' => check_plain($email) . '</li>'
      );
      $entry_counter++;
    }
  }
  $form['operation'] = array(
    '#type' => 'hidden', 
    '#value' => 'delete'
  );

  if (!$entry_counter) {
    drupal_set_message(t('There do not appear to be any entries to delete, '
      . 'or your selected entry was deleted by another administrator.'));
    drupal_goto('admin/config/marigold-ideasforgood/contest_entries');
  }
  else {
    return confirm_form($form,
      t('Are you sure you want to delete these entries?'),
      'admin/config/marigold-ideasforgood/contest_entries',
      t('This action cannot be undone.'),
      t('Delete entries'), t('Cancel'));
  }
}

/**
 * Process takepart_contests_contest_entry_multiple_delete_confirm form submissions.
 */
function takepart_contests_contest_entry_multiple_delete_confirm_submit($form, &$form_state) {
  if ($form_state['values']['confirm']) {
    $ids = array_keys($form_state['values']['entries']);
    entity_delete_multiple('takepart_contests_contest_entry', $ids);
    cache_clear_all();
    $count = count($form_state['values']['entries']);
    watchdog('content', 'Deleted @count entries.', array('@count' => $count));
    drupal_set_message(format_plural($count, 'Deleted 1 entry.',
      'Deleted @count entries.'));
  }
  $form_state['redirect'] = 'admin/config/marigold-ideasforgood/contest_entries';
}

/**
 * Contest Entry entity form
 */
function takepart_contests_contest_entry_form($form, &$form_state, $entity, $op = 'edit') {

  $form_state['takepart_contests_contest_entry'] = $entity;

  if ($op == 'clone') {
    $entity->entry_id = '';
    $entity->is_new = TRUE;
  }

  $form['status'] = array(
    '#title' => t('Published'),
    '#description' => t('The published status of the entry.'),
    '#type' => 'checkbox',
    '#default_value' => $entity->status,
  );

  field_attach_form('takepart_contests_contest_entry',
    $form_state['takepart_contests_contest_entry'], $form, $form_state);

  $form['actions'] = array('#type' => 'actions');
  $submit = array();
  if (! empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save entry'),
    '#weight' => 40,
    '#submit' => $submit + array('takepart_contests_contest_entry_form_submit'),
  );

  // only add the delete button if we are editting an existing entity
  $id = $entity->identifier();
  if (! empty($id)) {
    $form['actions']['delete'] = array(
      '#value' => t('Delete entry'),
      '#type' => 'submit',
      '#weight' => 45,
      '#submit' => array('takepart_contests_contest_entry_form_submit_delete'),
    );
  }

  $form['actions']['cancel'] = array(
    '#type' => 'markup',
    '#markup' => l(t('Cancel'), 
      'admin/config/marigold-ideasforgood/contest_entries'),
    '#weight' => 50,
  );

  $form['#validate'][] = 'takepart_contests_contest_entry_form_validate';

  return $form;
}

/**
 * Contest Entry entity form validation handler
 */
function takepart_contests_contest_entry_form_validate(&$form, &$form_state) {
  // Validate the attached fields.
  field_attach_form_validate('takepart_contests_contest_entry',
    $form_state['takepart_contests_contest_entry'], $form, $form_state);
}

/**
 * Contest Entry entity form save (submit) handler.
 */
function takepart_contests_contest_entry_form_submit(&$form, &$form_state) {

  // Build entity from the form.
  $entity = entity_ui_form_submit_build_entity($form, $form_state);

  // Save the entity.
  $status = $entity->save();
  if ($status == SAVED_UPDATED) {
    drupal_set_message(t('The contest entry has been updated.'));
  }
  else if ($status == SAVED_NEW) {
    drupal_set_message(t('The contest entry has been added.'));
  }

  // Go back to the list of entities.
  $form_state['redirect']
    = 'admin/config/marigold-ideasforgood/contest_entries';
}

/**
 * Contest Entry entity form delete (submit) handler
 */
function takepart_contests_contest_entry_form_submit_delete(&$form, &$form_state) {
  // Go to the delete confirmation page.
  $form_state['redirect'] = array(
    'admin/config/marigold-ideasforgood/contest_entries/manage/'
      . (string) $form_state['takepart_contests_contest_entry']->identifier() . '/delete',
    array(
      'query' => array(
        'destination' => 'admin/config/marigold-ideasforgood/contest_entries',
      ),
    ),
  );
}
