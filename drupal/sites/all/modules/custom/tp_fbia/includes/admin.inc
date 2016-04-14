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
    '#title' => t('How long to cache the results (in seconds)?'),
    '#default_value' => variable_get('tp_fbia_feed_cache_lifetime', 180),
    '#size' => 10,
  );

  $form = system_settings_form($form);

  return $form;
}
