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
 * campaign delete callback
 */
function _newsletter_campaign_delete($campaign) {
  $result = entity_delete('newsletter_campaign', $campaign->ncid);

  if ($result === NULL)
    drupal_set_message("Newsletter Campaign, '$campaign->title' was deleted", "status");
  else
    drupal_set_message("Campaign, '$campaign->title' could not be removed.", "status");
    
  drupal_goto('admin/structure/newsletter-campaign');
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
    '#required' => TRUE, 
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


function _newsletter_campaign_settings() {
  $form = array();

  $form['subscribe_fs'] = array(
    '#type' => 'fieldset',
    '#title' => t('Subscribe Settings'),
  );
  $form['subscribe_fs']['newsletter_campaign_tp_opt_in_code'] = array(
    '#type' => 'textfield',
    '#title' => ('TakePart campaign code'),
    '#description' => t('TakePart campaign code for opting in from the profile or registration pages.'),
    '#size' => 60,
    '#default_value' => 'tpnews1'    
  );
  
  $form['unsubscribe_fs'] = array(
    '#type' => 'fieldset',
    '#title' => t('Unsubscription Settings'),
  );
  $form['unsubscribe_fs']['takepart_newsletter_signup_unsubscribe_confirmation_page'] = array(
    '#type' => 'textfield',
    '#title' => t('Unsubscription confirmation page.'),
    '#description' => t('Page displayed when unsubscribe action is successful.'),
    '#size' => 60,
    '#default_value' => 'newsletter-unsubscribe-confirmation',     
  );
    
  $form['unsubscribe_fs']['takepart_newsletter_signup_unsubscribe_problem_page'] = array(
    '#type' => 'textfield',
    '#title' => t('Unsubscription problem page'),
    '#description' => t('The Pluris system campaign id for unsubscribing from all emails.'),
    '#size' => 60,
    '#default_value' => 'newsletter-unsubscribe-problem',     
  );
  $form['unsubscribe_fs']['newsletter_campaign_unsubscribe_all_campaign_code'] = array(
    '#type' => 'textfield',
    '#title' => ('Unsubscribe-All campaign code'),
    '#description' => t('The campaign code for opting out of all takepart emails.'),
    '#size' => 60,
    '#default_value' => 'alltpnl'
  );  
  
  $form['pluris_fs'] = array(
    '#type' => 'fieldset',
    '#title' => t('Pluris Settings'),
  );
  
  $form['pluris_fs']['takepart_newsletter_signup_pluris_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Pluris signup service URL'),
    '#description' => t('The endpoint for campaign signups'),
    '#size' => 60,
    '#default_value' => 'https://digitalsubscriptions.plurismarketing.com/subscribeRequest.php'    
  );
  
  $form['pluris_fs']['takepart_newsletter_signup_pluris_unsubscribe_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Pluris unsubscribe service URL'),
    '#description' => t('The Pluris service endpoint for unsubscribing.'),
    '#size' => 60,
    '#default_value' => 'https://digitalsubscriptions.plurismarketing.com/unsubscribeAll.php'
  );
  
  $form['pluris_fs']['takepart_newsletter_signup_pluris_requester'] = array(
    '#type' => 'textfield',
    '#title' => t('Pluris requester key'),
    '#description' => t('Requestor code required by the pluris service.'),
    '#size' => 60,
    '#default_value' => 'tp',
  );
  
  
  return system_settings_form($form);
}

