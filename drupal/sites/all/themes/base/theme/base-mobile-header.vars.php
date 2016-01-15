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
  $block_delta = variable_get('search_api_page_block_delta',2);
  /* Grab the search form */
  $search = module_invoke('search_api_page', 'block_view', $block_delta);
  $variables['search'] = drupal_render($search['content']);
}
