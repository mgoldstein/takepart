<?php
/**
 * @file
 * takepart_rotator_slide.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function takepart_rotator_slide_filter_default_formats() {
  $formats = array();

  // Exported format: Limited HTML.
  $formats['limited_html'] = array(
    'format' => 'limited_html',
    'name' => 'Limited HTML',
    'cache' => '1',
    'status' => '1',
    'weight' => '0',
    'filters' => array(
      'media_filter' => array(
        'weight' => '-50',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_html' => array(
        'weight' => '-49',
        'status' => '1',
        'settings' => array(
          'allowed_html' => ' <b><em><strong><i>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'tab' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
