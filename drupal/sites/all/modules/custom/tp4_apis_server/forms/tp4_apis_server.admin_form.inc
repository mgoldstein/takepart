<?php

/**
 *  @function:
 *    This function is used to provide an admin form for module.
 */
function tp4_apis_server_admin_form() {
  //variables
  $form = array();
  $apis = _tp4_apis_server_available_api();

  //description
  $form['markup'] = array(
    '#markup' => t('Flush Drupal Menu Cache to rebuild the URLs after any changes are made')
  );
  
  //cache time
  $form['tp4_api_cache_time'] = array(
    '#title' => t('Cache Time for All API'),
    '#description' => t('Cache Time set for all API below'),
    '#type' => 'select',
    '#options' => array(
      0 => 'Off',
      5 => '5 Minutes',
      30 => 'Half Hour',
      60 => '1 Hour'
    ),
    '#default_value' => variable_get('tp4_api_cache_time', 5)
  );

  //parent url
  $form['tp4_api_parent_url'] = array(
    '#title' => t('Enter Service Parent URL'),
    '#description' => t('Such as api/takepart'),
    '#type' => 'textfield',
    '#default_value' => variable_get('tp4_api_parent_url', 'api/takepart')
  );
  
  //define fieldset
  $form['tp4_api_services'] = array(
    '#type' => 'fieldset',
    '#tree' => TRUE
  );
  
  //returns the api variable so its centralized
  $tp4_api_services = _tp4_apis_get_variable();
  
  //does for each available api that is defined within the module
  foreach ($apis as $key => $value) {
    $variable_value = '';
    
    //gets all the values
    if (isset($tp4_api_services[$key])) {
      $variable_value = $tp4_api_services[$key];
    }
    
    //sets up the wrapper
    $form['tp4_api_services'][$key] = array(
      '#title' => t('Function: @function', array('@function' => $value)),
      '#type' => 'fieldset',
      '#collapsible' => TRUE
    );

    //does for the url
    $form['tp4_api_services'][$key]['function'] = array(
      '#title' => t('Function Name'),
      '#description' => t('Function name for referene'),
      '#type' => 'textfield',
      '#default_value' => $value,
      '#disabled' => TRUE
    );
    
    //does for the url
    $form['tp4_api_services'][$key]['url'] = array(
      '#title' => t('Enter a path to api', array('@function' => $value)),
      '#description' => t('This will be appended after the parent url. Such as /nodes which will be added to api/takepart/nodes'),
      '#type' => 'textfield',
      '#default_value' => (empty($variable_value['url'])) ? '' : $variable_value['url']
    );
    
    //does for the type
    $form['tp4_api_services'][$key]['type'] = array(
      '#title' => t('Select a type'),
      '#description' => t('Select a type such as plain, json, or xml. This will add a header based on the function.'),
      '#type' => 'select',
      '#options' => array(
        'json' => 'json',
        'xml' => 'xml',
        'plain' => 'plain'
      ),
      '#default_value' => (empty($variable_value['type'])) ? 'json' : $variable_value['type']
    );
  }
  
  //returns the system form
  return system_settings_form($form);
}