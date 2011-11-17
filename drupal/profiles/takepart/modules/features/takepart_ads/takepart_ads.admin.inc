<?php

/**
 * System settings form to manage ad variables
 */
function takepart_ads_configure_ads() {    
  $form['takepart_ads_dfp_property_code'] = array(
    '#type' => 'textfield',
    '#title' => t('Property Code'),
    '#description' => t('Enter your DFP Propery Code here.'),
    '#default_value' => variable_get('takepart_ads_dfp_property_code', ''),
    '#required' => TRUE
  );
 
  return system_settings_form($form, FALSE);
}