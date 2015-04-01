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
  /* Set variables for node--openpublish-article.tpl.php */
//  $variables['author_teaser'] = theme('fresh_author_teaser', array('author' => $user, 'date' => $date));
}