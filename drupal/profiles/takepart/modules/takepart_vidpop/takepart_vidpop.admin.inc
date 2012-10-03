<?php

/**
 * @file
 * Admin page callbacks for the Cleanup Pathauto module.
 *
 * @ingroup pathauto
 */

/**
 * Form builder; Configure the video popup settings.
 *
 * @ingroup forms
 * @see system_settings_form()
 */
function takepart_vidpop_settings_form($form) {
  $form['takepart_vidpop_ads'] = array(
    '#type'          => 'fieldset',
    '#title'         => t('Ads'),
    '#collapsible'   => TRUE,
    '#collapsed'     => FALSE,
  );
  $form['takepart_vidpop_ads']['takepart_vidpop_ad_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Ad slot ID for vidpop'),
    '#default_value' => variable_get('takepart_vidpop_ad_id', TAKEPART_VIDPOP_DEFAULT_AD_ID),
    '#description' => t('ID of ad to use for vidpop.'),
  );

  $form['takepart_vidpop_map'] = array(
    '#type'          => 'fieldset',
    '#title'         => t('Map settings'),
    '#collapsible'   => TRUE,
    '#collapsed'     => FALSE,
  );
  $form['takepart_vidpop_map']['takepart_vidpop_map_nid'] = array(
    '#type' => 'textfield',
    '#title' => t('Node ID for vidpop map page'),
    '#default_value' => variable_get('takepart_vidpop_map_nid', 27693),
    '#description' => t('Enter the nid of the page containing the map with video popups.'),
  );

  return system_settings_form($form);
}

