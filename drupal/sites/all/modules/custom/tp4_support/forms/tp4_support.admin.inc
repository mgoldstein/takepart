<?php

/**
 *  @function:
 *    Custom Admin Support Form
 */
function tp4_support_admin_form($form, &$form_state)  {
  //defines new form array
  $form = array();
  
  //url for json feed
  $form['tp4_support_action_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Action FEED URL'),
    '#description' => t('ACTION URL'),
    '#default_value' => variable_get('tp4_support_action_url', 'http://takeaction.takepart.com/api/actions?all=true')
  );
  
  //cron regen hour
  $form['tp4_support_action_regen_hour'] = array(
    '#type' => 'select',
    '#default_value' => variable_get('tp4_support_action_regen_hour', 'Off'),
    '#title' => t('CRON schedule hour'),
    '#description' => t('Cron will run on the hour it'),
    '#options' => array(
      'Off' => 'Off',
      0 => '12:00 am',
      1 => '1:00 am',
      2 => '2:00 am',
      3 => '3:00 am',
      4 => '4:00 am',
      5 => '5:00 am',
      6 => '6:00 am',
      7 => '7:00 am',
      8 => '8:00 am',
      9 => '9:00 am',
      10 => '10:00 am',
      11 => '11:00 am',
      12 => '12:00 pm',
      13 => '1:00 pm',
      14 => '2:00 pm',
      15 => '3:00 pm',
      16 => '4:00 pm',
      17 => '5:00 pm',
      18 => '6:00 pm',
      19 => '7:00 pm',
      20 => '8:00 pm',
      21 => '9:00 pm',
      22 => '10:00 pm',
      23 => '11:00 pm',        
    )
  );

  //how often to execute cron job
  $form['tp4_support_action_regen_day'] = array(
    '#type' => 'select',
    '#default_value' => variable_get('tp4_support_action_regen_day', 1),
    '#title' => t('CRON schedule hour'),
    '#description' => t('Cron will run by how many days'),
    '#options' => array(
      1 => '1 day',
      2 => '2 days',
      7 => 'Weekly (7 days)'
    )
  );  
  
  //next cron execution
  $form['tp4_support_action_next_exec'] = array(
    '#type' => 'textfield',
    '#title' => t('CRON next exec'),
    '#default_value' => variable_get('tp4_support_action_next_exec', 0),
    '#max_length' => '64',
    '#description' => 'The next scheduled time is <strong>' . variable_get('tp4_support_action_next_exec', 0) . '</strong>.<br/>0 = has not run once yet<br/><br/>',
  );  
  
  //manual
  $form['tp4_support_action_unpublisher'] = array(
    '#type' => 'select',
    '#title' => t('Manual unpublish action content type from feed URL'),
    '#description' => t('Select yes to run the action content type'),
    '#options' => array(
      0 => 'No',
      1 => 'Yes'
    )
  );
  
  $form['#submit'][] = 'tp4_support_admin_form_submit';
  
  return system_settings_form($form);
}

/**
 *  @function:
 *    This form_submit is used to call the batch op
 */
function tp4_support_admin_form_submit(&$form, &$form_state) {
  if ($form_state['values']['tp4_support_action_unpublisher']) {
    _tp4_support_action_batch();
  }
}
