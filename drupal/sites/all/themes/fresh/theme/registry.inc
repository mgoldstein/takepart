<?php
/**
 * @file
 * registry.inc
 *
 * Contains functions specific to the theme registry.
 *
 */

/**
 * Stub implementation for hook_theme().
 *
 * @see fresh_theme()
 * @see hook_theme()
 */
function _fresh_theme(&$existing, $type, $theme, $path) {

  /* Do not define template or path */
  $hook_theme = array(
    'fresh_mobile_menu' => array(
      'variables' => array(
        'links' => array(),
        'attributes' => array(),
        'heading' => NULL,
      ),
    ),
  );


  /* Add necessary includes */
  base_hook_theme_complete($hook_theme, $theme, $path . '/theme');
  base_hook_theme_complete($existing, $theme, $path . '/theme');
  return $hook_theme;
}
