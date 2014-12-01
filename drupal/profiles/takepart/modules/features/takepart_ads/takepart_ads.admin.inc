<?php
/**
 * @file
 * TakePart DoubleClick Ad support admin.
 */

/**
 * Global settings form.
 */
function takepart_ads_settings_form($form, &$form_state) {

  $form['takepart_ads_dfp_property_code'] = array(
    '#type' => 'textfield',
    '#title' => t('GAM Property Code'),
    '#default_value' => variable_get('takepart_ads_dfp_property_code', ''),
    '#required' => TRUE
  );

  $form['takepart_ads_dfp_property_code_gpt'] = array(
    '#type' => 'textfield',
    '#title' => t('GPT Property Code'),
    '#default_value' => variable_get('takepart_ads_dfp_property_code_gpt', '4355895'),
    '#required' => TRUE
  );
  $form['takepart_ads_dfp_refresh'] = array(
    '#type' => 'textfield',
    '#title' => t('Refresh'),
    '#description' => t('In seconds, how often would you like ads to refresh? (Example: 31)'),
    '#default_value' => variable_get('takepart_ads_dfp_refresh', '30'),
  );

  return system_settings_form($form, $form_state);
}

/**
 * Ad tag edit page title callback.
 */
function takepart_ads_tag_page_title($tag) {
  return $tag->title;
}

/**
 * Ad tag listing page callback.
 */
function takepart_ads_tag_listing_page() {

  $headers = array(
    t('Title'),
    t('Tag'),
    array(
      'data' => t('Operations'),
      'colspan' => 2,
    ),
  );

  $tags = takepart_ads_load_tag_list();
  $rows = array();

  foreach ($tags as $tag) {
    $path = 'admin/config/system/ads/tags/manage/' . $tag->name;
    $rows[] = array(
      $tag->title,
      $tag->url,
      l(t('edit'), $path),
      l(t('delete'), $path . '/delete'),
    );
  }

  return array(
    'table' => array(
      '#theme' => 'table',
      '#header' => $headers,
      '#rows' => $rows,
      '#empty' => t('None.'),
    ),
  );
}

/**
 * Ad tag add/edit form.
 */
function takepart_ads_tag_form($form, &$form_state, $tag) {

  if (is_null($tag)) {
    $tag = takepart_ads_create_tag();
  }
  $form_state['storage']['takepart_ads_tag'] = $tag;

  $values = empty($form_state['values']) ? (array) $tag : $form_state['values'];

  $form['title'] = array(
    '#title' => t('Title'),
    '#description' => t('The human-readable name of the ad tag'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#size' => 60,
    '#default_value' => $values['title'],
  );

  $form['name'] = array(
    '#title' => t('Name'),
    '#description' => t('A unqiue machine-readable name for the ad tag. It must only contain lowercase letters, numbers and underscores.'),
    '#type' => 'machine_name',
    '#maxlength' => 255,
    '#machine_name' => array(
      'exists' => 'takepart_ads_tag_load',
      'source' => array('title'),
    ),
    '#default_value' => $values['name'],
    '#disabled' => !empty($tag->name),
  );

  $form['url'] = array(
    '#title' => t('URL'),
    '#description' => t('The ad tag URL'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#maxlength' => 255,
    '#default_value' => $values['url'],
  );

  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => t('Save tag'),
    ),
  );

  return $form;
}

function takepart_ads_tag_form_validate($form, &$form_state) {
  $tag = $form_state['storage']['takepart_ads_tag'];
  if (empty($tag->id)) {
    $name = $form_state['values']['name'];
    $existing = takepart_ads_load_tag($name);
    if (!is_null($existing)) {
      form_set_error('name', t('A tag with that name already exists.'));
    }
  }
}

/**
 * Ad tag add/edit form submit callback.
 */
function takepart_ads_tag_form_submit($form, &$form_state) {
  $tag = $form_state['storage']['takepart_ads_tag'];

  $action = isset($tag->id) ? 'updated' : 'added';

  $tag->name = $form_state['values']['name'];
  $tag->title = $form_state['values']['title'];
  $tag->url = $form_state['values']['url'];

  takepart_ads_save_tag($tag);

  drupal_set_message(t('The ad tag %label has been !action.', array(
    '%label' => $tag->title,
    '!action' => $action,
  )));

  $form_state['redirect'] = 'admin/config/system/ads/tags';
}

/**
 * Ad tag delete form.
 */
function takepart_ads_tag_delete_form($form, &$form_state, $tag) {
  $form_state['storage']['takepart_ads_tag'] = $tag;
  $question = t('Are you sure you want to delete tag %label?',
    array('%label' => $tag->title)
  );
  return confirm_form($form, $question, 'admin/config/system/ads/tags');
}

/**
 * Ad tag delete form submit callback.
 */
function takepart_ads_tag_delete_form_submit($form, &$form_state) {
  $tag = $form_state['storage']['takepart_ads_tag'];
  takepart_ads_delete_tag($tag);
  drupal_set_message(t('Ad tag %label deleted.', array(
    '%label' => $tag->title
  )));
  $form_state['redirect'] = 'admin/config/system/ads/tags';
}
