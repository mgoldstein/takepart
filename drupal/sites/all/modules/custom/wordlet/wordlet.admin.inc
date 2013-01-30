<?php
/**
 * @file
 * Administrative interface for Wordlets
 */

/**
 * Wordlet API UI Controller
 */
class WordletUIController extends EntityDefaultUIController {

  public function applyOperation($op, $entity) {
    // Only allow deletes.
    if ($op === 'delete') {
      return parent::applyOperation($op, $entity);
    }
    return FALSE;
  }

  public function hook_menu() {

    $id_count = count(explode('/', $this->path));
    $items = array();

    $items[$this->path] = array(
      'title callback' => 'wordlet_get_overview_title',
      'title arguments' => array($id_count - 1),
      'page callback' => 'wordlet_overview_callback',
      'page arguments' => array($id_count - 1),
      'access callback' => 'wordlet_access',
      'access arguments' => array('edit'),
      'type' => MENU_NORMAL_ITEM,
      'weight' => -10,
      'file' => 'wordlet.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module']),
    );

    $items[$this->path . '/list'] = array(
      'title' => 'Existing',
      'type' => MENU_DEFAULT_LOCAL_TASK,
      'weight' => -10,
      'file' => 'wordlet.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module']),
    );

    $items[$this->path . '/new'] = array(
      'title' => 'New',
      'title callback' => 'wordlet_count_new',
      'title arguments' => array($id_count - 1),
      'page arguments' => array($id_count - 1, FALSE),
      'access callback' => 'wordlet_access',
      'access arguments' => array('add'),
      'type' => MENU_LOCAL_TASK,
      'weight' => 0,
      'file' => 'wordlet.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module']),
    );

    $items[$this->path . '/add'] = array(
      'title' => 'Add wordlet',
      'page callback' => 'wordlet_ui_get_form',
      'page arguments' => array($id_count - 1, $this->entityType, NULL, 'add'),
      'access callback' => 'wordlet_access',
      'access arguments' => array('add'),
      'type' => MENU_LOCAL_ACTION,
      'file' => 'wordlet.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module']),
    );

    $items[$this->path . '/manage/%wordlet'] = array(
      'title callback' => 'entity_label',
      'title arguments' => array($this->entityType, $id_count + 1),
      'page callback' => 'wordlet_ui_get_form',
      'page arguments' => array($id_count - 1, $this->entityType, $id_count + 1),
      'access callback' => 'wordlet_access',
      'access arguments' => array('edit', $id_count + 1),
      'file' => 'wordlet.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module']),
    );

    $items[$this->path . '/manage/%wordlet/edit'] = array(
      'title' => 'Edit',
      'type' => MENU_DEFAULT_LOCAL_TASK,
      'weight' => -10,
      'file' => 'wordlet.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module']),
    );

    $items[$this->path . '/manage/%wordlet/configure'] = array(
      'title' => 'Configure',
      'page callback' => 'wordlet_ui_get_form',
      'page arguments' => array($id_count - 1, $this->entityType, $id_count + 1,
        'configure'),
      'access callback' => 'wordlet_access',
      'access arguments' => array('administer', $id_count + 1),
      'type' => MENU_LOCAL_TASK,
      'weigth' => 0,
      'file' => 'wordlet.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module']),
    );

    $items[$this->path . '/manage/%wordlet/delete'] = array(
      'page callback' => 'drupal_get_form',
      'page arguments' => array($this->entityType . '_operation_form',
        $this->entityType, $id_count + 1, 'delete'),
      'access callback' => 'wordlet_access',
      'access arguments' => array('delete', $id_count + 1),
      'file' => 'includes/entity.ui.inc',
    );

    return $items;
  }
}

/**
 * Wordlet overview page title callback.
 */
function wordlet_get_overview_title($page) {
  return t('@page_title wordlets', array('@page_title' => $page['title']));
}

/**
 * New wordlet page title callback.
 */
function wordlet_count_new($page) {
  $result = db_select('wordlet', 'w')
    ->fields('w')
    ->condition('w.page', $page['name'])
    ->condition('w.type', '')
    ->execute();
  $count = $result->rowCount();
  return t('New wordlets (@count)', array('@count' => $count));
}

/**
 * Wordlet type labels.
 */
function wordlet_type_labels() {
  return array(
    'single-line' => 'Single Line',
    'multiple-lines' => 'Multi Line',
    'node-reference' => 'Node Reference',
  );
}

/**
 * Wordlet overview page callback.
 */
