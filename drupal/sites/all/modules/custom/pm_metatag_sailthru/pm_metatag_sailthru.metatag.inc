<?php
/**
 * @file
 * Metatag integration for the pm_metatag_sailthru module.
 */

/**
 * Implements hook_metatag_config_default_alter().
 */
function pm_metatag_sailthru_metatag_config_default_alter(array &$configs) {
  foreach ($configs as &$config) {
    switch ($config->instance) {
      case 'global':
        $config->config += array(
          'sailthru.keywords' => array(),
        );
        break;

      case 'global:frontpage':
        $config->config += array(
          'sailthru.keywords' => array(),
        );
        break;

      case 'node':
        $config->config += array(
          'sailthru.keywords' => array(
            'value' => '[sailthru_metatags:tags_type:{node:nid}]'
          ),
        );
        break;

      case 'taxonomy_term':
        $config->config += array(
          'sailthru.keywords' => array(),
        );
        break;

      case 'user':
        $config->config += array(
          'sailthru.keywords' => array(),
        );
        break;
    }
  }
}

/**
 * Implements hook_metatag_info().
 */
function pm_metatag_sailthru_metatag_info() {
  $groups = array(
    'custom-sailthru' => array(
      'label' => t('SailThru Custom'),
      'form' => array('#weight' => 50),
    ),
  );

  $tags = array(
    'sailthru.keywords' => array(
      'label' => t('SailThru Keywords'),
      'description' => t('Keywords for SailThru platform'),
      'class' => 'DrupalTextMetaTag',
      'group' => 'custom-sailthru',
      'element' => array('#theme' => 'metatag_sailthru'),
    ),
  );

  return array(
    'groups' => $groups,
    'tags' => $tags,
  );
}
