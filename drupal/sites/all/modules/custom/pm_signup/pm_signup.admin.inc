<?php

function pm_signup_endpoint_load_by_name($name) {
  return SignupEndpoint::loadByName($name);
}

function pm_signup_endpoint_page_title($endpoint) {
  $title = $endpoint->getLabel();
  if (empty($title)) { $title = t('Unlabeled Endpoint'); }
  return $title;
}

function pm_signup_endpoint_list_headers() {
  return array(
    t('ID'),
    t('Label'),
    t('Name'),
    array(
      'data' => t('Operations'),
      'colspan' => 2,
    ),
  );
}

function pm_signup_endpoint_list_data() {
  $data_query = db_select('pm_signup_endpoint', 'ep')
    ->fields('ep', array('id', 'label', 'name'))
    ->condition('name', '', '!=')
    ->orderBy('label');
  $paged_query = $data_query->extend('PagerDefault')->limit(25);
  return $paged_query->execute()->fetchAllAssoc('id');
}

function pm_signup_endpoint_listing_rows($endpoints) {
  $rows = array();
  foreach ($endpoints as $id => $endpoint) {
    $path = 'admin/config/signups/endpoints/manage/' . $id;
    $row = array();
    $row[] = l($id, $path);
    $row[] = $endpoint->label;
    $row[] = $endpoint->name;
    $row[] = l(t('edit'), $path);
    $row[] = l(t('delete'), $path . '/delete');
    $rows[] = $row;
  }
  return $rows;
}

function pm_signup_endpoint_listing_page() {
  $endpoints = pm_signup_endpoint_list_data();
  return array(
    'table' => array(
      '#theme' => 'table',
      '#header' => pm_signup_endpoint_list_headers(),
      '#rows' => pm_signup_endpoint_listing_rows($endpoints),
      '#empty' => t('None.'),
    ),
    'pager' => array('#theme' => 'pager'),
  );
}

function pm_signup_endpoint_handler_ids() {
  $ids = array();
  $plugins = ctools_get_plugins('pm_signup', 'handler');
  foreach ($plugins as $id => $plugin) {
    $class = ctools_plugin_get_class($plugin, 'handler');
    if (class_exists($class)) {
      $ids[] = $id;
    }
  }
  return $ids;
}

function pm_signup_endpoint_form_defaults() {
  $defaults = array(
    'type' => 'NewsletterCampaignSignupEndpoint',
    'label' => '',
    'name' => '',
    'plugins' => array(),
  );
  foreach (pm_signup_endpoint_handler_ids() as $id) {
    $defaults['plugins'][$id] = array(
      'enabled' => FALSE,
      'configuration' => '',
    );
  }
  return $defaults;
}

function pm_signup_endpoint_form_values($endpoint) {
  $values = pm_signup_endpoint_form_defaults();
  if (!is_null($endpoint)) {
    $values['type'] = get_class($endpoint);
    $values['label'] = $endpoint->getLabel();
    $values['name'] = $endpoint->getName();
    foreach (pm_signup_endpoint_handler_ids() as $id) {
      $values['plugins'][$id]['enabled'] = $endpoint->getPluginEnabled($id);
      $values['plugins'][$id]['configuration']
        = $endpoint->getPluginConfiguration($id);
    }
  }
  return $values;
}

