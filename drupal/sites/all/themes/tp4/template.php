<?php

/**
 * @file
 * Contains the theme's functions to manipulate Drupal's default markup.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728096
 */
/**
 * Override or insert variables into the maintenance page template.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("maintenance_page" in this case.)
 */
/* -- Delete this line if you want to use this function
  function STARTERKIT_preprocess_maintenance_page(&$variables, $hook) {
  // When a variable is manipulated or added in preprocess_html or
  // preprocess_page, that same work is probably needed for the maintenance page
  // as well, so we can just re-use those functions to do that work here.
  STARTERKIT_preprocess_html($variables, $hook);
  STARTERKIT_preprocess_page($variables, $hook);
  }
  // */

/**
 * Override or insert variables into the html templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("html" in this case.)
 */
function tp4_preprocess_html(&$variables, $hook) {
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
    $campaign_types = variable_get('card_types');
    $campaign_types[] = 'campaign_page';
    if (isset($node) && in_array($node->type, $campaign_types)) {
      $variables['use_production_dtm'] = variable_get('use_production_dtm', FALSE);
      $variables['use_development_dtm'] = variable_get('use_production_dtm', FALSE) ? FALSE : TRUE;
    }
    else {
      $variables['use_production_dtm'] = FALSE;
      $variables['use_development_dtm'] = FALSE;
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

function tp4_campaign_megamenu($nid){
	
  
  $campaign = node_load($nid);		

  /* Parent Menu */

  $mega_tree = menu_tree_all_data('menu-'.$campaign->field_campaign_menu['und'][0]['value'], $link = NULL, $max_depth = 1);
  menu_tree_add_active_path($mega_tree);
  $parent_menu = drupal_render(menu_tree_output($mega_tree));
  
  /* Child Block*/
  $mega_tree = menu_tree_all_data('menu-'.$campaign->field_campaign_menu['und'][0]['value'], $link = NULL, $max_depth = 2);
  $output = '';
  $output .= '<ul>';
  foreach($mega_tree as $key => $link){
    $output .= '<li class="mega-item '. $link['link']['mlid']. '">';
    $path = drupal_get_path_alias($mega_tree[$key]['link']['link_path']);
    $output .= '<div class="title">'. l($mega_tree[$key]['link']['link_title'], $path, array('fragment' => $mega_tree[$key]['link']['localized_options']['attributes']['rel'], 'attributes' => array('class' => array($link['link']['options']['attributes']['class'][0])))). '</div>';
    $output .= '<div class="mega-content">';
    //left menu curation
    $menu = render(menu_tree_output($mega_tree[$key]['below']));
    $output .= '<div class="side-menu">';
    if($link['link']['options']['attributes']['title']){
      $output .= '<div class="text">'. $link['link']['options']['attributes']['title']. '</div>';
    }
    $output .= $menu;
    $output .= '</div>';


    //middle content curation
    $url = current(explode("/", $link['link']['href']));
    if($url != 'taxonomy' && $url != 'node'){
      $url = drupal_lookup_path("source", $link['link']['href']);
      $url = current(explode("/", $url));
    }
    if($url == 'taxonomy'){
      $entities = menu_get_object('taxonomy_term', 2, $link['link']['href']);
    }
    elseif($url == 'node'){
      $entities = menu_get_object('node', 1, $link['link']['href']);
    }
    else{
      // url is not a node or taxonomy
    }





    $output .= '<div class="categories">';;
    if(isset($entities->field_promo_content_collection['und']) && isset($url)){  
      foreach($entities->field_promo_content_collection['und'] as $key => $entity){
        $field_collection = entity_load('field_collection_item', array($entity['value']));
        $field_collection = current($field_collection);
        $nid = $field_collection->field_promo_content['und'][0]['target_id']; //TODO Change promo content to a single value
        $node = node_load($nid);

        global $base_url;
        $node_path = drupal_get_path_alias('node/'. $node->nid);

        //Subcategory content menu item is linked to a taxonomy term
        if($url == 'taxonomy'){
          $term = $node->field_topic['und'][0]['tid'];
          $term = taxonomy_term_load($term);
          //Subcategory content for menu items with the ID of 'series' (example: Features & Columns)
          if(isset($link['link']['options']['attributes']['id']) && $link['link']['options']['attributes']['id'] == 'series'){
            $thumb = file_load($node->field_thumbnail['und'][0]['fid']);
            $thumb = '<img src="'. image_style_url('homepage_featured_image', $thumb->uri). '">';
            $author_node = node_load($node->field_author['und'][0]['nid']);
            $series_term = taxonomy_term_load($node->field_series['und'][0]['tid']);
            $text = '<div class="author">'. $author_node->title. '</div>'. $node->field_promo_headline['und'][0]['value'];  //author and promo_headline
            $label = $series_term->name;
            $label_path = drupal_get_path_alias('taxonomy/term/'. $series_term->tid);
          }
          else{
            $thumb = file_load($node->field_thumbnail['und'][0]['fid']);
            $thumb = '<img src="'. image_style_url('homepage_featured_image', $thumb->uri). '">';
            $text = $node->field_promo_headline['und'][0]['value'];
            $label = $term->name;
            $label_path = drupal_get_path_alias('taxonomy/term/'. $term->tid);
          }
        }
        //Subcategory content menu item is linked to a node
        else{
          if(isset($link['link']['options']['attributes']['id']) && $link['link']['options']['attributes']['id'] == 'action'){
            $thumb = file_load($node->field_action_main_image['und'][0]['fid']);
            $thumb = '<img src="'. image_style_url('homepage_featured_image', $thumb->uri). '">';
            $label = taxonomy_term_load($node->field_action_type['und'][0]['tid']);
            $label = $label->name;
            if($node->type == 'petition_action' || $node->type == 'pledge_action'){
              $text = $node->title;
            }
            else{
              $text = $node->field_tab_call_to_action['und'][0]['value'];
            }
          }
          else{
            $thumb = file_load($node->field_thumbnail['und'][0]['fid']);
            $thumb = '<img src="'. image_style_url('homepage_featured_image', $thumb->uri). '">';
            $label = $node->title;
            $text = $node->field_promo_headline['und'][0]['value'];
          }
        }
        
        //Check for overrides
        $label = (isset($field_collection->field_promo_label['und'][0]['value']) ? $field_collection->field_promo_label['und'][0]['value'] : $label);
        $text = (isset($field_collection->field_promo_headline['und'][0]['value']) ? $field_collection->field_promo_headline['und'][0]['value'] : $text);
        if(isset($field_collection->field_promo_thumbnail['und'][0]['fid'])){
          $thumb = file_load($field_collection->field_promo_thumbnail['und'][0]['fid']);
          $thumb = '<img src="'. image_style_url('homepage_featured_image', $thumb->uri). '">';
        }

        //Output subcategories based on input from menu link ID field
        $output .= '<a href="'. $base_url. '/'. $node_path. '" class="sub-category">';
        $output .= '<div class="thumb">'. $thumb. '</div>';
        $output .= '<div class="label">'. $label. '</div>';
        $output .= '<div class="text">'. $text. '</div>';
        $output .= '</a>'; //end .sub-category

      }
      $output .= '</div>'; //end .categories
      //return more link
      if(isset($link['link']['options']['attributes']['name'])){
        $output .= l($link['link']['options']['attributes']['name'], $path, array('attributes' => array('class' => array('more'))));
      }
      else{
        $output .= l('See More '. $link['link']['link_title'], $path, array('attributes' => array('class' => array('more'))));
      }
    }
    $output .= '</div>'; //end .mega-content
    $output .= '</li>'; //end .mega-item
  }
  $output .= '</ul>';

  return $output;
  
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

    $campaign_nid = $variables['node']->field_campaign_reference['und'][0]['target_id'];
	$variables['campaign_menu'] = tp4_campaign_megamenu($campaign_nid);
			
			
				
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
    if (!empty($variables['node']) && in_array($variables['node']->type, array('openpublish_article', 'feature_article', 'openpublish_photo_gallery', 'video'))) {
        $variables['title'] = '';
    }

  // add Taboola JS if we're on an article, feature or photo gallery page
  // but only if we're on the production site: variable_get('environment', 'dev') == 'prod' &&
  if (variable_get('environment', 'dev') === 'prod' && !empty($variables['node']) && in_array($variables['node']->type, array('openpublish_article', 'feature_article', 'openpublish_photo_gallery', 'video'))) {
    drupal_add_js(drupal_get_path('theme', 'tp4') . '/js/taboola.js', 'file');
    drupal_add_js('window._taboola = window._taboola || []; _taboola.push({flush:true});', array('type' => 'inline', 'scope' => 'footer'));
  }
  $card_types = variable_get('card_types');
  if(in_array($variables['node']->type, $card_types) == true){
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

    if(isset($campaign_ref->field_promo_headline['und'][0]['value']) == true){
      $variables['promo_title'] = $campaign_ref->field_promo_headline['und'][0]['value'];
    }else{
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
    if (in_array($variables['type'], array('openpublish_video', 'video')) && $variables['view_mode'] == 'full') {
        $variables['theme_hook_suggestions'][] = 'node__openpublish_article__full';
    }

  // Add template variables for the local node url
  // (for compatability in dev/qa environments)
  // and for the url to the same node on production
  // (for facebook plugins and whatnot)
  $variables['url_local'] = url('node/' . $variables['nid'], array('absolute' => TRUE));
  $variables['url_production'] = 'http://www.takepart.com' . url('node/' . $variables['nid']);

  // Run node-type-specific preprocess functions, like
  // tp4_preprocess_node__page() or tp4_preprocess_node__story().
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

	$campaign_trays = count($variables['field_campaign_tray']);
	
	for($i=0; $i < $campaign_trays; $i++){
		
		$campaign_tray = node_load($variables['field_campaign_tray'][$i]['target_id']);

		if(!empty($campaign_tray->field_campaign_tray_title_color['und'][0]['rgb'])){
			$campaign_tray->field_campaign_tray_title['und'][0]['value'] = '<span style ="color:'.$campaign_tray->field_campaign_tray_title_color['und'][0]['rgb'].'">'.$campaign_tray->field_campaign_tray_title['und'][0]['value'].'</font>';
		}
		
		$campaign_card = node_load($campaign_tray->field_campaign_card_reference['und'][0]['target_id']);
		$card_color_scheme = $campaign_card->field_card_color_scheme['und'][0]['value']; // color 1	
		
		// Array of campaign color schemes
		$color_schemes = $campaign_node->field_color_scheme['und'];
	
		foreach ($color_schemes as $field_collection) {
		  $color_scheme = field_collection_item_load($field_collection['value']);
		  // If card color scheme exists in campaign color scheme then inherit the value	
		  if($color_scheme->field_color_scheme_name['und'][0]['value'] == $card_color_scheme)
		  {
			$card_new_font_color = $color_scheme->field_color_scheme_font_color['und'][0]['rgb'];
			
			//$card_new_background = $color_scheme->field_color_scheme_background['und'][0]['rgb'];
			//if(!empty($card_new_background)){
				// Apply the background from color scheme
				//$campaign_card->field_campaign_bg_color['und'][0]['rgb'] = $card_new_background;
			//}

			if(!empty($card_new_font_color)){
				// Add font color to variables
				$campaign_card->field_card_color_scheme_font = $card_new_font_color;
			}
		  }
		  		  
		}
		
		
	}	
	//$campaign_card->field_campaign_bg_color['und'][0]['rgb'] = "#000000";
	
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
	
	// Check if campaign reference is not empty
	if($variables['field_campaign_reference']['und'][0]['target_id'] != ''){

		//Get field css
		$uri = $campaign_node->field_css['und'][0]['uri'];
		
		// If file exist, add the css file to the campaign page
		if (file_exists($uri)){
			  drupal_add_css($uri, array('group' => CSS_THEME, 'weight' => 999));
		}
	
	}
	
	
}

/**
 * Override or insert variables into the campaign card media template
 */
function tp4_preprocess_node__campaign_card_media(&$variables, $hook) {

  if($variables['field_campaign_media_photo'][0]['alt'] == ''){
  	$variables['field_campaign_media_photo'][0]['alt'] = $variables['title'];	
  }
  
  $alt =   $variables['field_campaign_media_photo'][0]['alt'];

  
  $column_count = $variables['field_campaign_media_col']['und'][0]['value'];
  $instructional = $variables['field_campaign_instructional'][0]['value'];
  $media_title = '';
  if(isset($variables['field_campaign_media_title'][0]['value']) == true){
    $media_title = '<h4 class="media-title">'. $variables['field_campaign_media_title'][0]['value']. '</h4>';
  }

  //Prepare Media
  if($variables['field_campaign_media_type'][0]['value'] == 1){  //Media is a video
    $media = $variables['field_campaign_media_video'];
    $media_node = node_load($variables['field_campaign_media_video'][0]['target_id']);
    $media = drupal_render(node_view($media_node, 'embed'));
  }
  else{ //Media is a photo

    $image = file_create_url($variables['field_campaign_media_photo'][0]['uri']);
    //Check if photo has a link
    if(isset($variables['field_campaign_media_image_link'][0]['url']) == true){
      $link = $variables['field_campaign_media_image_link'][0];
      $media = l('<img src="'. $image. '" alt="'.$alt.'">', $link['url'], array('html' => true, 'attributes' => array('target' => $link['attributes']['target'])));
    }
    else{
      $media .= '<img src="'. $image. '" alt="'.$alt.'">';
    }

  }
  //Set Layout
  if($column_count == 1 || $column_count == 2 || $column_count == 3){  // two column

    // 1:even, 2:left-large, 3:right-large
    if($column_count == 2){
      $variables['classes_array'][] = 'left-large';
    }
    elseif($column_count == 3){
      $variables['classes_array'][] = 'right-large';
    }


    if($variables['field_campaign_content_side'][0]['value'] == 0){ // Media goes on the left
      //Prepare the left side content
      $left = '';
      $left .= $media_title;
      $left .= $media;
      $left .= (isset($variables['field_campaign_media_caption'][0]['value']) ? '<div class="caption">'. $variables['field_campaign_media_caption'][0]['value']. '</div>' : '');

      $right = (isset($variables['body']['und'][0]['value']) ? '<div class="description">'. $variables['body']['und'][0]['value']. '</div>' : '');
    }
    else{  //media goes on the right
      $right = '';
      $right .= $media_title;
      $right .= $media;
      $right .= (isset($variables['field_campaign_media_caption'][0]['value']) ? '<div class="caption">'. $variables['field_campaign_media_caption'][0]['value']. '</div>' : '');

      $left = (isset($variables['body']['und'][0]['value']) ? '<div class="description">'. $variables['body']['und'][0]['value']. '</div>' : '');
    }

    $variables['theme_hook_suggestions'][] = 'node__campaign_card_2col';
  }
  elseif($column_count == 0){ //single column
    $center = '';
    $center .= $media_title;
    $center .= $media;
    $center .= (isset($variables['field_campaign_media_caption'][0]['value']) ? '<div class="caption">'. $variables['field_campaign_media_caption'][0]['value']. '</div>' : '');

    $center .= (isset($variables['body']['und'][0]['value']) ? '<div class="description">'. $variables['body']['und'][0]['value']. '</div>' : '');
    $variables['theme_hook_suggestions'][] = 'node__campaign_card_1col';
  }

  //Width and height variables
  $variables['styles'] = array();
  $variables['styles'][] = 'background-color: '. $variables['field_campaign_bg_color']['und'][0]['rgb']. ';';
  if(isset($variables['field_campaign_min_height']['und'][0]['value']) == true){
    $variables['styles'][] = 'min-height: '. $variables['field_campaign_min_height']['und'][0]['value']. 'px;';
  }
  if($variables['field_campaign_bgw']['und'][0]['value'] == 0){
    $variables['classes_array'][] = 'card-width-full';
  }
  else{
    $variables['classes_array'][] = 'card-width-980';
  }
  if($variables['field_campaign_bgw_image']['und'][0]['value'] == 0){
    $variables['styles'][] = 'background-size: 100%;';
  }
  else{
    $variables['styles'][] = 'background-size: 1000px;';
  }
  
  $variables['card_background'] = file_create_url($variables['field_campaign_background']['und'][0]['uri']);
  $variables['left'] = $left;
  $variables['right'] = $right;
  $variables['center'] = $center;
  $variables['instructional'] =  $instructional;

  // If color scheme is enabled add font color to major html tag inside the card
  if(!empty($variables['field_card_color_scheme'])){
    $variables['classes_array'][]  = 'color_scheme_'.$variables['nid'];
  	$campaign_style['style'] = 
  	'.color_scheme_'.$variables['nid'].', 
  	.color_scheme_'.$variables['nid'].' h1, 
  	.color_scheme_'.$variables['nid'].' h2, 
  	.color_scheme_'.$variables['nid'].' h3, 
  	.color_scheme_'.$variables['nid'].' h4, 
  	.color_scheme_'.$variables['nid'].' h5, 
  	.color_scheme_'.$variables['nid'].' h6, 
  	.color_scheme_'.$variables['nid'].' a,
  	.color_scheme_'.$variables['nid'].' p, 
  	.color_scheme_'.$variables['nid'].' label, 
  	.color_scheme_'.$variables['nid'].' ul, 
  	.color_scheme_'.$variables['nid'].' li,
  	.color_scheme_'.$variables['nid'].' th,
  	.color_scheme_'.$variables['nid'].' td
  	{ color: '. $variables['field_card_color_scheme_font']. '!important; }';
    
    drupal_add_css($campaign_style['style'], 
				  array(
				        'group' => CSS_THEME,
				        'type' => 'inline',
				        'media' => 'screen',
				        'preprocess' => FALSE,
				        'weight' => '9999',
				  ));
  }  

  
}




function tp4_preprocess_node__campaign_card_text(&$variables, $hook) {

  $column_count = $variables['field_campaign_media_col'][0]['value'];

  $instructional = $variables['field_campaign_instructional'][0]['value'];

  //Set Layout
  if($column_count == 1 || $column_count == 2 || $column_count == 3){  // two column

    // 1:even, 2:left-large, 3:right-large
    if($column_count == 2){
      $variables['classes_array'][] = 'left-large';
    }
    elseif($column_count == 3){
      $variables['classes_array'][] = 'right-large';
    }

    $left = (isset($variables['field_campaign_text_left'][0]['value']) ? '<div class="text">'. $variables['field_campaign_text_left'][0]['value']. '</div>' : '');
    $right = (isset($variables['field_campaign_text_right'][0]['value']) ? '<div class="text">'. $variables['field_campaign_text_right'][0]['value']. '</div>' : '');

    $variables['theme_hook_suggestions'][] = 'node__campaign_card_2col';
  }

  elseif($column_count == 0){ //single column
    $center = (isset($variables['field_campaign_text_left'][0]['value']) ? '<div class="text">'. $variables['field_campaign_text_left'][0]['value']. '</div>' : '');

    $variables['theme_hook_suggestions'][] = 'node__campaign_card_1col';
  }

  //Width and height variables
  $variables['styles'] = array();
  $variables['styles'][] = 'background-color: '. $variables['field_campaign_bg_color']['und'][0]['rgb']. ';';
  if(isset($variables['field_campaign_min_height']['und'][0]['value']) == true){
    $variables['styles'][] = 'min-height: '. $variables['field_campaign_min_height']['und'][0]['value']. 'px;';
  }
  if($variables['field_campaign_bgw']['und'][0]['value'] == 0){
    $variables['classes_array'][] = 'card-width-full';
  }
  else{
    $variables['classes_array'][] = 'card-width-980';
  }
  if($variables['field_campaign_bgw_image']['und'][0]['value'] == 0){
    $variables['styles'][] = 'background-size: 100%;';
  }
  else{
    $variables['styles'][] = 'background-size: 1000px;';
  }
  
  $variables['card_background'] = file_create_url($variables['field_campaign_background']['und'][0]['uri']);
  $variables['left'] = $left;
  $variables['right'] = $right;
  $variables['center'] = $center;
  $variables['instructional'] =  $instructional;
  
  // If color scheme is enabled add font color to major html tag inside the card
  if(!empty($variables['field_card_color_scheme'])){
    $variables['classes_array'][]  = 'color_scheme_'.$variables['nid'];
  	$campaign_style['style'] = 
  	'.color_scheme_'.$variables['nid'].', 
  	.color_scheme_'.$variables['nid'].' h1, 
  	.color_scheme_'.$variables['nid'].' h2, 
  	.color_scheme_'.$variables['nid'].' h3, 
  	.color_scheme_'.$variables['nid'].' h4, 
  	.color_scheme_'.$variables['nid'].' h5, 
  	.color_scheme_'.$variables['nid'].' h6, 
  	.color_scheme_'.$variables['nid'].' a,
  	.color_scheme_'.$variables['nid'].' p, 
  	.color_scheme_'.$variables['nid'].' label, 
  	.color_scheme_'.$variables['nid'].' ul, 
  	.color_scheme_'.$variables['nid'].' li,
  	.color_scheme_'.$variables['nid'].' th,
  	.color_scheme_'.$variables['nid'].' td
  	{ color: '. $variables['field_card_color_scheme_font']. '!important; }';
    
    drupal_add_css($campaign_style['style'], 
				  array(
				        'group' => CSS_THEME,
				        'type' => 'inline',
				        'media' => 'screen',
				        'preprocess' => FALSE,
				        'weight' => '9999',
				  ));
  } 

}


/**
 * Override or insert variables into the campaign card social template
 */
function tp4_preprocess_node__campaign_card_social(&$variables, $hook) {
  // social!
  $variables['theme_hook_suggestions'][] = 'node__campaign_card_1col';
  $instructional = $variables['field_campaign_instructional']['und'][0]['value'];

  $collections = array();
  foreach($variables['field_campaign_social_follow']['und'] as $key => $collection){
    $collections[] = $collection['value'];
  }
  $collections = entity_load('field_collection_item', $collections);
  $center = '';
  $center .= '<div class=social-follow>';
  foreach($collections as $key => $item){
    $tid = $item->field_social_network['und'][0]['target_id'];
    $taxonomy = entity_load('taxonomy_term', array($tid));
    $taxonomy = current($taxonomy);
    $name = $taxonomy->name;
    // $name = $item->field_social_network['und'][0]['entity']->name;
    $name = strtolower($name);
    $name = preg_replace("/[\s_]/", "-", $name);
    $url = $item->field_social_link['und'][0]['url'];

    $center .= l('', $url, array('html' => true, 'attributes' => array('target' => '_blank', 'class' => array($name, 'social-icon', 'tp-social-link'))));
  }
  $center .= '</div>';

  if(isset($variables['field_campaign_newsletter']['und'][0]['target_id']) == true){

    $block_id = $variables['field_campaign_newsletter']['und'][0]['target_id'];
    $block = block_load('newsletter_campaign',$block_id);
    $renderable_block =  _block_get_renderable_array(_block_render_blocks(array($block)));
    $center .= drupal_render($renderable_block);
  }
  if(isset($variables['field_campaign_sms']['und'][0]['value']) == true){
    $center .= '<div class="sms">'. $variables['field_campaign_sms']['und'][0]['value']. '</div>';

    //if legal override exists, print it, otherwise print the global copy
    if(isset($variables['field_campaign_sms_legal']['und'][0]['value']) == true){
      $sms_legal = $variables['field_campaign_sms_legal']['und'][0]['value'];
    }else{
      $sms_legal = variable_get('sms_legal', '');
    }
    $center .= '<div class="sms-legal">'. $sms_legal. '</div>';
  }

  //Width and height variables
  $variables['styles'] = array();
  $variables['styles'][] = 'background-color: '. $variables['field_campaign_bg_color']['und'][0]['rgb']. ';';
  if(isset($variables['field_campaign_min_height']['und'][0]['value']) == true){
    $variables['styles'][] = 'min-height: '. $variables['field_campaign_min_height']['und'][0]['value']. 'px;';
  }
  if($variables['field_campaign_bgw']['und'][0]['value'] == 0){
    $variables['classes_array'][] = 'card-width-full';
  }
  else{
    $variables['classes_array'][] = 'card-width-980';
  }
  if($variables['field_campaign_bgw_image']['und'][0]['value'] == 0){
    $variables['styles'][] = 'background-size: 100%;';
  }
  else{
    $variables['styles'][] = 'background-size: 1000px;';
  }
  $variables['card_background'] = file_create_url($variables['field_campaign_background']['und'][0]['uri']);
  $variables['center'] = $center;
  $variables['instructional'] =  $instructional;
  
  // If color scheme is enabled add font color to major html tag inside the card
  if(!empty($variables['field_card_color_scheme'])){
    $variables['classes_array'][]  = 'color_scheme_'.$variables['nid'];
  	$campaign_style['style'] = 
  	'.color_scheme_'.$variables['nid'].', 
  	.color_scheme_'.$variables['nid'].' h1, 
  	.color_scheme_'.$variables['nid'].' h2, 
  	.color_scheme_'.$variables['nid'].' h3, 
  	.color_scheme_'.$variables['nid'].' h4, 
  	.color_scheme_'.$variables['nid'].' h5, 
  	.color_scheme_'.$variables['nid'].' h6, 
  	.color_scheme_'.$variables['nid'].' a,
  	.color_scheme_'.$variables['nid'].' p, 
  	.color_scheme_'.$variables['nid'].' label, 
  	.color_scheme_'.$variables['nid'].' ul, 
  	.color_scheme_'.$variables['nid'].' li,
  	.color_scheme_'.$variables['nid'].' th,
  	.color_scheme_'.$variables['nid'].' td
  	{ color: '. $variables['field_card_color_scheme_font']. '!important; }';
    
    drupal_add_css($campaign_style['style'], 
				  array(
				        'group' => CSS_THEME,
				        'type' => 'inline',
				        'media' => 'screen',
				        'preprocess' => FALSE,
				        'weight' => '9999',
				  ));
  } 


}

/**
 * Implementation of hook_query_TAG_alter
 */
function tp4_query_filter_alter(QueryAlterableInterface $query) {
  $node = node_load();
  $tags = $query->alterMetaData['entity_field_query']->tags;
  $nid = array_slice($tags, 1, 1);
  $node = node_load($nid[0]);
  
  if(isset($node->field_campaign_news_filter_tag['und'][0]['target_id'])){
    $term_id = $node->field_campaign_news_filter_tag['und'][0]['target_id'];
    $query
      ->leftJoin('field_data_field_topic', 'a', 'node.nid = a.entity_id');
    $query
      ->leftJoin('field_data_field_series', 'b', 'node.nid = b.entity_id');
    $query
      ->leftJoin('field_data_field_free_tag', 'c', 'node.nid = c.entity_id');
    $or = db_or()
      ->condition('a.field_topic_tid', array($term_id), 'IN')
      ->condition('b.field_series_tid', array($term_id), 'IN')
      ->condition('c.field_free_tag_tid', array($term_id), 'IN');
    $query
      ->condition($or);
  }

}


/**
 * Override or insert variables into the campaign card news
 */
function tp4_preprocess_node__campaign_card_news(&$variables, $hook) {

    // Count the number of values
    $instructional = $variables['field_campaign_instructional'][0]['value'];
    $more = ''; //Add this to news and media
    $more = '<div class="more-link">'. $variables['field_campaign_more_link'][0]['value']. '</div>';



    if($variables['field_campaign_news_type'][0]['value'] == 0){  //single value

      $node = node_load($variables['field_campaign_single_news_ref'][0]['target_id']);

      $file = file_load($node->field_article_main_image['und'][0]['fid']);
      $image = file_create_url($file->uri);	  
      $image = image_style_url('campaign_news_3x2', $file->uri);
	  $alt = $node->title;
      $center = '';  // single news reference will use one column now
      $path = drupal_get_path_alias('node/'. $node->nid);
      $image = '<img src="'. $image. '" alt="'.$alt.'">';  //image
      $center .= l($image, $path, array('html' => true));
      $center .= '<h3 class="headline">'. l($node->field_promo_headline['und'][0]['value'], $path). '</h3>';  //headline
      $center .= '<p class="short-headline">'. $node->field_article_subhead['und'][0]['value']. '</p>';  //short headline
      $center .= $more;

      $variables['theme_hook_suggestions'][] = 'node__campaign_card_1col';
    }
    else{ //multivalue

      $variables['classes_array'][] = 'multi-news';
      $term_id = $variables['field_campaign_news_filter_tag'][0]['target_id'];

      $nids = array();
      foreach($variables['field_campaign_multi_news_ref'] as $key => $item){
        $nids[] = $item['target_id'];
      }

      // Query non referenced content (max 5)
      $max_count = $variables['field_campaign_news_count'][0]['value'] + 2;
      $count = count($variables['field_campaign_multi_news_ref']);

      if($max_count > $count) {
        $campaignNewsArticles = new EntityFieldQuery();
        $campaignNewsArticles->entityCondition('entity_type', 'node')
          ->entityCondition('bundle', array('openpublish_article', 'feature_article', 'article', 'openpublish_photo_gallery', 'video'))
          ->fieldCondition('field_thumbnail', 'fid', 0, '>')
          ->propertyCondition('status', 1)
          ->propertyOrderBy('created', 'DESC')
          ->addTag('filter')
          ->addTag($variables['nid'])
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

        $node_path = drupal_get_path_alias('node/'. $node->nid);
        $file = file_load($node->field_thumbnail['und'][0]['fid']);
        $image = file_create_url($file->uri);
        $image = image_style_url('campaign_news_3x2', $file->uri);
		$alt = $node->title;
        $media = '<img src="'. $image. '" alt="'.$alt.'">';
        $headline = $node->field_promo_headline['und'][0]['value'];
        $news_column = $media;
        $news_column .= '<h5>'. $headline. '</h5>';
        $center .= l($news_column, $node_path, array('html' => true, 'attributes' => array('class' => array('news-column'))));
      }
      $center .= '</div>';
      $center .= $more;
      $variables['theme_hook_suggestions'][] = 'node__campaign_card_1col';
    }

  //Width and height variables
  $variables['styles'] = array();
  $variables['styles'][] = 'background-color: '. $variables['field_campaign_bg_color']['und'][0]['rgb']. ';';
  if(isset($variables['field_campaign_min_height']['und'][0]['value']) == true){
    $variables['styles'][] = 'min-height: '. $variables['field_campaign_min_height']['und'][0]['value']. 'px;';
  }
  if($variables['field_campaign_bgw']['und'][0]['value'] == 0){
    $variables['classes_array'][] = 'card-width-full';
  }
  else{
    $variables['classes_array'][] = 'card-width-980';
  }
  if($variables['field_campaign_bgw_image']['und'][0]['value'] == 0){
    $variables['styles'][] = 'background-size: 100%;';
  }
  else{
    $variables['styles'][] = 'background-size: 1000px;';
  }

    $variables['card_background'] = file_create_url($variables['field_campaign_background']['und'][0]['uri']);
    $variables['instructional'] = $instructional;
    $variables['center'] = $center;
	
  // If color scheme is enabled add font color to major html tag inside the card
  if(!empty($variables['field_card_color_scheme'])){
    $variables['classes_array'][]  = 'color_scheme_'.$variables['nid'];
  	$campaign_style['style'] = 
  	'.color_scheme_'.$variables['nid'].', 
  	.color_scheme_'.$variables['nid'].' h1, 
  	.color_scheme_'.$variables['nid'].' h2, 
  	.color_scheme_'.$variables['nid'].' h3, 
  	.color_scheme_'.$variables['nid'].' h4, 
  	.color_scheme_'.$variables['nid'].' h5, 
  	.color_scheme_'.$variables['nid'].' h6, 
  	.color_scheme_'.$variables['nid'].' a,
  	.color_scheme_'.$variables['nid'].' p, 
  	.color_scheme_'.$variables['nid'].' label, 
  	.color_scheme_'.$variables['nid'].' ul, 
  	.color_scheme_'.$variables['nid'].' li,
  	.color_scheme_'.$variables['nid'].' th,
  	.color_scheme_'.$variables['nid'].' td
  	{ color: '. $variables['field_card_color_scheme_font']. '!important; }';
    
    drupal_add_css($campaign_style['style'], 
				  array(
				        'group' => CSS_THEME,
				        'type' => 'inline',
				        'media' => 'screen',
				        'preprocess' => FALSE,
				        'weight' => '9999',
				  ));
  } 


}
function tp4_preprocess_node__campaign_card_iframe(&$variables, $hook) {
  $instructional = $variables['field_campaign_instructional'][0]['value'];
  $center = '';
  $height = $variables['field_campaign_iframe_height'][0]['value'];
  $width = $variables['field_campaign_iframe_width'][0]['value'];
  if(isset($variables['field_campaign_iframe'][0]['value']) == true){
    if($variables['field_campaign_iframe_type'][0]['value'] == 1){
      $ratio = $height/$width * 100;
      $center .= '<div class="iframe-wrapper" style="padding-bottom: '. $ratio. '%;">';
      $center .= '<iframe src="'. $variables['field_campaign_iframe'][0]['value']. '"></iframe>';
      $center .= '</div>';
    }
    else{
      $variables['classes_array'][] = 'iframe-fixed';
      $center .= '<div class="iframe-wrapper-fixed">';
      $center .= '<iframe src="'. $variables['field_campaign_iframe'][0]['value']. '" height="'. $height. '" width="'. $width. '"></iframe>';
      $center .= '</div>';
    }

  }
  else{
    $variables['classes_array'][] = 'embed-field';
    $center .= '<div class="embed">'. $variables['body'][0]['value']. '</div>';
  }
  

  //Width and height variables
  $variables['styles'] = array();
  $variables['styles'][] = 'background-color: '. $variables['field_campaign_bg_color']['und'][0]['rgb']. ';';
  if(isset($variables['field_campaign_min_height']['und'][0]['value']) == true){
    $variables['styles'][] = 'min-height: '. $variables['field_campaign_min_height']['und'][0]['value']. 'px;';
  }
  if($variables['field_campaign_bgw']['und'][0]['value'] == 0){
    $variables['classes_array'][] = 'card-width-full';
  }
  else{
    $variables['classes_array'][] = 'card-width-980';
  }
  if($variables['field_campaign_bgw_image']['und'][0]['value'] == 0){
    $variables['styles'][] = 'background-size: 100%;';
  }
  else{
    $variables['styles'][] = 'background-size: 1000px;';
  }
  $variables['card_background'] = file_create_url($variables['field_campaign_background']['und'][0]['uri']);
  $variables['instructional'] = $instructional;
  $variables['center'] = $center;
  $variables['theme_hook_suggestions'][] = 'node__campaign_card_1col';
  
  // If color scheme is enabled add font color to major html tag inside the card
  if(!empty($variables['field_card_color_scheme'])){
    $variables['classes_array'][]  = 'color_scheme_'.$variables['nid'];
  	$campaign_style['style'] = 
  	'.color_scheme_'.$variables['nid'].', 
  	.color_scheme_'.$variables['nid'].' h1, 
  	.color_scheme_'.$variables['nid'].' h2, 
  	.color_scheme_'.$variables['nid'].' h3, 
  	.color_scheme_'.$variables['nid'].' h4, 
  	.color_scheme_'.$variables['nid'].' h5, 
  	.color_scheme_'.$variables['nid'].' h6, 
  	.color_scheme_'.$variables['nid'].' a,
  	.color_scheme_'.$variables['nid'].' p, 
  	.color_scheme_'.$variables['nid'].' label, 
  	.color_scheme_'.$variables['nid'].' ul, 
  	.color_scheme_'.$variables['nid'].' li,
  	.color_scheme_'.$variables['nid'].' th,
  	.color_scheme_'.$variables['nid'].' td
  	{ color: '. $variables['field_card_color_scheme_font']. '!important; }';
    
    drupal_add_css($campaign_style['style'], 
				  array(
				        'group' => CSS_THEME,
				        'type' => 'inline',
				        'media' => 'screen',
				        'preprocess' => FALSE,
				        'weight' => '9999',
				  ));
  } 

}
function tp4_preprocess_node__campaign_card_branding(&$variables, $hook) {
  $center = '';
  //content of the page

  $tid = $variables['field_campaign_branding_category']['und'][0]['tid'];
  $campaign_category = taxonomy_term_load($tid);
  if(isset($campaign_category->field_campaign_category_image['und'][0]['uri']) == true){
    $url = file_create_url($campaign_category->field_campaign_category_image['und'][0]['uri']);
    $image .= '<img src="'. $url. '">';
    $center .= '<div class="branding-content">';
    $center .= '<div class="branding-text">'. $campaign_category->field_campaign_branding_text['und'][0]['value']. '</div>';
    if(isset($campaign_category->field_campaign_branding_url['und'][0]['url']) == true){
      $branding_url = $campaign_category->field_campaign_branding_url['und'][0]['url'];
      $target = $campaign_category->field_campaign_branding_url['und'][0]['attributes']['target'];
      $center .= l($image, $branding_url, array('html' => true, 'attributes' => array('target' => $target)));
    }
    else{
      $center .= $image;
    }
    $center .= '</div>';
    
  }

  //Width and height variables
  $variables['styles'] = array();
  $variables['styles'][] = 'background-color: '. $variables['field_campaign_bg_color']['und'][0]['rgb']. ';';
  if(isset($variables['field_campaign_min_height']['und'][0]['value']) == true){
    $variables['styles'][] = 'min-height: '. $variables['field_campaign_min_height']['und'][0]['value']. 'px;';
  }
  if($variables['field_campaign_bgw']['und'][0]['value'] == 0){
    $variables['classes_array'][] = 'card-width-full';
  }
  else{
    $variables['classes_array'][] = 'card-width-980';
  }
  if($variables['field_campaign_bgw_image']['und'][0]['value'] == 0){
    $variables['styles'][] = 'background-size: 100%;';
  }
  else{
    $variables['styles'][] = 'background-size: 1000px;';
  }
  $variables['card_background'] = file_create_url($variables['field_campaign_background']['und'][0]['uri']);
  $variables['instructional'] = $instructional;
  $variables['center'] = $center;
  $variables['theme_hook_suggestions'][] = 'node__campaign_card_1col';

  // If color scheme is enabled add font color to major html tag inside the card
  if(!empty($variables['field_card_color_scheme'])){
    $variables['classes_array'][]  = 'color_scheme_'.$variables['nid'];
  	$campaign_style['style'] = 
  	'.color_scheme_'.$variables['nid'].', 
  	.color_scheme_'.$variables['nid'].' h1, 
  	.color_scheme_'.$variables['nid'].' h2, 
  	.color_scheme_'.$variables['nid'].' h3, 
  	.color_scheme_'.$variables['nid'].' h4, 
  	.color_scheme_'.$variables['nid'].' h5, 
  	.color_scheme_'.$variables['nid'].' h6, 
  	.color_scheme_'.$variables['nid'].' a,
  	.color_scheme_'.$variables['nid'].' p, 
  	.color_scheme_'.$variables['nid'].' label, 
  	.color_scheme_'.$variables['nid'].' ul, 
  	.color_scheme_'.$variables['nid'].' li,
  	.color_scheme_'.$variables['nid'].' th,
  	.color_scheme_'.$variables['nid'].' td
  	{ color: '. $variables['field_card_color_scheme_font']. '!important; }';
    
    drupal_add_css($campaign_style['style'], 
				  array(
				        'group' => CSS_THEME,
				        'type' => 'inline',
				        'media' => 'screen',
				        'preprocess' => FALSE,
				        'weight' => '9999',
				  ));
  } 

}
function tp4_preprocess_node__campaign_card_empty(&$variables, $hook) {
  $image = file_create_url($variables['field_campaign_background']['und'][0]['uri']);
  $center = '<img src="'. $image. '">';
  //Width and height variables
  $variables['styles'] = array();
  $variables['styles'][] = 'background-color: '. $variables['field_campaign_bg_color']['und'][0]['rgb']. ';';
  if(isset($variables['field_campaign_min_height']['und'][0]['value']) == true){
    $variables['styles'][] = 'min-height: '. $variables['field_campaign_min_height']['und'][0]['value']. 'px;';
  }
  if($variables['field_campaign_bgw_image']['und'][0]['value'] == 0){
    $variables['classes_array'][] = 'card-image-width-full';
  }
  if($variables['field_campaign_bgw']['und'][0]['value'] == 0){
    $variables['classes_array'][] = 'card-width-full';
  }
  else{
    $variables['classes_array'][] = 'card-width-980';
  }
  if($variables['field_campaign_bgw_image']['und'][0]['value'] == 0){
    $variables['styles'][] = 'background-size: 100%;';
  }
  else{
    $variables['styles'][] = 'background-size: 1000px;';
  }
  $variables['card_background'] = file_create_url($variables['field_campaign_background']['und'][0]['uri']);
  $variables['instructional'] = $instructional;
  $variables['center'] = $center;
  $variables['theme_hook_suggestions'][] = 'node__campaign_card_1col';
  
  // If color scheme is enabled add font color to major html tag inside the card
  if(!empty($variables['field_card_color_scheme'])){
    $variables['classes_array'][]  = 'color_scheme_'.$variables['nid'];
  	$campaign_style['style'] = 
  	'.color_scheme_'.$variables['nid'].', 
  	.color_scheme_'.$variables['nid'].' h1, 
  	.color_scheme_'.$variables['nid'].' h2, 
  	.color_scheme_'.$variables['nid'].' h3, 
  	.color_scheme_'.$variables['nid'].' h4, 
  	.color_scheme_'.$variables['nid'].' h5, 
  	.color_scheme_'.$variables['nid'].' h6, 
  	.color_scheme_'.$variables['nid'].' a,
  	.color_scheme_'.$variables['nid'].' p, 
  	.color_scheme_'.$variables['nid'].' label, 
  	.color_scheme_'.$variables['nid'].' ul, 
  	.color_scheme_'.$variables['nid'].' li,
  	.color_scheme_'.$variables['nid'].' th,
  	.color_scheme_'.$variables['nid'].' td
  	{ color: '. $variables['field_card_color_scheme_font']. '!important; }';
    
    drupal_add_css($campaign_style['style'], 
				  array(
				        'group' => CSS_THEME,
				        'type' => 'inline',
				        'media' => 'screen',
				        'preprocess' => FALSE,
				        'weight' => '9999',
				  ));
  } 

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

        // ad "TakePart Features" branding
        $variables['title_prefix'][] = array(
            '#theme' => 'link',
            '#text' => 'TakePart Features',
            '#path' => 'taxonomy/term/114900',
            '#options' => array(
                'attributes' => array('class' => array('takepart-features-branding', $variables['field_title_color'][LANGUAGE_NONE][0]['value'])),
                'html' => FALSE,
            ),
        );

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
            $url = !empty($topic->field_topic_box_link) ? url($topic->field_topic_box_link['und'][0]['url'], array('absolute' => TRUE)) : '';
            $variables['field_topic_box_top'] = empty($url) ? $image : l($image, $url, array('html' => true));
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
        $created = $variables['created'];

        // find the next article, if any
        // (if it doesn't exist, $next will be an empty array)
        $seriesQueryNext = new EntityFieldQuery();
        $seriesQueryNext->entityCondition('entity_type', 'node')
                ->entityCondition('bundle', array('openpublish_article', 'feature_article', 'video'))
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
                ->entityCondition('bundle', array('openpublish_article', 'feature_article', 'video'))
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
        $series_nav .= $series_image;

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
            $output .= '<figcaption>' . $caption . '</figure>';
        }
    }

    $output = '<div class="' . $variables['classes'] . '"' . $variables['attributes'] . '>' . $output . '</div>';
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

                        if ($node->type == 'openpublish_article' || $node->type == 'feature_article' || $node->type == 'video' || $node->type == 'campaign' || $node->type == 'campaign_page') {
                            $main_image = field_get_items('node', $node, 'field_thumbnail');
                        }
                        if ($node->type == 'action') {
                            $main_image = field_get_items('node', $node, 'field_action_main_image');
                        }
                        if ($node->type == 'openpublish_photo_gallery') {
                            $main_image = field_get_items('node', $node, 'field_thumbnail');
                            if ($main_image == NULL) {
                                $main_image = field_get_items('node', $node, 'field_gallery_images');
                            }
                        }
                        if ($node->type == 'openpublish_video') {
                            $main_image = field_get_items('node', $node, 'field_thumbnail');
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
        if ($variables['content']['#bundle'] == 'video') {
            $variables['title_attributes_array']['class'][] = 'no-overlap';
            $variables['title_link'] = url('node/' . $variables['content']['#node']->nid);
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








