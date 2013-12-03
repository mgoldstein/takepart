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
/* -- Delete this line if you want to use this function
function STARTERKIT_preprocess_html(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');

  // The body tag's classes are controlled by the $classes_array variable. To
  // remove a class from $classes_array, use array_diff().
  //$variables['classes_array'] = array_diff($variables['classes_array'], array('class-to-remove'));
}
// */

/**
 * Override or insert variables into the page templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("page" in this case.)
 */
function tp4_preprocess_page(&$variables) {
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
  if (!empty($variables['node']) && in_array($variables['node']->type, array('openpublish_article', 'feature_article'))) {
    $variables['title'] = '';
  }

  // add Taboola JS if we're on an article or photo gallery page
  if (!empty($variables['node']) && in_array($variables['node']->type, array('openpublish_article', 'openpublish_photo_gallery'))) {
    drupal_add_js(drupal_get_path('theme', 'tp4') . '/js/taboola.js', 'file');
    drupal_add_js('window._taboola = window._taboola || []; _taboola.push({flush:true});', array('type' => 'inline', 'scope' => 'footer'));
  }
}

/**
 * Override or insert variables into block templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 */
function tp4_preprocess_block(&$variables) {
  $variables['title_attributes_array']['class'][] = 'section-header';
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
  $variables['theme_hook_suggestions'][] = 'node__' . $variables['type'] . '__' . $vars['view_mode'];
  if($variables['type'] == 'openpublish_video' && $variables['view_mode'] == 'full'){
    $variables['theme_hook_suggestions'][] = 'node__openpublish_article__full';
  }
  
  // Add template variables for the local node url
  // (for compatability in dev/qa environments)
  // and for the url to the same node on production
  // (for facebook plugins and whatnot)
  $variables['url_local'] = url('node/' . $variables['nid'], array('absolute' => TRUE));
  $variables['url_production'] = 'http://www.takepart.com' . url('node/' . $variables['nid']);

  // Run node-type-specific preprocess functions, like
  // tp4_preprocess_node_page() or tp4_preprocess_node_story().
  $function = __FUNCTION__ . '__' . $variables['node']->type;
  if (function_exists($function)) {
    $function($variables, $hook);
  }
}

/**
 * Override or insert variables into the openpublish_article template.
 */
function tp4_preprocess_node__openpublish_article(&$variables, $hook) {

  // expose series tid in a data attribute on article.node
  $series = taxonomy_term_load($variables['field_series'][LANGUAGE_NONE][0]['tid']);
  if ($series) {
    $variables['attributes_array']['data-series'] = $series->name;
  }

  // we're going to do some things only on the full view of an article
  if($variables['view_mode'] == 'full'){
    // provide "on our radar" block
    $variables['on_our_radar'] = module_invoke('bean', 'block_view', 'on-our-radar-block');

    // provide topic box
    if (!empty($variables['field_topic_box'])) {
      $topic = taxonomy_term_load($variables['field_topic_box']['und'][0]['tid']);
      if (!empty($topic->field_topic_box_image['und'][0]['uri'])) {
	$image = theme('image', array('path' => $topic->field_topic_box_image['und'][0]['uri']));
	$url = !empty($topic->field_topic_box_link) ? url($topic->field_topic_box_link['und'][0]['url'], array('absolute' => TRUE)) : '';
	$variables['field_topic_box_top'] = empty($url) ? $image : l($image, $url, array('html' => true));
      }
    }

    // provide a series prev/next nav if a series exists
    if(!empty($variables['field_series'])){
      $series = taxonomy_term_load($variables['field_series']['und'][0]['tid']);
      $series_image = theme('image', array('path' => $series->field_series_graphic_header['und'][0]['uri']));
      $created = $variables['created'];

      // find the next article, if any
      // (if it doesn't exist, $next will be an empty array)
      $seriesQueryNext = new EntityFieldQuery();
      $seriesQueryNext->entityCondition('entity_type', 'node')
              ->entityCondition('bundle', 'openpublish_article')
              ->propertyCondition('status', 1)
              ->propertyCondition('created', $created, '>')
              ->fieldCondition('field_series', 'tid', $series->tid, '=')
              ->propertyOrderBy('created', 'ASC')
              ->range(0,1);
      $next = $seriesQueryNext->execute();
      if (!empty($next)) {
            $next = current($next['node']);
            $next = node_load($next->nid);
            $next_url = drupal_get_path_alias('node/'. $next->nid);
      }

      // find the previous article, if any
      // (if it doesn't exist, $previous will be an empty array)
      $seriesQueryPrev = new EntityFieldQuery();
      $seriesQueryPrev->entityCondition('entity_type', 'node')
              ->entityCondition('bundle', 'openpublish_article')
              ->propertyCondition('status', 1)
              ->propertyCondition('created', $created, '<')
              ->fieldCondition('field_series', 'tid', $series->tid, '=')
              ->propertyOrderBy('created', 'DESC')
              ->range(0,1);
      $previous = $seriesQueryPrev->execute();
      if (!empty($previous)) {
            $previous = current($previous['node']);
            $previous = node_load($previous->nid);
            $previous_url = drupal_get_path_alias('node/'. $previous->nid);
      }

      // build up the series nav div
      $series_nav = '';
      $series_nav .= $series_image;

      // weird ternary operators will hide nav elements if they don't exist
      $series_nav .= empty($previous) ? '' : '<div class="more-prev">' . l("previous", $previous_url) . '</div>';
      $series_nav .= empty($next) ? '' : '<div class="more-next">' . l('next', $next_url) . '</div>';

      if (!empty($previous)) {
            $previous = '<div class="previous">'. (isset($previous->field_promo_headline['und'][0]['value']) ? $previous->field_promo_headline['und'][0]['value'] : drupal_render($previous->title)). '</div>';
            $series_nav .= l($previous, $previous_url, array('html' => true));
      }
      if (!empty($next)) {
            $next = '<div class="next">'. (isset($next->field_promo_headline['und'][0]['value']) ? $next->field_promo_headline['und'][0]['value'] : $next->title). '</div>';
            $series_nav .= l($next, $next_url, array('html' => true));
      }

      $variables['series_nav'] = $series_nav;
    } // if isset($variables['field_series'])

  } // if ($variables['view_mode'] == 'full')
}

