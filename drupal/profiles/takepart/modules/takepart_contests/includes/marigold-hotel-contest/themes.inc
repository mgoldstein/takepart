<?php
/**
 * Marigold hotel contest form theme.
 */
function theme_takepart_contests_contest_entry_form_1(&$variables) {

  $modulename = 'takepart_contests';

  // TODO: When is it possibly set? The code for pulling the form
  // from the theme variables comes after this
  if(!isset($form['#step']['#value'])) {
    drupal_add_library('system', 'ui');
    drupal_add_js(drupal_get_path('module', $modulename)
      . '/includes/marigold-hotel-contest/js/jquery.preloader.js');
    drupal_add_js(drupal_get_path('module', $modulename)
      . '/includes/marigold-hotel-contest/js/ui.checkbox.js');
    drupal_add_js(drupal_get_path('module', $modulename)
      . '/includes/marigold-hotel-contest/js/jquery.selectbox-0.5.js');
    drupal_add_js(drupal_get_path('module', $modulename)
      . '/includes/marigold-hotel-contest/js/customSelect.jquery.js');
    drupal_add_css(drupal_get_path('module', $modulename)
      . '/includes/marigold-hotel-contest/css/form.css');
    drupal_add_js(drupal_get_path('module', $modulename)
      . '/includes/marigold-hotel-contest/js/form.js');
  }

  $form = $variables['form'];

  if($form['#step']['#value'] == 4) {
    $output  = '<div id="takepart_contests_form_wrapper_1">';
    $output .= '<div id="step4legend"></div>';
    $output .= '<div class="step4wrapper">';
    $output .= drupal_render_children($form);
    $output .= '</div>';
    $output .= '</div>';
  } else {
    $output  = '<div id="takepart_contests_form_wrapper_1">';
    $output .= drupal_render_children($form);
    $output .= '</div>';
  }

  return $output;
}



/**
 * Theme for form button submit.
 */
function theme_takepart_contests_contest_entry_form_1_button_next($variables) {
  return '<span class="button next"><div class='
    . implode(" ", $variables['element']['#attributes']['class']) . '>'
    . $variables['element']['#takepart_before']  . '</div>'
    . theme_button($variables) . '</span>';
}

function theme_takepart_contests_contest_entry_form_1_button_prev($variables) {
  return '<span class="button prev">' . theme_button($variables) . '</span>';
}

function takepart_contests_contest_entry_form_1_columns($variables) {
  return '<span>' . theme_form_elements($variables) . '</span>';
}