<?php
/**
 * @file
 * Contains the theme's functions to manipulate Drupal's default markup.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728096
 */


/**
 * Implements hook_page_build
 */
function fresh_page_alter(&$page){
  $node = menu_get_object();
  if($node->type == 'openpublish_article'){
    $path = drupal_get_path('theme', 'fresh'). '/css/article.css';
    $page['content']['#attached']['css'][] = $path;
  }
}


/**
 * Implements hook_preprocess_page
 */
function fresh_preprocess_page(&$variables) {

  /* Statically add mobile menu on every page */
  $mobile_menu = theme('tp4_support_mobile_menu_header');
  $variables['page']['left_drawer']['social']['#markup'] = '<div id="block-tp4-support-tp4-mobile-menu-header">'. $mobile_menu. '</div>';

  /* Statically add mobile menu */
  $menu = drupal_render(menu_tree_output(menu_tree_all_data('menu-megamenu')));
  $variables['page']['left_drawer']['menu']['#markup'] = '<div id="block-menu-menu-megamenu">'. $menu. '</div>';

}