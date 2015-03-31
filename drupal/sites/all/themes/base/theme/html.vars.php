<?php


/**
 * Implements hook_html_preprocess()
 */
function base_preprocess_html(&$variables){
  /* Add shared assets to all tp4 pages */
  drupal_add_css(variable_get('shared_assets_path'), array('type' => 'external'));
}