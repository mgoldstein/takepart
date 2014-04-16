<?php
/**
 * @file
 * tpf_content_campaigns.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function tpf_content_campaigns_filter_default_formats() {
  $formats = array();

  // Exported format: Campaign- FULL HTML.
  $formats['campaign_full_html'] = array(
    'format' => 'campaign_full_html',
    'name' => 'Campaign- FULL HTML',
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
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
