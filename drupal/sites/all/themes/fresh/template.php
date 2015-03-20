<?php
/**
 * @file
 * Contains the theme's functions to manipulate Drupal's default markup.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728096
 */


/**
 * Function implements hook_page_build
 */
function fresh_page_alter(&$page){
  $node = menu_get_object();
  if($node->type == 'openpublish_article'){
    $path = drupal_get_path('theme', 'fresh'). '/css/article.css';
    $page['content']['#attached']['css'][] = $path;
  }
}