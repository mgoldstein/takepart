<?php

/**
 * @file
 * Contains the theme's functions to manipulate Drupal's default markup.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728096
 */
/**
 * Override or insert variables into the html templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("html" in this case.)
 */

/*
 * Campaign Stuff
 */
if(module_exists('tp_campaigns')){
  module_load_include('inc', 'tp_campaigns', 'campaign_card_preprocesses');
}
$card_types = array(
  'campaign_card_media',
  'campaign_card_iframe',
  'campaign_card_social',
  'campaign_card_news',
  'campaign_card_text',
  'campaign_card_branding',
  'campaign_card_tap',
  'campaign_card_twitter',
  'campaign_card_empty',
  'campaign_card_ad',
  'campaign_card_multi_column',
  'campaign_card_tap_widget'
);
define('CARDTYPES', serialize($card_types));


/**
 * Invokes hook_preprocess_html()
 * @param $variables
 * @param $hook
 */
/**
 * Implements hook_preprocess_html();
 */
function tp4_preprocess_html(&$variables, $hook) {
  /* Add shared assets to all tp4 pages */
  drupal_add_css(variable_get('shared_assets_path').'font.css',           array('type' => 'external'));
  drupal_add_css(variable_get('shared_assets_path').'takepart_icons.css', array('type' => 'external'));

  /* Grab node object if it exists */
  $node = menu_get_object();

  // Pass the digital data to the HTML template.
  $variables['tp_digital_data'] =  isset($variables['page']['tp_digital_data'])
    ? $variables['page']['tp_digital_data'] : NULL;

  // If on an individual node page, add the node type to body classes.
  if ($node) {
    $card_types = unserialize(CARDTYPES);
    if(in_array($node->type, $card_types) == true || $node->type == 'campaign_page'){
      $variables['classes_array'][] = drupal_html_class('campaign-display');
      //Transparent nav body class
      $transnav = field_get_items('node', $node, 'field_transparent_nav');
      if(isset($transnav) && $transnav[0]['value'] == 1) {
        $variables['classes_array'][] = drupal_html_class('campaign-transparent-nav');
        //Transparent nav styling options
        $transnav_style = field_get_items('node', $node, 'field_transparent_nav_style');
        if (isset($transnav_style) && $transnav_style[0]['value'] == 'dark') {
          $variables['classes_array'][] = drupal_html_class('transparent-nav-dark');
        }

      }
    }
  }

    if ($variables['page']['content']['system_main']['#entity_view_mode']['bundle'] == 'topic') {
        $variables['classes_array'][] = 'vocabulary-topic';
    }

    /*drupal_add_js('//cdn.optimizely.com/js/77413453.js', array(
        'type' => 'external',
        'scope' => 'header',
        'group' => JS_DEFAULT,
        'every_page' => TRUE,
        'weight' => -1,
    ));*/

    // add jquery cookie library to tp4 pages
    drupal_add_library('system', 'jquery.cookie', true);

    $uri = filter_input(INPUT_SERVER, 'REQUEST_URI', FILTER_SANITIZE_URL);
    if (preg_match('/^\/entity_iframe/', $uri) ||  preg_match('/^\/iframes/', $uri)) {
        unset($variables['page']['page_bottom']['omniture']);
        unset($variables['page']['page_bottom']['quantcast']);
    }
}

function tp4_js_alter(&$javascript) {

  /* Remove Google Analytics from iframed pages */
  $uri = filter_input(INPUT_SERVER, 'REQUEST_URI', FILTER_SANITIZE_URL);
  if (preg_match('/^\/entity_iframe/', $uri) ) {
    unset($javascript['sites/all/modules/contrib/google_analytics/googleanalytics.js']);
  }

  /* Update our version of jQuery to 2.x */
  $jquery_path = 'https://ajax.googleapis.com/ajax/libs/jquery/1.7.1/jquery.min.js';
  //$jquery_path = 'https://ajax.googleapis.com/ajax/libs/jquery/2.1.3/jquery.min.js';
  $javascript['misc/jquery.js']['data'] = $jquery_path;
  $javascript['misc/jquery.js']['type'] = 'external';
  unset($javascript['sites/all/libraries/colorbox/colorbox/jquery.colorbox-min.js']);
  unset($javascript['sites/all/modules/contrib/colorbox/js/colorbox.js']);
  unset($javascript['sites/all/modules/contrib/colorbox/styles/default/colorbox_default_style.js']);
  unset($javascript['sites/all/modules/contrib/colorbox/js/colorbox_load.js']);
  unset($javascript['sites/all/modules/contrib/colorbox/js/colorbox_inline.js']);

 }

/*
 * Manually sort the order of the meta tags
 * @param $head_elements
 *  An array of meta tags included in the HTML head of the document
 */
function tp4_html_head_alter(&$head_elements) {
    /*
     *  Twitter cards
     */
    $head_elements['metatag_twitter:card']['#weight'] = -900;
    $head_elements['metatag_twitter:site']['#weight'] = -890;
    $head_elements['metatag_twitter:title']['#weight'] = -880;
    $head_elements['metatag_twitter:description']['#weight'] = -870;
    $head_elements['metatag_twitter:url']['#weight'] = -860;
    $head_elements['metatag_twitter:image']['#weight'] = -850;
    /*
     * Open graph
     */
    $head_elements['metatag_fb:app_id']['#weight'] = -800;
    $head_elements['metatag_fb:admins']['#weight'] = -790;
    $head_elements['metatag_og:site_name']['#weight'] = -780;
    $head_elements['metatag_og:title']['#weight'] = -770;
    $head_elements['metatag_og:description']['#weight'] = -760;
    $head_elements['metatag_og:url']['#weight'] = -750;
    $head_elements['metatag_og:type']['#weight'] = -740;
    $head_elements['metatag_og:image']['#weight'] = -730;

	// Truncate descriptions that are too long for FB
	$desc_length = 300;
	$desc = $head_elements['metatag_og:description_0']['#value'];
	if( strlen($desc) > $desc_length ) {
		$desc = substr($desc, 0, $desc_length);
		$head_elements['metatag_og:description_0']['#value'] = preg_replace('/\w+$/', '', $desc).'…';
	}
}

/**
 * TODO: This function should be removed once the tp4_campaign_megamenu starts
 *   using the anchor provided by the menu_attributes module.
 */
function _tp4_campaign_megamenu_attach_fragments(&$link) {
  if (isset($link['#localized_options']['attributes']['rel'])) {
    $link['#localized_options']['fragment'] = $link['#localized_options']['attributes']['rel'];
    unset($link['#localized_options']['attributes']['rel']);
  }
}

function tp4_campaign_megamenu($nid){

  $campaign = node_load($nid);

  /* Parent Menu */
  $menu           = 'menu-'. $campaign->field_campaign_menu['und'][0]['value'];
  $menu_tree      = menu_tree_all_data($menu);
  $menu_tree      = menu_tree_output($menu_tree);

  $menu_elements  = element_children($menu_tree);
  $output       = array();
  foreach($menu_elements as $key => $item){
    $output[]   = $menu_tree[$item];
  }

  // TODO: Use the anchor provided by the menu_attributes module.
  foreach ($output as &$link) {
    _tp4_campaign_megamenu_attach_fragments($link);
    if (isset($link['#below']) == TRUE && $link['#below'] != NULL) {
      $child_elements = element_children($link['#below']);
      foreach ($child_elements as &$link_child) {
        _tp4_campaign_megamenu_attach_fragments($link_child);
      }
    }
  }

  return $output;
}

function tp4_should_show_taboola_widget($variables) {
  // add Taboola JS if we're on an article, feature, photo gallery, or video page
  if (!empty($variables['node'])) {
    $node = $variables['node'];
    if (in_array($node->type, array('openpublish_photo_gallery'))) {
      // but only if we're on the production site
      if (ENVIRONMENT === 'production' || ENVIRONMENT === 'prod') {
        return TRUE;
      }
    }
  }
  return FALSE;
}

/**
 * Override or insert variables into the page templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("page" in this case.)
 */
