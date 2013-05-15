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
    ->condition('w.keys_data', '')
    ->execute();
  $count = $result->rowCount();
  return t('New wordlets (@count)', array('@count' => $count));
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
      '#rows' => 20,
      '#cols' => 80,
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
      'data' => t('Keys'),
      'field' => 'w.keys_data',
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
    ->fields('w', array('id', 'page' ,'title', 'name', 'keys_data', 'changed'))
    ->condition('w.keys_data', '', $configured_op)
    ->condition('w.page', $page['name'], '=')
    ->limit(50)
    ->orderByHeader($header)
    ->execute();

  $destination = drupal_get_destination();

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
      $delete_operation = '';
    }

    $options[$row->id] = array(
      $row->title,
      $row->name,
      $row->keys_data,
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
    $entity = entity_create($entity_type, array(
      'page' => $page['name'],
    ));
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

  $form['configuration'] = array(
    '#title' => t('Configuration'),
    '#type' => 'fieldset',
    '#tree' => TRUE,
  );

  $pages = wordlet_page_load();
  $page_names = array();
  foreach ($pages as $name => $info) {
    $page_names[$name] = $info['title'];
  }
  asort($page_names);
  $form['configuration']['page'] = array(
    '#title' => t('Page/Group'),
    '#type' => 'select',
    '#options' => $page_names,
    '#default_value' => $entity->page,
    '#required' => TRUE,
  );

  if ($op == 'add') {
    $form['configuration']['name'] = array(
      '#title' => t('Name'),
      '#type' => 'textfield',
      '#default_value' => $entity->name,
      '#description' => t('The machine-readable name of this wordlet'),
      '#required' => TRUE,
    );
  }
  else {
    $form['configuration']['name'] = array(
      '#type' => 'value',
      '#value' => $entity->name,
    );
  }

  $form['configuration']['title'] = array(
    '#title' => t('Title'),
    '#type' => 'textfield',
    '#default_value' => $entity->title,
    '#description' => t('The human-readable title of this wordlet'),
    '#required' => TRUE,
  );

  $form['configuration']['description'] = array(
    '#title' => t('Description'),
    '#description' => t('Short description of the purpose/function of the wordlet'),
    '#type' => 'textfield',
    '#default_value' => $entity->description,
  );

  $form['configuration']['format'] = array(
    '#title' => t('Format'),
    '#description' => t('Format of the value.'),
    '#type' => 'select',
    '#options' => array(
      WORDLET_PLAIN_TEXT => t('Plain Text'),
      WORDLET_SIMPLE_HTML => t('Simple HTML'),
      WORDLET_FULL_HTML => t('Full HTML'),
    ),
    '#default_value' => $entity->format,
  );

  $form['configuration']['cardinality'] = array(
    '#title' => t('Cardinality'),
    '#description' => t('Number of values allowed.'),
    '#type' => 'select',
    '#options' => array(
      1 => t('Single Value'),
      0 => t('Multiple Values'),
    ),
    '#default_value' => $entity->cardinality,
  );

  $form['configuration']['weight'] = array(
    '#title' => t('Weight'),
    '#description' => t('Display order of the wordlet in the single page edit form.'),
    '#type' => 'textfield',
    '#default_value' => $entity->weight,
    '#element_validate' => array('element_validate_integer'),
  );

  $form['data'] = array(
    '#title' => t('Values'),
    '#type' => 'fieldset',
    '#tree' => TRUE,
    '#prefix' => '<div id="wordlet-edit-form-data">',
    '#suffix' => '</div>'
  );
  $form['data'] += wordlet_get_item_fields($entity, TRUE);

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

function wordlet_configuration_change_callback($form, $form_state) {
  return $form['data'];
}

function wordlet_get_item_fields($entity, $configure = FALSE) {

  $form = array(
    'items' => array(
      '#title' => $entity->title,
      '#description' => $entity->description,
      '#type' => 'fieldset',
      '#tree' => TRUE,
    ),
  );

  if ($entity->cardinality == 1) {
    $first = reset($entity->items);
    $item = $first !== FALSE ? $first : array();
    $form['items'][] = wordlet_get_single_item_fields($entity, $item, $configure);
  }
  else {
    $form['items']['#attributes'] = array(
      'class' => array('repeating-container'),
    );
    foreach ($entity->items as $item) {
      $form['items'][] = wordlet_get_single_item_fields($entity, $item, $configure);
      $configure = FALSE;
    }
    // Extra field for additional value
    $form['items'][] = wordlet_get_single_item_fields($entity, array(), $configure);
  }

  return $form;
}

function wordlet_get_single_item_fields($entity, $values, $configure = FALSE) {

  $form = array(
    '#type' => 'container',
    '#tree' => TRUE,
  );
  if ($entity->cardinality != 1) {
    $form['#attributes'] = array('class' => array('repeating'));
  }

  if ($configure || in_array('single', $entity->item_keys)) {
    $form['single'] = array(
      '#tree' => TRUE,
    );
    if ($configure) {
      $form['single']['enabled'] = array(
       '#type' => 'checkbox',
       '#title' => 'Enable Single Line',
       '#attributes' => array('data-for' => array('single-input')),
       '#default_value' => in_array('single', $entity->item_keys),
      );
    }
    $form['single']['value'] = array(
      '#title' => t('Single Line'),
      '#type' => 'textfield',
      '#maxlength' => '1000',
      '#attributes' => array('class' => array('single-input')),
      '#default_value' => $values['single'],
    );
  }

  if ($configure || in_array('multi', $entity->item_keys)) {
    $form['multi'] = array(
      '#tree' => TRUE,
    );
    if ($configure) {
      $form['multi']['enabled'] = array(
       '#type' => 'checkbox',
       '#title' => 'Enable Multi Line',
       '#attributes' => array('data-for' => array('multi-input')),
       '#default_value' => in_array('multi', $entity->item_keys),
      );
    }
    $form['multi']['value'] = array(
      '#title' => t('Multi Line'),
      '#type' => 'textarea',
      '#attributes' => array('class' => array('multi-input')),
      '#default_value' => $values['multi'],
    );
  }

  if ($configure || in_array('multi_short', $entity->item_keys)) {
    $form['multi_short'] = array(
      '#tree' => TRUE,
    );
    if ($configure) {
      $form['multi_short']['enabled'] = array(
       '#type' => 'checkbox',
       '#title' => 'Enable Short Multi Line',
       '#attributes' => array('data-for' => array('multi-short-input')),
       '#default_value' => in_array('multi_short', $entity->item_keys),
      );
    }
    $form['multi_short']['value'] = array(
      '#title' => t('Short Multi Line'),
      '#type' => 'textarea',
      '#attributes' => array('class' => array('multi-short-input')),
      '#default_value' => $values['multi_short'],
    );
  }

  if ($configure || in_array('href', $entity->item_keys)) {
    $form['href'] = array(
      '#tree' => TRUE,
    );
    if ($configure) {
      $form['href']['enabled'] = array(
        '#type' => 'checkbox',
        '#title' => 'Enable HREF',
        '#attributes' => array('data-for' => array('href-input')),
        '#default_value' => in_array('href', $entity->item_keys),
      );
    }
    $form['href']['value'] = array(
      '#title' => t('Link'),
      '#type' => 'textfield',
      '#maxlength' => '1000',
      '#default_value' => $values['href'],
      '#attributes' => array('class' => array('href-input')),
      '#element_validate' => array('wordlet_validate_href'),
    );
  }

  if ($configure || in_array('node', $entity->item_keys)) {
    $form['node'] = array(
      '#tree' => TRUE,
    );
    if ($configure) {
      $form['node']['enabled'] = array(
        '#type' => 'checkbox',
        '#title' => 'Enable Embedded Node',
        '#attributes' => array('data-for' => array('node-input')),
        '#default_value' => in_array('node', $entity->item_keys),
      );
    }
    $form['node']['value'] = array(
      '#type' => 'container',
      '#tree' => TRUE,
      '#attributes' => array('class' => array('node-input')),
      '#prefix' => '<div class="form-type-container">',
      'nid' => array(
        '#title' => t('Node'),
        '#type' => 'textfield',
        '#default_value' => $values['node']['nid'],
        '#element_validate' => array('wordlet_validate_node_id'),
      ),
      'view_mode' => array(
        '#title' => t('View Mode'),
        '#type' => 'textfield',
        '#default_value' => $values['node']['view_mode'],
      ),
      '#suffix' => '</div>',
    );
  }

  if ($configure || in_array('img_src', $entity->item_keys)) {
    $form['img_src'] = array(
      '#tree' => TRUE,
    );
    if ($configure) {
      $form['img_src']['enabled'] = array(
        '#type' => 'checkbox',
        '#title' => 'Enable Image Source',
        '#attributes' => array('data-for' => array('img-src-input')),
        '#default_value' => in_array('img_src', $entity->item_keys),
      );
    }
    $form['img_src']['value'] = array(
      '#title' => t('Image Source'),
      '#type' => 'textfield',
      '#maxlength' => '1000',
      '#default_value' => $values['img_src'],
      '#attributes' => array('class' => array('img-src-input')),
      '#element_validate' => array('wordlet_validate_href'),
    );
  }

  if ($configure || in_array('thumb_src', $entity->item_keys)) {
    $form['thumb_src'] = array(
      '#tree' => TRUE,
    );
    if ($configure) {
      $form['thumb_src']['enabled'] = array(
        '#type' => 'checkbox',
        '#title' => 'Enable Thumb Source',
        '#attributes' => array('data-for' => array('thumb-src-input')),
        '#default_value' => in_array('thumb_src', $entity->item_keys),
      );
    }
    $form['thumb_src']['value'] = array(
      '#title' => t('Thumb Source'),
      '#type' => 'textfield',
      '#maxlength' => '1000',
      '#default_value' => $values['thumb_src'],
      '#attributes' => array('class' => array('thumb-src-input')),
      '#element_validate' => array('wordlet_validate_href'),
    );
  }

  if ($configure || in_array('small_src', $entity->item_keys)) {
    $form['small_src'] = array(
      '#tree' => TRUE,
    );
    if ($configure) {
      $form['small_src']['enabled'] = array(
        '#type' => 'checkbox',
        '#title' => 'Enable Small Image Source',
        '#attributes' => array('data-for' => array('small-src-input')),
        '#default_value' => in_array('small_src', $entity->item_keys),
      );
    }
    $form['small_src']['value'] = array(
      '#title' => t('Small Image Source'),
      '#type' => 'textfield',
      '#maxlength' => '1000',
      '#default_value' => $values['small_src'],
      '#attributes' => array('class' => array('small-src-input')),
      '#element_validate' => array('wordlet_validate_href'),
    );
  }

  if ($configure || in_array('active', $entity->item_keys)) {
    $form['active'] = array(
      '#tree' => TRUE,
    );
    if ($configure) {
      $form['active']['enabled'] = array(
        '#type' => 'checkbox',
        '#title' => 'Enable Active',
        '#attributes' => array('data-for' => array('active-input')),
        '#default_value' => in_array('active', $entity->item_keys),
      );
    }
    $form['active']['value'] = array(
      '#title' => t('Active'),
      '#type' => 'checkbox',
      '#default_value' => $values['active'],
      '#attributes' => array('class' => array('active-input')),
    );
  }

  if ($configure || in_array('token', $entity->item_keys)) {
    $form['token'] = array(
      '#tree' => TRUE,
    );
    if ($configure) {
      $form['token']['enabled'] = array(
        '#type' => 'checkbox',
        '#title' => 'Enable Token',
        '#attributes' => array('data-for' => array('token-input')),
        '#default_value' => in_array('token', $entity->item_keys),
      );
    }
    $form['token']['value'] = array(
      '#title' => t('Token'),
      '#type' => 'textfield',
      '#maxlength' => '1000',
      '#default_value' => $values['token'],
      '#attributes' => array('class' => array('token-input')),
    );
  }

  if ($configure || in_array('video', $entity->item_keys)) {
    $form['video'] = array(
      '#tree' => TRUE,
    );
    if ($configure) {
      $form['video']['enabled'] = array(
        '#type' => 'checkbox',
        '#title' => 'Enable Video',
        '#attributes' => array('data-for' => array('video-input')),
        '#default_value' => in_array('video', $entity->item_keys),
      );
    }
    $form['video']['value'] = array(
      '#title' => t('Video'),
      '#type' => 'textfield',
      '#maxlength' => '1000',
      '#default_value' => $values['video'],
      '#attributes' => array('class' => array('video-input')),
    );
  }

  if ($configure || in_array('form', $entity->item_keys)) {
    $form['form'] = array(
      '#tree' => TRUE,
    );
    if ($configure) {
      $form['form']['enabled'] = array(
        '#type' => 'checkbox',
        '#title' => 'Enable Form',
        '#attributes' => array('data-for' => array('form-input')),
        '#default_value' => in_array('form', $entity->item_keys),
      );
    }
    $form['form']['value'] = array(
      '#type' => 'container',
      '#tree' => TRUE,
      '#attributes' => array('class' => array('form-input')),
      '#prefix' => '<div class="form-type-container">',
      '#suffix' => '</div>',
    );
    if ($configure) {
      $form['form']['value']['name'] = array(
        '#title' => t('Form'),
        '#type' => 'select',
        // TODO: Get the list of forms from custom module hook.
        '#options' => array(
          'newsletter_campaign_email_only_signup' => t('Email Only Signup'),
          'newsletter_campaign_mobile_only_signup' => t('Mobile Only Signup'),
          'newsletter_campaign_email_mobile_signup' => t('Email + Mobile Signup'),
          'contest_intel_entry' => t('Intel Contest Entry'),
          'contest_intel_vote' => t('Intel Contest Vote'),
        ),
        '#default_value' => $values['form']['name'],
        '#element_validate' => array('wordlet_validate_form'),
      );
    }
    else {
      $form['form']['value']['name'] = array(
        '#type' => 'value',
        '#value' => $values['form']['name'],
      );
    }
    if (!empty($values['form']['name'])) {
      $config_hook = "{$values['form']['name']}_configuration";
      if (function_exists($config_hook)) {
        $config_form = array();
        $config_values = empty($values['form']['config']) ? array()
          : $values['form']['config'];
        $fields = call_user_func_array($config_hook, array(
          $config_form,
          $config_values
        ));
        $form['form']['value']['config'] = $fields;
      }
    }
  }

  if ($configure || in_array('block', $entity->item_keys)) {
    $form['block'] = array(
      '#tree' => TRUE,
    );
    if ($configure) {

      $form['block']['enabled'] = array(
        '#type' => 'checkbox',
        '#title' => 'Enable Block',
        '#attributes' => array('data-for' => array('block-input')),
        '#default_value' => in_array('block', $entity->item_keys),
      );

      $form['block']['value'] = array(
        '#type' => 'container',
        '#tree' => TRUE,
        '#attributes' => array('class' => array('block-input')),
        '#prefix' => '<div class="form-type-container">',
        '#suffix' => '</div>',
      );

      $form['block']['value']['module'] = array(
        '#title' => t('Module'),
        '#type' => 'select',
        // TODO: Get the list of modules from custom module hook.
        '#options' => array(
          'boxes' => t('Boxes'),
          'newsletter_campaign' => t('Newsletter Campaigns'),
          'views' => t('Views'),
        ),
        '#default_value' => $values['block']['module'],
      );

      $form['block']['value']['delta'] = array(
        '#title' => t('Delta'),
        '#type' => 'textfield',
        '#default_value' => $values['block']['delta'],
      );
    }
    else {
      $form['block']['value']['module'] = array(
        '#type' => 'value',
        '#value' => $values['block']['module'],
      );
      $form['block']['value']['delta'] = array(
        '#type' => 'value',
        '#value' => $values['block']['delta'],
      );
    }
  }

  return $form;
}

function wordlet_validate_href($element, &$form_state) {
  $value = $element['#value'];
  if (!empty($value)) {
    $parts = parse_url($value);
    if ($parts === FALSE) {
      form_error($element, t('%name must be a valid URL or absolute path.',
        array('%name' => $element['#title'])));
    }
  }
}

function wordlet_validate_node_id($element, &$form_state) {
  $value = $element['#value'];
  $not_empty = ($value !== '');
  $not_numeric = (!is_numeric($value) || intval($value) != $value);
  if ($not_empty && ($not_numeric || $value < 0)) {
    form_error($element, t('%name must be a valid node id.',
      array('%name' => $element['#title'])));
  }
  elseif ($not_empty) {
    $node = node_load($value);
    if ($node === FALSE) {
      form_error($element, t('%name must be a valid node id.',
        array('%name' => $element['#title'])));
    }
  }
}

function wordlet_validate_form($element, &$form_state) {
  $value = $element['#value'];
  if (!empty($value)) {
    $form_hook = "{$value}_form";
    $config_hook = "{$value}_configuration";
    if (!function_exists($form_hook) || !function_exists($config_hook)) {
      form_error($element, t('%name must be a valid form callback.',
        array('%name' => $element['#title'])));
    }
  }
}

function wordlet_form($form, &$form_state, $entity, $op) {

  $form_state['wordlet_op'] = $op;
  if ($op == 'add' || $op == 'configure') {
    $form = wordlet_configuration_form($form, $form_state, $entity, $op);
  }
  elseif ($op == 'edit') {

    $form += wordlet_get_item_fields($entity);

    $form['actions'] = array('#type' => 'actions');
    $submit = array('wordlet_form_submit');
    if (!empty($form['#submit'])) {
      $submit += $form['#submit'];
    }
    $form['actions']['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Save wordlet'),
      '#weight' => 40,
    );
    $wordlet_formats = wordlet_formats($entity->format);

    if ( $wordlet_formats ) {
      $wordlet_formats = strtolower(str_replace('_', '-', $wordlet_formats));
      $form['#attributes'] = array('class' => $wordlet_formats);
    }
  }
  return $form;
}

