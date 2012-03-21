<?php

class TakePartContestUIController extends EntityDefaultUIController {

  public function hook_menu() {

    $items = parent::hook_menu();

    // Make the Contests main page a subsection of the content section
    $items[$this->path]['type'] = MENU_LOCAL_TASK;

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
        'page arguments' => array($type->type),
        'access callback' => '_takepart_contests_contest_access',
        'access arguments' => array('edit'),
        'file' => 'contest.admin.inc',
        'file path' => drupal_get_path('module', $this->entityInfo['module']),
      );
    }

    return $items;
  }
}

function takepart_contests_contest_add_page() {

  $item = menu_get_item();
  $content = system_admin_menu_block($item);

  // go straight to add contest page if there is only 1 type
  if (count($content) == 1) {
    $item = array_shift($content);
    drupal_goto($item['href']);
  }

  return theme('takepart_contests_contest_add_list', array('content' => $content));
}

/**
 * Contest Type entity form wrapper for adding a specific bundle
 */
function takepart_contests_contest_form_wrapper($type_name) {
  $values = array('type' => $type_name);
  $contest = entity_get_controller('takepart_contests_contest')->create($values);
  return entity_ui_get_form('takepart_contests_contest', $contest, 'add');
}

/**
 * Contest Type entity form
 */
function takepart_contests_contest_form($form, &$form_state, $contest, $op = 'edit') {

  if ($op == 'clone') {
    $contest->name .= ' (cloned)';
  }
  
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

  $form_state['takepart_contests_contest'] = $contest;
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
    '#weight' => 40,
    '#submit' => $submit + array('takepart_contests_contest_form_submit'),
  );

  // only add the delete button if we are editting an existing contest
  if (! empty($contest->contest_id)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete contest '),
      '#submit' => $submit + array('takepart_contests_contest_form_submit_delete'),
      '#weight' => 45,
    );
  }
  
  $form['actions']['cance'] = array(
    '#type' => 'markup',
    '#markup' => l(t('Cancel'), 'admin/content/contests'),
    '#weight' => 50,
  );

  $form['#validate'][] = 'takepart_contests_contest_form_validate';

  return $form;
}

/**
 * Contest entity form validation handler
 */
function takepart_contests_contest_form_validate(&$form, &$form_state) {

  // validate the attached fields
  $contest = $form_state['takepart_contests_contest'];
  field_attach_form_validate('takepart_contests_contest', $contest, $form, $form_state);
}

/**
 * Contest entity form save handler
 */
function takepart_contests_contest_form_submit(&$form, &$form_state) {

  // build the contest entity from the form
  $controller = entity_ui_controller('takepart_contests_contest');
  $contest = $controller->entityFormSubmitBuildEntity($form, $form_state);
  
  // set/update the created and changed timestamps
  if ($contest->is_new = isset($contest->is_new) ? $contest->is_new : 0) {
    $contest->created = time();
  }
  $contest->changed = time();

  // save the contest
  $contest->save();
  drupal_set_message(t('The contest %name has been saved.', array('%name' => $contest->name)));

  // go back to the list of content types
  $form_state['redirect'] = 'admin/content/contests';
}

/**
 * Contest entity form delete handler
 */
function takepart_contests_contest_form_submit_delete(&$form, &$form_state) {
  
  // go to the delete confirmation page
  $id = $form_state['takepart_contests_contest']->contest_id;
  $form_state['redirect'] = 'admin/content/contests/manage/' . $id . '/delete?destination=admin/content/contests';
}

function theme_takepart_contests_contest_add_list($variables) {

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