function tp4_preprocess_page(&$variables) {

  if(isset($variables['node']) && $variables['node']->type != 'campaign_page'){
    /* Statically add the mobile header to all pages */
    $header = theme('base_mobile_header');
    $variables['page']['header']['boxes_ga_mobile_320x50_relative']['#prefix'] = $header;

    /* Statically add the Megaslim Menu to all pages */
    if(module_exists('tp_megaslim_menu')){
      $variables['page']['header']['megaslim']['#markup'] = tp_megaslim_menu_load_menu();
    }
  }

  if(isset($variables['node']) && $variables['node']->type == 'campaign_page'){

    // Make sure the Campaign Page references a Campaign
    if($campaign_ref = field_get_items('node', $variables['node'], 'field_campaign_reference')) {
      $campaign_ref = node_load($campaign_ref[0]['target_id']);
    }else {
      return;
    }

    //Mobile Menu
    $variables['campaign_menu'] = tp4_campaign_megamenu($campaign_ref->nid);

    // Sponsored Content
    if($s = field_get_items('node', $variables['node'], 'field_sponsored')) {
      drupal_add_css('.promoted.sponsor-'.$s[0]['tid'].' {display: none;}', array('type' => 'inline'));
    }
  }

  $variables['skinny'] = render($variables['page']['skinny']);
  $variables['sidebar'] = render($variables['page']['sidebar']);

  // build up a string of classes for the main content div
  $variables['content_classes'] = 'content';
  $variables['content_classes'] .= ($variables['skinny'] ? ' with-skinny' : '');
  $variables['content_classes'] .= ($variables['sidebar'] ? ' with-sidebar' : '');

  // override page titles on certain node templates
  $override_page_title_types = array(
      'openpublish_article',
      'feature_article',
      'openpublish_photo_gallery',
      'video',
      'video_playlist',
      'flashcard',
  );
  if (!empty($variables['node']) && in_array($variables['node']->type, $override_page_title_types)) {
      $variables['title'] = '';
  }

  if (tp4_should_show_taboola_widget($variables)) {
    drupal_add_js(drupal_get_path('theme', 'tp4') . '/js/taboola.js', 'file');
    drupal_add_js('window._taboola = window._taboola || []; _taboola.push({flush:true});', array('type' => 'inline', 'scope' => 'footer'));
  }

  $card_types = unserialize(CARDTYPES);
  if(isset($variables['node']) && in_array($variables['node']->type, $card_types) == true){
    $variables['theme_hook_suggestions'][] = 'page__campaign_page';
    $variables['classes_array'][] = 'card-page';

    $variables['campaign_content_meta'] = array();
    // Create some meta information if the user can edit the node
    if (node_access("update", $variables['node'], $variables['user'])) {
      $variables['campaign_content_meta']['#prefix'] = '<p class="campaign-content-meta">';
      $variables['campaign_content_meta']['#suffix'] = '</p>';

      $variables['campaign_content_meta']['header'] = array(
        '#prefix' => '<strong>',
        '#suffix' => '</strong>',
        '#markup' => 'Campaign Card <small>(' . end(explode('_', $variables['node']->type)) . ')</small>',
      );
      $variables['campaign_content_meta']['node_title'] = array(
        '#prefix' => ' &middot; ',
        '#suffix' => ' &middot; ',
        '#markup' => $variables['node']->title,
      );
      $variables['campaign_content_meta']['edit_link'] = array(
        '#markup' => l('Edit', 'node/' . $variables['node']->nid . '/edit')
      );
    }
  }

  //stuff for the campaign page
  if($variables['node']->type == 'campaign_page'){

    $campaign_ref = $variables['node']->field_campaign_reference['und'][0]['target_id'];
    //campoign Nid
    $cid = $campaign_ref;
    $campaign_ref = node_load($campaign_ref);
    $campaign_menu = 'menu-'. $campaign_ref->field_campaign_menu['und'][0]['value'];
    $menu_tree = menu_tree_all_data($campaign_menu);
    $menu_tree = menu_tree_output($menu_tree);

    $menu_elements = element_children($menu_tree);
    $improved = array();
    foreach($menu_elements as $key => $item){
      $improved[] = $menu_tree[$item];
    }
    $anchor_tags = array();
    foreach($improved as $key => $item){
      if(isset($item['#localized_options']['attributes']['rel']) == true){
        $anchor_tags[] = $item['#localized_options']['attributes']['rel'];
      }
    }

    if (isset($campaign_ref->field_promo_headline['und'][0]['value']) == true) {
      $variables['promo_title'] = $campaign_ref->field_promo_headline['und'][0]['value'];
    } else {
      $variables['promo_title'] = '';
    }
    $variables['anchor_tags'] = $anchor_tags;

    //Is the campaign associated with content menu? (cic)
    $cic_menu  = FALSE;
    if($cic_menu = field_get_items('node', $campaign_ref, 'field_content_menu')) {
      module_load_include('module' , 'tp_cic');
      $campaign_info = tp_cic_getCampInfo($cid);
      $variables['page']['cic_menu'] = TRUE;
    }

    //Transparent nav adding essentials
    $transnav = field_get_items('node', $variables['node'], 'field_transparent_nav');
    $variables['transnav'] = '';
    $variables['drawers'] = '';
    if(isset($transnav) && $transnav[0]['value'] == 1) {
      //Class so we know it is transparent
      $variables['transnav'] = 'transparent';

      //Social Icons for mobile
      $mobile_menu = theme('base_social_follow');
      $about_tp = '<span class = "about">TakePart is the digital news and lifestyle magazine from <a href="http://www.participantmedia.com" target="_blank">Participant Media</a>, the company behind such acclaimed documentaries as CITIZENFOUR, An Inconvenient Truth and Food, Inc. and feature films including Lincoln and Spotlight.</span>';

      //CIC menu
      if ($cic_menu) {
        $variables['page']['trans_left_drawer']['#markup'] = theme('base_cic_menu' , array(
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
      else {
        //Logo
        $variables['page']['trans_left_drawer']['top-section']['#markup'] = '<div class = "left-drawer-control"><span class="icon i-close-x"></span><a href="/" class="logo-feature"></a></div>';
        $variables['page']['trans_left_drawer']['social']['#markup'] = '<div class="mobile-menu-header">'. $mobile_menu. '</div>';
        $menu = drupal_render(menu_tree_output(menu_tree_all_data('menu-megamenu')));
        $variables['page']['trans_left_drawer']['menu']['#markup'] = '<div class="mobile-menu">'. $menu. '</div>';

        //Descriptive Text
        $variables['page']['trans_left_drawer']['text']['#markup'] = $about_tp;

        //Social Icons for Destkop - feature article
        $mobile_menu = theme('base_social_follow');
        $variables['page']['trans_left_drawer']['social-desktop']['#markup'] = '<div class="mobile-menu-header feature-destkop"><p class = "follow">FOLLOW US</p>'. $mobile_menu. '</div>';
      }
      //Bringing in navfat for mobile
      $header = theme('base_mobile_header');
      $variables['page']['header']['mobile_menu']['#markup'] = $header;
      //Adding the mobile draw for transparent nav
      $variables['page']['trans_left_drawer']['tp4_support_tp4_mobile_menu_header'];
      $variables['drawers'] = theme('tp4_support_transparent_nav_drawer', array('vars' => $variables));
    }
    else {
      //Add the left draw for slim nav
      $variables['drawers'] = theme('tp4_support_slim_nav_drawer', array('vars' => $variables));
    }

    /* Check to see if Campaign Menu is toggled off */
    $disable = field_get_items('node', $campaign_ref, 'field_campaign_disable_menu');
    if(empty($disable) || $disable[0]['value'] != 1){

      // Add StickUp.js for the fixed header
      // TODO: stickup isn't necessary
      drupal_add_js(array('tp_campaigns' => array(
        'stickupParts' => (object) $variables['anchor_tags'],
      )), 'setting');
      drupal_add_js(drupal_get_path('theme', 'tp4'). '/js/vendor/stickUp/stickUp.js');

      $header = module_invoke('tp_campaigns', 'block_view', 'tp_campaigns_hero');
      $campaign_menu = theme('html_tag', array(
        'element' => array(
          '#tag' => 'div',
          '#value' => $header['content'],
          '#attributes' => array(
            'class' => 'block',
            'id' => 'block-tp-campaigns-tp-campaigns-hero'
        ))));
      $variables['page']['header']['campaign_header']['#markup'] = $campaign_menu;
    }
  }
  _tp4_on_our_radar_block($variables);
}

/**
 * Override or insert variables into block templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 */
function tp4_preprocess_block(&$variables) {

  $variables['title_attributes_array']['class'][] = 'section-header';

  // add slim nav class to slim nav block
  if ($variables['block']->delta == "tp4_fat_header") {
      $variables['classes_array'][] = "tp4-fat-header";
  }

  if ($variables['block']->delta == "tp4_slim_nav") {
      $variables['classes_array'][] = "slim-nav";
  }

  //ensures that the bean block has a wrapper at the block level
  if ($variables['block']->module == 'bean') {
    $wrapper_label = $variables['elements']['bean'][$variables['block']->delta]['#bundle'];
    $wrapper_label = str_replace('_', '-', $wrapper_label);
    $variables['classes_array'][] = $wrapper_label . '-wrapper';
  }
}

/**
 * Override or insert variables into the template for
 * the "slim-nav" template.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 */

function tp4_preprocess_tp4_support_slim_nav(&$variables) {
  if (isset($variables['user_links']['#links']['user'])){
    $user_menu = $variables['user_links'];
    $user_menu['#attributes'] = array(
      'class' => array(
        'popup'
      ),
    );
    unset($variables['user_links']['#links']['logout']);
    $variables['user_links']['#links']['popup'] = array(
      'title' => render($user_menu),
      'html' => TRUE,
    );
  }
}

/**
 * Override or insert variables into the node templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("node" in this case.)
 */

function tp4_preprocess_node(&$variables, $hook) {
  //only show facebook comments if node is published
  $variables['show_fb_comments'] = ($variables['status']) ? TRUE : FALSE;

  // Add template suggestions for view modes and
  // node types per view view mode.
  $variables['theme_hook_suggestions'][] = 'node__' . $variables['view_mode'];
  $variables['theme_hook_suggestions'][] = 'node__' . $variables['type'] . '__' . $variables['view_mode'];
  if (in_array($variables['type'], array('openpublish_video', 'video', 'video_playlist')) && $variables['view_mode'] == 'full') {
    $variables['theme_hook_suggestions'][] = 'node__openpublish_article__full';
  }

  // Add template variables for the local node url
  // (for compatability in dev/qa environments)
  // and for the url to the same node on production
  // (for facebook plugins and whatnot)
  $variables['url_local'] = url('node/' . $variables['nid'], array('absolute' => TRUE));
  $variables['url_production'] = 'http://www.takepart.com' . url('node/' . $variables['nid']);

  // put the nodetype as a date type on the node object.
  // I'm Matt Wrather and I Approve This Hack.
  $variables['attributes_array']['data-contenttype'] = $variables['type'];

  //address issue with title for photo gallery not showing the titles
  if ($variables['view_mode'] == 'inline_content' && !$variables['title'] && $variables['referencing_field'] == 'field_related_stories') {
    $variables['title'] = $variables['node']->title;
  }

	// Add the PROMOTED tag to nodes employing the feature_secondary display when not on the homepage
  if($variables['view_mode'] == 'feature_secondary') {
	  if( !drupal_is_front_page() ) {
			$variables['node']->field_promo_headline['und'][0]['safe_value'] .= _tp4_support_sponsor_flag($variables['node']);
	  }
	}

  $function = __FUNCTION__ . '__' . $variables['node']->type;
  if (function_exists($function)) {
    $function($variables, $hook);
  }
}

function tp4_preprocess_node__campaign(&$variables, $hook) {
  if(isset($variables['field_campaign_hp'][0]['url']) == true){
    drupal_goto($variables['field_campaign_hp'][0]['url']);
  }
}

function tp4_preprocess_node__campaign_page(&$variables, $hook) {

   $campaign_node = node_load($variables['field_campaign_reference']['und'][0]['target_id']);
  // Check if alt text is empty then add title as alt text for campaign logo
  if($campaign_node->field_campaign_logo['und'][0]['alt'] == ''){
    $campaign_node->field_campaign_logo['und'][0]['alt'] = $campaign_node->title;
  }

  // Check if added images for css alt is empty then add image name as alt text
  $campaign_custom_styling_images = count($campaign_node->field_images_for_css['und']);
  if($campaign_custom_styling_images != 0){

    for($y = 0; $y < $campaign_custom_styling_images; $y++){

      if($campaign_node->field_images_for_css['und'][$y]['alt'] == ''){
        $campaign_node->field_images_for_css['und'][$y]['alt'] = $campaign_node->field_images_for_css['und'][$y]['filename'];
      }

    }
  }

	$s = field_get_items('node', $campaign_node, 'field_sponsored');
	if($s[0]['tid']) {
		drupal_add_css('.promoted.sponsor-'.$s[0]['tid'].' {display: none;}', array('type' => 'inline'));
	}

  // Check if subheadline is empty, if yes get meta description from campaign reference
  if($variables['field_article_subhead']['und'][0]['value'] == ''){

    if($variables['metatags']['und']['description']['value'] == ''){

     $meta_description = array(
            '#type' => 'html_tag',
            '#tag' => 'meta',
            '#attributes' => array(
                'name' => 'description',
                'content' => $campaign_node->field_article_subhead['und'][0]['value']
            )
        );

     drupal_add_html_head( $meta_description, 'meta_description' );

    }

  }

  // Check if campaign reference is not empty
  if($variables['field_campaign_reference']['und'][0]['target_id'] != ''){

    //Get field css
    $uri = $campaign_node->field_css['und'][0]['uri'];

    // If file exist, add the css file to the campaign page
    if (file_exists($uri)){
        drupal_add_css($uri, array('group' => CSS_THEME, 'weight' => 999));
    }

    if($campaign_css_s3 = field_get_items('node', $campaign_node, 'field_s3_css_filename')) {
      $campaign_css_s3_file = $campaign_css_s3[0]['safe_value'];
      if($campaign_css_s3_path = variable_get('campaign_css_s3_path', '')) {
        drupal_add_css($campaign_css_s3_path.$campaign_css_s3_file, array('group' => CSS_THEME, 'weight' => 999, 'type' => 'external'));
      } else {
        watchdog("Campaigns", "S3 css path does not exist. NODE: %node", array('%node' => $campaign_node->nid), WATCHDOG_ERROR);
      }
    }

  }

  //Check if there should be a mute button
  if ($variables['field_mute'][0]['value'] == 1) {
    $variables['classes_array'][] = 'has-mute-button';
  }

  //Check if there is a back-to-top link
  if ($variables['field_campaign_back_to_top'][0]['value'] == 1) {
    $variables['classes_array'][] = 'has-back-to-top';
  }

  //Check if Full Page Scrolling is enabled
  if ($camp_page_scroll = field_get_items('node', $variables['node'], 'field_campaign_page_scrolling')) {
    if ($camp_page_scroll[0]['value']) {
      $variables['classes_array'][] = 'campaign-page-animation';
      drupal_add_js(drupal_get_path('module', 'tp_campaigns').'/js/tp_campaign_animation.js', array('type' => 'file', 'scope' => 'footer'));
    }
  }
  // Check whether facebook comments should be enabled
  foreach (field_get_items('node', $variables['node'], 'field_campaign_facebook_comments') as $item) {
    $variables['show_facebook_comments'] = $item['value'];
  }

  // Clear the Campaign Ad number after page load.
  cache_clear_all('tp_campaign_small_ad_number', 'cache');
  cache_clear_all('tp_campaign_long_ad_number', 'cache');

}


/**
 * Override or insert variables into the campaign card media template
 */
function tp4_preprocess_node__campaign_card_media(&$variables, $hook) {

  //content
  $instructional = tp4_render_field_value('node', $variables['node'], 'field_campaign_instructional');
  if(!empty($instructional)){
    $variables['instructional'] = $instructional;
    $variables['classes_array'][] = 'has-instructional';
  }

  $media_photo = field_get_items('node', $variables['node'], 'field_campaign_media_photo');
  if(empty($media_photo[0]['alt'])){
    $alt = $variables['title'];
  }

  $media_title = tp4_render_field_value('node', $variables['node'], 'field_campaign_media_title');
  if(!empty($media_title)){
    $media_title = '<h4 class="media-title">'. $media_title. '</h4>';
  }


  //Prepare Media
  $media_type = tp4_render_field_value('node', $variables['node'], 'field_campaign_media_type');
  if($media_type == 'Video'){  //Media is a video
    $media = drupal_render(field_view_field('node', $variables['node'], 'field_campaign_media_video', 'embed'));
  }
	elseif ($media_type == 'Video Playlist') {
		//gets the video playlist value
		$video_playlist = field_get_items('node', $variables['node'], 'field_media_video_playlist');

		//checks if its not empty
		if (!empty($video_playlist[0]['target_id'])) {
			//this function lives in tp_video_player.module.
			$media = drupal_render(tp_video_player_list_from_nid($video_playlist[0]['target_id']));
		}
	}elseif ($media_type == 'Video Modal') {

    //Get Modal
    if($media_modal = field_get_items('node', $variables['node'], 'field_campaign_video_modal')) {
      $media_modal = field_view_value('node', $variables['node'], 'field_campaign_video_modal', $media_modal[0]);
      $media = drupal_render($media_modal);
    }
	}

  else{ //Media is a photo

    if($image = field_get_items('node', $variables['node'], 'field_campaign_media_photo')){
      $file = $image[0];
      $mapping = picture_mapping_load('feature_main_image');
      $file['breakpoints'] = picture_get_mapping_breakpoints($mapping);
      $file['attributes'] = array();
      $image = theme('picture', $file);
    }
    //Check if photo has a link
    $image_url = field_get_items('node', $variables['node'], 'field_campaign_media_image_link');
    if(!empty($image_url) && !empty($image)){
      $media = l($image, $image_url[0]['url'], array('html' => true, 'attributes' => array('target' => $image_url[0]['attributes']['target'], 'class' => array('media'))));
    }
    else{
      $media = $image;
    }

  }
  //Grab Description
//  $description = tp4_render_field_value('node', $variables['node'], 'body');
  $description_display = array(
    'label' => 'hidden',
    'type'  => 'text_with_inline_content',
    'settings' => array(
      'source' => 'field_inline_replacements'
    )
  );
  $description = field_view_field('node', $variables['node'], 'body', $description_display);
  $description = drupal_render($description);


  if (!empty($description)) {
    $description = '<div class="description">'. $description. '</div>';
  } else {
    $description = '';
  }
  //Grab Media Caption
  $media_caption = tp4_render_field_value('node', $variables['node'], 'field_campaign_media_caption');
  if(!empty($media_caption)){
    $media_caption = '<div class="caption">'. $media_caption. '</div>';
  }else{
    $media_caption = '';
  }
  //Set Layout
  $column_count = tp4_render_field_value('node', $variables['node'], 'field_campaign_media_col');
  if($column_count == 'Two Column (even width)' || $column_count == 'Two Column (left side wide)' || $column_count == 'Two Column (right side wide)'){  // two column

    // Set the classes
    if($column_count == 'Two Column (left side wide)'){
      $variables['classes_array'][] = 'left-large';
    }
    elseif($column_count == 'Two Column (right side wide)'){
      $variables['classes_array'][] = 'right-large';
    }

    // Set the location of the media element depending on the location set within the CMS
    $content_side = tp4_render_field_value('node', $variables['node'], 'field_campaign_content_side');
    if(!empty($content_side) && $content_side == 'Left Side'){
      //Prepare the left side content
      $left = '';
      $left .= $media_title;
      $left .= $media;
      $left .= $media_caption;

      $right = $description;

    }
    else{  //media goes on the right
      $right = '';
      $right .= $media_title;
      $right .= $media;
      $right .= $media_caption;

      $left = $description;
    }

    $variables['theme_hook_suggestions'][] = 'node__campaign_card_2col';
  }
  elseif($column_count == 0){ //single column
    $center = '';
    $center .= $media_title;
    $center .= $media;
    $center .= $media_caption;
    $center .= $description;

    $variables['theme_hook_suggestions'][] = 'node__campaign_card_1col';
  }

  //background properties
  tp4_campaign_background_rules($variables);

  $variables['center'] = $center;
  if(!empty($center)){
    $variables['center'] = $center;
  }
  if(!empty($left)){
    $variables['left'] = $left;
  }
  if(!empty($right)){
    $variables['right'] = $right;
  }

}

function num_to_letter($num){
  $num -= 1;
  $letter =   chr(($num % 26) + 97);
  $letter .=  (floor($num/26) > 0) ? str_repeat($letter, floor($num/26)) : '';
  return $letter;
}


function _tp4_campaign_ad_block($ad_type){
  $ad_number = &drupal_static(__FUNCTION__);

    $small_ad_number = '';
    $long_ad_number = '';
    $ad_slots = array();
    if($ad_type == '300x250'){
      if($cache = cache_get('tp_campaign_small_ad_number')){
        $small_ad_number = $cache->data + 1;
      }else{
        $small_ad_number = 1;
      }
      $letter = num_to_letter($small_ad_number);
      $block_name = 'ga_campaign_300x250_'. $letter;
      cache_set('tp_campaign_small_ad_number', $small_ad_number, 'cache');

      //Set the Ad Slot
      switch($small_ad_number){
        case 1:
          $ad_slot = "googletag.defineSlot('/4355895/TP_Campaign_300x250_a', [300, 250], 'div-gpt-ad-1401393484136-0').addService(googletag.pubads());";
        break;
        case 2:
          $ad_slot = "googletag.defineSlot('/4355895/TP_Campaign_300x250_b', [300, 250], 'div-gpt-ad-1401406506269-0').addService(googletag.pubads());";
        break;
        case 3:
          $ad_slot = "googletag.defineSlot('/4355895/TP_Campaign_300x250_c', [300, 250], 'div-gpt-ad-1401406531316-0').addService(googletag.pubads());";
        break;
      }
    }else{
      if($cache = cache_get('tp_campaign_long_ad_number')){
        $long_ad_number = $cache->data + 1;
      }else{
        $long_ad_number = 1;
      }

      //Set the Ad Slot
      switch($long_ad_number){
        case 1:
          $ad_slot = "googletag.defineSlot('/4355895/TP_Campaign_728x90_b', [728, 90], 'div-gpt-ad-1401406546626-0').addService(googletag.pubads());";
        break;
        case 2:
          $ad_slot = "googletag.defineSlot('/4355895/TP_Campaign_728x90_c', [728, 90], 'div-gpt-ad-1401406557634-0').addService(googletag.pubads());";
        break;
        case 3:
          $ad_slot = "googletag.defineSlot('/4355895/TP_Campaign_728x90_d', [728, 90], 'div-gpt-ad-1401406568148-0').addService(googletag.pubads());";
        break;
      }

      $letter = num_to_letter($long_ad_number + 1);
      $block_name = 'ga_campaign_728x90_'. $letter;
      cache_set('tp_campaign_long_ad_number', $long_ad_number, 'cache');
    }
    drupal_add_js('googletag.cmd.push(function() {
      '.  $ad_slot.'
      googletag.pubads().enableSingleRequest();
      googletag.enableServices();
      });',
    array('type' => 'inline'));

    cache_set('tp_campaign_ad_slots', $ad_slots, 'cache');
    $ad_block = block_load('boxes', $block_name);
    $ad_block = drupal_render(_block_get_renderable_array(_block_render_blocks(array($ad_block))));

  return $ad_block;
 }



/**
 * Override or insert variables into the campaign card media template
 */
function tp4_preprocess_node__campaign_card_ad(&$variables, $hook) {

  $ad_type = tp4_render_field_value('node', $variables['node'], 'field_campaign_ad_type');
  $ad_block = _tp4_campaign_ad_block($ad_type);

  //Set Layout
  $column_count = tp4_render_field_value('node', $variables['node'], 'field_campaign_media_col');
  if($column_count == 'Two Column (even width)' || $column_count == 'Two Column (left side wide)' || $column_count == 'Two Column (right side wide)'){  // two column

    // Set the classes
    if($column_count == 'Two Column (left side wide)'){
      $variables['classes_array'][] = 'left-large';
    }
    elseif($column_count == 'Two Column (right side wide)'){
      $variables['classes_array'][] = 'right-large';
    }

    // Set the location of the media element depending on the location set within the CMS
    $content_side = tp4_render_field_value('node', $variables['node'], 'field_campaign_content_side');
    if(!empty($content_side) && $content_side == 'Left Side'){
      //ad goes on the left
      $left = '';
      $left = $ad_block;

      $right = '';
      $right = tp4_render_field_value('node', $variables['node'], 'body');

    } else{
      //ad goes on the right
      $right = '';
      $right = $ad_block;

      $left = '';
      $left = tp4_render_field_value('node', $variables['node'], 'body');

    }

    $variables['theme_hook_suggestions'][] = 'node__campaign_card_2col';
  }
  elseif($column_count == 0){ //single column
    $center = '';
    $center = $ad_block;
    $center .= tp4_render_field_value('node', $variables['node'], 'body');

    $variables['theme_hook_suggestions'][] = 'node__campaign_card_1col';
  }

  //background properties
  tp4_campaign_background_rules($variables);

  //content
  $variables['center'] = $center;
  if(!empty($center)){
    $variables['center'] = $center;
  }
  if(!empty($left)){
    $variables['left'] = $left;
  }
  if(!empty($right)){
    $variables['right'] = $right;
  }

}



function tp4_preprocess_node__campaign_card_text(&$variables, $hook) {
  //content
  $instructional = tp4_render_field_value('node', $variables['node'], 'field_campaign_instructional');
  if(!empty($instructional)){
    $variables['instructional'] = $instructional;
    $variables['classes_array'][] = 'has-instructional';
  }

  $column_count = tp4_render_field_value('node', $variables['node'], 'field_campaign_media_col');
  $slim_text = tp4_render_field_value('node', $variables['node'], 'field_slim_card_text');

  //Set Layout
  if($column_count == 'Two Column (even width)' || $column_count == 'Two Column (left side wide)' || $column_count == 'Two Column (right side wide)'){

    // Set the styling layouts
    if($column_count == 'Two Column (left side wide)'){
      $variables['classes_array'][] = 'left-large';
    }
    elseif($column_count == 'Two Column (right side wide)'){
      $variables['classes_array'][] = 'right-large';
    }

    // Return the left and right text columns if they exist
    $left = tp4_render_field_value('node', $variables['node'], 'field_campaign_text_left');
    if(!empty($left)){
      $left = '<div class="text">'. $left. '</div>';
    }
    $right = tp4_render_field_value('node', $variables['node'], 'field_campaign_text_right');
    if(!empty($right)){
      $right = '<div class="text">'. $right. '</div>';
    }

    $variables['theme_hook_suggestions'][] = 'node__campaign_card_2col';
  }

  // Else, if it's a single column use the single column template and $center variable
  elseif($column_count == 'Single Column'){
    $center = tp4_render_field_value('node', $variables['node'], 'field_campaign_text_left');
    if(!empty($center)){
      $center = '<div class="text">'. $center. '</div>';
    }

    $variables['theme_hook_suggestions'][] = 'node__campaign_card_1col';
  }

  // Slim Text card
  if($slim_text == 1){
    $variables['classes_array'][] = 'slim-text';
  $variables['slim_text'] =  'slim-text-card-inner';
  }
  //background properties
  tp4_campaign_background_rules($variables);

  //Parallax field - commented out till we have a better understanding of future products.
  /*$parallax_container = array();
  if ($parallax = $variables['node']->field_campaign_parallax_image['und']) {
    //Editors can upload multiple fields
    foreach ($parallax as $key => $file) {
      $parallax_container[] = 'parallax-' . $key;
      $background = $file['uri'];
      $bg = file_create_url($file['uri']);
      //set background image for tablet and mobile
      $variables['parallax_bg'][$key]['background_image_desktop'] = "background-image: url('$bg');";
      if($bgtablet = image_style_path('large_responsive_tablet', $background)) {
        $bgtablet = file_create_url($bgtablet);
        $variables['parallax_bg'][$key]['background_image_tablet'] = "background-image: url('$bgtablet');";
      } else {
        $variables['parallax_bg'][$key]['background_image_tablet'] = "background-image: url('$bg');";
      }
      if($bgmobile = image_style_path('large_responsive_mobile', $background)) {
        $bgmobile = file_create_url($bgmobile);
        $variables['parallax_bg'][$key]['background_image_mobile'] = "background-image: url('$bgmobile');";
      } else {
        $variables['parallax_bg'][$key]['background_image_mobile'] = "background-image: url('$bg');";
      }
    }
  }*/

  $variables['center'] = $center;
  $variables['left'] = $left;
  $variables['right'] = $right;
  //$variables['parallax'] = $parallax_container;
}


/**
 * Override or insert variables into the campaign card social template
 */
function tp4_preprocess_node__campaign_card_social(&$variables, $hook) {
  //content
  $instructional = tp4_render_field_value('node', $variables['node'], 'field_campaign_instructional');
  if(!empty($instructional)){
    $variables['instructional'] = $instructional;
    $variables['classes_array'][] = 'has-instructional';
  }


  $collections = array();
  $social_follows = field_get_items('node', $variables['node'], 'field_campaign_social_follow');

  //Each social network is a node reference to a field collection
  foreach($social_follows as $key => $collection){
    $collections[] = $collection['value'];
  }
  $collections = entity_load('field_collection_item', $collections);
  $center = '';
  $center .= '<div class=social-follow>';
  foreach($collections as $key => $item){
    //Load the Socail Network Taxonomy Term to get the name
    $tid = field_get_items('field_collection_item', $item, 'field_social_network');
    $tid = $tid[0]['target_id'];
    $taxonomy = entity_load('taxonomy_term', array($tid));
    $taxonomy = current($taxonomy);
    $name = $taxonomy->name;
    $name = strtolower($name);
    $name = preg_replace("/[\s_]/", "-", $name);
    $url = field_get_items('field_collection_item', $item,'field_social_link');
    $url = $url[0]['url'];

    $center .= l('', $url, array('html' => true, 'attributes' => array('target' => '_blank', 'class' => array($name, 'social-icon', 'tp-social-link'))));
  }
  $center .= '</div>';

  // Get the Newsletter block if it exists.  Newsletter block is a custom entity that uses blocks for display
  $newsletter = field_get_items('node', $variables['node'], 'field_campaign_newsletter');
  if(!empty($newsletter)){

    $block_id = $newsletter[0]['target_id'];
    $block = block_load('newsletter_campaign',$block_id);
    $renderable_block =  _block_get_renderable_array(_block_render_blocks(array($block)));
    $center .= drupal_render($renderable_block);
  }
  ;
  if($sms = tp4_render_field_value('node', $variables['node'], 'field_campaign_sms')){
    $center .= '<div class="sms">'. $sms. '</div>';

    //if legal override exists, print it, otherwise print the global copy
    $sms_legal = tp4_render_field_value('node', $variables['node'], 'field_campaign_sms_legal');
    if(empty($sms_legal)){
      $sms_legal = variable_get('sms_legal', '');
    }
    $center .= '<div class="sms-legal">'. $sms_legal. '</div>';
  }

  //background properties
  tp4_campaign_background_rules($variables);

  //content
  $variables['theme_hook_suggestions'][] = 'node__campaign_card_1col';

  $variables['center'] = $center;

}

function tp4_preprocess_node__campaign_card_twitter(&$variables, $hook) {

  if($variables['type'] == "campaign_card_twitter"){

  // Please change the settings based on TakePart application (removed this comment if already changed)
    $consumer_key = "5TGmga1wMRDfMD0gCUIAtI0YG";
    $consumer_secret = "l2ZOmrQlOmnMeTnw7YYvhKrLSzeaaGNn6SPtet4cI2Of2rRyKd";
  // Get username, number of tweets, timeline type, and access tokens from content type
  $username = $variables['field_twitter_username'][0]['value'];
  $number_of_tweets = $variables['field_number_of_tweets'][0]['value'];
  $type = $variables['field_twitter_type'][0]['value'];
  $oauth_access_token = $variables['field_oauth_token'][0]['value'];
  $oauth_access_token_secret = $variables['field_oauth_token_secret'][0]['value'];

  if ( ! class_exists('TwitterOAuth')){
  require('./sites/all/modules/custom/tp_twitter/twitteroauth/twitteroauth.php');
  }

  $connection = new TwitterOAuth($consumer_key, $consumer_secret, $oauth_access_token, $oauth_access_token_secret);

  switch($type){
    case "user_timeline":
    case "mentions_timeline":
    case "home_timeline":
    case "retweets_of_me":
      $twitter_api_url = 'statuses/'.$type;
      $parameters = array('screen_name' => $username, 'count' => $number_of_tweets);
      break;
    case "favorites_list":
      $twitter_api_url = 'favorites/list';
      $parameters = array('screen_name' => $username, 'count' => $number_of_tweets);
      break;
    case "hashtag":
      $twitter_api_url = 'search/tweets';
      $parameters = array('q' => $username, 'count' => $number_of_tweets); //hashtag is in Username field
      break;
    case "list":
      $twitter_api_url = 'lists/statuses';
      $parameters = array('owner_screen_name' => $username,  'slug' => $variables['field_twitter_list_slug'][0]['value'], 'count' => $number_of_tweets);
    break;
  }

  $twitter_data = $connection->get($twitter_api_url, $parameters);

  if($type == 'hashtag'){

    foreach($twitter_data->statuses as $tweets){

        $variables['tweet'][] = $tweets->text;
          $variables['username'][] = '<a href="http://www.twitter.com/'.$tweets->user->screen_name.'" target="_blank">'.$tweets->user->screen_name."</a>";
        $image = str_replace("_normal","",$tweets->user->profile_image_url);
        $variables['profile_pic'][] = $image;
        $variables['entities'][] = $tweets->entities; // Entites contains URL, Hashtag, User, Media
        $variables['created_at'][] = tp4_convert_twitter_time($tweets->created_at);

    }


  }
  else{

    foreach($twitter_data as $tweets){
        $variables['tweet'][] = $tweets->text;
          $variables['username'][] = '<a href="http://www.twitter.com/'.$tweets->user->screen_name.'" target="_blank">'.$tweets->user->screen_name."</a>";
        $image = str_replace("_normal","",$tweets->user->profile_image_url);
        $variables['profile_pic'][] = $image;
        $variables['entities'][] = $tweets->entities; // Entites contains URL, Hashtag, User, Media
        $variables['created_at'][] = tp4_convert_twitter_time($tweets->created_at);
    }

  }
  // Get entities count
    $entities_count = count($variables['entities']);
  for($x=0; $x<$entities_count; $x++){

    // Check if there is URLs in tweet
    if(!empty($variables['entities'][$x]->urls)){

      // Check number of URLs
      $url_count = count($variables['entities'][$x]->urls);

      for($y=0; $y<$url_count; $y++){

        // Check if URL exists in a tweet, if yes, add link tag
        if (strpos($variables['tweet'][$x],$variables['entities'][$x]->urls[$y]->url) !== false) {
             $variables['tweet'][$x] = str_replace($variables['entities'][$x]->urls[$y]->url, '<a href="'.$variables['entities'][$x]->urls[$y]->url.'" target="_blank">'.$variables['entities'][$x]->urls[$y]->display_url.'</a>', $variables['tweet'][$x]);
        }

      }

    } // End URL

    // Check if there is user mention in tweet
    if(!empty($variables['entities'][$x]->user_mentions)){

      // Check number of URLs
      $user_mention_count = count($variables['entities'][$x]->user_mentions);

      for($y=0; $y<$user_mention_count; $y++){

        // Check if user mention exists in a tweet, if yes, add link tag
        if (strpos($variables['tweet'][$x],$variables['entities'][$x]->user_mentions[$y]->screen_name) !== false) {
             $variables['tweet'][$x] = str_replace('@'.$variables['entities'][$x]->user_mentions[$y]->screen_name, '<a href="http://twitter.com/'.$variables['entities'][$x]->user_mentions[$y]->screen_name.'" target="_blank">@'.$variables['entities'][$x]->user_mentions[$y]->screen_name.'</a>', $variables['tweet'][$x]);
        }

      }

    } // End user mention

    // Check if there is hashtag
    if(!empty($variables['entities'][$x]->hashtags)){

      // Check number of URLs
      $hashtags_count = count($variables['entities'][$x]->hashtags);

      for($z=0; $z<$hashtags_count; $z++){

        // Check if hashtag exist in a tweet, if yes, add link tag
        if (strpos($variables['tweet'][$x],$variables['entities'][$x]->hashtags[$z]->text) !== false) {
             $variables['tweet'][$x] = str_replace('#'.$variables['entities'][$x]->hashtags[$z]->text, '<a href="https://twitter.com/search?q=%23'.$variables['entities'][$x]->hashtags[$z]->text.'&src=hash" target="_blank">#'.$variables['entities'][$x]->hashtags[$z]->text.'</a>'." ", $variables['tweet'][$x]);
        }

      }

    } // End hashtag


  }

  //background properties
    tp4_campaign_background_rules($variables);

 }

  $descriptive_text = tp4_render_field_value('node', $variables['node'], 'body');
  $variables['descriptive_text'] = $descriptive_text;
}

//Convert Twitter timestamp
function tp4_convert_twitter_time( $t ) {

  // Set time zone
  date_default_timezone_set('America/Los_Angeles');

  // Get Current Server Time
  $server_time = $_SERVER['REQUEST_TIME'];

  // Convert Twitter Time to UNIX
  $new_tweet_time = strtotime($t);

  // Set Up Output for the Timestamp if over 24 hours
  $this_tweet_day =  date('D. M j, Y', strtotime($t));

  // Subtract Twitter time from current server time
  $time = $server_time - $new_tweet_time;

  // less than an hour, output 'minutes' messaging
  if( $time < 3599) {
    $time = round($time / 60) . ' minutes ago';
  }
  // less than a day but over an hour, output 'hours' messaging
  else if ($time >= 3600 && $time <= 86400) {
    $time = round($time / 3600) . ' hours ago';
  }
  // over a day, output the $tweet_day formatting
  else if ( $time > 86400)  {
    $time = $this_tweet_day;
  }

  return $time;

}

/**
 * Implementation of hook_query_TAG_alter
 * Needed for the OR condition for terms
 */
function tp4_query_termfilter_alter(QueryAlterableInterface $query) {
  $tags = $query->alterMetaData['entity_field_query']->tags;
  $nid = array_slice($tags, 1, 1);
  $node = node_load($nid[0]);

  if($filters = field_get_items('node', $node, 'field_campaign_news_filter_tag')){
    $or = db_or();
    foreach($filters as $item) {

      //Filter can have only one value so this will work
      if($item['entity']->vid == 5){
        $query
          ->leftJoin('field_data_field_topic', 'a', 'node.nid = a.entity_id');
        $or->condition('a.field_topic_tid', array($item['target_id']), 'IN');
      }
      elseif($item['entity']->vid == 3){
        $query
          ->leftJoin('field_data_field_series', 'b', 'node.nid = b.entity_id');
        $or->condition('b.field_series_tid', array($item['target_id']), 'IN');
      }
      elseif($item['entity']->vid == 4){
        $query
          ->leftJoin('field_data_field_free_tag', 'c', 'node.nid = c.entity_id');
        $or->condition('c.field_free_tag_tid', array($item['target_id']), 'IN');
      }
      else{
        $query
          ->leftJoin('field_data_field_admin_tag', 'd', 'node.nid = d.entity_id');
        $or->condition('d.field_admin_tag_tid', array($item['target_id']), 'IN');
      }
    }
    $query->condition($or);
  }

}

/**
 * Implementation of hook_query_TAG_alter
 * Needed for the OR condition for promo content since Actions don't use promos
 */
function tp4_query_promofilter_alter(QueryAlterableInterface $query) {

  $query
    ->leftJoin('field_data_field_thumbnail', 'e', 'node.nid = e.entity_id');
  $query
    ->leftJoin('field_data_field_action_main_image', 'f', 'node.nid = f.entity_id');
  $or = db_or()
    ->condition('e.field_thumbnail_fid', 0, '>')
    ->condition('f.field_action_main_image_fid', 0, '>');
  $query
    ->condition($or);

}


/**
 * Override or insert variables into the campaign card news
 */
function tp4_preprocess_node__campaign_card_news(&$variables, $hook) {

    //content
    $instructional = tp4_render_field_value('node', $variables['node'], 'field_campaign_instructional');
  if(!empty($instructional)){
    $variables['instructional'] = $instructional;
    $variables['classes_array'][] = 'has-instructional';
  }

    // Is this card a single value news card or a multi-value news card?
    $news_type = tp4_render_field_value('node', $variables['node'], 'field_campaign_news_type');
    if($news_type == 'Single Article'){  //single value
      $news_ref = field_get_items('node', $variables['node'], 'field_campaign_single_news_ref');
      $node = node_load($news_ref[0]['target_id']);

      //There is no node do not try to pull values from it.
      if(isset($node) && !empty($node)) {

        //Determine if the referenced content is an action or not
        //Actions have different promotable material
        if($node->type == 'action'){
          $file = field_get_items('node', $node, 'field_action_main_image');
          $file = file_load($file[0]['fid']);

          $action_link = field_get_items('node', $node, 'field_action_url');
          if(!empty($action_link)){
            $link = field_view_value('node', $node, 'field_action_url', $action_link, 'default');
            $link_url = $link['#element'][0]['url'];
            $link_title = $link['#element'][0]['title'];
            $link = l($link_title, $link_url);
          }
          $short_headline = (!empty($action_link) ? $link : '');
          $headline = $node->title;
        }
        //Referenced node is not an Action so we use different fields
        else{
          $file = field_get_items('node', $node, 'field_thumbnail');
          $file = file_load($file[0]['fid']);

          //ensures that this field is set
          if (isset($node->field_article_subhead)) {
            $short_headline = tp4_render_field_value('node', $node, 'field_article_subhead');
          }
          elseif (isset($node->field_subhead)) {
            $short_headline = tp4_render_field_value('node', $node, 'field_subhead');
          }

          $headline = tp4_render_field_value('node', $node, 'field_promo_headline');
        }

        $mapping = picture_mapping_load('campaign_news_image');
        $file->breakpoints = picture_get_mapping_breakpoints($mapping);
        $file->attributes = array();
        $file->alt = (isset($file->alt) == true && $file->alt != NULL ? $file->alt : $node->title);
        $image = theme('picture', (array) $file);

        $center = '';  // single news reference will use one column now
        $path = drupal_get_path_alias('node/'. $node->nid);
        $center .='<div class ="single-news-wrapper">';
        $center .= l($image, $path, array('html' => true));
        $center .= '<h1 class="headline">'. l($headline, $path, array('html' => true)). '</h3>';  //headline
        $center .= '<p class="short-headline">'. $short_headline. '</p>';  //short headline
        $center .= _tp4_support_sponsor_flag($node);
        $center .= '</div>';  //single-news-wrapper
      } else {
        $center ='<div class ="single-news-wrapper">';
        $center .= '</div>';
      }
    }
    else{ //multivalue

      $variables['classes_array'][] = 'multi-news';

      $nids = array();
      $news_ref = field_get_items('node', $variables['node'], 'field_campaign_multi_news_ref');
      foreach($news_ref as $key => $item){
        $nids[] = $item['target_id'];
      }

      // Query non referenced content (max 15)
      $max_count = tp4_render_field_value('node', $variables['node'], 'field_campaign_news_count');
      $count = (!empty($news_ref) ? count($news_ref) : 0);

      if($max_count > $count) {
        $campaignNewsArticles = new EntityFieldQuery();
        $campaignNewsArticles->entityCondition('entity_type', 'node')
          ->entityCondition('bundle', array('openpublish_article', 'feature_article', 'article', 'openpublish_photo_gallery', 'video', 'video_playlist', 'flashcard', 'action'))
          ->propertyCondition('status', 1)
          ->propertyOrderBy('created', 'DESC')
          ->addTag('termfilter')
          ->addTag($variables['nid'])
          ->addTag('promofilter')
          ->range(0, $max_count - $count);

        //only add condition if nids is not empty
        if (!empty($nids)) {
          $campaignNewsArticles->entityCondition('entity_id', $nids, 'NOT IN');
        }

        $articles = $campaignNewsArticles->execute();
      }
      foreach($articles['node'] as $key => $item){
        $nids[] = $item->nid;
      }

      $nodes = node_load_multiple($nids);
      $center = '';
      $center .= '<div class="news-column-wrapper">';
      foreach($nodes as $key => $node){
        //Render different news promo content if item is an Action
        if($node->type == 'action'){
          $file = field_get_items('node', $node, 'field_action_main_image');
          $file = file_load($file[0]['fid']);
          $headline = tp4_render_field_value('node', $node, 'field_tab_call_to_action');
        }
        else{
          $file = field_get_items('node', $node, 'field_thumbnail');
          $file = file_load($file[0]['fid']);
          $headline = tp4_render_field_value('node', $node, 'field_promo_headline');
        }

        $headline .= _tp4_support_sponsor_flag($node);

        $mapping = picture_mapping_load('campaign_news_image');
        $file->breakpoints = picture_get_mapping_breakpoints($mapping);
        $file->attributes = array();
        $file->alt = (isset($file->alt) == true && $file->alt != NULL ? $file->alt : $node->title);
        $media = theme('picture', (array) $file);
        $news_column = $media;
        $news_column .= '<h4>'. $headline. '</h4>';

        $uri = entity_uri('node', $node);
        $uri['options'] += array(
          'html' => true,
          'attributes' => array(
            'class' => array('news-column')
          ),
        );

        $center .= l($news_column, $uri['path'], $uri['options']);
      }
      $center .= '</div>';
    }
    $more = tp4_render_field_value('node', $variables['node'], 'field_campaign_more_link');
    $more = '<div class="more-link">'. $more. '</div>';
    $center .= $more;

    //background properties
    tp4_campaign_background_rules($variables);

  //content
  $variables['theme_hook_suggestions'][] = 'node__campaign_card_1col';
  $variables['center'] = $center;


}

function tp4_preprocess_node__campaign_card_iframe(&$variables, $hook) {
  //content
  $instructional = tp4_render_field_value('node', $variables['node'], 'field_campaign_instructional');
  if(!empty($instructional)){
    $variables['instructional'] = $instructional;
    $variables['classes_array'][] = 'has-instructional';
  }

  //Full Width card
  if ($variables['field_campaign_iframe_full_width']['und'][0]['value']) {
    $variables['classes_array'][] = 'full-width-iframe';
  }

  $center = '';
  $height = tp4_render_field_value('node', $variables['node'], 'field_campaign_iframe_height');
  $width = tp4_render_field_value('node', $variables['node'], 'field_campaign_iframe_width');
  $iframe = tp4_render_field_value('node', $variables['node'], 'field_campaign_iframe');
  if(!empty($iframe)){
    $iframe_type = tp4_render_field_value('node', $variables['node'], 'field_campaign_iframe_type');
    //if the iframe is not fixed add a padding hack to make it responsive
    if($iframe_type == 'Responsive (100%)'){
      $ratio = $height/$width * 100;
      $center .= '<div class="iframe-wrapper" style="padding-bottom: '. $ratio. '%;">';
      $center .= '<iframe src="'. $iframe. '"></iframe>';
      $center .= '</div>';
    }
    //if it is marked 'fixed' make the iframe unresponsive
    else{
      $variables['classes_array'][] = 'iframe-fixed';
      $center .= '<div class="iframe-wrapper-fixed">';
      $center .= '<iframe src="'. $iframe. '" height="'. $height. '" width="'. $width. '"></iframe>';
      $center .= '</div>';
    }
  }
  // if it's not an iframe, it is an embed field. used for items like the pivot channel finder
  else{
    $variables['classes_array'][] = 'embed-field';
    $body = tp4_render_field_value('node', $variables['node'], 'body');
    $center .= '<div class="embed">'. $body. '</div>';
  }

  //background properties
  tp4_campaign_background_rules($variables);

  //content
  $variables['theme_hook_suggestions'][] = 'node__campaign_card_1col';
  $variables['center'] = $center;

}

function tp4_preprocess_node__campaign_card_branding(&$variables, $hook) {
  $center = '';

  //Load the referenced taxonomy term (Campaign Categories)
  $tid = field_get_items('node', $variables['node'], 'field_campaign_branding_category');
  $tid = $tid[0]['tid'];
  $campaign_category = taxonomy_term_load($tid);

  $image = field_get_items('taxonomy_term', $campaign_category, 'field_campaign_category_image');

  if(!empty($image)){
    $file = $image[0];
    $mapping = picture_mapping_load('large');
    $file['breakpoints'] = picture_get_mapping_breakpoints($mapping);
    $file['attributes'] = array();
    $image = theme('picture', $file);

    $branding_text = tp4_render_field_value('taxonomy_term', $campaign_category, 'field_campaign_category_text');
    $center .= '<div class="branding-content">';
    if(!empty($branding_text)){
      $center .= '<div class="branding-text">'. $branding_text. '</div>';
    }
    $branding_url = field_get_items('taxonomy_term', $campaign_category, 'field_campaign_branding_url');

    if(!empty($branding_url)){
      $url = $branding_url[0]['url'];
      $target = $branding_url[0]['attributes']['target'];
      $center .= l($image, $url, array('html' => true, 'attributes' => array('target' => $target)));
    }
    else{
      $center .= $image;
    }
    $center .= '</div>';

  }

  //background properties
  tp4_campaign_background_rules($variables);

  //content
  $variables['theme_hook_suggestions'][] = 'node__campaign_card_1col';
  $variables['center'] = $center;

}
function tp4_preprocess_node__campaign_card_empty(&$variables, $hook) {
  $file = $variables['field_campaign_background'][LANGUAGE_NONE][0];
  $mapping = picture_mapping_load('feature_main_image');
  $file['breakpoints'] = picture_get_mapping_breakpoints($mapping);
  $file['attributes'] = array();
  $center = theme('picture', $file);

  //background properties
  tp4_campaign_background_rules($variables);

  //content
  $variables['theme_hook_suggestions'][] = 'node__campaign_card_1col';
  $variables['center'] = $center;

}

function tp4_preprocess_node__campaign_card_multi_column(&$variables, $hook) {
  //content
  $instructional = tp4_render_field_value('node', $variables['node'], 'field_campaign_instructional');
  if(!empty($instructional)){
    $variables['instructional'] = $instructional;
    $variables['classes_array'][] = 'has-instructional';
  }

  $multi_grid = field_get_items('node', $variables['node'], 'field_campaign_multigrid_item');
  $item_width = tp4_render_field_value('node', $variables['node'], 'field_campaign_multi_item_width');
  if(empty($item_width)){
      $item_width = 200;
  }

  $items = array();
  foreach($multi_grid as $key=> $item){
    $items[] = $item['value'];
  }
  $field_collections = entity_load('field_collection_item', $items);
  $center = '';
  $center .= '<div class="center-inner">';
  foreach($field_collections as $key => $collection){
    $file = $collection->field_promo_thumbnail[LANGUAGE_NONE][0];
    $mapping = picture_mapping_load('large');
    $file['breakpoints'] = picture_get_mapping_breakpoints($mapping);
    $file['attributes'] = array();
    $image = theme('picture', $file);
    $text = tp4_render_field_value('field_collection_item', $collection, 'field_promo_text');
    $link = field_get_items('field_collection_item', $collection, 'field_campaign_multigrid_link');
    $target = (isset($link[0]['attributes']['target']) ? $link[0]['attributes']['target'] : '_self');
    if(!empty($link)){
        $image = l($image, $link[0]['display_url'], array('html' => true, 'attributes' => array('target' => $target)));
    }
    $center .= '<div class="item" style="max-width:'. $item_width. 'px;">';

    //conditional check to ensure there's an image before appending
    if (!empty($collection->field_promo_thumbnail)) {
      $center .= $image;
    }
    $center .= (!empty($text) ? $text : '');
    $center .= '</div>';
  }
  $center .= '</div>';
  //background properties
  tp4_campaign_background_rules($variables);

  //content
  $variables['theme_hook_suggestions'][] = 'node__campaign_card_1col';
  $variables['center'] = $center;
}

function tp4_preprocess_node__campaign_card_tap_widget(&$variables, $hook) {
  if(module_exists('tp_campaigns')){

    $instructional = tp4_render_field_value('node', $variables['node'], 'field_campaign_instructional');
    if(!empty($instructional)){
      $variables['instructional'] = $instructional;
      $variables['classes_array'][] = 'has-instructional';
    }

    $variables['card_content'] = tp_campaigns_card_content_tap_widget($variables);
    tp_campaigns_card_background($variables);
    $variables['theme_hook_suggestions'][] = 'node__campaign_card';
  }
}

/* Remove this function when all other Card Types transition to it */
function tp4_campaign_background_rules(&$variables){

  $variables['styles'] = array();
  if($card_style = field_get_items('node', $variables['node'], 'field_campaign_style_setting')){
    $variables['classes_array'][] = $card_style[0]['value'];
  }
  if($background_color = field_get_items('node', $variables['node'], 'field_campaign_bg_color')){
    $variables['styles'][] = 'background-color: '. $background_color[0]['rgb']. ';';
  }
  if($min_height = tp4_render_field_value('node', $variables['node'], 'field_campaign_min_height')){
    $variables['styles'][] = 'min-height: '. $min_height. 'px;';
  }
  $background_width = tp4_render_field_value('node', $variables['node'], 'field_campaign_bgw');
  if($background_width == 'Full Width'){
    $variables['classes_array'][] = 'card-width-full';
  }
  else{
    $variables['classes_array'][] = 'card-width-980';
  }
  $background_crop_value = 0;
  if($background_crop = field_get_items('node', $variables['node'], 'field_campaign_bg_crop')){
    if($background_crop[0]['value'] == 1){
      $variables['classes_array'][] = 'background-crop';
      $background_crop_value = $background_crop[0]['value'];
    }
  }
  /* Content Full Bleed */
  if($content_full_width = field_get_items('node', $variables['node'], 'field_campaign_full_width')){
    if($content_full_width[0]['value'] != 0){
      $variables['classes_array'][] = 'content-full-width';
    }
  }

  //Set the size of the background image
  $bg_image_width = tp4_render_field_value('node', $variables['node'], 'field_campaign_bgw_image');
  if($bg_image_width == 'Full Width'){
    $variables['styles'][] = 'background-size: 100%;';
  }
  else{
    $variables['styles'][] = 'background-size: 1000px;';
  }

  //Set the position of the background
  if($background_position = field_get_items('node', $variables['node'], 'field_campaign_bg_image_position')){
    if($background_position[0]['value'] == 2){
      $background_position = 'bottom';
    }else{
      $background_position = 'top';
    }
    $variables['styles'][] = 'background-position: '. $background_position. ';';
  }

  $background = '';
  $bg = '';
  if($background = field_get_items('node', $variables['node'], 'field_campaign_background')){
    $bg = file_create_url($background[0]['uri']);
    if($background_crop_value) {
      //image style for tablet and mobile
      $variables['background_image_desktop'][] = "background-image: url('$bg');";
      $variables['background_image_tablet'][] = "background-image: url('$bg');";
      $variables['background_image_mobile'][] = "background-image: url('$bg');";
    } else {
      //image style for tablet and mobile
      $variables['background_image_desktop'][] = "background-image: url('$bg');";
      if($bgtablet = image_style_path('large_responsive_tablet', $background[0]['uri'])) {
        $bgtablet = file_create_url($bgtablet);
        $variables['background_image_tablet'][] = "background-image: url('$bgtablet');";
      } else {
        $variables['background_image_tablet'][] = "background-image: url('$bg');";
      }
      if($bgmobile = image_style_path('large_responsive_mobile', $background[0]['uri'])) {
        $bgmobile = file_create_url($bgmobile);
        $variables['background_image_mobile'][] = "background-image: url('$bgmobile');";
      } else {
        $variables['background_image_mobile'][] = "background-image: url('$bg');";
      }
    }
    $variables['background_class'] = $variables['type'].$variables['nid'];
    $variables['classes_array'][] = $variables['type'].$variables['nid'];

    //Add parallax class
    if($is_parallax = field_get_items('node' , $variables['node'] , 'field_campaign_bg_parallax')) {
      if ($is_parallax[0]['value'] == 1) {
        $variables['classes_array'][] = 'parallax-bg';
      }
    }

  }

  /* Background Video */
  if($video = field_get_items('node', $variables['node'], 'field_campaign_bg_video')){
    $video = $video[0]['uri'];
    $video = file_create_url($video);

    if($video_poster = field_get_items('node', $variables['node'], 'field_campaign_bg_video_poster')){
      $bg = file_create_url($video_poster[0]['uri']);
      //image style for tablet and mobile
      $variables['background_image_desktop'][] = "background-image: url('$bg');";
      if($bgtablet = image_style_path('large_responsive_tablet', $video_poster[0]['uri'])) {
        $bgtablet = file_create_url($bgtablet);
        $variables['background_image_tablet'][] = "background-image: url('$bgtablet');";
      } else {
        $variables['background_image_tablet'][] = "background-image: url('$bg');";
      }
      if($bgmobile = image_style_path('large_responsive_mobile', $video_poster[0]['uri'])) {
        $bgmobile = file_create_url($bgmobile);
        $variables['background_image_mobile'][] = "background-image: url('$bgmobile');";
      } else {
        $variables['background_image_mobile'][] = "background-image: url('$bg');";
      }
      $variables['background_class'] = $variables['type'].$variables['nid'];
      $variables['classes_array'][] = $variables['type'].$variables['nid'];
    }
    //Ambient Video Check
    if($is_ambient = field_get_items('node' , $variables['node'] , 'field_ambient_video')) {
      if ($is_ambient[0]['value'] == 1) {
        $variables['classes_array'][] = 'is-ambient';
      }
    }

    //Audio volume Check
    if ($volume = field_get_items('node' , $variables['node'] , 'field_audio_volume')) {
      $volume = $volume[0]['value'];
      $variables['attributes_array']['data-video-volume'] = $volume;
    }

    $variables['attributes_array']['data-video-bg'] = "[\"$bg\", \"$video\"]";
    $variables['classes_array'][] = "has-videoBG";
  }
}

/**
 * Override or insert variables into the openpublish_photo_gallery template.
 */
function tp4_preprocess_node__openpublish_photo_gallery(&$variables) {

    if ($variables['view_mode'] == 'full') {

        // expose series tid in a data attribute
        $series = taxonomy_term_load($variables['field_series'][LANGUAGE_NONE][0]['tid']);
        if ($series) {
            $variables['attributes_array']['data-series'] = $series->name;
        }

        // Decide whether to display a TAP banner
        if ($variables['field_display_tab_banner']['und'][0]['value']) {
						$description_display = array(
							'label' => 'hidden',
							'type'  => 'text_with_inline_content',
							'settings' => array(
								'source' => 'field_inline_replacements'
							)
						);

						//removes all body info and just has it do a replacement to add at the end
						$node_clone = $variables['node'];
						$lang = $node_clone->language;
						$node_clone->body[$lang][0]['value'] = '';
						$node_clone->body[$lang][0]['safe_value'] = '';
						$variables['gallery_tap_banner'] = field_view_field('node', $node_clone, 'body', $description_display);
        }
	   // provide "on our radar" block
          _tp4_on_our_radar_block($variables);
        // provide topic box
        if($topic = field_get_items('node', $variables['node'], 'field_topic_box')){
          $variables['topic_box_top'] = theme('base_topic_box', array('tid' => $topic[0]['tid']));
        }
      _tp4_sponsor($variables);
    }
}

function tp4_preprocess_node__flashcard(&$variables) {

    $variables['content']['flashcard_related_content_primary'] = array(
        '#weight'=> 10,
        '#prefix' => '<aside class="flashcard-realted-content-primary">',
        '#suffix' => '</aside>',
    );
    $variables['content']['flashcard_related_content_primary'][] = $variables['content']['field_flashcard_related_primary'];
    $variables['content']['flashcard_related_content_primary'][] = array_merge($variables['flashcard_cta_link'], array('#weight' => 10));
    unset($variables['content']['field_flashcard_related_primary']);

    if ($variables['view_mode'] === 'full') {
        $variables['content']['body'][0]['#markup'] .= '<p><strong>What flashcards would you like to see?</strong> <a href="mailto:editorial@takepart.com?subject=New%20Flashcard%20Request">Email us</a> or let us know in the <a href="#block-tp-flashcards-flashcard-comments">comments</a> below.</p>';
    }

    //unsets the flashcard related if reference is empty
    if (empty($variables['content']['flashcard_related_content_primary'][0])) {
      unset($variables['content']['flashcard_related_content_primary']);
    }

    _tp4_sponsor($variables);
}

/**
 * Utility function to provide "On Our Radar" block to node templates
 */
function _tp4_on_our_radar_block(&$variables) {
  if ($variables['is_front'] != TRUE) {
    $variables['on_our_radar'] = theme('html_tag', array(
         'element' => array(
         '#tag' => 'div',
         '#value' => '',
         '#attributes' => array(
           'id' => 'pubexchange_related_links',
		 'data-pubexchange-module-id' => '514',
		 'class' => 'pubexchange_module',
     ))));
    drupal_add_js('(function(w, d, s, id) {
w.PUBX=w.PUBX || {pub: "take_part", discover: false, lazy: true};
var js, pjs = d.getElementsByTagName(s)[0];
if (d.getElementById(id)) return;
js = d.createElement(s); js.id = id; js.async = true;
js.src = "//main.pubexchange.com/loader.min.js";
pjs.parentNode.insertBefore(js, pjs);
}(window, document, "script", "pubexchange-jssdk"));',
      array(
        'type' => 'inline',
        'scope' => 'footer',
        'weight' => 10
      )
    );
  }
}

