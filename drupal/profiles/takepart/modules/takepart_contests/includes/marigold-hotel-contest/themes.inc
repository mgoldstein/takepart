<?php
/**
 * Marigold hotel contest form theme.
 */
function theme_takepart_contests_contest_entry_form_1(&$variables) {
  $form = $variables['form'];
  $output = drupal_render_children($form);
  return $output;
}
