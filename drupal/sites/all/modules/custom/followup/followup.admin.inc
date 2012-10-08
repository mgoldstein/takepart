<?php
/**
 * @file
 * Administrative interface for Follow Ups
 */

class FollowUpUIController extends EntityDefaultUIController {

  /**
   * Overrides EntityDefaultUIController::hook_menu().
   */
  public function hook_menu() {

    $items = parent::hook_menu();

    $id_count = count(explode('/', $this->path));
    $wildcard = isset($this->entityInfo['admin ui']['menu wildcard'])
      ? $this->entityInfo['admin ui']['menu wildcard'] : '%entity_object';

    $items[$this->path] = array(
      'title' => t('Updates'),
      'description' => t('List and edit follow ups for this node.'),
      'type' => MENU_LOCAL_TASK | MENU_NORMAL_ITEM,
      'access arguments' => array('administer', $this->entityType),
      'access callback' => 'entity_access',
      'page arguments' => array(1),
      'page callback' => 'followup_list_page',
      'file path' => drupal_get_path('module', $this->entityInfo['module']),
      'file' => 'followup.admin.inc',
    );

    $items[$this->path . '/list'] = array(
      'title' => t('Published updates'),
      'type' => MENU_DEFAULT_LOCAL_TASK,
      'weight' => -10,
    );

    $items[$this->path . '/publish'] = array(
      'title' => 'Unpublished updates',
      'type' => MENU_LOCAL_TASK,
      'access arguments' => array('administer', $this->entityType),
      'access callback' => 'entity_access',
      'page arguments' => array(1, 'approval'),
      'title arguments' => array(1),
      'title callback' => 'followup_count_unpublished',
      'file path' => drupal_get_path('module', $this->entityInfo['module']),
      'file' => 'followup.admin.inc',
    );

    $items[$this->path . '/add'] = array(
      'title' => t('Add update'),
      'type' => MENU_LOCAL_ACTION,
      'access arguments' => array('create', $this->entityType),
      'access callback' => 'entity_access',
      'page arguments' => array(1),
      'page callback' => 'followup_add_page',
      'file path' => drupal_get_path('module', $this->entityInfo['module']),
      'file' => 'followup.admin.inc',
    );

    foreach (followup_type_load() as $type) {
      $type_url_str = str_replace('_', '-', $type->type);
      $items[$this->path . '/add/' . $type_url_str] = array(
        'title' => $type->label,
        'title callback' => 'check_plain',
        'description' => $type->description,
        'access arguments' => array('create', $this->entityType),
        'access callback' => 'entity_access',
        'page arguments' => array(1, NULL, 'add', $type->type),
        'page callback' => 'followup_ui_get_form',
        'file path' => drupal_get_path('module', $this->entityInfo['module']),
        'file' => 'followup.admin.inc',
      );
    }

    $items[$this->path . '/manage/' . $wildcard] = array(
      'title' => 'Edit',
      'title arguments' => array($this->entityType, $id_count + 1),
      'title callback' => 'entity_label',
      'access arguments' => array('update', $this->entityType),
      'access callback' => 'entity_access',
      'page arguments' => array(1, $id_count + 1),
      'page callback' => 'followup_ui_get_form',
      'file path' => drupal_get_path('module', $this->entityInfo['module']),
      'file' => 'followup.admin.inc',
    );

    $items[$this->path . '/manage/' . $wildcard . '/edit'] = array(
      'title' => 'Edit',
      'type' => MENU_DEFAULT_LOCAL_TASK,
    );

    // Clone form, a special case for the edit form.
    $items[$this->path . '/manage/' . $wildcard . '/clone'] = array(
      'title' => 'Clone',
      'access arguments' => array('create', $this->entityType),
      'access callback' => 'entity_access',
      'page arguments' => array(1, $id_count + 1, 'clone'),
      'page callback' => 'followup_ui_get_form',
      'file path' => drupal_get_path('module', $this->entityInfo['module']),
      'file' => 'followup.admin.inc',
    );

    // Menu item for operations like revert and delete.
    $items[$this->path . '/manage/' . $wildcard . '/%'] = array(
      'access callback' => 'entity_access',
      'access arguments' => array('delete', $this->entityType),
      'page arguments' => array(1, $id_count + 1, $id_count + 2),
      'page callback' => 'followup_ui_get_form',
      'file path' => drupal_get_path('module', $this->entityInfo['module']),
      'file' => 'followup.admin.inc',
    );

    return $items;
  }
}

