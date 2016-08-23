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
  $type = $node -> type;
  $path = drupal_get_path('theme', 'fresh');

  if (in_array($type, array('openpublish_article', 'video', 'video_playlist', 'feature_article', 'fresh_gallery'))) {
    $page['content']['#attached']['css'][] = $path.'/css/fresh.css';
  }

  if (in_array($type, array('fresh_gallery'))) {
    $page['content']['#attached']['js'][] = 'sites/all/libraries/fresh-gallery/gallery.js';
    $page['content']['#attached']['js'][] = $path.'/js/fresh-gallery.js';
  }
}

/**
* Implements hook_js_alter()
*/
function fresh_js_alter(&$javascript){

  /* Update our version of jQuery to 2.x
  jQuery update will not work with other themes. */
  $jquery_path = 'https://ajax.googleapis.com/ajax/libs/jquery/2.1.3/jquery.min.js';
  $javascript['misc/jquery.js']['data'] = $jquery_path;
  $javascript['misc/jquery.js']['type'] = 'external';
  unset($javascript['sites/all/libraries/colorbox/colorbox/jquery.colorbox-min.js']);
  unset($javascript['sites/all/modules/contrib/colorbox/js/colorbox.js']);
  unset($javascript['sites/all/modules/contrib/colorbox/styles/default/colorbox_default_style.js']);
  unset($javascript['sites/all/modules/contrib/colorbox/js/colorbox_load.js']);
  unset($javascript['sites/all/modules/contrib/colorbox/js/colorbox_inline.js']);
  //Needed for this updated version of jquery. It will make sure the correct form.js
  //is used for inline replacements.
  if(!isset($javascript['sites/all/modules/contrib/jquery_update/replace/misc/jquery.form.min.js'])) {
    drupal_add_js(drupal_get_path('module','jquery_update') . '/replace/misc/jquery.form.min.js');
  }

}


/**
 * Implements hook_css_alter()
 */
function fresh_css_alter(&$css){

  /* Remove the page-default.css if article.css exists */
  $theme_path = drupal_get_path('theme', 'fresh');
  if(isset($css[$theme_path. '/css/fresh.css'])){
    unset($css[$theme_path. '/css/page-default.css']);
  }
}
