<?php

/**
 * Implements hook_features_export_options().
 */
function pm_signup_endpoint_features_export_options() {
  return db_select('pm_signup_endpoint', 'ep')
    ->fields('ep', array('name', 'label'))
    ->isNotNull('name')
    ->execute()
    ->fetchAllKeyed();
}

/**
 * Implements hook_featues_export().
 */
function pm_signup_endpoint_features_export($data, &$export, $module_name,
  $type = 'pm_signup_endpoint') {
  $pipe = array();
  $export['dependencies']['pm_signup'] = 'pm_signup';
  foreach ($data as $component) {
    $export['features'][$type][$component] = $component;
  }
  return $pipe;
}

/**
 * Implements hook_features_export_render().
 */
function pm_signup_endpoint_features_export_render($module_name, $data,
  $export = NULL) {
  $lines = array();
  $lines[] = '  $endpoints = array();';
  foreach ($data as $name) {
    $endpoint = SignupEndpoint::loadByName($name);
    if ($endpoint !== FALSE) {
      $item = $endpoint->exportToFeature();
      $lines[] = '  $endpoints[] = ' . features_var_export($item, '  ') . ';';
    }
  }
  $lines[] = '  return $endpoints;';
  $code = implode("\n", $lines);
  return array('pm_signup_endpoint_defaults' => $code);
}

/**
 * Implements hook_features_rebuild().
 */
function pm_signup_endpoint_features_rebuild($module) {
  $items = module_invoke($module, 'pm_signup_endpoint_defaults');
  foreach ($items as $item) {

    // The endpoint class must be available
    $type = $item['type'];
    if (class_exists($type)) {

      // Load any existing endpoint.
      $endpoint = SignupEndpoint::loadByName($item['name']);

      if ($endpoint === FALSE) {
        // No existing endpoint so create one.
        $endpoint = new $type();
      }
      elseif (get_class($endpoint) !== $type) {
        // The type of the endpoint has changed,
        // replace the existing one.
        $endpoint->delete();
        $endpoint = new $type();
      }

      // (Re)build the endpoint from the feature and save.
      $endpoint->rebuildFromFeature($item);
      $endpoint->save();
    }
  }
}

/**
 * Implements hook_features_rebuild().
 */
function pm_signup_endpoint_features_revert($module) {
  return pm_signup_endpoint_features_rebuild($module);
}
