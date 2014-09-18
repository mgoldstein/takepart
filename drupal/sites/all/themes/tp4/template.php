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
function tp4_preprocess_html(&$variables, $hook) {

  // Pass the digital data to the HTML template.
  $variables['tp_digital_data'] =  isset($variables['page']['tp_digital_data'])
    ? $variables['page']['tp_digital_data'] : NULL;

  // If on an individual node page, add the node type to body classes.
  if ($node = menu_get_object()) {
	  $card_types = unserialize(CARDTYPES);
    if(in_array($node->type, $card_types) == true || $node->type == 'campaign_page'){
      $variables['classes_array'][] = drupal_html_class('campaign-display');
    }
  }

    if ($variables['page']['content']['system_main']['#entity_view_mode']['bundle'] == 'topic') {
        $variables['classes_array'][] = 'vocabulary-topic';
    }
    drupal_add_js('//cdn.optimizely.com/js/77413453.js', array(
        'type' => 'external',
        'scope' => 'footer',
        'group' => JS_DEFAULT,
        'every_page' => TRUE,
        'weight' => -1,
    ));
    // add jquery cookie library to tp4 pages
    drupal_add_library('system', 'jquery.cookie', true);

    $node = menu_get_object();
		$campaign_types = unserialize(CARDTYPES);
		if(!empty($campaign_types)){
	    $campaign_types[] = 'campaign_page';
	    if (isset($node) && in_array($node->type, $campaign_types)) {
        $variables['dtm_script_src'] = variable_get('dtm_script_src');
	    }
		}

    if (preg_match('/^\/entity_iframe/', $_SERVER['REQUEST_URI']) ) {
        unset($variables['page']['page_bottom']['omniture']);
        unset($variables['page']['page_bottom']['quantcast']);
    }
}

function tp4_js_alter(&$javascript) {
  if (preg_match('/^\/entity_iframe/', $_SERVER['REQUEST_URI']) ) {
    unset($javascript['sites/all/modules/contrib/google_analytics/googleanalytics.js']);
  }
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

}

/**
 * TODO: This function should be removed once the tp4_campaign_megamenu starts
 *   using the anchor provided by the menu_attributes module.
 */
