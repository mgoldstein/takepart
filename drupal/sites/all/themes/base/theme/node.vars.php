<?php

/**
 * Implements hook_preprocess_node();
 */
function base_preprocess_node(&$variables, $hook) {
  // Run node-type-specific preprocess functions, like
  // base_preprocess_node__page() or base_preprocess_node__story().
  $function = __FUNCTION__ . '__' . $variables['node']->type;
  if (function_exists($function)) {
    $function($variables, $hook);
  }
}
