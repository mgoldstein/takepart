<?php

/**
 * Implements hook_preprocess_page()
 */
function base_preprocess_page(&$variables) {
  // jquery.cookie plugin is not being loaded for anonymous users and needs to be for TAP
  drupal_add_library('system', 'jquery.cookie');

  /*
   * Adds <meta property="sponsored" content="Promoted" /> to sponsored content
   */
  if (isset($variables['node'])) {
    if (!empty($variables['node']->field_sponsored[$variables['node']->language][0]['tid'])) {
	 $sponsored_metatag = array(
	   '#type' => 'html_tag',
	   '#tag' => 'meta',
	   '#attributes' => array(
		'property' => 'sponsored',
		'content' => 'Promoted',
	   )
	 );
	 drupal_add_html_head($sponsored_metatag, 'sponsored_metatag');
    }
  }

  // Add Node-specific page templates
  if (!empty($variables['node'])) {
    $variables['theme_hook_suggestions'][] = 'page__' . $variables['node']->type;
  }
}
