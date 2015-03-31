<?php

/**
 * Implements theme_preprocess_fresh_mobile_menu()
 */
function fresh_preprocess_fresh_mobile_menu(&$variables){
  dpm($variables, 'variable preprocess');
}

/**
 * Implements theme_process_fresh_mobile_menu()
 */
function fresh_process_fresh_mobile_menu(&$variables){
  dpm($variables, 'variables process');
}