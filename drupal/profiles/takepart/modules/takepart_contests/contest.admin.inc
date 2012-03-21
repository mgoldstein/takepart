<?php

class TakePartContestUIController extends EntityDefaultUIController {

  public function hook_menu() {
    //return parent::hook_menu();
    
    $items = array();
    $id_count = count(explode('/', $this->path));
    if (isset($this->entityInfo['admin ui']['menu wildcard'])) {
      $wildcard = $this->entityInfo['admin ui']['menu wildcard'];
    }
    else {
      $wildcard = '%' . $this->entityType;
    }
  
    // The main admin page for contests, show an overview of all contests
    $items[$this->path] = array(
      'title' => 'Contests',
      'description' => 'Add edit and update contests',
      'access arguments' => array('access administration pages'),
      'page callback' => 'takepart_contests_contest_overview_page',
      'file' => 'contest.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module']),
      'type' => MENU_LOCAL_TASK,
    );
    
    // Page for adding instances of existing contest types
    $items[$this->path . '/add'] = array(
      'title' => 'Add a contest',
      'description' => 'Add a new contest',
      'page callback' => 'takepart_contests_contest_add_page',
      'access callback' => '_takepart_contests_contest_access',
      'access arguments' => array('edit'),
      'type' => MENU_NORMAL_ITEM,
      'weight' => 0,
      'file' => 'contest.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module']),
    );

    // Page(s) for the adding an instance of a specific contest type
    // these menu entries are used to generate the list on the global add page
    foreach (takepart_contests_get_types() as $type) {
      $items[$this->path . '/add/' . $type->type] = array(
        'title' => 'Add a ' . $type->label,
        'page callback' => 'takepart_contests_contest_form_wrapper',
        'page arguments' => array(takepart_contests_contest_create(array('type' => $type->type))),
        'access callback' => '_takepart_contests_contest_access',
        'access arguments' => array('edit'),
        'file' => 'contest.admin.inc',
        'file path' => drupal_get_path('module', $this->entityInfo['module']),
      );
    }

    // Page for editting a contest instance
    $items[$this->path . '/manage/%'] = array(
      'title' => 'Edit',
      'page callback' => 'takepart_contests_contest_edit_page',
      'page arguments' => array($id_count + 1),
      'access callback' => '_takepart_contests_contest_access',
      'access arguments' => array('edit'),
      'type' => MENU_LOCAL_TASK,
      'weight' => 0,
      'file' => 'contest.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module']),
    );

    // Page for cloning a contest instance
    $items[$this->path . '/manage/%/clone'] = array(
      'title' => 'Edit',
      'page callback' => 'takepart_contests_contest_clone_page',
      'page arguments' => array($id_count + 1),
      'access callback' => '_takepart_contests_contest_access',
      'access arguments' => array('edit'),
      'type' => MENU_LOCAL_TASK,
      'weight' => 0,
      'file' => 'contest.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module']),
    );
    
    // Page for deleting a contest instance
    $items[$this->path . '/manage/%/delete'] = array(
      'title' => 'Edit',
      'page callback' => 'takepart_contests_contest_delete_page',
      'page arguments' => array($id_count + 1),
      'access callback' => '_takepart_contests_contest_access',
      'access arguments' => array('edit'),
      'type' => MENU_LOCAL_TASK,
      'weight' => 0,
      'file' => 'contest.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module']),
    );

    return $items;
  }
}

function takepart_contests_contest_set_breadcrumb() {
  $breadcrumb = array(
    l(t('Home'), '<front>'),
    l(t('Administration'), 'admin'),
    l(t('Content'), 'admin/content'),
    l(t('Contests'), 'admin/content/contests'),
  );
  drupal_set_breadcrumb($breadcrumb);
}

function takepart_contests_contest_overview_page() {
  takepart_contests_contest_set_breadcrumb();
  drupal_set_title(t('Contests'), PASS_THROUGH);
  $controller = entity_ui_controller('takepart_contests_contest');
  return $controller->overviewForm();
}

function takepart_contests_contest_add_page() {
  takepart_contests_contest_set_breadcrumb();
  drupal_set_title(t('Add Contest'), PASS_THROUGH);
  $item = menu_get_item();
  $content = system_admin_menu_block($item);
  if (count($content) == 1) {
    $item = array_shift($content);
    drupal_goto($item['href']);
  }
  return theme('takepart_contests_contest_add_list', array('content' => $content));
}

function theme_takepart_contests_contest_add_list($variables) {
  takepart_contests_contest_set_breadcrumb();
  drupal_set_title(t('Add Contest'), PASS_THROUGH);
  $content = $variables['content'];
  $output = '';
  
  if ($content) {
    $output = '<dl class="contest-type-list">';
    foreach ($content as $item) {
      $output .= '<dt>' . l($item['title'], $item['href']) . '</dt>';
      $output .= '<dd>' . filter_xss_admin($item['description']) . '</dd>';
    }
    $output .= '</dl>';
  }
  else {
    if (user_access('administer takepart contest types')) {
      $output = '<p>' . t('Contests cannot be added because you have not created any contest types yet. Go to the <a href="@create-contest-type">contest type creation page</a> to add a new contest type.', array('@create-contest-type' => url('admin/structure/contest_types/add'))) . '</p>';
    }
    else {
      $output = '<p>' . t('No contest types have been created yet for you to use.') . '</p>';
    }
  }
  
  return $output;
}

