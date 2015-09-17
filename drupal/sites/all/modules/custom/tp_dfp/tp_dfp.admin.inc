<?php

/**
 * DFP Admin Settings Form
 */
function tp_dfp_admin_config($form, &$form_state, $form_id){

  //Template Id
  $form['dfp_template_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Network Code'),
    '#default_value' => variable_get('dfp_template_id', '10051895'),
    '#size' => 60,
    '#maxlength' => 128,
  );


  return system_settings_form($form);

}

