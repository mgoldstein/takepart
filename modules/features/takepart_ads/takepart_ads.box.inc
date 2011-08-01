<?php
/**
 * @file
 * takepart_ads.box.inc
 */

/**
 * Implementation of hook_default_box().
 */
function takepart_ads_default_box() {
  $export = array();

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-3981ef30';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Ad - Right Rail Top';
  $box->options = array(
    'body' => array(
      'value' => '<img src="/sites/default/files/tp_pageone_banner320x250_0.jpg">',
      'format' => 'full_html',
    ),
  );
  $export['box-3981ef30'] = $box;

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-f130b806';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Ad - Right Rail Bottom';
  $box->options = array(
    'body' => array(
      'value' => '<img src="/sites/default/files/gardencentre300x600static.gif">',
      'format' => 'full_html',
    ),
  );
  $export['box-f130b806'] = $box;

  return $export;
}
