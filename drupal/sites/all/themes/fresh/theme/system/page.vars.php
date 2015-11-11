<?php

/**
* Implements hook_preprocess_page
*/
function fresh_preprocess_page(&$variables) {

  drupal_add_js(array(
    'tp_common' => array(
      'breakpoint_phablet' => 480,
    )),
  'setting');


  /* Add special mobile menu when nav is transparent */
  if($variables['node'] && $variables['node']->type == 'feature_article'){

    //Logo
     $variables['page']['left_drawer']['top-section']['#markup'] = '<div class = "left-drawer-control"><span class="icon i-close-x"></span><a href="/" class="logo-feature"></a></div>';

    //Social Icons for mobile
    $mobile_menu = theme('base_social_follow');
    $variables['page']['left_drawer']['social']['#markup'] = '<div class="mobile-menu-header">'. $mobile_menu. '</div>';
    $menu = drupal_render(menu_tree_output(menu_tree_all_data('menu-megamenu')));
    $variables['page']['left_drawer']['menu']['#markup'] = '<div class="mobile-menu">'. $menu. '</div>';

    //Descriptive Text
    $variables['page']['left_drawer']['text']['#markup'] = '<span class = "about">TakePart -- a digital news & lifestyle magazine and social action platform -- is a division of Participant Media, the company behind Pivot Television Network and important films such as An Inconvenient Truth, Waiting for Superman, Food, Inc., and many others.</span>';

    //Social Icons for Destkop - feature article
    $mobile_menu = theme('base_social_follow');
    $variables['page']['left_drawer']['social-desktop']['#markup'] = '<div class="mobile-menu-header feature-destkop"><p class = "follow">FOLLOW US</p>'. $mobile_menu. '</div>';

  }else{
    //Social Icons
    $mobile_menu = theme('base_social_follow');
    $variables['page']['left_drawer']['social']['#markup'] = '<div class="mobile-menu-header">'. $mobile_menu. '</div>';

    //Menu
    $menu = drupal_render(menu_tree_output(menu_tree_all_data('menu-megamenu')));
    $variables['page']['left_drawer']['menu']['#markup'] = '<div class="mobile-menu">'. $menu. '</div>';
  }

  /* Add Transparent Nav to Featured Articles and MegaSlim to all others */
  if($variables['node'] && $variables['node']->type == 'feature_article'){
    $variables['page']['header']['nav']['#markup'] = theme('base_header_transparent', array());
  }else{
    //Header
    $header = theme('base_mobile_header');
    $variables['page']['header']['mobile_menu']['#markup'] = $header;
    //MegaSlim
    if(module_exists('tp_megaslim_menu')){
      $variables['page']['header']['megaslim']['#markup'] = tp_megaslim_menu_load_menu();
    }
  }

  /* Statically add the mobile footer to all pages */
  $footer = theme('fresh_mobile_footer');
  $variables['page']['footer']['footer']['#markup'] = $footer;

  $variables['page']['header']['#prefix'] = theme('html_tag', array(
    'element' => array(
      '#tag' => 'div',
      '#value' => '',
      '#attributes' => array(
        'class' => 'fresh-first-ad',
  ))));
}
