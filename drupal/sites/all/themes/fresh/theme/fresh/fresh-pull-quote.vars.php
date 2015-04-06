<?php

/**
 * Implements hook_preprocess_HOOK
 */
function fresh_preprocess_pull_quote(&$variables){
  /* Quote */
  $variables['quote'] = 'quote';

  /* Author */
  $variables['author'] = 'author';
}