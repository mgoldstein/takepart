<?php

/**
 * Implements hook_preprocess_page()
 */
function base_preprocess_page(&$variables){
  // jquery.cookie plugin is not being loaded for anonymous users and needs to be for TAP
  drupal_add_library('system', 'jquery.cookie');

  // Add Node-specific page templates
  if (!empty($variables['node'])) {
    $variables['theme_hook_suggestions'][] = 'page__' . $variables['node']->type;
  }
}