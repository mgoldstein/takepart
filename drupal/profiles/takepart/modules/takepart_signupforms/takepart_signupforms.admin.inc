<?php

/**
 * Get the settings for a field attached to a bundle
 *
 * This function always returns an array of settings even if no settings
 * previously existed.
 *
 * @param string $entity_type
 *   The entity type of the bundle
 * @param string $bundle
 *   The bundle name
 * @param string $field_name
 *   The name of the field
 * @return associative array
 *   A associative array containing:
 *   - form_id: The integer ID of the BSD form
 *   - field_id: The integer ID of the BSD field
 *   - send_updates: A boolean indicating if updates to the field should trigger
 *     a submission to BSD
 */
function _takepart_signupforms_field_settings($entity_type, $bundle, $field_name) {

  // sub-query to get the BSD field settings
  $subquery = db_select('takepart_signupforms_fields', 'ff')
    ->fields('ff', array('bundle_id','form_id','field_id','send_updates'))
    ->condition('ff.field_name', $field_name, '=');

  // query to get the BSD field settings and join in the bundle enabled flag
  // this query will return all the bundles even if they have no configured fields
  $query = db_select($subquery, 'f');
  $query->rightJoin('takepart_signupforms_bundles', 'b', 'f.bundle_id = b.id');
  $query->fields('f', array('form_id', 'field_id', 'send_updates'))
    ->fields('b', array('enabled'))
    ->condition('b.entity_type', $entity_type, '=')
    ->condition('b.bundle', $bundle, '=');

  return $query->execute()
    ->fetchAssoc();
}

/**
 * Alter the field settings form.
 */
function _takepart_signupforms_field_settings_form_alter(&$form, $form_state, $form_id) {

  $supported_field_types = array('text', 'text_long', 'text_with_summary',
    'list_integer', 'list_text', 'list_boolean', 'date', 'datetime', 'zip_code',
    'partner_code');

  if (in_array($form['#field']['type'], $supported_field_types)) {

    $entity_type = $form['#instance']['entity_type'];
    $bundle = $form['#instance']['bundle'];
    $field_name = $form['#instance']['field_name'];

    $result = _takepart_signupforms_field_settings($entity_type, $bundle, $field_name);

    if ($result && $result['enabled']) {

      // get the settings for the field
      $settings_form_id = isset($result['form_id']) ? $result['form_id'] : '';
      $settings_field_id = isset($result['field_id']) ? $result['field_id'] : '';
      $settings_updates = isset($result['send_updates']) ? $result['send_updates'] : 0;

      $form_id = isset($form_state['values']['takepart_signupforms']['form_id'])
        ? $form_state['values']['takepart_signupforms']['form_id'] : $settings_form_id;
      $field_id = isset($form_state['values']['takepart_signupforms']['field_id'])
        ? $form_state['values']['takepart_signupforms']['field_id'] : $settings_field_id;
      $send_updates = isset($form_state['values']['send_updates'])
        ? $form_state['values']['send_updates'] : $settings_updates;

      // add form elements for BSD settings
      $form['takepart_signupforms'] = array(
        '#title' => 'Blue State Digital Signup Tracking',
        '#type' => 'fieldset',
        '#description' => t('Select the Blue State Digital signup form and field corresponding to this field.'),
        '#tree' => TRUE,
      );

      $form['takepart_signupforms']['form_id'] =
        bluestatedigital_forms_signup_form_id($form_id);
      $form['takepart_signupforms']['form_id'] += array(
        '#ajax' => array(
          'event' => 'change',
          'callback' => 'takepart_signupforms_form_id_callback',
          'wrapper' => 'takepart-signup-field-select',
        ),
      );

      $form['takepart_signupforms']['field_id'] =
        bluestatedigital_forms_signup_field_id($form_id, $field_id);
      $form['takepart_signupforms']['field_id'] += array(
        '#prefix' => '<div id="takepart-signup-field-select">',
        '#suffix' => '</div>',
      );

      $form['takepart_signupforms']['send_updates'] = array(
        '#title' => 'Resubmit signup when field is updated',
        '#type' => 'checkbox',
        '#default_value' => $send_updates,
      );

      // add a submit handler to save our part of the settings
      $form['#submit'][] = '_takepart_signupforms_settings_form_submit';
    }
  }
}

function takepart_signupforms_form_id_callback(&$form, $form_state) {
  return $form['takepart_signupforms']['field_id'];
}

