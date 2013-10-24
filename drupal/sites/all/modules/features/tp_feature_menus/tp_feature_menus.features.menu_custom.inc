<?php
/**
 * @file
 * tp_feature_menus.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function tp_feature_menus_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-participant-media-footer-me.
  $menus['menu-participant-media-footer-me'] = array(
    'menu_name' => 'menu-participant-media-footer-me',
    'title' => 'Participant Media Footer Menu',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Participant Media Footer Menu');


  return $menus;
}
