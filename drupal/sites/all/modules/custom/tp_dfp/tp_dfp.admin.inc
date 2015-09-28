<?php

/**
 * DFP Admin Settings Form
 */
function tp_dfp_admin_config($form, &$form_state, $form_id){

  $tp_dfp = variable_get('tp_dfp', array());

  //Template Id
  $form['tp_dfp']['template_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Network Code'),
    '#default_value' => isset($tp_dfp['template_id']) ? $tp_dfp['template_id'] : '10051775',
    '#size' => 60,
    '#maxlength' => 128,
  );

  //Creative Width
  $form['tp_dfp']['creative_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Creative Width'),
    '#default_value' => isset($tp_dfp['creative_width']) ? $tp_dfp['creative_width'] : '152',
    '#size' => 60,
    '#maxlength' => 128,
  );

  //Creative Height
  $form['tp_dfp']['creative_height'] = array(
    '#type' => 'textfield',
    '#title' => t('Creative Height'),
    '#default_value' => isset($tp_dfp['creative_height']) ? $tp_dfp['creative_height'] : '200',
    '#size' => 60,
    '#maxlength' => 128,
  );

  //Destination URL
  $form['tp_dfp']['destination_url'] = array(
    '#type' => 'select',
    '#title' => t('Destination URL'),
    '#default_value' => isset($tp_dfp['destination_url']) ? $tp_dfp['destination_url'] : 'www.takepart.com',
    '#options' => array(
      'dev.takepart.com' => 'dev.takepart.com',
      'qa.takepart.com' => 'qa.takepart.com',
      'stage.takepart.com' => 'stage.takepart.com',
      'www.takepart.com' => 'www.takepart.com'
    ),
  );

  return system_settings_form($form);

}

