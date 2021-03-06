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
    'fresh_ad' => array(
      'variables' => array(
        'ad_tag' => '',
        'class' => '',
      )
    ),
    'fresh_author_teaser' => array(
      'variables' => array(
        'authors' => '',
        'published_at' => '',
        'timetoread' => '',
        'nid' => '',
        'type' => ''
      )
    ),
    'fresh_gallery_author_teaser' => array(
      'variables' => array(
        'authors' => '',
        'published_at' => '',
        'timetoread' => '',
        'nid' => ''
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
        'nid' => '',
      )
    ),
    'fresh_sponsor' => array(
      'variables' => array(
        'tid' => '',
      )
    ),
    'fresh_sponsor_disclaimer' => array(
      'variables' => array(
        'tid' => '',
      )
    ),
    'fresh_mobile_footer' => array(
      'variables' => array(
        'title' => '',
        'body' => '',
        'menu' => '',
      )
    ),
    'fresh_featured_link' =>  array(
      'variables' => array(
        'link' => '',
      )
    ),
  );


  /* Add necessary includes */
  base_hook_theme_complete($hook_theme, $theme, $path . '/theme');
  base_hook_theme_complete($existing, $theme, $path . '/theme');
  return $hook_theme;
}
