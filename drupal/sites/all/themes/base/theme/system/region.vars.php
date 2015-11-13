<?php

/**
 * Implements hook_preprocess_region()
 */
function base_preprocess_region(&$variables){

  if($variables['region'] == "header"){
    $node = menu_get_object();
    if ($node && $node->type == 'feature_article') {
      $variables['classes_array'][] = 'transparent';
    }
  }
}