<?php

/**
* Implements hook_preprocess_page
*/
function fresh_preprocess_page(&$variables) {
  /* Statically add mobile menu on every page */
  $mobile_menu = theme('tp4_support_mobile_menu_header');
  $variables['page']['left_drawer']['social']['#markup'] = '<div class="mobile-menu-header">'. $mobile_menu. '</div>';

  /* Statically add mobile menu */
  $menu = drupal_render(menu_tree_output(menu_tree_all_data('menu-megamenu')));
  $variables['page']['left_drawer']['menu']['#markup'] = '<div class="mobile-menu">'. $menu. '</div>';

}