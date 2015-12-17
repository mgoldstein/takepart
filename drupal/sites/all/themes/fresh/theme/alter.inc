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
  if ($type == 'openpublish_article' || $type == 'video' || $type == 'video_playlist' || $type == 'feature_article') {
      $path = drupal_get_path('theme', 'fresh');
      $page['content']['#attached']['css'][] = $path.'/css/fresh.css';
  }


}

/**
* Implements hook_js_alter()
*/
function fresh_js_alter(&$javascript){

  //It will make sure the correct form.js is used for inline replacements.
  //Some nodes will not add this in time just a forced update
  if(!isset($javascript['sites/all/modules/contrib/jquery_update/replace/jquery.form/3/jquery.form.min.js'])) {
    drupal_add_js(drupal_get_path('module','jquery_update'). '/replace/jquery.form/3/jquery.form.min.js');
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