/**
 * Utility function to provide series nav to node templates
 */
function _tp4_series_nav(&$variables) {
    if (!empty($variables['field_series'])) {
        $series = taxonomy_term_load($variables['field_series']['und'][0]['tid']);

        $series_image = theme('image', array(
        	'path' => $series->field_series_graphic_header['und'][0]['uri'],
        	'alt' => $series->name,
        ));
        $termpath = taxonomy_term_uri($series);
        $series_header = l($series_image, $termpath['path'], array(
        	'html' => TRUE,
			'attributes' => array(
        		'id' => 'series_header',
			)
		));
        $created = $variables['created'];

        // find the next article, if any
        // (if it doesn't exist, $next will be an empty array)
        $seriesQueryNext = new EntityFieldQuery();
        $seriesQueryNext->entityCondition('entity_type', 'node')
                ->entityCondition('bundle', array('openpublish_article', 'feature_article', 'video', 'video_playlist'))
                ->propertyCondition('status', 1)
                ->propertyCondition('created', $created, '>')
                ->fieldCondition('field_series', 'tid', $series->tid, '=')
                ->propertyOrderBy('created', 'ASC')
                ->range(0, 1);
        $next = $seriesQueryNext->execute();
        if (!empty($next)) {
            $next = current($next['node']);
            $next = node_load($next->nid);
            $next_url = drupal_get_path_alias('node/' . $next->nid);
        }

        // find the previous article, if any
        // (if it doesn't exist, $previous will be an empty array)
        $seriesQueryPrev = new EntityFieldQuery();
        $seriesQueryPrev->entityCondition('entity_type', 'node')
                ->entityCondition('bundle', array('openpublish_article', 'feature_article', 'video', 'video_playlist'))
                ->propertyCondition('status', 1)
                ->propertyCondition('created', $created, '<')
                ->fieldCondition('field_series', 'tid', $series->tid, '=')
                ->propertyOrderBy('created', 'DESC')
                ->range(0, 1);
        $previous = $seriesQueryPrev->execute();
        if (!empty($previous)) {
            $previous = current($previous['node']);
            $previous = node_load($previous->nid);
            $previous_url = drupal_get_path_alias('node/' . $previous->nid);
        }

        // build up the series nav div
        $series_nav = '';
        $series_nav .= $series_header; // $series_image;

        // weird ternary operators will hide nav elements if they don't exist
        $series_nav .= empty($previous) ? '' : '<div class="more-prev">' . l("previous", $previous_url) . '</div>';
        $series_nav .= empty($next) ? '' : '<div class="more-next">' . l('next', $next_url) . '</div>';

        if (!empty($previous)) {
            $previous = '<div class="previous">' . (isset($previous->field_promo_headline['und'][0]['value']) ? $previous->field_promo_headline['und'][0]['value'] : drupal_render($previous->title)) . '</div>';
            $series_nav .= l($previous, $previous_url, array(
	        	'html' => TRUE,
				'attributes' => array(
	        		'class' => 'series_navigation',
				)
			));
        }
        if (!empty($next)) {
            $next = '<div class="next">' . (isset($next->field_promo_headline['und'][0]['value']) ? $next->field_promo_headline['und'][0]['value'] : $next->title) . '</div>';
            $series_nav .= l($next, $next_url, array(
	        	'html' => TRUE,
				'attributes' => array(
	        		'class' => 'series_navigation',
				)
			));
        }

        $variables['series_nav'] = $series_nav;
    } // if isset($variables['field_series'])
}

