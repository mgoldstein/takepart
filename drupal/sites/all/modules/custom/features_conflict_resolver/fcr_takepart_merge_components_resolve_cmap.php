<?php
  global $argv;

  $map_file = 'conflicts.map.php';
  $cmap = array();
  $group = $argv[4];

  if (!file_exists($map_file)) {
    $message = t('Error: You need to dump the map first.');
    trigger_error($message, E_USER_ERROR);
    exit(1);
  }
  require_once $map_file;
  unset($cmap['node']);

  if (!isset($cmap[$group])) {
    $message = t('Error: Component @group does not exist.', array(
      '@group' => $group,
    ));
    trigger_error($message, E_USER_ERROR);
    exit(1);
  }

  drupal_flush_all_caches();

  $current = $cmap[$group];
  print_r($current);

  $not_exists = array();

  foreach ($current['modules'] as $module) {
    if (!module_exists($module)) {
      $not_exists[$module] = TRUE;
    }
  }

  features_conflict_resolver_create_feature($current);

  if ($not_exists != NULL) {
    module_enable(array_values($not_exists));
    drupal_flush_all_caches();
  }

  features_conflict_resolver_update_feature($current);

  if ($not_exists != NULL) {
    module_disable(array_values($not_exists));
  }

?>
