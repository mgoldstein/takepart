<?php

/**
 * Admin settings for FBIA
 */
function tp_fbia_admin_settings_form() {
  $form['tp_fbia_page_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Article Page Id'),
    '#default_value' => variable_get('tp_fbia_page_id', ''),
    '#description' => t('Includes the meta tag to claim your domain.'),
    '#size' => 30,
  );
  $form['tp_fbia_channel_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Channel Title'),
    '#default_value' => variable_get('fb_instant_articles_channel_title', variable_get('site_name', t('Default site name'))),
    '#size' => 60,
  );
  $form['tp_fbia_channel_description'] = array(
    '#type' => 'textfield',
    '#title' => t('Channel Description'),
    '#default_value' => variable_get('tp_fbia_channel_description', variable_get('site_slogan', t('Default site slogan.'))),
    '#size' => 140,
  );
  $form['tp_fbia_number_results_in_feed'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of results to display in the feed.'),
    '#default_value' => variable_get('tp_fbia_number_results_in_feed', 20),
    '#size' => 10,
  );
  $form['tp_fbia_feed_cache_lifetime'] = array(
    '#type' => 'textfield',
    '#title' => t('Disabled. How long to cache the results (in seconds)?'),
    '#default_value' => variable_get('tp_fbia_feed_cache_lifetime', 180),
    '#disabled' => true,
    '#size' => 10,
  );

  for ($ad_ctr = 0; $ad_ctr <4; $ad_ctr++) {
    $ad_settings = variable_get('tp_fbia_ads_config_'.$ad_ctr , '');

    $form['tp_fbia_ads_config_' .$ad_ctr] = array(
      '#tree' => TRUE,
      '#type' => 'fieldset',
      '#title' => t('Configuration for Advertisement '.($ad_ctr+1)),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE
    );
    $form['tp_fbia_ads_config_' .$ad_ctr]['ad_slot'] = array (
      '#type' => 'textfield',
      '#title' => t('Ad Slot'),
      '#description' => t('Such as FBIA_ROS_320x50'),
      '#default_value' => (isset($ad_settings['ad_slot'])  ? $ad_settings['ad_slot'] : ''),
      '#size' => 60,
    );
    $form['tp_fbia_ads_config_' .$ad_ctr]['gpd_id'] = array(
      '#type' => 'textfield',
      '#title' => t('Ad GPD ID'),
      '#description' => t('Such as div-gpt-ad-1459514019072-0'),
      '#default_value' => (isset($ad_settings['gpd_id'])  ? $ad_settings['gpd_id'] : ''),
      '#size' => 60,
    );
    $form['tp_fbia_ads_config_' .$ad_ctr]['ad_width'] = array (
      '#type' => 'textfield',
      '#title' => t('Ad Width'),
      '#default_value' => (isset($ad_settings['ad_width'])  ? $ad_settings['ad_width'] : ''),
      '#size' => 10,
    );
    $form['tp_fbia_ads_config_' .$ad_ctr]['ad_height'] = array (
      '#type' => 'textfield',
      '#title' => t('Ad Height'),
      '#default_value' => (isset($ad_settings['ad_height'])  ? $ad_settings['ad_height'] : ''),
      '#size' => 10,
    );

    $form['tp_fbia_ads_config_' .$ad_ctr]['multiple_ads_check'] = array(
      '#type' => 'checkbox',
      '#title' => t('Allow facebook to re-use this Ad if the article is long enough.'),
      '#description' => t('The op-ad-default class be added to feed when checked.'),
      '#default_value' => (isset($ad_settings['multiple_ads_check'])  ? $ad_settings['multiple_ads_check'] : ''),
    );
  }

  $form = system_settings_form($form);

  return $form;
}
