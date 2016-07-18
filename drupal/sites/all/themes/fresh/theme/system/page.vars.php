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

  //In Campaign Experience - variables and main nav
  if($campaign_content = field_get_items('node', $variables['node'], 'field_editor_campaign_reference')){
    $camp = node_load($campaign_content[0]['target_id']);

    $variables['page']['campaign_ref'] = TRUE;
    $campaign_info['title'] = $camp -> title;
    $campaign_info['url'] = url('node/'.$camp->nid , array('absolute' => TRUE));

    //Camapaign menu
    if($camp_menu = field_get_items('node', $camp, 'field_campaign_menu')) {
      $camp_menu = $camp_menu[0]['value'];
      $camp_menu = 'menu-' . $camp_menu;
      $camp_menu = drupal_render(menu_tree_output(menu_tree_all_data($camp_menu)));
      $campaign_info['camp_menu'] = $camp_menu;
    }
    //Content Inside Campaign Menu
    if($content_menu = field_get_items('node', $camp, 'field_content_menu')) {
      $content_menu = $content_menu[0]['value'];
      $content_menu = drupal_render(menu_tree_output(menu_tree_all_data($content_menu)));
      $campaign_info['camp_content_menu'] = $content_menu;
    }
    //Campaign menu description
    if ($camp_description =  field_get_items('node', $camp, 'field_content_menu_description')) {
      $camp_description = $camp_description[0]['value'];
      $campaign_info['description'] = $camp_description;
    }
    //Campaign BG color
    if ($camp_color =  field_get_items('node', $camp, 'field_content_promo_bg')) {
      $camp_color = $camp_color[0]['rgb'];
      $campaign_info['color'] = $camp_color;
    }
    //Campaign Logo
    if ($camp_logo =  field_get_items('node', $camp, 'field_content_menu_logo')) {
      $camp_logo = $camp_logo[0]['uri'];
      $camp_logo = file_create_url($camp_logo);
      $campaign_info['logo'] = $camp_logo;
    }
    //Campaign Big Issue Volume
    if ($camp_vol =  field_get_items('node', $camp, 'field_content_issue_volume')) {
      $camp_vol = $camp_vol[0]['value'];
      $campaign_info['vol'] = $camp_vol;
    }
    //Campaign Banner
    if ($camp_banner =  field_get_items('node', $camp, 'field_content_banner_bg')) {
      $camp_banner = $camp_banner[0]['uri'];
      $camp_banner = file_create_url($camp_banner);
      $campaign_info['banner'] = $camp_banner;
    }
    $variables['page']['left_drawer']['#markup'] = theme('base_cic_menu' , array(
      'camp_name'         => isset($campaign_info['title']) ? $campaign_info['title'] : '',
      'camp_url'          => isset($campaign_info['url']) ? $campaign_info['url'] : '',
      'camp_description'  => isset($campaign_info['description']) ? $campaign_info['description'] : '',
      'camp_logo'         => isset($campaign_info['logo']) ? $campaign_info['logo'] : '',
      'camp_menu'         => isset($campaign_info['camp_menu']) ? $campaign_info['camp_menu'] : '',
      'camp_content_menu' => isset($campaign_info['camp_content_menu']) ? $campaign_info['camp_content_menu'] : '',
      'camp_color'        => isset($campaign_info['color']) ? $campaign_info['color'] : '',
      'about_tp'          => $about_tp,
      'social_menu'       => $mobile_menu
    ));

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
  if($variables['node'] && isset($variables['page']['campaign_ref'])) {
    //Content Inside Campaign header
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
