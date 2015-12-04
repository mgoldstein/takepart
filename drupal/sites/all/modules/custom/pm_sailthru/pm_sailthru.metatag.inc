<?php

/**
 * @file
 * Metatag integration for the pm_metatag_sailthru module.
 */

/**
 * Implements hook_metatag_config_default_alter().
 */
function pm_sailthru_metatag_config_default_alter(array &$configs) {
  foreach ($configs as &$config) {
    switch ($config->instance) {
	 case 'global':
	   $config->config += array(
		'sailthru.tags' => array(),
		'sailthru.author' => array(),
		'sailthru.date' => array(),
	   );
	   break;

	 case 'global:frontpage':
	   $config->config += array(
		'sailthru.tags' => array(),
		'sailthru.author' => array(),
		'sailthru.date' => array(),
	   );
	   break;

	 case 'node':
	   $config->config += array(
		'sailthru.tags' => array(
		  'value' => '[sailthru_metatags:tags_type]'
		),
		'sailthru.author' => array(
		  'value' => '[sailthru_metatags:author]',
		),
		'sailthru.date' => array(
		  'value' => '[node:published:custom:Y-m-d H:i:s]',
		),
	   );
	   break;

	 case 'taxonomy_term':
	   $config->config += array(
		'sailthru.tags' => array(),
		'sailthru.author' => array(),
		'sailthru.date' => array(),
	   );
	   break;

	 case 'user':
	   $config->config += array(
		'sailthru.tags' => array(),
		'sailthru.author' => array(),
		'sailthru.date' => array(),
	   );
	   break;
    }
  }
}

/**
 * Implements hook_metatag_info().
 */
function pm_sailthru_metatag_info() {
  $groups = array(
    'custom-sailthru' => array(
	 'label' => t('SailThru Custom'),
	 'form' => array('#weight' => 50),
    ),
  );

  $tags = array(
    'sailthru.tags' => array(
	 'label' => t('SailThru Keywords'),
	 'description' => t('Keywords for SailThru platform'),
	 'class' => 'DrupalTextMetaTag',
	 'group' => 'custom-sailthru',
	 'element' => array('#theme' => 'metatag_sailthru'),
    ),
    'sailthru.author' => array(
	 'label' => t('SailThru Author'),
	 'description' => t('Content authors formatted for SailThru'),
	 'class' => 'DrupalTextMetaTag',
	 'group' => 'custom-sailthru',
	 'element' => array('#theme' => 'metatag_sailthru'),
    ),
    'sailthru.date' => array(
	 'label' => t('SailThru Date'),
	 'description' => t('Content publication date formatted for SailThru'),
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
