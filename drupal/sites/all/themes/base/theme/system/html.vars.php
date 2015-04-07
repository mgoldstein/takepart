<?php


/**
 * Implements hook_html_preprocess()
 */
function base_preprocess_html(&$variables){
  /* Add shared assets to all tp4 pages */
  if($shared_assets = variable_get('shared_assets_path')){
    drupal_add_css($shared_assets, array('type' => 'external', 'weight' => -1));
  }
}