<?php

/**
* Implements hook_preprocess_THEME_HOOK().
*/
function fresh_preprocess_inline_content(&$variables) {
  $element = $variables['element'];
  $inline_content = $element['#inline_content'];
  $variables['theme_hook_suggestions'][] = "inline_content__" . $inline_content->type;
  $variables['classes_array'] = $variables['element']['#attributes']['class'];
  $variables['classes_array'][] = $inline_content->type;
}