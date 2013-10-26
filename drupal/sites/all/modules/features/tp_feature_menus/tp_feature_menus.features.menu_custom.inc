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

  // Exported menu: menu-corporate-footer.
  $menus['menu-corporate-footer'] = array(
    'menu_name' => 'menu-corporate-footer',
    'title' => 'Corporate Footer',
    'description' => 'Corporate menu at the very bottom of the page.',
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
  t('Corporate Footer');
  t('Corporate menu at the very bottom of the page.');
  t('Global social follow menu for the tp4 theme.');
  t('Social Footer Follow');
  t('Social Header Follow');
  t('Social links in the footer');


  return $menus;
}