/**
 * Wordlet entity form valdiate hander.
 */
function wordlet_form_validate($form, &$form_state) {

  $page = $form_state['wordlet_page'];
  $entity = $form_state['wordlet'];
  $op = $form_state['wordlet_op'];

  $page_changed = $form_state['values']['configuration']['page'] != $entity->page;

  if ($op == 'add' || ($op == 'configure' && $page_changed)) {

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'wordlet');
    $query->propertyCondition('page', $form_state['values']['configuration']['page']);
    $query->propertyCondition('name', $form_state['values']['configuration']['name']);
    $result = $query->execute();

    if (!empty($result['wordlet'])) {
      form_set_error('name', t('A wordlet with that page and name already exists.'));
    }
  }

}

/**
 * Wordlet entity form save (submit) handler.
 */
function wordlet_form_submit(&$form, &$form_state) {

  $page = $form_state['wordlet_page'];
  $entity = $form_state['wordlet'];
  $op = $form_state['wordlet_op'];

  // Update the configuration.
  if (isset($form_state['values']['configuration'])) {
    foreach ($form_state['values']['configuration'] as $attribute => $value) {
      $entity->{$attribute} = $value;
    }
  }
  if ($op == 'add' || $op == 'configure') {

    $entity->item_keys = array();
    $enabled_states = reset($form_state['values']['data']['items']);
    foreach ($enabled_states as $key => $values) {
      if (!empty($values['enabled'])) {
        $entity->item_keys[] = $key;
      }
    }

    // Set the initial values passed in by the configuration form.
    if (isset($form_state['values']['data'])) {
      wordlet_update_items_from_fields($entity, $form_state['values']['data']);
    }
  }

  // Set the values passed in by the edit form.
  if ($op == 'edit') {
    wordlet_update_items_from_fields($entity, $form_state['values']);
  }

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

function wordlet_update_items_from_fields($entity, $values) {
  $entity->items = array();
  foreach ($values['items'] as $fields) {
    $item = array(
      'single' => '',
      'multi' => '',
      'multi_short' => '',
      'href' => '',
      'node' => '',
      'img_src' => '',
      'thumb_src' => '',
      'small_src' => '',
      'active' => '',
      'token' => '',
      'video' => '',
      'form' => '',
      'block' => '',
    );
    $is_empty = TRUE;
    foreach (array_keys($item) as $key) {
      if (isset($fields[$key]) && in_array($key, $entity->item_keys)) {
        $item[$key] = $fields[$key]['value'];
        $is_empty &= empty($item[$key]);
      }
    }
    if (!$is_empty) {
      $entity->items[] = $item;
    }
  }
}
