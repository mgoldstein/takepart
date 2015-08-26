<?php

/**
 * Implements hook_preprocess_node();
 */
function base_preprocess_node(&$variables, $hook) {
  // Show an article without the UNPUBLISHED text and pink background if adding &preview=1 to the url
  // Do this by auto-logging in the user as TPpreview
  global $user;
  $ispreview = filter_input(INPUT_GET, 'preview', FILTER_SANITIZE_URL);
  if ($ispreview == 1) {
    drupal_session_start();
    $user = user_load_by_name('tppreview'); // load the tppreview user
    // redirect new user to an uncached version of the same page
    drupal_goto(current_path());
  } else if (isset($ispreview) && $ispreview == 0) {
    $user = user_load(0);
    drupal_goto(current_path());
  }
  if (in_array('preview', $user->roles)) {
    $variables['unpublished'] = false;
    $variables['classes_array'][] = 'node-preview';
  }
  // Run node-type-specific preprocess functions, like
  // base_preprocess_node__page() or base_preprocess_node__story().
  $function = __FUNCTION__ . '__' . $variables['node']->type;
  if (function_exists($function)) {
    $function($variables, $hook);
  }
}
