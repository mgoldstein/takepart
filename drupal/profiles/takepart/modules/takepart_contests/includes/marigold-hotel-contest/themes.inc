<?php
/**
 * Marigold hotel contest form theme.
 */
function theme_takepart_contests_contest_entry_form_1(&$variables) {

  $modulename = 'takepart_contests';

  if(!isset($form['#step']['#value'])) {
    drupal_add_library('system', 'ui');
    drupal_add_js(drupal_get_path('module', $modulename) . '/includes/marigold-hotel-contest/js/ui.checkbox.js');
    drupal_add_js(drupal_get_path('module', $modulename) . '/includes/marigold-hotel-contest/js/jquery.selectbox-0.5.js');
    drupal_add_js(drupal_get_path('module', $modulename) . '/includes/marigold-hotel-contest/js/customSelect.jquery.js');
    drupal_add_css(drupal_get_path('module', $modulename) . '/includes/marigold-hotel-contest/css/form.css');
    drupal_add_js(drupal_get_path('module', $modulename) . '/includes/marigold-hotel-contest/js/form.js');
  }

  $wrapper = 'takepart_contests_form_wrapper_1';
  $form = $variables['form'];

  //Code for rendering the steps:
  if($form['#step']['#value'] != 4) {
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


  if($form['#step']['#value'] == 4) {
    foreach ($variables['form'] as $key => $value) {

      //print "\n--------------------------------\n";
      //print $key;
      //print "\n--------------------------------\n";

      //print_r($variables['form'][$key]);


      if((strlen($key) > 10) && (substr($key, 0, 10) == 'group_step')) {
        $groupstep = substr($key, 10, strlen($key));
        if(is_numeric($groupstep)) {

          if((int)$groupstep == 1) {



          }
           
          // print "\n--------------------------------\n";
          // print $key;
          // print "\n--------------------------------\n";
          // print_r($variables['form'][$key]['field_custom_265']);

          if(isset($variables['form'][$key]['field_custom_265']['und'][0]['value']['#title'])) {
            $title = ($variables['form'][$key]['field_custom_265']['und'][0]['value']['#title']);
          }


        }
      }

    }
  }

  if($form['#step']['#value'] == 4) {
    $output = '<div id="' . $wrapper . '">' . 
      '<div id="step4legend"></div><div class="step4wrapper">' .
      drupal_render_children($form) . 
    '</div></div>';
  } else {
    $output = '<div id="' . $wrapper . '">' . drupal_render_children($form) . '</div>';
  }
  
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