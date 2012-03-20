<?php
/**
 * Marigold hotel contest form theme.
 */
function theme_marigold_hotel_contest_form($variables) {
  $modulename = 'takepart_contests';
  drupal_add_js(drupal_get_path('module', $modulename) . '/includes/marigold-hotel-contest/js/ui.checkbox.js');
  drupal_add_js(drupal_get_path('module', $modulename) . '/includes/marigold-hotel-contest/js/jquery.selectbox-0.5.js');
  drupal_add_js(drupal_get_path('module', $modulename) . '/includes/marigold-hotel-contest/js/customSelect.jquery.js');
  drupal_add_css(drupal_get_path('module', $modulename) . '/includes/marigold-hotel-contest/css/form.css');
  drupal_add_js(drupal_get_path('module', $modulename) . '/includes/marigold-hotel-contest/js/form.js');
  $form = $variables['form'];


  $title = $form['choice']['#title'];
  $form['choice']['#title'] = '';
  $output = 'THEME2<strong>' . $title . '</strong>';
  $form['choice']['#prefix'] = '<div class="container-inline">';
  $form['submit']['#suffix'] = '</div>';


  if($form['#step']['#value'] == 1) {
    $form['next']['#attributes']['class'][] = 'aboutyou';
    $form['next']['#takepart_before'] = 'next: ';
    $form['next']['#theme_wrappers'] = array('marigold_hotel_contest_form_button_next');
  }

  if($form['#step']['#value'] == 2) {
    $form['next']['#attributes']['class'][] = 'finalinfo';
    $form['next']['#takepart_before'] = 'next: ';
    $form['next']['#theme_wrappers'] = array('marigold_hotel_contest_form_button_next');

    $form['prev']['#attributes']['class'][] = 'backtostepone';
    $form['prev']['#theme_wrappers'] = array('marigold_hotel_contest_form_button_prev');

  }

  if($form['#step']['#value'] == 3) {
    $form['next']['#attributes']['class'][] = 'reviewentry';
    $form['next']['#takepart_before'] = 'next: ';
    $form['next']['#theme_wrappers'] = array('marigold_hotel_contest_form_button_next');

    $form['prev']['#attributes']['class'][] = 'backtosteptwo';
    $form['prev']['#theme_wrappers'] = array('marigold_hotel_contest_form_button_prev');
  }


  $output .= drupal_render_children($form);
  return $output;
}

/**
 * Theme for form button submit.
 */
function theme_marigold_hotel_contest_form_button_next($variables) {
  return '<span class="button"><div class=' . implode(" ", $variables['element']['#attributes']['class']) . '>' . $variables['element']['#takepart_before']  . '</div>' . theme_button($variables) . '</span>';
}

function theme_marigold_hotel_contest_form_button_prev($variables) {
  return '<span class="button">' . theme_button($variables) . '</span>';
}