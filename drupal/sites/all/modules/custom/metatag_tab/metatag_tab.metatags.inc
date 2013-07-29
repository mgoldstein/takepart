<?php
//
// Implements hook_metatag_info().
//
function metatag_tab_metatag_info() {
  $info['groups']['metatag_tab'] = array(
    'label' => t('TAB Keywords'),
  );
 
  $info['tags']['tab-keywords'] = array(
    'label' => t('TAB Keywords'),
    'description' => t('This is a custom meta tag'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'metatag_tab',
  );
 
  return $info;
}
 
//
// Implements hook_metatag_config_default_alter().
//
function metatag_tab_metatag_config_default_alter(array &$configs) {
  foreach ($configs as &$config) {
      dpm($config->instance);
    switch ($config->instance) {
      case 'global':
        $config->config += array();
        break;
 
      case 'global:frontpage':
        $config->config += array();
        break;
 
      case 'node':
        $config->config += array(
          'tab-keywords' => array('value' => 'This is a default value.'),
        );
        break;
 
      case 'taxonomy_term':
        $config->config += array();
        break;
 
      case 'user':
        $config->config += array( );
        break;
    }
  }
}