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
  $block_delta = search_api_page_load_multiple();
  if(isset($block_delta['site_search']->id) && is_numeric($block_delta['site_search']->id)) {
    $b_d = $block_delta['site_search']->id;
  } else {
    $b_d = variable_get('search_api_page_block_delta', 3);
  }
  /* Grab the search form */
  $search = module_invoke('search_api_page', 'block_view', $b_d);
  $variables['search'] = drupal_render($search['content']);
}
