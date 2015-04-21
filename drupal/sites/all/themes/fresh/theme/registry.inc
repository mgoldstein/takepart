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
    'fresh_mobile_menu_header' => array(
      'variables' => array(
        'links' => array(),
      ),
    ),
    'fresh_mobile_header' => array(
      'variables' => array(
        'links' => array(),
      ),
    ),
    'fresh_ad' => array(
      'variables' => array(
        'ad_tag' => '',
        'class' => '',
      )
    ),
    'fresh_author_teaser' => array(
      'variables' => array(
        'author' => '',
        'published_at' => ''
      )
    ),
    'fresh_series_navigation' => array(
      'variables' => array(
        'entity' => '',
        'series' => ''
      )
    ),
    'fresh_pull_quote' => array(
      'variables' => array(
        'entity' => '',
      )
    ),
    'fresh_fb_comments' => array(
      'variables' => array(
        'url' => '',
      )
    ),
    'fresh_mobile_footer' => array(
      'variables' => array(
        'title' => '',
        'body' => '',
        'menu' => '',
      )
    ),
  );


  /* Add necessary includes */
  base_hook_theme_complete($hook_theme, $theme, $path . '/theme');
  base_hook_theme_complete($existing, $theme, $path . '/theme');
  return $hook_theme;
}