/**
 * Final preparation of node template data for display.
 *
 * Commented out by MW on 2014-01-15
 * Because we have no use for it
 */
// function tp4_process_node(&$variables, $hook) {
//   // Run node-type-specific process functions, like
//   // tp4_process_node_page() or tp4_process_node_story().
//   $function = __FUNCTION__ . '__' . $variables['node']->type;
//   if (function_exists($function)) {
//     $function($variables, $hook);
//   }
// }

/**
 * Override or insert variables into the comment templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("comment" in this case.)
 */
/* -- Delete this line if you want to use this function
  function STARTERKIT_preprocess_comment(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');
  }
  // */

/**
 * Override or insert variables into the region templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("region" in this case.)
 */


/**
 * Override or insert variables into the block templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("block" in this case.)
 */
/* -- Delete this line if you want to use this function
  function STARTERKIT_preprocess_block(&$variables, $hook) {
  // Add a count to all the blocks in the region.
  // $variables['classes_array'][] = 'count-' . $variables['block_id'];

  // By default, Zen will use the block--no-wrapper.tpl.php for the main
  // content. This optional bit of code undoes that:
  //if ($variables['block_html_id'] == 'block-system-main') {
  //  $variables['theme_hook_suggestions'] = array_diff($variables['theme_hook_suggestions'], array('block__no_wrapper'));
  //}
  }
  // */

