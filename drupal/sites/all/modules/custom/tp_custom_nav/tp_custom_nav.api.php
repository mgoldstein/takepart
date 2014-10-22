<?php

/**
 *  Implements hook_tp_preprocess_slim_nav_alter().
 *
 *  @function:
 *    This function alters the variables for the slim nav before it's
 *    passed to the template file
 */
function hook_tp_preprocess_slim_nav_alter(&$vars) {
  //any logic that you would need to adjust the render array before it goes to the tpl
}

/**
 *  Implements hook_tp_nav_process_alter().
 *
 *  @function:
 *    This function alters the variables for the slim nav and is called
 *    after all logic has been performed. This function is called within
 *    the hook_preprocess_page() for tp_custom_nav.module
 */
function hook_tp_nav_process_alter(&$vars) {
  //any logic that you would need to adjust the page data
}