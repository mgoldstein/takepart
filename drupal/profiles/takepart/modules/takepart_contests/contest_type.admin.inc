<?php

class TakePartContestTypeUIController extends EntityDefaultUIController {

  public function hook_menu() {
    xdebug_break();
    $items = parent::hook_menu();
    $items[$this->path]['description'] = 'Manage contest types, including adding and removing fields and the display of fields.';
    return $items;
  }
}

function takepart_contests_contest_type_form($form, &$form_state, $contest_type, $op = 'edit') {

  if ($op == 'clone') {
    $contest_type->label .= ' (cloned)';
    $contest_type->type = '';
  }
  
  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $contest_type->label,
    '#description' => t('The human-readable name of the contest type'),
    '#required' => TRUE,
    '#size' => 30,
  );

  $form['default_entry_period'] = array(
    '#type' => 'textarea',
    '#title' => t('Default Entry Period'),
    '#default_value' => isset($contest_type->default_entry_period) ? $contest_type->default_entry_period : '',
  );

  $form['type'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($contest_type->type) ? $contest_type->type : '',
    '#maxlength' => 32,
    '#machine_name' => array(
      'exists' => 'takepart_contests_get_types',
      'source' => array('label'),
    ),
    '#description' => t('A unqiue machine-readable name for this contest type. It must only contain lowercase letters, numbers and underscores.'),
  );
  
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save contest type'),
    '#weight' => 40,
  );
  
  return $form;
}

function takepart_contests_contest_type_form_submit(&$form, &$form_state) {
  $contest_type = entity_ui_form_submit_build_entity($form, $form_state);
  $contest_type->save();
  $form_state['redirect'] = 'admin/structure/contest_types';
}

function takepart_contests_contest_type_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/structure/contest_types/manage/' . $form_state['contest_type']->type . '/delete';
}