/**
 * Override or insert variables into field templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("node" in this case.)
 */
function tp4_preprocess_field(&$variables, $hook) {
    if ('field_author' == $variables['element']['#field_name']) {
        $variables['classes_array'][] = 'author';
    }

    if ('field_tab_action_override' == $variables['element']['#field_name'] && 'feature_main' == $variables['element']['#view_mode']) {
        // Limit the main feature to one action override.
        if (!empty($variables['items'])) {
            $first = reset($variables['items']);
            $variables['items'] = array($first);
        }
    }

    if ('field_campaign_instructional' === $variables['element']['#field_name']) {
      // @todo this belongs in the featurized node display settings
      $variables['element']['#label_display'] = 'none';
      $variables['label_hidden'] = TRUE;
      $variables['classes_array'][] = 'instructional';
    }

    // allow us to add attributes to a field from hook_preprocess_node.
    if (isset($variables['element']['#attributes_array'])) {
        if (!isset($variables['attributes_array'])) {
            $variables['attributes_array'] = array();
        }
        $variables['attributes_array'] += $variables['element']['#attributes_array'];
    }
}

/**
 * Outputs Topic Taxonomy Links for Article Nodes
 */
function tp4_field__field_topic__openpublish_article($variables) {
    $output = '';

    foreach ($variables['items'] as $item) {
        $output .= '<li>' . drupal_render($item) . '</li>';
    }

    return $output;
}

