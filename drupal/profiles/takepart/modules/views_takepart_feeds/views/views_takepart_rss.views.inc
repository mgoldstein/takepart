<?php
/**
 * @file
 * Views style plugins for rendering nodes in feed formats.
 *
 */

/**
 * Implements hook_views_plugins().
 */
function views_takepart_rss_views_plugins() {
  $formats = views_takepart_rss_views_formats();
  $additional_themes = array();
  foreach ($formats as $format => $description) {
    $additional_themes['views_views_takepart_rss_style_' . $format] = 'style';
  }

  $path = drupal_get_path('module', 'views_takepart_rss') . '/views';
  return array(
    'module' => 'views_takepart_rss',
    'style' => array(
      'views_takepart_rss_style' => array(
        'title'           => t('TakePart Feed Formats'),
        'path'            => $path . '/plugins',
        'help'            => t('Display a view as a feed such as RSS.'),
        'handler'         => 'views_plugin_style_takepart_rss',
        'theme'           => 'views_views_takepart_rss_style',
        'theme file'      => 'views_views_takepart_rss_style.theme.inc',
        'theme path'      => $path . '/theme',
        'additional themes' => $additional_themes,
        'uses row plugin' => FALSE,
        'uses fields'     => TRUE,
        'uses options'    => TRUE,
        'type'            => 'normal',
        'help_topic'      => 'style-takepart_rss',
        'even empty'      => TRUE,
      ),
    ),
  );
}

/**
 * All recognised feed output formats
 */
function views_takepart_rss_views_formats() {
    return module_invoke_all('views_takepart_rss_formats');
}

/**
 * Implements hook_views_formats().
 */
function views_takepart_rss_views_takepart_rss_formats() { 
   $formats = array(
    'rssimages' => t('TakePart Default RSS'),
  );
  return $formats;
}
