<?php
/**
 * Marigold hotel contest form theme.
 */
function theme_takepart_contests_contest_entry_form_1(&$variables) {
  $wrapper = 'takepart_contests_form_wrapper_1';
  $form = $variables['form'];
  //prefix and suffix are ignored for some reason:
  //$form['#prefix'] = '<div id="' . $wrapper . '">';
  //$form['#suffix'] = '</div>';
  $output = '<div id="' . $wrapper . '">' . drupal_render_children($form) . '</div>';
  return $output;
}
