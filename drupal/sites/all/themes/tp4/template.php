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
  // Deal with the author stuff
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

