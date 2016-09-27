<?php

/**
 * Implements hook_preprocess_html();
 */
function fresh_preprocess_html(&$variables) {
  // Pass the digital data to the HTML template.
  $variables['tp_digital_data'] = isset($variables['page']['tp_digital_data']) ? $variables['page']['tp_digital_data'] : NULL;

  drupal_add_js('//cdn.optimizely.com/js/77413453.js', array(
    'type' => 'external',
    'scope' => 'header',
    'group' => JS_DEFAULT,
    'every_page' => TRUE,
    'weight' => -1,
  ));
}
