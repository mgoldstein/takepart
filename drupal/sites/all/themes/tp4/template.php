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

  // override page titles on certain node templates
  if (!empty($variables['node']) && in_array($variables['node']->type, array('openpublish_article'))) {
    $variables['title'] = '';
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
  if($variables['type'] == 'openpublish_video'){
    $variables['theme_hook_suggestions'][] = 'node__openpublish_article__full';
  }
  $vars['theme_hook_suggestions'][] = 'node__' . $vars['view_mode'];
  $vars['theme_hook_suggestions'][] = 'node__' . $vars['type'] . '__' . $vars['view_mode'];
  
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
  $variables['attributes_array']['data-series'] = $variables['field_series'][LANGUAGE_NONE][0]['tid'];

  // get the caption working
  $variables['main_image_image'] = render($variables['content']['field_article_main_image']);
  $variables['main_image_caption'] = $variables['field_article_main_image'][0]['file']->field_media_caption[LANGUAGE_NONE][0]['safe_value'];

  // render topic box
  $image = file_create_url($variables['field_topic_box'][0]['taxonomy_term']->field_topic_box_image['und'][0]['uri']);
  $image = '<img src="'. $image. '">';
  $url = (isset($variables['field_topic_box'][0]['taxonomy_term']->field_topic_box_link['und'][0]['url']) ? $variables['field_topic_box'][0]['taxonomy_term']->field_topic_box_link['und'][0]['url'] : '');
  $variables['field_topic_box_top'] = l($image, $url, array('html' => true));

  // we're going to do some things only on the full view of an article
  if($variables['view_mode'] == 'full'){
    // provide "on our radar" block
    $variables['on_our_radar'] = module_invoke('bean', 'block_view', 'on-our-radar-block');

    // provide a series prev/next nav if a series exists
    if(isset($variables['field_series'])){
      $series = taxonomy_term_load($variables['field_series']['und'][0]['tid']);
      $series_image = file_create_url($series->field_series_graphic_header['und'][0]['uri']);
      $series_image = '<img src="'. $series_image. '">';

      $created = $variables['created'];
      $seriesQueryNext = new EntityFieldQuery();
      $seriesQueryNext->entityCondition('entity_type', 'node')
              ->entityCondition('bundle', 'openpublish_article')
              ->propertyCondition('status', 1)
              ->propertyCondition('created', $created, '>')
              ->fieldCondition('field_series', 'tid', $series->tid, '=')
              ->propertyOrderBy('created', 'ASC')
              ->range(0,1);
      $next = $seriesQueryNext->execute();
      $next = current($next['node']);
      $next = node_load($next->nid);
      $next_url = drupal_get_path_alias('node/'. $next->nid);

      $seriesQueryPrev = new EntityFieldQuery();
      $seriesQueryPrev->entityCondition('entity_type', 'node')
              ->entityCondition('bundle', 'openpublish_article')
              ->propertyCondition('status', 1)
              ->propertyCondition('created', $created, '<')
              ->fieldCondition('field_series', 'tid', $series->tid, '=')
              ->propertyOrderBy('created', 'DESC')
              ->range(0,1);
      $previous = $seriesQueryPrev->execute();
      $previous = current($previous['node']);
      $previous = node_load($previous->nid);
      $previous_url = drupal_get_path_alias('node/'. $previous->nid);

      $series_nav = '';
      $series_nav .= $series_image;
      $series_nav .= '<div class="more-prev">previous</div><div class="more-next">next</div>';
      $previous = '<div class="previous">'. (isset($previous->field_promo_headline['und'][0]['value']) ? $previous->field_promo_headline['und'][0]['value'] : drupal_render($previous->title)). '</div>';
      $next = '<div class="next">'. (isset($next->field_promo_headline['und'][0]['value']) ? $next->field_promo_headline['und'][0]['value'] : $next->title). '</div>';
      $series_nav .= l($previous, $previous_url, array('html' => true));
      $series_nav .= l($next, $next_url, array('html' => true));

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