/**
 * @todo TODO can we do this with one set of functions instead of 3?
 * I.e., Are these fields printed out anywhere else?
 */

/**
 * Outputs Topic Taxonomy links for gallery nodes.
 */
function tp4_field__field_topic__openpublish_photo_gallery($variables) {
    return tp4_field__field_topic__openpublish_article($variables);
}

/**
 * Outputs free tag taxonomy links for gallery nodes.
 */
function tp4_field__field_free_tag__openpublish_photo_gallery($variables) {
    return tp4_field__field_topic__openpublish_article($variables);
}

function tp4_menu_link(array $variables) {
    if ($variables['element']['#theme'] == 'menu_link__menu_megamenu') {
        $variables['element']['#attributes']['data-mlid'][] = $variables['element']['#original_link']['mlid'];
    }

	// Make urls absolute
	$variables['element']['#localized_options']['absolute'] = true;

    return theme_menu_link($variables);
}

// I think this is overridden by tp4_support/field-formatter--author-full.tpl.php
function tp4_field__field_author__openpublish_article($variables) {
    $output = '';

    $number_of_authors = count($variables['items']);

    $output .= '<span' . $variables['content_attributes'] . '>';
    foreach ($variables['items'] as $delta => $item) {
        $output .= '<span class="byline-author"' . $variables['item_attributes'][$delta] . '>';
        $output .= drupal_render($item);
        $output .= '</span>';
        // add commas for lists of 3 or greater ($delta is zero-indexed)
        $output .= ($number_of_authors > 2 && $delta < $number_of_authors - 2 ) ? ', ' : '';
        // add 'and' for lists of 2 or greater ($delta is zero-indexed)
        $output .= ($number_of_authors > 1 && $delta == $number_of_authors - 2 ) ? ' and ' : '';
    }
    $output .= '</span>';

    // Render the top-level div.
    $output = '<div class="byline ' . $variables['classes'] . '"' . $variables['attributes'] . '>By ' . $output . '</div>';

    return $output;
}

