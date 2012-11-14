<?php

/**
 * @file
 * Admin page callbacks for the Universal Popup module.
 *
 * @ingroup pathauto
 */

/**
 * Form builder; Configure the universal popup settings.
 *
 * @ingroup forms
 * @see system_settings_form()
 */
function unipop_settings_form($form) {
  $types = node_type_get_types();
  $type_names = node_type_get_names();
  // get current values
  $current_values = array();
  $result = db_query("SELECT type, status FROM {unipop_types}");
  foreach ($result as $record) {
    if ($record->status == 1) {
      $current_values[] = $record->type;
    }
  }

  $form['unipop_types'] = array(
    '#type'          => 'fieldset',
    '#title'         => t('Content Types'),
    '#collapsible'   => TRUE,
    '#collapsed'     => FALSE,
  );
  $form['enabled_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Enable universal popup support for the following types'),
    '#description' => t('Unchecking a type that has already been configured will delete all existing popups for that content type.'),
    '#options' => $type_names,
    '#default_value' => $current_values,
    '#states' => array(
      'visible' => array(
        ':input[name="custom_settings"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['unipop_ads'] = array(
    '#type'          => 'fieldset',
    '#title'         => t('Ads'),
    '#collapsible'   => TRUE,
    '#collapsed'     => FALSE,
  );
  $form['unipop_ads']['unipop_ad_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Default ad slot ID for unipop'),
    '#default_value' => variable_get('unipop_ad_id', unipop_DEFAULT_AD_ID),
    '#description' => t('ID of ad to use for unipop.'),
  );
  $form['#submit'][] = 'unipop_settings_form_submit';

  return system_settings_form($form);
}


/***
 * @param $form
 * @param $form_state
 *
 * form submission handler
 */
function unipop_settings_form_submit($form, &$form_state) {
  // Save the enabled types
  form_state_values_clean($form_state);
  foreach ($form_state['values']['enabled_types'] as $key => $val) {
    if ($val !== 0) {
      $val = 1;
    }
   $sql = "REPLACE INTO {unipop_types} SET type=:type, status=:status";
    db_query($sql, array(':type' => $key, ':status' => $val));
  }
}