/**
 * Follow up add page callback.
 */
function followup_add_page($node) {
  drupal_set_title(t('Add update to %title', array(
    '%title' => $node->title,
  )), PASS_THROUGH);
  $types = followup_type_load();
  $base_url = 'node/' . $node->nid . '/updates';
  // Bypass the add listing if only one follow up type is available.
  if (count($types) == 1) {
    $type = reset($types);
    drupal_goto($base_url . '/add/' . str_replace('_', '-', $type->type));
  }
  return theme('followup_add_list', array(
    'content' => $types,
    'base_url' => $base_url,
  ));
}

/**
 * Follow up add page theme function.
 */
function theme_followup_add_list($variables) {
  $content = $variables['content'];
  $base_url = $variables['base_url'];
  $options = array(
    'html' => TRUE,
    'attributes' => array(
      'class' => array(
        'path-node-add',
        'path-node',
      ),
    ),
  );
  $output = '';
  if (count($content)) {
    $output = '<ul class="admin-list">';
    foreach ($content as $item) {
      $output .= '<li>';
      $text = '<span class="icon"></span>' . check_plain($item->label);
      $href = $base_url . '/add/' . str_replace('_', '-', $item->type);
      $output .= l($text, $href, $options);
      $output .= '<div class="description">';
      $output .= filter_xss_admin($item->description);
      $output .= '</div>';
      $output .= '</li>';
    }
    $output .= '</ul>';
  }
  else {
    $output = '<p>' . t('You have not created any update types yet. Go to the <a href="@create-update">update type creation page</a> to add a new update type.', array('@create-update' => url('admin/structure/followup_types/add'))) . '</p>';
  }
  return $output;
}

/**
 * Followup menu item callback.
 */
function followup_ui_get_form($node, $entity, $op = 'edit', $bundle = NULL) {
  // Create a new follow up if we are adding one.
  if (!isset($entity) && $op === 'add') {
    $entity = entity_create('followup', array(
      'type' => $bundle,
      'nid' => $node->nid,
    ));
  }
  // Make sure the follow up belongs to the selected node.
  if (!empty($entity) && $node->nid == $entity->nid) {
    if ($op === 'add' || $op === 'edit' || $op === 'clone') {
      return entity_ui_get_form('followup', $entity, $op, array());
    }
    else {
      // Pass any other operations off to the entity controller operation form.
      return drupal_get_form('followup_operation_form', 'followup', $entity, $op);
    }
  }
  // The follow up does not belong to the node, or could not be created.
  drupal_not_found();
  exit;
}

/**
 * Unplublished overview page title callback.
 */
function followup_count_unpublished($node) {
  $result = db_select('followup', 'f')
    ->fields('f')
    ->condition('f.status', 0, '=')
    ->condition('f.nid', $node->nid, '=')
    ->execute();
  $count = $result->rowCount();
  return t('Unpublished updates (@count)', array('@count' => $count));
}

/**
 * Menu callback; present an administrative follow up listing.
 */
function followup_list_page($node, $type = 'new') {
  drupal_set_title(t('Updates for %title', array(
    '%title' => $node->title,
  )), PASS_THROUGH);
  $edit = $_POST;
  $is_delete = isset($edit['operation']) && ($edit['operation'] == 'delete');
  $have_followups = isset($edit['followups']) && $edit['followups'];
  if ($is_delete && $have_followups) {
    return drupal_get_form('followup_multiple_delete_confirm', $node);
  }
  else {
    return drupal_get_form('followup_admin_overview', $node, $type);
  }
}

/**
 * Form builder for the follow up overview administration form.
 *
 * @param array $form
 *   The form being built.
 * @param array $form_state
 *   The form state of the form being built.
 * @param object $node
 *   The node for which follow ups are being managed.
 * @param string $arg
 *   Current path's fourth component: the type of overview form ('approval' or
 *   'new').
 *
 * @ingroup forms
 * @see followup_admin_overview_validate()
 * @see followup_admin_overview_submit()
 * @see theme_followup_admin_overview()
 */
