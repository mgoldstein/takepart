<?php
  drupal_flush_all_caches();
  $cmap = features_conflict_resolver_get_cmap();

  $v_map = array();
  $not_exists = array();

  foreach ($cmap as $current) {
    foreach ($current['all-conflicts'] as $c_val => $val) {
      $v_map[$c_val] = $current;
    }
    foreach ($current['modules'] as $module) {
      if (!module_exists($module)) {
        $not_exists[$module] = TRUE;
      }
    }
  }
  
  if (count($not_exists) > 0) {
    $message = t('Error: The following modules are not enabled: @modules', array( 
      '@modules' => implode(',', array_keys($not_exists))));
    trigger_error($message, E_USER_ERROR);
    exit(1);
  }

//  print_r($v_map['comment_anonymous_audio']);
//  $current = $v_map['comment_anonymous_audio'];
/*
  print_r($v_map['comment_audio']);
  $current = $v_map['comment_audio'];
  features_conflict_resolver_create_feature($current);
  features_conflict_resolver_update_feature($current);
*/
  
  $comps = array('comment_anonymous_audio', 'comment_audio');

  foreach ($comps as $comp) {
    if (isset($v_map[$comp])) {
      $current = $v_map[$comp];
      print_r($current);
      error_log('--------------------------------------');
      error_log(print_r($current, TRUE));
      features_conflict_resolver_create_feature($current);
      features_conflict_resolver_update_feature($current);
    }
  }

/*
  foreach ($cmap as $current) {
    print_r($current);
    features_conflict_resolver_create_feature($current);
  }

  foreach ($cmap as $current) {
    print_r($current);
    features_conflict_resolver_update_feature($current);
  }*/

?>
