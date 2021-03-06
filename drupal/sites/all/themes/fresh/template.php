<?php
/**
 * @file
 * Contains the theme's functions to manipulate Drupal's default markup.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728096
 */


/**
 * Include common functions used through out theme.
 */
include_once dirname(__FILE__) . '/theme/common.inc';


/**
 * Implements hook_theme()
 */
function fresh_theme(&$existing, $type, $theme, $path) {
  base_include($theme, 'theme/registry.inc');
  return _fresh_theme($existing, $type, $theme, $path);
}

/**
 * For various hook_alters
 * Keep at end of file
 */
include_once dirname(__FILE__) . '/theme/alter.inc';