function wordlet_overview_callback($page, $configured = TRUE) {
  $edit = $_POST;

  $is_delete = isset($edit['operation']) && ($edit['operation'] == 'delete');
  $is_export = isset($edit['operation']) && ($edit['operation'] == 'export');
  $have_wordlets = isset($edit['wordlets']) && $edit['wordlets'];
  if ($is_delete && $have_wordlets) {
    return drupal_get_form('wordlet_multiple_delete_confirm', $page);
  }
  elseif ($is_export && $have_wordlets) {
    return drupal_get_form('wordlet_export_form', $page);
  }
  else {
    return drupal_get_form('wordlet_overview_form', $page, $configured);
  }
}

/**
 * List the selected wordlets and verify that the admin wants to delete them.
 *
 * @param $form_state
 *   An associative array containing the current state of the form.
 * @return
 *   TRUE if the wordlets should be deleted, FALSE otherwise.
 * @ingroup forms
 * @see wordlet_multiple_delete_confirm_submit()
 */
function wordlet_multiple_delete_confirm($form, &$form_state, $page) {
  $edit = $form_state['input'];
  $form_state['wordlet_page'] = $page;

  $form['wordlets'] = array(
    '#prefix' => '<ul>',
    '#suffix' => '</ul>',
    '#tree' => TRUE,
  );

  // array_filter() returns only elements with actual values.
  $wordlet_counter = 0;
  foreach (array_filter($edit['wordlets']) as $id => $value) {
    $wordlet = entity_load_single('wordlet', $id);
    if (is_object($wordlet) && is_numeric($wordlet->id)) {
      $title = db_query('SELECT title FROM {wordlet} WHERE id = :id',
        array(':id' => $id))->fetchField();
      $form['wordlets'][$id] = array('#type' => 'hidden', '#value' => $id,
        '#prefix' => '<li>', '#suffix' => check_plain($title) . '</li>');
      $wordlet_counter++;
    }
  }
  $form['operation'] = array(
    '#type' => 'hidden',
    '#value' => 'delete'
  );

  if (!$wordlet_counter) {
    drupal_set_message(t('There do not appear to be any wordlets to delete, or
      your selected wordlet was deleted by another administrator.'));
    drupal_goto('admin/wordlet/page/' . $page['name']);
  }
  else {
    return confirm_form($form,
      t('Are you sure you want to delete these wordlets?'),
      'admin/wordlet/page/' . $page['name'],
      t('This action cannot be undone.'),
      t('Delete wordlets'), t('Cancel'));
  }
}

/**
 * Process wordlet_multiple_delete_confirm form submissions.
 */
function wordlet_multiple_delete_confirm_submit($form, &$form_state) {
  $page = $form_state['wordlet_page'];
  if ($form_state['values']['confirm']) {
    entity_delete_multiple('wordlet', array_keys($form_state['values']['wordlets']));
    cache_clear_all();
    $count = count($form_state['values']['wordlets']);
    watchdog('content', 'Deleted @count wordlets.', array('@count' => $count));
    drupal_set_message(format_plural($count, 'Deleted 1 wordlet.',
      'Deleted @count wordlets.'));
  }
  $form_state['redirect'] = 'admin/wordlet/page/' . $page['name'];
}

function wordlet_export_form($form, &$form_state, $page) {
  $edit = $form_state['input'];

  // array_filter() returns only elements with actual values.
  $wordlet_counter = 0;
  $json = array();
  foreach (array_filter($edit['wordlets']) as $id => $value) {
    $wordlet = entity_load_single('wordlet', $id);
    if (is_object($wordlet) && is_numeric($wordlet->id)) {
      $wrapper = entity_metadata_wrapper('wordlet', $wordlet);
      $data = array();
      foreach ($wrapper->getIterator() as $name => $property) {
        $data[$name] = $property->value();
      }
      $json[] = $data;
      $wordlet_counter += 1;
    }
  }

  if (!$wordlet_counter) {
    drupal_set_message(t('There do not appear to be any wordlets to export, or
      your selected wordlet(s) were deleted by another administrator.'));
    drupal_goto('admin/wordlet/page/' . $page['name']);
  }
  else {
    $form['json'] = array(
      '#title' => t('Exported wordlets'),
      '#description' => t('Exported wordlets as a JSON array suitable for using
        when importing wordlets'),
      '#type' => 'textarea',
      '#default_value' => drupal_json_encode($json),
    );
  }
  return $form;
}

function wordlet_bulk_action_form($form, &$form_state, $page, $configured) {

  // Build an 'Management Actions' form.
  $form['options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Bulk Wordlet Actions'),
    '#attributes' => array('class' => array('container-inline')),
  );

  $options = array(
    'delete' => t('Delete the selected wordlets'),
  );
  if ($configured) {
    $options['export'] = t('Export the selected wordlets');
  }

  $form['options']['operation'] = array(
    '#type' => 'select',
    '#title' => t('Operation'),
    '#title_display' => 'invisible',
    '#options' => $options,
    '#default_value' => 'publish',
  );
  $form['options']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  return $form;
}

function wordlet_overview_form($form, &$form_state, $page, $configured) {

  $form_state['wordlet_page'] = $page;
  $form = wordlet_bulk_action_form($form, $form_state, $page, $configured);

  $header = array(
    array(
      'data' => t('Title'),
      'field' => 'w.title',
    ),
    array(
      'data' => t('Name'),
      'field' => 'w.name',
    ),
    array(
      'data' => t('Type'),
      'field' => 'w.type',
    ),
    array(
      'data' => t('Updated'),
      'field' => 'w.changed',
      'sort' => 'desc'
    ),
    t(''),
    t(''),
    t(''),
  );

  $configured_op = $configured ? '!=' : '=';
  $query = db_select('wordlet', 'w')
    ->extend('PagerDefault')
    ->extend('TableSort');
  $result = $query
    ->fields('w', array('id', 'page' ,'title', 'name', 'type', 'changed'))
    ->condition('w.type', '', $configured_op)
    ->condition('w.page', $page['name'], '=')
    ->limit(50)
    ->orderByHeader($header)
    ->execute();

  $destination = drupal_get_destination();
  $type_labels = wordlet_type_labels();

  $options = array();
  foreach ($result as $row) {

    if ($configured && wordlet_access('edit')) {
      $edit_operation = array(
        'data' => array(
          '#type' => 'link',
          '#title' => t('edit'),
          '#href' => "admin/wordlet/page/{$row->page}/manage/{$row->id}/edit",
          '#options' => array('query' => $destination),
        ),
      );
    }
    else {
      $edit_operation = '';
    }

    if (wordlet_access('administer')) {
      $configure_operation = array(
        'data' => array(
          '#type' => 'link',
          '#title' => t('configure'),
          '#href' => "admin/wordlet/page/{$row->page}/manage/{$row->id}/configure",
          '#options' => array('query' => $destination),
        ),
      );
      $delete_operation = array(
        'data' => array(
          '#type' => 'link',
          '#title' => t('delete'),
          '#href' => "admin/wordlet/page/{$row->page}/manage/{$row->id}/delete",
          '#options' => array('query' => $destination),
        ),
      );
    }
    else {
      $configure_operation = '';
      $delete_operations = '';
    }

    $options[$row->id] = array(
      $row->title,
      $row->name,
      $type_labels[$row->type],
      format_date($row->changed, 'short'),
      $edit_operation,
      $configure_operation,
      $delete_operation,
    );
  }

  $empty = $configured ? t('No wordlets available.') : t('No new wordlets.');

  $form['wordlets'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $options,
    '#empty' => $empty,
  );

  $form['pager'] = array('#theme' => 'pager');

  return $form;
}

/**
 * Validate wordlet_overview_form form submissions.
 */
function wordlet_overview_form_validate($form, &$form_state) {
  $form_state['values']['wordlets']
    = array_diff($form_state['values']['wordlets'], array(0));
  // We can't execute any 'bulk actions' if no wordlets were selected.
  if (count($form_state['values']['wordlets']) == 0) {
    form_set_error('', t('Select one or more wordlets to perform the operation on.'));
  }
}

function wordlet_ui_get_form($page, $entity_type, $entity, $op = 'edit') {
  $form_state = array('wordlet_page' => $page);

  if (isset($entity)) {
    list(, , $bundle) = entity_extract_ids($entity_type, $entity);
  }
  $form_id = (!isset($bundle) || $bundle == $entity_type)
    ? $entity_type . '_form'
    : $entity_type . '_edit_' . $bundle . '_form';

  if (!isset($entity) && $op == 'add') {
    $entity = entity_create($entity_type, array());
  }

  // Do not use drupal_get_form(), but invoke drupal_build_form() ourself so
  // we can prepulate the form state.
  $form_state['wrapper_callback'] = 'entity_ui_main_form_defaults';
  $form_state['entity_type'] = $entity_type;
  // We don't pass the entity type as first parameter, as the implementing
  // module knows the type anyway. However, in order to allow for efficient
  // hook_forms() implementiations we append the entity type as last argument,
  // which the module implementing the form constructor may safely ignore.
  // @see entity_forms()
  $form_state['build_info']['args'] = array($entity, $op, $entity_type);
  module_load_include('inc', 'entity', 'includes/entity.ui');
  return drupal_build_form($form_id, $form_state);
}

function wordlet_configuration_form($form, &$form_state, $entity, $op) {

  $form['page'] = array(
    '#type' => 'value',
    '#value' => $form_state['wordlet_page']['name'],
  );

  $form['configuration'] = array(
    '#title' => t('Configuration'),
    '#type' => 'fieldset',
    '#tree' => FALSE,
  );

  $form['configuration']['title'] = array(
    '#title' => t('Title'),
    '#type' => 'textfield',
    '#default_value' => $entity->title,
    '#description' => t('The human-readable title of this wordlet'),
    '#required' => TRUE,
    '#size' => 30,
  );

  if ($op == 'add') {
    $form['configuration']['name'] = array(
      '#title' => t('Name'),
      '#type' => 'textfield',
      '#default_value' => $entity->name,
      '#description' => t('The machine-readable name of this wordlet'),
      '#required' => TRUE,
      '#size' => 30,
    );
  }

  $form['configuration']['description'] = array(
    '#title' => t('Description'),
    '#description' => t('Short description of the purpose/function of the wordlet'),
    '#type' => 'textfield',
    '#default_value' => $entity->description,
  );

  $form['configuration']['type'] = array(
    '#title' => t('Type'),
    '#description' => t('The type of wordlet'),
    '#type' => 'select',
    '#options' => wordlet_type_labels(),
    '#required' => TRUE,
    '#default_value' => $entity->type,
  );

  $form['configuration']['allow_markup'] = array(
    '#title' => t('Format'),
    '#description' => t('Format of the data value.'),
    '#type' => 'select',
    '#options' => array(
      0 => t('Plain Text'),
      1 => t('Simple HTML'),
      2 => t('Full HTML'),
    ),
    '#default_value' => $entity->allow_markup,
  );

  $form['configuration']['enabled'] = array(
    '#title' => t('Enabled'),
    '#description' => t('The worldet enabled state.'),
    '#type' => 'checkbox',
    '#default_value' => $entity->enabled,
  );

  $form['data'] = array(
    '#title' => t('Values'),
    '#type' => 'fieldset',
    '#tree' => FALSE,
  );

  $form['data']['string_value'] = array(
    '#title' => t('Single Line'),
    '#type' => 'textfield',
    '#default_value' => $entity->string_value,
  );

  $form['data']['text_value'] = array(
    '#title' => t('Multiple Lines'),
    '#type' => 'textarea',
    '#default_value' => $entity->text_value,
  );

  $form['data']['markup'] = array(
    '#title' => t('Format'),
    '#description' => t('Format of the value.'),
    '#type' => 'select',
    '#options' => array(
      0 => t('Plain Text'),
      1 => t('Simple HTML'),
      2 => t('Full HTML'),
    ),
    '#default_value' => $entity->markup,
  );

  $form['data']['integer_value'] = array(
    '#title' => t('Integer Value'),
    '#type' => 'textfield',
    '#default_value' => $entity->integer_value,
    //'#element_validate' => array('element_validate_integer_positive'),
  );

  $form['actions'] = array('#type' => 'actions');
  $submit = array();
  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save wordlet'),
    '#weight' => 40,
  );

  return $form;
}

function wordlet_single_line_form($form, &$form_state, $entity, $op) {

  $form['string_value'] = array(
    '#title' => $entity->title,
    '#description' => $entity->description,
    '#type' => 'textfield',
    '#default_value' => $entity->string_value,
  );
  if ($entity->allow_markup) {
    $allowed_options = array(
      0 => t('Plain Text'),
      1 => t('Simple HTML'),
    );
    if ($entity->allow_markup == 2) {
      $allowed_options[2] = t('Full HTML');
    }
    $form['markup'] = array(
      '#title' => t('Format'),
      '#description' => t('Format of the value.'),
      '#type' => 'select',
      '#options' => $allowed_options,
      '#default_value' => $entity->markup,
    );
  }

  $form['description'] = array(
    '#title' => t('Description'),
    '#type' => 'markup',
    '#markup' => '<p>' . $entity->description . '</p>',
  );

  $form['actions'] = array('#type' => 'actions');
  $submit = array();
  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save wordlet'),
    '#weight' => 40,
  );

  return $form;
}

function wordlet_multiple_lines_form($form, &$form_state, $entity, $op) {

  $form['text_value'] = array(
    '#title' => $entity->title,
    '#description' => $entity->description,
    '#type' => 'textarea',
    '#default_value' => $entity->text_value,
  );
  if ($entity->allow_markup) {
    $allowed_options = array(
      0 => t('Plain Text'),
      1 => t('Simple HTML'),
    );
    if ($entity->allow_markup == 2) {
      $allowed_options[2] = t('Full HTML');
    }
    $form['markup'] = array(
      '#title' => t('Format'),
      '#description' => t('Format of the value.'),
      '#type' => 'select',
      '#options' => $allowed_options,
      '#default_value' => $entity->markup,
    );
  }

  $form['description'] = array(
    '#title' => t('Description'),
    '#type' => 'markup',
    '#markup' => '<p>' . $entity->description . '</p>',
  );

  $form['actions'] = array('#type' => 'actions');
  $submit = array();
  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save wordlet'),
    '#weight' => 40,
  );

  return $form;
}

function wordlet_node_reference_form($form, &$form_state, $entity, $op) {

  $form['integer_value'] = array(
    '#title' => $entity->title,
    '#description' => $entity->description,
    '#type' => 'textfield',
    '#default_value' => $entity->integer_value,
    //'#element_validate' => array('element_validate_integer_positive'),
  );
  $form['string_value'] = array(
    '#title' => t('View Mode'),
    '#description' => t('The view mode to display'),
    '#type' => 'textfield',
    '#default_value' => $entity->string_value,
  );

  $form['description'] = array(
    '#title' => t('Description'),
    '#type' => 'markup',
    '#markup' => '<p>' . $entity->description . '</p>',
  );

  $form['actions'] = array('#type' => 'actions');
  $submit = array();
  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save wordlet'),
    '#weight' => 40,
  );

  return $form;
}