function takepart_contests_contest_form_wrapper($contest) {
  takepart_contests_contest_set_breadcrumb();
  $type = takepart_contests_get_types($contest->type);
  drupal_set_title(t('Add %name', array('%name' => $type->label)), PASS_THROUGH);
  return drupal_get_form('takepart_contests_contest_edit_form', $contest);
}

function takepart_contests_contest_edit_page($contest_id) {
  $contest = takepart_contests_contest_load($contest_id);
  takepart_contests_contest_set_breadcrumb();
  drupal_set_title(t('Edit contest %name', array('%name' => $contest->name)), PASS_THROUGH);
  return drupal_get_form('takepart_contests_contest_edit_form', $contest);
}

function takepart_contests_contest_clone_page($contest_id) {
  takepart_contests_contest_set_breadcrumb();
  drupal_set_title(t('Clone contest %name', array('%name' => $contest->name)), PASS_THROUGH);
  $contest = takepart_contests_contest_load($contest_id);
  return drupal_get_form('takepart_contests_contest_clone_form', $contest, 'clone');
}

function takepart_contests_contest_delete_page($contest_id) {
  $contest = takepart_contests_contest_load($contest_id);
  takepart_contests_contest_set_breadcrumb();
  drupal_set_title(t('Delete contest %name', array('%name' => $contest->name)), PASS_THROUGH);
  return drupal_get_form('takepart_contests_contest_delete_form', $contest);
}

function takepart_contests_contest_edit_form($form, &$form_state, $contest, $op = 'edit') {

  if ($op == 'clone') {
    $contest->name .= ' (cloned)';
  }
  
  $form_state['takepart_contests_contest'] = $contest;
  
  $form['name'] = array(
    '#title' => t('Name'),
    '#type' => 'textfield',
    '#default_value' => isset($contest->name) ? $contest->name : '',
    '#description' => t('The human-readable name of the contest'),
    '#required' => TRUE,
    '#size' => 30,
  );

  if (isset($contest->is_new) && $contest->is_new) {
    $type = takepart_contests_get_types($contest->type);
    $default_value = isset($type->default_entry_period) ? $type->default_entry_period : '';
  }
  else {
    $default_value = isset($contest->entry_period) ? $contest->entry_period : '';
  }

  $form['entry_period'] = array(
    '#type' => 'textarea',
    '#title' => t('Entry Period'),
    '#default_value' => $default_value,
  );

  field_attach_form('takepart_contests_contest', $contest, $form, $form_state);

  $form['actions'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('form-actions')),
    '#weight' => 400,
  );
  
  $submit = array();

  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save contest'),
    '#submit' => $submit + array('takepart_contests_contest_edit_form_submit'),
  );
  
  if (!empty($model->name)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete contest'),
      '#suffix' => l(t('Cancel'), 'admin/content/contests'),
      '#submit' => $submit + array('takepart_contests_contest_edit_form_submit_delete'),
      '#weight' => 45,
    );
  }
  
  $form['#validate'][] = 'takepart_contests_contest_edit_form_validate';

  return $form;
}

function takepart_contests_contest_edit_form_validate(&$form, &$form_state) {
  $contest = $form_state['takepart_contests_contest'];
  field_attach_form_validate('takepart_contests_contest', $contest, $form, $form_state);
}

function takepart_contests_contest_edit_form_submit(&$form, &$form_state) {
  $controller = entity_ui_controller('takepart_contests_contest');
  $contest = $controller->entityFormSubmitBuildEntity($form, $form_state);
  
  if ($contest->is_new = isset($contest->is_new) ? $contest->is_new : 0) {
    $contest->created = time();
  }
  $contest->modified = time();
  $contest->save();
  drupal_set_message(t('The contest %name has been saved.', array('%name' => $contest->name)));
  $form_state['redirect'] = 'admin/content/contests';
}

function takepart_contests_contest_edit_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/content/contests/manage/' . $form_state['takepart_contests_contest']->contest_id . '/delete';
}

function takepart_contests_contest_clone_form($form, &$form_state, $contest, $op = 'edit') {
  $form['not_available'] = array(
    '#type' => 'markup',
    '#markup' => '<h1>Currently not available.</h1>',
  );
  return $form;
}

function takepart_contests_contest_delete_form($form, &$form_state, $contest) {
  $form_state['takepart_contests_contest'] = $contest;
  $form['#submit'][] = 'takepart_contests_contest_delete_form_submit';

  $form = confirm_form($form,
    t('Are you sure you want to delete contest %name?', array('%name' => $contest->name)),
    'admin/content/contests',
    '<p>' . t('This action cannot be undone.') . '</p>',
    t('Delete'),
    t('Cancel'),
    'confirm'
  );
  return $form;
}

function takepart_contests_contest_delete_form_submit($form, &$form_state) {
  $contest = $form_state['takepart_contests_contest'];
  takepart_contests_contest_delete($contest);
  drupal_set_message(t('The contest %name has been deleted.', array('%name' => $contest->name)));
  $form_state['redirect'] = 'admin/content/contests';
}
