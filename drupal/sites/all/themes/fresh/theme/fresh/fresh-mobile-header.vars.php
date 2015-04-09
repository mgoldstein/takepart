<?php

/**
 * Implements theme_preprocess_fresh_mobile_header()
 */
function fresh_preprocess_fresh_mobile_header(&$variables){
  /* Grab the logo */
  $path = drupal_get_path('theme', 'fresh');
  $logo = theme('image', array('path' => $path));

  /* Grab the search form */
  $search = module_invoke('search_api_page', 'block_view', '2');
  $variables['search'] = drupal_render($search['content']);
}