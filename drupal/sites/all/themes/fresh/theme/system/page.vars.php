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

  //main menu is mega menu by default
  $data_menu = 'menu-megamenu';
  //Social menu
  $mobile_menu = theme('base_social_follow');
  $about_tp = '<span class = "about">TakePart is the digital news and lifestyle magazine from <a href="http://www.participantmedia.com" target="_blank">Participant Media</a>, the company behind such acclaimed documentaries as CITIZENFOUR, An Inconvenient Truth and Food, Inc. and feature films including Lincoln and Spotlight.</span>';

  if (module_exists('tp_social_menu')) {
    //if disable is TRUE then exclude this
    if (!$variables['disable_social']) {
      $variables['page']['page_bottom']['highlight_share']['#markup'] = theme('tp_highlight_share', array());
    }
  }

  //In Campaign Experience - variables and main nav
  if($campaign_content = field_get_items('node', $variables['node'], 'field_editor_campaign_reference')){
    $cid = $campaign_content[0]['target_id'];
    //Grab the campaign info
    module_load_include('module' , 'tp_cic');
    $campaign_info = tp_cic_getCampInfo($cid);
    //Add cic menu if NOT suppressing campaign visuals
    if (!empty($campaign_info)) {
      $variables['page']['campaign_ref'] = TRUE;
      $variables['page']['left_drawer']['#markup'] = theme('base_cic_menu' , array(
        'camp_name'         => isset($campaign_info['title']) ? $campaign_info['title'] : '',
        'camp_url'          => isset($campaign_info['url']) ? $campaign_info['url'] : '',
        'camp_description'  => isset($campaign_info['description']) ? $campaign_info['description'] : '',
        'camp_logo'         => isset($campaign_info['logo']) ? $campaign_info['logo'] : '',
        'camp_dark_logo'    => isset($campaign_info['dark_logo']) ? $campaign_info['dark_logo'] : '',
        'camp_menu'         => isset($campaign_info['camp_menu']) ? $campaign_info['camp_menu'] : '',
        'camp_content_menu' => isset($campaign_info['camp_content_menu']) ? $campaign_info['camp_content_menu'] : '',
        'camp_color'        => isset($campaign_info['color']) ? $campaign_info['color'] : '',
        'about_tp'          => $about_tp,
        'social_menu'       => $mobile_menu
      ));
      //Load the JS file for handling the CIC menu
      drupal_add_js(drupal_get_path('theme', 'base'). '/js/cic-menu.js');
    }
  }
  //Main menu when its NOT the in-campaign-experience
  /* Add special mobile menu when nav is transparent */
  if(!isset($variables['page']['campaign_ref']) && $variables['node'] && $variables['node']->type == 'feature_article'){

    //Logo
     $variables['page']['left_drawer']['top-section']['#markup'] = '<div class = "left-drawer-control"><span class="icon i-close-x"></span><a href="/" class="logo-feature"></a></div>';

    //Social Icons for mobile
    $mobile_menu = theme('base_social_follow');
    $variables['page']['left_drawer']['social']['#markup'] = '<div class="mobile-menu-header">'. $mobile_menu. '</div>';
    $menu = drupal_render(menu_tree_output(menu_tree_all_data($data_menu)));
    $variables['page']['left_drawer']['menu']['#markup'] = '<div class="mobile-menu">'. $menu. '</div>';

    //Descriptive Text
    $variables['page']['left_drawer']['text']['#markup'] = $about_tp;

    //Social Icons for Destkop - feature article
    $mobile_menu = theme('base_social_follow');
    $variables['page']['left_drawer']['social-desktop']['#markup'] = '<div class="mobile-menu-header feature-destkop"><p class = "follow">FOLLOW US</p>'. $mobile_menu. '</div>';

  }else{
    //Social Icons
    $variables['page']['left_drawer']['social']['#markup'] = '<div class="mobile-menu-header">'. $mobile_menu. '</div>';

    //Menu
    $menu = drupal_render(menu_tree_output(menu_tree_all_data($data_menu)));
    $variables['page']['left_drawer']['menu']['#markup'] = '<div class="mobile-menu">'. $menu. '</div>';
  }
  //Header - not included on the content inside campaign nav
  if (!isset($variables['page']['campaign_ref'])) {
    $header = theme('base_mobile_header');
    $variables['page']['header']['mobile_menu']['#markup'] = $header;
  }

  /* Add Transparent Nav to Featured Articles/CIC header and MegaSlim to all others */

  //Content Inside Campaign header
  //If content is tagged with a campaign and supress campaign visual is not checked on the campaign
  if($variables['node'] && isset($variables['page']['campaign_ref']) && !empty($campaign_info)) {

    $variables['page']['header']['nav']['#markup'] = theme('base_header_transparent', array());
    $variables['page']['header']['sticky_cic']['#markup'] = theme('base_sticky_cic_header' , array(
      'camp_bg_color' => isset($campaign_info['color']) ? $campaign_info['color'] : '',
      'camp_logo'     => isset($campaign_info['logo']) ? $campaign_info['logo'] : '',
      'camp_url'      => $campaign_info['url'],
      'camp_vol'      => isset($campaign_info['vol']) ? $campaign_info['vol'] : '',
      'camp_banner'   => isset($campaign_info['banner']) ? $campaign_info['banner'] : ''
    ));
  }
  elseif ($variables['node'] && $variables['node']->type == 'feature_article') {
      $variables['page']['header']['nav']['#markup'] = theme('base_header_transparent', array());
      $variables['page']['header']['nav']['transparent'] = TRUE;
  }
  else{
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
