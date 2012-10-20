<?php

/**
 * @file
 * Admin page callbacks for the TakePart Right Rail Video Popups Support module.
 *
 * @ingroup pathauto
 */

/**
 * Form builder; Configure the video popup settings.
 *
 * @ingroup forms
 * @see system_settings_form()
 */
function takepart_rightrail_popups_settings_form($form) {
  $form['takepart_rightrail_popups_ads'] = array(
    '#type'          => 'fieldset',
    '#title'         => t('Ads'),
    '#collapsible'   => TRUE,
    '#collapsed'     => FALSE,
  );
  $form['takepart_rightrail_popups_ads']['takepart_rightrail_popups_ad_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Ad slot ID for vidpop'),
    '#default_value' => variable_get('takepart_rightrail_popups_ad_id', takepart_rightrail_popups_DEFAULT_AD_ID),
    '#description' => t('ID of ad to use for vidpop.'),
  );

  $form['takepart_rightrail_popups_map'] = array(
    '#type'          => 'fieldset',
    '#title'         => t('Map settings'),
    '#collapsible'   => TRUE,
    '#collapsed'     => FALSE,
  );
  $form['takepart_rightrail_popups_map']['takepart_rightrail_popups_map_nid'] = array(
    '#type' => 'textfield',
    '#title' => t('Node ID for vidpop Rollins map page'),
    '#default_value' => variable_get('takepart_rightrail_popups_map_nid', 27693),
    '#description' => t('Enter the nid of the page containing the map with video popups.'),
  );
  $form['takepart_rightrail_popups_map']['takepart_rightrail_popups_tour_nid'] = array(
    '#type' => 'textfield',
    '#title' => t('Node ID for vidpop Rollins tour page'),
    '#default_value' => variable_get('takepart_rightrail_popups_tour_nid', 27693),
    '#description' => t('Enter the nid of the page containing the tour schedule with video popups.'),
  );

  return system_settings_form($form);
}

