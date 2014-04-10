<?php
/**
 * @file
 * Metatag integration for the pm_metatag_tap module.
 */

/**
 * Implements hook_metatag_config_default_alter().
 */
function pm_metatag_tap_metatag_config_default_alter(array &$configs) {
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
          'tab-keywords' => array(
            'value' => '[tab_metatags:topic_freetags:{node:field_topic}, {node:field_free_tag}]'
          ),
          'tp:node_id' => array(
            'value' => '[node:nid]'
          ),
          'tp:node_title' => array(
            'value' => '[node:title]'
          ),
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
function pm_metatag_tap_metatag_info() {
  $groups = array(
    'custom-tab' => array(
      'label' => t('TAB Custom'),
      'form' => array('#weight' => 50),
    ),
    'tp-analytics' => array(
      'label' => t('TakePart Analytics'),
      'form' => array('#weight' => 50),
    ),
  );

  $tags = array(
    'tab-keywords' => array(
      'label' => t('TAB Keywords'),
      'description' => t('Keywords for TAB platform recommendations'),
      'class' => 'DrupalTextMetaTag',
      'group' => 'custom-tab',
      'element' => array('#theme' => 'metatag_tab'),
    ),
    'tp:node_id' => array(
      'label' => t('Node ID'),
      'description' => t('Node ID'),
      'class' => 'DrupalTextMetaTag',
      'group' => 'tp-analytics',
      'element' => array('#theme' => 'metatag_tab'),
    ),
    'tp:content_title' => array(
      'label' => t('Content Title'),
      'description' => t('Content Title'),
      'class' => 'DrupalTextMetaTag',
      'group' => 'tp-analytics',
      'element' => array('#theme' => 'metatag_tab'),
    ),
    'tp:content_type' => array(
      'label' => t('Content Type'),
      'description' => t('Content Type'),
      'class' => 'DrupalTextMetaTag',
      'group' => 'tp-analytics',
      'element' => array('#theme' => 'metatag_tab'),
    ),
    'tp:content_authors' => array(
      'label' => t('Content Authors'),
      'description' => t('Content Authors'),
      'class' => 'DrupalTextMetaTag',
      'group' => 'tp-analytics',
      'element' => array('#theme' => 'metatag_tab'),
    ),
    'tp:published_date' => array(
      'label' => t('Published Date'),
      'description' => t('Published Date'),
      'class' => 'DrupalTextMetaTag',
      'group' => 'tp-analytics',
      'element' => array('#theme' => 'metatag_tab'),
    ),
    'tp:campaign' => array(
      'label' => t('Campaign Name'),
      'description' => t('Campaign Name'),
      'class' => 'DrupalTextMetaTag',
      'group' => 'tp-analytics',
      'element' => array('#theme' => 'metatag_tab'),
    ),
    'tp:series' => array(
      'label' => t('Series'),
      'description' => t('Series'),
      'class' => 'DrupalTextMetaTag',
      'group' => 'tp-analytics',
      'element' => array('#theme' => 'metatag_tab'),
    ),
    'tp:topic' => array(
      'label' => t('Topic'),
      'description' => t('Topic'),
      'class' => 'DrupalTextMetaTag',
      'group' => 'tp-analytics',
      'element' => array('#theme' => 'metatag_tab'),
    ),
  );

  return array(
    'groups' => $groups,
    'tags' => $tags,
  );
}