/**
 * Submit callback for saving the signup forms part of the field settings
 */
function _takepart_signupforms_settings_form_submit($form, &$form_state) {

  $values = $form_state['values']['takepart_signupforms'];

  // get the bundle record id of the entity_type/bundle of the field
  $query = db_select('takepart_signupforms_bundles', 'b')
    ->fields('b', array('id'))
    ->condition('b.entity_type', $form['#instance']['entity_type'], '=')
    ->condition('b.bundle', $form['#instance']['bundle'], '=');
  $result = $query->execute()
    ->fetchAssoc();

  if ($result) {

    // save the BSD field setting
    db_merge('takepart_signupforms_fields')
      ->key(array(
          'bundle_id' => $result['id'],
          'field_name' => $form['#instance']['field_name'],
        ))
      ->insertFields(array(
          'bundle_id' => $result['id'],
          'field_name' => $form['#instance']['field_name'],
          'form_id' => empty($values['form_id']) ? 0 : $values['form_id'],
          'field_id' => empty($values['field_id']) ? 0 : $values['field_id'],
          'send_updates' => $values['send_updates'],
        ))
      ->updateFields(array(
          'form_id' => empty($values['form_id']) ? 0 : $values['form_id'],
          'field_id' => empty($values['field_id']) ? 0 : $values['field_id'],
          'send_updates' => $values['send_updates'],
        ))
      ->execute();
  }

  cache_clear_all('takepart_signupforms:', 'cache', TRUE);
}

function _takepart_signupforms_bundle_field_values() {

  $field_values = array();

  // get a list of all the entity types
  $entity_types = entity_get_info();

  foreach ($entity_types as $type => $info) {

    if (isset($info['bundles']) && (!empty($info['fieldable']))) {

      // get the existing settings for the entity type's bundles
      $results = db_select('takepart_signupforms_bundles', 'm')
        ->fields('m', array('bundle', 'enabled'))
        ->condition('m.entity_type', $type, '=')
        ->execute()
        ->fetchAllKeyed();

      // create the option and default value lists for the entity type
      $options = array();
      $default_value = array();

      foreach ($info['bundles'] as $bundle => $bundle_info) {
        $options[$bundle] = $bundle_info['label'];
        if (! empty($results[$bundle])) {
          $default_value[$bundle] = $bundle;
        }
      }

      $field_values[$type] = array(
        '#options' => $options,
        '#default_value' => $default_value,
      );
    }
  }

  return $field_values;
}

function takepart_signupforms_admin($form, &$form_state) {

  // Bundle List
  $form['enabled_bundles'] = array(
    '#type' => 'fieldset',
    '#title' => t('Enabled Content Types'),
    '#tree' => TRUE,
    '#description' => t('Check the content types that should have the option to send their fields to Blue State Digital enabled.'),
  );

  // get a list of all the entity types
  $entity_types = entity_get_info();

  // get the settings for all the entity types
  $field_values = _takepart_signupforms_bundle_field_values();

  foreach ($entity_types as $type => $info) {
    if (isset($field_values[$type])) {
      $form['enabled_bundles'][$type] = array(
        '#title' => $info['label'],
        '#type' => 'checkboxes',
        '#tree' => TRUE,
      );
      $form['enabled_bundles'][$type] += $field_values[$type];
    }
  }

  $form['actions'] = array(
    '#weight' => 100,
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Save settings',
  );

  return $form;
}

function takepart_signupforms_admin_submit($form, &$form_state) {

  $bundles = $form_state['values']['enabled_bundles'];
  foreach ($bundles as $entity_name => $entity_bundles) {
    foreach ($entity_bundles as $bundle_name => $enabled) {
      db_merge('takepart_signupforms_bundles')
        ->key(array(
            'entity_type' => $entity_name,
            'bundle' => $bundle_name,
          ))
        ->insertFields(array(
            'entity_type' => $entity_name,
            'bundle' => $bundle_name,
            'enabled' => ($enabled !== 0) ? 1 : 0,
          ))
        ->updateFields(array(
            'enabled' => ($enabled !== 0) ? 1 : 0,
          ))
        ->execute();
    }
  }

  cache_clear_all('takepart_signupforms:', 'cache', TRUE);

  drupal_set_message(st('Blue State Digital Signup Forms configuration saved.'));
}