function pm_signup_endpoint_form($form, &$form_state, $endpoint, $op) {

  $form_state['op'] = $op;
  $form_state['endpoint'] = $endpoint;
  $values = pm_signup_endpoint_form_values($endpoint);

  $signup_types = array(
    'NewsletterCampaignSignupEndpoint' => t('Newsletter'),
    'SignatureSignupEndpoint' => t('Action Opt-In'),
    'TakePartUserSignupEndpoint' => t('User Registration'),
  );

  if ($op === 'add') {
    $form['type'] = array(
      '#title' => t('Type'),
      '#description' => t('The type of signup endpoint'),
      '#type' => 'select',
      '#options' => $signup_types,
      '#required' => TRUE,
      '#default_value' => $values['type'],
    );
  }
  else {
    $form['type'] = array(
      '#title' => t('Type'),
      '#type' => 'item',
      '#markup' => $signup_types[$values['type']],
    );
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#description' => t('The human-readable name of the signup endpoint'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#size' => 60,
    '#default_value' => $values['label'],
  );

  $form['name'] = array(
    '#title' => t('Name'),
    '#description' => t('A unqiue machine-readable name for this signature type. It must only contain lowercase letters, numbers and underscores.'),
    '#type' => 'machine_name',
    '#maxlength' => 255,
    '#machine_name' => array(
      'exists' => 'pm_signup_endpoint_load_by_name',
      'source' => array('label'),
    ),
    '#default_value' => $values['name'],
  );

  foreach (pm_signup_endpoint_handler_ids() as $id) {
    $element = str_replace(array('-', '.'), array('_', '_'), $id);
    $form[$element] = array(
      '#title' => $id,
      '#type' => 'fieldset',
    );
    $form[$element][$element . '_enabled'] = array(
      '#title' => t('Enabled'),
      '#type' => 'checkbox',
      '#default_value' => $values['plugins'][$id]['enabled'],
    );
    $configuration = $values['plugins'][$id]['configuration'];
    $json = empty($configuration) ? ''
      : json_encode($configuration, JSON_PRETTY_PRINT);
    $form[$element][$element . '_configuration'] = array(
      '#title' => t('Configuration'),
      '#type' => 'textarea',
      '#default_value' => $json,
      '#rows' => 10,
    );
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save endpoint'),
    '#weight' => 40,
  );

  return $form;
}

function pm_signup_endpoint_handlers($endpoint) {
  static $handlers = FALSE;
  if ($handlers === FALSE) {
    $handlers = array();
    $plugins = ctools_get_plugins('pm_signup', 'handler');
    foreach ($plugins as $id => $plugin) {
      $class = ctools_plugin_get_class($plugin, 'handler');
      if (class_exists($class)) {
        $handlers[$id] = new $class($plugin,
          $endpoint->getPluginConfiguration($id));
      }
    }
  }
  return $handlers;
}

function pm_signup_endpoint_form_validate($form, $form_state) {

  $endpoint = $form_state['endpoint'];
  $type = $form_state['values']['type'];
  if ($form_state['op'] === 'add') {
    $endpoint = new $type();
  }

  foreach (pm_signup_endpoint_handlers($endpoint) as $id => $handler) {
    $element = str_replace(array('-', '.'), array('_', '_'), $id) . '_configuration';
    $json = trim($form_state['values'][$element]);
    $configuration = empty($json) ? array() : json_decode($json);
    if (!is_null($configuration)) {
      $errors = $handler->validateConfiguration($type, $configuration);
      foreach ($errors as $error) {
        form_set_error($element, $error);
      }
    }
    else {
      form_set_error($element, t(
       'Invalid configuration syntax for %label configuration',
        array('%label' => $id)
      ));
    }
  }
}

function pm_signup_endpoint_form_submit($form, &$form_state) {

  $endpoint = $form_state['endpoint'];
  $type = $form_state['values']['type'];
  if ($form_state['op'] === 'add') {
    $endpoint = new $type();
  }

  $endpoint->labelForExport($form_state['values']['label'],
    $form_state['values']['name']);

  foreach (pm_signup_endpoint_handler_ids() as $id) {
    $element = str_replace(array('-', '.'), array('_', '_'), $id);

    $enabled = $form_state['values'][$element . '_enabled'] ? TRUE : FALSE;
    $endpoint->setPluginEnabled($id, $enabled);

    $json = trim($form_state['values'][$element . '_configuration']);
    $configuration = empty($json) ? array() : json_decode($json);
    $endpoint->setPluginConfiguration($id, $configuration);
  }

  $action = is_null($endpoint->getID()) ? 'added' : 'updated';
  $endpoint->save();
  drupal_set_message(t('The signup endpoint %label has been !action.', array(
    '%label' => $endpoint->getLabel(),
    '!action' => $action,
  )));
  $form_state['redirect'] = 'admin/config/signups/endpoints';
}

function pm_signup_endpoint_delete_form($form, &$form_state, $endpoint) {
  $form_state['endpoint'] = $endpoint;
  $question = t('Are you sure you want to delete signup endpoint %label?',
    array('%label' => $endpoint->getLabel())
  );
  return confirm_form($form, $question, 'admin/config/signups/endpoints');
}

function pm_signup_endpoint_delete_form_submit($form, &$form_state) {
  $endpoint = $form_state['endpoint'];
  $endpoint->delete();
  drupal_set_message(t('Signup endpoint %label deleted.', array(
    '%label' => $endpoint->getLabel()
  )));
  $form_state['redirect'] = 'admin/config/signups/endpoints';
}
