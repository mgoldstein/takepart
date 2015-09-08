<?php

/**
 *  @function:
 *    Takepart oembed admin form
 */
function takepart_oembed_admin_form($form, &$form_state)  {
  $form = array();
  
  //intro message
  $form['takepart_oembed_intro'] = array(
    '#markup' => t("
      Configuration for oembed service for TakePart.<br/>
      Flush cache to clear out all stale cache.<br/><br/>
      Uses: service/oembed/[format=json|xml]?url=[requested-url][&width=[int]|full][&break_cache=true]<br/></br>
      format = json or xml<br/>
      width = full (100%) or int (ratio based on height)<br/>
      break_cache = true to rebuild cache data<br/><br/>
    "),
  );
  
  //service for oembed url
  $form['takepart_oembed_service_url'] = array(
    '#type' => 'textfield',
    '#title' => t('URL Service Path'),
    '#description' => t('URL service. Empty value will disable service for oembed after menu path rebuilds.'),
    '#default_value' => variable_get('takepart_oembed_service_url', 'service/oembed')
  );
  
  //set up cache time
  $form['takepart_oembed_cache_time'] = array(
    '#type' => 'select',
    '#title' => t('Cache Time for oembed service'),
    '#options' => array(
      5 => 5,
      10 => 10,
      15 => 15,
      30 => 30,
      60 => 60
    ),
    '#default_value' => variable_get('takepart_oembed_cache_time', 10)
  );
  
  $form['takepart_oembed_debug_mode'] = array(
    '#title' => t('Debug mode'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('takepart_oembed_debug_mode', 0),
    '#description' => t('Debug mode into watchdog for oembed')
  );
  
  return system_settings_form($form);
}