function followup_admin_overview($form, &$form_state, $node, $arg) {

  $form_state['overview_page_url'] = 'node/' . $node->nid . '/updates';

  // Build an 'Update options' form.
  $form['options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Update options'),
    '#attributes' => array('class' => array('container-inline')),
  );

  $options = array();
  if ($arg == 'approval') {
    $options['publish'] = t('Publish the selected updates');
  }
  else {
    $options['unpublish'] = t('Unpublish the selected updates');
  }
  $options['delete'] = t('Delete the selected updates');

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

  // Load the follow ups that need to be displayed.
  $status = ($arg == 'approval') ? FALSE : TRUE;
  $header = array(
    'title' => array(
      'data' => t('Title'),
      'field' => 'f.title',
    ),
    'type' => array(
      'data' => t('Type'),
      'field' => 'f.type',
    ),
    'changed' => array(
      'data' => t('Updated'),
      'field' => 'f.changed',
      'sort' => 'desc',
    ),
    'operations' => array(
      'data' => t('Operations'),
    ),
  );

  $query = db_select('followup', 'f')
    ->extend('PagerDefault')
    ->extend('TableSort');
  $result = $query
    ->fields('f', array('id', 'title', 'type', 'changed'))
    ->condition('f.status', $status)
    ->condition('f.nid', $node->nid)
    ->limit(50)
    ->orderByHeader($header)
    ->execute();

  // Build a table listing the appropriate follow ups.
  $types = followup_type_load();
  $options = array();
  $destination = drupal_get_destination();

  foreach ($result as $followup) {
    $type = $types[$followup->type];
    $options[$followup->id] = array(
      'title' => $followup->title,
      'type' => $type->label,
      'changed' => format_date($followup->changed, 'short'),
      'operations' => array(
        'data' => array(
          '#type' => 'link',
          '#title' => t('edit'),
          '#href' => 'node/' . $node->nid . '/updates/manage/' . $followup->id,
          '#options' => array('query' => $destination),
        ),
      ),
    );
  }

  $form['followups'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $options,
    '#empty' => t('No updates available.'),
  );

  $form['pager'] = array('#theme' => 'pager');

  return $form;
}

/**
 * Validate followup_admin_overview form submissions.
 */
function followup_admin_overview_validate($form, &$form_state) {
  $form_state['values']['followups']
    = array_diff($form_state['values']['followups'], array(0));
  // We can't execute any 'Update options' if no follow ups were selected.
  if (count($form_state['values']['followups']) == 0) {
    form_set_error('', t('Select one or more update items to perform the update on.'));
  }
}

/**
 * Process followup_admin_overview form submissions.
 *
 * Execute the chosen 'Update option' on the selected follow ups, such as
 * publishing, unpublishing or deleting.
 */
function followup_admin_overview_submit($form, &$form_state) {
  $operation = $form_state['values']['operation'];
  $ids = $form_state['values']['followups'];

  if ($operation == 'delete') {
    entity_delete_multiple('followup', $ids);
  }
  else {
    foreach ($ids as $id => $value) {
      $followup = entity_load_single('followup', $value);
      if ($operation == 'unpublish') {
        $followup->status = FALSE;
      }
      elseif ($operation == 'publish') {
        $followup->status = TRUE;
      }
      entity_save('followup', $followup);
    }
  }
  drupal_set_message(t('The update has been performed.'));
  $form_state['redirect'] = $form_state['overview_page_url'];
  cache_clear_all();
}

/**
 * List the selected follow ups and verify that the admin wants to delete them.
 *
 * @param array $form
 *   The form that was submitted.
 * @param array $form_state
 *   An associative array containing the current state of the form.
 *
 * @return boolean
 *   TRUE if the follow ups should be deleted, FALSE otherwise.
 *
 * @ingroup forms
 * @see followup_multiple_delete_confirm_submit()
 */
