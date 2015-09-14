<?php
/**
 * @file
 * tpf_display_menus.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function tpf_display_menus_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-corporate-footer.
  $menus['menu-corporate-footer'] = array(
    'menu_name' => 'menu-corporate-footer',
    'title' => 'Corporate Footer',
    'description' => 'Corporate menu at the very bottom of the page.',
  );
  // Exported menu: menu-megamenu.
  $menus['menu-megamenu'] = array(
    'menu_name' => 'menu-megamenu',
    'title' => 'MegaMenu',
    'description' => 'New to the tp4 theme.',
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
  // Exported menu: menu-takepart-links.
  $menus['menu-takepart-links'] = array(
    'menu_name' => 'menu-takepart-links',
    'title' => 'TakePart Footer Links',
    'description' => 'List of TakePart links  - Footer',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Corporate Footer');
  t('Corporate menu at the very bottom of the page.');
  t('Global social follow menu for the tp4 theme.');
  t('List of TakePart links  - Footer');
  t('MegaMenu');
  t('New to the tp4 theme.');
  t('Social Footer Follow');
  t('Social Header Follow');
  t('Social links in the footer');
  t('TakePart Footer Links');


  return $menus;
}
