<?php

/**
 *  @function:
 *    This function is used to provide an admin form for module.
 */
function tp_mobile_ads_admin_form() {
  //variables
  $form = array();
  $settings = variable_get('tp_ads_settings', '');
  $i = 0;
  $break = FALSE;
  
  //js selector
  $form['tp_ads_settings_selector'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('tp_ads_settings_selector', '.field-name-body br'),
    '#description' => t('Selector for page')
  );
  
  $form['tp_ads_settings'] = array(
    '#tree' => TRUE,
    '#type' => 'fieldset'
  );

  //dynamicly generate the form elements
  do {
    //checks to ensures that the next one is not set
    if (!isset($settings['tp_ads_setting_' . $i]) && empty($settings['tp_ads_setting_' . $i]['ad_slot'])) {
      $break = TRUE;
      //sets each step to empty
      $ad_slot = '';
      $ad_gpd_id = '';
      $ad_width = '';
      $ad_height = '';
      $placement = '';
    }
    else {
      //this is for the dynamic variable values
      $ad_slot = $settings['tp_ads_setting_' . $i]['ad_slot'];
      $ad_gpd_id = $settings['tp_ads_setting_' . $i]['ad_gpd_id'];
      $ad_width = $settings['tp_ads_setting_' . $i]['ad_width'];
      $ad_height = $settings['tp_ads_setting_' . $i]['ad_height'];
      $placement = $settings['tp_ads_setting_' . $i]['placement'];
    }
    
    //each form item
    $form['tp_ads_settings']['tp_ads_setting_' . $i] = array(
      '#type' => 'fieldset',
      '#title' => t('Advertisement - ' . ($i + 1) .  ' - ' . (!empty($ad_slot) ? $ad_slot : $i + 1)),
      '#collapsible' => TRUE,
      '#collapsed' => (!empty($ad_slot)) ? TRUE : FALSE
    );
    
    $form['tp_ads_settings']['tp_ads_setting_' . $i]['ad_slot'] = array(
      '#type' => 'textfield',
      '#title' => t('Ad Slot'),
      '#description' => t('Such as TP_Campaign_300x250_c'),
      '#default_value' => $ad_slot,
    ); 
      
    $form['tp_ads_settings']['tp_ads_setting_' . $i]['ad_gpd_id'] = array(
      '#type' => 'textfield',
      '#title' => t('Ad GPD ID'),
      '#description' => t('Such as div-gpt-ad-1427756284687-0'),
      '#default_value' => $ad_gpd_id,
    ); 

    $form['tp_ads_settings']['tp_ads_setting_' . $i]['ad_width'] = array(
      '#type' => 'textfield',
      '#title' => t('Ad Width'),
      '#description' => t('Such as 300'),
      '#default_value' => $ad_width,
    );
    
    $form['tp_ads_settings']['tp_ads_setting_' . $i]['ad_height'] = array(
      '#type' => 'textfield',
      '#title' => t('Ad Height'),
      '#description' => t('Such as 250'),
      '#default_value' => $ad_height,
    ); 
      
    $form['tp_ads_settings']['tp_ads_setting_' . $i]['placement'] = array(
      '#type' => 'textfield',
      '#title' => t('Placement after paragraph continue from previous ad placement'),
      '#default_value' => $placement,
    );

    $i++;
  } while (!$break);
  
  //adds custom submit handler to unset values that are empty
  $form['#submit'][] = 'tp_mobile_ads_admin_form_submit';
  
  //returns the system form
  return system_settings_form($form);
}

/**
 *  @function:
 *    custom submit handler that it used to unset values before being saved
 */
function tp_mobile_ads_admin_form_submit(&$form, &$form_state) {
  //variables
  $values = $form_state['values']['tp_ads_settings'];
  $values = array_reverse($values);
  
  //does for each value to unset backwards until the last one with data
  foreach ($values as $key => $value) {
    if (empty($value['ad_slot'])) {
      unset($values[$key]);
    }
    elseif(!empty($value['ad_slot'])) {
      break;
    }
  }
  
  //puts it back into the array
  $form_state['values']['tp_ads_settings'] = array_reverse($values);
}