<?php

class PetitionUIController extends EntityDefaultUIController {

  public function hook_menu() {

    $items = parent::hook_menu();

    // Make the Petitions main page a subsection of the content section
    $items[$this->path]['type'] = MENU_LOCAL_TASK;

    // Page for adding instances of existing petition types
    $items[$this->path . '/add'] = array(
      'title' => t('Add a petition'),
      'description' => t('Add a new petition'),
      'page callback' => 'petition_add_page',
      'access callback' => 'petition_access',
      'access arguments' => array('edit'),
      'type' => MENU_NORMAL_ITEM,
      'weight' => 0,
      'file' => 'petition.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module']),
    );

    // Page(s) for the adding an instance of a specific petition type
    // these menu entries are used to generate the list on the global add page
    foreach (petition_get_types() as $type) {
      $items[$this->path . '/add/' . $type->type] = array(
        'title' => t('Add a !petition_type', array('!petition_type' => $type->label)),
        'page callback' => 'petition_form_wrapper',
        'page arguments' => array($type->type),
        'access callback' => 'petition_access',
        'access arguments' => array('edit'),
        'file' => 'petition.admin.inc',
        'file path' => drupal_get_path('module', $this->entityInfo['module']),
      );
    }

    return $items;
  }
}

function petition_add_page() {

  $item = menu_get_item();
  $content = system_admin_menu_block($item);

  // go straight to add petition page if there is only 1 type
  if (count($content) == 1) {
    $item = array_shift($content);
    drupal_goto($item['href']);
  }

  return theme('petition_add_list', array('content' => $content));
}

/**
 * Petition entity form wrapper for adding a specific bundle
 */
function petition_form_wrapper($type_name) {
  $values = array('type' => $type_name);
  $petition = entity_get_controller('petition')->create($values);
  return entity_ui_get_form('petition', $petition, 'add');
}

/**
 * Petition entity form
 */
function petition_form($form, &$form_state, $petition, $op = 'edit') {

  if ($op == 'clone') {
    $petition->name .= ' (cloned)';
  }

  $form['name'] = array(
    '#title' => t('Name'),
    '#type' => 'textfield',
    '#default_value' => isset($petition->name) ? $petition->name : '',
    '#description' => t('The human-readable name of the petition'),
    '#required' => TRUE,
    '#size' => 30,
  );

  $form['goal'] = array(
    '#type' => 'textfield',
    '#title' => t('Goal'),
    '#description' => t('The target number of signatures for the petition.'),
    '#default_value' => isset($petition->goal) ? $petition->goal : 1000000,
    '#element_validate' => array('petition_validate_goal',),
    '#required' => TRUE,
  );

  $variable = "petition:{$petition->type}:{$petition->petition_id}:thank_you_page";
  $form['thank_you_page'] = array(
    '#type' => 'textfield',
    '#title' => t('Thank You Page'),
    '#description' => t('The path to the petition thank you page relative to the site root.'),
    '#default_value' => variable_get($variable, ''),
  );

  $variable = "petition:{$petition->type}:{$petition->petition_id}:updates_page";
  $form['updates_page'] = array(
    '#type' => 'textfield',
    '#title' => t('Update Page'),
    '#description' => t('The path to the petition updates page relative to the site root.'),
    '#default_value' => variable_get($variable, ''),
  );

  $variable = "petition:{$petition->type}:{$petition->petition_id}:email_share_msg";
  $form['email_share_msg'] = array(
    '#type' => 'textarea',
    '#title' => t('Email Share Message'),
    '#description' => t('The default message for AddThis email sharing.'),
    '#maxlength' => 255,
    '#default_value' => variable_get($variable, ''),
  );

  $variable = "petition:{$petition->type}:{$petition->petition_id}:twitter_share_msg";
  $form['twitter_share_msg'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter Share Message'),
    '#description' => t('The default message for AddThis Twitter sharing.'),
    '#maxlength' => 255,
    '#default_value' => variable_get($variable, ''),
  );

  $form_state['petition'] = $petition;
  field_attach_form('petition', $petition, $form, $form_state);

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
    '#value' => t('Save petition'),
    '#weight' => 40,
    '#submit' => $submit + array('petition_form_submit'),
  );

  // only add the delete button if we are editting an existing petition
  if (! empty($petition->petition_id)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete petition '),
      '#submit' => $submit + array('petition_form_submit_delete'),
      '#weight' => 45,
    );
  }

  $form['actions']['cancel'] = array(
    '#type' => 'markup',
    '#markup' => l(t('Cancel'), 'admin/content/petitions'),
    '#weight' => 50,
  );

  $form['#validate'][] = 'petition_form_validate';

  return $form;
}

/**
 * Petition entity form validation handler
 */
function petition_form_validate(&$form, &$form_state) {

  // validate the attached fields
  $petition = $form_state['petition'];
  field_attach_form_validate('petition', $petition, $form, $form_state);
}

/**
 * Petition entity form save (submit) handler
 */
function petition_form_submit(&$form, &$form_state) {

  // build the petition entity from the form
  $controller = entity_ui_controller('petition');
  $petition = $controller->entityFormSubmitBuildEntity($form, $form_state);

  // save the petition
  $status = $petition->save();
  if ($status == SAVED_UPDATED) {
    drupal_set_message(t('The petition %name has been updated.',
      array('%name' => $petition->name)));
  }
  else if ($status == SAVED_NEW) {
    drupal_set_message(t('The petition %name has been added.',
      array('%name' => $petition->name)));
  }

  // save the additional settings
  $settings = array(
    'thank_you_page',
    'updates_page',
    'email_share_msg',
    'twitter_share_msg',
  );
  foreach ($settings as $setting) {
    $variable = "petition:{$petition->type}:{$petition->petition_id}:{$setting}";
    $value = $form_state['values'][$setting];
    variable_set($variable, $value);
  }

  // go back to the list of petitions
  $form_state['redirect'] = 'admin/content/petitions';
}

/**
 * Petition entity form delete (submit) handler
 */
function petition_form_submit_delete(&$form, &$form_state) {

  // go to the delete confirmation page
  $form_state['redirect'] = 'admin/content/petitions/manage/'
    . $form_state['petition']->petition_id
    . '/delete?destination=admin/content/petitions';
}

/**
 * Petition type 'Add' list theme handler
 */
function theme_petition_add_list($variables) {

  $content = $variables['content'];
  $output = '';

  if ($content) {

    $output = '<dl class="petition-type-list">';
    foreach ($content as $item) {
      $output .= '<dt>' . l($item['title'], $item['href']) . '</dt>';
      $output .= '<dd>' . filter_xss_admin($item['description']) . '</dd>';
    }
    $output .= '</dl>';
  }
  else {

    if (user_access('administer petition types')) {
      $output = '<p>' . t('Petitions cannot be added because you have not created any petition types yet. Go to the <a href="@create-href">petition type creation page</a> to add a new petition type.', array('@create-href' => url('admin/structure/petition_types/add'))) . '</p>';
    }
    else {
      $output = '<p>' . t('No petition types have been created yet for you to use.') . '</p>';
    }
  }

  return $output;
}
