<?php

/**
 * Implements hook_preprocess_fresh_header_transparent()
 */
function base_preprocess_base_header_transparent(&$variables) {
  //Set logo
  $logo = l('', '<front>', array('html' => TRUE, 'attributes' => array('class' => array('logo-transparent'))));
  $variables['logo'] = $logo;
  $block_delta = search_api_page_load_multiple();
  if(isset($block_delta['site_search']->id) && is_numeric($block_delta['site_search']->id)) {
    $b_d = $block_delta['site_search']->id;
  } else {
    $b_d = variable_get('search_api_page_block_delta', 3);
  }
  //Set Search
  $search = module_invoke('search_api_page', 'block_view', $b_d);
  $variables['search'] = drupal_render($search['content']);
}
