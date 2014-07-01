<?php
/**
 * @file
 * Metatag integration for the metatag Twitter Cards module.
 */

/**
 * Implements hook_metatag_config_default_alter().
 */
function tp_dtm_metatag_config_default_alter(array &$configs) {
  foreach ($configs as &$config) {
    switch ($config->instance) {
      case 'global':
        $config->config += array(
          'dtm:page-title' => array('value' => 'Title Not Working'),
        );
        break;

      case 'global:frontpage':
        $config->config += array(
          // 'twitter:description' => array('value' => ''),
        );
        break;

      // On error pages point everything to the homepage.
      case 'global:403':
      case 'global:404':
        $config->config += array(
          // 'twitter:description' => array('value' => ''),
          // 'twitter:title' => array('value' => '[site:name]'),
          // 'twitter:url' => array('value' => '[site:url]'),
        );
        break;

      case 'node':
        $config->config += array(
          // 'twitter:card' => array('value' => 'summary'),
          // 'twitter:description' => array('value' => '[node:summary]'),
          // 'twitter:title' => array('value' => '[node:title]'),
        );
        break;

      case 'taxonomy_term':
        $config->config += array(
          // 'twitter:card' => array('value' => 'summary'),
          // 'twitter:title'=> array('value' => '[term:name]'),
        );
        break;
    }
  }
}

/**
 * Implements hook_metatag_info().
 */
function tp_dtm_metatag_info() {
  $info['groups']['tp-dtm'] = array(
    'label' => t('TakePart DTM'),
    'description' => t('A set of meta tags specially for controlling the data DTM requires on page load' ),
    'form' => array(
      '#weight' => 60,
    ),
  );

  $info['tags']['dtm:page-title'] = array(
    'label' => t('DTM Page Title'),
    'description' => t('The Page Title'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'tp-dtm',
		'context' => array('global'),
  );

  return $info;
}
