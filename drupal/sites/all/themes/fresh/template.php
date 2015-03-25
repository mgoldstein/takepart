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
  $variables['page']['left_drawer']['social']['#markup'] = '<div class="mobile-menu-header">'. $mobile_menu. '</div>';

  /* Statically add mobile menu */
  $menu = drupal_render(menu_tree_output(menu_tree_all_data('menu-megamenu')));
  $variables['page']['left_drawer']['menu']['#markup'] = '<div class="mobile-menu">'. $menu. '</div>';

}


/**
 * Implements hook_js_alter()
 */
function fresh_js_alter(&$javascript){

  /* Update our version of jQuery to 2.x */
  $jquery_path = 'https://ajax.googleapis.com/ajax/libs/jquery/2.1.3/jquery.min.js';
  $javascript['misc/jquery.js']['data'] = $jquery_path;
  $javascript['misc/jquery.js']['type'] = 'external';
  unset($javascript['sites/all/libraries/colorbox/colorbox/jquery.colorbox-min.js']);
  unset($javascript['sites/all/modules/contrib/colorbox/js/colorbox.js']);
  unset($javascript['sites/all/modules/contrib/colorbox/styles/default/colorbox_default_style.js']);
  unset($javascript['sites/all/modules/contrib/colorbox/js/colorbox_load.js']);
  unset($javascript['sites/all/modules/contrib/colorbox/js/colorbox_inline.js']);

}