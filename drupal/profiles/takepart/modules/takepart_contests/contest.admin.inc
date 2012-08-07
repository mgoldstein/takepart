<?php
/**
 * @file
 * Administrative interface for Contests.
 */

/**
 * Contest Admin UI Controller.
 */
class TakePartContestUIController extends EntityDefaultUIController {

  public function hook_menu() {
    $items = parent::hook_menu();
    
    // Update the description for the main admin page.
    $items[$this->path]['description'] = 'Manage the Ideas for Good contest name and entry period.';

    // Don't allow any new contests to be added. They need to be re-worked to be
    // node based.
    unset($items[$this->path . '/add']);

    return $items;
  }
}

/**
 * Contest entity form
 */
function takepart_contests_contest_form($form, &$form_state, $entity, $op = 'edit') {

  $form_state['takepart_contests_contest'] = $entity;

  if ($op == 'clone' && !isset($form_state['values'])) {
    $entity->contest_id = '';
    $entity->name .= ' (cloned)';
    $entity->is_new = TRUE;
  }

  $name = isset($form_state['values']['name']) ? $form_state['values']['name']
    : $entity-> name;
  $form['name'] = array(
    '#title' => t('Name'),
    '#type' => 'textfield',
    '#default_value' => $name,
    '#description' => t('The human-readable name of the contest'),
    '#required' => TRUE,
    '#size' => 30,
  );

  $form['period'] = array(
    '#title' => t('Entry Period'),
    '#type' => 'fieldset',
    '#tree' => TRUE,
  );

  $duration = $entity->entry_period['duration'];
  $duration_type = empty($form_state['values']['period']['duration_type'])
    ? $duration['type']
    : $form_state['values']['period']['duration_type'];
  $form['period']['duration_type'] = array(
    '#title' => t('Duration'),
    '#description' => t('The type of duration to use for limiting entries. None places no limits on entries, slot limits entries to one per time slot with no limitation on the time between entries, span limits entries to once per some amount of time, and phase limits entries to once per item in a list of start and end dates.'),
    '#type' => 'select',
    '#options' => array(
      TakePartContest::DURATION_NONE => t('None - Do not limit the number entries'),
      TakePartContest::DURATION_SLOT => t('Slot - Allow an entry any time once per ...'),
      TakePartContest::DURATION_SPAN => t('Span - Entries must be separated by at least ...'),
    ),
    '#ajax' => array(
      'event' => 'change',
      'callback' => 'takepart_contests_contest_form_callback',
      'wrapper' => 'takepart-contests-entry-period-settings',
    ),
    '#default_value' => $duration_type,
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
      '#title' => t('Units'),
      '#description' => t('The units of measurement for the duration'),
      '#type' => 'select',
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
      '#title' => t('Count'),
      '#description' => t('The number of units in the duration'),
      '#type' => 'textfield',
      '#size' => 4,
      '#required' => TRUE,
      '#element_validate' => array('_element_validate_integer_positive'),
      '#default_value' => $count,
    );
    $form['period']['duration_settings']['units'] = array(
      '#title' => t('Units'),
      '#description' => t('The units of measurement for the duration'),
      '#type' => 'select',
      '#options' => array(
        TakePartContest::UNITS_MINUTES => t('Minutes'),
        TakePartContest::UNITS_HOURS => t('Hours'),
        TakePartContest::UNITS_DAYS => t('Days'),
        TakePartContest::UNITS_WEEKS => t('Weeks'),
      ),
      '#default_value' => $units,
    );
  }

  field_attach_form('takepart_contests_contest',
    $form_state['takepart_contests_contest'], $form, $form_state);

  $form['actions'] = array('#type' => 'actions');
  $submit = array();
  if (! empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save contest'),
    '#weight' => 40,
    '#submit' => $submit + array('takepart_contests_contest_form_submit'),
  );

  // only add the delete button if we are editting an existing entity
  $id = $entity->identifier();
  if (! empty($id)) {
    $form['actions']['delete'] = array(
      '#value' => t('Delete contest'),
      '#type' => 'submit',
      '#weight' => 45,
      '#submit' => array('takepart_contests_contest_form_submit_delete'),
    );
  }

  $form['actions']['cancel'] = array(
    '#type' => 'markup',
    '#markup' => l(t('Cancel'), 'admin/config/marigold-ideasforgood/contests'),
    '#weight' => 50,
  );

  $form['#validate'][] = 'takepart_contests_contest_form_validate';

  return $form;
}

function takepart_contests_contest_form_callback(&$form, $form_state) {
  return $form['period']['duration_settings'];
}

/**
 * Contest entity form validation handler
 */
function takepart_contests_contest_form_validate(&$form, &$form_state) {
  // Validate the attached fields.
  field_attach_form_validate('takepart_contests_contest',
    $form_state['takepart_contests_contest'], $form, $form_state);
}

/**
 * Contest entity form save handler
 */
function takepart_contests_contest_form_submit(&$form, &$form_state) {

  // build the contest entity from the form
  $entity = entity_ui_form_submit_build_entity($form, $form_state);

  // update the entry period
  $entity->entry_period = array(
    'duration' => array(
      'type' => $form_state['values']['period']['duration_type'],
      'count' => $form_state['values']['period']['duration_settings']['count'],
      'units' => $form_state['values']['period']['duration_settings']['units'],
    ),
  );

  // Save the entity.
  $status = $entity->save();
  if ($status == SAVED_UPDATED) {
    drupal_set_message(t('The contest %name has been updated.',
      array('%name' => $entity->name)));
  }
  else if ($status == SAVED_NEW) {
    drupal_set_message(t('The contest %name has been added.',
      array('%name' => $entity->name)));
  }

  // Go back to the list of entities.
  $form_state['redirect'] = 'admin/config/marigold-ideasforgood/contests';
}

/**
 * Contest entity form delete handler
 */
function takepart_contests_contest_form_submit_delete(&$form, &$form_state) {
  // Go to the delete confirmation page.
  $form_state['redirect'] = array(
    'admin/config/marigold-ideasforgood/contests/manage/'
      . (string) $form_state['takepart_contests_contest']->identifier()
      . '/delete',
    array(
      'query' => array(
        'destination' => 'admin/config/marigold-ideasforgood/contests',
      ),
    ),
  );
}
