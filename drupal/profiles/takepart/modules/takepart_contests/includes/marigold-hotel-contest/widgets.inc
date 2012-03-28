<?php
/**
 * Submit your idea email share widget
 */
function _marigold_hotel_contest_emailshare() {
  $modulename = 'takepart_contests';
  drupal_add_css(drupal_get_path('module', $modulename) . '/includes/marigold-hotel-contest/css/widget.css');
  drupal_add_js(drupal_get_path('module', $modulename) . '/includes/marigold-hotel-contest/js/widget.js');
  return  theme('marigold_hotel_email_share_block', array());
}

function _marigold_hotel_contest_emailshare_2() {
  $modulename = 'takepart_contests';
  drupal_add_css(drupal_get_path('module', $modulename) . '/includes/marigold-hotel-contest/css/widget.css');
  drupal_add_js(drupal_get_path('module', $modulename) . '/includes/marigold-hotel-contest/js/widget.js');
  return  theme('marigold_hotel_email_share_block_2', array());
}

function _marigold_hotel_saved_entry() {
  $modulename = 'takepart_contests';
  drupal_add_css(drupal_get_path('module', $modulename) . '/includes/marigold-hotel-contest/css/widget.css');
  drupal_add_js(drupal_get_path('module', $modulename) . '/includes/marigold-hotel-contest/js/widget.js');
  return  theme('marigold_hotel_saved_entry_block', array());
}

function _marigold_hotel_addthis() {
  $modulename = 'takepart_contests';
  drupal_add_library('system','jquery.cookie');
  drupal_add_css(drupal_get_path('module', $modulename) . '/includes/marigold-hotel-contest/css/widget.css');
  drupal_add_js(drupal_get_path('module', $modulename) . '/includes/marigold-hotel-contest/js/widget.js');
  return  theme('marigold_hotel_addthis_block', array());
}