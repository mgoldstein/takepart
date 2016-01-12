<?php

/**
 * Implements hook_preprocess_fresh_header_transparent()
 */
function base_preprocess_base_header_transparent(&$variables) {
  //Set logo
  $logo = l('', '<front>', array('attributes' => array('class' => array('logo-transparent'))));
  $variables['logo'] = $logo;

  //Set Search
  $search = module_invoke('search_api_page', 'block_view', '4');
  $variables['search'] = drupal_render($search['content']);
}