/**
 * Final preparation of node template data for display.
 */
function tp4_process_node(&$variables, $hook) {
  // Run node-type-specific process functions, like
  // tp4_process_node_page() or tp4_process_node_story().
  $function = __FUNCTION__ . '__' . $variables['node']->type;
  if (function_exists($function)) {
    $function($variables, $hook);
  }
}

function tp4_process_node__openpublish_article(&$variables) {
  
  $variables['author_bios'] = array();
  foreach ($variables['field_author'] as $author) {
    $author_node = node_load($author['nid']);
    $variables['author_bios'][] = $author_node;
  }
}

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
/* -- Delete this line if you want to use this function
function STARTERKIT_preprocess_region(&$variables, $hook) {
  // Don't use Zen's region--sidebar.tpl.php template for sidebars.
  //if (strpos($variables['region'], 'sidebar_') === 0) {
  //  $variables['theme_hook_suggestions'] = array_diff($variables['theme_hook_suggestions'], array('region__sidebar'));
  //}
}
// */

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
  // not sure this is the best way to test for the field type
  if ('field-author' == $variables['field_name_css']) {
    $variables['classes_array'][] = 'author';
  }
}


/**
 * Outputs Free Tag Taxonomy Links for Article Nodes
 */
function tp4_field__field_topic__openpublish_article($variables) {
  $output = '';

  foreach ($variables['items'] as $item) {
    $output .= '<li>' . drupal_render($item) . '</li>';
  }

  return $output;
}

/**
 * Outputs topic taxonomy links for article nodes.
 */
function tp4_field__field_free_tag__openpublish_article($variables) {
  return tp4_field__field_topic__openpublish_article($variables);
}

function tp4_menu_link(array $variables) {
  if($variables['element']['#theme'] == 'menu_link__menu_megamenu'){
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
    $output .= ($number_of_authors > 2 && $delta < $number_of_authors - 2 ) ? ', ' :'';
    // add 'and' for lists of 2 or greater ($delta is zero-indexed)
    $output .= ($number_of_authors > 1 && $delta == $number_of_authors - 2 ) ? ' and ' :'';
  }
  $output .= '</span>';

  // Render the top-level div.
  $output = '<div class="byline ' . $variables['classes'] . '"' . $variables['attributes'] . '>By ' . $output . '</div>';

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
  $output = '<h2 class="' . $variables['classes'] . '"' . $variables['attributes'] . '>' . $output . '</h2>';

  return $output;
}



function tp4_field__field_article_main_image__openpublish_article($variables) {
  $output = '';

  foreach ($variables['items'] as $delta => $item) {

    // set up some variables we're going to need.
    $image = array();
    $image['path'] = $item['#file']->uri;

    // pick out the image style, defaulting to landscape
    $image['style_name'] = 'landscape_main_image';
    if ($item['#view_mode'] == 'portrait') $image['style_name'] = 'portrait_main_image';

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
 * Implements template_preprocess_entity().
 *
 * This is legacy code from chunkpart to make the "more on our site" bean work
 */
function tp4_preprocess_entity(&$variables, $hook) {

  $variables["custom_render"] = array();

  switch ($variables['entity_type']) {
    case "bean":
      if ($variables['bean']->{'type'} == "of_the_day") {
	//Look for a tpl file called bean--of-the-day-custom.tpl.php:
	$variables['theme_hook_suggestions'][] = 'bean__of_the_day_custom';

	for ($i = 0; $i <= sizeof($variables['elements']['field_listing_collection']); $i++) {
	  $listing = $variables['elements']['field_listing_collection'][$i];
	  $collection = $listing['entity']['field_collection_item'];

	  foreach ($collection as $key => $collectiondata) {

	    $acnid = $collectiondata['field_associated_content']['#items'][0]['nid'];
	    $node  = node_load($acnid);

	    if ($node->status == 1) {

	      $variables['custom_render'][$key]['typename'] = $collectiondata['field_type_label']['#items'][0]['value'];

	      if ($node->type == 'openpublish_article') {
		$main_image = field_get_items('node', $node, 'field_thumbnail');
	      }
	      if ($node->type == 'action') {
		$main_image = field_get_items('node', $node, 'field_action_main_image');
	      }
	      if ($node->type == 'openpublish_photo_gallery') {
		//field_gallery_main_image would also work here:
		$main_image = field_get_items('node', $node, 'field_gallery_images');
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
      }
    break;
  }
}



function tp4_preprocess_html(&$variables) {
  if($variables['page']['content']['system_main']['#entity_view_mode']['bundle'] == 'topic'){
    $variables['classes_array'][] = 'vocabulary-topic';
  }
 
}






