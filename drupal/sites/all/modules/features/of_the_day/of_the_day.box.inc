<?php
/**
 * @file
 * of_the_day.box.inc
 */

/**
 * Implements hook_default_box().
 */
function of_the_day_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'of_the_day';
  $box->plugin_key = 'view';
  $box->title = '... Of the Day';
  $box->description = 'Of the Day Box';
  $box->options = array(
    'view' => 'of_the_day--block',
    'settings' => array(),
    'view_object' => NULL,
    'view_more_text' => '',
    'view_more_link' => '',
    'expose_filters' => 0,
    'additional_classes' => '',
  );
  $export['of_the_day'] = $box;

  return $export;
}
