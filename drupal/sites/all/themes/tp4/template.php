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

}


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
  // Run node-type-specific preprocess functions, like
  // tp4_preprocess_node_page() or tp4_preprocess_node_story().
  $function = __FUNCTION__ . '_' . $variables['node']->type;
  if (function_exists($function)) {
    $function($variables, $hook);
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
 * Implementations of theme_field().
 *
 * You can override field output globally, per field, per content
 * type, or per field in a content type.
 *
 * @see https://api.drupal.org/api/drupal/modules!field!field.module/function/theme_field/7
 */

/**
 * Implements theme_field().
 *
 * Outputs the author field for article nodes.
 */
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
    $output .= ($number_of_authors > 1 && $delta == $number_of_authors - 2 ) ? 'and ' :'';
  }
  $output .= '</span>';

  // Render the top-level div.
  $output = '<div class="byline ' . $variables['classes'] . '"' . $variables['attributes'] . '>By ' . $output . '</div>';

  return $output;
}


function tp4_menu_link(array $variables) {
  if($variables['element']['#theme'] == 'menu_link__menu_megamenu'){
    $variables['element']['#attributes']['data-mlid'][] = $variables['element']['#original_link']['mlid'];
  }
  return theme_menu_link($variables);
}