function tp4_field__field_author__feature_article($variables) {
  return tp4_field__field_author__openpublish_article($variables);
}

function tp4_field__field_author__openpublish_photo_gallery($variables) {
  return tp4_field__field_author__openpublish_article($variables);
}

function tp4_field__field_author__video($variables) {
  return tp4_field__field_author__openpublish_article($variables);
}

function tp4_field__field_author__video_playlist($variables) {
  return tp4_field__field_author__openpublish_article($variables);
}

function tp4_field__field_author__fresh_gallery($variables) {
  return tp4_field__field_author__openpublish_article($variables);
}

function tp4_field__field_flashcard_page_headline__flashcard($variables) {
    $output = '<h1 class="node-title ' . $variables['classes'] . '"' . $variables['attributes'] . '>';

    // Render the items.
    $output .= '<span class="field-items"' . $variables['content_attributes'] . '>';
    foreach ($variables['items'] as $delta => $item) {
        $classes = 'field-item ' . ($delta % 2 ? 'odd' : 'even');
        $output .= '<span class="' . $classes . '"' . $variables['item_attributes'][$delta] . '>' . drupal_render($item) . '</span>';
    }
    $output .= '</span>';

    $output .= '</h1>';

    return $output;
}

function tp4_field__field_article_subhead__openpublish_article($variables) {
    $output = '';

    // Render the items.
    $output .= '<span class="field-items"' . $variables['content_attributes'] . '>';
    foreach ($variables['items'] as $delta => $item) {
        $classes = 'field-item ' . ($delta % 2 ? 'odd' : 'even');
        $output .= '<span class="' . $classes . '"' . $variables['item_attributes'][$delta] . '>' . drupal_render($item) . '</span>';
    }
    $output .= '</span>';

    // Render the top-level DIV.
    if ($variables['element']['#view_mode'] == 'feature_main_tpl') {
        $path = drupal_get_path_alias('node/' . $variables['element']['#object']->nid);
        $output = '<h2 class="' . $variables['classes'] . '"' . $variables['attributes'] . '>' . l($output, $path, array('html' => true)) . '</h2>';
    } else {
        $output = '<h2 class="' . $variables['classes'] . '"' . $variables['attributes'] . '>' . $output . '</h2>';
    }

    return $output;
}

function tp4_field__field_article_subhead__flashcard($variables) {
    return tp4_field__field_article_subhead__openpublish_article($variables);
}

function tp4_field__field_article_main_image__openpublish_article($variables) {
    $output = '';

    foreach ($variables['items'] as $delta => $item) {

        // set up some variables we're going to need.
        $image = array();
        $image['path'] = $item['#file']->uri;

        // pick out the image style, defaulting to landscape
        $image['style_name'] = 'landscape_main_image';
        if ($item['#view_mode'] == 'portrait')
            $image['style_name'] = 'portrait_main_image';

        // schema.org article microdata
        $image['attributes'] = array();
        $image['attributes']['itemprop'] = 'image';

        // TODO: do this through drupal APIs
        $image['alt'] = $item['#file']->field_media_alt['und'][0]['safe_value'];

        $output .= '<figure class="' . $item['#view_mode'] . '"' . $variables['item_attributes'][$delta] . '>';
        // $output .= drupal_render($item['file']);
        // $output .= theme('image', $item['#file']);
        $output .= theme('image_style', $image);
        $output .= '<figcaption>';
        $output .= drupal_render($item['field_media_caption']);
        $output .= '</figcaption></figure>';
    }
    $output = '<div class="' . $variables['classes'] . '"' . $variables['attributes'] . '>' . $output . '</div>';
    return $output;
}

/**
 *  Copying code from above to allow flashcard to have captions
 */
function tp4_field__field_flashcard_main_image__flashcard($variables) {
    $output = '';

    foreach ($variables['items'] as $delta => $item) {
        // set up some variables we're going to need.
        $image = array();
        $image['path'] = $item['#item']['uri'];

        // pick out the image style, defaulting to landscape
        $image['style_name'] = 'landscape_main_image';
        if ($item['#view_mode'] == 'portrait')
            $image['style_name'] = 'portrait_main_image';

        // schema.org article microdata
        $image['attributes'] = array();
        $image['attributes']['itemprop'] = 'image';

        // TODO: do this through drupal APIs
        $image['alt'] = $item['#file']->field_media_alt['und'][0]['safe_value'];

        $output .= '<figure class="' . $item['#view_mode'] . '"' . $variables['item_attributes'][$delta] . '>';
        $output .= theme('image_style', $image);
        $output .= '<figcaption>';
        $output .= (isset($item['#item']['field_media_caption']['und'])) ? $item['#item']['field_media_caption']['und'][0]['safe_value'] : '';
        $output .= '</figcaption></figure>';
    }
    $output = '<div class="' . $variables['classes'] . '"' . $variables['attributes'] . '>' . $output . '</div>';
    return $output;
}

