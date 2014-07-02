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
  $info['groups']['tp_dtm'] = array(
    'label' => t('TakePart DTM'),
  );

  $info['tags']['dtm:page-title'] = array(
    'label' => t('DTM Page Title'),
    'description' => t('The Page Title'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'tp_dtm',
  );
	$info['tags']['dtm:section'] = array(
		'label' => t('DTM Section'),
		'description' => t('The Section (aka Channel)'),
		'class' => 'DrupalTextMetaTag',
		'group' => 'tp_dtm',
	);
	$info['tags']['dtm:subsection'] = array(
		'label' => t('DTM Subsection'),
		'description' => t('The Subsection ([path1]:[path2])'),
		'class' => 'DrupalTextMetaTag',
		'group' => 'tp_dtm',
	);
	$info['tags']['dtm:content-type'] = array(
		'label' => t('DTM Content Type'),
		'description' => t('The Content Type if a node'),
		'class' => 'DrupalTextMetaTag',
		'group' => 'tp_dtm',
	);
	$info['tags']['dtm:node-id'] = array(
		'label' => t('DTM Node ID'),
		'description' => t('The Node ID if on a node page'),
		'class' => 'DrupalTextMetaTag',
		'group' => 'tp_dtm',
	);
	$info['tags']['dtm:url'] = array(
		'label' => t('DTM URL'),
		'description' => t('The URL of the page'),
		'class' => 'DrupalTextMetaTag',
		'group' => 'tp_dtm',
	);
	$info['tags']['dtm:gallery-name'] = array(
		'label' => t('DTM Gallery Name'),
		'description' => t('The Name of a Gallery if a gallery node'),
		'class' => 'DrupalTextMetaTag',
		'group' => 'tp_dtm',
	);
	$info['tags']['dtm:photo-name'] = array(
		'label' => t('DTM Photo Name'),
		'description' => t('The name of the photo'),
		'class' => 'DrupalTextMetaTag',
		'group' => 'tp_dtm',
	);
	$info['tags']['dtm:author-name'] = array(
		'label' => t('DTM Author Name'),
		'description' => t('The name of the author'),
		'class' => 'DrupalTextMetaTag',
		'group' => 'tp_dtm',
	);
	$info['tags']['dtm:series-name'] = array(
		'label' => t('DTM Series Name'),
		'description' => t('The Name of the Series if an Article'),
		'class' => 'DrupalTextMetaTag',
		'group' => 'tp_dtm',
	);
	$info['tags']['dtm:publish-date'] = array(
		'label' => t('DTM Publishe Date'),
		'description' => t('The publish date if on a node'),
		'class' => 'DrupalTextMetaTag',
		'group' => 'tp_dtm',
	);
	$info['tags']['dtm:topic'] = array(
		'label' => t('DTM Topic'),
		'description' => t('The topic if node is tagged with a topic or on a topic page'),
		'class' => 'DrupalTextMetaTag',
		'group' => 'tp_dtm',
	);
	$info['tags']['dtm:campaign-name'] = array(
		'label' => t('DTM Campaign Name'),
		'description' => t('The name of the Campaign if on a campaign page'),
		'class' => 'DrupalTextMetaTag',
		'group' => 'tp_dtm',
	);


  return $info;
}


/* Drupal add meta programmatically for Time of Day, Day of Week, Weekday/Weekend */
/* Is 'page action taken on' a page load thing? */