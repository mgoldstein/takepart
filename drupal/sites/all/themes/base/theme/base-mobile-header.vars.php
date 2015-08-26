<?php

/**
 * Implements theme_preprocess_fresh_mobile_header()
 */
function base_preprocess_base_mobile_header(&$variables){
  /* Grab the logo */
  global $base_url;
  $path = drupal_get_path('theme', 'base');
  $logo_path = $path. '/images/logo.png';
  $logo = theme('image', array('path' => $logo_path));
  $logo = l($logo, $base_url, array('html' => true, 'attributes' => array('class' => array('logo'))));
  $variables['logo'] = $logo;

  /* Grab the search form */
  $search = module_invoke('search_api_page', 'block_view', '2');
  $variables['search'] = drupal_render($search['content']);
}