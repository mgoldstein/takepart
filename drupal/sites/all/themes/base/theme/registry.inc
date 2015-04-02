<?php
/**
 * @file
 * registry.inc
 */

/**
 * Stub implementation for hook_theme().
 *
 * @see base_theme()
 * @see hook_theme()
 */
function _base_theme(&$existing, $type, $theme, $path) {
  // Custom theme hooks:
  // Do not define the `path` or `template`.
  $hook_theme = array(
    'base_links' => array(
      'variables' => array(
        'links' => array(),
        'attributes' => array(),
        'heading' => NULL,
      ),
    ),
    'base_topic_box' => array(
      'render element' => 'element'
    )
  );

  // Process custom. This should be used again for any sub-themes.
  base_hook_theme_complete($hook_theme, $theme, $path . '/theme');

  // Process existing registry. Only invoke once from base theme.
  base_hook_theme_complete($existing, $theme, $path . '/theme');

  return $hook_theme;
}

/**
 * Discovers and fills missing elements in the theme registry.
 *
 * Adds the following:
 *  - `includes` `*.vars.php` if variables file is found.
 *  - `includes` `*.func.php` if function file is found.
 *  - `function` if the function for $theme is found.
 *  - `path` if template file is found.
 *  - `template` if template file is found.
 */
function base_hook_theme_complete(&$registry, $theme, $path) {

  $registry = drupal_array_merge_deep(
    $registry,
    base_find_theme_includes($registry, '.vars.php', $path),
    base_find_theme_includes($registry, '.func.php', $path),
    drupal_find_theme_functions($registry, array($theme)),
    drupal_find_theme_templates($registry, '.tpl.php', $path)
  );


  // Post-process the theme registry.
  foreach ($registry as $hook => $info) {
    // Core find functions above does not carry over the base `theme path` when
    // finding suggestions. Add it to prevent notices for `theme` calls.
    if (!isset($info['theme path']) && isset($info['base hook'])) {
      $registry[$hook]['theme path'] = $path;
    }
  }
}


/**
 * Discovers and sets the path to each `THEME-HOOK.$extension` file.
 */
function base_find_theme_includes($registry, $extension, $path) {

  $regex = '/' . str_replace('.', '\.', $extension) . '$/';
  $files = drupal_system_listing($regex, $path, 'name', 0);
  $hook_includes = array();
  foreach ($files as $name => $file) {
    // Chop off the remaining extension.
    if (($pos = strpos($name, '.')) !== FALSE) {
      $name = substr($name, 0, $pos);
    }
    // Transform "-" in filenames to "_" to match theme hook naming scheme.
    $hook = strtr($name, '-', '_');
    if (isset($registry[$hook]) && !isset($registry[$hook]['base hook'])) {
      // Include the file so core can discover any containing functions.
      include_once DRUPAL_ROOT . '/' . $file->uri;
      $hook_includes[$hook]['includes'][] = $file->uri;
    }
  }
  return $hook_includes;

}