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
  // Exported menu: menu-social-footer-follow.
  $menus['menu-social-footer-follow'] = array(
    'menu_name' => 'menu-social-footer-follow',
    'title' => 'Social Footer Follow',
    'description' => 'Social links in the footer',
  );
  // Exported menu: menu-social-header-follow.
  $menus['menu-social-header-follow'] = array(
    'menu_name' => 'menu-social-header-follow',
    'title' => 'Social Header Follow',
    'description' => 'Global social follow menu for the tp4 theme.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Global social follow menu for the tp4 theme.');
  t('Participant Media Footer Menu');
  t('Social Footer Follow');
  t('Social Header Follow');
  t('Social links in the footer');


  return $menus;
}
