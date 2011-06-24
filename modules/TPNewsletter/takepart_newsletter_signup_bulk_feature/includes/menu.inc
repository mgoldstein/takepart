<?php 
function takepart_newsletter_signup_bulk_feature_menu() {
  $items['signup_bulk_load/%node'] = array(
    'type' => MENU_NORMAL_ITEM,
	'title' => t('TakePart Newsletter Signup Upload'),
	'description' => t('Upload emails for newsletter signup'),
	'page callback' => 'takepart_newsletter_signup_bulk_feature_populate_queue_page',
	'access arguments' => array('administer newsletter email collector service'),
    'page arguments' => array(1)
  );
  return $items;

}

function takepart_newsletter_signup_bulk_feature_populate_queue_page($node) {
  #takepart_newsletter_signup_bulk_feature_populate_queue($node);
  #takepart_newletter_signup_bulk_feature_preprocess($node);
  #takepart_newsletter_signup_bulk_feature_generate_report($node);
   #takepart_newsletter_signup_bulk_feature_process_items();
  variable_set('takepart_newsletter_signup_bulk_feature_nodes_to_queue', array($node->nid));
 

  drupal_set_message(" Processed");
  return "bob";
  
}
