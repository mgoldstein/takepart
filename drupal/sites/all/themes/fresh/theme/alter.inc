<?php
/**
 * @file
 * A file to organize all of the theme's hook_alters
 */


/**
 * Implements hook_page_alter
 */
function fresh_page_alter(&$page){
  $node = menu_get_object();
  if($node->type == 'openpublish_article'){
    $path = drupal_get_path('theme', 'fresh');
    $page['content']['#attached']['css'][] = $path.'/css/page-article.css';
  }
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


/**
 * Implements hook_css_alter()
 */
function fresh_css_alter(&$css){

  /* Remove the page-default.css if article.css exists */
  $theme_path = drupal_get_path('theme', 'fresh');
  if(isset($css[$theme_path. '/css/page-article.css'])){
    unset($css[$theme_path. '/css/page-default.css']);
  }

}