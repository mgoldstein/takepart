<?php

/**
 * @file
 * Admin page callbacks for the Takepart Universal Popup module.
 *
 * @ingroup pathauto
 */

/**
 * Form builder; Configure the video popup settings.
 *
 * @ingroup forms
 * @see system_settings_form()
 */
function takepart_unipop_settings_form($form) {
  $form['takepart_unipop_ads'] = array(
    '#type'          => 'fieldset',
    '#title'         => t('Ads'),
    '#collapsible'   => TRUE,
    '#collapsed'     => FALSE,
  );
  $form['takepart_unipop_ads']['takepart_unipop_ad_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Ad slot ID for unipop'),
    '#default_value' => variable_get('takepart_unipop_ad_id', TAKEPART_unipop_DEFAULT_AD_ID),
    '#description' => t('ID of ad to use for unipop.'),
  );

  return system_settings_form($form);
}

