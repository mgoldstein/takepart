<?php

/**
 * @file
 * Metatag integration for the metatag_tab module.
 */

/**
 * Implements hook_metatag_config_default_alter().
 */
function metatag_tab_metatag_config_default_alter(array &$configs) {
  foreach ($configs as &$config) {
    switch ($config->instance) {
      case 'global':
        $config->config += array( 
            'tab-keywords' => array(),
        );
        break;
    
      case 'global:frontpage':
        $config->config += array( 
            'tab-keywords' => array(),
        );
        break;
    
      case 'node':
        $config->config += array(
          'tab-keywords' => array('value' => '[tab_metatags:topic_freetags:{node:field_topic}, {node:field_free_tag}]'),
        );
        break;
    
      case 'taxonomy_term':
        $config->config += array( 
            'tab-keywords' => array(),
        );
        break;
    
      case 'user':
        $config->config += array( 
            'tab-keywords' => array(),
        );
        break;

    }
  }
}

/**
 * Implements hook_metatag_info().
 */
function metatag_tab_metatag_info() {
  $info['groups']['custom-tab'] = array(
    'label' => t('TAB Custom'),
    'form' => array(
      '#weight' => 50,
    ),
  );

  $info['tags']['tab-keywords'] = array(
    'label' => t('TAB Keywords'),
    'description' => t('Keywords for TAB platform recommendations'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'custom-tab',
    'element' => array(
      '#theme' => 'metatag_tab',
    ),
  );

  return $info;
}