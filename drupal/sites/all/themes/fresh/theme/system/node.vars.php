<?php

/**
 * Implements hook_preprocess_node();
 */
function fresh_preprocess_node(&$variables, $hook){
  // Run node-type-specific preprocess functions, like
  // fresh_preprocess_node__page() or fresh_preprocess_node__story().
  $function = __FUNCTION__ . '__' . $variables['node']->type;
  if (function_exists($function)) {
    $function($variables, $hook);
  }
}



/**
 * Article Node Preprocess
 * @see base/theme/node.vars.php
 * Implements hook_preprocess_node__NODE-TYPE()
 */
function fresh_preprocess_node__openpublish_article(&$variables){

  /* Set variables for node--openpublish-article.tpl.php (Full View)*/
  if($variables['view_mode'] == 'full'){

    /* Author */
    $author_vars = array();
    if($authors = field_get_items('node', $variables['node'], 'field_author')){
      $author_vars['author'] =  node_load($authors[0]['nid']);
    }
    $author_vars['published_at'] = $variables['node']->published_at;
    $variables['author_teaser'] = theme('fresh_author_teaser', $author_vars);

    /* Article Navigation */
  }



}