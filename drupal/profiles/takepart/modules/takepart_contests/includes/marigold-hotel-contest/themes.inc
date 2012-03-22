<?php
/**
 * Marigold hotel contest form theme.
 */
function theme_takepart_contests_contest_entry_form_1(&$variables) {
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
      
  $output = '<div id="' . $wrapper . '">' . drupal_render_children($form) . '</div>';
  return $output;
}