function wordlet_form($form, &$form_state, $entity, $op) {
  if ($op == 'add' || $op == 'configure') {
    return wordlet_configuration_form($form, $form_state, $entity, $op);
  }
  elseif ($op == 'edit' && !empty($entity->type)) {
    if ($entity->type == 'single-line') {
      return wordlet_single_line_form($form, $form_state, $entity, $op);
    }
    elseif ($entity->type == 'multiple-lines') {
      return wordlet_multiple_lines_form($form, $form_state, $entity, $op);
    }
    elseif ($entity->type == 'node-reference') {
      return wordlet_node_reference_form($form, $form_state, $entity, $op);
    }
  }
  return $form;
}

/**
 * Wordlet entity form valdiate hander.
 */
function wordlet_form_validate($form, &$form_state) {
  $page = $form_state['wordlet_page'];
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'wordlet');
  $query->propertyCondition('page', $form_state['values']['page']);
  $query->propertyCondition('name', $form_state['values']['name']);
  $result = $query->execute();
  if (!empty($result['wordlet'])) {
    $entities = entity_load('wordlet', array_keys($result['wordlet']));
    $existing = reset($entities);
    if (empty($existing->type)) {
      $args = array('!existing_link' => l('configure wordlet page.', "admin/wordlet/page/{$page['name']}/manage/{$existing->id}/configure"));
      form_set_error('name', t('A wordlet with that name has already been added to the system, but has not yet been configured. The wordlet can be configured on the !existing_link', $args));
    }
    else {
      form_set_error('name', t('A wordlet with that name already exists.'));
    }
  }
}

/**
 * Wordlet entity form save (submit) handler.
 */
function wordlet_form_submit(&$form, &$form_state) {

  $page = $form_state['wordlet_page'];

  // Build entity from the form.
  $entity = entity_ui_form_submit_build_entity($form, $form_state);

  // Save the entity.
  $status = $entity->save();
  if ($status == SAVED_UPDATED) {
    drupal_set_message(t('The wordlet @title has been updated.',
      array('@title' => $entity->title)));
  }
  elseif ($status == SAVED_NEW) {
    drupal_set_message(t('The wordlet @title has been added.',
      array('@title' => $entity->title)));
  }

  // Go back to the list of entities.
  $form_state['redirect'] = 'admin/wordlet/page/' . $page['name'];
}
