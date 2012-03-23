<?php
/**
 * Marigold hotel contest form theme.
 */
function theme_takepart_contests_contest_entry_form_1(&$variables) {
  
  $modulename = 'takepart_contests';
  drupal_add_js(drupal_get_path('module', $modulename) . '/includes/marigold-hotel-contest/js/ui.checkbox.js');
  drupal_add_js(drupal_get_path('module', $modulename) . '/includes/marigold-hotel-contest/js/jquery.selectbox-0.5.js');
  drupal_add_js(drupal_get_path('module', $modulename) . '/includes/marigold-hotel-contest/js/customSelect.jquery.js');
  drupal_add_css(drupal_get_path('module', $modulename) . '/includes/marigold-hotel-contest/css/form.css');
  drupal_add_js(drupal_get_path('module', $modulename) . '/includes/marigold-hotel-contest/js/form.js');
  
  $wrapper = 'takepart_contests_form_wrapper_1';
  $form = $variables['form'];
  
  //Code for rendering the steps:
  for ($groups = 0; $groups <= 5; $groups++) {
    if (array_key_exists('group_step' . $groups, $form) && array_key_exists('#step', $form)) {
      if($groups == ((int)$form['#step']['#value']) ) {
        if(array_key_exists('#access', $form['group_step' . $groups])) {
          unset($form['group_step' . $groups]['#access']);
        }
      } else {
        $form['group_step' . $groups] = array('#access'=>FALSE);
      }
    }
  }
 
  
  if($form['#step']['#value'] == 1) {
    $form['next']['#attributes']['class'][] = 'aboutyou';
    $form['next']['#takepart_before'] = 'next: ';
    $form['next']['#theme_wrappers'] = array('takepart_contests_contest_entry_form_1_button_next');
  }
  
  if($form['#step']['#value'] == 2) {
    $form['next']['#attributes']['class'][] = 'finalinfo';
    $form['next']['#takepart_before'] = 'next: ';
    $form['next']['#theme_wrappers'] = array('takepart_contests_contest_entry_form_1_button_next');
  
    $form['prev']['#attributes']['class'][] = 'backtostepone';
    $form['prev']['#theme_wrappers'] = array('takepart_contests_contest_entry_form_1_button_prev');
  
  }
  
  if($form['#step']['#value'] == 3) {
    $form['next']['#attributes']['class'][] = 'reviewentry';
    $form['next']['#takepart_before'] = 'next: ';
    $form['next']['#theme_wrappers'] = array('takepart_contests_contest_entry_form_1_button_next');
  
    $form['prev']['#attributes']['class'][] = 'backtosteptwo';
    $form['prev']['#theme_wrappers'] = array('takepart_contests_contest_entry_form_1_button_prev');
   
    /*foreach ($form['#fieldgroups'] as $key => $value) {
      if($value->{'group_name'} == 'group_step3') {
        $form['#fieldgroups'][$key]['#theme_wrappers'] = array('takepart_contests_contest_entry_form_1_columns');
      }
    }*/
  }
  
  if($form['#step']['#value'] == 4) {
    $form['submit']['#attributes']['class'][] = 'submitentry';
    $form['submit']['#takepart_before'] = '';
    $form['submit']['#theme_wrappers'] = array('takepart_contests_contest_entry_form_1_button_next');
  
    $form['prev']['#attributes']['class'][] = 'backtostepthree';
    $form['prev']['#theme_wrappers'] = array('takepart_contests_contest_entry_form_1_button_prev');
  }
  
  $output = '<div id="' . $wrapper . '">' . drupal_render_children($form) . '</div>';
  return $output;
}



/**
 * Theme for form button submit.
 */
function theme_takepart_contests_contest_entry_form_1_button_next($variables) {
  return '<span class="button"><div class=' . implode(" ", $variables['element']['#attributes']['class']) . '>' . $variables['element']['#takepart_before']  . '</div>' . theme_button($variables) . '</span>';
}

function theme_takepart_contests_contest_entry_form_1_button_prev($variables) {
  return '<span class="button">' . theme_button($variables) . '</span>';
}

function takepart_contests_contest_entry_form_1_columns($variables) {
  return '<span>' . theme_form_elements($variables) . '</span>';
}