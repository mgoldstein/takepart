<?php

/**
 * Implements hook_preprocess_page()
 */
function base_preprocess_page(&$variables){
  // Add Node-specific page templates
  if (!empty($variables['node'])) {
    $variables['theme_hook_suggestions'][] = 'page__' . $variables['node']->type;
  }
}