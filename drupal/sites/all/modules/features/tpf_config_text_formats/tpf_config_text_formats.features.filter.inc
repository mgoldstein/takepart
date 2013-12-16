<?php
/**
 * @file
 * tpf_config_text_formats.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function tpf_config_text_formats_filter_default_formats() {
  $formats = array();

  // Exported format: Full HTML.
  $formats['full_html'] = array(
    'format' => 'full_html',
    'name' => 'Full HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'ckeditor_link_filter' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'tab' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'media_filter' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Limited HTML.
  $formats['limited_html'] = array(
    'format' => 'limited_html',
    'name' => 'Limited HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'media_filter' => array(
        'weight' => -50,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_html' => array(
        'weight' => -49,
        'status' => 1,
        'settings' => array(
          'allowed_html' => ' <b><em><strong><i>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'tab' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Full HTML - No WYSIWYG.
  $formats['no_wysiwg_full_html'] = array(
    'format' => 'no_wysiwg_full_html',
    'name' => 'Full HTML - No WYSIWYG',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'media_filter' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
