<?php
/**
 * @file
 * Administration settings for TakePart AddThis Module
 */

/**
 * Administration settings form.
 *
 * @return
 *   The completed form definition.
 */
function takepart_addthis_admin_settings() {
  $form = array();
  $form['takepart_addthis_user_settings'] = array(
    '#type'         => 'fieldset',
    '#title'        => t('Account settings'),
    '#collapsible'  => TRUE,
    '#collapsed'    => FALSE,
  );
  $form['takepart_addthis_username'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Username'),
    '#default_value' => variable_get('takepart_addthis_username', 'my-username'),
    '#description'   => t('Your username for <a href="http://www.addthis.com/">addthis.com</a>. Example: my-username'),
  );
  $form['takepart_addthis_pub_id'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Publication ID'),
    '#default_value' => variable_get('takepart_addthis_pub_id', '4e4811b05dc77943'),
    '#description'   => t('The profile id to be used for the site <a href="http://www.addthis.com/">addthis.com</a>.'),
  );
  $form['takepart_addthis_share_settings'] = array(
    '#type'         => 'fieldset',
    '#title'        => t('Share settings'),
    '#collapsible'  => TRUE,
    '#collapsed'    => FALSE,
  );
  $form['takepart_addthis_share_settings']['takepart_addthis_facebook_like_text'] = array(
    '#type'          => 'radios',
    '#title'         => t('Facebook Like Text'),
    '#default_value' => variable_get('takepart_addthis_facebook_like_text', 'Recommend'),
    '#options'       => array('like' => t('Like'), 'recommend' => t('Recommend')),
    '#description'   => t('Text to be used for Facebook Like button'),
  );
  $form['takepart_addthis_share_settings']['takepart_addthis_tweet_via'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Twitter Username for VIA'),
    '#default_value' => variable_get('takepart_addthis_tweet_via', 'takepart'),
    '#description'   => t('This is used as the via @username section of the tweet text'),
  );
  return system_settings_form($form);
}