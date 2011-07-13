<?php

/**
 * Add a new campaign callback
 *
 */ 
function _newsletter_campaign_add() {
  $campaign = _newsletter_campaign_default();
  return drupal_get_form('newsletter_campaign_form', $campaign);
}


/**
 * campaign edit callback
 */
function _newsletter_campaign_edit($campaign) {
  drupal_set_title( t("<em>Edit newsletter campaign</em> @title", array('@title' => $campaign->title)), PASS_THROUGH);
  return drupal_get_form('newsletter_campaign_form', $campaign);
}

/**
 * Entity edit form
 *
 */
function newsletter_campaign_form($form, &$form_state, $campaign) {
  $form = array();
  
  if ($campaign->ncid) {
    $form['ncid'] = array(
      '#type' => 'hidden',
      '#default_value' => $campaign->ncid,
    );
  }
  
  $form['tpnc_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#description' => t('The Newsletter Campaign title'),
    '#max_length' => 50,
    '#default_value' => $campaign->title,  
  );
  
  $form['tpnc_header'] = array(
    '#type' => 'textfield',
    '#title' => t('Header'),
    '#description' => t('This text will appear as the header of the block.'),
    '#max_length' => 255,
    '#default_value' => $campaign->header,  
  );
  $form['tpnc_promo_message'] = array(
    '#type' => 'textarea',
    '#title' => t('Promo message'),
    '#description' => t('This text will appear above the email input box.'),
    '#default_value' => $campaign->promo_message,
  );
  $form['tpnc_campaign_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Campaign ID'),
    '#description' => t('Campaign Code generated from the Pluris system.'),
    '#max_length' => 40,
    '#default_value' => $campaign->campaign_id,  
  
  );
  $form['tpnc_thankyou_message'] = array(
    '#type' => 'textarea',
    '#title' => t('Thank you message'),
    '#description' => t('Text to display in signup block after a user has successfully submitted their email.'),
    '#default_value' => $campaign->thankyou_message,  
  );
  
  // attach any fieldable fields, most notable a file field.
  field_attach_form('newsletter_campaign', $campaign, $form, $form_state);
  
  $form['actions'] = array('#type' => 'actions');
  
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#default_value' => t('Save'),
  );
  
  $form['actions']['cancel'] = array(
     '#markup' => l(t('Cancel'), 'admin/structure/newsletter-campaign'),
  );
  
  return $form;
}

/** 
 * form submit handler for campaigin edit form
 */
function newsletter_campaign_form_submit($form, &$form_state) {
  $campaign = _newsletter_campaign_default();
  $update = NULL;
  
  if (!empty($form_state['values']['ncid'])) {
    $update = 'ncid';
    $campaign->ncid = $form_state['values']['ncid'];
  }
  
  $campaign->title            = $form_state['values']['tpnc_title'];
  $campaign->header           = $form_state['values']['tpnc_header'];
  $campaign->promo_message    = $form_state['values']['tpnc_promo_message'];
  $campaign->campaign_id      = $form_state['values']['tpnc_campaign_id'];
  $campaign->thankyou_message = $form_state['values']['tpnc_thankyou_message'];

  field_attach_submit('newsletter_campaign', $campaign, $form, $form_state);
  
  if ($update) {
    drupal_write_record('newsletter_campaign', $campaign, $update);
    field_attach_update('newsletter_campaign', $campaign, $form, $form_state);
  }
  else {
    drupal_write_record('newsletter_campaign', $campaign);
    $update = 'ncid';
    drupal_write_record('newsletter_campaign', $campaign, $update);
    field_attach_insert('newsletter_campaign', $campaign, $form, $form_state);
  }

  drupal_goto('admin/structure/newsletter-campaign');
}