function _tp4_campaign_megamenu_attach_fragments(&$link) {
  if (isset($link['#localized_options']['attributes']['rel'])) {
    $link['#localized_options']['fragment']
      = $link['#localized_options']['attributes']['rel'];
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
    if (in_array($node->type, array('openpublish_article', 'feature_article', 'openpublish_photo_gallery', 'video', 'video_playlist'))) {
      // but only if we're on the production site
      return ENVIRONMENT === 'production';
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

	if(isset($variables['node']) && $variables['node']->type == 'campaign_page'){
	  $campaign_nid = $variables['node']->field_campaign_reference['und'][0]['target_id'];
	  $variables['campaign_menu'] = tp4_campaign_megamenu($campaign_nid);
	}
  $variables['skinny'] = render($variables['page']['skinny']);
  $variables['sidebar'] = render($variables['page']['sidebar']);

  // build up a string of classes for the main content div
  $variables['content_classes'] = 'content';
  $variables['content_classes'] .= ($variables['skinny'] ? ' with-skinny' : '');
  $variables['content_classes'] .= ($variables['sidebar'] ? ' with-sidebar' : '');

  // Add Node-specific page templates
  if (!empty($variables['node'])) {
    $variables['theme_hook_suggestions'][] = 'page__' . $variables['node']->type;
  }

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
  }
}

/**
 * Implements hook_css_alter().
 */
function tp4_css_alter(&$css) {
    // Take out tp4_support's slimnav CSS file to avoid duplication of code
    unset($css[drupal_get_path('module', 'tp4_support') . '/css/tp4_support.css']);
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
}

/**
 * Override or insert variables into the template for
 * the "slim-nav" tempalte.
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

  // Run node-type-specific preprocess functions, like
  // tp4_preprocess_node__page() or tp4_preprocess_node__story().
  $function = __FUNCTION__ . '__' . $variables['node']->type;
  if (function_exists($function)) {
    $function($variables, $hook);
  }

	//address issue with title for photo gallery not showing the titles
	if ($variables['view_mode'] == 'inline_content' && !$variables['title'] && $variables['referencing_field'] == 'field_related_stories') {
		$variables['title'] = $variables['node']->title;
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
  else{ //Media is a photo

    $image = field_get_items('node', $variables['node'], 'field_campaign_media_photo');
    if(!empty($image)){
      $image = file_create_url($image[0]['uri']);
    }
    //Check if photo has a link
    $image_url = field_get_items('node', $variables['node'], 'field_campaign_media_image_link');
    if(!empty($image_url) && !empty($image)){
      $media = l('<img src="'. $image. '" alt="'.$alt.'">', $image_url[0]['url'], array('html' => true, 'attributes' => array('target' => $image_url[0]['attributes']['target'])));
    }
    else{
      $media = '<img src="'. $image. '" alt="'.$alt.'">';
    }

  }
  //Grab Description
  $description = tp4_render_field_value('node', $variables['node'], 'body');
  if(!empty($description)){
    if (function_exists('tp_flashcards_parse_html')) {
      $description = tp_flashcards_parse_html($description);
      $description = '<div class="description">'. $description. '</div>';
    }else{
      $description = '';
    }
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

  //content
  $instructional = tp4_render_field_value('node', $variables['node'], 'field_campaign_instructional');
  if(!empty($instructional)){
    $variables['instructional'] = $instructional;
  }
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
      if (function_exists('tp_flashcards_parse_html')) {
        $left = tp_flashcards_parse_html($left);
      }
      $left = '<div class="text">'. $left. '</div>';
    }
    $right = tp4_render_field_value('node', $variables['node'], 'field_campaign_text_right');
    if(!empty($right)){
      if (function_exists('tp_flashcards_parse_html')) {
        $right = tp_flashcards_parse_html($right);
      }
      $right = '<div class="text">'. $right. '</div>';
    }

    $variables['theme_hook_suggestions'][] = 'node__campaign_card_2col';
  }

  // Else, if it's a single column use the single column template and $center variable
  elseif($column_count == 'Single Column'){
    $center = tp4_render_field_value('node', $variables['node'], 'field_campaign_text_left');
    if(!empty($center)){
      if (function_exists('tp_flashcards_parse_html')) {
        $center = tp_flashcards_parse_html($center);
      }
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

  //content
  $instructional = tp4_render_field_value('node', $variables['node'], 'field_campaign_instructional');
  if(!empty($instructional)){
    $variables['instructional'] = $instructional;
  }
  $variables['center'] = $center;
  $variables['left'] = $left;
  $variables['right'] = $right;
}


/**
 * Override or insert variables into the campaign card social template
 */
function tp4_preprocess_node__campaign_card_social(&$variables, $hook) {

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

  $instructional = tp4_render_field_value('node', $variables['node'], 'field_campaign_instructional');
  if(!empty($instructional)){
    $variables['instructional'] = $instructional;
  }
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
    if (function_exists('tp_flashcards_parse_html')) {
      $descriptive_text = tp_flashcards_parse_html($descriptive_text);
    }
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

    // Is this card a single value news card or a multi-value news card?
    $news_type = tp4_render_field_value('node', $variables['node'], 'field_campaign_news_type');
    if($news_type == 'Single Article'){  //single value
      $news_ref = field_get_items('node', $variables['node'], 'field_campaign_single_news_ref');
      $node = node_load($news_ref[0]['target_id']);

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
        $short_headline = tp4_render_field_value('node', $node, 'field_article_subhead');
        $headline = tp4_render_field_value('node', $node, 'field_promo_headline');
      }

      $image = file_create_url($file->uri);
      $image = image_style_url('campaign_news_3x2', $file->uri);
      $alt = (isset($file->alt) == true && $file->alt != NULL ? $file->alt : $node->title);
      $image = '<img src="'. $image. '" alt="'.$alt.'">';  //image
      $center = '';  // single news reference will use one column now
      $path = drupal_get_path_alias('node/'. $node->nid);

      $center .= l($image, $path, array('html' => true));
      $center .= '<h3 class="headline">'. l($headline, $path, array('html' => true)). '</h3>';  //headline
      $center .= '<p class="short-headline">'. $short_headline. '</p>';  //short headline

    }
    else{ //multivalue

      $variables['classes_array'][] = 'multi-news';

      $nids = array();
      $news_ref = field_get_items('node', $variables['node'], 'field_campaign_multi_news_ref');
      foreach($news_ref as $key => $item){
        $nids[] = $item['target_id'];
      }

      // Query non referenced content (max 5)
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

        $alt = (isset($file->alt) == true && $file->alt != NULL ? $file->alt : $node->title);
        $image = file_create_url($file->uri);
        $image = image_style_url('campaign_news_3x2', $file->uri);
        $media = '<img src="'. $image. '" alt="'.$alt.'">';
        $news_column = $media;
        $news_column .= '<h5>'. $headline. '</h5>';

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
    if (function_exists('tp_flashcards_parse_html')) {
      $more = tp_flashcards_parse_html($more);
    }
    $more = '<div class="more-link">'. $more. '</div>';
    $center .= $more;

    //background properties
    tp4_campaign_background_rules($variables);

  //content
  $variables['theme_hook_suggestions'][] = 'node__campaign_card_1col';
  $instructional = tp4_render_field_value('node', $variables['node'], 'field_campaign_instructional');
  if(!empty($instructional)){
    $variables['instructional'] = $instructional;
  }
  $variables['center'] = $center;


}

function tp4_preprocess_node__campaign_card_iframe(&$variables, $hook) {
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
  $instructional = tp4_render_field_value('node', $variables['node'], 'field_campaign_instructional');
  if(!empty($instructional)){
    $variables['instructional'] = $instructional;
  }
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
    $image = file_create_url($image[0]['uri']);
    $image = '<img src="'. $image. '">';
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
  $image = file_create_url($variables['field_campaign_background']['und'][0]['uri']);
  $center = '<img src="'. $image. '">';

  //background properties
  tp4_campaign_background_rules($variables);

  //content
  $variables['theme_hook_suggestions'][] = 'node__campaign_card_1col';
  $variables['center'] = $center;

}

function tp4_preprocess_node__campaign_card_multi_column(&$variables, $hook) {

  $multi_grid = field_get_items('node', $variables['node'], 'field_campaign_multigrid_item');
  $item_width = tp4_render_field_value('node', $variables['node'], 'field_campaign_multi_item_width');
  if(empty($item_width)){
      $item_width = 180;
  }

  $items = array();
  foreach($multi_grid as $key=> $item){
    $items[] = $item['value'];
  }
  $field_collections = entity_load('field_collection_item', $items);
  $center = '';
  $center .= '<div class="center-inner">';
  foreach($field_collections as $key => $collection){
    $image = tp4_render_field_value('field_collection_item', $collection, 'field_promo_thumbnail');
    $text = tp4_render_field_value('field_collection_item', $collection, 'field_promo_text');
    $link = field_get_items('field_collection_item', $collection, 'field_campaign_multigrid_link');
    $target = (isset($link[0]['attributes']['target']) ? $link[0]['attributes']['target'] : '_self');
    if(!empty($link)){
        $image = l($image, $link[0]['url'], array('html' => true, 'attributes' => array('target' => $target)));
    }
    $center .= '<div class="item" style="max-width:'. $item_width. 'px;">';
    $center .= $image;
    $center .= (!empty($text) ? $text : '');
    $center .= '</div>';
  }
  $center .= '</div>';
  //background properties
  tp4_campaign_background_rules($variables);

  //content
  $instructional = tp4_render_field_value('node', $variables['node'], 'field_campaign_instructional');
  if(!empty($instructional)){
      $variables['instructional'] = $instructional;
  }
  $variables['theme_hook_suggestions'][] = 'node__campaign_card_1col';
  $variables['center'] = $center;
}

function tp4_preprocess_node__campaign_card_tap_widget(&$variables, $hook) {
	if(module_exists('tp_campaigns')){
		$card_title = tp_campaigns_card_title($variables);
		$variables['instructional'] = tp_campaigns_card_instructional($variables);
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
	if($background_crop = field_get_items('node', $variables['node'], 'field_campaign_bg_crop')){
		if($background_crop[0]['value'] == 1){
			$variables['classes_array'][] = 'background-crop';
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

	$background = field_get_items('node', $variables['node'], 'field_campaign_background');
	$variables['card_background'] = (!empty($background) ? file_create_url($background[0]['uri']) : '');

}


/**
 * Override or insert variables into the openpublish_article template.
 */
function tp4_preprocess_node__openpublish_article(&$variables, $hook) {

    // expose series tid in a data attribute
    $series = taxonomy_term_load($variables['field_series'][LANGUAGE_NONE][0]['tid']);
    if ($series) {
        $variables['attributes_array']['data-series'] = $series->name;
    }

    // we're going to do some things only on the full view of an article
    if ($variables['view_mode'] == 'full') {
        // provide "on our radar" block
        _tp4_on_our_radar_block($variables);

        // provide topic box
        _tp4_topic_box($variables);

        // provide a series prev/next nav if a series exists
        _tp4_series_nav($variables);

        // Add schema.org Article microdata
        $variables['attributes_array']['itemscope'] = 'itemscope';
        $variables['attributes_array']['itemtype'] = 'http://schema.org/Article';
        $variables['title_attributes_array']['itemprop'] = 'headline';
        // these work because of some magic in hook_preprocess_field
        $variables['content']['field_article_subhead']['#attributes_array']['itemprop'] = "description";
        $variables['content']['body']['#attributes_array']['itemprop'] = 'articleBody';
        // for more microdata:
        // @see tp4_field__field_article_main_image__feature_article()
        // @see tp4_field__field_article_main_image__openpublish_article()
        // @see field-formatter--author-full.tpl.php
    } // if ($variables['view_mode'] == 'full')
}

/**
 * Override or insert variables into the feature_article template.
 *
 * Largely this reproduces the author, series, and topic markup
 * from the openpublish_article template.
 */
function tp4_preprocess_node__feature_article(&$variables, $hook) {
    tp4_preprocess_node__openpublish_article($variables);

    if ($variables['view_mode'] == 'full') {
        // put the title color as a class on the title.
        $variables['title_attributes_array']['class'][] = $variables['field_title_color'][LANGUAGE_NONE][0]['value'];

				//grabs featured link from node
				$featured_link = field_get_items('node', $variables['node'], 'field_article_featured_link');
				$featured_link_array = field_view_value('node', $variables['node'], 'field_article_featured_link', $featured_link[0]);

				//ensures that the title is set
				if (isset($featured_link_array['#element']['url'])) {
					//variables for featured link
					$feature_title = $featured_link_array['#element']['title'];
					$feature_link = $featured_link_array['#element']['url'];

					//ensures that the link is not empty
					if (!empty($feature_link)) {
						// ad "TakePart Features" branding
						$variables['title_prefix'][] = array(
								'#theme' => 'link',
								'#text' => $feature_title,
								'#path' => $feature_link,
								'#options' => array(
										'attributes' => array('class' => array('takepart-features-branding', $variables['field_title_color'][LANGUAGE_NONE][0]['value'])),
										'html' => FALSE,
								),
						);
					}
				}

        // orphan protection for headlines
        $title = trim($variables['title']);
        $last_space = strrpos($title, ' ');
        $variables['title'] = substr($title, 0, $last_space) . '&nbsp;' . substr(strrchr($title, ' '), 1);
    }
}

function tp4_preprocess_node__video(&$variables, $hook) {
    tp4_preprocess_node__openpublish_article($variables, $hook);
    if ($variables['view_mode'] == 'embed') {
        $variables['title'] = '';
    }
}

function tp4_preprocess_node__video_playlist(&$variables, $hook) {
    tp4_preprocess_node__openpublish_article($variables, $hook);
    if ($variables['view_mode'] == 'embed') {
        $variables['title'] = '';
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
            $variables['gallery_tap_banner'] = array(
                '#type' => 'markup',
                '#markup' => '<div class="takepart-take-action-widget"></div>',
            );
        }

        // provide "on our radar" block
        _tp4_on_our_radar_block($variables);

        // provide topic box
        _tp4_topic_box($variables);
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
}

/**
 * Utility function to provide "On Our Radar" block to node templates
 */
function _tp4_on_our_radar_block(&$variables) {
    $on_our_radar_block = block_load('bean', 'on-our-radar-block');
    $variables['on_our_radar'] = _block_get_renderable_array(_block_render_blocks(array($on_our_radar_block)));
}

/**
 * Utility function to provide topic box to node templates
 */
function _tp4_topic_box(&$variables) {
    if (!empty($variables['field_topic_box'])) {
        $topic = taxonomy_term_load($variables['field_topic_box']['und'][0]['tid']);

        if (!empty($topic->field_topic_box_image['und'][0]['uri'])) {
            $image = theme('image', array('path' => $topic->field_topic_box_image['und'][0]['uri']));
            if (!empty($topic->field_topic_box_link)) {
              $drupal_url = ( substr($topic->field_topic_box_link['und'][0]['url'], 0, 1) === "/") ? substr($topic->field_topic_box_link['und'][0]['url'], 1) : $topic->field_topic_box_link['und'][0]['url'];

            }
          $variables['field_topic_box_top'] = empty($drupal_url) ? $image : l($image, $drupal_url, array('html' => TRUE));
        }
    }
}

/**
 * Utility function to provide series nav to node templates
 */
function _tp4_series_nav(&$variables) {
    if (!empty($variables['field_series'])) {
        $series = taxonomy_term_load($variables['field_series']['und'][0]['tid']);
        $series_image = theme('image', array('path' => $series->field_series_graphic_header['und'][0]['uri']));
        $termpath = taxonomy_term_uri($series);
        $series_header = l($series_image, $termpath['path'], array('html' => TRUE) );
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
            $series_nav .= l($previous, $previous_url, array('html' => true));
        }
        if (!empty($next)) {
            $next = '<div class="next">' . (isset($next->field_promo_headline['und'][0]['value']) ? $next->field_promo_headline['und'][0]['value'] : $next->title) . '</div>';
            $series_nav .= l($next, $next_url, array('html' => true));
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
 * Outputs Free Tag taxonomy links for article nodes.
 */
function tp4_field__field_free_tag__openpublish_article($variables) {
    return tp4_field__field_topic__openpublish_article($variables);
}

/**
 * Outputs Topic Taxonomy links for featre article nodes.
 */
function tp4_field__field_topic__feature_article($variables) {
    return tp4_field__field_topic__openpublish_article($variables);
}

/**
 * Outputs free tag taxonomy links for feature article nodes.
 */
function tp4_field__field_free_tag__feature_article($variables) {
    return tp4_field__field_topic__openpublish_article($variables);
}

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

/**
 * Outputs Topic Taxonomy links for gallery nodes.
 */
function tp4_field__field_topic__video($variables) {
    return tp4_field__field_topic__openpublish_article($variables);
}

/**
 * Outputs free tag taxonomy links for gallery nodes.
 */
function tp4_field__field_free_tag__video($variables) {
    return tp4_field__field_topic__openpublish_article($variables);
}

/**
 * Outputs Topic Taxonomy links for gallery nodes.
 */
function tp4_field__field_topic__video_playlist($variables) {
    return tp4_field__field_topic__openpublish_article($variables);
}

/**
 * Outputs free tag taxonomy links for gallery nodes.
 */
function tp4_field__field_free_tag__video_playlist($variables) {
    return tp4_field__field_topic__openpublish_article($variables);
}

function tp4_menu_link(array $variables) {
    if ($variables['element']['#theme'] == 'menu_link__menu_megamenu') {
        $variables['element']['#attributes']['data-mlid'][] = $variables['element']['#original_link']['mlid'];
    }
    return theme_menu_link($variables);
}

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

function tp4_field__field_article_subhead__feature_article($variables) {
    return tp4_field__field_article_subhead__openpublish_article($variables);
}

function tp4_field__field_article_subhead__video($variables) {
    return tp4_field__field_article_subhead__openpublish_article($variables);
}

function tp4_field__field_article_subhead__video_playlist($variables) {
    return tp4_field__field_article_subhead__openpublish_article($variables);
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
 *	Copying code from above to allow flashcard to have captions
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

function tp4_field__field_article_main_image__feature_article($variables) {
    $output = '';

    foreach ($variables['items'] as $delta => $item) {

        // set up some variables we're going to need.
        $image = array();
        $image['path'] = $item['#file']->uri;
        $image['width'] = '980';
        $image['style_name'] = 'feature_article_hero';
        $image['attributes'] = array();
        $image['attributes']['itemprop'] = 'image';

        // TODO: do this through drupal APIs
        $image['alt'] = $item['#file']->field_media_alt['und'][0]['safe_value'];

        // The caption field is not shown on the default file display mode.
        // TODO: Make it available on a display mode.
        $caption_items = field_get_items('file', $item['#file'], 'field_media_caption');
        $item['field_media_caption'] = field_view_value('file', $item['#file'], 'field_media_caption', $caption_items[0]);
        $item['field_media_caption']['#label_display'] = 'hidden';

        $output .= '<figure ' . $variables['item_attributes'][$delta] . '>';
        $output .= theme('image_style', $image);
        $output .= '<figcaption>';
        $output .= drupal_render($item['field_media_caption']);
        $output .= '</figcaption></figure>';
    }
    $output = '<div class="' . $variables['classes'] . '"' . $variables['attributes'] . '>' . $output . '</div>';
    return $output;
}

function tp4_field__field_video__video($variables) {
    $output = '';

    foreach ($variables['items'] as $delta => $item) {
        $output .= '<figure ' . $variables['item_attributes'][$delta] . '>';
        $output .= render($item);
        //$caption = $item['#item']['field_media_caption']['und'][0]['value'];
        if (!empty($caption)) {
            $output .= '<figcaption>' . $caption . '</figcaption>';
        }
        $output .= '</figure>';
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
			/* This is so dirty I need a bath */
			drupal_add_css('html{overflow: hidden;}', array('type' => 'inline'));
		}
	}
}
