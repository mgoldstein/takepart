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