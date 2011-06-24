<?php


function takepart_newsletter_signup_bulk_feature_theme() {
  $items['takepart_newsletter_signup_bulk_feature_report_mail'] = array(
    'arguments' => array('node' => NULL),
    'template' => 'takepart-newsletter-signup-bulk-feature-report-mail',
    'path' => drupal_get_path('module','takepart_newsletter_signup_bulk_feature') . "/theme",
  );
  return $items;

}

/**
* Implementation of hook_registry_alter
*/
function takepart_newsletter_signup_bulk_feature_theme_registry_alter(&$theme_registry) {

  //— Provide default node template implementations from this module,
  //— but make sure we give a correspodning tpl in a theme folder a chance 
  //— to override us.
  $idx = array_search('modules/node', $theme_registry['node']['theme paths']);

  if ($idx !== False) {
    array_splice( $theme_registry['node']['theme paths'], 
      $idx+1, 0, 
      drupal_get_path('module', 'takepart_newsletter_signup_bulk_feature') . '/theme'
    );
  }
}
