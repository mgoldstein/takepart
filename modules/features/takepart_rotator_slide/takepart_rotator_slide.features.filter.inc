<?php
/**
 * @file
 * takepart_rotator_slide.features.filter.inc
 */

/**
 * Implementation of hook_filter_default_formats().
 */
function takepart_rotator_slide_filter_default_formats() {
  $formats = array();

  // Exported format: Limited HTML
  $formats['limited_html'] = array(
    'format' => 'limited_html',
    'name' => 'Limited HTML',
    'cache' => '1',
    'status' => '1',
    'weight' => '0',
    'filters' => array(
      'filter_html' => array(
        'weight' => '-10',
        'status' => '1',
        'settings' => array(
          'allowed_html' => ' <b><em><strong><i>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
    ),
  );

  return $formats;
}