function tp4_field__field_flashcard_display_name__flashcard($variables) {
    $output = '<h2 class="' . $variables['classes'] . '"' . $variables['attributes'] . '><dfn>';

    // Render the items.
    $output .= '<span class="field-items"' . $variables['content_attributes'] . '>';
    foreach ($variables['items'] as $delta => $item) {
        $classes = 'field-item ' . ($delta % 2 ? 'odd' : 'even');
        $output .= '<span class="' . $classes . '"' . $variables['item_attributes'][$delta] . '>' . drupal_render($item) . '</span>';
    }
    $output .= '</span>';

    $output .= '</dfn></h2>';

    return $output;
}

function tp4_field__field_flashcard_pronunciation__flashcard($variables) {
    $output = '<div class="' . $variables['classes'] . '"' . $variables['attributes'] . '>[';

    // Render the items.
    $output .= '<span class="field-items"' . $variables['content_attributes'] . '>';
    foreach ($variables['items'] as $delta => $item) {
        $classes = 'field-item ' . ($delta % 2 ? 'odd' : 'even');
        $output .= '<span class="' . $classes . '"' . $variables['item_attributes'][$delta] . '>' . drupal_render($item) . '</span>';
    }
    $output .= '</span>';

    $output .= ']</div>';

    return $output;
}

/**
 * Implements template_preprocess_entity().
 *
 * This is legacy code from chunkpart to make the "more on our site" bean work
 */
function tp4_preprocess_entity(&$variables, $hook) {

    $variables['custom_render'] = array();
    switch ($variables['entity_type']) {
        case "bean":
            if ($variables['bean']->{'type'} == "of_the_day") {
                //Look for a tpl file called bean--of-the-day-custom.tpl.php:
                $variables['theme_hook_suggestions'][] = 'bean__of_the_day_custom';
                $children = element_children($variables['elements']['field_listing_collection'], $sort = FALSE);

                foreach ($children as $key => $child) {
                    $collectiondata = $variables['elements']['field_listing_collection'][$child];
                    $collectiondata = current($collectiondata['entity']['field_collection_item']);

                    $acnid = $collectiondata['field_associated_content']['#items'][0]['nid'];
                    $node = node_load($acnid);
                    if ($node->status == 1) {
                        $variables['custom_render'][$key]['typename'] = $collectiondata['field_type_label']['#items'][0]['value'];

                        if (
                            $node->type == 'openpublish_article'
                            || $node->type == 'feature_article'
                            || $node->type == 'video'
                            || $node->type == 'video_playlist'
                            || $node->type == 'flashcard'
                            || $node->type == 'openpublish_video'
                            || $node->type == 'campaign_page'
                        ) {
                            $main_image = field_get_items('node', $node, 'field_thumbnail');
                        }
                        else if ($node->type == 'action') {
                            $main_image = field_get_items('node', $node, 'field_action_main_image');
                        }
                        else if ($node->type == 'openpublish_photo_gallery') {
                            $main_image = field_get_items('node', $node, 'field_thumbnail');
                            if ($main_image == NULL) {
                                $main_image = field_get_items('node', $node, 'field_gallery_images');
                            }
                        }
                        if (isset($main_image[0]['fid'])) {
                            $img_url = file_load($main_image[0]['fid']);
                            $img_alt = field_get_items('file', $img_url, 'field_media_alt');
                            $variables['custom_render'][$key]['thumbnail_alt'] = $img_alt[0]['safe_value'];
                            if (isset($img_url->{'uri'})) {
                                $variables['custom_render'][$key]['thumbnail'] = image_style_url('thumbnail_v2', $img_url->{'uri'});
                            }
                        }
                        $types = node_type_get_types();
                        if (isset($types[$node->type]->{'name'})) {
                            $variables['custom_render'][$key]['type'] = $types[$node->type]->{'name'};
                        }

                        $variables['custom_render'][$key]['title'] = field_get_items('node', $node, 'field_promo_headline');

                        if ((isset($node->{'title'})) && (!isset($variables['custom_render'][$key]['title']))) {
                            $variables['custom_render'][$key]['title'] = $node->{'title'};
                        }

                        //adding fix to address issue with title not displaying
                        if (!$variables['custom_render'][$key]['title']) {
                          //creates new title var at 0
                          $variables['custom_render'][$key]['title'][0] = array(
                            'value' => $node->title,
                            'safe_value' => $node->title
                          );
                        }

                        $variables['custom_render'][$key]['url'] = url('node/' . $node->nid);
                    }
                }
            }
            break;
    }
}

function tp4_preprocess_panels_pane(&$variables) {
  if ($variables['pane']->panel == 'main_featured') {
    $variables['theme_hook_suggestions'][] = 'panels_pane__main_featured';
    $variables['title_link'] = url('node/' . $variables['content']['#node']->nid);
    if ($variables['content']['#bundle'] == 'video' || $variables['content']['#bundle'] == 'video_playlist') {
      $variables['title_attributes_array']['class'][] = 'no-overlap';
    }
    else if ($variables['content']['#bundle'] == 'flashcard') {
      $variables['title'] = l($variables['content']['#node']->title, 'node/' . $variables['content']['#node']->nid);
    }
  }
}

/*
 * Campaign Field Overrides
 */
function tp4_field__field_campaign_media_title($variables) {
  return tp4_field_campaign_media_title($variables);
}
function tp4_field__field_campaign_iframe($variables){
  return tp4_field_campaign_iframe($variables);
}
function tp4_field_campaign_media_title($variables){
  $output = '';
  $output .= '<h4 class="title">'. $variables['items'][0]['#markup']. '</h4>';
  return $output;
}
function tp4_field_campaign_iframe($variables){
  $output = '';
  $height = $variables['element']['#object']->field_campaign_iframe_height['und'][0]['value'];
  $width = $variables['element']['#object']->field_campaign_iframe_width['und'][0]['value'];
  $output .= '<iframe src="'. $variables['items'][0]['#markup']. '" width="'. $width. '" height="'. $height. '"></iframe>';
  return $output;
}

function tp4_block_view_alter(&$data, $block) {
    switch ($block->delta) {
        case 'ga_mobile_320x50':
            $button = '<a href="#" id="close-'.$block->delta.'" class="close-mobile-ad tplinkpos"><span>X</span></a>';
            $data['content'] = $button . $data['content'];
            break;
    }
}

function tp4_preprocess_entity_iframe(&$variables){
  if(arg(1) == 'node'){
    $nid = arg(2);
    $nodes = entity_load('node', array($nid));
    $node = reset($nodes);
    $type = $node->type;
    if($type == 'video' || $type == 'video_playlist'){
      drupal_add_css('html{overflow: hidden;}', array('type' => 'inline'));
    }
  }
}

/**
 * Theme function for displaying search results.
 */
function tp4_search_api_page_results(array &$variables) {
#    drupal_add_css(drupal_get_path('module', 'search_api_page') . '/search_api_page.css');

	// Get the human-readable node types
	$types = node_type_get_types();

    $index = $variables['index'];
    $results = $variables['results'];
    $entities = $variables['items'];
    $keys = $variables['keys'];
    $output = '<p class="search-performance">' .
            format_plural($results['result count'], 'Current search found 1 result for ' .
            check_plain($keys), 'Current search found @count results for ' .
            check_plain($keys), array('@sec' => round($results['performance']['complete'], 3))) . '</p>';
    if (!$results['result count']) {
        $output .= "\n<h2>" . t('Your search yielded no results') . "</h2>\n";
        return $output;
    } else {
        $block = module_invoke('search_api_sorts', 'block_view', 'search-sorts');
        $output .= '<div id="block-search-api-sorts-search-sorts"><h2>Sort by:</h2><div class="content">' . render($block['content']) . '</div></div>';
    }

	// Borrowing styling from Views for consistency
	$output .= '<div class="view view-taxonomy-search-list view-id-taxonomy_search_list view-display-id-block_2 view-topic-listing">
    <div class="view-content">

';

    if ($variables['view_mode'] == 'search_api_page_result') {
        entity_prepare_view($index->entity_type, $entities);

        foreach ($results['results'] as $item) {
	        $result = $entities[$item['id']];
          if(!empty($result)) {
            $field_promo_title = field_get_items('node', $result, 'field_promo_headline');
            if (empty($field_promo_title)) {
	            $field_promo_title = $result->title;
	          } else {
              $field_promo_title = $field_promo_title[0]['value'];
            }
          } else {
             $field_promo_title = $result->title;
          }

          //Use Actions main image for the thumbnail
          if ($result ->type == 'action') {
            $field_thumbnail  = field_get_items('node',$result,'field_action_main_image');
            $field_thumbnail = file_load($field_thumbnail[0]['fid']);
          }
          else {
            $field_thumbnail = field_get_items('node',$result,'field_thumbnail');
            $field_thumbnail = file_load($field_thumbnail[0]['fid']);
          }

		      $field_promo_text = field_get_items('node',$result,'field_promo_text');
		      $text = $result->excerpt ? $result->excerpt : $field_promo_text[0]['value'];

          $output .= theme('search_result', array(
        	    'result' => array(
	        	    'title' => $field_promo_title,
	              'url' => entity_uri($index->item_type, $result),
	        	    'snippet' => $text,
				        'type' => $types[$result->type]->name,
				        'thumbnail' => theme('image_style', array(
					        'style_name' => 'topic_thumbnail',
					        'path' => $field_thumbnail->uri,
					        'alt' => $field_promo_title,
					        'title' => $field_promo_title,
				        )),
        	    ),
            ));
		    }
    } else {
        $output .= render(entity_view($index->entity_type, $entities, $variables['view_mode']));
    }

	// Customize the pager links
    $entities['tags'] = array(
    	0 => t('First'),
    	1 => t('Previous'),
    	2 => t(''),
    	3 => t('Next'),
    	4 => t('Last'),
    );

	$output .= theme('pager', $entities);
	$output .= '</div></div>';

	$variables['search_results'] = $output;

	return $output;
}

function tp4_page_alter(&$page) {
  // unset the search-results $pager. It's being created in the TP4 template.
  if($page['content']['system_main']['pager']) {
	unset($page['content']['system_main']['pager']);
  }

  $uri = filter_input(INPUT_SERVER, 'REQUEST_URI', FILTER_SANITIZE_URL);
  if (preg_match('/^\/entity_iframe/', $uri) ||  preg_match('/^\/iframes/', $uri)) {
    header_remove('X-Frame-Options');
  }
}

function _tp4_sponsor(&$variables){
	$s = field_get_items('node',$variables['node'],'field_sponsored');
	$tid = $s[0]['tid'];
	if($tid) {
		$sponsor = taxonomy_term_load($tid);
		$sponsored_by = $sponsor->field_sponsor_label['und'][0]['value'];

		// Add the sponsor logo, or the name, if there isn't one
		if( $sponsor->field_sponsor_logo['und'][0]['fid'] ) {
			$logo = file_load($sponsor->field_sponsor_logo['und'][0]['fid']);
			$logo = theme('image', array(
					'style_name' => 'sponsor_logo',
					'path' => $logo->uri,
					'alt' => $sponsored_by.' '.$sponsor->name,
					'title' => $sponsored_by.' '.$sponsor->name,
			));
		} else {
			$logo = ' '.$sponsor->name;
		}

		$variables['content']['sponsored'] = theme('base_sponsor', array('sponsor' => $sponsored_by, 'logo' => $logo));

		// Get (default) disclaimer
		if($sponsor->description) {
			$disclaimer = $sponsor->description;
		} else {
	    	$default_disclaimer = taxonomy_term_load($sponsor->field_sponsor_type['und'][0]['tid']);
	    	$disclaimer = $default_disclaimer->description;
		}

		$variables['content']['sponsor_disclaimer'] = theme('base_sponsor_disclaimer', array('disclaimer' => trim($disclaimer)));
	}
}