function followup_multiple_delete_confirm($form, &$form_state, $node) {
  $edit = $form_state['input'];
  $form_state['overview_page_url'] = 'node/' . $node->nid . '/updates';
  $form['followups'] = array(
    '#prefix' => '<ul>',
    '#suffix' => '</ul>',
    '#tree' => TRUE,
  );
  // array_filter() returns only elements with actual values.
  $followup_counter = 0;
  foreach (array_filter($edit['followups']) as $id => $value) {
    $followup = entity_load_single('followup', $id);
    if (is_object($followup) && is_numeric($followup->id)) {
      $title = db_query('SELECT title FROM {followup} WHERE id = :id',
        array(':id' => $id))->fetchField();
      $form['followups'][$id] = array(
        '#type' => 'hidden',
        '#value' => $id,
        '#prefix' => '<li>', '#suffix' => check_plain($title) . '</li>',
      );
      $followup_counter++;
    }
  }
  $form['operation'] = array(
    '#type' => 'hidden',
    '#value' => 'delete',
  );

  if (!$followup_counter) {
    drupal_set_message(t('There do not appear to be any updates to delete, or your selected update was deleted by another administrator.'));
    drupal_goto($form_state['overview_page_url']);
  }
  else {
    return confirm_form($form,
      t('Are you sure you want to delete these updates?'),
      $form_state['overview_page_url'], t('This action cannot be undone.'),
      t('Delete updates'), t('Cancel'));
  }
}

/**
 * Process followup_multiple_delete_confirm form submissions.
 */
function followup_multiple_delete_confirm_submit($form, &$form_state) {
  if ($form_state['values']['confirm']) {
    entity_delete_multiple('followup', array_keys($form_state['values']['followups']));
    cache_clear_all();
    $count = count($form_state['values']['followups']);
    watchdog('content', 'Deleted @count updates.', array('@count' => $count));
    drupal_set_message(format_plural($count, 'Deleted 1 update.',
      'Deleted @count updates.'));
  }
  $form_state['redirect'] = $form_state['overview_page_url'];
}

/**
 * Follow Up entity form.
 */
function followup_form($form, &$form_state, $entity, $op = 'edit') {

  $form_state['followup'] = $entity;

  if ($op == 'clone') {
    $entity->id = '';
    $entity->is_new = TRUE;
  }

  $form['title'] = array(
    '#title' => t('Title'),
    '#description' => t('The title of the update.'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => $entity->title,
  );

  $form['status'] = array(
    '#title' => t('Published'),
    '#description' => t('The published status of the update.'),
    '#type' => 'checkbox',
    '#default_value' => $entity->status,
  );

  field_attach_form('followup', $form_state['followup'], $form, $form_state);

  $form['actions'] = array('#type' => 'actions');
  $submit = array();
  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save update'),
    '#weight' => 40,
    '#submit' => $submit + array('followup_form_submit'),
  );

  // Only add the delete button if we are editting an existing entity.
  $id = $entity->identifier();
  if (!empty($id)) {
    $form['actions']['delete'] = array(
      '#value' => t('Delete update'),
      '#type' => 'submit',
      '#weight' => 45,
      '#submit' => array('followup_form_submit_delete'),
    );
  }

  $form['actions']['cancel'] = array(
    '#type' => 'markup',
    '#markup' => l(t('Cancel'), 'node/' . $entity->nid . '/updates'),
    '#weight' => 50,
  );

  $form['#validate'][] = 'followup_form_validate';

  return $form;
}

/**
 * Follow Up entity form validation handler.
 */
function followup_form_validate(&$form, &$form_state) {
  // Validate the attached fields.
  field_attach_form_validate('followup', $form_state['followup'], $form,
    $form_state);
}

/**
 * Follow Up entity form save (submit) handler.
 */
function followup_form_submit(&$form, &$form_state) {

  // Build entity from the form.
  $entity = entity_ui_form_submit_build_entity($form, $form_state);

  // Save the entity.
  $status = $entity->save();
  if ($status == SAVED_UPDATED) {
    drupal_set_message(t('The update @title has been updated.',
      array('@title' => $entity->title)));
  }
  elseif ($status == SAVED_NEW) {
    drupal_set_message(t('The update @title has been added.',
      array('@title' => $entity->title)));
  }

  // Go back to the list of entities.
  $form_state['redirect'] = 'node/' . $entity->nid . '/updates';
}

/**
 * Follow Up entity form delete (submit) handler.
 */
function followup_form_submit_delete(&$form, &$form_state) {
  // Go to the delete confirmation page.
  $entity = $form_state['followup'];
  $form_state['redirect'] = array(
    'node/' . $entity->nid . '/updates/manage/'
    . (string) $entity->identifier() . '/delete',
    array(
      'query' => array(
        'destination' => 'node/' . $entity->nid . '/updates',
      ),
    ),
  );
}
