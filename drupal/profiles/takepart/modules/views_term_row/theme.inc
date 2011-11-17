<?php

/**
 * Template helper for theme_views_view_row_term
 */
function template_preprocess_views_view_row_term(&$vars) {
  $options = $vars['options'];

  // Make sure the variables are defined.
  $vars['term'] = '';
  $vars['comments'] = '';

  if (!empty($vars['row']->{$vars['field_alias']})) {
    $nid = $vars['row']->{$vars['field_alias']};
  }
  if (!is_numeric($nid)) {
    return;
  }

  $row_plugin = $vars['view']->style_plugin->row_plugin;
  $term = $row_plugin->terms[$nid];

  if (empty($term)) {
    return;
  }

  $term->view = $vars['view'];
  // Detect which build module should be used.
  $term->view_mode = (!empty($options['view_mode'])) ? $options['view_mode'] : 'full';
  //@todo: need to work on view mode
  $content = taxonomy_term_view($term, $term->view_mode);
  if (!$options['links']) {
    unset($content['links']);
  }

  if (!empty($options['comments']) && user_access('access comments') && $term->comment) {
    $build = comment_term_page_additions($term);
    $vars['comments'] = drupal_render($build);
  }

  $vars['term'] = drupal_render($content);

}

