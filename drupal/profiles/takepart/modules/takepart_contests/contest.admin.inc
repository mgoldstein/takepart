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

  if (! isset($form_state['takepart_contests_contest'])) {
    $form_state['takepart_contests_contest'] = $contest;
  }
  $contest = $form_state['takepart_contests_contest'];

  // When cloning a contest, the name should only be updated when the form is
  // first built, and not when it is built as part of ajax callback
  if (empty($form_state['takepart_contests_label_clone_check'])) {
    // update the name if we are cloning the contest
    if ($op == 'clone') {
      $contest->name .= ' (cloned)';
    }
    $form_state['takepart_contests_label_clone_check'] = TRUE;
  }

  $name = isset($form_state['values']['name']) ? $form_state['values']['name']
    : isset($contest->name) ? $contest->name : '';
  $form['name'] = array(
    '#title' => t('Name'),
    '#type' => 'textfield',
    '#default_value' => $name,
    '#description' => t('The human-readable name of the contest'),
    '#required' => TRUE,
    '#size' => 30,
  );

  $form['period'] = array(
    '#type' => 'fieldset',
    '#title' => t('Entry Period'),
    '#tree' => TRUE,
  );

  $key = isset($form_state['values']['period']['key'])
    ? $form_state['values']['period']['key']
    : implode(' ', $contest->entry_period['key']);
  $form['period']['key'] = array(
    '#type' => 'textfield',
    '#title' => t('Key Fields'),
    '#description' => t('List of field names separated by spaces that make up the unique entry key'),
    '#element_validate' => array('takepart_contests_validate_entry_period_key'),
    '#default_value' => $key,
  );

  $duration = $contest->entry_period['duration'];
  $duration_type = isset($form_state['values']['period']['duration_type'])
    ? $form_state['values']['period']['duration_type'] : $duration['type'];
  $form['period']['duration_type'] = array(
    '#type' => 'select',
    '#title' => t('Duration'),
    '#description' => t('The type of duration to use for limiting entries. None places no limits on entries, slot limits entries to one per time slot with no limitation on the time between entries, span limits entries to once per some amount of time, and phase limits entries to once per item in a list of start and end dates.'),
    '#default_value' => $duration_type,
    '#options' => array(
      TakePartContest::DURATION_NONE => t('None - Do not limit the number entries'),
      TakePartContest::DURATION_SLOT => t('Slot - Allow an entry any time once per ...'),
      TakePartContest::DURATION_SPAN => t('Span - Entries must be separated by at least ...'),
    ),
    '#ajax' => array(
      'event' => 'change',
      'callback' => 'takepart_contests_contest_duration_callback',
      'wrapper' => 'takepart-contests-entry-period-settings',
    ),
  );

  $form['period']['duration_settings'] = array(
    '#type' => 'container',
    '#prefix' => '<div id="takepart-contests-entry-period-settings">',
    '#suffix' => '</div>',
  );

  $count = empty($form_state['values']['period']['duration_settings']['count'])
    ? $duration['count']
    : $form_state['values']['period']['duration_settings']['count'];

  $units = empty($form_state['values']['period']['duration_settings']['units'])
    ? $duration['units']
    : $form_state['values']['period']['duration_settings']['units'];

  if ($duration_type == TakePartContest::DURATION_NONE) {
    $form['period']['duration_settings']['count'] = array(
      '#type' => 'value',
      '#value' => $count,
    );
    $form['period']['duration_settings']['units'] = array(
      '#type' => 'value',
      '#value' => $units,
    );
  }
  else if ($duration_type == TakePartContest::DURATION_SLOT) {
    $form['period']['duration_settings']['count'] = array(
      '#type' => 'value',
      '#value' => $count,
    );
    $form['period']['duration_settings']['units'] = array(
      '#type' => 'select',
      '#title' => t('Units'),
      '#description' => t('The units of measurement for the duration'),
      '#options' => array(
        TakePartContest::UNITS_HOURS => t('Hour'),
        TakePartContest::UNITS_DAYS => t('Day'),
        TakePartContest::UNITS_WEEKS => t('Week'),
        TakePartContest::UNITS_MONTHS => t('Month'),
        TakePartContest::UNITS_YEARS => t('Year'),
        TakePartContest::UNITS_LIFETIME => t('Lifetime'),
      ),
      '#default_value' => $units,
    );
  }
  else {
    $form['period']['duration_settings']['count'] = array(
      '#type' => 'textfield',
      '#title' => t('Count'),
      '#description' => t('The number of units in the duration'),
      '#size' => 4,
      '#required' => TRUE,
      '#element_validate' => array('_element_validate_integer_positive'),
      '#default_value' => $count,
    );
    $form['period']['duration_settings']['units'] = array(
      '#type' => 'select',
      '#title' => t('Units'),
      '#description' => t('The units of measurement for the duration'),
      '#options' => array(
        TakePartContest::UNITS_MINUTES => t('Minutes'),
        TakePartContest::UNITS_HOURS => t('Hours'),
        TakePartContest::UNITS_DAYS => t('Days'),
        TakePartContest::UNITS_WEEKS => t('Weeks'),
      ),
      '#default_value' => $units,
    );
  }

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

  $form['actions']['cancel'] = array(
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

function takepart_contests_validate_entry_period_key($element, &$form_state) {
  $value = $element['#value'];
  if (!empty($value) && !preg_match('/^[a-zA-Z0-9_ ]+$/', $value)) {
    form_error($element, t('%name must be a space delimited list of field names.',
      array('%name' => $element['#title'])));
  }
}

function takepart_contests_contest_duration_callback(&$form, $form_state) {
  return $form['period']['duration_settings'];
}

/**
 * Contest entity form save handler
 */
function takepart_contests_contest_form_submit(&$form, &$form_state) {

  // build the contest entity from the form
  $contest = entity_ui_form_submit_build_entity($form, $form_state);

  // clean up the list of key fields
  $fields = explode(' ', $form_state['values']['period']['key']);
  $fields = array_map('trim', $fields);
  $fields = array_filter($fields, 'strlen');

  // update the entry period
  $contest->entry_period = array(
    'key' => $fields,
    'duration' => array(
      'type' => $form_state['values']['period']['duration_type'],
      'count' => $form_state['values']['period']['duration_settings']['count'],
      'units' => $form_state['values']['period']['duration_settings']['units'],
    ),
  );

  // save the contest
  $status = $contest->save();
  if ($status == SAVED_UPDATED) {
    drupal_set_message(t('The contest %name has been updated.',
      array('%name' => $contest->name)));
  }
  else if ($status == SAVED_NEW) {
    drupal_set_message(t('The contest %name has been added.',
      array('%name' => $contest->name)));
  }

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
